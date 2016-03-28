<?php
/**
 * @file
 * menus.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function menus_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'valitsuse_teenused';
  $page->task = 'page';
  $page->admin_title = 'Valitsuse teenused';
  $page->admin_description = '';
  $page->path = 'valitsuse-teenused';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_valitsuse_teenused__panel_context_4d44ffda-71d5-42b8-b541-c17d7756e867';
  $handler->task = 'page';
  $handler->subtask = 'valitsuse_teenused';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5e8b057e-12fb-4d67-bd9a-f11d012cd03a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-aa9199b4-0363-47c9-934e-70f6cbf7134f';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views-fd69b09acbdd7431037b2cdca7deadc1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'aa9199b4-0363-47c9-934e-70f6cbf7134f';
    $display->content['new-aa9199b4-0363-47c9-934e-70f6cbf7134f'] = $pane;
    $display->panels['center'][0] = 'new-aa9199b4-0363-47c9-934e-70f6cbf7134f';
    $pane = new stdClass();
    $pane->pid = 'new-8ac03c8d-a3f2-4047-94e1-22a9509f7d98';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views-55982814919d0cfdc19f096cadba003f';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8ac03c8d-a3f2-4047-94e1-22a9509f7d98';
    $display->content['new-8ac03c8d-a3f2-4047-94e1-22a9509f7d98'] = $pane;
    $display->panels['center'][1] = 'new-8ac03c8d-a3f2-4047-94e1-22a9509f7d98';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-8ac03c8d-a3f2-4047-94e1-22a9509f7d98';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['valitsuse_teenused'] = $page;

  return $pages;

}
