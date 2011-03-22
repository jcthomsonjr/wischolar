<?php
/**
 * Provides theme selection for each site
 */
class vsite_news_settings_activity implements vsite_setting {
  
  //Remove From Menu
  public $menu_name = FALSE;
  
  var $id;
  function __construct($id = NULL) {
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'activity';
    }
  }

  function form($space, $value = array()) {
    $form = array('#title' => 'Privacy Settings' );
     
    if (!is_array($value)) $value = array();
    
    $form['ignore_insert'] = array(
      '#type' => 'radios',
      '#title' => "Should an activity be recorded when you create a post?",
      '#options' => array(1 => t('Record an activity message'), 0 => t('Do not record')),
      '#default_value' => array_key_exists('ignore_insert', $value) ? $value['ignore_insert'] : 1,
    );
    $form['ignore_update'] = array(
      '#type' => 'radios',
      '#title' => "Should an activity be recorded when you update a post?",
      '#options' => array(1 => t('Record an activity message'), 0 => t('Do not record')),
      '#default_value' => array_key_exists('ignore_update', $value) ? $value['ignore_update'] : 1,
    );
  
  $a_generic_settings = $vsite->controllers->variable->get('vsite_setting_generic');
  if (is_array($a_generic_settings) && $a_generic_settings['private_vsite']){
       $form['info'] = array(
         '#type' => 'item',
         '#description' => "Note: Your site is private and activity messages will not be recorded untill your site becomes public.",
       );
    }

    return $form;
  }

  function validate($space, $value) {
    // autocomplete has its own validation
  }

  function submit($space, $value) {
    
    return $value;
  }
}
