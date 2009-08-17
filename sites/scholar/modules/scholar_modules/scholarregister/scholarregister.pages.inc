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
    '#title' => t ( 'Desired user name' ),
    '#required' => TRUE,
    '#description' => t('Choose an easy to remember user name.'),
    '#prefix' => '<div id="username-field">',
    '#suffix' => '<div id="username-suffix"></div></div>',
    '#attributes' => array('class' => 'ctools-use-ajax-onchange'),
  );
  ctools_ajax_associate_url_to_element($form, $form['username'], url('scholarregister/name_js'));

  // last name
  $form ['email'] = array (
    '#type' => 'textfield',
    '#size' => 45,
    '#title' => t ( 'Your email address' ),
    '#required' => TRUE,
    '#description' => t('A valid %harvard e-mail address is required. All e-mails from the Scholar Web Sites Project will be sent to this address.', array('%harvard' => 'Harvard')),
    '#attributes' => array('class' => 'ctools-use-ajax-onchange'),
    '#prefix' => '<div id="email-field">',
    '#suffix' => '<div id="email-suffix"></div></div>',
  );
  ctools_ajax_associate_url_to_element($form, $form['email'], url('scholarregister/mail_js'));

  global $base_url;
  // domain name
  $form ['domain'] = array (
    '#type' => 'textfield',
    '#title' => t ( 'Your Domain Name' ),
    '#field_prefix' => $base_url . '/',
    '#size' => 20,
    '#default_value' => $form_values ['name'],
    '#description' => t ( 'Example the choice of \'jdoe\' would result in domain name: %site. Your choice must be at least four characters long, and comprise of alphanumeric characters only.', array (
    '%site' => $base_url . '/jdoe')),
    '#prefix' => '<div id="domain-field">',
    '#suffix' => '<div id="domain-suffix"></div></div>',
    '#attributes' => array('class' => 'ctools-use-ajax-onchange'),

  );
  ctools_ajax_associate_url_to_element($form, $form['domain'], url('scholarregister/domain_js'));

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create your site'),
    '#weight' => 20,
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
  $form_s ['values'] ['pass'] = user_password();
  $form_s ['values'] ['op'] = t ( 'Create new account' );
  drupal_execute ( 'user_register', $form_s );

  $msgs = drupal_get_messages ();

  foreach ($msgs as $status => $m){
   if ($status == 'error'){
     $commands [] = ctools_ajax_command_replace ( '#submit-suffix', 'The web site cannot be created. Please fix the errors and try again.' );
     ctools_ajax_render ( $commands );
   }
  }

  // ok user is created sucessfully 
  // try to create the site
  scholarregister_vsite_create($name, $email, $domain);
  
  ctools_add_js ( 'ajax-responder' );
  $commands = array ();
  global $base_url;
  $message  = '<div id="success-message">';
  $message .= '<p>Success! Your site has been created.</p>';
  $message .= '<p>The url of your site is ' . $base_url . '/' . $domain . '. <a href="' . $base_url . '/' . $domain . '">Go there now.</a></p>';
  $message .= '<p>Check your email account for further details.</p>';
  $message .= '</div>';
  $commands [] = ctools_ajax_command_replace ( '#submit-suffix', $message );
  ctools_ajax_render ( $commands );
}


/**
 * Create a scholar vsite
 */
function scholarregister_vsite_create($name, $email, $domain){
  install_include(array(
      'node' 
  ));
  $properties = array(
      'name' => $name, 
      'type' => variable_get('scholar_content_type', 'scholarsite'), 
      'promote' => '0', 
      'purl' => array(
          'value' => $domain, 
          'provider' => 'spaces_og', 
          'id' => NULL 
      ), 
      'preset' => 'scholarsite', 
      'og_description' => "$domain's web site", 
      'theme' => 'scholar_theme_01', // TODO what is the default theme ? 
  );
  $node = install_create_node($title = $domain, $body = NULL, $properties = $properties);
}