<?php
/**
 * @file
 * Default simple view template to display a list of summary lines.
 *
 * @ingroup views_templates
 */

/**
 * Overrides the default Views version (in sites/all/modules) to display the
 * whole alphabet.
 */

$alphabet_letters = array('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
  'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'Š','T', 'U', 'V', 'W', 'Z', 'Ž', 'Õ',
  'Ä', 'Ö', 'Ü', 'X', 'Y',
);

$query = db_query("SELECT DISTINCT UCASE(LEFT(title, 1)) as letter FROM node n WHERE type = 'teenus' ORDER BY letter;");
$used_symbols = $query->fetchCol();

$letters = array_unique(array_merge($alphabet_letters, $used_symbols));
$letters = array_values($letters);

// Parse the letter list, outputting one element per letter.
$counter = 0;
// Traverses the $rows array as letters with links are processed.
$max = count($rows);
$rows_additional = array();
if (is_array($rows)) {
  foreach ($rows as $row) {
    $rows_additional[$row->link] = $row;
  }
}

$url_parts = explode('/', $_GET['q']);
for ($i = 0; $i < count($letters); $i++) {
  $additional_class = '';
  $current_letter = trim($letters[$i]);

  if (empty($current_letter)) {
    continue;
  }

  if (isset($url_parts[1]) && strtoupper($url_parts[1]) == $current_letter) {
    $additional_class = ' chosen-letter';
  }

//  if (!empty($row->separator)) {
//    print $row->separator;
//  }

  if (isset($rows_additional[$current_letter])) {
    $additional_class .= ' active-letter';
    $output = '<a href="'. $rows_additional[$current_letter]->url. '"><span class="letter">'. $rows_additional[$current_letter]->link .'</span></a>';
  }
  else {
    $additional_class .= ' disabled-letter';
    // This letter does not have a link, print it plain
    $output = $current_letter;
  }

  print '<span class="views-summary views-summary-unformatted' . $additional_class . '">';
  print $output;
  print '</span>';
}

global $language;

$current_url = '/' . $language->language . '/' . $view->display['teenuste_otsing_page']->display_options['path'];
print '<span class="views-summary views-summary-unformatted show-all-letters">';
print '<a href="' . $current_url . '/"><span class="show-all-letters-span">'. t('Show all') .'</span></a>';
print '</span>';
