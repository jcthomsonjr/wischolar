<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_announcements_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'announcements',
    'description' => 'Announcements feature context',
    'node' => array(
      '0' => 'announcement',
    ),
    'views' => array(
      '0' => 'scholar_announcements',
    ),
    'menu' => 'announcements',
    'block' => array(
      'views_scholar_announcements-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_announcements-block_1',
        'weight' => -21,
        'region' => 'right',
        'status' => '0',
        'label' => 'Latest Announcements',
        'type' => 'context_ui',
      ),
      'vsite_taxonomy_0' => array(
        'module' => 'vsite_taxonomy',
        'delta' => '0',
        'weight' => -20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Scholar site categories',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_announcements_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Announcements',
    'path' => 'announcements',
    'weight' => '0',
    'description' => 'List of announcements in my site',
  );
  // Translatables
  array(
    t('Announcements'),
    t('List of announcements in my site'),
  );


  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_announcements_user_default_permissions() {
  $permissions = array();

  // Exported permission: create announcement content
  $permissions[] = array(
    'name' => 'create announcement content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: delete own announcement content
  $permissions[] = array(
    'name' => 'delete own announcement content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: edit own announcement content
  $permissions[] = array(
    'name' => 'edit own announcement content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override announcement promote to front page option
  $permissions[] = array(
    'name' => 'override announcement promote to front page option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override announcement published option
  $permissions[] = array(
    'name' => 'override announcement published option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override announcement revision option
  $permissions[] = array(
    'name' => 'override announcement revision option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override announcement sticky option
  $permissions[] = array(
    'name' => 'override announcement sticky option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  return $permissions;
}
