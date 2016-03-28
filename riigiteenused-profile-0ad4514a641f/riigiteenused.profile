<?php

/**
 * @file
 * Riigiteenused profile.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function riigiteenused_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate some fields in configure site form.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
  $form['site_information']['site_mail']['#default_value'] = 'admin@' . $_SERVER['SERVER_NAME'];
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  $form['admin_account']['account']['mail']['#default_value'] = 'admin@' . $_SERVER['SERVER_NAME'];
  $form['server_settings']['site_default_country']['#default_value'] = 'ET';
  $form['server_settings']['date_default_timezone']['#default_value'] = 'Europe/Tallinn';
}

/**
 * Implements hook_install_tasks().
 */
function riigiteenused_install_tasks($install_state) {
  $tasks = array(
    'riigiteenused_setup_siteconfig' => array(
      'display_name' => st('Cleanup'),
      'display' => FALSE,
      'type' => 'normal',
    ),
  );
  return $tasks;
}

/**
 * Install task.
 */
function riigiteenused_setup_siteconfig() {
  theme_enable(array('adminimal_theme'));
  variable_set('admin_theme', 'adminimal_theme');
  variable_set('site_frontpage', 'empty');

  features_rebuild();
  features_revert();
}
