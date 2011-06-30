<?php

/**
 * @file
 * The class for "CC license" type widgets.  
 */

class os_boxes_feedreader extends os_boxes_default {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    
    $form['feed'] = array(
      '#type' => 'select', 
      '#title' => t('Feed'), 
      '#options' => array(
        'all' => t('All') 
      ), 
      '#required' => TRUE,
    );

    $form += parent::options_form();
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    //@todo
    $block = parent::render();
    $block['content'] = "Feed reader output";
    return $block;
  }

}