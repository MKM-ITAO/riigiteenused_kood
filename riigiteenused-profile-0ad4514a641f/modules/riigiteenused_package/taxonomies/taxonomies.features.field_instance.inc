<?php
/**
 * @file
 * taxonomies.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function taxonomies_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-valitsuse_puu-field_allasutuse_prefix'
  $field_instances['taxonomy_term-valitsuse_puu-field_allasutuse_prefix'] = array(
    'bundle' => 'valitsuse_puu',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_allasutuse_prefix',
    'label' => 'Allasutuse prefix',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 5,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Allasutuse prefix');

  return $field_instances;
}
