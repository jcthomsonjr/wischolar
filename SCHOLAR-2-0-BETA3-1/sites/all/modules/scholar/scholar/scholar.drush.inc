<?php

/**
 * Implementation of hook_drush_command().
 */
function scholar_drush_command() {
  $items['scholar generate content'] = array(
    'callback' => 'scholar_generate_content',
    'description' => 'Creates content.',
  );
  return $items;
}



function scholar_generate_content(){
	// copy the function from scholar.profile (scholar.testingcontent.inc);
}