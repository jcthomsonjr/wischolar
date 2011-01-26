<?php

/**
 * Implementation of hook_strongarm().
 */
function scholar_blog_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_blog';
  $strongarm->value = 1;

  $export['comment_anonymous_blog'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_blog';
  $strongarm->value = 2;

  $export['comment_blog'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_blog';
  $strongarm->value = 3;

  $export['comment_controls_blog'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_blog';
  $strongarm->value = 4;

  $export['comment_default_mode_blog'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_blog';
  $strongarm->value = 2;

  $export['comment_default_order_blog'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_blog';
  $strongarm->value = 10;

  $export['comment_default_per_page_blog'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_blog';
  $strongarm->value = 1;

  $export['comment_form_location_blog'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_blog';
  $strongarm->value = 0;

  $export['comment_preview_blog'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_blog';
  $strongarm->value = 1;

  $export['comment_subject_field_blog'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_blog';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );

  $export['node_options_blog'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_info_blog';
  $strongarm->value = TRUE;

  $export['node_submitted_info_blog'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_blog_pattern';
  $strongarm->value = '[space-og-path]/blog/[yyyy]/[mm]/[title-raw]';

  $export['pathauto_node_blog_pattern'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_blog';
  $strongarm->value = FALSE;

  $export['show_diff_inline_blog'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_blog';
  $strongarm->value = TRUE;

  $export['show_preview_changes_blog'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_blog';
  $strongarm->value = TRUE;

  $export['upload_blog'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_blog_default';
  $strongarm->value = unserialize('a:13:{s:5:"title";a:4:{s:6:"region";s:4:"main";s:6:"weight";s:1:"0";s:12:"has_required";b:1;s:5:"title";s:5:"Title";}s:10:"body_field";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"1";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"menu";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"1";s:12:"has_required";b:0;s:5:"title";s:13:"Menu settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:20:"revision_information";a:3:{s:6:"region";s:5:"right";s:6:"weight";s:1:"2";s:6:"hidden";i:0;}s:16:"comment_settings";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"7";s:12:"has_required";b:0;s:5:"title";s:16:"Comment settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:4:"path";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"6";s:12:"has_required";b:0;s:5:"title";s:17:"URL path settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:7:"options";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"4";s:12:"has_required";b:0;s:5:"title";s:18:"Publishing options";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:6:"author";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"3";s:12:"has_required";b:0;s:5:"title";s:21:"Authoring information";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:7:"buttons";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"4";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"book";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"5";s:12:"has_required";b:0;s:5:"title";s:12:"Book outline";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:8:"taxonomy";a:5:{s:6:"region";s:5:"right";s:6:"weight";s:1:"0";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:11:"attachments";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"3";s:12:"has_required";b:0;s:5:"title";s:31:"Attach files to this blog entry";s:6:"hidden";i:0;}s:10:"og_nodeapi";a:6:{s:6:"region";s:4:"main";s:6:"weight";s:1:"2";s:12:"has_required";b:0;s:5:"title";s:9:"Web Sites";s:9:"collapsed";i:0;s:6:"hidden";i:0;}}');

  $export['nodeformscols_field_placements_blog_default'] = $strongarm;
  return $export;
}
