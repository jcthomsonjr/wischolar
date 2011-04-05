<?php
function scholar_reader_settings($vsite) {

  $form = array(
    '#title' => 'Feed Settings'
  );

  $form['scholar_reader_twitter_username'] = array(
    '#title' => t('Twitter Feed'),
    '#type' => 'textfield',
    '#default_value' => variable_get('scholar_reader_twitter_username', ''),
    '#description' => "To pull your Twitter posts into your site add your username to the above field (examples: '@username' says show all the tweets I have posted, 'from:username' says pull all the tweets and retweets I have sent, '#harvard_scholar' says pull anything tagged harvard_scholar). Once this setting is saved, you can place the Twitter widget anywhere on your site by clicking the layout."
  );

  return system_settings_form($form);
}