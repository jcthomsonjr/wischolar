<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _vsite_support_content_default_fields() {
  $fields = array();

  // Exported field: field_support_question_ref
  $fields[] = array(
    'field_name' => 'field_support_question_ref',
    'type_name' => 'support_answer',
    'display_settings' => array(
      'weight' => '31',
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
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'support_question' => 'support_question',
      'announcement' => 0,
      'support_answer' => 0,
      'biblio' => 0,
      'blog' => 0,
      'scholar_class' => 0,
      'feature_request' => 0,
      'feed' => 0,
      'feed_item' => 0,
      'gallery' => 0,
      'image' => 0,
      'link' => 0,
      'page' => 0,
      'profile' => 0,
      'vsite' => 0,
      'scholar_software' => 0,
      'vsite_users_profile' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 1,
        'full' => 1,
        'title' => 'Answer',
        'hover_title' => 'Answer this question',
        'destination' => 'node',
      ),
      'fallback' => 'page_not_found',
      'label' => 'Question',
      'weight' => '31',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Translatables
  array(
    t('Question'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _vsite_support_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'cp',
    'attribute' => 'feature',
    'value' => 'support',
    'description' => '',
    'node' => array(
      '0' => 'feature_request',
      '1' => 'support_question',
    ),
    'path' => array(
      'cp/support/*' => 'cp/support/*',
    ),
    'views' => array(
      '0' => 'vsite_support',
      '1' => 'vsite_support:page_1',
      '2' => 'vsite_support:page_2',
    ),
    'block' => array(
      'views_2a17815f62da05b62035d31b9de3c969' => array(
        'module' => 'views',
        'delta' => '2a17815f62da05b62035d31b9de3c969',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Feature Requests: Moste voted',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_flag_default_flags().
 */
function _vsite_support_flag_default_flags() {
$flags = array();
// Exported flag: "Flag question, answers and support requests".
$flags[] = array (
  'content_type' => 'node',
  'name' => 'vsite_support',
  'title' => 'Flag question, answers and support requests',
  'global' => '1',
  'types' => 
  array (
    0 => 'support_answer',
    1 => 'feature_request',
    2 => 'support_question',
  ),
  'flag_short' => 'like it',
  'flag_long' => 'like it',
  'flag_message' => 'Your vote is registered ',
  'unflag_short' => 'undo',
  'unflag_long' => '',
  'unflag_message' => 'your vote is canceled',
  'unflag_denied_text' => '',
  'link_type' => 'toggle',
  'roles' => 
  array (
    'flag' => 
    array (
      0 => 2,
    ),
    'unflag' => 
    array (
      0 => 2,
    ),
  ),
  'show_on_page' => 1,
  'show_on_teaser' => 1,
  'show_on_form' => 0,
  'access_author' => '',
  'i18n' => 0,
  'module' => 'vsite_support',
  'api_version' => 2,
);
return $flags;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _vsite_support_user_default_permissions() {
  $permissions = array();

  // Exported permission: create feature_request content
  $permissions[] = array(
    'name' => 'create feature_request content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'scholar admin',
    ),
  );

  // Exported permission: create support_answer content
  $permissions[] = array(
    'name' => 'create support_answer content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'scholar admin',
    ),
  );

  // Exported permission: create support_question content
  $permissions[] = array(
    'name' => 'create support_question content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'scholar admin',
    ),
  );

  return $permissions;
}
