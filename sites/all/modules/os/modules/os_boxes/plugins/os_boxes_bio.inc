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
    //show more link

    $form += parent::options_form();
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    //@todo
    $block = parent::render();    
    
    if (($vsite = vsite_get_vsite()) == FALSE) {
      return array(); 
    }

    $bio_node = content_profile_load('bio', $vsite->group->uid, $lang = '');
    if(!$bio_node) {
      return array();
    }

    //won't be blurb for long.  blurb text is to be copied to a simple box instance for each user with a blurb.
    $blurb = $bio_node->field_hook_text[0]['value'];
    $output = strlen($blurb) ? $blurb : node_teaser($bio_node->body, null,400) ;
    // trim the output's length
    $output .= l(" more", $bio_node->path,array(attributes=>array('class'=>'more')));
    $block['content'] = $output;
    
    return $block;
  }

}