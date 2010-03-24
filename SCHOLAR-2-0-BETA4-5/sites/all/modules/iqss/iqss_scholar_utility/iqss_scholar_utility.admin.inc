<?php


function iqss_scholar_utility_form(){  
  // variable_set('iqss_scholar_utility_submit', 0); //for dev only should remove this
  
    $form['iqss_scholar_utility_info'] = array(
    '#type' => 'item',
    '#description' => t('Run this utility script to import biblio node values within Other Biblio Fields into cck biblio extra fields'),
  );
  
  if (variable_get('iqss_scholar_utility_submit', 0) !== 1){
  $form['iqss_scholar_utility_submit'] = array(
    '#type' => 'submit',
    '#value' => 'Run Script',
  );
  }
   else{
    drupal_set_message(t('The utility script has already ran and can only be run once.'));
  }
  
  return $form;
 }

 function iqss_scholar_utility_form_submit($form, &$form_state){
   variable_set('iqss_scholar_utility_submit', 1);
   //run utility update script
   iqss_scholar_utility_other_biblio_fields();
   drupal_set_message(t('The utility script has compeleted'));
 }