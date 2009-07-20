<?php

/**
 * Form to display cite_distribute widgets
 *
 * @param unknown_type $nid
 * @return unknown
 */
function cite_distribute_form($form, $nid){
  $submodules = cite_distribute_installed_mods();
  
  $form['cite_distribute_widgets'] = array(
  '#type' => 'fieldset',
  '#title' => t('Select repositories for distribution'),
  '#collapsible' => FALSE,
  '#collapsed' => FALSE,
  );
  
  foreach ($submodules as $module){
    $form['cite_distribute_widgets'][$module['name'] . '_module'] = array(
    '#type' => 'checkbox',
    '#title' => t('@repos', array('@repos' => $module['repository'])),
    '#default_value' => '',// TODO: need to query the cite_distribute table to get this value
    );
  }

  $form['cite_distribute_widgets']['nid'] = array(
  '#type' => 'hidden',
  '#value' => $nid,
  );

  $form['cite_distribute_widgets']['cite_distribute_submit'] = array(
  '#type' => 'submit',
  '#value' => t('Submit'),
  );

  return $form;  
}

/**
 * Submit functon for cite_distribute_get_formlink
 */
function cite_distribute_form_submit($form, &$form_state){ print 'submit'; die;
  $nid =  $form_state['values']['nid'];

  foreach ($form_state['values'] as  $name => $value){
    if (strpos($name, '_module') && $value == 1){
      $module_name = trim(str_replace('_module', '', $name));
      
      //load flag each repository selected
      $flag = flag_get_flag($module_name);

      //set the flag for this node
      $flag->flag('flag', (int)$nid);
    }
  }
}
