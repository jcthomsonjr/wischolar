<?php

/**
 * scholar_dvn feature settings
 */
class scholar_biocv_settings_feature implements space_setting {
  
  var $id;

  function __construct($id = NULL){
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'scholar_biocv';
    }
  }

  function form($space, $value = array()){
    
    $form['use_pdf_as_cv'] = array(
        '#type' => 'checkbox',
        '#weight' => -10,
        '#title' => t('Use PDF upload as your CV'),
        '#default_value' => (is_array($value) && array_key_exists('use_pdf_as_cv',$value))?$value['use_pdf_as_cv']:0,
        '#description' => t('When this is checked the pdf you upload will be displayed on the cv section of your site.'),
      );
    return $form;
  }

  function validate($space, $value){
    
  }

  function submit($space, $value){
  	//Boolean
    $value['use_pdf_as_cv'] = !!$value['use_pdf_as_cv'];
  	
    return $value;
  }
}