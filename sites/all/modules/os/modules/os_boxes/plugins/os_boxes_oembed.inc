<?php

/**
 * @file
 * The class for "Embed" type widgets.  
 */

class os_boxes_oembed extends os_boxes_default {
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
    
    $form['oembed_url'] = array(
      '#type' => 'textbox', 
      '#title' => t('Oembed URL'),  
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
    $block['content'] = "Oembed output";
    return $block;
  }

}