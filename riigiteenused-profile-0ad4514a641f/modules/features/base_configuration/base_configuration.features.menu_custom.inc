<?php
/**
 * @file
 * base_configuration.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function base_configuration_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-web-portal.
  $menus['menu-web-portal'] = array(
    'menu_name' => 'menu-web-portal',
    'title' => 'Web portal',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Web portal');


  return $menus;
}
