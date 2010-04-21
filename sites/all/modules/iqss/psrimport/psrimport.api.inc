<?php

/** API Funciton and utilities **/

/**
 * Add a node to an OG
 */
function psrimport_node_to_og($nid){
  $sid = psrimport_get_sid();
  
if(!$sid){  
  $account = user_load(array('name' => 'pmoynihan'));
  if($spaces = vsite_get_vsite_by_owner($account -> uid)){
  if(!$sid = $spaces[0] -> group -> nid) psrimport_print("Error: Could not obtain SID when trying to add node to og"); 
  }
}
if($sid){  
    db_query("DELETE FROM {og_ancestry} WHERE nid = %d AND group_nid = %d", $nid, $sid);
    db_query("INSERT INTO {og_ancestry} (nid, group_nid) VALUES (%d, %d)", $nid, $sid);
  }
}

/**
 * Get the psr site id
 */
  function psrimport_get_sid(){
  db_set_active('default');
  if (PSR_SID) return PSR_SID;
  $account = user_load(array('name' => 'pmoynihan'));
  if($spaces = vsite_get_vsite_by_owner($account -> uid)){
    return $spaces[0] -> group -> nid;
  }
  return false;
}

/**
 * Abstraction function to print real time feedback
 * and to prevent errors if script is not run with drush
 */
function psrimport_print($text){
  switch(PSR_DRUSH_RUN){
    case 0;
    return print (t("$text"));
    break;

    case 1:
      return drush_print (t("$text"));
      break;

    default:
      return print (t("$text"));
      break;
  }
}