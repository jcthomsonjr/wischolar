<?php


/**
 * Find and return the custom Primary Links in the old site
 *
 * @param unknown_type $old
 * @return unknown
 */

function simport_get_menu_links($old){

  $custom_links = array();

  if (is_array($old -> scholar_menu_links) && count($old -> scholar_menu_links)){
    foreach($old -> scholar_menu_links as $link){
     $pattern = '/(^node)\/([0-9]+)$/';
            
      preg_match($pattern,$link['path'], $matches);
      if(!empty($matches)){
        $custom_links[] = array(
        'nid' => $matches[2],
        'title' => $link['title'],
        'path' => $link['path'],
        'primary' => 1,
        );
      }
    }
  }
  return $custom_links;
}

/**
 *  Load menu info and save node
 *
 * @param unknown_type $link
 * @param unknown_type $nid
 * @param unknown_type $primary
 */
function simport_add_custom_menu_links($link, $nid, $primary = 1){
  $node = node_load(array('nid' => $nid));
 
  $node -> menu  = array(
  'mlid' => 0,
  'module' => menu,
  'has_children' => 0,
  'customized' => 0,
  'options' => array(),
  'expanded' => 0,
  'parent_depth_limit' => 8,
  'link_title' => $link['title'],
  'parent' => ($primary = 1) ? 'features:0' : 'scholar_secondary_menu:0',
  'weight' => 0,
  'plid' => 0,
  'menu_name' => ($primary = 1) ? 'features' : 'scholar_secondary_menu',
  );
 
  //save the menu link
  node_save($node);
}




