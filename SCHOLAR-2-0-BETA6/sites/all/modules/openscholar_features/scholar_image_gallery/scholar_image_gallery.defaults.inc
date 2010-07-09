<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _scholar_image_gallery_content_default_fields() {
  $fields = array();

  // Exported field: field_gallery
  $fields[] = array(
    'field_name' => 'field_gallery',
    'type_name' => 'image',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => '',
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'gallery' => 'gallery',
      'announcement' => 0,
      'support_answer' => 0,
      'blog' => 0,
      'book' => 0,
      'class' => 0,
      'class_material' => 0,
      'event' => 0,
      'feature_request' => 0,
      'feed' => 0,
      'image' => 0,
      'link' => 0,
      'page' => 0,
      'profile' => 0,
      'biblio' => 0,
      'support_question' => 0,
      'vsite' => 0,
      'scholar_software_project' => 0,
      'scholar_software_release' => 0,
      'vsite_users_profile' => 0,
      'bio' => 0,
      'cv' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 1,
        'full' => 1,
        'title' => 'Add image',
        'hover_title' => 'Add a new image to this gallery',
        'destination' => 'node',
      ),
      'fallback' => 'select',
      'label' => 'Gallery',
      'weight' => '-3',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_gallery_image
  $fields[] = array(
    'field_name' => 'field_gallery_image',
    'type_name' => 'image',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'thumb_linked',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'reg_linked',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'reg_linked',
      ),
      '2' => array(
        'format' => 'reg_linked',
      ),
      '3' => array(
        'format' => 'reg_linked',
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'jpg jpeg png gif',
      'file_path' => 'images',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '2M',
      'max_filesize_per_node' => '',
      'max_resolution' => '640x400',
      'min_resolution' => 0,
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Image',
      'weight' => '-4',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Translatables
  array(
    t('Gallery'),
    t('Image'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_image_gallery_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'image_gallery',
    'description' => 'scholar > image gallery',
    'node' => array(
      '0' => 'gallery',
      '1' => 'image',
    ),
    'views' => array(
      '0' => 'scholar_image_gallery',
    ),
    'menu' => 'photos',
    'block' => array(
      'views_scholar_image_gallery-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_image_gallery-block_1',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Recent images',
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
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _scholar_image_gallery_imagecache_default_presets() {
  $items = array(
    'gallery_small_thumb' => array(
      'presetname' => 'gallery_small_thumb',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '100%',
            'height' => '85',
            'upscale' => 0,
          ),
        ),
        '1' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '71',
            'height' => '71',
          ),
        ),
      ),
    ),
    'gallery_thumb' => array(
      'presetname' => 'gallery_thumb',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '100%',
            'height' => '133',
            'upscale' => 0,
          ),
        ),
        '1' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '113',
            'height' => '113',
          ),
        ),
      ),
    ),
    'reg' => array(),
    'thumb' => array(
      'presetname' => 'thumb',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_deprecated_scale',
          'data' => array(
            'fit' => 'outside',
            'width' => '200',
            'height' => '150',
          ),
        ),
        '1' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_crop',
          'data' => array(
            'width' => '200',
            'height' => '150',
            'xoffset' => 'center',
            'yoffset' => 'center',
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
function _scholar_image_gallery_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Images',
    'path' => 'images',
    'weight' => '0',
    'description' => 'my images',
  );
  // Translatables
  array(
    t('Images'),
    t('my images'),
  );


  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_image_gallery_user_default_permissions() {
  $permissions = array();

  // Exported permission: create gallery content
  $permissions[] = array(
    'name' => 'create gallery content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: create image content
  $permissions[] = array(
    'name' => 'create image content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: delete own gallery content
  $permissions[] = array(
    'name' => 'delete own gallery content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: delete own image content
  $permissions[] = array(
    'name' => 'delete own image content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: edit own gallery content
  $permissions[] = array(
    'name' => 'edit own gallery content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: edit own image content
  $permissions[] = array(
    'name' => 'edit own image content',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override gallery promote to front page option
  $permissions[] = array(
    'name' => 'override gallery promote to front page option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  // Exported permission: override gallery sticky option
  $permissions[] = array(
    'name' => 'override gallery sticky option',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'scholar user',
    ),
  );

  return $permissions;
}
