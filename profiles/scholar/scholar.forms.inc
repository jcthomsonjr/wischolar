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
    if (substr($module -> info['name'],0,7) === 'scholar'){
      $form['status'][$name] = array(
        '#type' => 'checkbox',
        '#title' => $module->info['name'],
        '#description' =>  $module->info['description'],
        '#default_value' => 1, //$module->status,
        '#disabled' => FALSE,
      );
    }
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
      
      //drupal_flush_all_caches();
      // the above will disable all themes
      // try this
      $core = array('cache', 'cache_block', 'cache_filter', 'cache_page');
      $cache_tables = array_merge(module_invoke_all('flush_caches'), $core);
      foreach ($cache_tables as $table) {
        cache_clear_all('*', $table, TRUE);
      }
      
      }
   }
}


// content generation form (from devel)

function scholar_generate_content_form($form_state, $url) {
  module_load_include('inc', 'devel','devel.generate');

  $form = devel_generate_content_form();
  $form['#action'] = $url;
  $form['#redirect'] = FALSE;
  
  $form['node_types']['#options'] = array
                (
                    'blog' => 'blog',
                    'announcement' => 'announcement',
                    'link' => 'link'

                );
  
  $form['max_comments']['#default_value'] = 10;
               
  $form['kill_content'] = array(
    '#type' => 'value',
    '#value' => FALSE,
  );
  
  $form['#submit'][] = 'devel_generate_content_form_submit';
  
  return $form;
}

