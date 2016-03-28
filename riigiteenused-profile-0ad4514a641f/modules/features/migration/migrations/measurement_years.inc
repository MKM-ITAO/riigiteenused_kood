<?php

/**
 * @file
 * Riigiteenused Mõõtmise aastad term migration.
 */

/**
 * The MeasurementYearsTermMigration uses CSV sheet as migration base.
 */
class MeasurementYearsTermMigration extends RiigiteenusedMigration {
  /**
   * Constructor.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->destination = new MigrateDestinationTerm('mootmise_aastad',array('allow_duplicate_terms' => TRUE));

    // Source and destination relation for rollbacks.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'Term name' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ), MigrateDestinationTerm::getKeySchema()
    );

    $this->addFieldMapping('name', 'Term name');
  }
}