<?php

/**
 * Present a form for setting
 */
function simport_settings_form(&$form_state){
 
  $form['current_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Current Path'),
    '#default_value' => variable_get('simport_current_path', ''),
    '#description' => t('Absolule file system path to the current web site root.'),
    '#required' => TRUE,
  );

  $form['remote_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Remote Path'),
    '#default_value' => variable_get('simport_remote_path', ''),
    '#description' => t('Absolule file system path to the remote web site root.'),
    '#required' => TRUE,
  );

  $form['run_import'] = array(
    '#type' => 'checkbox',
    '#title' => t('Run Import Process'),
    '#default_value' => isset($form_state['post']['run_import']) ? 1: 0,
    '#description' => t('Check this box to run the import process'),
  );
  
   $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
 
  return $form;
}

function simport_settings_form_submit(&$form_state, $form){
  $paths = array(
  'current_path' => $form_state['current_path']['#value'],
  'remote_path' => $form_state['remote_path']['#value'],
  );
  
//remove trailing slash if necessary
 foreach ($paths as $key => $val) {
    if (substr($val, -1) == '/'){ 
            $new_val = substr($val, 0, -1);
            variable_set('simport_' . $key, $new_val);
    }    
    else{           
     variable_set('simport_' . $key, $val);
    }
  }
  
  if ($form_state['run_import']['#value'] == 1){
  //now call script to import site
  //simport_import();

  //TODO: include log or stats regarding import
  drupal_set_message(t('Import Completed'));
    }
 }