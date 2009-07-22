<?php 
/**
 * Hook for the admin module
 * for the form builder
 */
function berkley_contrib_lookup_admin_settings() {

  $form = array();
  
   $form['berkley_contrib_lookup_allow_autocomplete'] = array(
    '#type' => 'checkbox',
    '#title' => t('Lookup via autocomplete'),
    '#default_value' => 0,
    '#return_value' => 1,
    '#description' => t('Should the search of the berkly be user initiated or automatic via the autocomplete field.')
  );
   
   return system_settings_form($form);
}