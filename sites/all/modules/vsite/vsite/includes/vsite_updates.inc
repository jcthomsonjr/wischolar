<?php

function vsite_update_6001() {
  $return = array();
  $t = get_t();
  
  $return[] = db_query("UPDATE {menu_custom}  SET title='%s', description = '%s' WHERE menu_name='%s'", $t('Primary menu'), $t('Primary menu for each scholar site.'), 'features');
  
  $return[] = db_query("INSERT INTO {menu_custom} (menu_name, title, description) VALUES ('%s', '%s', '%s')", 'scholar_secondary_menu', $t('Secondary menu'), $t('Side menu for each scholar site.'));
  
  return $return;
}

function vsite_update_6002() {
  $return = array("Taxonimies for the Vsite object created");
  
  _vsite_object_create_taxonomys();
  
  return $return;
}