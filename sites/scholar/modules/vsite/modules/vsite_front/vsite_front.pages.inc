<?php

/**
 * Menu callback for "home"
 * Get the vsite home page settings and act accordingly
 * @return the content to be rendered in the content area of the front page
 */
function vsite_front_home(){
  
  $vsite = scholar_get_scholar();
  if ($vsite) {
    $front_type = $vsite->settings['front']['frontpage'];
    switch ($front_type) {
      case 'bio' :
        $bio_nid = $vsite->settings['bio']['nid'];
        $result = vsite_front_home_bio($bio_nid);
        break;
      case 'feature' :
        $node_options = $vsite->settings['front']['node_options'];
        $result = vsite_front_home_feature($node_options);
        break;
      case 'html' :
        $front_nid = $vsite->settings['front']['front_nid'];
        $result = vsite_front_home_html($front_nid);
        break;
      case 'flag' :
        $result = vsite_front_home_flag();
        break;
    }
    return $result;
  }
}

/**
 * if front page is set to bio
 * @param $bio_nid the nid of the bio node
 */
function vsite_front_home_bio($bio_nid){
  $node = node_load($bio_nid);
  // TODO "include title" option not implemented here
  $result = node_view($node, $teaser = FALSE, $page = FALSE, $links = FALSE);
  return $result;
}


/**
 * if front page is set to "features" 
 * @param $node_options array of node types users want to be promoted to the front page
 */
function vsite_front_home_feature($node_options){

  //initialize the scholar base view
  $view = views_get_view('scholar_view_base');
  
  // add a filter for "node types" in the view
  $options = array();
  foreach($node_options as $o){
    $options[$o] = $o; // that's how views wants it
  }
  
  $view -> display['default'] -> display_options['filters']['type'] = array(
    'operator' => 'in',
    'value' => $options,

    'group' => 0,
    'exposed' => FALSE,
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'relationship' => 'none',
  );
  $view->init();
  $view->set_display('default');


  $view -> execute();
  return $view -> render();

}

/**
 * if front page is set to "html" 
 * @param $front_nid the nid of the node 
 */
function vsite_front_home_html($front_nid){
  $node = node_load($front_nid);
  $result = node_view($node, $teaser = FALSE, $page = FALSE, $links = FALSE);
  return $result;
}

/**
 * if front page is set to "flag" 
 */
function vsite_front_home_flag(){
  return views_page("scholar_frontpage", "default");
}