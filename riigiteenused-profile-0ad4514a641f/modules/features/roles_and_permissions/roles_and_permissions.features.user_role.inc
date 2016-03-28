<?php
/**
 * @file
 * roles_and_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function roles_and_permissions_user_default_roles() {
  $roles = array();

  // Exported role: allasutuse administraator.
  $roles['allasutuse administraator'] = array(
    'name' => 'allasutuse administraator',
    'weight' => 2,
  );

  // Exported role: ministeeriumi administraator.
  $roles['ministeeriumi administraator'] = array(
    'name' => 'ministeeriumi administraator',
    'weight' => 3,
  );

  // Exported role: valitsuse tasemel administraator.
  $roles['valitsuse tasemel administraator'] = array(
    'name' => 'valitsuse tasemel administraator',
    'weight' => 4,
  );

  return $roles;
}
