<?php

/**
 * @file
 * The class for "CC license" type widgets.  
 */

class os_boxes_bio extends os_boxes_default {
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
    $form['bio'] = array();
    /*
      '#type' => 'select', 
      '#title' => t('License Type'), 
      '#options' => array(
        'cc' => t('cc') 
      ), 
      '#required' => TRUE,
    );*/
    //options to include cv?

    $form += parent::options_form();
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    //@todo
    $block = parent::render();
    $blurb = scholar_biocv_bio_blurb_content();//'new bio block<br /><Br />'.$s_out;
    if ($blurb['content']) {
      $block['content'] = $blurb['content'];
    } else {  
      $block['content'] = '';
    }
    return $block;
  }

}