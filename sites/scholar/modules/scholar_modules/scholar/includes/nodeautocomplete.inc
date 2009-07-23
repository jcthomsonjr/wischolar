<?php

/**
 * API function which construct an autocomplete node field
 * TODO caller should be able to override the element attributes
 * not just the title
 */
function scholar_node_autocomplete_element($title = NULL){
  $item = array(
    '#type' => 'textfield',
    '#title' => $title ? $title : t('Select a node'),
    '#maxlength' => 80,
    '#autocomplete_path' => 'scholar/node/autocomplete', 
    '#element_validate' => array('scholar_node_autocomplete_validate'),
  );
  
  return $item;
}

/**
 * schlar nodeautocomplete callback function
 */
function scholar_node_autocomplete($str){

  //initialize view to generate sessions output when viewing a conference
  $view = views_get_view('scholar_autocomplete');
  $view->init();

  $view->set_display('default');
  $view -> set_items_per_page(0);
  $view -> execute();
  foreach ($view -> result as $node){
    if(stristr($node -> node_title, $str)){
     $matches[$node -> node_title. ' [nid:' . $node->nid . ']'] = check_plain($node -> node_title);
    }
  }

  print drupal_to_js($matches);
  exit();
}


function scholar_node_autocomplete_validate($element, &$form_state){
  $element_value = $element['#value'];
  if ($element_value){
    preg_match('/^(?:\s*|(.*) )?\[\s*nid\s*:\s*(\d+)\s*\]$/', $element_value, $matches);
    
    if (!empty($matches)) {
      $form_state['scholar_referenced_nid'] = $matches[2];
    }
    else {
      form_error($element, t('This post is not valid'));
    }
  }
}