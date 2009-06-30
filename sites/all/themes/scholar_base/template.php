<?php

function scholar_base_preprocess_page($vars){

  $regions = array (   // TODO do this programatically
    'left' => $vars['header_left'],
    'main' => $vars['header_main'],
    'right' => $vars['header_right'],
  );
  
  $non_empty_regoins = array_filter($regions, "__scholar_base_is_empty");
  
  $my_body_classes = 'header-' . implode('-', array_keys($non_empty_regoins));
  
  $vars['body_classes'] .= " " . $my_body_classes;
  
}

function __scholar_base_is_empty($s){
  return $s ? TRUE : FALSE;
}