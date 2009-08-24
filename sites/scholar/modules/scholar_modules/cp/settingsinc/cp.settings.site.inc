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
    
    
    $form['headline'] = array(
      '#type' => 'textfield',
		  '#title' => t('Headline'),
		  '#default_value' => isset($value['headline'])?$value['headline']:'',
		  '#size' => 60,
		  '#maxlength' => 128,
		  '#required' => TRUE,
    );
    $form['sub_heading'] = array(
      '#type' => 'textfield',
      '#title' => t('Sub Heading 1'),
      '#default_value' => isset($value['sub_heading'])?$value['sub_heading']:'',
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
    );
    $form['sub_heading_extra'] = array(
      '#type' => 'textfield',
      '#title' => t('Sub Heading 2'),
      '#default_value' => isset($value['sub_heading_extra'])?$value['sub_heading_extra']:'',
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => FALSE,
    );

//    Notification Pref Disabled 8/19/09 @rbrandon
//    $form['notification_preferences'] = array(
//          '#title' => 'Notification Preferences',
//          '#type' => 'fieldset',
//          '#tree' => TRUE,
//    );
//    $form['notification_preferences']['scholar_updates'] = array(
//      '#type' => 'checkbox',
//      '#title' => t('Email me with Scholars\' website updates'),
//      '#default_value' => isset($value['notification_preferences']['scholar_updates'])?$value['notification_preferences']['scholar_updates']:0,
//    );
//    $form['notification_preferences']['scholar_comments'] = array(
//      '#type' => 'checkbox',
//      '#title' => t('Email me when somone writes a comment on my site'),
//      '#default_value' => isset($value['notification_preferences']['scholar_comments'])?$value['notification_preferences']['scholar_comments']:0,
//    );

  
    return $form;
  }

  function validate($space, $value) {
    // autocomplete has its own validation
  }

  function submit($space, $value) {
  	
    return $value;
  }
}