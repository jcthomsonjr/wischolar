<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_feeds_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'feeds',
    'description' => 'scholar > feeds',
    'node' => array(
      '0' => 'feed',
      '1' => 'feed_item',
    ),
    'menu_trail' => array(
      'feeds' => 'feeds',
    ),
    'views' => array(
      '0' => 'scholar_feed_items',
      '1' => 'scholar_feeds',
    ),
    'menu' => 'feeds',
    'block' => array(
      'views_scholar_feed_items-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_feed_items-block_1',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'scholar_feed_items: Latest feed items',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_feeds_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Feeds',
    'path' => 'feeds',
    'weight' => '0',
    'description' => 'My feeds',
  );
  // Translatables
  array(
    t('Feeds'),
    t('My feeds'),
  );


  return $items;
}
