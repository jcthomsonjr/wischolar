<?php
define('DRUPAL_ROOT', getcwd());


/**
 * Generates some sites and assign users to each 
 * site. 
 * Later during task 'generate-content' nodes are assigned 
 * to these sites
 */

/*
function _scholar_testingcontent(){
	
	//include_once DRUPAL_ROOT . '/includes/theme.inc';
	
	// include all inc files
	install_include(array('install_profile_api', 'node', 'user'));
  
	// get all scholar themes. Just so that we create a group for each theme
	// and assign that theme to the group
	$all_themes = list_themes(TRUE);
	$scholar_themes = array();
	foreach ($all_themes as $theme){
		if (strpos( $theme -> name, 'scholar_theme_') === 0){
			$scholar_themes[] = $theme -> name;
		}
	}

	$nr_themes = count($scholar_themes);
	for ($i = 1; $i <= $nr_themes; $i++ ){
		$uname_admin = "scholaradmin0$i";
		$scholar_theme = "scholar_theme_0$i";
		
		install_add_user($uname_admin, "sharepass", "scholar0$i@scholar.iq.harvard.edu", $roles = array("scholar admin"), $status = 1);
		
		$properties = array (
			'name' => $uname_admin, 
			'type' => variable_get('scholar_content_type', 'vsite'),
		  	'promote' => '1',
			'purl' => array ('value' => "site0$i", 'provider' => 'spaces_og', 'id' => NULL ), 
			'preset' => 'vsite', // : 'public', 
			'og_description' => "site0$i", 
			'theme' => $scholar_theme, 
			'og_description' => "site0$i", // TODO $terms array should include descriptions
		);
		$node = install_create_node ( $title = "site0$i", $body = NULL, $properties = $properties );
    
        //make admin group member (admin) for each group
        og_save_subscription($node -> nid, 1, array('is_active' => 1));
			
		$uids = array();
		
		for ($j=1; $j < 10; $j++){
			$uname_user = "site0$i".'_'."scholaruser0$j";
			
			install_add_user( $uname_user, "sharepass", "$uname_user@scholar.iq.harvard.edu", $roles = array("scholar user"), $status = 1);
			$uid = db_result(db_query("SELECT uid FROM {users} WHERE name='%s'", $uname_user));
	    
			$uids[] = $uid;
			if ($j < 4){
				og_save_subscription($node -> nid, $uid, array('is_active' => 1, 'is_admin' => 1));
			} else {
				og_save_subscription($node -> nid, $uid, array('is_active' => 1));	
			}

		}
	}
}

*/
