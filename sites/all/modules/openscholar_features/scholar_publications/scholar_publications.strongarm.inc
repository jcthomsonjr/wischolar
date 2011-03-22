<?php

/**
 * Implementation of hook_strongarm().
 */
function scholar_publications_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_base';
  $strongarm->value = 'publications';

  $export['biblio_base'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_sort_tabs';
  $strongarm->value = array(
    'author' => 'author',
    'title' => 'title',
    'type' => 'type',
    'year' => 'year',
  );

  $export['biblio_sort_tabs'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_biblio';
  $strongarm->value = 0;

  $export['comment_biblio'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_biblio';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_biblio'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_biblio_pattern';
  $strongarm->value = '[space-og-path]/publications/[title-raw]';

  $export['pathauto_node_biblio_pattern'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_biblio';
  $strongarm->value = FALSE;

  $export['show_diff_inline_biblio'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_biblio';
  $strongarm->value = FALSE;

  $export['show_preview_changes_biblio'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_biblio';
  $strongarm->value = TRUE;

  $export['upload_biblio'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_biblio_default';
  $strongarm->value = unserialize('a:27:{s:5:"title";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:3:"-46";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"menu";a:5:{s:6:"region";s:5:"right";s:6:"weight";s:1:"7";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:20:"revision_information";a:5:{s:6:"region";s:5:"right";s:6:"weight";s:1:"2";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:16:"comment_settings";a:5:{s:6:"region";s:5:"right";s:6:"weight";s:1:"6";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"path";a:5:{s:6:"region";s:5:"right";s:6:"weight";s:1:"8";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:7:"options";a:5:{s:6:"region";s:5:"right";s:6:"weight";s:1:"5";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:6:"author";a:5:{s:6:"region";s:5:"right";s:6:"weight";s:1:"4";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:7:"buttons";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:2:"17";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:3:"nid";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"6";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:3:"vid";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"7";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:3:"uid";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"8";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:7:"created";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:1:"9";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:4:"type";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:3:"-45";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:8:"language";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:2:"10";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:7:"changed";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:2:"11";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:17:"biblio_doi_lookup";a:6:{s:6:"region";s:4:"main";s:6:"weight";s:1:"5";s:12:"has_required";b:0;s:5:"title";s:10:"DOI Lookup";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:16:"biblio_cut_paste";a:6:{s:6:"region";s:4:"main";s:6:"weight";s:1:"4";s:12:"has_required";b:0;s:5:"title";s:5:"Paste";s:9:"collapsed";i:1;s:6:"hidden";i:0;}s:11:"biblio_type";a:4:{s:6:"region";s:4:"main";s:6:"weight";s:3:"-45";s:12:"has_required";b:1;s:5:"title";s:16:"Publication Type";}s:4:"book";a:5:{s:6:"region";s:5:"right";s:6:"weight";s:1:"3";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:8:"taxonomy";a:5:{s:6:"region";s:5:"right";s:6:"weight";s:1:"0";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:11:"attachments";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:2:"12";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:18:"field_biblio_extra";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:2:"13";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:18:"field_biblio_image";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:2:"16";s:12:"has_required";b:0;s:5:"title";s:10:"Book Cover";s:6:"hidden";i:0;}s:17:"og_initial_groups";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:2:"14";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:10:"og_nodeapi";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:2:"15";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:26:"cite_distribute_selections";a:5:{s:6:"region";s:5:"right";s:6:"weight";s:1:"1";s:12:"has_required";b:0;s:5:"title";N;s:6:"hidden";i:0;}s:11:"submit_type";a:5:{s:6:"region";s:4:"main";s:6:"weight";s:3:"-45";s:12:"has_required";b:0;s:5:"title";s:23:"Select Publication Type";s:6:"hidden";i:0;}}');

  $export['nodeformscols_field_placements_biblio_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_biblio';
  $strongarm->value = 'group_post_standard';

  $export['og_content_type_usage_biblio'] = $strongarm;
  return $export;
}
