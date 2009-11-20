<?php

/**
 * Provides theme selection for each site
 */
class vsite_design_settings_theme implements space_setting {
  var $id;

  function __construct($id = NULL){
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'theme';
    }
  }

  function form($space, $value = array()){
  	if(is_string($value)) $value = array('maintheme' => $value); //Backwards Compatibility
  	
    ctools_include('dependent');
    ctools_include('form');
    
    // all the enabled themes
    vsite_include('vsiteapi');
    $enabled = vsite_vsite_themes();
    if (count($enabled) > 0) {
      ksort($enabled);
    }
    
    $form = array('#title' => 'Theme', '#theme' => 'vsite_design_theme_form'); 
    
    $options = array(); //Radio Options
 
    foreach ( $enabled as $theme_obj ) {
      $info = $theme_obj->info;
      $info['theme_name'] = $theme_obj->name;
      
      if (isset($info['theme_flavor']) && is_array($info['theme_flavor'])) {
        $form[$info['theme_name'] . '_flavor'] = array(
          '#type' => 'select', 
          '#title' => 'Flavor', 
          '#options' => $info['theme_flavor'], 
          '#default_value' => $value['flavor'] ? $value['flavor'] : '', 
          '#process' => array(
            'ctools_dependent_process' 
          ), 
          '#dependency' => array(
            'radio:settings[theme][maintheme]' => array(
              $info['theme_name']
            ) 
          ) 
        );
      }
      
      $options[$info['theme_name']] = $info['theme_name'];
    }
    
    $form['maintheme'] = array(
      '#enabled_themes' => $enabled,
      '#type' => 'radios', 
      '#options' => $options, 
      '#default_value' => $value['maintheme'] ? $value['maintheme'] : 'scholar_theme_01', 
      '#tree' => TRUE 
    );
    
    $form['#prefix'] = theme('vsite_design_theme_subnav', count($enabled));

    return $form;
  }

  function validate($space, $value){

  }

  function submit($space, $value){
    $save = array(
      'maintheme' => $value['maintheme'],
      'flavor' => $value[$value['maintheme'] . '_flavor'],
    );

    $space->group->og_theme = $save['maintheme'];
    spaces_save($space);
    return $save;
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


