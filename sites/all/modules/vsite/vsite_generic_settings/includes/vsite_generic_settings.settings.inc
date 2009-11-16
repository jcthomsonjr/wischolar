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
    
    $a_settings = module_invoke_all('vsite_generic_settings',$value);
    
    foreach ($a_settings as $s_key => $setting){
    	if(!array_key_exists('form',$setting)) continue;
    	$form[$key] = $setting['form'];
    }
		
    return $form;
  }

  function validate($space, $value) {
    return $value;
  }

  function submit($space, $value) {
    return $value;
  }
}

