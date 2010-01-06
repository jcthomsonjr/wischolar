<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _scholar_links_content_default_fields() {
  $fields = array();

  // Exported field: field_link_href
  $fields[] = array(
    'field_name' => 'field_link_href',
    'type_name' => 'link',
    'display_settings' => array(
      'weight' => '1',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '1',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'none',
    'title_value' => '',
    'enable_tokens' => 0,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'title' => '',
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'href',
      'weight' => '1',
      'description' => '',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Translatables
  array(
    t('href'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_links_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'links',
    'description' => 'Links feature context',
    'node' => array(
      '0' => 'link',
    ),
    'views' => array(
      '0' => 'scholar_links',
    ),
    'menu' => 'links',
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
        'delta' => '4',
        'weight' => 50,
        'region' => 'left',
        'status' => '0',
        'label' => 'AddThis button',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _scholar_links_imagecache_default_presets() {
  $items = array(
    'image_s' => array(
      'presetname' => 'image_s',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '90',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_links_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Links',
    'path' => 'links',
    'weight' => '0',
    'description' => 'List of links in my site',
  );
  // Translatables
  array(
    t('Links'),
    t('List of links in my site'),
  );


  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_links_user_default_permissions() {
  $permissions = array();

  // Exported permission: create link content
  $permissions[] = array(
    'name' => 'create link content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: delete own link content
  $permissions[] = array(
    'name' => 'delete own link content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: edit own link content
  $permissions[] = array(
    'name' => 'edit own link content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  return $permissions;
}
