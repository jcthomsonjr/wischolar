<?php

/**
 * Construct the form itself
 *
 * @param unknown_type $form_values
 * @return unknown
 */
function  scholarregister_signup_form() {
  //print_r(drupal_get_form('user_register'));
  ctools_include ( 'ajax' );
  ctools_add_js ( 'ajax-responder');
  $form = array ();
  $form ['#prefix'] = '<div id = "user_register">';
  $form ['#suffix'] = '</div>';
  
  // username
  $form ['username'] = array (
    '#type' => 'textfield', 
    '#size' => 45, 
    '#title' => t ( 'User name' ), 
    '#required' => TRUE,
    '#description' => t('User name to login .. etc'),
    '#suffix' => '<div id="username-suffix"></div>',
    '#attributes' => array('class' => 'ctools-use-ajax-onchange'),
  );
  ctools_ajax_associate_url_to_element($form, $form['username'], url('scholarregister/name_js'));
  
  // last name
  $form ['email'] = array (
    '#type' => 'textfield', 
    '#size' => 45, 
    '#title' => t ( 'mail' ), 
    '#required' => TRUE,
    '#description' => t('A valid %harvard e-mail address . 
                        All e-mails from the system will be sent to this address. The e-mail address is
                        not made public and will only be used if you wish to receive a new password or
                        wish to receive certain news or notifications by e-mail.', array('%harvard' => 'Harvard')), 
    '#attributes' => array('class' => 'ctools-use-ajax-onchange'),
    '#suffix' => '<div id="email-suffix"></div>',
  );
  ctools_ajax_associate_url_to_element($form, $form['email'], url('scholarregister/mail_js'));
    
  global $base_url;
  // domain name
  $form ['domain'] = array (
    '#type' => 'textfield', 
    '#title' => t ( 'Domain Name' ), 
    '#field_prefix' => $base_url . '/', 
    '#size' => 20, 
    '#default_value' => $form_values ['name'], 
    '#description' => t ( 'The address of your web site will be %site. It must be at least 4 characters long, letters and numbers only', array (
    '%site' => $base_url . '/domain')),
    '#suffix' => '<div id="domain-suffix"></div>',
    '#attributes' => array('class' => 'ctools-use-ajax-onchange'),
 
  );
  ctools_ajax_associate_url_to_element($form, $form['domain'], url('scholarregister/domain_js'));
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create'),
    '#weight' => 20,
    /*
    '#ahah' => array(
       'path' => 'scholarregister/domain_js',
       'wrapper' => 'search',
       'progress' => array(
          'type' => 'bar',
          'message' => 'wwwwwwwwwwaait...',
       ),
     ),
    */
    '#attributes' => array('class' => 'ctools-use-ajax'),
    '#suffix' => '<div id="submit-suffix"></div>',
    );
  return $form;

}


function scholarregister_signup_form_submit($form, &$form_state) {
  //dpm($form_state);
  

  $name = $form_state ['values'] ['username'];
  $email = $form_state ['values'] ['email'];
  $domain = $form_state ['values'] ['domain'];
  
  //scholarregister_validate_name($name);
  //scholarregister_validate_mail($email);
  

  $form_s = array ();
  $form_s ['values'] ['name'] = $name;
  $form_s ['values'] ['mail'] = $email;
  $form_s ['values'] ['pass'] = 'password';
  $form_s ['values'] ['op'] = t ( 'Create new account' );
  drupal_execute ( 'user_register', $form_s );
  
  $msgs = drupal_get_messages ();
  $commands [] = ctools_ajax_command_replace ( '#submit-suffix', $m );
  ctools_ajax_render ( $commands );
  
  /*
  dpm($msgs);
  foreach ($msgs as $status => $m){
   if ($status == 'error'){
     $commands [] = ctools_ajax_command_replace ( '#submit-suffix', $m );
     ctools_ajax_render ( $commands );     
   }
  }
  */
  
  ctools_add_js ( 'ajax-responder' );
  $commands = array ();
  global $base_url;
  $message = 'Done !! Your site is created. The url of the site is ' . $base_url . '/' . $domain;
  
  $message .= 'Check your email account for ...';
  $commands [] = ctools_ajax_command_replace ( '#submit-suffix', $message );
  ctools_ajax_render ( $commands );
}