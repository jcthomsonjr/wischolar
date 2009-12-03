<?php

function vsite_ga_settings_form(){
  $form = array();

  $form['vsite_ga_global_id'] = array(
  '#type' => 'textfield',
  '#title' => t('Enter your Google Analytics ID'),
  '#size' => 20,
  '#maxlength' => 255,
  '#default_value' => variable_get('vsite_ga_global_id', ''),
  '#description' => "Entering your ID this will enable the sending of Scholars' Web Sites Project page and visitor data to your Google Analytics account.",
  );

  $form['vsite_ga_cache'] = array(
  '#type' => 'checkbox',
  '#title' => t('Cache the ga.js file Locally (Recommended)'),
  '#default_value' => variable_get('vsite_ga_cache', 1),
   '#description' => t('Cacheing the ga.js locally may improve overall page loading speeds')
  );
  return system_settings_form($form);
}