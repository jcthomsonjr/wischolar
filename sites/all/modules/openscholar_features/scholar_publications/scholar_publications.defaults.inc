<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _scholar_publications_content_default_fields() {
  $fields = array();

  // Exported field: field_biblio_extra
  $fields[] = array(
    'field_name' => 'field_biblio_extra',
    'type_name' => 'biblio',
    'display_settings' => array(
      'weight' => '31',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'dyntextfield',
    'required' => '0',
    'multiple' => '1',
    'module' => 'dyntextfield',
    'active' => '1',
    'max_length' => '255',
    'widget' => array(
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'dyntext_fieldset' => array(
            'label' => '',
            'value' => '',
          ),
          '_error_element' => 'value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Extra Fields',
      'weight' => '5',
      'description' => '',
      'type' => 'dyntextfield_widget',
      'module' => 'dyntextfield',
    ),
  );

  // Exported field: field_biblio_image
  $fields[] = array(
    'field_name' => 'field_biblio_image',
    'type_name' => 'biblio',
    'display_settings' => array(
      'weight' => '32',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'book_cover_linked',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'book_cover_default',
        'exclude' => 1,
      ),
      '5' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Book Cover',
      'weight' => '8',
      'description' => 'Upload your book cover image.',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Translatables
  array(
    t('Book Cover'),
    t('Extra Fields'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_publications_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'publications',
    'node' => array(
      '0' => 'biblio',
    ),
    'path' => array(
      'publications' => 'publications',
      'publications/*' => 'publications/*',
    ),
    'menu' => 'publications',
    'block' => array(
      'vsite_taxonomy_0' => array(
        'module' => 'vsite_taxonomy',
        'delta' => '0',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Categories - A widget used to quickly filter categorized content',
        'type' => 'context_ui',
      ),
      'views_scholar_publications-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_publications-block_1',
        'weight' => 21,
        'region' => 'right',
        'status' => '0',
        'label' => 'Recent publications',
        'type' => 'context_ui',
      ),
      'vsite_widgets_2' => array(
        'module' => 'vsite_widgets',
        'delta' => '2',
        'weight' => 22,
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
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _scholar_publications_imagecache_default_presets() {
  $items = array(
    'book_cover' => array(
      'presetname' => 'book_cover',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '100',
            'height' => '100%',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'book_cover_thumb' => array(
      'presetname' => 'book_cover_thumb',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '40',
            'height' => '100%',
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
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
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

  // Exported permission: override biblio promote to front page option
  $permissions[] = array(
    'name' => 'override biblio promote to front page option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override biblio published option
  $permissions[] = array(
    'name' => 'override biblio published option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override biblio revision option
  $permissions[] = array(
    'name' => 'override biblio revision option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override biblio sticky option
  $permissions[] = array(
    'name' => 'override biblio sticky option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: show download links
  $permissions[] = array(
    'name' => 'show download links',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: show export links
  $permissions[] = array(
    'name' => 'show export links',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: show filter tab
  $permissions[] = array(
    'name' => 'show filter tab',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: show own download links
  $permissions[] = array(
    'name' => 'show own download links',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: show sort links
  $permissions[] = array(
    'name' => 'show sort links',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: submit repec widget
  $permissions[] = array(
    'name' => 'submit repec widget',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: view full text
  $permissions[] = array(
    'name' => 'view full text',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  return $permissions;
}
