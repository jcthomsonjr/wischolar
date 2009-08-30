<?php

/**
 * Provides theme selection for each site
 */
class vsite_design_settings_theme implements space_setting {
  var $id;
  function __construct($id = NULL) {
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'theme';
    }
  }

  function form($space, $value = array()) {
	  $form = array();
	
	  // all the enabled themes
	  vsite_include('vsiteapi');
	  $enabled = vsite_vsite_themes();
	  if (count($enabled) > 0){
	    ksort($enabled);
	  }
	  
	  $options = array();
	  
	  foreach ($enabled as $theme_obj) {
	    $info = $theme_obj -> info;
	    $info['theme_name'] = $theme_obj -> name;
	
	    $options[$info['theme_name']] = theme('vsite_design_theme_picker', $info); 
	  }  
	
	  $form = array(
	    '#title' => t(''),
	    '#type' => 'radios',
	    '#options' => $options,
	    '#default_value' => $value ? $value : '',
	  );
	  
	  return $form;
  }

  function validate($space, $value) {

  }

  function submit($space, $value) {
    $space -> group -> og_theme = $value;
    spaces_save($space);
    return $value;
  }
}


/**
 * Submits the form.
 */

/*
function cp_themes_form_submit($form, &$form_state){
  $site = vsite_get_vsite();
  $site -> group -> og_theme = $form_state['values']['theme'];
  spaces_save($site);
}
*/


