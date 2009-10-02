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
    //  $pattern = '/^node\/'. $old->nid . '\//';
      $pattern = '/(^node)\/(\d+)\/$/';
            
      preg_match($pattern,$link['path'], $matches);
      if(empty($matches)){
        $custom_links[] = array(
        'nid' => $maches[2],
        'title' => $link['title'],
        'path' => $link['path'],
        );
      }
    }
  }
  //dpm($custom_links);
  return $custom_links;
}

/**
 * This function is no longer called
 *
 * @param unknown_type $link
 * @return unknown
 */
function simport_get_menu_link_node($link){
  $exploded = explode('/', $link['path']);
  if ($exploded[0] == 'node'){
    $nid = int($exploded[1]);
    //return the node that should contain the menu link
    return node_load($nid);
  }
  else return;
}

/**
 * Add the imported custom menu links to the new vsite
 *
 * @param unknown_type $vsite
 * @param unknown_type $custom_links
 */
function simport_add_custom_menu_links($vsite, $custom_links, $node, $primary = 1){

  $node -> menu  = array(
  'mlid' => 0,
  'module' => menu,
  'has_children' => 0,
  'customized' => 0,
  'options' => array(),

  'expanded' => 0,
  'parent_depth_limit' => 8,
  'link_title' => $custom_links['title'],
  'parent' => ($primary = 1) ? 'features:0' : 'scholar_secondary_menu:0' ,

  'weight' => 0,
  'plid' => 0,
  'menu_name' => 'features',
  );
  
  //save the menu link
  node_save($node);

  $mlid = db_result(db_query("SELECT MAX(mlid) FROM {menu_links}"));
  
  //save the vsite settings
  $vsite -> settings['menus']['menu_items'][(int)$mlid] = array(
  'menu' => 'primary',
  'weight' => 100,
  );
  $vsite -> settings['menus']['primary'] = array((int)$mlid);
  spaces_save($vsite);
}