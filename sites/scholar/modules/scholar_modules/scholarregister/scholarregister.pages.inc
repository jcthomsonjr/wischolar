<?php

/**
 * Construct the form itself
 *
 * @param unknown_type $form_values
 * @return unknown
 */
function  scholarregister_signup_form() {
  ctools_include ( 'ajax' );
  ctools_add_js ( 'ajax-responder');
  $form = array ();
  $form ['#prefix'] = '<div id = "user_register">';
  $form ['#suffix'] = '</div>';
  
  // username
  $form ['name'] = array (
    '#type' => 'textfield', 
    '#size' => 45, 
    '#title' => t ( 'User name' ), 
    '#required' => TRUE,
    '#description' => t('User name to login .. etc'),
    '#suffix' => '<div id="name-suffix"></div>',
    '#attributes' => array('class' => 'ctools-use-ajax-onchange'),
  );
  ctools_ajax_associate_url_to_element($form, $form['name'], url('scholarregister/name_js'));
  
  // last name
  $form ['mail'] = array (
    '#type' => 'textfield', 
    '#size' => 45, 
    '#title' => t ( 'mail' ), 
    '#required' => TRUE,
    '#description' => t('A valid %harvard e-mail address . 
                        All e-mails from the system will be sent to this address. The e-mail address is
                        not made public and will only be used if you wish to receive a new password or
                        wish to receive certain news or notifications by e-mail.', array('%harvard' => 'Harvard')), 
    '#attributes' => array('class' => 'ctools-use-ajax-onchange'),
    '#suffix' => '<div id="mail-suffix"></div>',
  );
  ctools_ajax_associate_url_to_element($form, $form['mail'], url('scholarregister/mail_js'));
    
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
  //dpm ( $form_state );
  
  $name = $form_state ['values'] ['name'];
  $email = $form_state ['values'] ['mail'];
  
  ctools_add_js ( 'ajax-responder' );
  $commands = array ();
  global $base_url;
  $message = 'Congratulation !! Your site is created. The url of the site is ' . $base_url . '/' . $name;
  $message .= 'Check your email account for ...';
  $commands [] = ctools_ajax_command_replace ( '#submit-suffix',  $message );
  ctools_ajax_render ( $commands );
}