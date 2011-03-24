<?php

/**
 * Implementation of hook_spaces_registry_alter().
 */
function vsite_layout_spaces_registry_alter(&$registry) {
  
  //Use our own context controller
  if(isset($registry['controllers']['context'])){
    $registry['controllers']['context']['plugin'] = "spaces_controller_vsite_context";
  }
}



/**
 * Implementation of hook_spaces_plugins().
 */
function vsite_layout_spaces_plugins() {
  $plugins = array();
 
  $plugins['spaces_controller_vsite_context'] = array(
    'handler' => array(
      'path' => drupal_get_path('module', 'vsite_layout') .'/plugins',
      'file' => 'spaces_controller_vsite_context.inc',
      'class' => 'spaces_controller_vsite_context',
      'parent' => 'spaces_controller_context',
    ),
  );
  return $plugins;
}
