<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_book_context_default_contexts() {
  $items = array();

  $items[] = array(
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
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_book_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Documents',
    'path' => 'documents',
    'weight' => '0',
    'description' => 'list of documents',
  );
  // Translatables
  array(
    t('Documents'),
    t('list of documents'),
  );


  return $items;
}
