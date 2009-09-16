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
      '#description' => "The admin menu bar displays at the top of the page when you are logged in as a site administrator.",
      '#default_value' => (is_array($value) && array_key_exists('admin_menu',$value))?$value['admin_menu']:1,
		);
		
		$s_default_shield = drupal_get_path('module','vsite_generic_settings')."/theme/shields/harvard_shield.png";
    $s_shield_dir = drupal_get_path('module','vsite_generic_settings')."/theme/shields";
    $a_shields = file_scan_directory($s_shield_dir, '.*', array('.', '..'));
    
    $shield_options = array();
    
    foreach ($a_shields as $shield) {
      $shield_options[$shield->filename] = theme('vsite_design_theme_shieldpicker', $shield); 
    }  
  
    $form['shield'] = array(
      '#prefix' => "<div class='shield_wrapper'>",
      '#title' => t('Shield'),
      '#type' => 'radios',
      '#options' => $shield_options,
      '#default_value' => is_array($value) && array_key_exists('shield',$value) ? $value['shield']:$s_default_shield,
      '#append' => '</div>',
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

