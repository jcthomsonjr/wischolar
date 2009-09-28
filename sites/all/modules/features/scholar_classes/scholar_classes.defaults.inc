<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _scholar_classes_content_default_fields() {
  $fields = array();

  // Exported field: field_class_semester
  $fields[] = array(
    'field_name' => 'field_class_semester',
    'type_name' => 'class',
    'display_settings' => array(
      'weight' => '32',
      'parent' => '',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'Fall
Spring
Summer',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Semester',
      'weight' => '4',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_class_year
  $fields[] = array(
    'field_name' => 'field_class_year',
    'type_name' => 'class',
    'display_settings' => array(
      'weight' => '31',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
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
    'type' => 'date',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'now',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'm/d/Y - H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Year',
      'weight' => '5',
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Translatables
  array(
    t('Semester'),
    t('Year'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_classes_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'classes',
    'description' => '',
    'node' => array(
      '0' => 'class',
    ),
    'views' => array(
      '0' => 'scholar_classes',
    ),
    'menu' => 'classes',
  );
  return $items;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _scholar_classes_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Classes',
    'path' => 'classes',
    'weight' => '0',
    'description' => 'My classes',
  );
  // Translatables
  array(
    t('Classes'),
    t('My classes'),
  );


  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_classes_user_default_permissions() {
  $permissions = array();

  // Exported permission: create class content
  $permissions[] = array(
    'name' => 'create class content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: delete own class content
  $permissions[] = array(
    'name' => 'delete own class content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: edit own class content
  $permissions[] = array(
    'name' => 'edit own class content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  return $permissions;
}
