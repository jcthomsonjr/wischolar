<?php
/**
 * Form Controlls
 */


/*
 * The CP form for saving the block values and thier order
 */
function vsite_menus_settings_form($form_state){
  
  $space = vsite_get_vsite();
  if(!$space) return array();
  
  // just do have distinct id for each setting form
  $form['#prefix'] = '<div id = "cp-settings-menus">';
  $form['#suffix'] = '</div>';
  
  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t(''),
    '#tree' => TRUE,
  );

  $form['settings']['layout'] = array('#title' => 'Site Menus');


  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );
  
  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset to defaults'),
    '#submit' => array('vsite_menus_settings_form_reset'),
  );
  
  return $form;
  
}

/**
 * Include the css in after_build so that it always appears with the form, even with a cached form
 */
function vsite_menus_settings_form_after_build($form, &$form_state) {
  //CSS To be included with the form
  drupal_add_css(drupal_get_path('module', 'vsite_menus') . '/theme/vsite_menus.css');
}

/**
 * Reset function for the CP blocks form to return the settings for the current theme to defaults
 */
function vsite_menus_settings_form_reset($form, &$form_state) {
  $space = vsite_get_vsite();
  if(!$space) return;
  
//  foreach (array_keys(vsite_layout_get_pagetypes($space)) as $s_page_type) {
//    $space->controllers->context->del('openscholar-feature-'.$s_page_type.":reaction:block:".$space->group->og_theme);
//  }
}

/**
 * Save Handler for the CP Menus Form
 */
function vsite_menus_settings_form_submit($form, &$form_state) {
  $space = vsite_get_vsite();
  if(!$space) return;
  
  
}
