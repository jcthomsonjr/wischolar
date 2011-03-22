<?php

/**
 * Provides front page settings for each site
 */
class vsite_generic_settings_settings implements vsite_setting {
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
    
    $a_settings = module_invoke_all('vsite_generic_settings', $space, $value);
    foreach ($a_settings as $s_key => $setting) {
      if (!array_key_exists('form', $setting)) continue;
      $form[$s_key] = $setting['form'];
    }
    return $form;
  }

  function validate($space, $value) {

    $a_settings = module_invoke_all('vsite_generic_settings', $space, $value);
    foreach ($a_settings as $s_key => $setting) {
      if (!array_key_exists('validate', $setting) || !function_exists($setting['validate'])) continue;
      call_user_func($setting['validate'], $space, $value);
    }
    
    return $value;
  }

  function submit($space, $value) {

    $a_settings = module_invoke_all('vsite_generic_settings', $space, $value);
    foreach ($a_settings as $s_key => $setting) {
      if (!array_key_exists('submit', $setting) || !function_exists($setting['submit'])) continue;
      call_user_func_array($setting['submit'], array($space, &$value));
    }
    
    return $value;
  }
}

