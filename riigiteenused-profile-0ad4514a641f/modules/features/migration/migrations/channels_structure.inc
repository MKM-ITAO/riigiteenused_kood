<?php

/**
 * @file
 * Riigiteenused Kanaalide struktuur term migration.
 */

/**
 * The ChannelsStructureTermMigration uses CSV sheet as migration base.
 */
class ChannelsStructureTermMigration extends RiigiteenusedMigration {
  /**
   * Constructor.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->destination = new MigrateDestinationTerm('kanaalide_struktuur',array('allow_duplicate_terms' => TRUE));

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
    $this->addFieldMapping('parent_name', 'Parent');
  }
}
