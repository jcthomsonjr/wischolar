<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_reader_context_default_contexts() {
  $items = array();

  $items['scholar-feature-reader'] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'reader',
    'description' => 'scholar > feed reader',
    'node' => array(
      '0' => 'feed',
    ),
    'menu_trail' => array(
      'reader' => 'reader',
    ),
    'views' => array(
      '0' => 'scholar_reader',
    ),
    'menu' => 'reader',
    'block' => array(
      'vsite_widgets_4' => array(
        'module' => 'vsite_widgets',
        'delta' => '2',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'AddThis button',
        'type' => 'context_ui',
      ),
      'vsite_taxonomy_0' => array(
        'module' => 'vsite_taxonomy',
        'delta' => '0',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Categories',
        'type' => 'context_ui',
      ),
      'views_scholar_reader-block_2' => array(
        'module' => 'views',
        'delta' => 'scholar_reader-block_2',
        'weight' => 21,
        'region' => 'right',
        'status' => '0',
        'label' => 'scholar_reader: Latest feed items',
        'type' => 'context_ui',
      ),
      'views_scholar_reader-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_reader-block_1',
        'weight' => 22,
        'region' => 'right',
        'status' => '0',
        'label' => 'scholar_reader: Feeds subscriptions',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function scholar_reader_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "data" && $api == "data_default") {
    return array("version" => 1);
  }
  elseif ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function scholar_reader_node_info() {
  $items = array(
    'feed' => array(
      'name' => t('Feed'),
      'module' => 'features',
      'description' => t('Items from these feeds will be turned into nodes.'),
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
function scholar_reader_views_api() {
  return array(
    'api' => '2',
  );
}
