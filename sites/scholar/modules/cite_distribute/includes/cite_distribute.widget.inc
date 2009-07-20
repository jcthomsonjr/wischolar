<?php

/**
 * theme_cite_distribute_formlink()
 * themable title link
 */
function theme_cite_distribute_get_formlink($object){
  $output = '<a href="#cite-distribute-link-title" id="cite-distribute-link-title">Distribute</a>'; // l
  $output .= '<div class = "distribute-form-wrapper">' . drupal_get_form('cite_distribute_form', $object->nid). '</div>';
  return $output;
}
