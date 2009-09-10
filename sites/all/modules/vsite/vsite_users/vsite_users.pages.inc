<?php 
function vsite_users_members(){
  drupal_add_css(drupal_get_path('module', 'vsite_users') .'/theme/vsite_users.css');
  $site = vsite_get_vsite();
  $arg = $site -> group -> nid;
  ctools_include('ajax');
  ctools_include('modal');
  ctools_modal_add_js();
  return views_page('og_members', 'default', $arg); 
}

/**
 * Some function are used to render the user edit page
 */
require_once(drupal_get_path('module', 'user') .'/user.pages.inc');

/**
 * callback function for user edit popup form
 */
function vsite_users_edit_user($account){
  ctools_include('ajax');
  ctools_include('modal');
  ctools_modal_add_js();
  
//  $form_state = array(
//    're_render' => TRUE,
//    'ajax' => TRUE,
//  );
//
//  // pass all arguments needed by the callback function (ctools thing)
//  $form_state['args'] = array(NULL, $feature_name);

  $output = ctools_modal_command_display(user_page_title($account), user_view($account));

  if (empty($output)) {
    $output = array();
  }
  
  ctools_ajax_render($output);
}