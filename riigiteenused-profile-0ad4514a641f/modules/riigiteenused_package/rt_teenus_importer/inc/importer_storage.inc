<?php

module_load_include('inc', 'rt_teenus_importer', 'inc/interfaces/importer_storage_interface');

/**
 * @file
 * Importer storage.
 *
 * ImporterStorage contains required methods to handle importer storage
 * variable.
 *
 * Class implements ImporterInterface and ImporterStorageInterface interfaces
 * forcing to implements methods used in the Importer class.
 */

/**
 * Class ImporterStorage.
 */
class ImporterStorage implements ImporterStorageInterface {

  // Imporeter storage specific variblaes prefix.
  const IF_STATE_STORAGE  = 'importer_state_storage';

  /*
   * Importer storage variable template.
   * Variable template is used because storage $state_storage variable
   * is resetted by the @see resetStorage() from different places and
   * $importer_state_storage is initialize at the first importer call from the
   * cron, so it's better to have initial storage varible template to reset
   * from.
   */
  private $importerStateStorageVariableTmp = array(
    'import_started' => FALSE,
    'import_start_date' => NULL,
    'import_start_time' => NULL,
    'import_ended_date' => NULL,
    'import_ended_time' => NULL,
    'terms_imported_cc' => 0,
    'services_imported_cc' => 0,
    'import_steps_executed' => array(
      Importer::IF_IMPORT_STARTED_STEP    => FALSE,
      Importer::IF_CLEAR_TERMS_AND_NODES  => FALSE,
      Importer::IF_IMPORT_TERMS           => FALSE,
      Importer::IF_IMPORT_SERVICES        => FALSE,
      Importer::IF_FINISHED               => FALSE,
    ),
    'runtime_logs' => array(),
  );

  // Importer state variable.
  private $importerStateStorage;

  /**
   * ImporterStorage constructor.
   */
  public function __construct() {
    // Load storage variable from the database if exists.
    $state_storage_variable_value
      = self::getDrupalVariable(self::IF_STATE_STORAGE, array());
    $this->importerStateStorage
      = empty($state_storage_variable_value) ? $this->importerStateStorageVariableTmp : drupal_json_decode($state_storage_variable_value);
  }

  /**
   * {@inheritdoc}
   */
  public function resetStorage($save_logs = FALSE) {
    $importer_storage_logs = $save_logs
      ? $this->getImporterStorageVariable('runtime_logs') : array();
    $this->importerStateStorage = $this->importerStateStorageVariableTmp;
    $this->setImporterStorageVariable('runtime_logs', $importer_storage_logs);
    $this->saveImporterStateStorageVariableToDb();
  }

  /**
   * {@inheritdoc}
   */
  public function setImporterStorageVariable($variable_name, $variable_value) {
    $this->importerStateStorage[$variable_name] = $variable_value;
  }

  /**
   * {@inheritdoc}
   */
  public function getImporterStorageVariable($variable_name, $default_value = '') {
    return isset($this->importerStateStorage[$variable_name])
      ? $this->importerStateStorage[$variable_name] : $default_value;
  }

  /**
   * {@inheritdoc}
   */
  public function saveImporterStateStorageVariableToDb() {
    self::setDrupalVariable(
      self::IF_STATE_STORAGE,
      drupal_json_encode($this->importerStateStorage)
    );
  }

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
}
