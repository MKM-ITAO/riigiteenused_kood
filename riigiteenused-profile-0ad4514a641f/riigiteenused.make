api = 2
core = 7.x

; Core
projects[drupal][version] = 7.43

; Contrib projects
projects[admin_menu][subdir] = contrib
projects[admin_menu][version] = 3.0-rc5

projects[admin_views][subdir] = contrib
projects[admin_views][version] = 1.5

projects[adminimal_admin_menu][subdir] = contrib
projects[adminimal_admin_menu][version] = 1.5

projects[better_exposed_filters][subdir] = contrib
projects[better_exposed_filters][version] = 3.2

projects[block_class][subdir] = contrib
projects[block_class][version] = 2.3

projects[email][subdir] = contrib
projects[email][version] = 1.3

projects[ctools][subdir] = contrib
projects[ctools][version] = 1.9

; Enable if some custom permissions needed
; projects[config_perms][subdir] = contrib
; projects[config_perms][version] = 2.0

projects[date][subdir] = contrib
projects[date][version] = 2.9

projects[devel][subdir] = contrib
projects[devel][version] = 1.5

projects[delta][subdir] = contrib
projects[delta][version] = 3.0-beta11

projects[diff][subdir] = contrib
projects[diff][version] = 3.2

projects[ds][subdir] = contrib
projects[ds][version] = 2.8

; Enable if email field needed
; projects[email][subdir] = contrib
; projects[email][version] = 1.3

projects[entity][subdir] = contrib
projects[entity][version] = 1.6

projects[entitycache][subdir] = contrib
projects[entitycache][version] = 1.2

projects[entityreference][subdir] = contrib
projects[entityreference][version] = 1.1

projects[entity_translation][subdir] = contrib
projects[entity_translation][version] = 1.0-beta4

projects[features][subdir] = contrib
projects[features][version] = 2.7
;projects[features][patch][] = https://www.drupal.org/files/issues/features-catch_field_exceptions-1664160-26.patch

projects[field_collection][subdir] = contrib
projects[field_collection][version] = 7.x-1.0-beta11

projects[field_collection_fieldset][subdir] = contrib
projects[field_collection_fieldset][version] = 2.6

projects[field_group][subdir] = contrib
projects[field_group][version] = 1.5

projects[i18n][subdir] = contrib
projects[i18n][version] = 1.13

projects[i18nviews][subdir] = contrib
projects[i18nviews][version] = 7.x-3.0-alpha1

projects[jquery_update][subdir] = contrib
projects[jquery_update][version] = 2.7

projects[language_switcher_fallback][subdir] = contrib
projects[language_switcher_fallback][version] = 1.1

projects[libraries][subdir] = contrib
projects[libraries][version] = 2.2

projects[link][subdir] = contrib
projects[link][version] = 1.4

projects[local_tasks_fixed_to_bottom][subdir] = contrib
projects[local_tasks_fixed_to_bottom][version] = 1.0

projects[mailsystem][subdir] = contrib
projects[mailsystem][version] = 2.34

projects[memcache][subdir] = contrib
projects[memcache][version] = 1.5

projects[menu_block][subdir] = contrib
projects[menu_block][version] = 2.7

projects[menu_item_visibility][subdir] = contrib
projects[menu_item_visibility][version] = 1.0-beta1

projects[migrate][subdir] = contrib
projects[migrate][version] = 2.8

projects[module_filter][subdir] = contrib
projects[module_filter][version] = 2.0

projects[panels][subdir] = contrib
projects[panels][version] = 3.5

projects[panels_everywhere][subdir] = contrib
projects[panels_everywhere][version] = 1.0-rc2

projects[pathauto][subdir] = contrib
projects[pathauto][version] = 1.3

projects[registry_rebuild][subdir] = contrib
projects[registry_rebuild][version] = 2.3

projects[search_krumo][subdir] = contrib
projects[search_krumo][version] = 1.6

projects[security_review][subdir] = contrib
projects[security_review][version] = 1.2

projects[scheduler][subdir] = contrib
projects[scheduler][version] = 1.3

projects[shs][subdir] = contrib
projects[shs][version] = 1.6
; https://www.drupal.org/node/2296455 - fixed in dev, actual for 1.6 version.
projects[shs][patch][] = https://www.drupal.org/files/issues/shs_inline-entity-form_2296455.patch

projects[smtp][subdir] = contrib
projects[smtp][version] = 1.3

projects[strongarm][subdir] = contrib
projects[strongarm][version] = 2.0

projects[token][subdir] = contrib
projects[token][version] = 1.6

projects[uuid][subdir] = contrib
projects[uuid][version] = 1.0-alpha6

projects[uuid_features][subdir] = contrib
projects[uuid_features][version] = 1.0-alpha4

projects[variable][subdir] = contrib
projects[variable][version] = 2.5

projects[views][subdir] = contrib
projects[views][version] = 3.11
projects[views][patch][] = https://www.drupal.org/files/views-1685144-localization-bug_1.patch

projects[views_aggregator][subdir] = contrib
projects[views_aggregator][version] = 1.4

projects[views_bulk_operations][subdir] = contrib
projects[views_bulk_operations][version] = 3.3

projects[views_field_view][subdir] = contrib
projects[views_field_view][version] = 1.1

projects[views_term_hierarchy_weight_field][subdir] = contrib
projects[views_term_hierarchy_weight_field][version] = 1.2

projects[wysiwyg][subdir] = contrib
projects[wysiwyg][version] = 2.2

; Custom projects
;projects[service_catalog][subdir] = custom
;projects[service_catalog][download][type] = git
;projects[service_catalog][download][url] = git@bitbucket.org:eDragon/service-catalog-module.git

; Themes
projects[bootstrap][version] = 3.0
projects[bootstrap][patch][] = https://www.drupal.org/files/issues/bootstrap-2292899-3_0.patch
projects[bootstrap][patch][] = https://www.drupal.org/files/issues/bootstrap-webform-email.patch
projects[bootstrap][patch][] = https://www.drupal.org/files/issues/bootstrap-pager-translation-2479423.patch

projects[adminimal_theme][version] = 1.20

; Libraries
libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.3.4/ckeditor_4.3.4_full.tar.gz
libraries[ckeditor][destination] = libraries
