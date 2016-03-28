<?php

/**
 * @file
 * Importer Interface.
 *
 * ImporterInterface defines basic methods needs to be implemented by Importer*
 * classes.
 */

/**
 * Interface ImporterInterface.
 */
interface ImporterInterface {
  /**
   * Get Drupal variable value.
   *
   * Simply variable_get() drupal's function wrapper method.
   *
   * @param string $variable_name
   *   Variable name.
   * @param mixed $default_value
   *   Default value to return in case initial variable's value is not found.
   *
   * @return mixed
   *   variable value or passed default value.
   */
  public static function getDrupalVariable($variable_name, $default_value = '');

  /**
   * Set Drupal variable value.
   *
   * Simply variable_set() drupal's function wrapper method.
   *
   * @param string $variable_name
   *   Variable name.
   * @param mixed $value
   *   Variable value to set.
   *
   * @return mixed
   *   return FALSE on invalid varuable name.
   */
  public static function setDrupalVariable($variable_name, $value);

}
