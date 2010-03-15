<?php

define(HMDC_RBUILD_ROOT ,'http://gking.harvard.edu/src/contrib/');

/**
 * parse R cdf PACKAGES file
 */

/**
 * Parses http://r.iq.harvard.edu/src/contrib/PACKAGES
 * and load all the package in an array.
 * @return an array of all packages
 */
function scholar_software_rbuild_load_packages(){
  
  $homepage = file_get_contents(HMDC_RBUILD_ROOT . 'PACKAGES');
  $packages = array();
  $packages_raw = split("\n\n\n", $homepage);
  
  foreach ( $packages_raw as $package_raw ) {
    // this could work but it's a _bit ugly
    //$array = preg_split('/^(.*):/mU', $package_raw, - 1, PREG_SPLIT_DELIM_CAPTURE);
    
    $lines = split("\n", $package_raw);
    foreach ( $lines as $line ) {
      $line_elements = (explode(':', $line, 2));
      if (count($line_elements) == 2) {
        $current_key = ltrim($line_elements[0]);
        if ($current_key == 'Package') {
          $package_name = ltrim($line_elements[1]);
          $packages[$package_name] = array();
        }
        $packages[$package_name][$current_key] = ltrim($line_elements[1]);
      }
      else {
        $packages[$package_name][$current_key] .= ' ' . ltrim($line_elements[0]);
      }
    }
  }
  
  return $packages;
}


function scholar_software_rbuild_theme_package($pkg){
  $output = '';
  $authors = array();
  
  $authors_text = $pkg['Author'];
  $a_authors = explode(',', $authors_text);
  foreach($a_authors as $author_text){
    preg_match('/(.*)<(.*)>/', $author_text, $matches);
    //dpm($matches);
    $authors[]= array(
      'name' => $matches[1],
      'email' => $matches[2],
    );
  }
  
  
  foreach($authors as $author){
    
  }
  return 'xxxxxxxxxxxxxxxxxxxxx';
}