<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_projects_front_context_default_contexts() {
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
      'scholar_projects_front_0' => array(
        'module' => 'scholar_projects_front',
        'delta' => '0',
        'weight' => 20,
        'region' => 'content_top',
        'status' => '0',
        'label' => 'row 1',
        'type' => 'context_ui',
      ),
      'scholar_projects_front_1' => array(
        'module' => 'scholar_projects_front',
        'delta' => '1',
        'weight' => 21,
        'region' => 'content_top',
        'status' => '0',
        'label' => 'row 2',
        'type' => 'context_ui',
      ),
      'views_scholar_projects_front_sites-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_projects_front_sites-block_1',
        'weight' => 22,
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
function _scholar_projects_front_imagecache_default_presets() {
  $items = array(
    'scholar_projects_front_front_logo' => array(
      'presetname' => 'scholar_projects_front_front_logo',
      'actions' => array(
        '0' => array(
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
