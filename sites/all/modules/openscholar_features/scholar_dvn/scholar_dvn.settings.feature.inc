<?php

/**
 * scholar_dvn feature settings
 */
class scholar_dvn_settings_feature implements space_setting {
  
  var $id;

  function __construct($id = NULL){
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'scholar_dvn';
    }
  }

  function form($space, $value = array()){
    $base_url = 'http://dvn.iq.harvard.edu/dvn/dv/';
    $form['dvn_alias'] = array(
      '#type' => 'textfield',
      '#title' => t('Dataverse alias'),
      '#field_prefix' => $base_url,
      '#default_value' => (isset($value['dvn_alias'])) ? $value['dvn_alias'] : '',
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE
    );
    
    $form['dvn_next_steps'] = array(
      '#type' => 'markup',
      '#title' => t('Next Steps'),
      '#value' => '<h3>Next Steps: </h3><span class="field-prefix">To complete embedding the Dataverse in this OpenScholar site, go to your Dataverse Options, click Edit Layout Branding and select "Disable customization if Dataverse is embedded in an OpenScholar site</span>',
    );
    return $form;
  }

  function validate($space, $value){
    // autocomplete has its own validation
  }

  function submit($space, $value){
    
    return $value;
  }
}