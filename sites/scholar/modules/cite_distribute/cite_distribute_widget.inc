<?php

/**
 * theme_cite_distribute_formlink()
 * themable form for cite_distribute widgets
 *
 */
function theme_cite_distribute_get_formlink($submodules = NULL, $nid){

  $form['cite_distribute_widgets'] = array(
  '#type' => 'fieldset',
  '#title' => t('Distribute'),
  '#collapsible' => FALSE,
  '#collapsed' => FALSE,
  );
  
  foreach ($submodules as $module){
    $form['cite_distribute_widgets'][$module['name']] = array(
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