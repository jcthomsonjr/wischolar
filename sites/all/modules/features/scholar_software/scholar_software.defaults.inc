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
      '0' => 'project_project',
    ),
    'views' => array(
      '0' => 'scholar_software',
    ),
    'menu' => 'software',
    'block' => array(
      'vsite_taxonomy_0' => array(
        'module' => 'vsite_taxonomy',
        'delta' => '0',
        'weight' => -20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Scholar site categories',
        'type' => 'context_ui',
      ),
      'vsite_widgets_4' => array(
        'module' => 'vsite_widgets',
        'delta' => '2',
        'weight' => 50,
        'region' => 'right',
        'status' => '0',
        'label' => 'AddThis button',
        'type' => 'context_ui',
      ),
    ),
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

  // Exported permission: access projects
  $permissions[] = array(
    'name' => 'access projects',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'scholar admin',
      '2' => 'scholar user',
    ),
  );

  // Exported permission: browse project listings
  $permissions[] = array(
    'name' => 'browse project listings',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'scholar admin',
      '2' => 'scholar user',
    ),
  );

  // Exported permission: delete own projects
  $permissions[] = array(
    'name' => 'delete own projects',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: maintain projects
  $permissions[] = array(
    'name' => 'maintain projects',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override project_project authored by option
  $permissions[] = array(
    'name' => 'override project_project authored by option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override project_project authored on option
  $permissions[] = array(
    'name' => 'override project_project authored on option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override project_project published option
  $permissions[] = array(
    'name' => 'override project_project published option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override project_project revision option
  $permissions[] = array(
    'name' => 'override project_project revision option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override project_project sticky option
  $permissions[] = array(
    'name' => 'override project_project sticky option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override project_release authored by option
  $permissions[] = array(
    'name' => 'override project_release authored by option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override project_release authored on option
  $permissions[] = array(
    'name' => 'override project_release authored on option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override project_release published option
  $permissions[] = array(
    'name' => 'override project_release published option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override project_release revision option
  $permissions[] = array(
    'name' => 'override project_release revision option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override project_release sticky option
  $permissions[] = array(
    'name' => 'override project_release sticky option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  return $permissions;
}
