<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_links_context_default_contexts() {
  $items = array();

  $items['scholar-feature-links'] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'links',
    'description' => 'Links feature context',
    'node' => array(
      '0' => 'link',
    ),
    'views' => array(
      '0' => 'scholar_links',
    ),
    'menu' => 'links',
    'block' => array(
      'vsite_taxonomy_0' => array(
        'module' => 'vsite_taxonomy',
        'delta' => '0',
        'weight' => -20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Scholar site categories',
        'type' => 'context_ui',
      ),
      'vsite_widgets_4' => array(
        'module' => 'vsite_widgets',
        'delta' => '2',
        'weight' => 50,
        'region' => 'right',
        'status' => '0',
        'label' => 'AddThis button',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function scholar_links_imagecache_default_presets() {
  $items = array(
    'image_s' => array(
      'presetname' => 'image_s',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '90',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function scholar_links_node_info() {
  $items = array(
    'link' => array(
      'name' => t('Link'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function scholar_links_views_api() {
  return array(
    'api' => '2',
  );
}
