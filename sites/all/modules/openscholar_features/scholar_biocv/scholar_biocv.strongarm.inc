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
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_bio_default';
  $strongarm->value = unserialize('a:14:{s:5:"title";a:4:{s:6:"region";s:4:"main";s:6:"weight";s:1:"0";s:12:"has_required";b:1;s:5:"title";s:5:"Title";}s:10:"body_field";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"3";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"menu";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"2";s:12:"has_required";b:0;s:5:"title";s:13:"Menu settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:20:"revision_information";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"4";s:12:"has_required";b:0;s:5:"title";s:20:"Revision information";s:9:"collapsed";i:0;s:6:"hidden";i:0;}s:16:"comment_settings";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"7";s:12:"has_required";b:0;s:5:"title";s:16:"Comment settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:4:"path";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"6";s:12:"has_required";b:0;s:5:"title";s:17:"URL path settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:7:"options";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"5";s:12:"has_required";b:0;s:5:"title";s:18:"Publishing options";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:6:"author";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"3";s:12:"has_required";b:0;s:5:"title";s:21:"Authoring information";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:7:"buttons";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"5";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"book";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"1";s:12:"has_required";b:0;s:5:"title";s:12:"Book outline";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:8:"taxonomy";a:5:{s:6:"region";s:5:"right";s:6:"weight";s:1:"0";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:11:"attachments";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"4";s:12:"has_required";b:0;s:5:"title";s:24:"Attach files to this bio";s:6:"hidden";i:0;}s:15:"field_hook_text";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"1";s:12:"has_required";b:0;s:5:"title";s:11:"Short Blurb";s:6:"hidden";i:0;}s:10:"og_nodeapi";a:6:{s:6:"region";s:4:"main";s:6:"weight";s:1:"2";s:12:"has_required";b:0;s:5:"title";s:9:"Web Sites";s:9:"collapsed";i:0;s:6:"hidden";i:0;}}');

  $export['nodeformscols_field_placements_bio_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_cv_default';
  $strongarm->value = unserialize('a:15:{s:5:"title";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"1";s:12:"has_required";b:0;s:5:"title";s:5:"Title";s:6:"hidden";i:0;}s:10:"body_field";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"3";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"menu";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"2";s:12:"has_required";b:0;s:5:"title";s:13:"Menu settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:16:"comment_settings";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"5";s:12:"has_required";b:0;s:5:"title";s:16:"Comment settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:4:"path";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"6";s:12:"has_required";b:0;s:5:"title";s:17:"URL path settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:7:"options";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"4";s:12:"has_required";b:0;s:5:"title";s:18:"Publishing options";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:6:"author";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"3";s:12:"has_required";b:0;s:5:"title";s:21:"Authoring information";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:7:"buttons";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"7";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"book";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"1";s:12:"has_required";b:0;s:5:"title";s:12:"Book outline";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:8:"taxonomy";a:5:{s:6:"region";s:5:"right";s:6:"weight";s:1:"0";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:15:"field_cv_attach";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"4";s:12:"has_required";b:0;s:5:"title";s:10:"PDF Upload";s:6:"hidden";i:0;}s:10:"og_nodeapi";a:6:{s:6:"region";s:4:"main";s:6:"weight";s:1:"2";s:12:"has_required";b:0;s:5:"title";s:9:"Web Sites";s:9:"collapsed";i:0;s:6:"hidden";i:0;}s:18:"iqss_remote_source";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"5";s:12:"has_required";b:0;s:5:"title";s:22:"Remote Source Settings";s:6:"hidden";i:0;}s:13:"use_pdf_as_cv";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"0";s:12:"has_required";b:0;s:5:"title";s:25:"Use PDF upload as your CV";s:6:"hidden";i:0;}s:11:"attachments";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"6";s:12:"has_required";b:0;s:5:"title";s:23:"Attach files to this cv";s:6:"hidden";i:0;}}');

  $export['nodeformscols_field_placements_cv_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_bio';
  $strongarm->value = 'group_post_standard';

  $export['og_content_type_usage_bio'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_cv';
  $strongarm->value = 'group_post_standard';

  $export['og_content_type_usage_cv'] = $strongarm;
  return $export;
}
