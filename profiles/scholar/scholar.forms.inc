<?php



function scholar_get_features_info($form_state, $url){
  $form = array();
  //$form['#action'] = $url;
  $form['#redirect'] = FALSE;
  
  module_load_include('inc', 'features', 'features.export');
  
  $form['feature'] = array(
    '#tree' => TRUE,
  );
  
  // Generate features form.
  foreach (features_get_features('', TRUE) as $name => $module) {
    $form['feature'][$name] = array(
      '#type' => 'value',
      '#value' => $module,
    );
    
    $form['status'][$name] = array(
      '#type' => 'checkbox',
      '#title' => $module->info['name'],
      '#description' => 'some descirption', // $description,
      '#default_value' => $module->status,
      '#disabled' => FALSE,
    );
  }
  
  
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Enable features'),
    //'#validate' => array('features_form_validate'),
  );
  print_r($form);
  return $form;
}

function scholar_get_features_info_submit(&$form, &$form_state){
  variable_set('xxxxxxxxxxxx' , 22);
   print_r($form_state);
   $features = $form_state['values']['feature'];
   
   foreach ($features as $name => $feature) {
      module_enable($name);

      // Make sure the install API is available.
      include_once './includes/install.inc';
      drupal_install_modules($name);
   }
}