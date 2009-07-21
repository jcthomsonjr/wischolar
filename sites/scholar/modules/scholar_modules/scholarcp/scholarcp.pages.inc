<?php
/**
 * the form definition for theme selection
 */
function scholarcp_themes_form(){
  $form = array();
  $form['#prefix'] = '<div id = "scholar-select-theme">';
  $form['#suffix'] = '</div>';
  
  $form['themes'] = array(
    '#type' => 'fieldset',
    '#title' => t('Select a theme'),
    '#collapsible' => FALSE,
    '#prefix' => '<div class="select-theme">',
    '#suffix' => '</div>',
  );
  
  $enabled = scholarcp_get_scholar_themes();
  if (count($enabled) > 0){
    ksort($enabled);
  }
  
  foreach ($enabled as $theme_obj) {
    $info = $theme_obj -> info;
    $theme_name = $theme_obj -> name;

    $screenshot = t('no screenshoot available');
    if (file_exists($info['screenshot'])){
      $screenshot = theme('image', $info['screenshot'], t('Screenshot for %theme theme', array('%theme' => $theme_name)), '', array('class' => 'screenshot'), FALSE);
    }

    $form['themes'][$theme_name]['screenshot'] = array('#value' => $screenshot);
    $form['themes'][$theme_name]['name'] = array(
    	'#type' => 'item', 
    	'#title' => $theme_name,  
    	'#value' =>  '',
      '#description' => $info['description'],
    );
    
    $options[$theme_name] = ''; //'ccc';
  }  

  $default_value = scholarcp_current_theme();
  
  $form['themes']['theme'] = array(
    '#type' => 'radios',
    '#options' => $options,
    '#default_value' => $default_value ? $default_value : '',
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit')
  );
  return $form;
}

/**
 * return the current theme name of the active scholar site
 */
function scholarcp_current_theme(){
  $site = scholar_get_scholar();
  return $site -> group -> og_theme;
}

/**
 * Submits the form.
 */
function scholarcp_themes_form_submit($form, &$form_state){
  $site = scholar_get_scholar();
  $site -> group -> og_theme = $form_state['values']['theme'];
  spaces_save($site);
}


/**
 * returns an array of available themes for faculty to chose
 * For now it suppose that the theme name will follow this pattern
 * scholar_theme_01, scholar_theme__02 ... scholar_theme_99
 * @see _scholarcp_is_scholar_theme
 * @todo private themes ?!
 */
function scholarcp_get_scholar_themes(){
  $allthemes = list_themes();
  return (array_filter($allthemes,"_scholarcp_is_scholar_theme"));
}


/**
 * a callback function for array_filter() in iq_og_fac_themes
 *
 * @param unknown_type $atheme - the theme to be tested
 * @return TRUE if it should be listed as faculty theme, false otherwise
 */
function _scholarcp_is_scholar_theme($atheme){
  return (ereg("scholar_theme_[0-9][0-9]",$atheme -> name));
}



