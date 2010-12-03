<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_announcements_context_default_contexts() {
  $items = array();

  $items['scholar-feature-announcements'] = array(
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
 * Implementation of hook_node_info().
 */
function scholar_announcements_node_info() {
  $items = array(
    'announcement' => array(
      'name' => t('Announcement'),
      'module' => 'features',
      'description' => t('Manage announcements in your web site'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function scholar_announcements_views_api() {
  return array(
    'api' => '2',
  );
}
