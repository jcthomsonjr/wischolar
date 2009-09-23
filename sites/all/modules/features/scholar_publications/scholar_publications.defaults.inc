<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_publications_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'publication',
    'description' => '',
    'node' => array(
      '0' => 'biblio',
    ),
    'path' => array(
      'publications' => 'publications',
    ),
    'menu' => 'publications',
  );
  return $items;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_publications_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Publications',
    'path' => 'publications',
    'weight' => '0',
  );
  // Translatables
  array(
    t('Publications'),
  );


  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_publications_user_default_permissions() {
  $permissions = array();

  // Exported permission: access biblio content
  $permissions[] = array(
    'name' => 'access biblio content',
    'roles' => array(
      '0' => 'anonymous user',
    ),
  );

  // Exported permission: create biblio
  $permissions[] = array(
    'name' => 'create biblio',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: edit own biblio entries
  $permissions[] = array(
    'name' => 'edit own biblio entries',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: import from file
  $permissions[] = array(
    'name' => 'import from file',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: show download links
  $permissions[] = array(
    'name' => 'show download links',
    'roles' => array(
      '0' => 'anonymous user',
    ),
  );

  // Exported permission: show export links
  $permissions[] = array(
    'name' => 'show export links',
    'roles' => array(
      '0' => 'anonymous user',
    ),
  );

  // Exported permission: show filter tab
  $permissions[] = array(
    'name' => 'show filter tab',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: show own download links
  $permissions[] = array(
    'name' => 'show own download links',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: show sort links
  $permissions[] = array(
    'name' => 'show sort links',
    'roles' => array(
      '0' => 'anonymous user',
    ),
  );

  // Exported permission: view full text
  $permissions[] = array(
    'name' => 'view full text',
    'roles' => array(
      '0' => 'anonymous user',
    ),
  );

  return $permissions;
}
