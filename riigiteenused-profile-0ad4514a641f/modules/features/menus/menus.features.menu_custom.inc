<?php
/**
 * @file
 * menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-web-portal.
  $menus['menu-web-portal'] = array(
    'menu_name' => 'menu-web-portal',
    'title' => 'Web portal',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Web portal');


  return $menus;
}
