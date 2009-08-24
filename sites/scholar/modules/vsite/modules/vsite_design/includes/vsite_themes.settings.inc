<?php

/**
 * Provides theme selection for each site
 */
class vsite_themes_settings_theme implements space_setting {
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
	  $enabled = cp_get_scholar_themes();
	  if (count($enabled) > 0){
	    ksort($enabled);
	  }
	  
	  $options = array();
	  
	  foreach ($enabled as $theme_obj) {
	    $info = $theme_obj -> info;
	    $info['theme_name'] = $theme_obj -> name;
	
	    $options[$info['theme_name']] = theme('vsite_themes_theme_picker', $info); 
	  }  
	
	  $form = array(
	    '#title' => t('theme selection'),
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
 * return the current theme name of the active scholar site
 */
function cp_current_theme(){
  $site = vsite_get_vsite();
  return $site -> group -> og_theme;
}

/**
 * Submits the form.
 */
function cp_themes_form_submit($form, &$form_state){
  $site = vsite_get_vsite();
  $site -> group -> og_theme = $form_state['values']['theme'];
  spaces_save($site);
}


/**
 * returns an array of available themes for faculty to chose
 * For now it suppose that the theme name will follow this pattern
 * scholar_theme_01, scholar_theme__02 ... scholar_theme_99
 * @see _cp_is_scholar_theme
 * @todo private themes ?!
 */
function cp_get_scholar_themes(){
  $allthemes = list_themes();
  return (array_filter($allthemes,"_cp_is_scholar_theme"));
}


/**
 * a callback function for array_filter() in iq_og_fac_themes
 *
 * @param unknown_type $atheme - the theme to be tested
 * @return TRUE if it should be listed as faculty theme, false otherwise
 */
function _cp_is_scholar_theme($atheme){
  return (ereg("scholar_theme_[0-9][0-9]",$atheme -> name));
}

