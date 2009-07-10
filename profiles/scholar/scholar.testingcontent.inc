<?php
define('DRUPAL_ROOT', getcwd());

function _scholar_testingcontent(){
	
	//include_once DRUPAL_ROOT . '/includes/theme.inc';
	
	// include all inc files
	install_include(array('install_profile_api', 'node', 'user'));
  
	// get all scholar themes. Just so that we creat a group for each theme
	// and assign that theme to the group
	$all_themes = list_themes(TRUE);
	$scholar_themes = array();
	//print_r($all_themes);
	foreach ($all_themes as $theme){
		if (strpos( $theme -> name, 'scholar_theme_') === 0){
			$scholar_themes[] = $theme -> name;
		}
	}

	$i = 1;
	foreach($scholar_themes as $scholar_theme){
		$uname_admin = "schlaradmin0$i";
		install_add_user($uname_admin, "sharepass", "scholar0$i@scholar.iq.harvard.edu", $roles = array("scholar admin"), $status = 1);
		
		$properties = array (
			'name' => $uname_admin, 
			'type' => 'scholar_site', // TODO move this as global variable /settings
		  'promote' => '1',
			'purl' => array ('value' => "site0$i", 'provider' => 'spaces_og', 'id' => NULL ), 
			'preset' => ($i == 1) ? 'scholarsite' : 'public', 
			'og_description' => "site0$i", 
			'theme' => $scholar_theme, 
			'og_description' => "site0$i", // TODO $terms array should include descriptions
		);
		$node = install_create_node ( $title = "site0$i", $body = NULL, $properties = $properties );
    //print_r($node);
		// create some users for this group
		
		for ($j=1; $j < 10; $j++){
			$uname_user = "site0$i".'_'."scholaruser0$j";
			
			install_add_user( $uname_user, "sharepass", "$uname_user@scholar.iq.harvard.edu", $roles = array("scholar user"), $status = 1);
			$uid = db_result(db_query("SELECT uid FROM {users} WHERE name='%s'", $uname_user));
	
			if ($j < 4){
				og_save_subscription($node -> nid, $uid, array('is_active' => 1, 'is_admin' => 1));
			} else {
				og_save_subscription($node -> nid, $uid, array('is_active' => 1));	
			}
		}
    
		//next one
		$i++;
	}
}