<?php

/**
 * @file
 * The class for "CC license" type widgets.  
 */

class os_boxes_cclicense extends os_boxes_default {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    //$options['license_type'] = 'cc';
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    
    $form['license_type'] = array(
      '#type' => 'select', 
      '#title' => t('License Type'), 
      '#options' => array(
        'cc' => t('cc') 
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
    $block['content'] = "CC License output";
    return $block;
  }

}