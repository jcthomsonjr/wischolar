<?php
define('DRUPAL_ROOT', getcwd());

function _scholar_testingcontent(){
	
	//include_once DRUPAL_ROOT . '/includes/theme.inc';
	
	// include all inc files
	install_include(array('install_profile_api', 'node', 'user'));
  
	// get all scholar themes. Just so that we create a group for each theme
	// and assign that theme to the group
	$all_themes = list_themes(TRUE);
	$scholar_themes = array();
	//print_r($all_themes);
	foreach ($all_themes as $theme){
		if (strpos( $theme -> name, 'scholar_theme_') === 0){
			$scholar_themes[] = $theme -> name;
		}
	}

	$nr_themes = count($scholar_themes);
	for ($i = 1; $i <= $nr_themes; $i++ ){
		$uname_admin = "schlaradmin0$i";
		$scholar_theme = "scholar_theme_0$i";
		
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
		
		__scholar_generate_node('blog',$uids);
		
	}
}

/**
 * Create one node.  This is used by both the batch and non-batch branches of
 * the code.
 *
 * @param $num
 *   array of options obtained from devel_generate_content_form.
 */
function __scholar_generate_node($node_types, $uids) {
    module_load_include('inc', 'node', 'node.pages');
    module_load_include('inc',  'devel_generate', 'devel_generate');
  
  $results = array (
  	'values' => array (
  		'node_types' => array ('blog' => 'Blog Entry', 'announcement' => 'Announcement'), 
  		'users' => $uids,
      'num_nodes' => 10,
    ), 
  );
  
  devel_generate_content($results);
  /*
  // Insert new data:
  $node->type = array_rand($results['node_types']);
  module_load_include('inc', 'node', 'node.pages');
  node_object_prepare($node);
  $users = $results['users'];
  $node->uid = $users[array_rand($users)];

  $node->title = devel_create_greeking(mt_rand(1, $results['title_length']), TRUE);
  $node->body = "node ($node->type) - ". devel_create_content();
  $node->teaser = node_teaser($node->body);
  $node->filter = variable_get('filter_default_format', 1);
  $node->format = FILTER_FORMAT_DEFAULT;
  $node->language = '';
  $node->revision = mt_rand(0,1);
  $node->promote = mt_rand(0, 1);
  $node->created = time() - mt_rand(0, $results['time_range']);
  
  // A flag to let hook_nodeapi() implementations know that this is a generated node.
  $node->devel_generate = $results;
      
  // See devel_generate_nodeapi() for actions that happen before and after this save.
  node_save($node);
*/
}

/**
 * Create one node.  This is used by both the batch and non-batch branches of
 * the code.
 *
 * @param $num
 *   array of options obtained from devel_generate_content_form.
 */
function __scholar_generate_node1($type, $uids) {
  // Insert new data:
  $node->type = $type;
  module_load_include('inc', 'node', 'node.pages');
  node_object_prepare($node);
  $users = $results['users'];
  $node->uid = array_rand($uids);

  $node->title = devel_create_greeking(mt_rand(1, $results['title_length']), TRUE);
  $node->body = "node ($type) - ". devel_create_content();
  $node->teaser = node_teaser($node->body);
  $node->filter = variable_get('filter_default_format', 1);
  $node->format = FILTER_FORMAT_DEFAULT;
  $node->language = '';
  $node->revision = mt_rand(0,1);
  $node->promote = mt_rand(0, 1);
  $node->created = time() - mt_rand(0, $results['time_range']);
  
  //add group inf
  $node -> og_groups = array($node -> nid => $node -> nid);
  
  // A flag to let hook_nodeapi() implementations know that this is a generated node.
  $node->devel_generate = $results;
      
  // See devel_generate_nodeapi() for actions that happen before and after this save.
  node_save($node);

}



