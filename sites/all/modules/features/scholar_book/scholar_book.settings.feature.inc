<?php

/**
 * scholar_book feature settings
 */
class scholar_book_settings_feature implements space_setting {
  
  var $id;

  function __construct($id = NULL){
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'scholar_book';
    }
  }

  function form($space, $value = array()){
    $form['scholar_book_toc_location'] = array(
      '#type' => 'checkbox', 
      '#title' => t('Table of content location'), 
      '#default_value' => isset($value['scholar_book_toc_location']) ? $value['scholar_book_toc_location'] : 0,
      '#description' => t('Check if you want the booklet\'s table of contents in the content area of the page'),
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