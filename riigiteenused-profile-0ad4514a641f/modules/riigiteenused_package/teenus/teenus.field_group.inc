<?php
/**
 * @file
 * teenus.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function teenus_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_t_kanaalid|node|teenus|form';
  $field_group->group_name = 'group_t_kanaalid';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'teenus';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Service channels and indicators',
    'weight' => '4',
    'children' => array(
      0 => 'field_c_mootmise_aasta',
      1 => 'field_t_mootmismetoodika',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Service channels and indicators',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_t_kanaalid|node|teenus|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_t_kanaalid|node|teenus|full';
  $field_group->group_name = 'group_t_kanaalid';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'teenus';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teenuste kanalid ja mõõdikud',
    'weight' => '3',
    'children' => array(
      0 => 'field_c_mootmise_aasta',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-t-kanaalid field-group-fieldset',
      ),
    ),
  );
  $export['group_t_kanaalid|node|teenus|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_t_lisainfo|node|teenus|form';
  $field_group->group_name = 'group_t_lisainfo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'teenus';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional information',
    'weight' => '5',
    'children' => array(
      0 => 'field_t_eeltingimused',
      1 => 'field_t_funktsioon',
      2 => 'field_t_jareltingimused',
      3 => 'field_t_konfidentsiaalne_info',
      4 => 'field_t_lisainfo',
      5 => 'field_t_makse',
      6 => 'field_t_muudatus_vajav',
      7 => 'field_t_regulatsioon',
      8 => 'field_t_seotud_dokumendid',
      9 => 'field_t_teenuse_aegumise_kp',
      10 => 'field_t_teenuse_seisund',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Additional information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-t-lisainfo field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_t_lisainfo|node|teenus|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_t_lisainfo|node|teenus|full';
  $field_group->group_name = 'group_t_lisainfo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'teenus';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Lisainfo',
    'weight' => '4',
    'children' => array(
      0 => 'field_t_eeltingimused',
      1 => 'field_t_funktsioon',
      2 => 'field_t_jareltingimused',
      3 => 'field_t_konfidentsiaalne_info',
      4 => 'field_t_lisainfo',
      5 => 'field_t_makse',
      6 => 'field_t_muudatus_vajav',
      7 => 'field_t_regulatsioon',
      8 => 'field_t_seotud_dokumendid',
      9 => 'field_t_teenuse_aegumise_kp',
      10 => 'field_t_teenuse_seisund',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-t-lisainfo field-group-fieldset',
      ),
    ),
  );
  $export['group_t_lisainfo|node|teenus|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_t_osutaja|node|teenus|form';
  $field_group->group_name = 'group_t_osutaja';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'teenus';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Service provider',
    'weight' => '1',
    'children' => array(
      0 => 'field_t_allasutus_private',
      1 => 'field_t_allasutuse_reference',
      2 => 'field_t_lisainfo_osutaja',
      3 => 'field_t_ministeerium_private',
      4 => 'field_t_osakond_yksus',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Service provider',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-t-osutaja field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_t_osutaja|node|teenus|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_t_osutaja|node|teenus|full';
  $field_group->group_name = 'group_t_osutaja';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'teenus';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teenuse osutaja',
    'weight' => '0',
    'children' => array(
      0 => 'field_t_allasutus_private',
      1 => 'field_t_lisainfo_osutaja',
      2 => 'field_t_ministeerium_private',
      3 => 'field_t_osakond_yksus',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-t-osutaja field-group-fieldset',
      ),
    ),
  );
  $export['group_t_osutaja|node|teenus|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_t_statistika|node|teenus|form';
  $field_group->group_name = 'group_t_statistika';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'teenus';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Statistics',
    'weight' => '6',
    'children' => array(
      0 => 'field_t_osutatud_teenuste_arv',
      1 => 'field_t_rahulolu',
      2 => 'field_t_maksumus',
      3 => 'field_t_kliendihaldus_koormus',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Statistics',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-t-statistika field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_t_statistika|node|teenus|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_t_statistika|node|teenus|full';
  $field_group->group_name = 'group_t_statistika';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'teenus';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Statistika',
    'weight' => '5',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-t-statistika field-group-fieldset',
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'attributes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_t_statistika|node|teenus|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_t_vastutaja_omanik|node|teenus|form';
  $field_group->group_name = 'group_t_vastutaja_omanik';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'teenus';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Service owner',
    'weight' => '3',
    'children' => array(
      0 => 'field_field_t_lisainfo_vastutaja',
      1 => 'field_t_vastutaja_ametinimetus',
      2 => 'field_t_vastutaja_email',
      3 => 'field_t_vastutaja_nimi',
      4 => 'field_t_vastutaja_telefon',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Service owner',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-t-vastutaja-omanik field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_t_vastutaja_omanik|node|teenus|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_t_vastutaja_omanik|node|teenus|full';
  $field_group->group_name = 'group_t_vastutaja_omanik';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'teenus';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teenuse vastutaja / teenuse omanik',
    'weight' => '2',
    'children' => array(
      0 => 'field_field_t_lisainfo_vastutaja',
      1 => 'field_t_vastutaja_ametinimetus',
      2 => 'field_t_vastutaja_email',
      3 => 'field_t_vastutaja_nimi',
      4 => 'field_t_vastutaja_telefon',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-t-vastutaja-omanik field-group-fieldset',
      ),
    ),
  );
  $export['group_t_vastutaja_omanik|node|teenus|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_t_yld_andmed|node|teenus|form';
  $field_group->group_name = 'group_t_yld_andmed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'teenus';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General data about the service',
    'weight' => '2',
    'children' => array(
      0 => 'field_t_kirjeldus',
      1 => 'field_t_lisainfo_uldandmed',
      2 => 'field_t_sihtgrupp',
      3 => 'field_t_syndmus',
      4 => 'field_t_teenuse_prefix',
      5 => 'field_t_teenuse_tyyp',
      6 => 'field_t_tegevusvaldkond',
      7 => 'field_t_tunnus',
      8 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'General data about the service',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-t-yld-andmed field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_t_yld_andmed|node|teenus|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_t_yld_andmed|node|teenus|full';
  $field_group->group_name = 'group_t_yld_andmed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'teenus';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teenuse üldandmed',
    'weight' => '1',
    'children' => array(
      0 => 'field_t_kirjeldus',
      1 => 'field_t_lisainfo_uldandmed',
      2 => 'field_t_sihtgrupp',
      3 => 'field_t_syndmus',
      4 => 'field_t_teenuse_prefix',
      5 => 'field_t_teenuse_tyyp',
      6 => 'field_t_tegevusvaldkond',
      7 => 'field_t_tunnus',
      8 => 'field_t_varu_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-t-yld-andmed field-group-fieldset',
      ),
    ),
  );
  $export['group_t_yld_andmed|node|teenus|full'] = $field_group;

  return $export;
}
