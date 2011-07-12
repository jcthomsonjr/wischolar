<?php

/**
 * Implementation of hook_strongarm().
 */
function os_wysiwyg_fields_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_page_field_os_inline_image';
  $strongarm->value = 0;

  $export['ffp_page_field_os_inline_image'] = $strongarm;
  return $export;
}
