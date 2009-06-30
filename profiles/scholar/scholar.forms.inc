<?php



function scholar_get_features_info($form_state, $url){
  
  module_load_include('inc', 'features','features.admin');
  $form = array();
  
  $form['#action'] = $url;
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
  );
  
  return $form;
}

function scholar_get_features_info_submit(&$form, &$form_state){
  variable_set('scholar_features', TRUE);
   $features = $form_state['values']['feature'];
   $modules = array_keys($features);
   //$i = 0;
   //foreach ($features as $name => $feature) {
      //variable_set($name . $i, $i);
      module_enable($modules);

      // Make sure the install API is available.
      include_once './includes/install.inc';
      drupal_install_modules($modules);
   //}
}