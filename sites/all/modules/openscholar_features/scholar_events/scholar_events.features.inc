<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_events_context_default_contexts() {
  $items = array();

  $items['scholar-feature-events'] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'events',
    'description' => '',
    'node' => array(
      '0' => 'event',
    ),
    'views' => array(
      '0' => 'scholar_events',
      '1' => 'scholar_events_upcoming',
    ),
    'menu' => 'calendar',
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
      'vsite_widgets_4' => array(
        'module' => 'vsite_widgets',
        'delta' => '2',
        'weight' => 21,
        'region' => 'right',
        'status' => '0',
        'label' => 'ShareThis Button - Allows you to share posts using popular online services',
        'type' => 'context_ui',
      ),
      'scholar_events_mini' => array(
        'module' => 'scholar_events',
        'delta' => 'mini',
        'weight' => 22,
        'region' => 'right',
        'status' => '0',
        'label' => 'Mini Calendar - A small calendar used to display your sites upcoming events',
        'type' => 'context_ui',
      ),
      'views_scholar_events_upcoming-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_events_upcoming-block_1',
        'weight' => 23,
        'region' => 'right',
        'status' => '0',
        'label' => 'Upcoming events',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function scholar_events_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'module' => 'features',
      'description' => t('A calendar event with start and optional end times.'),
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
function scholar_events_views_api() {
  return array(
    'api' => '2',
  );
}
