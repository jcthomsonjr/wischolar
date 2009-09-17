<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_biocv_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'biocv',
    'description' => 'scholar > bio / cv',
    'path' => array(
      'bio' => 'bio',
    ),
    'menu' => 'bio',
    'block' => array(
      'biblio_0' => array(
        'module' => 'biblio',
        'delta' => '0',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Most recent publications',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_biocv_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Bio',
    'path' => 'bio',
    'weight' => '0',
  );
  // Translatables
  array(
    t('Bio'),
  );


  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_biocv_user_default_permissions() {
  $permissions = array();

  // Exported permission: create bio content
  $permissions[] = array(
    'name' => 'create bio content',
    'roles' => array(),
  );

  // Exported permission: create cv content
  $permissions[] = array(
    'name' => 'create cv content',
    'roles' => array(),
  );

  // Exported permission: delete own bio content
  $permissions[] = array(
    'name' => 'delete own bio content',
    'roles' => array(),
  );

  // Exported permission: delete own cv content
  $permissions[] = array(
    'name' => 'delete own cv content',
    'roles' => array(),
  );

  // Exported permission: edit own bio content
  $permissions[] = array(
    'name' => 'edit own bio content',
    'roles' => array(),
  );

  // Exported permission: edit own cv content
  $permissions[] = array(
    'name' => 'edit own cv content',
    'roles' => array(),
  );

  return $permissions;
}
