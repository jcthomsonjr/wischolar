<?php

function vsite_ga_settings_form(){
  $form = array();

  $form['vsite_ga_global_id'] = array(
  '#type' => 'textfield',
  '#title' => t('Enter your Google Analytics ID'),
  '#size' => 20,
  '#maxlength' => 255,
  '#default_value' => variable_get('vsite_ga_global_id', ''),
  '#description' => "Entering your ID this will enable the sending of your OpenScholar sitewide page and visitor data to your Google Analytics account.",
  );

  return system_settings_form($form);
}