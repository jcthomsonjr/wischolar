<?php

function scholar_get_features_info($form_state, $url){
  
  module_load_include('inc', 'features','features.admin');
  $form = array();
  
  $form['#action'] = $url;
  $form['#redirect'] = FALSE;
  
  module_load_include('inc', 'features', 'features.export');
  
  $form['status'] = array(
    '#tree' => TRUE,
  );
  
  // Generate features form.
  foreach (features_get_features('', TRUE) as $name => $module) {

    
    $form['status'][$name] = array(
      '#type' => 'checkbox',
      '#title' => $module->info['name'],
      '#description' =>  $module->info['description'],
      '#default_value' => $module->status,
      '#disabled' => FALSE,
    );
  }
  
  
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Enable features'),
  );
  
  return $form;
}

/**
 * Submit function; enable features (modules) selected by 
 * the administrator
 */
function scholar_get_features_info_submit(&$form, &$form_state){
  variable_set('scholar_features', TRUE);
   $features = $form_state['values']['status'];

   //$modules = array_keys($features);

   foreach ($features as $name => $value) {
      if ($value) {
      module_enable(array($name));

      // Make sure the install API is available.
      include_once './includes/install.inc';
      drupal_install_modules(array($name));
      }
   }
}