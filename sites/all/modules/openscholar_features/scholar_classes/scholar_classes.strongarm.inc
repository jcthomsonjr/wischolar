<?php

/**
 * Implementation of hook_strongarm().
 */
function scholar_classes_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_class';
  $strongarm->value = 0;

  $export['comment_class'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_class_material';
  $strongarm->value = 0;

  $export['comment_class_material'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_class';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );

  $export['node_options_class'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_class_material';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );

  $export['node_options_class_material'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_class_material_pattern';
  $strongarm->value = '[space-og-path]/classes/[field_class-title-raw]/materials/[title-raw]';

  $export['pathauto_node_class_material_pattern'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_class_pattern';
  $strongarm->value = '[space-og-path]/classes/[title-raw]';

  $export['pathauto_node_class_pattern'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_class';
  $strongarm->value = TRUE;

  $export['show_diff_inline_class'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_class_material';
  $strongarm->value = TRUE;

  $export['show_diff_inline_class_material'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_class';
  $strongarm->value = FALSE;

  $export['show_preview_changes_class'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_class_material';
  $strongarm->value = FALSE;

  $export['show_preview_changes_class_material'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_class';
  $strongarm->value = TRUE;

  $export['upload_class'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_class_material';
  $strongarm->value = TRUE;

  $export['upload_class_material'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_class_default';
  $strongarm->value = unserialize('a:16:{s:5:"title";a:4:{s:6:"region";s:4:"main";s:6:"weight";s:1:"0";s:12:"has_required";b:1;s:5:"title";s:5:"Title";}s:10:"body_field";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"4";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"menu";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"1";s:12:"has_required";b:0;s:5:"title";s:13:"Menu settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:20:"revision_information";a:3:{s:6:"region";s:5:"right";s:6:"weight";s:1:"2";s:6:"hidden";i:0;}s:16:"comment_settings";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"7";s:12:"has_required";b:0;s:5:"title";s:16:"Comment settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:4:"path";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"6";s:12:"has_required";b:0;s:5:"title";s:17:"URL path settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:7:"options";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"4";s:12:"has_required";b:0;s:5:"title";s:18:"Publishing options";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:6:"author";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"3";s:12:"has_required";b:0;s:5:"title";s:21:"Authoring information";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:7:"buttons";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"7";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"book";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"5";s:12:"has_required";b:0;s:5:"title";s:12:"Book outline";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:8:"taxonomy";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"0";s:12:"has_required";b:0;s:5:"title";s:12:"Vocabularies";s:9:"collapsed";i:0;s:6:"hidden";i:0;}s:11:"attachments";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"6";s:12:"has_required";b:0;s:5:"title";s:26:"Attach files to this class";s:6:"hidden";i:0;}s:20:"field_class_semester";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"1";s:12:"has_required";b:0;s:5:"title";s:8:"Semester";s:6:"hidden";i:0;}s:16:"field_class_year";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"2";s:12:"has_required";b:0;s:5:"title";s:7:"Offered";s:6:"hidden";i:0;}s:16:"field_class_link";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"3";s:12:"has_required";b:0;s:5:"title";s:4:"Link";s:6:"hidden";i:0;}s:10:"og_nodeapi";a:6:{s:6:"region";s:4:"main";s:6:"weight";s:1:"5";s:12:"has_required";b:0;s:5:"title";s:9:"Web Sites";s:9:"collapsed";i:0;s:6:"hidden";i:0;}}');

  $export['nodeformscols_field_placements_class_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_class_material_default';
  $strongarm->value = unserialize('a:14:{s:5:"title";a:4:{s:6:"region";s:4:"main";s:6:"weight";s:2:"-5";s:12:"has_required";b:1;s:5:"title";s:13:"Booklet Title";}s:10:"body_field";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:5:"0.008";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"menu";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"0";s:12:"has_required";b:0;s:5:"title";s:13:"Menu settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:20:"revision_information";a:3:{s:6:"region";s:5:"right";s:6:"weight";s:1:"2";s:6:"hidden";i:0;}s:16:"comment_settings";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"6";s:12:"has_required";b:0;s:5:"title";s:16:"Comment settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:4:"path";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"5";s:12:"has_required";b:0;s:5:"title";s:17:"URL path settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:7:"options";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"4";s:12:"has_required";b:0;s:5:"title";s:18:"Publishing options";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:6:"author";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"3";s:12:"has_required";b:0;s:5:"title";s:21:"Authoring information";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:7:"buttons";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:3:"100";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"book";a:6:{s:6:"region";s:4:"main";s:6:"weight";s:2:"10";s:12:"has_required";b:0;s:5:"title";N;s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:8:"taxonomy";a:5:{s:6:"region";s:5:"right";s:6:"weight";s:1:"1";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:11:"attachments";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:2:"30";s:12:"has_required";b:0;s:5:"title";s:35:"Attach files to this class material";s:6:"hidden";i:0;}s:11:"field_class";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:2:"31";s:12:"has_required";b:0;s:5:"title";s:5:"Class";s:6:"hidden";i:0;}s:10:"og_nodeapi";a:6:{s:6:"region";s:4:"main";s:6:"weight";s:1:"0";s:12:"has_required";b:0;s:5:"title";s:9:"Web Sites";s:9:"collapsed";i:0;s:6:"hidden";i:0;}}');

  $export['nodeformscols_field_placements_class_material_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_class';
  $strongarm->value = 'group_post_standard';

  $export['og_content_type_usage_class'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_class_material';
  $strongarm->value = 'group_post_standard';

  $export['og_content_type_usage_class_material'] = $strongarm;
  return $export;
}
