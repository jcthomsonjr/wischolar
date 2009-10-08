<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_blog_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'blog',
    'description' => '',
    'node' => array(
      '0' => 'blog',
    ),
    'views' => array(
      '0' => 'scholar_blog',
    ),
    'menu' => 'blog',
    'block' => array(
      'views_scholar_blog_comments-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_blog_comments-block_1',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'scholar_blog_comments: Recent comments',
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
function _scholar_blog_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Blog',
    'path' => 'blog',
    'weight' => '0',
    'description' => 'A simple blog.',
  );
  // Translatables
  array(
    t('A simple blog.'),
    t('Blog'),
  );


  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_blog_user_default_permissions() {
  $permissions = array();

  // Exported permission: create blog entries
  $permissions[] = array(
    'name' => 'create blog entries',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: delete own blog entries
  $permissions[] = array(
    'name' => 'delete own blog entries',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override blog promote to front page option
  $permissions[] = array(
    'name' => 'override blog promote to front page option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override blog published option
  $permissions[] = array(
    'name' => 'override blog published option',
    'roles' => array(),
  );

  // Exported permission: override blog revision option
  $permissions[] = array(
    'name' => 'override blog revision option',
    'roles' => array(),
  );

  // Exported permission: override blog sticky option
  $permissions[] = array(
    'name' => 'override blog sticky option',
    'roles' => array(),
  );

  return $permissions;
}
