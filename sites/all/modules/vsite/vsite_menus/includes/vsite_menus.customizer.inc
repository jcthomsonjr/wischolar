<?php 
require_once(drupal_get_path('module', 'spaces') .'/spaces.spaces.inc');

/**
 * Override Customizer for feature menus.
 */
class vsite_menus_customizer_menu extends space_customizer_menu implements space_customizer {

  public function form($space, $feature) {
    /** Remove default form **/
  }
  
  public function vsite_menu_form($space,$feature){
  	return parent::form($space,$feature);
  }
  
  
}