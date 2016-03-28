<?php
/**
 * @file
 * Riigiteenused migration definition.
 */

/**
 * Implements hook_migrate_api().
 */
function migration_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'riigiteenused' => array(
        'title' => t('Riigiteenused'),
      ),
    ),
    'migrations' => array(
      'GovStructureTerm' => array(
        'class_name' => 'GovStructureTermMigration',
        'group_name' => 'riigiteenused',
        'description' => t('Import Valitsuse puu'),
        'path' => 'https://docs.google.com/spreadsheets/d/1ov-l_x8YajBQBIpcuwcjuyklORDLHDus2QQsV1vXmaU/export?gid=0&format=csv',
      ),
      'ServiceAreaTerm' => array(
        'class_name' => 'ServiceAreaTermMigration',
        'group_name' => 'riigiteenused',
        'description' => t('Import Tegevusvaldkonnad'),
        'path' => 'https://docs.google.com/spreadsheets/d/1ov-l_x8YajBQBIpcuwcjuyklORDLHDus2QQsV1vXmaU/export?gid=278585113&format=csv',
      ),
      'ServiceTypeTerm' => array(
        'class_name' => 'ServiceTypeTermMigration',
        'group_name' => 'riigiteenused',
        'description' => t('Import Teenuse tüübid'),
        'path' => 'https://docs.google.com/spreadsheets/d/1ov-l_x8YajBQBIpcuwcjuyklORDLHDus2QQsV1vXmaU/export?gid=1683370865&format=csv',
      ),
      'MeasurementYearsTerm' => array(
        'class_name' => 'MeasurementYearsTermMigration',
        'group_name' => 'riigiteenused',
        'description' => t('Import Mõõtmise aastad'),
        'path' => 'https://docs.google.com/spreadsheets/d/1ov-l_x8YajBQBIpcuwcjuyklORDLHDus2QQsV1vXmaU/export?gid=1021100294&format=csv',
      ),
      'ChannelsStructureTerm' => array(
        'class_name' => 'ChannelsStructureTermMigration',
        'group_name' => 'riigiteenused',
        'description' => t('Import Kanaalide struktuur'),
        'path' => 'https://docs.google.com/spreadsheets/d/1ov-l_x8YajBQBIpcuwcjuyklORDLHDus2QQsV1vXmaU/export?gid=1953460327&format=csv',
      ),
    )
  );

  return $api;
}

abstract class RiigiteenusedMigration extends Migration {
  /**
   * @var path
   *  Path to our CSV file (may be remote)
   */
  protected $path;

  /**
   * Constructor.
   */
  public function __construct($arguments) {
    parent::__construct();

    ini_set("auto_detect_line_endings", true);
    if (isset($arguments['path'])) {
      $cached_file = 'public://' . get_class($this) . '.csv';
      if (file_exists($cached_file)) {
        $this->path = $cached_file;
      } else {
        $this->path = $arguments['path'];
      }
    }

    if (isset($arguments['description'])) {
      $this->description = $arguments['description'];
    }

    if (isset($arguments['dependencies'])) {
      $this->dependencies = $arguments['dependencies'];
    }

    $this->source = new MigrateSourceCSV(
      $this->path,
      array(),
      array('header_rows' => isset($arguments['header_rows']) ? $arguments['header_rows'] : 1, 'embedded_newlines' => TRUE)
    );

    $this->team = array(
      new MigrateTeamMember(
        'Ilia Ivanov',
        'ilia.ivanov@wunderkraut.com',
        t('Implementer')
      ),
    );

  }
}
