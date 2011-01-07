<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_presentations_context_default_contexts() {
  $items = array();

  $items['scholar-feature-presentations'] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'presentations',
    'description' => 'Presentations feature context',
    'node' => array(
      '0' => 'presentation',
    ),
    'views' => array(
      '0' => 'scholar_presentations',
    ),
    'menu' => 'presentations',
    'block' => array(
      'views_scholar_presentations-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_presentations-block_1',
        'weight' => 38,
        'region' => 'right',
        'status' => '0',
        'label' => 'Recent Presentations',
        'type' => 'context_ui',
      ),
      'vsite_taxonomy_0' => array(
        'module' => 'vsite_taxonomy',
        'delta' => '0',
        'weight' => 39,
        'region' => 'right',
        'status' => '0',
        'label' => 'Categories - Filter categorized content',
        'type' => 'context_ui',
      ),
      'vsite_widgets_4' => array(
        'module' => 'vsite_widgets',
        'delta' => '2',
        'weight' => 40,
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
 * Implementation of hook_ctools_plugin_api().
 */
function scholar_presentations_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function scholar_presentations_node_info() {
  $items = array(
    'presentation' => array(
      'name' => t('Presentation'),
      'module' => 'features',
      'description' => t('A presentation event.'),
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
function scholar_presentations_views_api() {
  return array(
    'api' => '2',
  );
}
