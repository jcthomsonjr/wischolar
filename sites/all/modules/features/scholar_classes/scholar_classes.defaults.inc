<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_classes_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'classes',
    'description' => '',
    'node' => array(
      '0' => 'class',
    ),
    'views' => array(
      '0' => 'scholar_classes',
    ),
    'menu' => 'classes',
  );
  return $items;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_classes_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Classes',
    'path' => 'classes',
    'weight' => '0',
    'description' => 'My classes',
  );
  // Translatables
  array(
    t('Classes'),
    t('My classes'),
  );


  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_classes_user_default_permissions() {
  $permissions = array();

  // Exported permission: create class content
  $permissions[] = array(
    'name' => 'create class content',
    'roles' => array(),
  );

  // Exported permission: delete own class content
  $permissions[] = array(
    'name' => 'delete own class content',
    'roles' => array(),
  );

  // Exported permission: edit own class content
  $permissions[] = array(
    'name' => 'edit own class content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  return $permissions;
}
