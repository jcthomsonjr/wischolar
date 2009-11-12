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
      'weight' => '31',
      'description' => '',
      'type' => 'dyntextfield_widget',
      'module' => 'dyntextfield',
    ),
  );

  // Translatables
  array(
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
    'description' => '',
    'node' => array(
      '0' => 'biblio',
    ),
    'path' => array(
      'publications' => 'publications',
    ),
    'menu' => 'publications',
    'block' => array(
      'views_scholar_publications-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_publications-block_1',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Recent publications',
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
      '0' => 'scholar admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
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
    ),
  );

  // Exported permission: override biblio published option
  $permissions[] = array(
    'name' => 'override biblio published option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override biblio revision option
  $permissions[] = array(
    'name' => 'override biblio revision option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override biblio sticky option
  $permissions[] = array(
    'name' => 'override biblio sticky option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: show download links
  $permissions[] = array(
    'name' => 'show download links',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: show export links
  $permissions[] = array(
    'name' => 'show export links',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: show filter tab
  $permissions[] = array(
    'name' => 'show filter tab',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: show own download links
  $permissions[] = array(
    'name' => 'show own download links',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: show sort links
  $permissions[] = array(
    'name' => 'show sort links',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: submit repec widget
  $permissions[] = array(
    'name' => 'submit repec widget',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: view full text
  $permissions[] = array(
    'name' => 'view full text',
    'roles' => array(
      '0' => 'scholar admin',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'scholar user',
    ),
  );

  return $permissions;
}
