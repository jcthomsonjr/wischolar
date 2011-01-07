<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_book_context_default_contexts() {
  $items = array();

  $items['scholar-feature-book'] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'book',
    'description' => 'scholar > book',
    'node' => array(
      '0' => 'book',
    ),
    'views' => array(
      '0' => 'scholar_books',
    ),
    'menu' => 'documents',
    'block' => array(
      'scholar_book_booktoc' => array(
        'module' => 'scholar_book',
        'delta' => 'booktoc',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Scholar: Book',
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
    ),
  );
  return $items;
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function scholar_book_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function scholar_book_node_info() {
  $items = array(
    'book' => array(
      'name' => t('Book page'),
      'module' => 'features',
      'description' => t('A <em>book page</em> is a page of content, organized into a collection of related entries collectively known as a <em>book</em>. A <em>book page</em> automatically displays links to adjacent pages, providing a simple navigation system for organizing and reviewing structured content.'),
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
function scholar_book_views_api() {
  return array(
    'api' => '2',
  );
}
