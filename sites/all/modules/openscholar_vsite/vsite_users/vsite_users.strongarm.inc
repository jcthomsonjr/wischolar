<?php

/**
 * Implementation of hook_strongarm().
 */
function vsite_users_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_vsite_users_profile';
  $strongarm->value = 0;

  $export['comment_vsite_users_profile'] = $strongarm;
  return $export;
}
