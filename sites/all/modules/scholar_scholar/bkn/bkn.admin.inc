<?php 
/**
 * Hook for the admin module
 * for the form builder
 */
function bkn_admin_settings() {

  $form = array();
  
   $form['bkn_allow_autocomplete'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Autocomplete'),
    '#default_value' => variable_get('bkn_allow_autocomplete',1),
    '#return_value' => 1,
    '#description' => t('Should contributor field use autocomplete?')
  );
  $form['bkn_mode'] = array(
    '#type' => 'radios',
    '#title' => t('How should the data be retrieved from BKN?'),
    '#default_value' => variable_get('bkn_mode', 2),
    '#options' => array(t('Lookup via autocomplete (many requests to bkn)'), t('User Initiated (single request)'), t('Disabled')),
  );
   
   return system_settings_form($form);
}
