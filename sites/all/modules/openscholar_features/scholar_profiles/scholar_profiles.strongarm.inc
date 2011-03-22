<?php

/**
 * Implementation of hook_strongarm().
 */
function scholar_profiles_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_person';
  $strongarm->value = '[field_person_firstname-raw] [field_person_middlename-raw] [field_person_lastname-raw]';

  $export['ant_pattern_person'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_person';
  $strongarm->value = '1';

  $export['ant_person'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_person';
  $strongarm->value = '1';

  $export['ant_php_person'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_person';
  $strongarm->value = 0;

  $export['comment_person'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_person';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );

  $export['node_options_person'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_person_pattern';
  $strongarm->value = '[space-og-path]/people/[title-raw]';

  $export['pathauto_node_person_pattern'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_person';
  $strongarm->value = FALSE;

  $export['show_diff_inline_person'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_person';
  $strongarm->value = FALSE;

  $export['show_preview_changes_person'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_person';
  $strongarm->value = FALSE;

  $export['upload_person'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_person_default';
  $strongarm->value = unserialize('a:21:{s:5:"title";a:3:{s:6:"region";s:4:"main";s:6:"weight";s:1:"3";s:6:"hidden";i:0;}s:10:"body_field";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"5";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"menu";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"1";s:12:"has_required";b:0;s:5:"title";s:13:"Menu settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:20:"revision_information";a:3:{s:6:"region";s:5:"right";s:6:"weight";s:1:"2";s:6:"hidden";i:0;}s:16:"comment_settings";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"6";s:12:"has_required";b:0;s:5:"title";s:16:"Comment settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:4:"path";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"5";s:12:"has_required";b:0;s:5:"title";s:17:"URL path settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:7:"options";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"4";s:12:"has_required";b:0;s:5:"title";s:18:"Publishing options";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:6:"author";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"3";s:12:"has_required";b:0;s:5:"title";s:21:"Authoring information";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:7:"buttons";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:2:"13";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"book";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"0";s:12:"has_required";b:0;s:5:"title";s:12:"Book outline";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:22:"field_person_firstname";a:4:{s:6:"region";s:4:"main";s:6:"weight";s:1:"0";s:12:"has_required";b:1;s:5:"title";s:10:"First Name";}s:21:"field_person_lastname";a:4:{s:6:"region";s:4:"main";s:6:"weight";s:1:"2";s:12:"has_required";b:1;s:5:"title";s:9:"Last Name";}s:23:"field_person_middlename";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"1";s:12:"has_required";b:0;s:5:"title";s:22:"Middle Name or Initial";s:6:"hidden";i:0;}s:18:"field_person_title";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"4";s:12:"has_required";b:0;s:5:"title";s:30:"Professional Title/Affiliation";s:6:"hidden";i:0;}s:20:"field_person_address";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"6";s:12:"has_required";b:0;s:5:"title";s:7:"Address";s:6:"hidden";i:0;}s:18:"field_person_phone";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"7";s:12:"has_required";b:0;s:5:"title";s:5:"Phone";s:6:"hidden";i:0;}s:18:"field_person_email";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"8";s:12:"has_required";b:0;s:5:"title";s:5:"Email";s:6:"hidden";i:0;}s:20:"field_person_website";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"9";s:12:"has_required";b:0;s:5:"title";s:8:"Web Site";s:6:"hidden";i:0;}s:18:"field_person_photo";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:2:"10";s:12:"has_required";b:0;s:5:"title";s:5:"Photo";s:6:"hidden";i:0;}s:10:"og_nodeapi";a:6:{s:6:"region";s:4:"main";s:6:"weight";s:2:"12";s:12:"has_required";b:0;s:5:"title";s:9:"Web Sites";s:9:"collapsed";i:0;s:6:"hidden";i:0;}s:11:"attachments";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:2:"11";s:12:"has_required";b:0;s:5:"title";s:27:"Attach files to this person";s:6:"hidden";i:0;}}');

  $export['nodeformscols_field_placements_person_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_person';
  $strongarm->value = 'group_post_standard';

  $export['og_content_type_usage_person'] = $strongarm;
  return $export;
}
