<?php

/**
 * Provides shield selection for each site
 */
class cp_setting_shield implements space_setting {
  var $id;
  function __construct($id = NULL) {
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'shield';
    }
  }

  function form($space, $value = array()) {
    $form = array();
  
    $s_default = drupal_get_path('theme','scholar_base')."/shields/harvard_shield.png";
    $s_shield_dir = drupal_get_path('theme','scholar_base')."/shields";
    $a_shields = file_scan_directory($s_shield_dir, '.*', array('.', '..'));
    
    $options = array();
    
    foreach ($a_shields as $shield) {
      $options[$shield->filename] = theme('cp_theme_shieldpicker', $shield); 
    }  
  
    $form = array(
      '#prefix' => "<div class='select_wrapper'>",
      '#title' => t('Shield'),
      '#type' => 'radios',
      '#options' => $options,
      '#default_value' => $value ? $value:$s_default,
      '#append' => '</div>',
    );
    
    return $form;
  }

  function validate($space, $value) {

  }

  function submit($space, $value) {
    
  	return $value;
  }
}

