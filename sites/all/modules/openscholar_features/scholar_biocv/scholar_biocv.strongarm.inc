<?php

/**
 * Implementation of hook_strongarm().
 */
function scholar_biocv_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_bio';
  $strongarm->value = 0;

  $export['comment_bio'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_cv';
  $strongarm->value = 0;

  $export['comment_cv'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_bio';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-1',
    'revision_information' => '3',
    'author' => '2',
    'options' => '4',
    'comment_settings' => '7',
    'menu' => '-2',
    'taxonomy' => '-3',
    'book' => '1',
    'path' => '6',
    'attachments' => '5',
    'og_nodeapi' => '0',
  );

  $export['content_extra_weights_bio'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_cv';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-1',
    'revision_information' => '2',
    'author' => '3',
    'options' => '4',
    'comment_settings' => '6',
    'menu' => '-2',
    'taxonomy' => '-3',
    'book' => '1',
    'path' => '5',
    'og_nodeapi' => '0',
  );

  $export['content_extra_weights_cv'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_bio';
  $strongarm->value = array(
    'weight' => 0,
    'user_display' => 0,
    'edit_link' => 0,
    'edit_tab' => '0',
    'add_link' => 0,
    'registration_use' => 0,
    'admin_user_create_use' => 0,
    'registration_hide' => array(
      0 => 'other',
    ),
  );

  $export['content_profile_bio'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_cv';
  $strongarm->value = array(
    'weight' => 0,
    'user_display' => 0,
    'edit_link' => 0,
    'edit_tab' => '0',
    'add_link' => 0,
    'registration_use' => 0,
    'admin_user_create_use' => 0,
    'registration_hide' => array(
      0 => 'other',
    ),
  );

  $export['content_profile_cv'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_bio';
  $strongarm->value = 1;

  $export['content_profile_use_bio'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_cv';
  $strongarm->value = 1;

  $export['content_profile_use_cv'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_bio';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );

  $export['node_options_bio'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cv';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_cv'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_bio';
  $strongarm->value = TRUE;

  $export['show_diff_inline_bio'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_cv';
  $strongarm->value = TRUE;

  $export['show_diff_inline_cv'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_bio';
  $strongarm->value = TRUE;

  $export['show_preview_changes_bio'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_cv';
  $strongarm->value = TRUE;

  $export['show_preview_changes_cv'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_bio';
  $strongarm->value = TRUE;

  $export['upload_bio'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_cv';
  $strongarm->value = FALSE;

  $export['upload_cv'] = $strongarm;
  return $export;
}
