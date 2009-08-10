<?php 


function scholarcp_user_members(){
  drupal_add_css(drupal_get_path('module', 'scholarcp') .'/theme/scholarcp-users.css');
  $site = scholar_get_scholar();
  $arg = $site -> group -> nid;
  return views_page('og_members', 'default', $arg); 
}