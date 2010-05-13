<?php

/**
 * Provides scholar_reader settings for each site
 */
class scholar_reader_settings_reader implements space_setting {
  var $id;

  function __construct($id = NULL){
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'reader';
    }
  }

  function form($vsite, $value = array()){
    
    $form = array(
      '#title' => 'Feed Settings'
    );

    if(!$vsite) return $form;

    $form['twitter_username'] = array(
      '#title' => t('Twitter Feed'),
      '#type' => 'textfield',
      '#default_value' => isset($value['twitter_username']) ? $value['twitter_username'] : '',
      '#description' => "If you have your twitter username set then a widget will become avalible with your latest tweets.  If you put a hashtag ie.(#openscholar) then the feed will alternativly include everything with that tag.  You can place this anywhere on your site."
    );

    return $form;
  }

  function validate($vsite, $value){
    
    return $value;

  }

  function submit($vsite, $value){
    
  	return $value;
  }
}

