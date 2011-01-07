<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_classes_context_default_contexts() {
  $items = array();

  $items['scholar-feature-classes'] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'classes',
    'description' => '',
    'node' => array(
      '0' => 'class',
      '1' => 'class_material',
    ),
    'views' => array(
      '0' => 'scholar_classes',
    ),
    'menu' => 'classes',
    'block' => array(
      'vsite_widgets_4' => array(
        'module' => 'vsite_widgets',
        'delta' => '2',
        'weight' => 37,
        'region' => 'right',
        'status' => '0',
        'label' => 'ShareThis Button - Allows you to share posts using popular online services',
        'type' => 'context_ui',
      ),
      'scholar_book_booktoc' => array(
        'module' => 'scholar_book',
        'delta' => 'booktoc',
        'weight' => 38,
        'region' => 'right',
        'status' => '0',
        'label' => 'Scholar: Book',
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
    ),
  );
  return $items;
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function scholar_classes_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function scholar_classes_node_info() {
  $items = array(
    'class' => array(
      'name' => t('Class'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'class_material' => array(
      'name' => t('Class Material'),
      'module' => 'features',
      'description' => t('A post related to a class'),
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
function scholar_classes_views_api() {
  return array(
    'api' => '2',
  );
}
