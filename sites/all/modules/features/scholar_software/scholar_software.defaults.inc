<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_software_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'software',
    'description' => '',
    'node' => array(
      '0' => 'software',
    ),
    'views' => array(
      '0' => 'scholar_software',
    ),
    'menu' => 'software',
  );
  return $items;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_software_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Software',
    'path' => 'software',
    'weight' => '0',
    'description' => 'My software',
  );
  // Translatables
  array(
    t('My software'),
    t('Software'),
  );


  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_software_user_default_permissions() {
  $permissions = array();

  // Exported permission: create software content
  $permissions[] = array(
    'name' => 'create software content',
    'roles' => array(),
  );

  // Exported permission: delete own software content
  $permissions[] = array(
    'name' => 'delete own software content',
    'roles' => array(),
  );

  // Exported permission: edit own software content
  $permissions[] = array(
    'name' => 'edit own software content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  return $permissions;
}
