<?php

function vsite_news_activity_settings_form(){
  $form = array();
  
  $form['vsite_activity_insert'] = array(
      '#type' => 'radios',
      '#title' => "Should an activity be recorded when you create a post?",
      '#options' => array(1 => t('Record an activity message'), 0 => t('Do not record')),
      '#default_value' => variable_get('vsite_activity_insert',1),
  );
  $form['vsite_activity_update'] = array(
      '#type' => 'radios',
      '#title' => "Should an activity be recorded when you update a post?",
      '#options' => array(1 => t('Record an activity message'), 0 => t('Do not record')),
      '#default_value' => variable_get('vsite_activity_update',1),
  );
  
  if (variable_get('vsite_private', 0)){
       $form['info'] = array(
         '#type' => 'item',
         '#description' => "Note: Your site is private and activity messages will not be recorded untill your site becomes public.",
       );
  }

  return system_settings_form($form);
}
