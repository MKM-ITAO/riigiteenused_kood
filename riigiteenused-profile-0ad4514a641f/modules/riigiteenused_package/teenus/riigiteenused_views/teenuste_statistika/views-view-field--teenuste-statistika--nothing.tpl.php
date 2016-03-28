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
$service_statistics = _teenus_get_statistics($row->nid, $view->exposed_data['field_fcf_mootmise_aasta_tid']);
?>
<div
  class="view view-kanaalite-statistika view-id-kanaalite_statistika view-display-id-teenuse_kanalite_statistika view-dom-id-6486a7363d2cbd69f7384d807bb335a3">
  <div class="view-content">
    <table class="views-table cols-5">
      <thead>
      <tr class="" style="display: none;">
        <th class="views-field views-field-name">
        </th>
        <th class="views-field views-field-field-fcf-osutamiste-arv">
          <?php print t('The number of times the service has been rendered');?>
        </th>
        <th class="views-field views-field-field-fcf-aasta-rahulolu">
          <?php print t('Annual satisfaction'); ?>
        </th>
        <th class="views-field views-field-field-fcf-aasta-halduskulu">
          <?php print t('Annual administrative cost'); ?>
        </th>
        <th class="views-field views-field-field-fcf-ajakulu-klientidele">
          <?php print t("Customer's administrative burden"); ?>
        </th>
      </tr>
      <tr class="">
        <th class="views-field views-field-name">
        </th>
        <th class="views-field views-field-field-fcf-osutamiste-arv">
          <div
            class="field field-name-field-fcf-osutamiste-arv field-type-number-integer field-label-hidden">
            <div class="field-items">
              <div class="field-item even"><?php print !empty($service_statistics['total']['osutamis_arv']) ? number_format($service_statistics['total']['osutamis_arv'], 0, '.', ' ') : '-'; ?></div>
            </div>
          </div>
        </th>
        <th class="views-field views-field-field-fcf-aasta-rahulolu">
          <div
            class="field field-name-field-fcf-aasta-rahulolu field-type-number-float field-label-hidden">
            <div class="field-items">
              <div class="field-item even"><?php print isset($service_statistics['total']) && !is_null($service_statistics['total']['rahuolu']) ? number_format($service_statistics['total']['rahuolu'], 2, '.', ' ') . '%' : '-'; ?></div>
            </div>
          </div>
        </th>
        <th class="views-field views-field-field-fcf-aasta-halduskulu">
          <div
            class="field field-name-field-fcf-aasta-halduskulu field-type-number-float field-label-hidden">
            <div class="field-items">
              <div class="field-item even"><?php print !empty($service_statistics['total']['halduskulu']) ? number_format($service_statistics['total']['halduskulu'], 2, '.', ' ') . '€' : '-'; ?></div>
            </div>
          </div>
        </th>
        <th class="views-field views-field-field-fcf-ajakulu-klientidele">
          <div
            class="field field-name-field-fcf-ajakulu-klientidele field-type-number-float field-label-hidden">
            <div class="field-items">
              <div class="field-item even"><?php print !empty($service_statistics['total']['halduskormus']) ? number_format($service_statistics['total']['halduskormus'], 2, '.', ' ') . 'h' : '-'; ?></div>
            </div>
          </div>
        </th>
      </tr>
      </thead>
      <tbody style="display: none;">
      <?php foreach ($service_statistics as $channel_name => $channel_stat): ?>
        <tr>
          <?php if ($channel_name == 'total') continue; ?>
          <td class="views-field views-field-name">
            <?php print $channel_name; ?>
          </td>
          <td class="views-field views-field-field-fcf-osutamiste-arv">
            <?php print !empty($service_statistics[$channel_name]['osutamis_arv']) ? number_format($service_statistics[$channel_name]['osutamis_arv'], 0, '.', ' ') : '-'; ?>
          </td>
          <?php
            $number_value = $service_statistics[$channel_name]['rahuolu'];
            $fclasses = ' red-td';
            $class = 'class="stat-red"';
            if (is_numeric($number_value)) {
              if ($number_value >= 75) {
                $fclasses = ' green-td';
                $class = 'class="stat-green"';
              }
              elseif ($number_value >= 50 && $number_value < 75) {
                $fclasses = ' yellow-td';
                $class = 'class="stat-yellow"';
              }
            }
          ?>
          <td class="views-field views-field-field-fcf-aasta-rahulolu<?php print $fclasses; ?>">
            <div <?php print $class ?>>
              <?php print !is_null($service_statistics[$channel_name]['rahuolu']) ? number_format($service_statistics[$channel_name]['rahuolu'], 2, '.', ' ') . '%' : '-'; ?>
            </div>
          </td>
          <td class="views-field views-field-field-fcf-aasta-halduskulu">
            <?php print !empty($service_statistics[$channel_name]['halduskulu']) ? number_format($service_statistics[$channel_name]['halduskulu'], 2, '.', ' ') . '€' : '-'; ?>
          </td>
          <td class="views-field views-field-field-fcf-ajakulu-klientidele">
            <?php print !empty($service_statistics[$channel_name]['halduskormus']) ? number_format($service_statistics[$channel_name]['halduskormus'], 2, '.', ' ') . 'h' : '-'; ?>
          </td>
        </tr>
      <?php endforeach; ?>
      </tbody>
    </table>
  </div>
</div>
