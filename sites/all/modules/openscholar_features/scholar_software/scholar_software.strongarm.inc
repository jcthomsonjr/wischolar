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
  return $export;
}
