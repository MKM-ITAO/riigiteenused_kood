<?php
/**
 * @file
 * services_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function services_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'teenuste_otsing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Teenuste otsing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Teenuste otsing';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reset filters';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sort';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 0,
        'combine_param' => 'sort_bef_combine',
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
        'secondary_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'title' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_t_kirjeldus_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_t_allasutuse_reference_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_select_all_none_nested' => 0,
        'bef_collapsible' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_t_sihtgrupp_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_t_teenuse_tyyp_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_fcf_kanal_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_select_all_none_nested' => 0,
        'bef_collapsible' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_t_tegevusvaldkond_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_select_all_none_nested' => 0,
        'bef_collapsible' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'plain_text';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_t_sihtgrupp' => 'field_t_sihtgrupp',
    'field_t_tegevusvaldkond' => 'field_t_tegevusvaldkond',
    'field_t_teenuse_tyyp' => 'field_t_teenuse_tyyp',
    'view' => 'view',
  );
  /* Header: Custom text: Page title */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['ui_name'] = 'Custom text: Page title';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h1>Teenuste otsing</h1>';
  /* Header: Custom text: Search description text */
  $handler->display->display_options['header']['area_text_custom_1']['id'] = 'area_text_custom_1';
  $handler->display->display_options['header']['area_text_custom_1']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom_1']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom_1']['ui_name'] = 'Custom text: Search description text';
  $handler->display->display_options['header']['area_text_custom_1']['content'] = '<div class="view-description-text">
Siin lehel saad erinevate tunnuste abil otsida Majandus- ja Kommunikatsiooniministeeriumi haldusala teenuseid.
</div>';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom_1']['id'] = 'area_text_custom_1';
  $handler->display->display_options['empty']['area_text_custom_1']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom_1']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom_1']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom_1']['content'] = '<div class="no-result-found">
No e-service corresponds to such a combination of filters.
<a href="/teenuste-otsing" class="search-reset-filters">Reset filters</a>
</div>';
  /* Relationship: Content: Measurement year and channels (field_c_mootmise_aasta) */
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['id'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['table'] = 'field_data_field_c_mootmise_aasta';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['field'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['label'] = 'Mõõdetud aasta';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['delta'] = '-1';
  /* Relationship: Field collection item: Mõõtmise kanal (field_fcf_mootmise_kanal) */
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['id'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['table'] = 'field_data_field_fcf_mootmise_kanal';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['field'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['relationship'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['label'] = 'Mõõdetud kanalid';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['delta'] = '-1';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h4';
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_t_kirjeldus']['id'] = 'field_t_kirjeldus';
  $handler->display->display_options['fields']['field_t_kirjeldus']['table'] = 'field_data_field_t_kirjeldus';
  $handler->display->display_options['fields']['field_t_kirjeldus']['field'] = 'field_t_kirjeldus';
  $handler->display->display_options['fields']['field_t_kirjeldus']['label'] = '';
  $handler->display->display_options['fields']['field_t_kirjeldus']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_t_kirjeldus']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['field_t_kirjeldus']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_t_kirjeldus']['element_label_colon'] = FALSE;
  /* Field: Target group */
  $handler->display->display_options['fields']['field_t_sihtgrupp']['id'] = 'field_t_sihtgrupp';
  $handler->display->display_options['fields']['field_t_sihtgrupp']['table'] = 'field_data_field_t_sihtgrupp';
  $handler->display->display_options['fields']['field_t_sihtgrupp']['field'] = 'field_t_sihtgrupp';
  $handler->display->display_options['fields']['field_t_sihtgrupp']['ui_name'] = 'Target group';
  $handler->display->display_options['fields']['field_t_sihtgrupp']['label'] = '';
  $handler->display->display_options['fields']['field_t_sihtgrupp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_t_sihtgrupp']['delta_offset'] = '0';
  /* Field: Tegevusvaldkond */
  $handler->display->display_options['fields']['field_t_tegevusvaldkond']['id'] = 'field_t_tegevusvaldkond';
  $handler->display->display_options['fields']['field_t_tegevusvaldkond']['table'] = 'field_data_field_t_tegevusvaldkond';
  $handler->display->display_options['fields']['field_t_tegevusvaldkond']['field'] = 'field_t_tegevusvaldkond';
  $handler->display->display_options['fields']['field_t_tegevusvaldkond']['ui_name'] = 'Tegevusvaldkond';
  $handler->display->display_options['fields']['field_t_tegevusvaldkond']['label'] = '';
  $handler->display->display_options['fields']['field_t_tegevusvaldkond']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_t_tegevusvaldkond']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Tüüp */
  $handler->display->display_options['fields']['field_t_teenuse_tyyp']['id'] = 'field_t_teenuse_tyyp';
  $handler->display->display_options['fields']['field_t_teenuse_tyyp']['table'] = 'field_data_field_t_teenuse_tyyp';
  $handler->display->display_options['fields']['field_t_teenuse_tyyp']['field'] = 'field_t_teenuse_tyyp';
  $handler->display->display_options['fields']['field_t_teenuse_tyyp']['ui_name'] = 'Tüüp';
  $handler->display->display_options['fields']['field_t_teenuse_tyyp']['label'] = '';
  $handler->display->display_options['fields']['field_t_teenuse_tyyp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_t_teenuse_tyyp']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Kanal */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['ui_name'] = 'Kanal';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'teenuste_statistika';
  $handler->display->display_options['fields']['view']['display'] = 'teenuse_prioriteetsem_kanal';
  $handler->display->display_options['fields']['view']['arguments'] = '[!nid]';
  /* Field: Eeltingimused */
  $handler->display->display_options['fields']['field_t_eeltingimused']['id'] = 'field_t_eeltingimused';
  $handler->display->display_options['fields']['field_t_eeltingimused']['table'] = 'field_data_field_t_eeltingimused';
  $handler->display->display_options['fields']['field_t_eeltingimused']['field'] = 'field_t_eeltingimused';
  $handler->display->display_options['fields']['field_t_eeltingimused']['ui_name'] = 'Eeltingimused';
  $handler->display->display_options['fields']['field_t_eeltingimused']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_t_eeltingimused']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_t_eeltingimused']['element_wrapper_class'] = 'service-conditions';
  /* Field: Kõik teenuse kanalid */
  $handler->display->display_options['fields']['view_1']['id'] = 'view_1';
  $handler->display->display_options['fields']['view_1']['table'] = 'views';
  $handler->display->display_options['fields']['view_1']['field'] = 'view';
  $handler->display->display_options['fields']['view_1']['ui_name'] = 'Kõik teenuse kanalid';
  $handler->display->display_options['fields']['view_1']['label'] = 'Kõik teenuse kanalid';
  $handler->display->display_options['fields']['view_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['view_1']['element_wrapper_class'] = 'service-statistic';
  $handler->display->display_options['fields']['view_1']['view'] = 'kanaalite_statistika';
  $handler->display->display_options['fields']['view_1']['display'] = 'teenuse_kanalite_list';
  $handler->display->display_options['fields']['view_1']['arguments'] = '[!nid]';
  /* Field: Statistika */
  $handler->display->display_options['fields']['view_2']['id'] = 'view_2';
  $handler->display->display_options['fields']['view_2']['table'] = 'views';
  $handler->display->display_options['fields']['view_2']['field'] = 'view';
  $handler->display->display_options['fields']['view_2']['ui_name'] = 'Statistika';
  $handler->display->display_options['fields']['view_2']['label'] = 'Statistics';
  $handler->display->display_options['fields']['view_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_2']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['view_2']['element_wrapper_class'] = 'service-statistic';
  $handler->display->display_options['fields']['view_2']['view'] = 'kanaalite_statistika';
  $handler->display->display_options['fields']['view_2']['display'] = 'teenuse_kanalite_statistika_yldnumbrid';
  $handler->display->display_options['fields']['view_2']['arguments'] = '[!nid]';
  /* Field: Content: Regulation */
  $handler->display->display_options['fields']['field_t_regulatsioon']['id'] = 'field_t_regulatsioon';
  $handler->display->display_options['fields']['field_t_regulatsioon']['table'] = 'field_data_field_t_regulatsioon';
  $handler->display->display_options['fields']['field_t_regulatsioon']['field'] = 'field_t_regulatsioon';
  $handler->display->display_options['fields']['field_t_regulatsioon']['label'] = 'Regulatsioon';
  $handler->display->display_options['fields']['field_t_regulatsioon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_t_regulatsioon']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_t_regulatsioon']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_t_regulatsioon']['delta_offset'] = '0';
  /* Sort criterion: Content: The amount of rendered services (field_t_osutatud_teenuste_arv) */
  $handler->display->display_options['sorts']['field_t_osutatud_teenuste_arv_value']['id'] = 'field_t_osutatud_teenuste_arv_value';
  $handler->display->display_options['sorts']['field_t_osutatud_teenuste_arv_value']['table'] = 'field_data_field_t_osutatud_teenuste_arv';
  $handler->display->display_options['sorts']['field_t_osutatud_teenuste_arv_value']['field'] = 'field_t_osutatud_teenuste_arv_value';
  $handler->display->display_options['sorts']['field_t_osutatud_teenuste_arv_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_t_osutatud_teenuste_arv_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_t_osutatud_teenuste_arv_value']['expose']['label'] = 'Populaarsemad ees';
  /* Sort criterion: A-Ü */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['ui_name'] = 'A-Ü';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'A-Ü';
  /* Sort criterion: Ü-A */
  $handler->display->display_options['sorts']['title_1']['id'] = 'title_1';
  $handler->display->display_options['sorts']['title_1']['table'] = 'node';
  $handler->display->display_options['sorts']['title_1']['field'] = 'title';
  $handler->display->display_options['sorts']['title_1']['ui_name'] = 'Ü-A';
  $handler->display->display_options['sorts']['title_1']['order'] = 'DESC';
  $handler->display->display_options['sorts']['title_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title_1']['expose']['label'] = 'Ü-A';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title_2']['id'] = 'title_2';
  $handler->display->display_options['sorts']['title_2']['table'] = 'node';
  $handler->display->display_options['sorts']['title_2']['field'] = 'title';
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'unformatted_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['summary_options']['inline'] = TRUE;
  $handler->display->display_options['arguments']['title']['summary_options']['separator'] = '|';
  $handler->display->display_options['arguments']['title']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
  $handler->display->display_options['arguments']['title']['case'] = 'upper';
  $handler->display->display_options['arguments']['title']['path_case'] = 'lower';
  $handler->display->display_options['arguments']['title']['break_phrase'] = TRUE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    3 => 'AND',
    2 => 'AND',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Keyword';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title-search';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Description (field_t_kirjeldus) */
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['id'] = 'field_t_kirjeldus_value';
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['table'] = 'field_data_field_t_kirjeldus';
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['field'] = 'field_t_kirjeldus_value';
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['group'] = 1;
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['expose']['operator_id'] = 'field_t_kirjeldus_value_op';
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['expose']['label'] = 'Description';
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['expose']['operator'] = 'field_t_kirjeldus_value_op';
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['expose']['identifier'] = 'field_t_kirjeldus_value';
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 2;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'teenus' => 'teenus',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  /* Filter criterion: Content: Subdivision&#039;s reference (field_t_allasutuse_reference) */
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['id'] = 'field_t_allasutuse_reference_tid';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['table'] = 'field_data_field_t_allasutuse_reference';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['field'] = 'field_t_allasutuse_reference_tid';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['expose']['operator_id'] = 'field_t_allasutuse_reference_tid_op';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['expose']['label'] = 'Asutus';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['expose']['operator'] = 'field_t_allasutuse_reference_tid_op';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['expose']['identifier'] = 'field_t_allasutuse_reference_tid';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['vocabulary'] = 'valitsuse_puu';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Target group (field_t_sihtgrupp) */
  $handler->display->display_options['filters']['field_t_sihtgrupp_value']['id'] = 'field_t_sihtgrupp_value';
  $handler->display->display_options['filters']['field_t_sihtgrupp_value']['table'] = 'field_data_field_t_sihtgrupp';
  $handler->display->display_options['filters']['field_t_sihtgrupp_value']['field'] = 'field_t_sihtgrupp_value';
  $handler->display->display_options['filters']['field_t_sihtgrupp_value']['group'] = 2;
  $handler->display->display_options['filters']['field_t_sihtgrupp_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_t_sihtgrupp_value']['expose']['operator_id'] = 'field_t_sihtgrupp_value_op';
  $handler->display->display_options['filters']['field_t_sihtgrupp_value']['expose']['label'] = 'Sihtgrupp';
  $handler->display->display_options['filters']['field_t_sihtgrupp_value']['expose']['operator'] = 'field_t_sihtgrupp_value_op';
  $handler->display->display_options['filters']['field_t_sihtgrupp_value']['expose']['identifier'] = 'field_t_sihtgrupp_value';
  $handler->display->display_options['filters']['field_t_sihtgrupp_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_t_sihtgrupp_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Type (field_t_teenuse_tyyp) */
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['id'] = 'field_t_teenuse_tyyp_tid';
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['table'] = 'field_data_field_t_teenuse_tyyp';
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['field'] = 'field_t_teenuse_tyyp_tid';
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['expose']['operator_id'] = 'field_t_teenuse_tyyp_tid_op';
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['expose']['label'] = 'Service type';
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['expose']['operator'] = 'field_t_teenuse_tyyp_tid_op';
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['expose']['identifier'] = 'field_t_teenuse_tyyp_tid';
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['vocabulary'] = 'teenuse_tyybid';
  /* Filter criterion: Field collection item: Kanal (field_fcf_kanal) */
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['id'] = 'field_fcf_kanal_tid';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['table'] = 'field_data_field_fcf_kanal';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['field'] = 'field_fcf_kanal_tid';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['relationship'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['expose']['operator_id'] = 'field_fcf_kanal_tid_op';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['expose']['label'] = 'Service channel';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['expose']['operator'] = 'field_fcf_kanal_tid_op';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['expose']['identifier'] = 'field_fcf_kanal_tid';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['vocabulary'] = 'kanaalide_struktuur';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Domain (field_t_tegevusvaldkond) */
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['id'] = 'field_t_tegevusvaldkond_tid';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['table'] = 'field_data_field_t_tegevusvaldkond';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['field'] = 'field_t_tegevusvaldkond_tid';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['expose']['operator_id'] = 'field_t_tegevusvaldkond_tid_op';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['expose']['label'] = 'Tegevusvaldkond';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['expose']['operator'] = 'field_t_tegevusvaldkond_tid_op';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['expose']['identifier'] = 'field_t_tegevusvaldkond_tid';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['vocabulary'] = 'tegevusvaldkonnad';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: The status of the service (field_t_teenuse_seisund) */
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['id'] = 'field_t_teenuse_seisund_value';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['table'] = 'field_data_field_t_teenuse_seisund';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['field'] = 'field_t_teenuse_seisund_value';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['value'] = array(
    'all' => 'all',
    'Aktiivne' => 'Aktiivne',
    'Arhiveeritud' => 'Arhiveeritud',
    'Muudatust vajav' => 'Muudatust vajav',
  );
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['group'] = 2;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 3;

  /* Display: Teenuste otsing page */
  $handler = $view->new_display('page', 'Teenuste otsing page', 'teenuste_otsing_page');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reset filters';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sort';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 0,
        'combine_param' => 'sort_bef_combine',
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
        'secondary_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'title' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_t_kirjeldus_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_t_allasutuse_reference_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_select_all_none_nested' => 0,
        'bef_collapsible' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_t_sihtgrupp_value_i18n' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_t_teenuse_tyyp_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_fcf_kanal_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_select_all_none_nested' => 0,
        'bef_collapsible' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_t_tegevusvaldkond_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_select_all_none_nested' => 0,
        'bef_collapsible' => 1,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'plain_text';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom_1']['id'] = 'area_text_custom_1';
  $handler->display->display_options['empty']['area_text_custom_1']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom_1']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom_1']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom_1']['content'] = '<div class="no-result-found">
No e-service corresponds to such a combination of filters.
<a href="/teenuste-otsing" class="search-reset-filters">Reset filters</a>
</div>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_t_kirjeldus']['id'] = 'field_t_kirjeldus';
  $handler->display->display_options['fields']['field_t_kirjeldus']['table'] = 'field_data_field_t_kirjeldus';
  $handler->display->display_options['fields']['field_t_kirjeldus']['field'] = 'field_t_kirjeldus';
  $handler->display->display_options['fields']['field_t_kirjeldus']['label'] = '';
  $handler->display->display_options['fields']['field_t_kirjeldus']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_t_kirjeldus']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['field_t_kirjeldus']['element_label_colon'] = FALSE;
  /* Field: Sihtgrupp */
  $handler->display->display_options['fields']['field_t_sihtgrupp']['id'] = 'field_t_sihtgrupp';
  $handler->display->display_options['fields']['field_t_sihtgrupp']['table'] = 'field_data_field_t_sihtgrupp';
  $handler->display->display_options['fields']['field_t_sihtgrupp']['field'] = 'field_t_sihtgrupp';
  $handler->display->display_options['fields']['field_t_sihtgrupp']['ui_name'] = 'Sihtgrupp';
  $handler->display->display_options['fields']['field_t_sihtgrupp']['label'] = '';
  $handler->display->display_options['fields']['field_t_sihtgrupp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_t_sihtgrupp']['type'] = 'i18n_list_default';
  $handler->display->display_options['fields']['field_t_sihtgrupp']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_t_sihtgrupp']['delta_offset'] = '0';
  /* Field: Domain */
  $handler->display->display_options['fields']['field_t_tegevusvaldkond']['id'] = 'field_t_tegevusvaldkond';
  $handler->display->display_options['fields']['field_t_tegevusvaldkond']['table'] = 'field_data_field_t_tegevusvaldkond';
  $handler->display->display_options['fields']['field_t_tegevusvaldkond']['field'] = 'field_t_tegevusvaldkond';
  $handler->display->display_options['fields']['field_t_tegevusvaldkond']['ui_name'] = 'Domain';
  $handler->display->display_options['fields']['field_t_tegevusvaldkond']['label'] = '';
  $handler->display->display_options['fields']['field_t_tegevusvaldkond']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_t_tegevusvaldkond']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Tüüp */
  $handler->display->display_options['fields']['field_t_teenuse_tyyp']['id'] = 'field_t_teenuse_tyyp';
  $handler->display->display_options['fields']['field_t_teenuse_tyyp']['table'] = 'field_data_field_t_teenuse_tyyp';
  $handler->display->display_options['fields']['field_t_teenuse_tyyp']['field'] = 'field_t_teenuse_tyyp';
  $handler->display->display_options['fields']['field_t_teenuse_tyyp']['ui_name'] = 'Tüüp';
  $handler->display->display_options['fields']['field_t_teenuse_tyyp']['label'] = '';
  $handler->display->display_options['fields']['field_t_teenuse_tyyp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_t_teenuse_tyyp']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Kanal */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['ui_name'] = 'Kanal';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'teenuste_statistika';
  $handler->display->display_options['fields']['view']['display'] = 'teenuse_prioriteetsem_kanal';
  $handler->display->display_options['fields']['view']['arguments'] = '[!nid]';
  /* Field: Eeltingimused */
  $handler->display->display_options['fields']['field_t_eeltingimused']['id'] = 'field_t_eeltingimused';
  $handler->display->display_options['fields']['field_t_eeltingimused']['table'] = 'field_data_field_t_eeltingimused';
  $handler->display->display_options['fields']['field_t_eeltingimused']['field'] = 'field_t_eeltingimused';
  $handler->display->display_options['fields']['field_t_eeltingimused']['ui_name'] = 'Eeltingimused';
  $handler->display->display_options['fields']['field_t_eeltingimused']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_t_eeltingimused']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_t_eeltingimused']['element_wrapper_class'] = 'service-conditions';
  $handler->display->display_options['fields']['field_t_eeltingimused']['hide_empty'] = TRUE;
  /* Field: Kõik teenuse kanalid */
  $handler->display->display_options['fields']['view_1']['id'] = 'view_1';
  $handler->display->display_options['fields']['view_1']['table'] = 'views';
  $handler->display->display_options['fields']['view_1']['field'] = 'view';
  $handler->display->display_options['fields']['view_1']['ui_name'] = 'Kõik teenuse kanalid';
  $handler->display->display_options['fields']['view_1']['label'] = 'All service channels';
  $handler->display->display_options['fields']['view_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['view_1']['element_wrapper_class'] = 'service-statistic';
  $handler->display->display_options['fields']['view_1']['view'] = 'kanaalite_statistika';
  $handler->display->display_options['fields']['view_1']['display'] = 'teenuse_kanalite_list';
  $handler->display->display_options['fields']['view_1']['arguments'] = '[!nid]';
  /* Field: Statistika */
  $handler->display->display_options['fields']['view_2']['id'] = 'view_2';
  $handler->display->display_options['fields']['view_2']['table'] = 'views';
  $handler->display->display_options['fields']['view_2']['field'] = 'view';
  $handler->display->display_options['fields']['view_2']['ui_name'] = 'Statistika';
  $handler->display->display_options['fields']['view_2']['label'] = 'Statistics';
  $handler->display->display_options['fields']['view_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_2']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['view_2']['element_wrapper_class'] = 'service-statistic';
  $handler->display->display_options['fields']['view_2']['view'] = 'kanaalite_statistika';
  $handler->display->display_options['fields']['view_2']['display'] = 'teenuse_kanalite_statistika_yldnumbrid';
  $handler->display->display_options['fields']['view_2']['arguments'] = '[!nid]';
  /* Field: Content: Regulation */
  $handler->display->display_options['fields']['field_t_regulatsioon']['id'] = 'field_t_regulatsioon';
  $handler->display->display_options['fields']['field_t_regulatsioon']['table'] = 'field_data_field_t_regulatsioon';
  $handler->display->display_options['fields']['field_t_regulatsioon']['field'] = 'field_t_regulatsioon';
  $handler->display->display_options['fields']['field_t_regulatsioon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_t_regulatsioon']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_t_regulatsioon']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_t_regulatsioon']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_t_regulatsioon']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_t_regulatsioon']['separator'] = '';
  /* Field: Content: Expiration date of the service */
  $handler->display->display_options['fields']['field_t_teenuse_aegumise_kp']['id'] = 'field_t_teenuse_aegumise_kp';
  $handler->display->display_options['fields']['field_t_teenuse_aegumise_kp']['table'] = 'field_data_field_t_teenuse_aegumise_kp';
  $handler->display->display_options['fields']['field_t_teenuse_aegumise_kp']['field'] = 'field_t_teenuse_aegumise_kp';
  $handler->display->display_options['fields']['field_t_teenuse_aegumise_kp']['label'] = 'Aegub';
  $handler->display->display_options['fields']['field_t_teenuse_aegumise_kp']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_t_teenuse_aegumise_kp']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Payment */
  $handler->display->display_options['fields']['field_t_makse']['id'] = 'field_t_makse';
  $handler->display->display_options['fields']['field_t_makse']['table'] = 'field_data_field_t_makse';
  $handler->display->display_options['fields']['field_t_makse']['field'] = 'field_t_makse';
  $handler->display->display_options['fields']['field_t_makse']['label'] = '';
  $handler->display->display_options['fields']['field_t_makse']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_t_makse']['type'] = 'i18n_list_default';
  /* Field: Content: The status of the service */
  $handler->display->display_options['fields']['field_t_teenuse_seisund']['id'] = 'field_t_teenuse_seisund';
  $handler->display->display_options['fields']['field_t_teenuse_seisund']['table'] = 'field_data_field_t_teenuse_seisund';
  $handler->display->display_options['fields']['field_t_teenuse_seisund']['field'] = 'field_t_teenuse_seisund';
  $handler->display->display_options['fields']['field_t_teenuse_seisund']['label'] = '';
  $handler->display->display_options['fields']['field_t_teenuse_seisund']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_t_teenuse_seisund']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_t_teenuse_seisund']['type'] = 'i18n_list_default';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Look details';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: The amount of rendered services (field_t_osutatud_teenuste_arv) */
  $handler->display->display_options['sorts']['field_t_osutatud_teenuste_arv_value']['id'] = 'field_t_osutatud_teenuste_arv_value';
  $handler->display->display_options['sorts']['field_t_osutatud_teenuste_arv_value']['table'] = 'field_data_field_t_osutatud_teenuste_arv';
  $handler->display->display_options['sorts']['field_t_osutatud_teenuste_arv_value']['field'] = 'field_t_osutatud_teenuste_arv_value';
  $handler->display->display_options['sorts']['field_t_osutatud_teenuste_arv_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_t_osutatud_teenuste_arv_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_t_osutatud_teenuste_arv_value']['expose']['label'] = 'Popular pages first';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title_2']['id'] = 'title_2';
  $handler->display->display_options['sorts']['title_2']['table'] = 'node';
  $handler->display->display_options['sorts']['title_2']['field'] = 'title';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title_4']['id'] = 'title_4';
  $handler->display->display_options['sorts']['title_4']['table'] = 'node';
  $handler->display->display_options['sorts']['title_4']['field'] = 'title';
  $handler->display->display_options['sorts']['title_4']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title_4']['expose']['label'] = 'A-Ü';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title_3']['id'] = 'title_3';
  $handler->display->display_options['sorts']['title_3']['table'] = 'node';
  $handler->display->display_options['sorts']['title_3']['field'] = 'title';
  $handler->display->display_options['sorts']['title_3']['order'] = 'DESC';
  $handler->display->display_options['sorts']['title_3']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title_3']['expose']['label'] = 'Ü-A';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    3 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Keyword';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title-search';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Description (field_t_kirjeldus) */
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['id'] = 'field_t_kirjeldus_value';
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['table'] = 'field_data_field_t_kirjeldus';
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['field'] = 'field_t_kirjeldus_value';
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['group'] = 1;
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['expose']['operator_id'] = 'field_t_kirjeldus_value_op';
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['expose']['label'] = 'Description';
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['expose']['operator'] = 'field_t_kirjeldus_value_op';
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['expose']['identifier'] = 'field_t_kirjeldus_value';
  $handler->display->display_options['filters']['field_t_kirjeldus_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 3;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 2;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'teenus' => 'teenus',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  /* Filter criterion: Content: Subdivision&#039;s reference (field_t_allasutuse_reference) */
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['id'] = 'field_t_allasutuse_reference_tid';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['table'] = 'field_data_field_t_allasutuse_reference';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['field'] = 'field_t_allasutuse_reference_tid';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['expose']['operator_id'] = 'field_t_allasutuse_reference_tid_op';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['expose']['label'] = 'Institution';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['expose']['operator'] = 'field_t_allasutuse_reference_tid_op';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['expose']['identifier'] = 'field_t_allasutuse_reference_tid';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['vocabulary'] = 'valitsuse_puu';
  $handler->display->display_options['filters']['field_t_allasutuse_reference_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Target group (field_t_sihtgrupp) (translated) */
  $handler->display->display_options['filters']['field_t_sihtgrupp_value_i18n']['id'] = 'field_t_sihtgrupp_value_i18n';
  $handler->display->display_options['filters']['field_t_sihtgrupp_value_i18n']['table'] = 'field_data_field_t_sihtgrupp';
  $handler->display->display_options['filters']['field_t_sihtgrupp_value_i18n']['field'] = 'field_t_sihtgrupp_value_i18n';
  $handler->display->display_options['filters']['field_t_sihtgrupp_value_i18n']['group'] = 2;
  $handler->display->display_options['filters']['field_t_sihtgrupp_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_t_sihtgrupp_value_i18n']['expose']['operator_id'] = 'field_t_sihtgrupp_value_i18n_op';
  $handler->display->display_options['filters']['field_t_sihtgrupp_value_i18n']['expose']['label'] = 'Target group';
  $handler->display->display_options['filters']['field_t_sihtgrupp_value_i18n']['expose']['operator'] = 'field_t_sihtgrupp_value_i18n_op';
  $handler->display->display_options['filters']['field_t_sihtgrupp_value_i18n']['expose']['identifier'] = 'field_t_sihtgrupp_value_i18n';
  $handler->display->display_options['filters']['field_t_sihtgrupp_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_t_sihtgrupp_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Type (field_t_teenuse_tyyp) */
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['id'] = 'field_t_teenuse_tyyp_tid';
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['table'] = 'field_data_field_t_teenuse_tyyp';
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['field'] = 'field_t_teenuse_tyyp_tid';
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['expose']['operator_id'] = 'field_t_teenuse_tyyp_tid_op';
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['expose']['label'] = 'Service type';
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['expose']['operator'] = 'field_t_teenuse_tyyp_tid_op';
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['expose']['identifier'] = 'field_t_teenuse_tyyp_tid';
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_t_teenuse_tyyp_tid']['vocabulary'] = 'teenuse_tyybid';
  /* Filter criterion: Field collection item: Kanal (field_fcf_kanal) */
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['id'] = 'field_fcf_kanal_tid';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['table'] = 'field_data_field_fcf_kanal';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['field'] = 'field_fcf_kanal_tid';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['relationship'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['expose']['operator_id'] = 'field_fcf_kanal_tid_op';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['expose']['label'] = 'Service channel';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['expose']['operator'] = 'field_fcf_kanal_tid_op';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['expose']['identifier'] = 'field_fcf_kanal_tid';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['vocabulary'] = 'kanaalide_struktuur';
  $handler->display->display_options['filters']['field_fcf_kanal_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Domain (field_t_tegevusvaldkond) */
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['id'] = 'field_t_tegevusvaldkond_tid';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['table'] = 'field_data_field_t_tegevusvaldkond';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['field'] = 'field_t_tegevusvaldkond_tid';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['expose']['operator_id'] = 'field_t_tegevusvaldkond_tid_op';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['expose']['label'] = 'Domain';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['expose']['operator'] = 'field_t_tegevusvaldkond_tid_op';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['expose']['identifier'] = 'field_t_tegevusvaldkond_tid';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['vocabulary'] = 'tegevusvaldkonnad';
  $handler->display->display_options['filters']['field_t_tegevusvaldkond_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: The status of the service (field_t_teenuse_seisund) */
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['id'] = 'field_t_teenuse_seisund_value';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['table'] = 'field_data_field_t_teenuse_seisund';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['field'] = 'field_t_teenuse_seisund_value';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['value'] = array(
    'all' => 'all',
    'Aktiivne' => 'Aktiivne',
    'Arhiveeritud' => 'Arhiveeritud',
    'Muudatust vajav' => 'Muudatust vajav',
  );
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['group'] = 2;
  $handler->display->display_options['path'] = 'teenuste-otsing';
  $handler->display->display_options['menu']['title'] = 'Teenuste otsing';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-web-portal';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Tähistiku filter attachment */
  $handler = $view->new_display('attachment', 'Tähistiku filter attachment', 'tahistiku_filter_attachment');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'unformatted_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['summary_options']['inline'] = TRUE;
  $handler->display->display_options['arguments']['title']['summary_options']['separator'] = '|';
  $handler->display->display_options['arguments']['title']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
  $handler->display->display_options['arguments']['title']['case'] = 'upper';
  $handler->display->display_options['arguments']['title']['path_case'] = 'lower';
  $handler->display->display_options['arguments']['title']['break_phrase'] = TRUE;
  $handler->display->display_options['displays'] = array(
    'teenuste_otsing_page' => 'teenuste_otsing_page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'both';
  $handler->display->display_options['inherit_arguments'] = FALSE;
  $export['teenuste_otsing'] = $view;

  return $export;
}
