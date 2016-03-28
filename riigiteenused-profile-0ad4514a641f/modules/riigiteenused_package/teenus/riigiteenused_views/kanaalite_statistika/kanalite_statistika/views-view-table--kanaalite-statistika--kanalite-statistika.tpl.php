<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */
$specialChars = array(" ", "%", "€", "h");
$replaceChars = array("", "", "", "");

$holder = array();
$tmp_rows = $rows;
$rows = array();
foreach ($tmp_rows as $key => $row_part) {
  if (!empty($row_part['name_i18n'])) {
    $osutamis_arv = str_replace($specialChars, $replaceChars, $row_part['field_fcf_osutamiste_arv']);
    $rahuolu = trim(str_replace($specialChars, $replaceChars, strip_tags($row_part['field_fcf_aasta_rahulolu'])));
    $halduskulu = str_replace($specialChars, $replaceChars, $row_part['field_fcf_aasta_halduskulu']);
    $halduskormus = str_replace($specialChars, $replaceChars, $row_part['field_fcf_ajakulu_klientidele']);

    $rahuolu_value = floatval($rahuolu);

    if (!empty($rahuolu)) {
      @$holder[$row_part['name_i18n']]['field_fcf_aasta_rahulolu'] += $rahuolu_value;
    }
    elseif (isset($holder[$row_part['name_i18n']])
      && !is_null($holder[$row_part['name_i18n']]['field_fcf_aasta_rahulolu'])
    ) {
      @$holder[$row_part['name_i18n']]['field_fcf_aasta_rahulolu'] = $holder[$row_part['name_i18n']]['field_fcf_aasta_rahulolu'];
    }
    else {
      @$holder[$row_part['name_i18n']]['field_fcf_aasta_rahulolu'] = NULL;
    }

    @$holder[$row_part['name_i18n']]['field_fcf_osutamiste_arv'] += is_numeric($osutamis_arv) ? floatval($osutamis_arv) : 0;
    @$holder[$row_part['name_i18n']]['field_fcf_aasta_halduskulu'] += is_numeric($halduskulu) ? $halduskulu : 0;
    @$holder[$row_part['name_i18n']]['field_fcf_ajakulu_klientidele'] += is_numeric($halduskormus) ? $halduskormus : 0;
    @$holder[$row_part['name_i18n']]['rahuolu_counter'] += !empty($rahuolu) ? 1 : 0;

    @$total_rahulolu_sum += !empty($rahuolu) ? $rahuolu_value : '';
    @$total_rahulolu_count += !empty($rahuolu) ? 1 : 0;
  }
}

foreach ($holder as $channel_name => $stat_block) {
  $rahuolu_avg = $stat_block['rahuolu_counter'] == 0 ? NULL : $stat_block['field_fcf_aasta_rahulolu'] / $stat_block['rahuolu_counter'];

  if ($rahuolu_avg >= 75) {
    $wrapper = '<div class="stat-green">__place__</div>';
  }
  elseif ($rahuolu_avg >= 50 && $rahuolu_avg < 75) {
    $wrapper = '<div class="stat-yellow">__place__</div>';
  }
  else {
    $wrapper = '<div class="stat-red">__place__</div>';
  }

  $rows[] = array(
    'name_i18n' => $channel_name,
    'field_fcf_osutamiste_arv'
      => !empty($stat_block['field_fcf_osutamiste_arv']) ? number_format($stat_block['field_fcf_osutamiste_arv'], 0, '.', ' ') : '-',
    'field_fcf_aasta_rahulolu'
      => !is_null($rahuolu_avg) ? str_replace('__place__', number_format($rahuolu_avg, 2, '.', ' ') . '%', $wrapper) : str_replace('__place__', '-', $wrapper),
    'field_fcf_aasta_halduskulu'
      => !empty($stat_block['field_fcf_aasta_halduskulu']) ? number_format($stat_block['field_fcf_aasta_halduskulu'], 2, '.', ' ') . '€' : '-',
    'field_fcf_ajakulu_klientidele'
      => !empty($stat_block['field_fcf_ajakulu_klientidele']) ? number_format($stat_block['field_fcf_ajakulu_klientidele'], 2, '.', ' ') . 'h' : '-',
  );
}
unset($osutamis_arv, $rahuolu, $rahuolu_value, $halduskulu, $halduskormus);

$total_rows = array();
foreach ($rows as $key => $row) {
  $osutamis_arv = str_replace($specialChars, $replaceChars, $row['field_fcf_osutamiste_arv']);
  $rahuolu = trim(str_replace($specialChars, $replaceChars, strip_tags($row['field_fcf_aasta_rahulolu'])));
  $halduskulu = str_replace($specialChars, $replaceChars, $row['field_fcf_aasta_halduskulu']);
  $halduskormus = str_replace($specialChars, $replaceChars, $row['field_fcf_ajakulu_klientidele']);

  $rahuolu_value = floatval($rahuolu);

  if (!empty($rahuolu)) {
    @$total_rows['rahuolu'] += $rahuolu_value;
  }
  elseif (isset($total_rows['rahuolu']) && !is_null($total_rows['rahuolu'])) {
    @$total_rows['rahuolu'] = $total_rows['rahuolu'];
  }
  else {
    @$total_rows['rahuolu'] = NULL;
  }

  @$total_rows['osutamis_arv'] += is_numeric($osutamis_arv) ? floatval($osutamis_arv) : 0;
  @$total_rows['halduskulu'] += is_numeric($halduskulu) ? $halduskulu : 0;
  @$total_rows['halduskormus'] += is_numeric($halduskormus) ? $halduskormus : 0;
  @$total_rows['rahuolu_counter'] += $rahuolu_value != 0 ? 1 : 0;
}

if (isset($total_rows['rahuolu_counter']) && $total_rows['rahuolu_counter'] > 0) {
  $total_rows['rahuolu'] = $total_rahulolu_sum / $total_rahulolu_count;
}

$number_value = isset($total_rows['rahuolu']) ? $total_rows['rahuolu'] : FALSE;
if (is_numeric($number_value)) {
  if ($number_value >= 75) {
    $fclasses = ' green-td';
    $class = 'class="stat-green"';
  }
  elseif ($number_value >= 50 && $number_value < 75) {
    $fclasses = ' yellow-td';
    $class = 'class="stat-yellow"';
  }
  else {
    $fclasses = ' red-td';
    $class = 'class="stat-red"';
  }
}
else {
  $fclasses = ' red-td';
  $class = 'class="stat-red"';
}
?>
<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?>>
  <?php if (!empty($title) || !empty($caption)) : ?>
    <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
    <tr>
      <?php foreach ($header as $field => $label): ?>
        <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?>>
          <?php print $label; ?>
        </th>
      <?php endforeach; ?>
    </tr>
    </thead>
  <?php endif; ?>
  <tbody>
  <?php foreach ($rows as $row_count => $row): ?>
    <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
      <?php foreach ($row as $field => $content): ?>
        <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
          <?php print $content; ?>
        </td>
      <?php endforeach; ?>
    </tr>
  <?php endforeach; ?>
  </tbody>
  <tfoot>
  <tr>
    <th class="views-field views-field-name">
      <div>
        <?php print t('The total statistics of services under the governance area'); ?>
      </div>
    </th>
    <th class="views-field views-field-field-fcf-osutamiste-arv">
      <div>
        <div
          class="field field-name-field-fcf-osutamiste-arv field-type-number-integer field-label-hidden">
          <div class="field-items">
            <div class="field-item even">
              <?php print !empty($total_rows['osutamis_arv']) ? number_format($total_rows['osutamis_arv'], 0, '.', ' ') : '-'; ?>
            </div>
          </div>
        </div>
      </div>
    </th>
    <th class="views-field views-field-field-fcf-aasta-rahulolu<?php print $fclasses; ?>">
      <div <?php print $class; ?>>
        <div
          class="field field-name-field-fcf-aasta-rahulolu field-type-number-float field-label-hidden">
          <div class="field-items">
            <div class="field-item even">
              <?php print !is_null($total_rows['rahuolu']) ? number_format($total_rows['rahuolu'], 2, '.', ' ') . '%' : '-'; ?>
            </div>
        </div>
      </div>
    </th>
    <th class="views-field views-field-field-fcf-aasta-halduskulu">
      <div>
        <div
          class="field field-name-field-fcf-aasta-halduskulu field-type-number-float field-label-hidden">
          <div class="field-items">
            <div class="field-item even">
              <?php print !empty($total_rows['halduskulu']) ? number_format($total_rows['halduskulu'], 2, '.', ' ') . '€' : '-'; ?>
            </div>
          </div>
        </div>
      </div>
    </th>
    <th class="views-field views-field-field-fcf-ajakulu-klientidele">
      <div>
        <div
          class="field field-name-field-fcf-ajakulu-klientidele field-type-number-float field-label-hidden">
          <div class="field-items">
            <div class="field-item even">
              <?php print !empty($total_rows['halduskormus']) ? number_format($total_rows['halduskormus'], 2, '.', ' ') . 'h' : '-'; ?>
            </div>
          </div>
        </div>
      </div>
    </th>
  </tr>
  </tfoot>
</table>
