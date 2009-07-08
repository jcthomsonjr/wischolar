<?php

function _scholar_testingcontent() {

	// create a couple of sites
	
	$sites = array('site1', 'site2', 'site3');

	for($i=1; $i < 5; $i++){
		// add a scholar user (faculty)
		install_add_user("scholar0$i", "sharepass", "scholar0$i@scholar.iq.harvard.edu", $roles = array("scholar admin"), $status = 1);
		
		$properties = array (
			'name' => "scholar0$i", 
			'type' => 'scholar_site', // TODO move this as global variable /settings
		  'promote' => '1',
			'purl' => array ('value' => "site0$i", 'provider' => 'spaces_og', 'id' => NULL ), 
			'preset' => 'public', 
			'og_description' => "site0$i", 
			'theme' => "scholar_theme_0$i", 
			'og_description' => "site0$i", // TODO $terms array should include descriptions
		);
		$node = install_create_node ( $title = "site0$i", $body = NULL, $properties = $properties );
	}

	//install_create_field_group('announcement', 'images_files', 'images & files', $settings = array(), $weight = 0);
  //install_fields_in_group('announcement', 'images_files', array('image', 'file'));
}