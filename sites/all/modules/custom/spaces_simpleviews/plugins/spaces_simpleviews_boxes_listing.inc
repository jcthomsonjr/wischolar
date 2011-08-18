<?php

/**
 * @file
 * The class for "list" type widgets.  It allows users to define widgets that are 
 * list of posts (i.e. latest anouncements, blogs etc).
 * It's simply an interface to an existing view (as in views module)
 */

class spaces_simpleviews_boxes_listing extends boxes_box {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = spaces_simpleviews_default_data();
    //$options += parent::options_defaults();


    //$options['number_of_items'] = 8; //@todo whats a good default ?
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    
    $form = spaces_simpleviews_get_edit_form($this->options);
    
    //$form += parent::options_form();
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
    $view = spaces_simpleviews_build_view($simpleview);

    $view->init();
    $view->set_display('default');

    $title = isset($this->title) ? check_plain($this->title) : NULL;
    $block = array(
      'title' => $title,
      'subject' => $title,
      'delta' => $this->delta,
      'content' => $view->execute_display(),
    );
    
    return $block;
  }

}


