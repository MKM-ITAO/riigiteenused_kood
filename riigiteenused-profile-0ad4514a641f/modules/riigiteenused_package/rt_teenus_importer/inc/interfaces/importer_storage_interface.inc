<?php

/**
 * @file
 * Importer storage interface.
 *
 * Interface describes methods required for the importer class.
 */

module_load_include('inc', 'rt_teenus_importer', 'inc/interfaces/importer_interface');

/**
 * @file
 * Importer storage interface.
 *
 * ImporterStorageInterface defines methods needs to be implemented by
 * ImporterStorageClass.
 *
 * Extends ImporterInterface.
 */

/**
 * Interface ImporterStorageInterface.
 */
interface ImporterStorageInterface extends ImporterInterface {
  /**
   * Return importer storage variable value.
   *
   * @param string $variable_name
   *   Storage variable name.
   * @param mixed $default_value
   *   Default value to return if variable is not set.
   *
   * @return mixed
   *   $variable_name variable value.
   */
  public function getImporterStorageVariable($variable_name, $default_value = '');

  /**
   * Set / update importer storage varible value.
   *
   * @param string $variable_name
   *   Storage variable name.
   * @param string $variable_value
   *   Storage variable new value.
   */
  public function setImporterStorageVariable($variable_name, $variable_value);

  /**
   * Save importer state storage variable into the Drupal variable.
   */
  public function saveImporterStateStorageVariableToDb();

  /**
   * Reset importer importer storage internal variable.
   *
   * Logs will stay untouch if resetting storage for the rollback.
   *
   * @param bool $save_logs
   *   Old logs will be copied to the new storage.
   */
  public function resetStorage($save_logs = FALSE);

}
