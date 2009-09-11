<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_announcements_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'announcements',
    'description' => 'Announcements feature context',
    'node' => array(
      '0' => 'announcement',
    ),
    'views' => array(
      '0' => 'scholar_announcements',
    ),
    'menu' => 'announcements',
    'block' => array(
      'views_scholar_announcements-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_announcements-block_1',
        'weight' => -21,
        'region' => 'right',
        'status' => '0',
        'label' => 'Latest Announcements',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_announcements_menu_default_items() {
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
