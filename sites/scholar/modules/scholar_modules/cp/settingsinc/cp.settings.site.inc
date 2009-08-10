<?php 
/**
 * Provides theme selection for each site
 */
class cp_setting_site implements space_setting {
  
  var $id;
  function __construct($id = NULL) {
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'site';
    }
  }

  function form($space, $value = array()) {
    $form = array('#title'=>'Site Information' );
    
    $form['name_title'] = array(
          '#title' => 'Name and Title',
          '#type' => 'fieldset',
          '#tree' => TRUE,
    );
    $form['name_title']['first'] = array(
      '#type' => 'textfield',
		  '#title' => t('First Name'),
		  '#default_value' => isset($value['name_title']['first'])?$value['name_title']['first']:'',
		  '#size' => 60,
		  '#maxlength' => 128,
		  '#required' => TRUE,
    );
    $form['name_title']['last'] = array(
      '#type' => 'textfield',
      '#title' => t('Last Name'),
      '#default_value' => isset($value['name_title']['last'])?$value['name_title']['last']:'',
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
    );
    $form['name_title']['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => isset($value['name_title']['title'])?$value['name_title']['title']:'',
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
    );
    
    $form['address'] = array(
          '#title' => 'Address',
          '#type' => 'fieldset',
          '#tree' => TRUE,
    );
    $form['address']['address'] = array(
      '#type' => 'textfield',
      '#title' => t('Address'),
      '#default_value' => isset($value['address']['address'])?$value['address']['address']:'',
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => false,
    );
    $form['address']['city'] = array(
      '#type' => 'textfield',
      '#title' => t('City'),
      '#default_value' => isset($value['address']['city'])?$value['address']['city']:'',
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
    );
    $form['address']['state'] = array(
      '#type' => 'textfield',
      '#title' => t('State'),
      '#default_value' => isset($value['address']['state'])?$value['address']['state']:'',
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
    );
    $form['address']['zip'] = array(
      '#type' => 'textfield',
      '#title' => t('Zip'),
      '#default_value' => isset($value['address']['zip'])?$value['address']['zip']:'',
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
    );
    
    $form['contact'] = array(
          '#title' => 'Contact',
          '#type' => 'fieldset',
          '#tree' => TRUE,
    );
    $form['contact']['phone'] = array(
      '#type' => 'textfield',
      '#title' => t('Phone'),
      '#default_value' => isset($value['contact']['phone'])?$value['contact']['phone']:'',
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => false,
    );
    $form['contact']['email'] = array(
      '#type' => 'textfield',
      '#title' => t('EMail'),
      '#default_value' => isset($value['contact']['email'])?$value['contact']['email']:'',
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
    );
    
    $form['notification_preferences'] = array(
          '#title' => 'Notification Preferences',
          '#type' => 'fieldset',
          '#tree' => TRUE,
    );
    $form['notification_preferences']['scholar_updates'] = array(
      '#type' => 'checkbox',
      '#title' => t('Email me with Scholars\' website updates'),
      '#default_value' => isset($value['notification_preferences']['scholar_updates'])?$value['notification_preferences']['scholar_updates']:0,
    );
    $form['notification_preferences']['scholar_comments'] = array(
      '#type' => 'checkbox',
      '#title' => t('Email me when somone writes a comment on my site'),
      '#default_value' => isset($value['notification_preferences']['scholar_comments'])?$value['notification_preferences']['scholar_comments']:0,
    );

  
    return $form;
  }

  function validate($space, $value) {
    // autocomplete has its own validation
  }

  function submit($space, $value) {

  	//Update User
  	$space;
  	$user = user_load($space->group->uid);
  	user_save($user,array(//'name' => "{$value['name_title']['first']} {$value['name_title']['last']}",
  	                      'mail' => $value['contact']['email']));
  	
    return $value;
  }
}