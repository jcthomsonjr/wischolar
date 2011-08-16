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

    $options['selection'] = FALSE;
    $options['oembed_url'] = '';
    $options['pasted'] = '';

    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){

    $form['selection'] = array(
      '#title' => t('Use: '),
      '#type' => 'radios',
      '#options' => array(
        'oembed_url' => t('Embed.ly Provider URL'),
        'pasted' => t('Original embed code.')
      ),
      '#default_value' => $this->options['selection'],
      '#description' => t('Which source do you want to use?'),
    );

    $form['oembed_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Embed.ly Provider URL'),
      '#default_value' => $this->options['oembed_url'],
    );

    $form['pasted'] = array(
      '#type' => 'textarea',
      '#title' => t('Original Embed Code'),
      '#default_value' => $this->options['pasted'],
      '#description' => embedfilter_filter_tips(0, 1),
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
    switch ($this->options['selection']) {
      case 'oembed_url':
        $block['content'] = oembed_filter('process', 0, -1, $this->options['oembed_url']);
      break;
      case 'pasted':
        $block['content'] = embedfilter_filter('process', 0, -1, $this->options['pasted']);
      break;
    }
    $block['content'] = embedfilter_media_resize($block['content'], 200);
    return $block;
  }

}