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
  
  $form_state = array(
    're_render' => TRUE,
    'ajax' => TRUE,
  );

  // pass all arguments needed 
  $form_state['args'] = array($account, 'account');

  $output = ctools_modal_form_wrapper('user_profile_form', $form_state);

  if (empty($output)) {
    $output = array();
  }
  
  ctools_ajax_render($output);
}