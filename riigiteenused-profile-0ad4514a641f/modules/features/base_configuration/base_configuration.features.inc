<?php
/**
 * @file
 * base_configuration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function base_configuration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
