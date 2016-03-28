<?php
/**
 * @file
 * menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-web-portal_lisa-uus-teenus:node/add/teenus
  $menu_links['menu-web-portal_lisa-uus-teenus:node/add/teenus'] = array(
    'menu_name' => 'menu-web-portal',
    'link_path' => 'node/add/teenus',
    'router_path' => 'node/add/teenus',
    'link_title' => t('Add a new service'),
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-web-portal_lisa-uus-teenus:node/add/teenus',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  //t('Lisa uus teenus');


  return $menu_links;
}
