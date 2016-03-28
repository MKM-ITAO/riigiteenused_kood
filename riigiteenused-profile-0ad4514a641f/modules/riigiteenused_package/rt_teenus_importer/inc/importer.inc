<?php

module_load_include('inc', 'rt_teenus_importer', 'inc/interfaces/importer_interface');

/**
 * @file
 * Importer class.
 *
 * This class handls services and terns import. Number of methods are descrubing
 * different tasks and steps.
 *
 * Importer can be executed from the importer form (kind a sorce execution) or
 * by cron with number. In case of cron services importer will be performed
 * iteratively: teenus_import_bunch_number variable defines how many services
 * will be imported per iteration.
 *
 * AbstractImporter abstract class is located at the end of the file
 * and defines which importer main methods should be implemented.
 */

/**
 * Class Importer.
 */
class Importer extends AbstractImporter implements ImporterInterface {

  // Importer execution tasks.
  const IF_IMPORT_STARTED_STEP    = 'initializeImport';
  const IF_CLEAR_TERMS_AND_NODES  = 'cleanUpTermsNodes';
  const IF_IMPORT_TERMS           = 'importTerms';
  const IF_IMPORT_SERVICES        = 'importServices';
  const IF_FINISHED               = 'finishImport';

  // Rollback required state variable.
  const IF_ROLLBACK_MARKER  = 'importer_rollback_required';
  // Factroy log.
  const IF_STATE_LOG      = 'importer_log';
  // Watchdog messages key.
  const IF_WATCHDOG_KEY   = 'riigiteenused-importer';
  // Drupal email template key.
  const IF_MAIL_KEY       = 'rt_importer_common';
  // Save backups for number of days.
  const IF_HOLD_BACKUPS_DAYS = 7;
  // Importer is running variable name.
  const IF_IMPORTER_RUNNING_KEY = 'importer_running';

  private static $exportDirectoryName = 'inc/json_export';
  private static $exportServicesFileName = 'services__date_.json';
  private static $exportTermsFileName = 'terms__date_.json';

  /**
   * Importer storage state variable.
   *
   * @var \ImporterStorage
   */
  private $importerStorage;

  // API urls.
  private $apiTermsUrl;
  private $apiServicesUrl;

  // Rollback files pathes.
  private $termsBackupPath;
  private $servicesBackupPath;

  // This attribute is TRUE when importer is executed from the form. Is this
  // case messages wouldn't be saved to the database.
  private $executedFromImporterForm = FALSE;

  // Name of the drupal static cache variable for the api json response.
  private static $apiResponseCacheKey = 'IMPORTER_API_JSON_RESPONSE_CACHE-';
  private static $apiServicesCacheSuffix = 'SERVICES-KEY';
  private static $apiTermsCacheSuffix = 'TERMS-KEY';


  // Set TRUE if importer rolling previous state back from the backup json
  // files.
  private $rollingStuffBack = FALSE;

  // Does this execution is skipped? Do not reset IF_IMPORTER_RUNNING_KEY if
  // true.
  private $executionSkipped = FALSE;

  // Number of nodes to be imported per iteration. Value can be configured in
  // the Application configuration form.
  private $importNodesPerIteration;

  // Site email.
  private $siteEmail;

  /**
   * Importer constructor.
   *
   * @param \ImporterStorageInterface $importer_storage
   *   Importer storage object.
   * @param string $api_terms_url
   *   Terms API url.
   * @param string $api_nodes_url
   *   Services API url.
   */
  public function __construct(ImporterStorageInterface $importer_storage, $api_terms_url = NULL, $api_nodes_url = NULL) {
    // Setup API urls.
    $this->apiTermsUrl
      = !is_null($api_terms_url) ? $api_terms_url : self::getDrupalVariable('teenus_service_application_url', '') . '/' . RT_TEENUS_IMPORTERTERMS_API_URI;
    $this->apiServicesUrl
      = !is_null($api_nodes_url) ? $api_nodes_url : self::getDrupalVariable('teenus_service_application_url', '') . '/' . RT_TEENUS_IMPORTERNODES_API_URI;

    // Rollback marker.
    $this->rollingStuffBack = self::getDrupalVariable(self::IF_ROLLBACK_MARKER, FALSE);

    // Setup rollback file names.
    $export_dir_full_path
      = drupal_get_path('module', 'rt_teenus_importer') . '/' . self::$exportDirectoryName;
    $terms_backup_file = str_replace('_date_', date('d_m_Y', strtotime("-1 DAY")), self::$exportTermsFileName);
    $services_backup_file = str_replace('_date_', date('d_m_Y', strtotime("-1 DAY")), self::$exportServicesFileName);
    $this->termsBackupPath = $export_dir_full_path . '/' . $terms_backup_file;
    $this->servicesBackupPath = $export_dir_full_path . '/' . $services_backup_file;

    // ImporterStorage class object.
    $this->importerStorage = $importer_storage;

    // How many services are allowed to import per iteration.
    $this->importNodesPerIteration
      = self::getDrupalVariable('teenus_import_bunch_number', 300);

    // Setup site email.
    $this->siteEmail = self::getDrupalVariable('teenus_import_notification_emails', '');
  }

  /**
   * Destruct method.
   */
  public function __destruct() {
    if (!$this->executionSkipped) {
      self::setDrupalVariable(self::IF_IMPORTER_RUNNING_KEY, FALSE);
    }
  }


  /**
   * Pickup next task to execute.
   *
   * Cron callback function. Correct execution task will be selected from the
   * task list in the importer storage variable.
   *
   * Import should be executed once a day.
   *
   * Importer storage variable will be truncated if import was executed more
   * then one day ago.
   */
  public function runNextTask() {
    if (self::getDrupalVariable(self::IF_IMPORTER_RUNNING_KEY, FALSE)) {
      $this->logImporterAction('Previous importer task still running. Skip.')
        ->updateStateStorage();

      $this->executionSkipped = TRUE;
    }
    else {
      // Set importer is running.
      self::setDrupalVariable(self::IF_IMPORTER_RUNNING_KEY, TRUE);
      $this->checkStorageVariable();

      // Pickup next task.
      $incorrect_task_name = NULL;
      $all_tasks_executed = TRUE;
      foreach ($this->importerStorage->getImporterStorageVariable('import_steps_executed') as $task => $task_state) {
        $incorrect_task_name = method_exists($this, $task) === FALSE;
        if ($task_state === FALSE && $incorrect_task_name === FALSE) {
          $this->logImporterAction(sprintf(
            'Next task | %s | executed at: %s',
            $task, date('H:i:s d-m-Y')
          ))->updateStateStorage();
          $all_tasks_executed = FALSE;
          $this->{$task}();
          return;
        }
      }

      if ($incorrect_task_name === FALSE && !$all_tasks_executed) {
        $this->logImporterAction(sprintf('Undefined method name (%s)!', $task))
          ->updateStateStorage();
      }
    }

  }

  /**
   * Force import terms and services.
   *
   * This method will be called from the @see rt_teenus_importer_form_submit
   * form submit hook. API links will be passed to the constructor.
   *
   * @return array
   *   imported terms and services number in the single array.
   */
  public function forceImportFromForm() {
    if (self::getDrupalVariable(self::IF_IMPORTER_RUNNING_KEY, FALSE)) {
      $this->logImporterAction('Previous importer task still running. Skip.')
        ->updateStateStorage();

      $this->executionSkipped = TRUE;
    }
    else {
      $this->executedFromImporterForm = TRUE;

      $this->logImporterAction(sprintf(
        'Import form submitted at: %s', date('H:i:s d-m-Y')
      ));

      // This limit are required for single-tun import.
      self::setPhpRuntimeConfigLimits();
      $this->cleanUpTermsNodes();
      $this->importTerms();
      $this->importServices();

      $this->logImporterAction(sprintf('Finished at: %s', date('H:i:s d-m-Y')));

      return array(
        'terms' => $this->importerStorage->getImporterStorageVariable('terms_imported_cc'),
        'services' => $this->importerStorage->getImporterStorageVariable('services_imported_cc'),
      );
    }
  }

  /**
   * Restore Importer state from the variables.
   *
   * Start new Importer for the initial execution.
   */
  protected function initializeImport() {
    cache_clear_all(self::$apiResponseCacheKey, 'cache', TRUE);

    $this->importerStorage->resetStorage(TRUE);
    $this->logImporterAction('Storage is flashed!')->updateStateStorage();
    $this->importerStorage->setImporterStorageVariable('import_started', TRUE);
    $this->importerStorage->setImporterStorageVariable('import_start_date', strtotime(date('d-m-Y')));
    $this->importerStorage->setImporterStorageVariable('import_start_time', strtotime(date('H:m:s')));
    $this->createApiResponsesBackup();
    $this->setTaskState(self::IF_IMPORT_STARTED_STEP, TRUE);
    $this->logImporterAction(sprintf('Initialized at: %s', date('H:i:s d-m-Y')))
      ->updateStateStorage();
  }

  /**
   * Clean up previously imported terms and nodes.
   */
  protected function cleanUpTermsNodes() {
    $terms_removed = $this->cleanUpTerms();
    $services_removed = $this->cleanUpServices();

    $this->setTaskState(self::IF_CLEAR_TERMS_AND_NODES, TRUE);
    $this->logImporterAction(sprintf(
      'Services (%d) and terms (%d) are cleaned up at: %s',
      $services_removed, $terms_removed, date('H:i:s d-m-Y')
    ))->updateStateStorage();
  }

  /**
   * Import terms from API json.
   */
  protected function importTerms() {
    $terms_from_json = $this->rollingStuffBack
      ? drupal_json_decode(file_get_contents($this->termsBackupPath)) : self::getJsonResponse($this->apiTermsUrl, self::$apiTermsCacheSuffix);
    $terms_imported = 0;
    $terms_total_count = 0;
    $input_is_valid = $terms_from_json && is_array($terms_from_json) && !empty($terms_from_json);

    if ($input_is_valid) {
      foreach ($terms_from_json as $taxonomy_machine_name => $terms_list) {
        if (is_array($terms_list)) {
          $taxonomy = taxonomy_vocabulary_machine_name_load($taxonomy_machine_name);
          foreach ($terms_list as $old_tid => $term) {
            $terms_total_count++;
            $parent = 0;
            if ($term['parents'][0] != '0') {
              if ($parent_term = $this->getTermByName($taxonomy_machine_name, $terms_list[$term['parents'][0]]['name'])) {
                $parent = $parent_term;
              }
              else {
                $this->logImporterAction(sprintf(
                  'Searching term\'s parent term failed: %s | %s',
                  $terms_list[$term['parents'][0]]['name'], $taxonomy_machine_name
                ));
                // Should rollback only when failed importing valitsuse_puu
                // terms. Log error and continue for other vocabularies.
                continue;
              }
            }

            $new_term = new stdClass();
            $new_term->vid = $taxonomy->vid;
            $new_term->vocabulary_machine_name = $taxonomy_machine_name;
            $new_term->name = $term['name'];
            $new_term->description = $term['description'];
            $new_term->format = $term['format'];
            $new_term->weight = $term['weight'];
            $new_term->hweight = $term['hweight'];
            $new_term->hdepth = $term['hdepth'];
            $new_term->depth = $term['depth'];
            $new_term->language = $term['language'];
            $new_term->parent = $parent;

            try {
              taxonomy_term_save($new_term);
              $terms_imported++;
            }
            catch (Exception $e) {
              $this->initializeRollback(sprintf('PDOexception catched saving term: %s', $e->getMessage()));
              return;
            }
          }
        }
      }
    }

    // Check import result.
    if (!$input_is_valid) {
      $this->initializeRollback('Invalid input for the terms input!');
    }
    elseif ($terms_imported < $terms_total_count) {
      $this->initializeRollback(sprintf(
        'Imported terms number is less then total number: %d / %d! Check importer log for more details.',
        $terms_imported, $terms_total_count
      ));
    }
    else {
      $this->importerStorage->setImporterStorageVariable('terms_imported_cc', $terms_imported);
      // This step will be executed again next cron run.
      $this->setTaskState(self::IF_IMPORT_TERMS, $input_is_valid);
      $this->logImporterAction(sprintf('%d terms are imported at: %s | with result: %s',
        $this->importerStorage->getImporterStorageVariable('terms_imported_cc'),
        date('H:i:s d-m-Y'),
        ($input_is_valid ? 'OK' : 'NOK')
      ))->updateStateStorage();
    }
  }

  /**
   * Import services from API json.
   */
  protected function importServices() {
    $services_from_json = $this->rollingStuffBack
      ? drupal_json_decode(file_get_contents($this->servicesBackupPath)) : self::getJsonResponse($this->apiServicesUrl, self::$apiServicesCacheSuffix);
    $all_nodes_imported = FALSE;
    $total_services_to_import = 0;
    $number_services_imported = 0;
    $last_importer_service_number = $this->executedFromImporterForm ?
      0 : $this->importerStorage->getImporterStorageVariable('services_imported_cc', 0);
    $input_is_valid = $services_from_json && is_array($services_from_json) && !empty($services_from_json);

    if ($input_is_valid) {
      $default_language = language_default();

      $total_services_to_import = count($services_from_json);
      $services_from_json = array_slice($services_from_json, $last_importer_service_number);
      $all_nodes_imported = empty($services_from_json) || $this->executedFromImporterForm;
      if (!empty($services_from_json) || $this->executedFromImporterForm) {
        foreach ($services_from_json as $teenus) {
          // Break if iteration max allowed per iteration services number is
          // reached.
          if ($number_services_imported == $this->importNodesPerIteration
            && !$this->executedFromImporterForm
          ) {
            break;
          }
          $new_service_saved = FALSE;

          $data = array(
            date('H:m:s'),
            $teenus['nimetus'],
            $teenus['ministeerium'],
            $teenus['allasutus'],
          );

          $node = new stdClass();
          $node->title = $teenus['nimetus'];
          $node->type = 'teenus';
          $node->language = $teenus['keel'] == LANGUAGE_NONE ? $default_language->language : $teenus['keel'];
          $node->uid = 1;
          $node->status = $teenus['published'];
          // Teenuse osutaja.
          $node->field_t_ministeerium_private[LANGUAGE_NONE][0]['value'] = $teenus['ministeerium'];
          $node->field_t_allasutus_private[LANGUAGE_NONE][0]['value'] = $teenus['allasutus'];
          if ($institution_term = $this->getTermByName('valitsuse_puu', $teenus['allasutus'])) {
            $node->field_t_allasutuse_reference[LANGUAGE_NONE][0]['tid']
              = $institution_term;
          }
          else {
            $this->initializeRollback(sprintf('Service institution term is not found: "%s (%s | %s)"',
              $teenus['nimetus'], $teenus['allasutus'], 'valitsuse_puu'
            ));
            return;
          }

          if (!empty($teenus['osakondyksus'])) {
            $node->field_t_osakond_yksus[LANGUAGE_NONE][0]['value'] = $teenus['osakondyksus'];
          }
          if (!empty($teenus['lisainfo_osutaja'])) {
            $node->field_t_lisainfo_osutaja[LANGUAGE_NONE][0]['value'] = $teenus['lisainfo_osutaja'];
          }

          // Teenuse üldandmed.
          if (!empty($teenus['eluarisyndmus'])) {
            $node->field_t_syndmus[LANGUAGE_NONE][0]['value'] = $teenus['eluarisyndmus'];
          }
          list($prefix, $id) = explode('-', $teenus['identifikaator']);
          $node->field_t_teenuse_prefix[LANGUAGE_NONE][0]['value'] = $prefix;
          $node->field_t_tunnus[LANGUAGE_NONE][0]['value'] = $id;
          $node->field_t_kirjeldus[LANGUAGE_NONE][0]['value'] = $teenus['kirjeldus'];
          foreach ($teenus['sihtgrupp'] as $sihtgrup) {
            $node->field_t_sihtgrupp[$teenus['keel']][]['value'] = $sihtgrup;
          }

          if ($area_term = $this->getTermByName('tegevusvaldkonnad', $teenus['tegevusvaldkond'])) {
            $node->field_t_tegevusvaldkond[LANGUAGE_NONE][0]['tid'] = $area_term;
          }

          if ($service_type_term = $this->getTermByName('teenuse_tyybid', $teenus['teenusetyyp'])) {
            $node->field_t_teenuse_tyyp[LANGUAGE_NONE][0]['tid'] = $service_type_term;
          }

          if (!empty($teenus['lisainfo_uldandmed'])) {
            $node->field_t_lisainfo_uldandmed[LANGUAGE_NONE][0]['value'] = $teenus['lisainfo_uldandmed'];
          }

          // Teenuse vastutaja.
          if (!empty($teenus['omanikunimi'])) {
            $node->field_t_vastutaja_nimi[LANGUAGE_NONE][0]['value'] = $teenus['omanikunimi'];
          }
          if (!empty($teenus['omanikuamet'])) {
            $node->field_t_vastutaja_ametinimetus[LANGUAGE_NONE][0]['value'] = $teenus['omanikuamet'];
          }
          if (!empty($teenus['omanikutelefon'])) {
            $node->field_t_vastutaja_telefon[LANGUAGE_NONE][0]['value'] = $teenus['omanikutelefon'];
          }
          if (!empty($teenus['omanikuemail'])) {
            $node->field_t_vastutaja_email[LANGUAGE_NONE][0]['email'] = $teenus['omanikuemail'];
          }
          if (!empty($teenus['lisainfo_vastutaja'])) {
            $node->field_field_t_lisainfo_vastutaja[LANGUAGE_NONE][0]['value'] = $teenus['lisainfo_vastutaja'];
          }

          // Lisainfo.
          $node->field_t_makse[$teenus['keel']][0]['value'] = $teenus['makse'];
          $node->field_t_konfidentsiaalne_info[LANGUAGE_NONE][0]['value'] = $teenus['konfinfo'];
          if (!empty($teenus['eeltingimus'])) {
            $node->field_t_eeltingimused[LANGUAGE_NONE][0]['value'] = $teenus['eeltingimus'];
          }
          if (!empty($teenus['jareltingimus'])) {
            $node->field_t_jareltingimused[LANGUAGE_NONE][0]['value'] = $teenus['jareltingimus'];
          }
          if (!empty($teenus['seotuddokumendid'])) {
            $node->field_t_seotud_dokumendid[LANGUAGE_NONE][0]['value'] = $teenus['seotuddokumendid'];
          }
          $node->field_t_teenuse_seisund[$teenus['keel']][0]['value'] = $teenus['seisund'];
          if (!empty($teenus['muudatustvajav'])) {
            $node->field_t_muudatus_vajav[LANGUAGE_NONE][0]['value'] = $teenus['muudatustvajav'];
          }
          if (!empty($teenus['aegumisekpv'])) {
            $node->field_t_teenuse_aegumise_kp[LANGUAGE_NONE][0]['value'] = $teenus['aegumisekpv'];
          }
          if (!empty($teenus['funktsioon'])) {
            $node->field_t_funktsioon[LANGUAGE_NONE][0]['value'] = $teenus['funktsioon'];
          }
          if (!empty($teenus['lisainfo'])) {
            $node->field_t_lisainfo[LANGUAGE_NONE][0]['value'] = $teenus['lisainfo'];
          }
          for ($i = 0; $i < count($teenus['regulatsioon']); $i++) {
            $node->field_t_regulatsioon[LANGUAGE_NONE][$i]['url'] = $teenus['regulatsioon'][$i];
          }

          if (!empty($teenus['osutatud_teenuste_arv'])) {
            $node->field_t_osutatud_teenuste_arv[LANGUAGE_NONE][0]['value'] = $teenus['osutatud_teenuste_arv'];
          }
          if (!empty($teenus['rahulolu'])) {
            $node->field_t_rahulolu[LANGUAGE_NONE][0]['value'] = $teenus['rahulolu'];
          }
          if (!empty($teenus['maksumus'])) {
            $node->field_t_maksumus[LANGUAGE_NONE][0]['value'] = $teenus['maksumus'];
          }
          if (!empty($teenus['kliendihaldus_koormus'])) {
            $node->field_t_kliendihaldus_koormus[LANGUAGE_NONE][0]['value'] = $teenus['kliendihaldus_koormus'];
          }

          try {
            node_save($node);
            $new_service_saved = TRUE;

            array_push($data, $node->title);
            array_push($data, 'saved');
            self::writeToLogs($data);
          }
          catch (Exception $e) {
            $this->initializeRollback(sprintf(
              'Failed saving node: %s | error: %s',
              $teenus['nimetus'], $e->getMessage()
            ));
            return;
          }

          /*
           * FIELD COLLECTIONS
           */
          if (!empty($teenus['teenuste_kanalid_ja_moodikud'])) {
            foreach ($teenus['teenuste_kanalid_ja_moodikud'] as $year_value => $measured_channels) {
              $year_field_collection_item
                = entity_create('field_collection_item', array('field_name' => 'field_c_mootmise_aasta'));
              if (!empty($year_value) && $year_value != 'empty' && $year_term = $this->getTermByName('mootmise_aastad', $year_value)) {
                $year_field_collection_item->field_fcf_mootmise_aasta[LANGUAGE_NONE][0]['tid'] = $year_term;
              }
              $year_field_collection_item->setHostEntity('node', $node);
              $year_field_collection_item->save();
              if (is_array($measured_channels)) {
                foreach ($measured_channels as $channel_name => $measurements) {
                  $channel_term = taxonomy_get_term_by_name($channel_name, 'kanaalide_struktuur');
                  $channel_field_collection_item
                    = entity_create('field_collection_item', array('field_name' => 'field_fcf_mootmise_kanal'));
                  $channel_field_collection_item->setHostEntity('field_collection_item', $year_field_collection_item);
                  if (!empty($channel_term)) {
                    $channel_field_collection_item->field_fcf_kanal[LANGUAGE_NONE][0]['tid'] = key($channel_term);
                  }
                  if (!empty($measurements['osutamistearv'])) {
                    $channel_field_collection_item->field_fcf_osutamiste_arv[LANGUAGE_NONE][0]['value'] = $measurements['osutamistearv'];
                  }
                  if (!empty($measurements['rahulolu'])) {
                    $channel_field_collection_item->field_fcf_aasta_rahulolu[LANGUAGE_NONE][0]['value'] = $measurements['rahulolu'];
                  }
                  if (!empty($measurements['halduskulu'])) {
                    $channel_field_collection_item->field_fcf_aasta_halduskulu[LANGUAGE_NONE][0]['value'] = $measurements['halduskulu'];
                  }
                  if (!empty($measurements['ajakulu'])) {
                    $channel_field_collection_item->field_fcf_ajakulu_klientidele[LANGUAGE_NONE][0]['value'] = $measurements['ajakulu'];
                  }
                  if (!empty($measurements['link'])) {
                    $channel_field_collection_item->field_fcf_viide_teenusele[LANGUAGE_NONE][0]['url'] = $measurements['link'];
                  }
                  $channel_field_collection_item->save();
                }
              }
            }
          }
          if ($new_service_saved) {
            $number_services_imported++;
          }
        }
      }
    }

    $this->importerStorage->setImporterStorageVariable(
      'services_imported_cc',
      $this->importerStorage->getImporterStorageVariable('services_imported_cc') + $number_services_imported
    );
    $this->setTaskState(self::IF_IMPORT_SERVICES, $all_nodes_imported);
    $message = sprintf('SERVICES: %d imported | started from %d nn | speed %d services / iteration | %d / %d total | at %s ',
      $number_services_imported,
      $last_importer_service_number,
      $this->importNodesPerIteration,
      $this->importerStorage->getImporterStorageVariable('services_imported_cc'),
      $total_services_to_import,
      date('H:i:s d-m-Y')
    );
    $this->logImporterAction($message)->updateStateStorage();
  }

  /**
   * Summarize import result, write log.
   */
  protected function finishImport() {
    $this->importerStorage
      ->setImporterStorageVariable('import_started', FALSE);
    $this->importerStorage
      ->setImporterStorageVariable('import_ended_date', strtotime(date('d-m-Y')));
    $this->importerStorage
      ->setImporterStorageVariable('import_ended_time', strtotime(date('H:m:s')));

    $this->setTaskState(self::IF_FINISHED, TRUE);
    $this->logImporterAction(sprintf(
      'Import finished at: %s', date('H:i:s d-m-Y')
    ))->updateStateStorage();

    $this->updateImporterLogsVariable();
    // Unset runtime logs in the importer storage varaible in case of lot of
    // logs appears.
    $this->importerStorage
      ->setImporterStorageVariable('runtime_logs', array());
    $this->updateStateStorage();

    if (self::getDrupalVariable(self::IF_ROLLBACK_MARKER, FALSE)) {
      self::mailer($this->siteEmail, sprintf('Rollback finished at: %s', date('H:m:s d-m-Y')));
      $this->setRollbackMarkerState(FALSE);
    }

    cache_clear_all('*', 'cache', TRUE);
    cache_clear_all('*', 'content', TRUE);
    cache_clear_all('*', 'cache_page', TRUE);
    cache_clear_all('*', 'cache_menu', TRUE);
    cache_clear_all('*', 'cache_filter', TRUE);
    cache_clear_all('*', 'cache_view', TRUE);
  }

  /**
   * Implementations.
   */

  /**
   * {@inheritdoc}
   */
  public static function getDrupalVariable($variable_name, $default_value = '') {
    if (is_null($variable_name) || empty($variable_name)) {
      return FALSE;
    }

    return variable_get($variable_name, $default_value);
  }

  /**
   * {@inheritdoc}
   */
  public static function setDrupalVariable($variable_name, $value) {
    if (is_null($variable_name) || empty($variable_name)) {
      return FALSE;
    }

    variable_set($variable_name, $value);
  }

  /**
   * Helper methods.
   */

  /**
   * Search for term by name.
   *
   * Searches for the term with passed name from the vocabulary with passed
   * machine name.
   *
   * Will return FALSE if term was not found or multiply terms found.
   *
   * @param string $voc_machine_name
   *   Taxonomy machine name.
   * @param string $term_name
   *   Term name.
   *
   * @return bool|mixed
   *   term id.
   */
  public function getTermByName($voc_machine_name, $term_name) {
    $default_return = FALSE;
    $search_result = taxonomy_get_term_by_name($term_name, $voc_machine_name);
    if (empty($search_result)) {
      $this->logImporterAction(sprintf(
        'No term with name found: %s (%s)',
        $term_name, $voc_machine_name
      ))->updateStateStorage();
      return $default_return;
    }
    elseif (count($search_result) > 1) {
      $this->logImporterAction(sprintf(
        'Multiply number of terms (%d) with the same name found: %s (%s)',
        count($search_result), $term_name, $voc_machine_name
      ))->updateStateStorage();
      return $default_return;
    }
    else {
      return key($search_result);
    }
  }

  /**
   * Create backup files from the API responses.
   *
   * Save API terms and services responses to the local files.
   * These fiels might be used to rollback terms and services.
   *
   * Previous day backups will be copied as today backups if rolling back.
   */
  public function createApiResponsesBackup() {
    self::clearOldExportFiles();

    $source_terms_array = $this->rollingStuffBack
      ? drupal_json_decode(file_get_contents($this->termsBackupPath)) : self::getJsonResponse($this->apiTermsUrl, self::$apiTermsCacheSuffix);
    $this->exportJsonResponseToTheFile(
      drupal_json_encode($source_terms_array),
      self::$exportTermsFileName
    );

    $source_services_array = $this->rollingStuffBack
      ? drupal_json_decode(file_get_contents($this->servicesBackupPath)) : self::getJsonResponse($this->apiServicesUrl, self::$apiServicesCacheSuffix);
    $this->exportJsonResponseToTheFile(
      drupal_json_encode($source_services_array),
      self::$exportServicesFileName
    );
  }

  /**
   * Returns JSON response from the passed URL.
   *
   * API response will be cached for the features importer execution on the
   * same day.
   *
   * @param string $url
   *   Request URL.
   * @param string $request_type
   *   This prefix will be embedded into cache key.
   *
   * @return mixed
   *   decoded json response.
   */
  public static function getJsonResponse($url, $request_type) {
    if ($cache = cache_get(self::$apiResponseCacheKey . $request_type)) {
      $json_response = $cache->data;
    }
    else {
      $ch = curl_init();
      curl_setopt($ch, CURLOPT_URL, $url);
      curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
      $json_response = curl_exec($ch);
      curl_close($ch);

      $json_response = drupal_json_decode($json_response);
      // Cache API response for the next 8 hours.
      // Cache anyway will be cleared on next initializeImporter execution.
      cache_set(self::$apiResponseCacheKey . $request_type, $json_response, 'cache', time() + 8 * 60 * 60);
    }

    return $json_response;
  }

  /**
   * Setup php max execution time or/and memory limit.
   *
   * @param int $execution_time_limit
   *   Execution time limit value.
   * @param string $memory_limit
   *   Runtime memory limit value.
   */
  public static function setPhpRuntimeConfigLimits($execution_time_limit = -1, $memory_limit = '1048M') {
    set_time_limit($execution_time_limit);
    ini_set('memory_limit', $memory_limit);
  }

  /**
   * Save messages into database with a importer specific prefix.
   *
   * Will display message instead of saving in case of
   * $this->executed_from_importer_form == TRUE, this means that importer form
   * was submitted.
   *
   * @param string $message
   *   Message to log.
   *
   * @return Importer
   *   $this.
   */
  public function logImporterAction($message) {
    if (!$this->executedFromImporterForm) {
      $message = $this->rollingStuffBack ? sprintf('ROLLBACK! > %s', $message) : $message;
      $importer_storage_logs = $this->importerStorage->getImporterStorageVariable('runtime_logs', array());
      array_push($importer_storage_logs, $message);
      $this->importerStorage
        ->setImporterStorageVariable('runtime_logs', $importer_storage_logs);

      watchdog(self::IF_WATCHDOG_KEY, $message);
    }
    else {
      drupal_set_message($message);
    }

    return $this;
  }

  /**
   * Write imploded data array to the local log file.
   *
   * @param array $data
   *   Data array to log.
   */
  public static function writeToLogs($data) {
    $path_file = $export_dir_full_path
      = drupal_get_path('module', 'rt_teenus_importer') . '/inc/logs/' . date('d_m_Y') . '.log';

    file_put_contents($path_file, implode(';;', $data) . PHP_EOL, FILE_APPEND);
  }

  /**
   * Remove riigiteenused related terms.
   *
   * @return int
   *   terms removed.
   */
  private function cleanUpTerms() {
    // Terms.
    $terms_removed = 0;
    foreach (self::getJsonResponse($this->apiTermsUrl, self::$apiTermsCacheSuffix) as $taxonomy_machine_name => $terms) {
      $taxonomy = taxonomy_vocabulary_machine_name_load($taxonomy_machine_name);
      $taxonomy_tree = taxonomy_get_tree($taxonomy->vid);
      $terms_removed += count($terms);
      foreach ($taxonomy_tree as $term) {
        // No need to use @see getTermByName method because we need to get all
        // result if case of multiply terms found.
        $multi_terms = taxonomy_get_term_by_name($term->name, $taxonomy_machine_name);
        foreach ($multi_terms as $m_term) {
          taxonomy_term_delete($m_term->tid);
        }
      }
    }

    return $terms_removed;
  }

  /**
   * Remove all services nodes.
   *
   * @return int
   *   services removed.
   */
  private function cleanUpServices() {
    // Nodes.
    $result = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('type', 'teenus', '=')
      ->execute();

    $services_removed = 0;
    if ($result->rowCount() > 0) {
      $services_removed = $result->rowCount();
      while ($nid = $result->fetchField()) {
        node_delete($nid);
      }
    }

    return $services_removed;
  }

  /**
   * Update storage state.
   *
   * Update state storage variable if Importer executed not from the importer
   * form.
   */
  private function updateStateStorage() {
    if (!$this->executedFromImporterForm) {
      $this->importerStorage->saveImporterStateStorageVariableToDb();
    }
  }

  /**
   * Update logs in the storage variable.
   *
   * Update separe logs vadriable. This variable is used to display logs on the
   * importer form.
   *
   * Importer stoge logs will be copied to the IF_STATE_LOG variable.
   */
  private function updateImporterLogsVariable() {
    self::setDrupalVariable(
      self::IF_STATE_LOG,
      drupal_json_encode($this->importerStorage->getImporterStorageVariable('runtime_logs'))
    );
  }

  /**
   * Remove old export JSON files older then 2 days.
   */
  private static function clearOldExportFiles() {
    $folder_name = drupal_get_path('module', 'rt_teenus_importer') . '/inc/' . self::$exportDirectoryName;

    if (file_exists($folder_name)) {
      foreach (new DirectoryIterator($folder_name) as $file_info) {
        if ($file_info->isDot()) {
          continue;
        }

        if ($file_info->getExtension() == 'json'
          && time() - $file_info->getCTime() >= self::IF_HOLD_BACKUPS_DAYS * 24 * 60 * 60
        ) {
          unlink($file_info->getRealPath());
        }
      }
    }
  }

  /**
   * Check importer storage variable state.
   *
   * Reset storage variable if importer was executed yesterday or if something
   * wrong with the state of the storage variable.
   */
  private function checkStorageVariable() {
    $import_running = $this->importerStorage->getImporterStorageVariable('import_started', FALSE);
    $current_date = strtotime(date('d-m-Y'));
    $last_recorded_start_date = $this->importerStorage->getImporterStorageVariable('import_start_date', NULL);
    $last_recorded_end_date = $this->importerStorage->getImporterStorageVariable('import_ended_date', NULL);

    // Check importer state if importer not running and start / end
    // dates are setted up means that importer was executed at some point.
    if (!is_null($last_recorded_start_date) && !is_null($last_recorded_end_date)) {
      if (!$import_running) {
        // Import was executed one or more day ago. Reset storage.
        if ($current_date > $last_recorded_start_date && $current_date > $last_recorded_end_date) {
          $this->importerStorage->resetStorage(FALSE);
          $this->logImporterAction('Storage is flashed!')->updateStateStorage();
        }
        // Importer was executed today. Check tasks statuses.
        elseif ($current_date == $last_recorded_start_date && $current_date == $last_recorded_end_date) {
          // Importer already worked and all tasks were successfully executed.
          // OK!
          if (array_search(FALSE, $this->importerStorage->getImporterStorageVariable('import_steps_executed')) === FALSE) {
            return;
          }
          // For some reasone some tasks were not executed.
          else {
            self::mailer($this->siteEmail, 'Looks like importer finished, but not all the tasks were executed.');
            return;
          }
        }
      }
      else {
        // Something wrong. Should reset storage variable to re-run importer.
        $this->importerStorage->resetStorage(TRUE);
        $this->logImporterAction('Storage is flashed!')->updateStateStorage();
      }
    }
    elseif (is_null($last_recorded_start_date) && !is_null($last_recorded_end_date)
      || $import_running && is_null($last_recorded_start_date) && is_null($last_recorded_end_date)
    ) {
      // Something wrong. Should reset storage variable to re-run importer.
      $this->importerStorage->resetStorage(TRUE);
      $this->logImporterAction('Storage is flashed!')->updateStateStorage();
    }
  }

  /**
   * Export JSON response to the external file.
   *
   * @param string $json_content
   *   API json response.
   * @param string $filename
   *   Export file name.
   */
  private function exportJsonResponseToTheFile($json_content, $filename) {
    $export_dir_full_path
      = drupal_get_path('module', 'rt_teenus_importer') . '/' . self::$exportDirectoryName;
    if (!is_dir($export_dir_full_path)) {
      mkdir($export_dir_full_path);
    }

    if (!is_null($json_content)) {
      $filename = str_replace('_date_', date('d_m_Y'), $filename);
      file_put_contents(
        $export_dir_full_path . '/' . $filename,
        $json_content
      );
    }
    else {
      $this->logImporterAction('Empty JSON passed to the export!')
        ->updateStateStorage();
    }
  }

  /**
   * Set task state value in the importer storage variable.
   *
   * @param string $task_name
   *   Task name.
   * @param bool $task_value
   *   Task state new value.
   */
  private function setTaskState($task_name, $task_value) {
    $importer_storage_states = $this->importerStorage->getImporterStorageVariable('import_steps_executed');
    $importer_storage_states[$task_name] = $task_value;
    $this->importerStorage
      ->setImporterStorageVariable('import_steps_executed', $importer_storage_states);
  }

  /**
   * Initialize rollback to previous state.
   *
   * This method will reset storage variable and set rollback marker to the
   * TRUE. This will cause replacement of the API source with local files and
   * iteratively import previous state back.
   *
   * Rollback will be cancelled and failure email will be send out if backup
   * files are missing.
   *
   * @param string $reason
   *   Text message why importer was initiated.
   */
  private function initializeRollback($reason) {
    if (is_file($this->termsBackupPath) && is_file($this->servicesBackupPath)) {
      $final_message = sprintf('Rollback initialized at %s. Reason: %s',
        date('H:i:s d-m-Y'), $reason
      );

      // Remove today backups.
      $export_dir_full_path
        = drupal_get_path('module', 'rt_teenus_importer') . '/' . self::$exportDirectoryName;
      $terms_backup_file
        = $export_dir_full_path . '/' . str_replace('_date_', date('d_m_Y'), self::$exportTermsFileName);
      $services_backup_file
        = $export_dir_full_path . '/' . str_replace('_date_', date('d_m_Y'), self::$exportServicesFileName);
      unlink($terms_backup_file);
      unlink($services_backup_file);

      $this->setRollbackMarkerState();
      $this->importerStorage->resetStorage(TRUE);
      $this->logImporterAction('Storage is flashed!')->updateStateStorage();
      self::mailer($this->siteEmail, $final_message);
      $this->logImporterAction($final_message)->updateStateStorage();
      $this->updateImporterLogsVariable();
    }
    else {
      $this->setRollbackMarkerState(FALSE);
      self::mailer(
        $this->siteEmail,
        sprintf('Failed initialize rollback: Backup files are partly/completely missing (backup date: %s)!', date("d_m_Y", strtotime("-1 DAY")))
      );
      $this->logImporterAction(sprintf(
        'Backup files are partly/completely missing (backup date: %s)!',
        date("d_m_Y", strtotime("-1 DAY"))
      ));
    }
  }

  /**
   * Update rollback marker variable with a passed value.
   *
   * @param bool $state
   *   New marker value.
   */
  private function setRollbackMarkerState($state = TRUE) {
    $this->rollingStuffBack = $state;
    self::setDrupalVariable(self::IF_ROLLBACK_MARKER, $state);
  }

  /**
   * Send email using @see IF_MAIL_KEY drupal mail template.
   *
   * @param string $email
   *   Recepient email address.
   * @param string $message
   *   Email message.
   */
  public static function mailer($email, $message) {
    drupal_mail('rt_teenus_importer',
      self::IF_MAIL_KEY,
      $email,
      'et',
      array('message' => $message),
      'importer@riigiteenused.ee'
    );
  }

}

/**
 * Class AbstractImporter.
 */
abstract class AbstractImporter {

  /**
   * Initialize import step.
   */
  abstract protected function initializeImport();

  /**
   * Pickup next task to execute.
   */
  abstract protected function runNextTask();

  /**
   * Clean up terms and nodes step.
   */
  abstract protected function cleanUpTermsNodes();

  /**
   * Import terms step.
   */
  abstract protected function importTerms();

  /**
   * Import services step.
   */
  abstract protected function importServices();

  /**
   * Finish import step.
   */
  abstract protected function finishImport();

}
