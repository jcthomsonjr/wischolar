<?php

/**
 * Implementation of hook_strongarm().
 */
function scholar_software_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_scholar_software_project';
  $strongarm->value = 0;

  $export['comment_scholar_software_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_scholar_software_release';
  $strongarm->value = 0;

  $export['comment_scholar_software_release'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_scholar_software_project';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_scholar_software_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_scholar_software_release';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_scholar_software_release'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_scholar_software_project_default';
  $strongarm->value = unserialize('a:18:{s:5:"title";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"0";s:12:"has_required";b:0;s:5:"title";s:7:"Project";s:6:"hidden";i:0;}s:10:"body_field";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"6";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"menu";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"0";s:12:"has_required";b:0;s:5:"title";s:13:"Menu settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:20:"revision_information";a:3:{s:6:"region";s:5:"right";s:6:"weight";s:1:"3";s:6:"hidden";i:0;}s:16:"comment_settings";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"7";s:12:"has_required";b:0;s:5:"title";s:16:"Comment settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:4:"path";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"6";s:12:"has_required";b:0;s:5:"title";s:17:"URL path settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:7:"options";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"5";s:12:"has_required";b:0;s:5:"title";s:18:"Publishing options";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:6:"author";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"4";s:12:"has_required";b:0;s:5:"title";s:21:"Authoring information";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:7:"buttons";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"9";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"book";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"2";s:12:"has_required";b:0;s:5:"title";s:12:"Book outline";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:8:"taxonomy";a:5:{s:6:"region";s:5:"right";s:6:"weight";s:1:"1";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:11:"attachments";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"8";s:12:"has_required";b:0;s:5:"title";s:37:"Attach files to this software project";s:6:"hidden";i:0;}s:29:"field_scholar_software_method";a:4:{s:6:"region";s:4:"main";s:6:"weight";s:1:"1";s:12:"has_required";b:1;s:5:"title";s:16:"Packaging method";}s:27:"field_scholar_software_name";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"2";s:12:"has_required";b:0;s:5:"title";s:12:"Software key";s:6:"hidden";i:0;}s:27:"field_scholar_software_logo";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"3";s:12:"has_required";b:0;s:5:"title";s:4:"Logo";s:6:"hidden";i:0;}s:27:"field_scholar_software_repo";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"4";s:12:"has_required";b:0;s:5:"title";s:14:"Repository URL";s:6:"hidden";i:0;}s:10:"og_nodeapi";a:6:{s:6:"region";s:4:"main";s:6:"weight";s:1:"5";s:12:"has_required";b:0;s:5:"title";s:9:"Web Sites";s:9:"collapsed";i:0;s:6:"hidden";i:0;}s:18:"iqss_remote_source";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"7";s:12:"has_required";b:0;s:5:"title";s:22:"Remote Source Settings";s:6:"hidden";i:0;}}');

  $export['nodeformscols_field_placements_scholar_software_project_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_scholar_software_release_default';
  $strongarm->value = unserialize('a:20:{s:5:"title";a:3:{s:6:"region";s:4:"main";s:6:"weight";s:1:"0";s:6:"hidden";i:0;}s:10:"body_field";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"9";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"menu";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"2";s:12:"has_required";b:0;s:5:"title";s:13:"Menu settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:20:"revision_information";a:3:{s:6:"region";s:5:"right";s:6:"weight";s:1:"3";s:6:"hidden";i:0;}s:16:"comment_settings";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"7";s:12:"has_required";b:0;s:5:"title";s:16:"Comment settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:4:"path";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"6";s:12:"has_required";b:0;s:5:"title";s:17:"URL path settings";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:7:"options";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"5";s:12:"has_required";b:0;s:5:"title";s:18:"Publishing options";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:6:"author";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"4";s:12:"has_required";b:0;s:5:"title";s:21:"Authoring information";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:7:"buttons";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:2:"11";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"book";a:6:{s:6:"region";s:5:"right";s:6:"weight";s:1:"1";s:12:"has_required";b:0;s:5:"title";s:12:"Book outline";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:8:"taxonomy";a:5:{s:6:"region";s:5:"right";s:6:"weight";s:1:"0";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:11:"attachments";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:2:"10";s:12:"has_required";b:0;s:5:"title";s:37:"Attach files to this software release";s:6:"hidden";i:0;}s:27:"field_scholar_software_file";a:4:{s:6:"region";s:4:"main";s:6:"weight";s:1:"7";s:12:"has_required";b:1;s:5:"title";s:7:"Package";}s:30:"field_scholar_software_project";a:4:{s:6:"region";s:4:"main";s:6:"weight";s:1:"1";s:12:"has_required";b:1;s:5:"title";s:7:"Project";}s:18:"field_versionmajor";a:4:{s:6:"region";s:4:"main";s:6:"weight";s:1:"2";s:12:"has_required";b:1;s:5:"title";s:13:"Major version";}s:18:"field_versionpatch";a:4:{s:6:"region";s:4:"main";s:6:"weight";s:1:"3";s:12:"has_required";b:1;s:5:"title";s:13:"Patch version";}s:18:"field_versionextra";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"4";s:12:"has_required";b:0;s:5:"title";s:13:"Extra version";s:6:"hidden";i:0;}s:32:"field_scholar_software_recommend";a:4:{s:6:"region";s:4:"main";s:6:"weight";s:1:"5";s:12:"has_required";b:1;s:5:"title";s:11:"Recommended";}s:31:"field_scholar_software_security";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"6";s:12:"has_required";b:0;s:5:"title";s:16:"Security release";s:6:"hidden";i:0;}s:10:"og_nodeapi";a:6:{s:6:"region";s:4:"main";s:6:"weight";s:1:"8";s:12:"has_required";b:0;s:5:"title";s:9:"Web Sites";s:9:"collapsed";i:0;s:6:"hidden";i:0;}}');

  $export['nodeformscols_field_placements_scholar_software_release_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_scholar_software_project';
  $strongarm->value = 'group_post_standard';

  $export['og_content_type_usage_scholar_software_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_scholar_software_release';
  $strongarm->value = 'group_post_standard';

  $export['og_content_type_usage_scholar_software_release'] = $strongarm;
  return $export;
}
