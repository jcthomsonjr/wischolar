<?php 
function vsite_users_members(){
  drupal_add_css(drupal_get_path('module', 'vsite_users') . '/theme/vsite_users.css');
  $site = vsite_get_vsite();
  $arg = $site->group->nid;
  ctools_include('ajax');
  ctools_include('modal');
  ctools_modal_add_js();
  $output = ctools_modal_text_button('Add new user', 'cp/users/add', 'add a new user', 'context-button');
  $output = theme('item_list', array(
    $output 
  ), $title = NULL, $type = 'ul', $attributes = array(
    "class" => "context-links" 
  ));
  
  $output .= views_page('og_members', 'default', $arg);
  return $output;
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

/**
 * callback function for our popup user add
 */
function vsite_users_add_user(){
  ctools_include('ajax');
  ctools_include('modal');
  
//  ctools_add_js('misc/jquery.form.js');
//  ctools_add_js('misc/ahah.js');
//  ctools_add_js(array('ahah' => array('edit-vsite-users-first-name' => array('url' => '/site01/cp/users/user_lookup', 
//                                      'event' => 'change', 
//                                      'keypress' => '', 
//                                      'wrapper' => 'user_lookup', 
//                                      'selector' => '#edit-vsite-users-first-name', 
//                                      'effect' => 'fade', 
//                                      'method' => 'replace', 
//                                      'progress' => Array('type' => 'throbber' ), 
//                                      'button' => '' ))), 'setting');
  
  $form_state = array(
    're_render' => FALSE,
    'ajax' => TRUE,
  );

  // pass all arguments needed by the callback function (ctools thing)
  $form_state['args'] = array(NULL);

  $output = ctools_modal_form_wrapper('ucreate_user_form', $form_state);
  
  if (empty($output)) {
    $output = array();
    $output[] = ctools_modal_command_dismiss();  //close the modal pop-up
    $output[] = ctools_ajax_command_reload();  //reload the parent window to display the confirmation message
  }else{
  	//$output[0]['output'] = "<div style='wdith:550px;float:left;'>".$output[0]['output']."</div><div id='user_lookup' style='float:left;'>This is for good</div>";
  }
  
  ctools_ajax_render($output);
}



/**
 * callback function for our user lookup
 */
function vsite_users_lookup_user(){
	$output = "<h3>Add an existing user</h3>";
	
	$output .= "<ul>";
	$output .= "<li><a class='add' href='add the user' /><span class='name'>Richard Brandon</span><span class='email'>rbrandon@iq.harvard.edu</span>";
	$output .= "<li><a class='add' href='add the user' /><span class='name'>Mikey Brandon</span><span class='email'>mbrock@iq.harvard.edu</span>";
	$output .= "</ul>";
	
	print drupal_to_js(array('status' => TRUE, 'data' => $output));
  exit;
}