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
      'biblio' => 0,
      'blog' => 0,
      'scholar_class' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'image' => 0,
      'link' => 0,
      'scholarsite' => 0,
      'scholar_software' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 0,
        'full' => 1,
        'title' => 'Add photo',
        'hover_title' => 'Add a new photo to this gallery',
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
      'file_path' => 'photos',
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
      '0' => 'gallery',
    ),
    'block' => array(
      'views_gallery-block_1' => array(
        'module' => 'views',
        'delta' => 'gallery-block_1',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'gallery: Latest image',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}
