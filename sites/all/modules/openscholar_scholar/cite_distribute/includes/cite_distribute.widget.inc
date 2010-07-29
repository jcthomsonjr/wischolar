<?php

/**
 * theme_cite_distribute_formlink()
 * themable title link
 */
function theme_cite_distribute_get_formlink($object){
  $output = '<span class="disto-toggle">Distribute</span>';
  $output .= '<ul class = "distribute-form-wrapper slider"><li>' . drupal_get_form('cite_distribute_form', $object->nid). '</li></ul>';
  return $output;
}

/**
 * Themable function to generate message after user submits
 *  cite_distribute widget selections
 *
 * @param unknown_type $modules
 * @return unknown
 */
function theme_cite_distribute_form_msg($modules = NULL){
  //determine whether to add 's' to the end of citatation(s)
    $s = count($modules) > 1 ? 's' : '';

    if($modules){
    $output = '<dl id="cite-distribute-submit-message">';
    $output .= '<dt>Submitted citatation' .  $s . ' to:</dt>';
    foreach ($modules as $module){
      //getting information about the module
      $info = module_invoke($module, 'cite_distribute_register');
      $output .= '<dd>' . $info[0]['repository'] . '</dd>';
    }
    $output .= '</dl>';
  }

  else{
    $output = 'No repositories selected';
  }
  return $output;
}