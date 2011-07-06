<?php

/**
 * @file
 * The class for "list" type widgets.  It allows users to define widgets that are 
 * list of posts (i.e. latest anouncements, blogs etc).
 * It's simply an interface to an existing view (as in views module)
 */

class os_simpleviews_boxes_listing extends os_boxes_default {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = simpleviews_get_edit_form();
    $options += parent::options_defaults();


    //$options['number_of_items'] = 8; //@todo whats a good default ?
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    
    $form = os_simpleviews_get_edit_form();
    
    $form += parent::options_form();
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    //if (notincache()){
      //$output = ...
      // set in cache
    //}
    //else {
      // get from cache
    //}
    
    $simpleview = $this -> options;
    $view = os_simpleviews_build_view($simpleview);

    $view->init();
    $view->set_display('default');

    $block = parent::render();
    $block['content'] = $view->execute_display();
    return $block;
  }

}


