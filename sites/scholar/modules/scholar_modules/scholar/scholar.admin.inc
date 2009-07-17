<?php 

function scholar_settings_form(){
  $form = array();
  
  $form['scholar_content_type'] = array(
    '#type' => 'select',
    '#options' => og_get_types('group'),
    '#title' => t('Node type'),
    '#default_value' => variable_get('scholar_content_type', 'scholarsite'),
    '#description' => t("Choose a og content type which represent a scholar site"),
  );

  return system_settings_form($form);
}