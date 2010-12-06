<?php

/**
 * Implementation of hook_content_default_fields().
 */
function scholar_publications_content_default_fields() {
  $fields = array();

  // Exported field: field_biblio_extra
  $fields['biblio-field_biblio_extra'] = array(
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
  $fields['biblio-field_biblio_image'] = array(
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
  // Included for use with string extractors like potx.
  t('Book Cover');
  t('Extra Fields');

  return $fields;
}
