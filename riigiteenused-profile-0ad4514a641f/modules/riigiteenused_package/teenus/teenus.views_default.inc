<?php
/**
 * @file
 * teenus.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function teenus_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'kanaalite_statistika';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Kanalite põhjal statistika';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Kanalite statistika';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühista';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'field_fcf_kanal' => 'field_fcf_kanal',
    'field_fcf_osutamiste_arv' => 'field_fcf_osutamiste_arv',
    'field_fcf_aasta_rahulolu' => 'field_fcf_aasta_rahulolu',
    'field_fcf_aasta_halduskulu' => 'field_fcf_aasta_halduskulu',
    'field_fcf_ajakulu_klientidele' => 'field_fcf_ajakulu_klientidele',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_fcf_kanal' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_fcf_osutamiste_arv' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_sum' => 'views_aggregator_sum',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_fcf_aasta_rahulolu' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_average' => 'views_aggregator_average',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_fcf_aasta_halduskulu' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_sum' => 'views_aggregator_sum',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_fcf_ajakulu_klientidele' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_sum' => 'views_aggregator_sum',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => 0,
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  /* Relationship: Sisu: Measurement year and channels (field_c_mootmise_aasta) */
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['id'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['table'] = 'field_data_field_c_mootmise_aasta';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['field'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['label'] = 'meser years';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['delta'] = '-1';
  /* Relationship: Field collection item: Mõõtmise kanal (field_fcf_mootmise_kanal) */
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['id'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['table'] = 'field_data_field_fcf_mootmise_kanal';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['field'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['relationship'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['label'] = 'meser kanalid';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['delta'] = '-1';
  /* Relationship: Taksonoomia termin: Vanemtermin */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['relationship'] = 'field_f_allasutuse_reference_tid';
  $handler->display->display_options['relationships']['parent']['label'] = 'Parent ministry';
  $handler->display->display_options['relationships']['parent']['required'] = TRUE;
  /* Väli: Field collection item: Kanal */
  $handler->display->display_options['fields']['field_fcf_kanal']['id'] = 'field_fcf_kanal';
  $handler->display->display_options['fields']['field_fcf_kanal']['table'] = 'field_data_field_fcf_kanal';
  $handler->display->display_options['fields']['field_fcf_kanal']['field'] = 'field_fcf_kanal';
  $handler->display->display_options['fields']['field_fcf_kanal']['relationship'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['fields']['field_fcf_kanal']['label'] = 'Kanali nimi';
  $handler->display->display_options['fields']['field_fcf_kanal']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fcf_kanal']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Väli: Field collection item: Osutamiste arv (kordades) */
  $handler->display->display_options['fields']['field_fcf_osutamiste_arv']['id'] = 'field_fcf_osutamiste_arv';
  $handler->display->display_options['fields']['field_fcf_osutamiste_arv']['table'] = 'field_data_field_fcf_osutamiste_arv';
  $handler->display->display_options['fields']['field_fcf_osutamiste_arv']['field'] = 'field_fcf_osutamiste_arv';
  $handler->display->display_options['fields']['field_fcf_osutamiste_arv']['relationship'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['fields']['field_fcf_osutamiste_arv']['label'] = 'Osutamiste arv';
  $handler->display->display_options['fields']['field_fcf_osutamiste_arv']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Väli: Field collection item: Aasta Rahulolu (%) */
  $handler->display->display_options['fields']['field_fcf_aasta_rahulolu']['id'] = 'field_fcf_aasta_rahulolu';
  $handler->display->display_options['fields']['field_fcf_aasta_rahulolu']['table'] = 'field_data_field_fcf_aasta_rahulolu';
  $handler->display->display_options['fields']['field_fcf_aasta_rahulolu']['field'] = 'field_fcf_aasta_rahulolu';
  $handler->display->display_options['fields']['field_fcf_aasta_rahulolu']['relationship'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['fields']['field_fcf_aasta_rahulolu']['label'] = 'Aasta Rahulolu';
  $handler->display->display_options['fields']['field_fcf_aasta_rahulolu']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Väli: Field collection item: Aasta halduskulu (€) */
  $handler->display->display_options['fields']['field_fcf_aasta_halduskulu']['id'] = 'field_fcf_aasta_halduskulu';
  $handler->display->display_options['fields']['field_fcf_aasta_halduskulu']['table'] = 'field_data_field_fcf_aasta_halduskulu';
  $handler->display->display_options['fields']['field_fcf_aasta_halduskulu']['field'] = 'field_fcf_aasta_halduskulu';
  $handler->display->display_options['fields']['field_fcf_aasta_halduskulu']['relationship'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['fields']['field_fcf_aasta_halduskulu']['label'] = 'Aasta halduskulu';
  $handler->display->display_options['fields']['field_fcf_aasta_halduskulu']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Väli: Field collection item: Ajakulu klientidele (h) */
  $handler->display->display_options['fields']['field_fcf_ajakulu_klientidele']['id'] = 'field_fcf_ajakulu_klientidele';
  $handler->display->display_options['fields']['field_fcf_ajakulu_klientidele']['table'] = 'field_data_field_fcf_ajakulu_klientidele';
  $handler->display->display_options['fields']['field_fcf_ajakulu_klientidele']['field'] = 'field_fcf_ajakulu_klientidele';
  $handler->display->display_options['fields']['field_fcf_ajakulu_klientidele']['relationship'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['fields']['field_fcf_ajakulu_klientidele']['label'] = 'Kliendi halduskoormus';
  $handler->display->display_options['fields']['field_fcf_ajakulu_klientidele']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Sisu: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Taksonoomia termin: Hierarchical weight */
  $handler->display->display_options['sorts']['hweight']['id'] = 'hweight';
  $handler->display->display_options['sorts']['hweight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['hweight']['field'] = 'hweight';
  $handler->display->display_options['sorts']['hweight']['relationship'] = 'field_fcf_kanal_tid';
  /* Contextual filter: Taksonoomia termin: Termini ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'parent';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Kõik';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Sisu: Avaldatud */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Sisu: Liik */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'teenus' => 'teenus',
  );

  /* Display: Asutuse kanalite statistika */
  $handler = $view->new_display('block', 'Asutuse kanalite statistika', 'kanalite_statistika');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Kanalite statistika';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_attachment_summary'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühista';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
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
    'field_fcf_mootmise_aasta_tid' => array(
      'bef_format' => 'bef_hidden',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
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
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_fcf_osutamiste_arv' => 'field_fcf_osutamiste_arv',
    'field_fcf_aasta_rahulolu' => 'field_fcf_aasta_rahulolu',
    'field_fcf_aasta_halduskulu' => 'field_fcf_aasta_halduskulu',
    'field_fcf_ajakulu_klientidele' => 'field_fcf_ajakulu_klientidele',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fcf_osutamiste_arv' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fcf_aasta_rahulolu' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fcf_aasta_halduskulu' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fcf_ajakulu_klientidele' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Sisu: Measurement year and channels (field_c_mootmise_aasta) */
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['id'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['table'] = 'field_data_field_c_mootmise_aasta';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['field'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['label'] = 'meser years';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['delta'] = '-1';
  /* Relationship: Field collection item: Mõõtmise kanal (field_fcf_mootmise_kanal) */
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['id'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['table'] = 'field_data_field_fcf_mootmise_kanal';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['field'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['relationship'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['label'] = 'meser kanalid';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['delta'] = '-1';
  /* Relationship: Field collection item: Kanal (field_fcf_kanal) */
  $handler->display->display_options['relationships']['field_fcf_kanal_tid']['id'] = 'field_fcf_kanal_tid';
  $handler->display->display_options['relationships']['field_fcf_kanal_tid']['table'] = 'field_data_field_fcf_kanal';
  $handler->display->display_options['relationships']['field_fcf_kanal_tid']['field'] = 'field_fcf_kanal_tid';
  $handler->display->display_options['relationships']['field_fcf_kanal_tid']['relationship'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_kanal_tid']['label'] = 'Channel name term';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Väli: Taksonoomia termin: Name (translated) */
  $handler->display->display_options['fields']['name_i18n']['id'] = 'name_i18n';
  $handler->display->display_options['fields']['name_i18n']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_i18n']['field'] = 'name_i18n';
  $handler->display->display_options['fields']['name_i18n']['relationship'] = 'field_fcf_kanal_tid';
  $handler->display->display_options['fields']['name_i18n']['label'] = 'Name';
  /* Väli: Field collection item: Osutamiste arv (kordades) */
  $handler->display->display_options['fields']['field_fcf_osutamiste_arv']['id'] = 'field_fcf_osutamiste_arv';
  $handler->display->display_options['fields']['field_fcf_osutamiste_arv']['table'] = 'field_data_field_fcf_osutamiste_arv';
  $handler->display->display_options['fields']['field_fcf_osutamiste_arv']['field'] = 'field_fcf_osutamiste_arv';
  $handler->display->display_options['fields']['field_fcf_osutamiste_arv']['relationship'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['fields']['field_fcf_osutamiste_arv']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_fcf_osutamiste_arv']['label'] = 'Osutamiste arv';
  $handler->display->display_options['fields']['field_fcf_osutamiste_arv']['empty'] = '-';
  $handler->display->display_options['fields']['field_fcf_osutamiste_arv']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_fcf_osutamiste_arv']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Väli: Field collection item: Aasta Rahulolu (%) */
  $handler->display->display_options['fields']['field_fcf_aasta_rahulolu']['id'] = 'field_fcf_aasta_rahulolu';
  $handler->display->display_options['fields']['field_fcf_aasta_rahulolu']['table'] = 'field_data_field_fcf_aasta_rahulolu';
  $handler->display->display_options['fields']['field_fcf_aasta_rahulolu']['field'] = 'field_fcf_aasta_rahulolu';
  $handler->display->display_options['fields']['field_fcf_aasta_rahulolu']['relationship'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['fields']['field_fcf_aasta_rahulolu']['label'] = 'Aasta Rahulolu';
  $handler->display->display_options['fields']['field_fcf_aasta_rahulolu']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Väli: Field collection item: Aasta halduskulu (€) */
  $handler->display->display_options['fields']['field_fcf_aasta_halduskulu']['id'] = 'field_fcf_aasta_halduskulu';
  $handler->display->display_options['fields']['field_fcf_aasta_halduskulu']['table'] = 'field_data_field_fcf_aasta_halduskulu';
  $handler->display->display_options['fields']['field_fcf_aasta_halduskulu']['field'] = 'field_fcf_aasta_halduskulu';
  $handler->display->display_options['fields']['field_fcf_aasta_halduskulu']['relationship'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['fields']['field_fcf_aasta_halduskulu']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_fcf_aasta_halduskulu']['label'] = 'Aasta halduskulu';
  $handler->display->display_options['fields']['field_fcf_aasta_halduskulu']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Väli: Field collection item: Ajakulu klientidele (h) */
  $handler->display->display_options['fields']['field_fcf_ajakulu_klientidele']['id'] = 'field_fcf_ajakulu_klientidele';
  $handler->display->display_options['fields']['field_fcf_ajakulu_klientidele']['table'] = 'field_data_field_fcf_ajakulu_klientidele';
  $handler->display->display_options['fields']['field_fcf_ajakulu_klientidele']['field'] = 'field_fcf_ajakulu_klientidele';
  $handler->display->display_options['fields']['field_fcf_ajakulu_klientidele']['relationship'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['fields']['field_fcf_ajakulu_klientidele']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_fcf_ajakulu_klientidele']['label'] = 'Kliendi halduskoormus';
  $handler->display->display_options['fields']['field_fcf_ajakulu_klientidele']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taksonoomia termin: Hierarchical weight */
  $handler->display->display_options['sorts']['hweight']['id'] = 'hweight';
  $handler->display->display_options['sorts']['hweight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['hweight']['field'] = 'hweight';
  $handler->display->display_options['sorts']['hweight']['relationship'] = 'field_fcf_kanal_tid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Sisu: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title'] = 'Kõik';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'valitsuse_puu' => 'valitsuse_puu',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '1';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Sisu: Avaldatud */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Field collection item: Mõõtmise aasta (field_fcf_mootmise_aasta) */
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['id'] = 'field_fcf_mootmise_aasta_tid';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['table'] = 'field_data_field_fcf_mootmise_aasta';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['field'] = 'field_fcf_mootmise_aasta_tid';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['relationship'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['operator_id'] = 'field_fcf_mootmise_aasta_tid_op';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['label'] = 'Teenuse ostutamise aasta';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['operator'] = 'field_fcf_mootmise_aasta_tid_op';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['identifier'] = 'field_fcf_mootmise_aasta_tid';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['vocabulary'] = 'mootmise_aastad';
  /* Filter criterion: Sisu: The status of the service (field_t_teenuse_seisund) */
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['id'] = 'field_t_teenuse_seisund_value';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['table'] = 'field_data_field_t_teenuse_seisund';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['field'] = 'field_t_teenuse_seisund_value';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['value'] = array(
    'Loomisel' => 'Loomisel',
    'Arhiveeritud' => 'Arhiveeritud',
  );
  /* Filter criterion: Sisu: Keel */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['block_description'] = 'Asutuse kanalite statistika';

  /* Display: Teenuse kanalite list */
  $handler = $view->new_display('block', 'Teenuse kanalite list', 'teenuse_kanalite_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Sisu: Measurement year and channels (field_c_mootmise_aasta) */
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['id'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['table'] = 'field_data_field_c_mootmise_aasta';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['field'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['label'] = 'meser years';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['delta'] = '-1';
  /* Relationship: Field collection item: Mõõtmise kanal (field_fcf_mootmise_kanal) */
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['id'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['table'] = 'field_data_field_fcf_mootmise_kanal';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['field'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['relationship'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['label'] = 'meser kanalid';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['delta'] = '-1';
  /* Relationship: Field collection item: Kanal (field_fcf_kanal) */
  $handler->display->display_options['relationships']['field_fcf_kanal_tid']['id'] = 'field_fcf_kanal_tid';
  $handler->display->display_options['relationships']['field_fcf_kanal_tid']['table'] = 'field_data_field_fcf_kanal';
  $handler->display->display_options['relationships']['field_fcf_kanal_tid']['field'] = 'field_fcf_kanal_tid';
  $handler->display->display_options['relationships']['field_fcf_kanal_tid']['relationship'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_kanal_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Väli: Field collection item: Viide teenusele */
  $handler->display->display_options['fields']['field_fcf_viide_teenusele']['id'] = 'field_fcf_viide_teenusele';
  $handler->display->display_options['fields']['field_fcf_viide_teenusele']['table'] = 'field_data_field_fcf_viide_teenusele';
  $handler->display->display_options['fields']['field_fcf_viide_teenusele']['field'] = 'field_fcf_viide_teenusele';
  $handler->display->display_options['fields']['field_fcf_viide_teenusele']['relationship'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['fields']['field_fcf_viide_teenusele']['label'] = '';
  $handler->display->display_options['fields']['field_fcf_viide_teenusele']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fcf_viide_teenusele']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fcf_viide_teenusele']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_fcf_viide_teenusele']['group_column'] = 'entity_id';
  /* Väli: Field collection item: Kanal */
  $handler->display->display_options['fields']['field_fcf_kanal']['id'] = 'field_fcf_kanal';
  $handler->display->display_options['fields']['field_fcf_kanal']['table'] = 'field_data_field_fcf_kanal';
  $handler->display->display_options['fields']['field_fcf_kanal']['field'] = 'field_fcf_kanal';
  $handler->display->display_options['fields']['field_fcf_kanal']['relationship'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['fields']['field_fcf_kanal']['label'] = '';
  $handler->display->display_options['fields']['field_fcf_kanal']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_fcf_kanal']['alter']['path'] = '[field_fcf_viide_teenusele]';
  $handler->display->display_options['fields']['field_fcf_kanal']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_fcf_kanal']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fcf_kanal']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Sisu: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Kõik';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'teenus' => 'teenus',
  );
  $handler->display->display_options['block_description'] = 'Teenuse kanalite list';

  /* Display: Teenuse kanalite statistika üldnumbrid */
  $handler = $view->new_display('block', 'Teenuse kanalite statistika üldnumbrid', 'teenuse_kanalite_statistika_yldnumbrid');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_attachment_summary'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühista';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Väli: Sisu: The amount of rendered services */
  $handler->display->display_options['fields']['field_t_osutatud_teenuste_arv']['id'] = 'field_t_osutatud_teenuste_arv';
  $handler->display->display_options['fields']['field_t_osutatud_teenuste_arv']['table'] = 'field_data_field_t_osutatud_teenuste_arv';
  $handler->display->display_options['fields']['field_t_osutatud_teenuste_arv']['field'] = 'field_t_osutatud_teenuste_arv';
  $handler->display->display_options['fields']['field_t_osutatud_teenuste_arv']['label'] = 'Osutatud teenuste arv';
  $handler->display->display_options['fields']['field_t_osutatud_teenuste_arv']['empty'] = '-';
  $handler->display->display_options['fields']['field_t_osutatud_teenuste_arv']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_t_osutatud_teenuste_arv']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Väli: Sisu: Satisfaction (%) */
  $handler->display->display_options['fields']['field_t_rahulolu']['id'] = 'field_t_rahulolu';
  $handler->display->display_options['fields']['field_t_rahulolu']['table'] = 'field_data_field_t_rahulolu';
  $handler->display->display_options['fields']['field_t_rahulolu']['field'] = 'field_t_rahulolu';
  $handler->display->display_options['fields']['field_t_rahulolu']['label'] = 'Rahulolu';
  $handler->display->display_options['fields']['field_t_rahulolu']['empty'] = '-';
  $handler->display->display_options['fields']['field_t_rahulolu']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_t_rahulolu']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_t_rahulolu']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Väli: Sisu: Cost (€) */
  $handler->display->display_options['fields']['field_t_maksumus']['id'] = 'field_t_maksumus';
  $handler->display->display_options['fields']['field_t_maksumus']['table'] = 'field_data_field_t_maksumus';
  $handler->display->display_options['fields']['field_t_maksumus']['field'] = 'field_t_maksumus';
  $handler->display->display_options['fields']['field_t_maksumus']['label'] = 'Halduskulu';
  $handler->display->display_options['fields']['field_t_maksumus']['empty'] = '-';
  $handler->display->display_options['fields']['field_t_maksumus']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_t_maksumus']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Väli: Sisu: Administrative burden (h) */
  $handler->display->display_options['fields']['field_t_kliendihaldus_koormus']['id'] = 'field_t_kliendihaldus_koormus';
  $handler->display->display_options['fields']['field_t_kliendihaldus_koormus']['table'] = 'field_data_field_t_kliendihaldus_koormus';
  $handler->display->display_options['fields']['field_t_kliendihaldus_koormus']['field'] = 'field_t_kliendihaldus_koormus';
  $handler->display->display_options['fields']['field_t_kliendihaldus_koormus']['label'] = 'Kliendihaldus koormus';
  $handler->display->display_options['fields']['field_t_kliendihaldus_koormus']['empty'] = '-';
  $handler->display->display_options['fields']['field_t_kliendihaldus_koormus']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_t_kliendihaldus_koormus']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Sisu: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Sisu: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Kõik';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'teenus' => 'teenus',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Sisu: Avaldatud */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Sisu: The status of the service (field_t_teenuse_seisund) */
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['id'] = 'field_t_teenuse_seisund_value';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['table'] = 'field_data_field_t_teenuse_seisund';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['field'] = 'field_t_teenuse_seisund_value';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['value'] = array(
    'Loomisel' => 'Loomisel',
    'Arhiveeritud' => 'Arhiveeritud',
  );
  $handler->display->display_options['block_description'] = 'Teenuse kanalite statistika üldnumbrid';
  $export['kanaalite_statistika'] = $view;

  $view = new view();
  $view->name = 'ministeeriumi_teenuste_statistika';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Ministeeriumi teenuste statistika';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Teenused numbrites';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühista';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
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
    'field_fcf_mootmise_aasta_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Jalus: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['label'] = 'View: Üldnumbrid';
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'kanaalite_statistika:kanalite_statistika_yldnumbrid';
  $handler->display->display_options['footer']['view']['inherit_arguments'] = TRUE;
  /* Relationship: Taksonoomia termin: Vanemtermin */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['label'] = 'Ministry ref';
  $handler->display->display_options['relationships']['parent']['required'] = TRUE;
  /* Relationship: Taksonoomia termin: Content with term */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'taxonomy_index';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Teenused';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Relationship: Sisu: Subdivision&#039;s reference (field_t_allasutuse_reference) */
  $handler->display->display_options['relationships']['field_t_allasutuse_reference_tid']['id'] = 'field_t_allasutuse_reference_tid';
  $handler->display->display_options['relationships']['field_t_allasutuse_reference_tid']['table'] = 'field_data_field_t_allasutuse_reference';
  $handler->display->display_options['relationships']['field_t_allasutuse_reference_tid']['field'] = 'field_t_allasutuse_reference_tid';
  $handler->display->display_options['relationships']['field_t_allasutuse_reference_tid']['relationship'] = 'nid';
  $handler->display->display_options['relationships']['field_t_allasutuse_reference_tid']['label'] = 'Institution ref';
  $handler->display->display_options['relationships']['field_t_allasutuse_reference_tid']['required'] = TRUE;
  /* Relationship: Sisu: Measurement year and channels (field_c_mootmise_aasta) */
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['id'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['table'] = 'field_data_field_c_mootmise_aasta';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['field'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['relationship'] = 'nid';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['label'] = 'Measurement years';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['delta'] = '-1';
  /* Relationship: Field collection item: Mõõtmise kanal (field_fcf_mootmise_kanal) */
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['id'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['table'] = 'field_data_field_fcf_mootmise_kanal';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['field'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['relationship'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['label'] = 'Measurement channel';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['delta'] = '-1';
  /* Väli: Taksonoomia termin: Nimi */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Väli: Taksonoomia termin: Termini ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Väli: VIew: Allasutuse teenuste arv */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['ui_name'] = 'VIew: Allasutuse teenuste arv';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'teenuste_statistika';
  $handler->display->display_options['fields']['view']['display'] = 'teenuste_arv_kokku';
  $handler->display->display_options['fields']['view']['arguments'] = '[!tid]';
  /* Väli: View: Allasutuse teenuste statistika */
  $handler->display->display_options['fields']['view_2']['id'] = 'view_2';
  $handler->display->display_options['fields']['view_2']['table'] = 'views';
  $handler->display->display_options['fields']['view_2']['field'] = 'view';
  $handler->display->display_options['fields']['view_2']['ui_name'] = 'View: Allasutuse teenuste statistika';
  $handler->display->display_options['fields']['view_2']['label'] = '';
  $handler->display->display_options['fields']['view_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_2']['view'] = 'teenuste_statistika';
  $handler->display->display_options['fields']['view_2']['display'] = 'allasutuse_teenuste_statistika_plokk';
  $handler->display->display_options['fields']['view_2']['arguments'] = '[!tid]';
  /* Sort criterion: Taksonoomia termin: Hierarchical weight */
  $handler->display->display_options['sorts']['hweight']['id'] = 'hweight';
  $handler->display->display_options['sorts']['hweight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['hweight']['field'] = 'hweight';
  /* Contextual filter: Taksonoomia termin: Termini ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'parent';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Kõik';
  $handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['title'] = '%1 (haldusala)';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'valitsuse_puu' => 'valitsuse_puu',
  );
  /* Filter criterion: Taksonoomia sõnastik: Süsteemne nimetus */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'valitsuse_puu' => 'valitsuse_puu',
  );
  /* Filter criterion: Field collection item: Mõõtmise aasta (field_fcf_mootmise_aasta) */
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['id'] = 'field_fcf_mootmise_aasta_tid';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['table'] = 'field_data_field_fcf_mootmise_aasta';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['field'] = 'field_fcf_mootmise_aasta_tid';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['relationship'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['operator_id'] = 'field_fcf_mootmise_aasta_tid_op';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['label'] = 'Teenuse ostutamise aasta';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['operator'] = 'field_fcf_mootmise_aasta_tid_op';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['identifier'] = 'field_fcf_mootmise_aasta_tid';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['vocabulary'] = 'mootmise_aastad';
  /* Filter criterion: Sisu: The status of the service (field_t_teenuse_seisund) */
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['id'] = 'field_t_teenuse_seisund_value';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['table'] = 'field_data_field_t_teenuse_seisund';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['field'] = 'field_t_teenuse_seisund_value';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['relationship'] = 'nid';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['value'] = array(
    'Loomisel' => 'Loomisel',
    'Arhiveeritud' => 'Arhiveeritud',
  );
  /* Filter criterion: Sisu: Avaldatud */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Sisu: Keel */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'nid';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Ministeeriumi teenuste statistika plokk */
  $handler = $view->new_display('block', 'Ministeeriumi teenuste statistika plokk', 'ministeeriumi_teenuste_statistika_plokk');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Ministeeriumi teenuste statistika plokk';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühista';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
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
    'field_fcf_mootmise_aasta_tid' => array(
      'bef_format' => 'bef_hidden',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
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
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Jalus: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['label'] = 'View: teenuse statistika üldnumbrid';
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'termide_statistikad:term_yldstatistika_with_text';
  $handler->display->display_options['footer']['view']['inherit_arguments'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Väli: Taksonoomia termin: Name (translated) */
  $handler->display->display_options['fields']['name_i18n']['id'] = 'name_i18n';
  $handler->display->display_options['fields']['name_i18n']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_i18n']['field'] = 'name_i18n';
  $handler->display->display_options['fields']['name_i18n']['label'] = '';
  $handler->display->display_options['fields']['name_i18n']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_i18n']['element_label_colon'] = FALSE;
  /* Väli: Taksonoomia termin: Nimi */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name_i18n]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Väli: Taksonoomia termin: Termini ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Väli: VIew: Allasutuse teenuste arv */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['ui_name'] = 'VIew: Allasutuse teenuste arv';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'teenuste_statistika';
  $handler->display->display_options['fields']['view']['display'] = 'teenuste_arv_kokku';
  $handler->display->display_options['fields']['view']['arguments'] = '[!tid]';
  /* Väli: View: Allasutuse teenuste statistika */
  $handler->display->display_options['fields']['view_2']['id'] = 'view_2';
  $handler->display->display_options['fields']['view_2']['table'] = 'views';
  $handler->display->display_options['fields']['view_2']['field'] = 'view';
  $handler->display->display_options['fields']['view_2']['ui_name'] = 'View: Allasutuse teenuste statistika';
  $handler->display->display_options['fields']['view_2']['label'] = '';
  $handler->display->display_options['fields']['view_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_2']['view'] = 'teenuste_statistika';
  $handler->display->display_options['fields']['view_2']['display'] = 'allasutuse_teenuste_statistika_plokk';
  $handler->display->display_options['fields']['view_2']['arguments'] = '[!tid]';
  $handler->display->display_options['block_description'] = 'Ministeeriumi teenuste statistika plokk';

  /* Display: Ministeeriumi teenused numbrites */
  $handler = $view->new_display('page', 'Ministeeriumi teenused numbrites', 'ministeeriumi_teenused_numbrites');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Päis: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'HTML title: Teenused numbrites';
  $handler->display->display_options['header']['area']['content'] = '<h1 class="statistics-page-title">Teenused numbrites</h1>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Päis: Global: Text area */
  $handler->display->display_options['header']['area_3']['id'] = 'area_3';
  $handler->display->display_options['header']['area_3']['table'] = 'views';
  $handler->display->display_options['header']['area_3']['field'] = 'area';
  $handler->display->display_options['header']['area_3']['label'] = 'Custom text: View description text';
  $handler->display->display_options['header']['area_3']['content'] = '<div class="view-description-text">Base statistics about the services across channels and institutions. The number of rendered services shows how many times the service was provided. The annual satisfaction shows the percentage of satisfied customers. The annual administrative cost shows the cost for the institution for rendering the service. Customer\'s administrative burden shows how much time in total did it took for the customer to consume a certain service in a particular channel.
</div>';
  $handler->display->display_options['header']['area_3']['format'] = 'full_html';
  /* Päis: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['label'] = 'HTML title: Haldusala';
  $handler->display->display_options['header']['area_1']['content'] = '<h2 class="statistic-page-sub-title">%1</h2>';
  $handler->display->display_options['header']['area_1']['format'] = 'full_html';
  $handler->display->display_options['header']['area_1']['tokenize'] = TRUE;
  /* Päis: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['label'] = 'View: Teenuste arv';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'teenuste_statistika:teenuste_arv_kokku';
  $handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
  /* Päis: Global: Text area */
  $handler->display->display_options['header']['area_2']['id'] = 'area_2';
  $handler->display->display_options['header']['area_2']['table'] = 'views';
  $handler->display->display_options['header']['area_2']['field'] = 'area';
  $handler->display->display_options['header']['area_2']['label'] = 'HTML title: Kanalite statistika';
  $handler->display->display_options['header']['area_2']['content'] = '<div class="statistic-page-channels-block"><h3>Kõik teenused kanalite lõikes</h3></div>';
  $handler->display->display_options['header']['area_2']['format'] = 'full_html';
  /* Päis: Global: View area */
  $handler->display->display_options['header']['view_1']['id'] = 'view_1';
  $handler->display->display_options['header']['view_1']['table'] = 'views';
  $handler->display->display_options['header']['view_1']['field'] = 'view';
  $handler->display->display_options['header']['view_1']['label'] = 'View: Kõik teenused kanalite lõikes';
  $handler->display->display_options['header']['view_1']['view_to_insert'] = 'kanaalite_statistika:kanalite_statistika';
  $handler->display->display_options['header']['view_1']['inherit_arguments'] = TRUE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Jalus: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['label'] = 'View: Üldnumbrid';
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'termide_statistikad:term_yldstatistika_with_text';
  $handler->display->display_options['footer']['view']['inherit_arguments'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Väli: Taksonoomia termin: Name (translated) */
  $handler->display->display_options['fields']['name_i18n']['id'] = 'name_i18n';
  $handler->display->display_options['fields']['name_i18n']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_i18n']['field'] = 'name_i18n';
  $handler->display->display_options['fields']['name_i18n']['label'] = '';
  $handler->display->display_options['fields']['name_i18n']['element_label_colon'] = FALSE;
  /* Väli: Taksonoomia termin: Nimi */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Väli: Taksonoomia termin: Termini ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Väli: VIew: Allasutuse teenuste arv */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['ui_name'] = 'VIew: Allasutuse teenuste arv';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'teenuste_statistika';
  $handler->display->display_options['fields']['view']['display'] = 'teenuste_arv_kokku';
  $handler->display->display_options['fields']['view']['arguments'] = '[!tid]';
  /* Väli: View: Allasutuse teenuste statistika */
  $handler->display->display_options['fields']['view_2']['id'] = 'view_2';
  $handler->display->display_options['fields']['view_2']['table'] = 'views';
  $handler->display->display_options['fields']['view_2']['field'] = 'view';
  $handler->display->display_options['fields']['view_2']['ui_name'] = 'View: Allasutuse teenuste statistika';
  $handler->display->display_options['fields']['view_2']['label'] = '';
  $handler->display->display_options['fields']['view_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_2']['view'] = 'teenuste_statistika';
  $handler->display->display_options['fields']['view_2']['display'] = 'allasutuse_teenuste_statistika_plokk';
  $handler->display->display_options['fields']['view_2']['arguments'] = '[!tid]';
  $handler->display->display_options['path'] = 'statistika/ministeerium';
  $handler->display->display_options['menu']['title'] = 'Ministeerium';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-web-portal';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['ministeeriumi_teenuste_statistika'] = $view;

  $view = new view();
  $view->name = 'teenuste_statistika';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Allasutuse teenuste statistika';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Teenused numbrites';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühista';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
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
    'field_fcf_mootmise_aasta_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'counter',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Päis: Global: View area */
  $handler->display->display_options['header']['view_1']['id'] = 'view_1';
  $handler->display->display_options['header']['view_1']['table'] = 'views';
  $handler->display->display_options['header']['view_1']['field'] = 'view';
  $handler->display->display_options['header']['view_1']['label'] = 'Kõik teenused kanalite lõikes';
  $handler->display->display_options['header']['view_1']['view_to_insert'] = 'kanaalite_statistika:kanalite_statistika';
  $handler->display->display_options['header']['view_1']['inherit_arguments'] = TRUE;
  /* Päis: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Jalus: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['label'] = 'View: Üldnumbrid';
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'termide_statistikad:term_yldstatistika_with_text';
  $handler->display->display_options['footer']['view']['inherit_arguments'] = TRUE;
  /* Relationship: Sisu: Subdivision&#039;s reference (field_t_allasutuse_reference) */
  $handler->display->display_options['relationships']['field_t_allasutuse_reference_tid']['id'] = 'field_t_allasutuse_reference_tid';
  $handler->display->display_options['relationships']['field_t_allasutuse_reference_tid']['table'] = 'field_data_field_t_allasutuse_reference';
  $handler->display->display_options['relationships']['field_t_allasutuse_reference_tid']['field'] = 'field_t_allasutuse_reference_tid';
  $handler->display->display_options['relationships']['field_t_allasutuse_reference_tid']['label'] = 'institution ref';
  $handler->display->display_options['relationships']['field_t_allasutuse_reference_tid']['required'] = TRUE;
  /* Relationship: Sisu: Measurement year and channels (field_c_mootmise_aasta) */
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['id'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['table'] = 'field_data_field_c_mootmise_aasta';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['field'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['label'] = 'Measured years';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['delta'] = '-1';
  /* Relationship: Field collection item: Mõõtmise kanal (field_fcf_mootmise_kanal) */
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['id'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['table'] = 'field_data_field_fcf_mootmise_kanal';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['field'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['relationship'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['label'] = 'Measured channels';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['delta'] = '-1';
  /* Väli: Sisu: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Väli: Sisu: Pealkiri */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'statistic-sevice-name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Väli: Service statistics table */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Service statistics table';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Sisu: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Contextual filter: Sisu: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title'] = 'Kõik';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1 (haldusala)';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['argument'] = '50';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'valitsuse_puu' => 'valitsuse_puu',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  /* Filter criterion: Sisu: Avaldatud */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Sisu: Liik */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'teenus' => 'teenus',
  );
  /* Filter criterion: Field collection item: Mõõtmise aasta (field_fcf_mootmise_aasta) */
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['id'] = 'field_fcf_mootmise_aasta_tid';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['table'] = 'field_data_field_fcf_mootmise_aasta';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['field'] = 'field_fcf_mootmise_aasta_tid';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['relationship'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['operator_id'] = 'field_fcf_mootmise_aasta_tid_op';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['label'] = 'Teenuse ostutamise aasta';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['operator'] = 'field_fcf_mootmise_aasta_tid_op';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['identifier'] = 'field_fcf_mootmise_aasta_tid';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['vocabulary'] = 'mootmise_aastad';
  /* Filter criterion: Sisu: The status of the service (field_t_teenuse_seisund) */
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['id'] = 'field_t_teenuse_seisund_value';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['table'] = 'field_data_field_t_teenuse_seisund';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['field'] = 'field_t_teenuse_seisund_value';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['value'] = array(
    'Loomisel' => 'Loomisel',
    'Arhiveeritud' => 'Arhiveeritud',
  );
  /* Filter criterion: Sisu: Avaldatud */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  /* Filter criterion: Sisu: Keel */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Allasutuse teenuste statistika plokk */
  $handler = $view->new_display('block', 'Allasutuse teenuste statistika plokk', 'allasutuse_teenuste_statistika_plokk');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühista';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
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
    'field_fcf_mootmise_aasta_tid' => array(
      'bef_format' => 'bef_hidden',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
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
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Päis: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['label'] = 'View: Üldnumbrid';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'termide_statistikad:term_yldstatistika_no_text';
  $handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Väli: Sisu: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Väli: Sisu: Pealkiri */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'statistic-sevice-name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Väli: Service statistics table */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Service statistics table';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'Allasutuse teenuste statistika plokk';

  /* Display: Allasutuse teenused numbrites */
  $handler = $view->new_display('page', 'Allasutuse teenused numbrites', 'allasutuse_teenused_numbrites');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Päis: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'HTML title: Teenused numbrites';
  $handler->display->display_options['header']['area']['content'] = '<h1 class="statistics-page-title">Teenused numbrites</h1>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Päis: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['label'] = 'Custom text: View description text';
  $handler->display->display_options['header']['area_1']['content'] = '<div class="view-description-text">
Teenuste baasstatistika kanalite ja asutuste lõikes. Osutamiste arv näitab, mitu korda teenust osutati. Aasta rahulolu näitab, kui rahulolevate klientide osakaalu. Aasta halduskulu näitab teenuse osutamise kulu asutusele. Kliendi halduskoormus näitab, kui palju aega kulus klientidel kokku teenuse tarbimiseks konkreetses kanalis.
</div>';
  $handler->display->display_options['header']['area_1']['format'] = 'full_html';
  /* Päis: Global: Text area */
  $handler->display->display_options['header']['area_2']['id'] = 'area_2';
  $handler->display->display_options['header']['area_2']['table'] = 'views';
  $handler->display->display_options['header']['area_2']['field'] = 'area';
  $handler->display->display_options['header']['area_2']['label'] = 'HTML title: Haldusala';
  $handler->display->display_options['header']['area_2']['content'] = '<h2 class="statistic-page-sub-title">%1</h2>';
  $handler->display->display_options['header']['area_2']['format'] = 'full_html';
  $handler->display->display_options['header']['area_2']['tokenize'] = TRUE;
  /* Päis: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['label'] = 'View: Teenuste arv';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'teenuste_statistika:teenuste_arv_kokku';
  $handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
  /* Päis: Global: Text area */
  $handler->display->display_options['header']['area_3']['id'] = 'area_3';
  $handler->display->display_options['header']['area_3']['table'] = 'views';
  $handler->display->display_options['header']['area_3']['field'] = 'area';
  $handler->display->display_options['header']['area_3']['label'] = 'HTML title: Kanalite statistika';
  $handler->display->display_options['header']['area_3']['content'] = '<div class="statistic-page-channels-block"><h3 id="channel-stat-title">Kanalite statistika</h3></div>';
  $handler->display->display_options['header']['area_3']['format'] = 'full_html';
  /* Päis: Global: View area */
  $handler->display->display_options['header']['view_1']['id'] = 'view_1';
  $handler->display->display_options['header']['view_1']['table'] = 'views';
  $handler->display->display_options['header']['view_1']['field'] = 'view';
  $handler->display->display_options['header']['view_1']['label'] = 'View: Kõik teenused kanalite lõikes';
  $handler->display->display_options['header']['view_1']['view_to_insert'] = 'kanaalite_statistika:kanalite_statistika';
  $handler->display->display_options['header']['view_1']['inherit_arguments'] = TRUE;
  /* Päis: Global: Text area */
  $handler->display->display_options['header']['area_4']['id'] = 'area_4';
  $handler->display->display_options['header']['area_4']['table'] = 'views';
  $handler->display->display_options['header']['area_4']['field'] = 'area';
  $handler->display->display_options['header']['area_4']['label'] = 'HTML title: Teenuste statistika';
  $handler->display->display_options['header']['area_4']['content'] = '<div class="statistic-page-channels-block"><h3 id="serv-stat-title">Teenuste statistika</h3></div>';
  $handler->display->display_options['header']['area_4']['format'] = 'full_html';
  $handler->display->display_options['path'] = 'statistika/allasutus';
  $handler->display->display_options['menu']['title'] = 'Allasutus';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-web-portal';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Teenuste arv kokku */
  $handler = $view->new_display('block', 'Teenuste arv kokku', 'teenuste_arv_kokku');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Teenuste arv kokku';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühista';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
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
    'field_fcf_mootmise_aasta_tid' => array(
      'bef_format' => 'bef_hidden',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
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
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
        'views_aggregator_sum' => 'views_aggregator_sum',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '1';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => 0,
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Väli: Sisu: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Sisu: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title'] = 'Kõik';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'valitsuse_puu' => 'valitsuse_puu',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '1';
  $handler->display->display_options['block_description'] = 'Teenuste arv kokku';

  /* Display: Teenuse prioriteetsem kanal */
  $handler = $view->new_display('block', 'Teenuse prioriteetsem kanal', 'teenuse_prioriteetsem_kanal');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Teenuse prioriteetsem kanal';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühista';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Sisu: Measurement year and channels (field_c_mootmise_aasta) */
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['id'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['table'] = 'field_data_field_c_mootmise_aasta';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['field'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['label'] = 'Measured years';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['delta'] = '-1';
  /* Relationship: Field collection item: Mõõtmise kanal (field_fcf_mootmise_kanal) */
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['id'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['table'] = 'field_data_field_fcf_mootmise_kanal';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['field'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['relationship'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['label'] = 'Measured channels';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['delta'] = '-1';
  /* Relationship: Field collection item: Kanal (field_fcf_kanal) */
  $handler->display->display_options['relationships']['field_fcf_kanal_tid']['id'] = 'field_fcf_kanal_tid';
  $handler->display->display_options['relationships']['field_fcf_kanal_tid']['table'] = 'field_data_field_fcf_kanal';
  $handler->display->display_options['relationships']['field_fcf_kanal_tid']['field'] = 'field_fcf_kanal_tid';
  $handler->display->display_options['relationships']['field_fcf_kanal_tid']['relationship'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_kanal_tid']['label'] = 'Term channel';
  $handler->display->display_options['relationships']['field_fcf_kanal_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Väli: Field collection item: Kanal */
  $handler->display->display_options['fields']['field_fcf_kanal']['id'] = 'field_fcf_kanal';
  $handler->display->display_options['fields']['field_fcf_kanal']['table'] = 'field_data_field_fcf_kanal';
  $handler->display->display_options['fields']['field_fcf_kanal']['field'] = 'field_fcf_kanal';
  $handler->display->display_options['fields']['field_fcf_kanal']['relationship'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['fields']['field_fcf_kanal']['label'] = '';
  $handler->display->display_options['fields']['field_fcf_kanal']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fcf_kanal']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taksonoomia termin: Hierarchical weight */
  $handler->display->display_options['sorts']['hweight']['id'] = 'hweight';
  $handler->display->display_options['sorts']['hweight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['hweight']['field'] = 'hweight';
  $handler->display->display_options['sorts']['hweight']['relationship'] = 'field_fcf_kanal_tid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Sisu: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Kõik';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'teenus' => 'teenus',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['block_description'] = 'Teenuse prioriteetsem kanal';
  $export['teenuste_statistika'] = $view;

  $view = new view();
  $view->name = 'termide_statistikad';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Termide statistikad';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühista';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Järjesta';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Väli: Taksonoomia termin: Termini ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Contextual filter: Taksonoomia termin: Termini ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Kõik';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'valitsuse_puu' => 'valitsuse_puu',
  );
  /* Filter criterion: Taksonoomia sõnastik: Süsteemne nimetus */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'valitsuse_puu' => 'valitsuse_puu',
  );

  /* Display: Term üldstatistika no text */
  $handler = $view->new_display('block', 'Term üldstatistika no text', 'term_yldstatistika_no_text');
  $handler->display->display_options['block_description'] = 'Term üldstatistika no text';

  /* Display: Term üldstatistika with text */
  $handler = $view->new_display('block', 'Term üldstatistika with text', 'term_yldstatistika_with_text');
  $handler->display->display_options['block_description'] = 'Term üldstatistika with text';
  $export['termide_statistikad'] = $view;

  $view = new view();
  $view->name = 'valitsuse_teenuste_statistika';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Valitsuse teenuste statistika';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Teenused numbrites';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Tühista';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
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
    'field_fcf_mootmise_aasta_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name_i18n',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Jalus: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['label'] = 'View: Üldnumbrid';
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'kanaalite_statistika:kanalite_statistika_yldnumbrid';
  $handler->display->display_options['footer']['view']['inherit_arguments'] = TRUE;
  /* Relationship: Taksonoomia termin: Content with term */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'taxonomy_index';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Teenused';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Relationship: Sisu: Subdivision&#039;s reference (field_t_allasutuse_reference) */
  $handler->display->display_options['relationships']['field_t_allasutuse_reference_tid']['id'] = 'field_t_allasutuse_reference_tid';
  $handler->display->display_options['relationships']['field_t_allasutuse_reference_tid']['table'] = 'field_data_field_t_allasutuse_reference';
  $handler->display->display_options['relationships']['field_t_allasutuse_reference_tid']['field'] = 'field_t_allasutuse_reference_tid';
  $handler->display->display_options['relationships']['field_t_allasutuse_reference_tid']['relationship'] = 'nid';
  $handler->display->display_options['relationships']['field_t_allasutuse_reference_tid']['label'] = 'Institution ref';
  $handler->display->display_options['relationships']['field_t_allasutuse_reference_tid']['required'] = TRUE;
  /* Relationship: Sisu: Measurement year and channels (field_c_mootmise_aasta) */
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['id'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['table'] = 'field_data_field_c_mootmise_aasta';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['field'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['relationship'] = 'nid';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['label'] = 'Measurement years';
  $handler->display->display_options['relationships']['field_c_mootmise_aasta_value']['delta'] = '-1';
  /* Relationship: Field collection item: Mõõtmise kanal (field_fcf_mootmise_kanal) */
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['id'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['table'] = 'field_data_field_fcf_mootmise_kanal';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['field'] = 'field_fcf_mootmise_kanal_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['relationship'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['label'] = 'Measurement channel';
  $handler->display->display_options['relationships']['field_fcf_mootmise_kanal_value']['delta'] = '-1';
  /* Relationship: Taksonoomia termin: Vanemtermin */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['relationship'] = 'field_f_allasutuse_reference_tid';
  $handler->display->display_options['relationships']['parent']['label'] = 'Ministeerium';
  $handler->display->display_options['relationships']['parent']['required'] = TRUE;
  /* Väli: View: Teenuste arv */
  $handler->display->display_options['fields']['view_1']['id'] = 'view_1';
  $handler->display->display_options['fields']['view_1']['table'] = 'views';
  $handler->display->display_options['fields']['view_1']['field'] = 'view';
  $handler->display->display_options['fields']['view_1']['ui_name'] = 'View: Teenuste arv';
  $handler->display->display_options['fields']['view_1']['label'] = '';
  $handler->display->display_options['fields']['view_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_1']['view'] = 'teenuste_statistika';
  $handler->display->display_options['fields']['view_1']['display'] = 'teenuste_arv_kokku';
  $handler->display->display_options['fields']['view_1']['arguments'] = '[!tid]';
  /* Väli: Taksonoomia termin: Nimi */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Väli: Taksonoomia termin: Termini ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'parent';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Väli: View: Ministeeriumi teenuste statistika */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['ui_name'] = 'View: Ministeeriumi teenuste statistika';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'ministeeriumi_teenuste_statistika';
  $handler->display->display_options['fields']['view']['display'] = 'ministeeriumi_teenuste_statistika_plokk';
  $handler->display->display_options['fields']['view']['arguments'] = '[!tid]';
  /* Sort criterion: Taksonoomia termin: Hierarchical weight */
  $handler->display->display_options['sorts']['hweight']['id'] = 'hweight';
  $handler->display->display_options['sorts']['hweight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['hweight']['field'] = 'hweight';
  $handler->display->display_options['sorts']['hweight']['relationship'] = 'parent';
  /* Filter criterion: Taksonoomia sõnastik: Süsteemne nimetus */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'valitsuse_puu' => 'valitsuse_puu',
  );
  /* Filter criterion: Field collection item: Mõõtmise aasta (field_fcf_mootmise_aasta) */
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['id'] = 'field_fcf_mootmise_aasta_tid';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['table'] = 'field_data_field_fcf_mootmise_aasta';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['field'] = 'field_fcf_mootmise_aasta_tid';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['relationship'] = 'field_c_mootmise_aasta_value';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['operator_id'] = 'field_fcf_mootmise_aasta_tid_op';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['label'] = 'Teenuse ostutamise aasta';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['operator'] = 'field_fcf_mootmise_aasta_tid_op';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['identifier'] = 'field_fcf_mootmise_aasta_tid';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_fcf_mootmise_aasta_tid']['vocabulary'] = 'mootmise_aastad';
  /* Filter criterion: Sisu: The status of the service (field_t_teenuse_seisund) */
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['id'] = 'field_t_teenuse_seisund_value';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['table'] = 'field_data_field_t_teenuse_seisund';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['field'] = 'field_t_teenuse_seisund_value';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['relationship'] = 'nid';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_t_teenuse_seisund_value']['value'] = array(
    'Loomisel' => 'Loomisel',
    'Arhiveeritud' => 'Arhiveeritud',
  );
  /* Filter criterion: Sisu: Avaldatud */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Sisu: Keel */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'nid';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Valitsuse teenused numbrites */
  $handler = $view->new_display('page', 'Valitsuse teenused numbrites', 'valitsuse_teenused_numbrites');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Päis: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'HTML title: Teenused numbrites';
  $handler->display->display_options['header']['area']['content'] = '<h1 class="statistics-page-title">Services in numbers</h1>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Päis: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['label'] = 'Custom text: View description text';
  $handler->display->display_options['header']['area_1']['content'] = '<div class="view-description-text">
Base statistics about the services across channels and institutions. The number of rendered services shows how many times the service was provided. The annual satisfaction shows the percentage of satisfied customers. The annual administrative cost shows the cost for the institution for rendering the service. Customer\'s administrative burden shows how much time in total did it took for the customer to consume a certain service in a particular channel.
</div>';
  $handler->display->display_options['header']['area_1']['format'] = 'full_html';
  /* Päis: Global: Text area */
  $handler->display->display_options['header']['area_2']['id'] = 'area_2';
  $handler->display->display_options['header']['area_2']['table'] = 'views';
  $handler->display->display_options['header']['area_2']['field'] = 'area';
  $handler->display->display_options['header']['area_2']['label'] = 'HTML title: Haldusala';
  $handler->display->display_options['header']['area_2']['content'] = '<h2 class="statistic-page-sub-title">Government\'s administration area</h2>';
  $handler->display->display_options['header']['area_2']['format'] = 'full_html';
  /* Päis: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['label'] = 'View: Teenuste arv';
  $handler->display->display_options['header']['view']['empty'] = TRUE;
  $handler->display->display_options['header']['view']['view_to_insert'] = 'teenuste_statistika:teenuste_arv_kokku';
  $handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
  /* Päis: Global: Text area */
  $handler->display->display_options['header']['area_3']['id'] = 'area_3';
  $handler->display->display_options['header']['area_3']['table'] = 'views';
  $handler->display->display_options['header']['area_3']['field'] = 'area';
  $handler->display->display_options['header']['area_3']['label'] = 'HTML title: Kanalite statistika';
  $handler->display->display_options['header']['area_3']['content'] = '<div class="statistic-page-channels-block"><h3>All services across channels</h3></div>';
  $handler->display->display_options['header']['area_3']['format'] = 'full_html';
  /* Päis: Global: View area */
  $handler->display->display_options['header']['view_1']['id'] = 'view_1';
  $handler->display->display_options['header']['view_1']['table'] = 'views';
  $handler->display->display_options['header']['view_1']['field'] = 'view';
  $handler->display->display_options['header']['view_1']['label'] = 'View: Kõik teenused kanalite lõikes';
  $handler->display->display_options['header']['view_1']['empty'] = TRUE;
  $handler->display->display_options['header']['view_1']['view_to_insert'] = 'kanaalite_statistika:kanalite_statistika';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Väli: View: Teenuste arv */
  $handler->display->display_options['fields']['view_1']['id'] = 'view_1';
  $handler->display->display_options['fields']['view_1']['table'] = 'views';
  $handler->display->display_options['fields']['view_1']['field'] = 'view';
  $handler->display->display_options['fields']['view_1']['ui_name'] = 'View: Teenuste arv';
  $handler->display->display_options['fields']['view_1']['label'] = '';
  $handler->display->display_options['fields']['view_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_1']['view'] = 'teenuste_statistika';
  $handler->display->display_options['fields']['view_1']['display'] = 'teenuste_arv_kokku';
  $handler->display->display_options['fields']['view_1']['arguments'] = '[!tid]';
  /* Väli: Taksonoomia termin: Name (translated) */
  $handler->display->display_options['fields']['name_i18n']['id'] = 'name_i18n';
  $handler->display->display_options['fields']['name_i18n']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_i18n']['field'] = 'name_i18n';
  $handler->display->display_options['fields']['name_i18n']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_i18n']['label'] = '';
  $handler->display->display_options['fields']['name_i18n']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_i18n']['element_label_colon'] = FALSE;
  /* Väli: Taksonoomia termin: Termini ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'parent';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Väli: View: Ministeeriumi teenuste statistika */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['ui_name'] = 'View: Ministeeriumi teenuste statistika';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'ministeeriumi_teenuste_statistika';
  $handler->display->display_options['fields']['view']['display'] = 'ministeeriumi_teenuste_statistika_plokk';
  $handler->display->display_options['fields']['view']['arguments'] = '[!tid]';
  $handler->display->display_options['path'] = 'statistika/valitsus';
  $handler->display->display_options['menu']['title'] = 'Valitsus';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-web-portal';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['valitsuse_teenuste_statistika'] = $view;

  return $export;
}
