<?php
/**
 * @file
 * teenus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function teenus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_haldusala-e-teenused:statistika/ministeerium/35
  $menu_links['main-menu_haldusala-e-teenused:statistika/ministeerium/35'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'statistika/ministeerium/35',
    'router_path' => 'statistika/ministeerium',
    'link_title' => 'Haldusala e-teenused',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_haldusala-e-teenused:statistika/ministeerium/35',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Haldusala e-teenused');


  return $menu_links;
}
