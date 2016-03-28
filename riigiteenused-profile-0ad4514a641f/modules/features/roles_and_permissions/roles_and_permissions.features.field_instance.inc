<?php
/**
 * @file
 * roles_and_permissions.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function roles_and_permissions_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_u_asutus'
  $field_instances['user-user-field_u_asutus'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_u_asutus',
    'label' => 'Asutus',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'shs',
      'settings' => array(
        'shs' => array(
          'create_new_levels' => 0,
          'create_new_terms' => 0,
          'force_deepest' => 0,
          'node_count' => 0,
        ),
      ),
      'type' => 'taxonomy_shs',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'user-user-field_u_teenuste_haldaja'
  $field_instances['user-user-field_u_teenuste_haldaja'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_u_teenuste_haldaja',
    'label' => 'Teenuste haldaja',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Asutus');
  t('Teenuste haldaja');

  return $field_instances;
}
