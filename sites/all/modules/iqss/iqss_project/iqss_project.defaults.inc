<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _iqss_project_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'iqss',
    'attribute' => 'feature',
    'value' => 'project',
    'description' => 'IQSS scholar front page',
    'path' => array(
      '<front>' => '<front>',
    ),
    'block' => array(
      'iqss_project_0' => array(
        'module' => 'iqss_project',
        'delta' => '0',
        'weight' => 20,
        'region' => 'content_top',
        'status' => '0',
        'label' => 'row 1',
        'type' => 'context_ui',
      ),
      'iqss_project_1' => array(
        'module' => 'iqss_project',
        'delta' => '1',
        'weight' => 21,
        'region' => 'content_top',
        'status' => '0',
        'label' => 'row 2',
        'type' => 'context_ui',
      ),
      'iqss_project_2' => array(
        'module' => 'iqss_project',
        'delta' => '2',
        'weight' => 22,
        'region' => 'content_top',
        'status' => '0',
        'label' => 'row 3',
        'type' => 'context_ui',
      ),
      'views_iqss_project_sites-block_1' => array(
        'module' => 'views',
        'delta' => 'iqss_project_sites-block_1',
        'weight' => 23,
        'region' => 'content_top',
        'status' => '0',
        'label' => 'Letest web sites',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _iqss_project_imagecache_default_presets() {
  $items = array(
    'iqss_project_front_logo' => array(
      'presetname' => 'iqss_project_front_logo',
      'actions' => array(
        '0' => array(
          'actionid' => '1',
          'presetid' => '1',
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '100',
            'height' => '100',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _iqss_project_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Announcements',
    'path' => 'announcements',
    'weight' => '0',
    'description' => 'List of announcements in my site',
  );
  // Translatables
  array(
    t('Announcements'),
    t('List of announcements in my site'),
  );


  return $items;
}
