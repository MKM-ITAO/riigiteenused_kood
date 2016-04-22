<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */

$all_service_statistics = array();
if ($term = taxonomy_term_load($output)) {
  // If ministry term.
  $nodes = array();
  $child_terms = taxonomy_get_children($term->tid);
  if (!empty($child_terms)) {
    foreach ($child_terms as $tid => $term_object) {
      $term_nodes = taxonomy_select_nodes($term_object->tid, FALSE);
      $nodes = array_merge($nodes, $term_nodes);
    }
  }
  else {
    $nodes = taxonomy_select_nodes($term->tid, FALSE);
  }

  if (!empty($nodes)) {
    foreach ($nodes as $nid) {
      $service_statistics = _teenus_get_statistics($nid, $view->old_view[0]->exposed_data['field_fcf_mootmise_aasta_tid']);

      if (!is_null(@$total_statistics['rahuolu'])) {
        @$all_service_statistics['rahuolu'] += $service_statistics['total']['rahuolu'];
      }
      elseif (isset($all_service_statistics['rahuolu'])
        && !is_null($all_service_statistics['rahuolu'])
      ) {
        @$all_service_statistics['rahuolu'] = $total_statistics['rahuolu'];
      }
      else {
        @$all_service_statistics['rahuolu'] = NULL;
      }
      @$all_service_statistics['rahuolu_counter'] += !is_null($service_statistics['total']['rahuolu']) ? 1 : 0;
      @$all_service_statistics['rahuolu2'] += $service_statistics['total']['totalsum'];//sum get from function _teenus_get_statistics
      @$all_service_statistics['rahuolu_counter2'] += $service_statistics['total']['totalcount'];//count get from function _teenus_get_statistics

      @$all_service_statistics['osutamis_arv'] += $service_statistics['total']['osutamis_arv'];
      @$all_service_statistics['halduskulu'] += $service_statistics['total']['halduskulu'];
      @$all_service_statistics['halduskormus'] += $service_statistics['total']['halduskormus'];
    }
  }

  if (!empty($all_service_statistics) && $all_service_statistics['rahuolu_counter'] != 0) {
    $all_service_statistics['rahuolu'] = round($all_service_statistics['rahuolu2'] / $all_service_statistics['rahuolu_counter2'], 2);
  }
}
else {
  // All terms in valitsuse_puu
}

$number_value = isset($all_service_statistics['rahuolu']) ? $all_service_statistics['rahuolu'] : FALSE;
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
<div class="view view-kanaalite-statistika view-id-kanaalite_statistika view-display-id-kanalite_statistika_yldnumbrid_no_text view-dom-id-95b8b43bcd553266740305e72d0fd2ae">
  <div class="view-content">
    <table class="views-table cols-0" id="views-aggregator-datatable">
      <thead>
      </thead>
      <tbody>
      <tr>
        <td class="views-field views-field-nothing">
        </td>
        <td class="views-field views-field-field-fcf-osutamiste-arv">
          <?php print !empty($all_service_statistics['osutamis_arv']) ? number_format($all_service_statistics['osutamis_arv'], 0, '.', ' ') : '-'; ?>
        </td>
        <td class="views-field views-field-field-fcf-aasta-rahulolu<?php print $fclasses; ?>">
          <div <?php print $class ?>>
            <?php print !empty($all_service_statistics['rahuolu']) ? number_format($all_service_statistics['rahuolu'], 2, '.', ' ') . '%' : '-'; ?>
          </div>
        </td>
        <td class="views-field views-field-field-fcf-aasta-halduskulu">
          <?php print !empty($all_service_statistics['halduskulu']) ? number_format($all_service_statistics['halduskulu'], 2, '.', ' ') . '€' : '-'; ?>
        </td>
        <td class="views-field views-field-field-fcf-ajakulu-klientidele">
          <?php print !empty($all_service_statistics['halduskormus']) ? number_format($all_service_statistics['halduskormus'], 2, '.', ' ') . 'h' : '-'; ?>
        </td>
      </tr>
      </tbody>
    </table>
  </div>
</div>
