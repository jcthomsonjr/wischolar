<?php

/**
 * Construct the registration form
 */
function scholarregister_signup_form(){
  drupal_add_css(drupal_get_path('module', 'scholarregister') . '/theme/scholarregister.css');
  // clear any drupal_messages. Ajax takes care of them
  drupal_get_messages();
  
  //check if user is SuperUser
   $superuser = vsite_users_create_site_access();
  
  ctools_include('ajax');
  ctools_add_js('ajax-responder');
  
  $form = array();
  $form['#prefix'] = '<div id = "user_register">';
  $form['#suffix'] = '</div>';
  
  // username
  $form['name'] = array(
      '#type' => 'textfield', 
      '#size' => 45, 
      '#title' => ($superuser) ? t('Choose Site Owner\'s Username') : t('Desired user name'), 
      '#required' => TRUE, 
      '#description' => t('Spaces are allowed; punctuation is not allowed except for periods, hyphens, and underscores.'), 
      '#prefix' => '<div id="name-field">', 
      '#suffix' => '<div id="name-suffix"></div></div>', 
  );
  ctools_ajax_associate_url_to_element($form, $form['name'], url('scholarregister/name_js'), 'ctools-use-ajax-onchange');
  
  // last name
  $form['mail'] = array(
      '#type' => 'textfield', 
      '#size' => 45, 
      '#title' => ($superuser) ? t('Site Owner\'s email address') :  t('Your email address'), 
      '#required' => TRUE, 
      '#description' => t('A valid %harvard e-mail address is required. All e-mails from the Scholar Web Sites Project will be sent to this address.', array(
          '%harvard' => 'Harvard' 
      )), 
      '#prefix' => '<div id="mail-field">', 
      '#suffix' => '<div id="mail-suffix"></div></div>' 
  );
  ctools_ajax_associate_url_to_element($form, $form['mail'], url('scholarregister/mail_js'), 'ctools-use-ajax-onchange');
  
  global $base_url;
  // domain name
  $form['domain'] = array(
      '#type' => 'textfield', 
      '#title' => ($superuser) ?  t('Select a Domain Name') :  t('Your Domain Name'), 
      '#required' => TRUE, 
      '#field_prefix' => $base_url . '/', 
      '#size' => 20, 
      '#default_value' => $form_values['name'], 
      '#description' => t('Example the choice of \'jdoe\' would result in domain name: %site. Your choice must be at least four characters long, and comprise of alphanumeric characters only.', array(
          '%site' => $base_url . '/jdoe' 
      )), 
      '#prefix' => '<div id="domain-field">', 
      '#suffix' => '<div id="domain-suffix"></div></div>', 
  );  
  ctools_ajax_associate_url_to_element($form, $form['domain'], url('scholarregister/domain_js'), 'ctools-use-ajax-onchange');
  
  
    //if user is superuser then load additional fields
  if ($superuser){
    //TODO: this module should have it's own css???
    $path = drupal_get_path('module', 'iqss_pinserver_register');
    drupal_add_css($path .'/iqss_pinserver_register.css', 'module', 'all', FALSE); 
    
      //add dynamic password validation
    _user_password_dynamic_validation();

    // password field
    $form['password'] = array(
    '#type' => 'password_confirm',
    '#size' => 35,
    '#required' => TRUE,
    '#description' => 'Create a password for the site owner\'s user account.'
    );        
    
     // password field
    $form['send_mail'] = array(
    '#title' => 'Send an email notification to the site owner upon creating the site.',
    '#type' => 'checkbox',
    '#default' => 1,
    );       
  }
  
  $form['submit'] = array(
      '#type' => 'submit', 
      '#value' => t('Create your site'), 
      '#weight' => 20
      );
      
      if (!$superuser){
        $form['submit'] ['#attributes'] = array('class' => 'ctools-use-ajax' );
        $form['submit'] ['#suffix'] = '<div id="submit-suffix"></div>';
      }
      
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

  $password =  !empty($form_state ['values'] ['password']) ? $form_state ['values'] ['password'] : user_password();
  $roles = variable_get('scholar_manager_role', 'scholar admin');

  //1. Create the user account
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

  // 2. Create the site
  $vsite = scholarregister_vsite_create($name, $domain, 'scholar');

  if (!$vsite){
    // first delete the user we just created
    // user_delete($user, $user -> uid);  // TODO test this
    $commands [] = _scholarregister_vsite_error();
    ctools_ajax_render ( $commands );
  }

  else{
    // site created successfully add the form values for additional submit fuctions
    $form_state['vsite'] = $vsite;
    // 3. send e-mail to the user (unless specified not to by super user)
    $send_mail =  ($form_state ['values'] ['send_mail'] ===1) ? scholarregister_notify_user($vsite, $user) : FALSE;
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
  
  if (vsite_users_create_site_access()){
    if($vsite){
      global $user;
      //give super user adminstrative rights to site
      og_save_subscription($vsite->sid, $user->uid, array('is_active' => 1, 'is_admin' => 1));
      // unset any messages
      drupal_get_messages();
      // set message
      drupal_set_message(t("The web site registration was successful! The site is live and you are logged in."));
      //re-direct user to site home
      return drupal_goto($vsite -> purl);
    }
    
    else{
      _scholarregister_vsite_error();
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
 return ctools_ajax_command_html('#submit-suffix', 'The web site cannot be created. Please fix the errors and try again.');
}

