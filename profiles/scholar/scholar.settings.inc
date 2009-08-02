<?php

function _scholar_variable_set(){
  variable_set('scholar_content_type', 'scholarsite');
  variable_set('menu_primary_links_source', 'features');  // TODO  Print them yourself as a links 
  
  // set default to america/new yourk
  variable_set(date_default_timezone_name, "America/New_York");
}
