<?php 

function scholar_settings_form(){
 
  $a_menus = menu_get_menus();
  
  $form = array();
  
  $form['scholar_content_type'] = array(
    '#type' => 'select',
    '#options' => og_get_types('group'),
    '#title' => t('Node type'),
    '#default_value' => variable_get('scholar_content_type', 'scholarsite'),
    '#description' => t("Choose a og content type which represent a scholar site"),
  );
  
  $form['scholar_primary_menu'] = array(
    '#type' => 'select',
    '#title' => t('Primary Menu'),
    '#default_value' => variable_get('scholar_primary_menu',key($a_menus)),
    '#options' => $a_menus,
    '#description' => t('The primary menu displayed along the top of scholar site.  Defaults are pulled from here and each site can be configured independently.')
  );
  
  $form['scholar_secondary_menu'] = array(
    '#type' => 'select',
    '#title' => t('Secondary Menu'),
    '#default_value' => variable_get('scholar_secondary_menu',key($a_menus)),
    '#options' => $a_menus,
    '#description' => t('The secondary menu displayed on a scholar site.  Defaults are pulled from here and each site can be configured independently.')
  );

  return system_settings_form($form);
}