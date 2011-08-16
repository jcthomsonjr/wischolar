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

    $options['license_type'] = '';
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){

    $form['license_type'] = array(
      '#type' => 'select',
      '#title' => t('License Type'),
      '#options' => creativecommons_get_available_license_list(),
      '#default_value' => $this->options['license_type'],
    	'#attributes' => array('class' => 'creativecommons creativecommons-license-select'),
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