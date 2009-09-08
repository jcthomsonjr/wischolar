<?php 

function vsite_users_members(){
  drupal_add_css(drupal_get_path('module', 'vsite_users') .'/theme/vsite_users.css');
  $site = vsite_get_vsite();
  $arg = $site -> group -> nid;
  return views_page('og_members', 'default', $arg); 
}

