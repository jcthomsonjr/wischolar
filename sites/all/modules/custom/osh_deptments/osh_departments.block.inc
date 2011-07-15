<?php

function _osh_departments_block_economics_banner_view(){
  $links = array();
  
  $links[] = array(
    'title' => 'Home', 
    'href' => 'http://http://www.economics.harvard.edu/' 
  );
  
  $links[] = array(
    'title' => 'News', 
    'href' => 'http://www.economics.harvard.edu/news' 
  );
  
  $links[] = array(
    'title' => 'Faculty', 
    'href' => 'http://www.economics.harvard.edu/faculty' 
  );
  
  $output = theme_links($links, array(
    'class' => 'economics-department-banner' 
  ));
  
  return $output;

}