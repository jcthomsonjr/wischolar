<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_publications_context_default_contexts() {
  $items = array();

  $items['scholar-feature-publications'] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'publications',
    'node' => array(
      '0' => 'biblio',
    ),
    'path' => array(
      'publications' => 'publications',
      'publications/*' => 'publications/*',
    ),
    'menu' => 'publications',
    'block' => array(
      'vsite_taxonomy_0' => array(
        'module' => 'vsite_taxonomy',
        'delta' => '0',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Categories - A widget used to quickly filter categorized content',
        'type' => 'context_ui',
      ),
      'views_scholar_publications-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_publications-block_1',
        'weight' => 21,
        'region' => 'right',
        'status' => '0',
        'label' => 'Recent publications',
        'type' => 'context_ui',
      ),
      'vsite_widgets_4' => array(
        'module' => 'vsite_widgets',
        'delta' => '2',
        'weight' => 22,
        'region' => 'right',
        'status' => '0',
        'label' => 'ShareThis Button - Allows you to share posts using popular online services',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function scholar_publications_imagecache_default_presets() {
  $items = array(
    'book_cover' => array(
      'presetname' => 'book_cover',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '100',
            'height' => '100%',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function scholar_publications_views_api() {
  return array(
    'api' => '2',
  );
}
