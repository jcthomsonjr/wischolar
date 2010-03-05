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
      'vsite_widgets_2' => array(
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

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_book_user_default_permissions() {
  $permissions = array();

  // Exported permission: add content to books
  $permissions[] = array(
    'name' => 'add content to books',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: create book content
  $permissions[] = array(
    'name' => 'create book content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: create new books
  $permissions[] = array(
    'name' => 'create new books',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: delete own book content
  $permissions[] = array(
    'name' => 'delete own book content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: edit own book content
  $permissions[] = array(
    'name' => 'edit own book content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override book promote to front page option
  $permissions[] = array(
    'name' => 'override book promote to front page option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override book published option
  $permissions[] = array(
    'name' => 'override book published option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override book revision option
  $permissions[] = array(
    'name' => 'override book revision option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override book sticky option
  $permissions[] = array(
    'name' => 'override book sticky option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  return $permissions;
}
