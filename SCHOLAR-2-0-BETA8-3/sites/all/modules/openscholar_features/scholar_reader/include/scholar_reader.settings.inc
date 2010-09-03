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
      '#description' => "To pull your Twitter posts into your site add your username to the above field (examples: '@username' says show all the tweets I have posted, 'from:username' says pull all the tweets and retweets I have sent, '#harvard_scholar' says pull anything tagged harvard_scholar). Once this setting is saved, you can place the Twitter widget anywhere on your site by clicking the layout."
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

