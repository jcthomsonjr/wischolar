<?php

/**
 * Themable function to generate message after user submits
 *  cite_distribute widget selections
 *
 * @param unknown_type $modules
 * @return unknown
 */
function theme_citation_distribute_form_msg($modules = NULL){
  $plugins = _plugins();
  
  if ($modules) {
  	$out = array(); 
  	foreach ($modules as $module) {
  		$out[] = $plugins[$module]['title'];
  	}
  	return 'Submitted citation to: ' . implode(', ', $out);
  } else { 	 
	  return false;
  }
}