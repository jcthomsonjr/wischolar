<?php

/**
 * Construct the registration form
 */
function scholarregister_signup_form(){
  drupal_add_css(drupal_get_path('module', 'scholarregister') . '/theme/scholarregister.css');
  // clear any drupal_messages. Ajax takes care of them
  drupal_get_messages();
  
  ctools_include('ajax');
  ctools_add_js('ajax-responder');
  
  $form = array();
  $form['#prefix'] = '<div id = "user_register">';
  $form['#suffix'] = '</div>';
  
  // username
  $form['name'] = array(
      '#type' => 'textfield', 
      '#size' => 45, 
      '#title' => t('Desired user name'), 
      '#required' => TRUE, 
      '#description' => t('Spaces are allowed; punctuation is not allowed except for periods, hyphens, and underscores.'), 
      '#prefix' => '<div id="name-field">', 
      '#suffix' => '<div id="name-suffix"></div></div>', 
      '#attributes' => array(
          'class' => 'ctools-use-ajax-onchange' 
      ) 
  );
  ctools_ajax_associate_url_to_element($form, $form['name'], url('scholarregister/name_js'));
  
  // last name
  $form['mail'] = array(
      '#type' => 'textfield', 
      '#size' => 45, 
      '#title' => t('Your email address'), 
      '#required' => TRUE, 
      '#description' => t('A valid %harvard e-mail address is required. All e-mails from the Scholar Web Sites Project will be sent to this address.', array(
          '%harvard' => 'Harvard' 
      )), 
      '#attributes' => array(
          'class' => 'ctools-use-ajax-onchange' 
      ), 
      '#prefix' => '<div id="mail-field">', 
      '#suffix' => '<div id="mail-suffix"></div></div>' 
  );
  ctools_ajax_associate_url_to_element($form, $form['mail'], url('scholarregister/mail_js'));
  
  global $base_url;
  // domain name
  $form['domain'] = array(
      '#type' => 'textfield', 
      '#title' => t('Your Domain Name'), 
      '#required' => TRUE, 
      '#field_prefix' => $base_url . '/', 
      '#size' => 20, 
      '#default_value' => $form_values['name'], 
      '#description' => t('Example the choice of \'jdoe\' would result in domain name: %site. Your choice must be at least four characters long, and comprise of alphanumeric characters only.', array(
          '%site' => $base_url . '/jdoe' 
      )), 
      '#prefix' => '<div id="domain-field">', 
      '#suffix' => '<div id="domain-suffix"></div></div>', 
      '#attributes' => array(
          'class' => 'ctools-use-ajax-onchange' 
      ) 
  )
  ;
  ctools_ajax_associate_url_to_element($form, $form['domain'], url('scholarregister/domain_js'));
  
  $form['submit'] = array(
      '#type' => 'submit', 
      '#value' => t('Create your site'), 
      '#weight' => 20, 
      '#attributes' => array(
          'class' => 'ctools-use-ajax' 
      ), 
      '#suffix' => '<div id="submit-suffix"></div>' 
  );
  return $form;

}

/**
 * validation callback for the registration form
 */
function scholarregister_signup_form_validate($form, &$form_state){
  // get all the errors in the form (default drupal validation (required fields etc)
  $msgs = form_get_errors();
  
  if (count($msgs)) {
    $commands = array();
    foreach ( $msgs as $field_name => $m ) {
      $commands[] = ctools_ajax_command_html("#$field_name-suffix", $m);
      $commands[] = ctools_ajax_command_attr("#$field_name-suffix", 'class', 'error');
      $commands[] = _scholarregister_vsite_error();
    }
    ctools_ajax_render($commands);
  }
  
  $name = $form_state['values']['name'];
  $mail = $form_state['values']['mail'];
  $domain = $form_state['values']['domain'];
  
  // if any of the above value fail validation, exit with an appropriate message
  if (scholarregister_validate_name($name) || scholarregister_validate_mail($mail) || scholarregister_validate_domain($domain)) {
    $commands[] = _scholarregister_vsite_error();
    ctools_ajax_render($commands);
  }
}

/**
 * the submit handler for the registration form
 */
function scholarregister_signup_form_submit($form, &$form_state) {

  $name = $form_state ['values'] ['name'];
  $mail = $form_state ['values'] ['mail'];
  $domain = $form_state ['values'] ['domain'];
  
  $password =  user_password();
  $roles = variable_get('scholar_manager_role', 'scholar admin');
  
  // 1. create user
  /*
  $form_s = array ();
  $form_s ['values'] ['name'] = $name;
  $form_s ['values'] ['mail'] = $mail;
  $form_s ['values'] ['pass'] = user_password();
  $form_s ['values'] ['op'] = t ( 'Create new account' );
  drupal_execute ( 'user_register', $form_s );

  $msgs = drupal_get_messages();
  foreach ($msgs as $status => $m){
   if ($status == 'error'){
     $commands [] = ctools_ajax_command_replace ( '#submit-suffix', 'The web site cannot be created. Please fix the errors and try again.' );
     ctools_ajax_render ( $commands );
   }
  }
  */
  install_include(array(
      'user' 
  ));
  $user = install_add_user($name, $password, $mail, $roles = array($roles), $status = 1);
  if (!$user){ // unlikely
    $commands [] = _scholarregister_vsite_error();
    ctools_ajax_render ( $commands );    
  } 
  
  //add $user object to $form_state  and can be used by other submit functions called after this
  if(is_object($user)){  
    $form_state['new_user'] = $user;
  }
  
  // ok user is created sucessfully 
  // 2. create the site
  $vsite = scholarregister_vsite_create($name, $mail, $domain);
    
  /*  //2a. if user and site created successfully then log user in the pinserver table
  if($vsite && module_exists('pinserver')){
    pinserver_process_user_registration($user->uid);    
  }*/
  
  if (!$vsite){
    // first delete the user we just created
    // user_delete($user, $user -> uid);  // TODO test this
    $commands [] = _scholarregister_vsite_error();
    ctools_ajax_render ( $commands );  
  }
  
  else{  
  // site created successfully add the form values for additional submit fuctions
  $form_state['vsite'] = $vsite;
  // 3. send e-mail to the user.
  scholarregister_notify_user($vsite, $user);  
  }
  // 4. let user know this was all sucessful
  
  //ctools_add_js ( 'ajax-responder' );
  $commands = array ();
  global $base_url;
  $message  = '<div id="success-message">';
  $message .= '<p>Success! Your site has been created.</p>';
  $message .= '<p>The url of your site is ' . $base_url . '/' . $domain . " " . l(t("Go there now"), $base_url . '/' . $domain);
  $message .= '<p>Check your email account for further details on how to login in to start adding features and
content.</p>';
  $message .= '</div>';
  $commands [] = ctools_ajax_command_replace ( '#submit-suffix', $message );
  $commands[] = ctools_ajax_command_attr('#edit-submit', 'disabled', true); 
  //dpm($commands);
  
  //call any other submit functions here
  foreach($form['#submit'] as $fnc){
    if (__FUNCTION__ !== $fnc){
      call_user_func($fnc, $form, $form_state);
    }
  }
  
ctools_ajax_render ( $commands );
}

/**
 * Create a scholar vsite
 */
function scholarregister_vsite_create($name, $mail, $domain){
  vsite_include('vsiteapi');
  return vsite_vsite_create($name, $mail, $domain);
}


function _scholarregister_vsite_error(){
  return ctools_ajax_command_replace('#submit-suffix', 'The web site cannot be created. Please fix the errors and try again.');
  //ctools_ajax_render($commands);
}