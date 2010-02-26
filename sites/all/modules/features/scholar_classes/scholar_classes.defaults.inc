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
      'weight' => '4',
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
      'weight' => '5',
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
      'label' => 'Offered',
      'weight' => '5',
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_class
  $fields[] = array(
    'field_name' => 'field_class',
    'type_name' => 'class_material',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'class' => 'class',
      'announcement' => 0,
      'support_answer' => 0,
      'blog' => 0,
      'book' => 0,
      'class_material' => 0,
      'event' => 0,
      'feature_request' => 0,
      'feed' => 0,
      'gallery' => 0,
      'image' => 0,
      'link' => 0,
      'page' => 0,
      'person' => 0,
      'profile' => 0,
      'biblio' => 0,
      'support_question' => 0,
      'vsite' => 0,
      'vsite_users_profile' => 0,
      'bio' => 0,
      'cv' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 0,
        'full' => 1,
        'title' => 'class material',
        'hover_title' => 'Add a post related to this class',
        'destination' => 'node',
      ),
      'fallback' => 'page_not_found',
      'label' => 'Class',
      'weight' => '31',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Translatables
  array(
    t('Class'),
    t('Offered'),
    t('Semester'),
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
      '1' => 'class_material',
    ),
    'views' => array(
      '0' => 'scholar_classes',
    ),
    'menu' => 'classes',
    'block' => array(
      'vsite_taxonomy_0' => array(
        'module' => 'vsite_taxonomy',
        'delta' => '0',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Categories',
        'type' => 'context_ui',
      ),
    ),
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

  // Exported permission: create class_material content
  $permissions[] = array(
    'name' => 'create class_material content',
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

  // Exported permission: delete own class_material content
  $permissions[] = array(
    'name' => 'delete own class_material content',
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

  // Exported permission: edit own class_material content
  $permissions[] = array(
    'name' => 'edit own class_material content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override class promote to front page option
  $permissions[] = array(
    'name' => 'override class promote to front page option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override class published option
  $permissions[] = array(
    'name' => 'override class published option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override class revision option
  $permissions[] = array(
    'name' => 'override class revision option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override class sticky option
  $permissions[] = array(
    'name' => 'override class sticky option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override class_material promote to front page option
  $permissions[] = array(
    'name' => 'override class_material promote to front page option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override class_material published option
  $permissions[] = array(
    'name' => 'override class_material published option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override class_material revision option
  $permissions[] = array(
    'name' => 'override class_material revision option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override class_material sticky option
  $permissions[] = array(
    'name' => 'override class_material sticky option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  return $permissions;
}
