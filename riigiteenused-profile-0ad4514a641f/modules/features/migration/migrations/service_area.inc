<?php

/**
 * @file
 * Riigiteenused Tegevusvaldkonnad term migration.
 */

/**
 * The ServiceAreaTermMigration uses CSV sheet as migration base.
 */
class ServiceAreaTermMigration extends RiigiteenusedMigration {
  /**
   * Constructor.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->destination = new MigrateDestinationTerm('tegevusvaldkonnad',array('allow_duplicate_terms' => TRUE));

    // Source and destination relation for rollbacks.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'Term name' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
        'Language' => array(
          'type' => 'varchar',
          'length' => 255,
          'description' => 'Language',
          'not null' => TRUE,
        ),
      ), MigrateDestinationTerm::getKeySchema()
    );

    $this->addFieldMapping('language', 'Language');
    $this->addFieldMapping('name', 'Term name');
  }
}