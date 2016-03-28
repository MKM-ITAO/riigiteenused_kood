<?php
/**
 * @file
 * taxonomies.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function taxonomies_taxonomy_default_vocabularies() {
  return array(
    'kanaalide_struktuur' => array(
      'name' => 'Riigiteenused: Kanaalide struktuur',
      'machine_name' => 'kanaalide_struktuur',
      'description' => 'Kirjeldab mis tüübi kanaalid on võimalik lisada.',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 4,
    ),
    'mootmise_aastad' => array(
      'name' => 'Riigiteenused: Mõõtmise aastad',
      'machine_name' => 'mootmise_aastad',
      'description' => 'Mõõtmise aastate loend.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'teenuse_tyybid' => array(
      'name' => 'Riigiteenused: Teenuse tüübid',
      'machine_name' => 'teenuse_tyybid',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 4,
    ),
    'tegevusvaldkonnad' => array(
      'name' => 'Riigiteenused: Tegevusvaldkonnad',
      'machine_name' => 'tegevusvaldkonnad',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 4,
    ),
    'valitsuse_puu' => array(
      'name' => 'Riigiteenused: Valitsuse puu',
      'machine_name' => 'valitsuse_puu',
      'description' => 'Defineerib kuidas ministeeriumid ja allasutused on valitsuses jaotud.',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 4,
    ),
  );
}
