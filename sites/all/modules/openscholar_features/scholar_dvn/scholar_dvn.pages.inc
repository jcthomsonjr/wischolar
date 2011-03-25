<?php

function scholar_dvn_settings(){
  $base_url = 'http://dvn.iq.harvard.edu/dvn/dv/';
  $form['dvn_alias'] = array(
    '#type' => 'textfield', 
    '#title' => t('Dataverse alias'), 
    '#field_prefix' => $base_url, 
    '#default_value' => variable_get('dvn_alias', ''),
    '#size' => 60, 
    '#maxlength' => 128, 
    '#required' => TRUE 
  );
  
  $form['dvn_next_steps'] = array(
    '#type' => 'markup', 
    '#title' => t('Next Steps'), 
    '#value' => '<h3>Next Steps: </h3><span class="field-prefix">To complete embedding the Dataverse in this OpenScholar site, go to your Dataverse Options, click Edit Layout Branding and select "Disable customization if Dataverse is embedded in an OpenScholar site</span>' 
  );
  
  return system_settings_form($form);
}