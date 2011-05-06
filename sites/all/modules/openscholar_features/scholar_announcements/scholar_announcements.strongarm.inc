<?php

/**
 * Implementation of hook_strongarm().
 */
function scholar_announcements_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_announcement';
  $strongarm->value = 0;

  $export['comment_announcement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_announcement';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-1',
    'revision_information' => '3',
    'author' => '2',
    'options' => '4',
    'comment_settings' => '7',
    'menu' => '-3',
    'taxonomy' => '-4',
    'book' => '1',
    'path' => '5',
    'attachments' => '6',
    'creativecommons' => '8',
    'og_nodeapi' => '-2',
  );

  $export['content_extra_weights_announcement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_announcement';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );

  $export['node_options_announcement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_info_announcement';
  $strongarm->value = TRUE;

  $export['node_submitted_info_announcement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_announcement_default';
  $strongarm->value = array(
    'title' => array(
      'region' => 'main',
      'weight' => '0',
      'has_required' => TRUE,
      'title' => 'Title',
    ),
    'body_field' => array(
      'region' => 'main',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'menu' => array(
      'region' => 'right',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Menu settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'revision_information' => array(
      'region' => 'right',
      'weight' => '3',
      'hidden' => 0,
    ),
    'comment_settings' => array(
      'region' => 'right',
      'weight' => '7',
      'has_required' => FALSE,
      'title' => 'Comment settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'path' => array(
      'region' => 'right',
      'weight' => '6',
      'has_required' => FALSE,
      'title' => 'URL path settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'options' => array(
      'region' => 'right',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Publishing options',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'author' => array(
      'region' => 'right',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Authoring information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'buttons' => array(
      'region' => 'main',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'book' => array(
      'region' => 'right',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'Book outline',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'taxonomy' => array(
      'region' => 'right',
      'weight' => '0',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'attachments' => array(
      'region' => 'main',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => 'Attach files to this announcement',
      'hidden' => 0,
    ),
    'og_nodeapi' => array(
      'region' => 'main',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Web Sites',
      'collapsed' => 1,
      'hidden' => 0,
    ),
  );

  $export['nodeformscols_field_placements_announcement_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_announcement';
  $strongarm->value = 'group_post_standard';

  $export['og_content_type_usage_announcement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_announcement_pattern';
  $strongarm->value = '[space-og-path]/announcements/[title-raw]';

  $export['pathauto_node_announcement_pattern'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_announcement';
  $strongarm->value = FALSE;

  $export['show_diff_inline_announcement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_announcement';
  $strongarm->value = FALSE;

  $export['show_preview_changes_announcement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_announcement';
  $strongarm->value = TRUE;

  $export['upload_announcement'] = $strongarm;
  return $export;
}
