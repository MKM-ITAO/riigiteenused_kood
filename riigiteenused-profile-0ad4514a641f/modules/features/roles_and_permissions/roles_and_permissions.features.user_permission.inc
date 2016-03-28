<?php
/**
 * @file
 * roles_and_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function roles_and_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'allasutuse administraator' => 'allasutuse administraator',
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'allasutuse administraator' => 'allasutuse administraator',
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'allasutuse administraator' => 'allasutuse administraator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'allasutuse administraator' => 'allasutuse administraator',
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'allasutuse administraator' => 'allasutuse administraator',
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'create teenus content'.
  $permissions['create teenus content'] = array(
    'name' => 'create teenus content',
    'roles' => array(
      'allasutuse administraator' => 'allasutuse administraator',
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'delete any teenus content'.
  $permissions['delete any teenus content'] = array(
    'name' => 'delete any teenus content',
    'roles' => array(
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own teenus content'.
  $permissions['delete own teenus content'] = array(
    'name' => 'delete own teenus content',
    'roles' => array(
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in kanaalide_struktuur'.
  $permissions['delete terms in kanaalide_struktuur'] = array(
    'name' => 'delete terms in kanaalide_struktuur',
    'roles' => array(
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in mootmise_aastad'.
  $permissions['delete terms in mootmise_aastad'] = array(
    'name' => 'delete terms in mootmise_aastad',
    'roles' => array(
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in teenuse_tyybid'.
  $permissions['delete terms in teenuse_tyybid'] = array(
    'name' => 'delete terms in teenuse_tyybid',
    'roles' => array(
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tegevusvaldkonnad'.
  $permissions['delete terms in tegevusvaldkonnad'] = array(
    'name' => 'delete terms in tegevusvaldkonnad',
    'roles' => array(
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in valitsuse_puu'.
  $permissions['delete terms in valitsuse_puu'] = array(
    'name' => 'delete terms in valitsuse_puu',
    'roles' => array(
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any teenus content'.
  $permissions['edit any teenus content'] = array(
    'name' => 'edit any teenus content',
    'roles' => array(
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own institutions content'.
  $permissions['edit own institutions content'] = array(
    'name' => 'edit own institutions content',
    'roles' => array(
      'allasutuse administraator' => 'allasutuse administraator',
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'roles_and_permissions',
  );

  // Exported permission: 'edit own ministries content'.
  $permissions['edit own ministries content'] = array(
    'name' => 'edit own ministries content',
    'roles' => array(
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'roles_and_permissions',
  );

  // Exported permission: 'edit own teenus content'.
  $permissions['edit own teenus content'] = array(
    'name' => 'edit own teenus content',
    'roles' => array(
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in kanaalide_struktuur'.
  $permissions['edit terms in kanaalide_struktuur'] = array(
    'name' => 'edit terms in kanaalide_struktuur',
    'roles' => array(
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in mootmise_aastad'.
  $permissions['edit terms in mootmise_aastad'] = array(
    'name' => 'edit terms in mootmise_aastad',
    'roles' => array(
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in teenuse_tyybid'.
  $permissions['edit terms in teenuse_tyybid'] = array(
    'name' => 'edit terms in teenuse_tyybid',
    'roles' => array(
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tegevusvaldkonnad'.
  $permissions['edit terms in tegevusvaldkonnad'] = array(
    'name' => 'edit terms in tegevusvaldkonnad',
    'roles' => array(
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in valitsuse_puu'.
  $permissions['edit terms in valitsuse_puu'] = array(
    'name' => 'edit terms in valitsuse_puu',
    'roles' => array(
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'schedule (un)publishing of nodes'.
  $permissions['schedule (un)publishing of nodes'] = array(
    'name' => 'schedule (un)publishing of nodes',
    'roles' => array(
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      'allasutuse administraator' => 'allasutuse administraator',
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate any entity'.
  $permissions['translate any entity'] = array(
    'name' => 'translate any entity',
    'roles' => array(
      'allasutuse administraator' => 'allasutuse administraator',
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate content'.
  $permissions['translate content'] = array(
    'name' => 'translate content',
    'roles' => array(
      'allasutuse administraator' => 'allasutuse administraator',
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'translation',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'allasutuse administraator' => 'allasutuse administraator',
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate node entities'.
  $permissions['translate node entities'] = array(
    'name' => 'translate node entities',
    'roles' => array(
      'allasutuse administraator' => 'allasutuse administraator',
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate taxonomy_term entities'.
  $permissions['translate taxonomy_term entities'] = array(
    'name' => 'translate taxonomy_term entities',
    'roles' => array(
      'allasutuse administraator' => 'allasutuse administraator',
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'allasutuse administraator' => 'allasutuse administraator',
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'allasutuse administraator' => 'allasutuse administraator',
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view scheduled content'.
  $permissions['view scheduled content'] = array(
    'name' => 'view scheduled content',
    'roles' => array(
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'allasutuse administraator' => 'allasutuse administraator',
      'ministeeriumi administraator' => 'ministeeriumi administraator',
      'valitsuse tasemel administraator' => 'valitsuse tasemel administraator',
    ),
    'module' => 'system',
  );

  return $permissions;
}
