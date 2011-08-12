<?php

/**
 * @file
 * The box class for "Twitter feed" type widgets.  
 */

class os_boxes_twitterfeed extends os_boxes_default {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();
    
    // the default value for the form
    $options['twitter_username'] = 'scholar_harvard';  //@todo remove just to test
    $options['followme_link'] = 0;
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    
    $form['twitter_username'] = array(
      '#type' => 'textfield', 
      '#title' => t('Twitter username'),  
      '#required' => TRUE,
      '#default_value' => $this->options['twitter_username']
    );
    
    $form['followme_link'] = array(
      '#type' => 'checkbox', 
      '#title' => t('Inlcude a "follow me link"'),  
      '#default_value' => $this->options['followme_link']
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
    
	//if(!($vsite = vsite_get_vsite()) || !$vsite->access_feature($op = 'view', 'scholar_reader')) return array();
	
	// settings values
    $twitter_username = $this->options['twitter_username'];
    $followme_link = $this->options['followme_link'];


	$output = twitter_pull_render ($twitter_username);
	
	// include a followme link
	if ($this->options['twitter_followme'] !== 0) {
      $output .= '<div class="twitter-followme">' . l('Follow me on Twitter','http://twitter.com/' . $twitter_username) .'</div>';
	}

    $block['content'] = $output;
    return $block;
  }

}