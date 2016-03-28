<?php

/**
 * @file
 * Importer factory.
 *
 * ImporterFactory class made to build Importer class object with all required
 * dependencies.
 */

/**
 * Class ImporterFactory.
 */
class ImporterFactory {

  /**
   * Build Importer object with all required dependencies.
   *
   * @param string $api_terms_url
   *   Terms API url.
   * @param string $api_nodes_url
   *   Services API url.
   *
   * @return \Importer
   *   Importer class object.
   */
  public static function build($api_terms_url = NULL, $api_nodes_url = NULL) {
    module_load_include('inc', 'rt_teenus_importer', 'inc/importer');
    module_load_include('inc', 'rt_teenus_importer', 'inc/importer_storage');

    return new Importer(new ImporterStorage(), $api_terms_url, $api_nodes_url);
  }

}