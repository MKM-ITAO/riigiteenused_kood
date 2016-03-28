<?php
/**
 * @file
 * base_configuration.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function base_configuration_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'allasutuse administraator' => 'allasutuse administraator',
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
