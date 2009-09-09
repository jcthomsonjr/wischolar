<?php

/**
 * Provides front page settings for each site
 */
class vsite_generic_settings_settings implements space_setting {
	public $weight = 100;
	
  var $id;
  function __construct($id = NULL) {
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'generic';
    }
  }

  function form($space, $value = array()) {
  
    $form = array('#title' => "Other Settings");	
  
    $form['admin_menu'] = array(
		  '#type' => 'checkbox',
		  '#title' => t('Display Admin Menu Bar.'),
      '#description' => "The admin menu bar dispalys at the top of the page when you are logged in as a site administrator.",
      '#default_value' => (is_array($value) && array_key_exists('admin_menu',$value))?$value['admin_menu']:1,
		);
    
    return $form;
  }

  function validate($space, $value) {
    return $value;  
  }

  function submit($space, $value) {

    return $value;
  }
}

