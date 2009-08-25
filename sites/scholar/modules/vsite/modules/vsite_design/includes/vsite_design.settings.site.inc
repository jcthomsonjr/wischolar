<?php 
/**
 * Provides theme selection for each site
 */
class vsite_design_setting_site implements space_setting {
  
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

  
    return $form;
  }

  function validate($space, $value) {
    // autocomplete has its own validation
  }

  function submit($space, $value) {
  	
    return $value;
  }
}