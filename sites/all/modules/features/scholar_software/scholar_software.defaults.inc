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

  // Exported permission: create software content
  $permissions[] = array(
    'name' => 'create software content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: delete own software content
  $permissions[] = array(
    'name' => 'delete own software content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: edit own software content
  $permissions[] = array(
    'name' => 'edit own software content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override software promote to front page option
  $permissions[] = array(
    'name' => 'override software promote to front page option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override software published option
  $permissions[] = array(
    'name' => 'override software published option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override software revision option
  $permissions[] = array(
    'name' => 'override software revision option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override software sticky option
  $permissions[] = array(
    'name' => 'override software sticky option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  return $permissions;
}
