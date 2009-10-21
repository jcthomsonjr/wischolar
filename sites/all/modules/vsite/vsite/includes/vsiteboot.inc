<?php

/**
 * Generates some sites and assign users to each 
 * site. 
 * Later during task 'generate-content' nodes are assigned 
 * to these sites
 */
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


function _vsite_filefield_paths_config() {
  $return = array();

  //set the "upload" paths
  $types = og_get_types('group_post');
  $file_name = array(
  'value' => '[filefield-onlyname-original].[filefield-extension-original]',
  'tolower' => 0,
  'pathauto' => 0,
  'transliterate' => 0,
  );

  $file_path = array(
  'value' => '[space-og-path-raw]/files',
  'tolower' => 0,
  'pathauto' => 0,
  'transliterate' => 0,
  );
  foreach ($types as $type){
    //if (variable_get("upload_$type", "0") === "1"){
    db_query("INSERT INTO {filefield_paths} (type, field, filename, filepath) VALUES ('%s', '%s', '%s', '%s')", $type, "upload", serialize($file_name), serialize($file_path));
    //}
  }

  //set the "filefield" paths
  $settings = new stdClass();
  $settings -> filepath = serialize($file_path);
  $settings -> filename = serialize($file_name);

  //get applicable content types
  $content_types = array_keys(spaces_features_map('node'));
  
  //find the fields
  foreach (content_fields() as $field){
    if (($field['module'] == 'filefield') && in_array($field['type_name'], $content_types)){
      
      $settings -> type = $field['type_name'];
      $settings -> field = $field['field_name'];
      
      //add path settings to database
      drupal_write_record('filefield_paths', $settings);
    }
  }

  $return[] = array('success' => TRUE,
  'query' => "the upload file paths were inserted in the filefield_paths table");

  return $return;
}

function _vsite_global_taxonomy(){
  // Create the global vocab
  $vocab_nodes = array();
  $types =  og_get_types('group_post');
  foreach($types as $type){
    $vocab_nodes[$type] = 1;
  }
  $vocab = array(
    'name' => 'Scholar Taxonomy', 
    'multiple' => 0, 
    'required' => 0, 
    'hierarchy' => 0, 
    'relations' => 0, 
    'module' => 'vsite', 
    'weight' => 0, 
    'nodes' => $vocab_nodes,  
    'tags' => TRUE,
    'help' => t('Scholar global taxonomy'),
  );
  taxonomy_save_vocabulary($vocab);
  
  $vid = db_last_insert_id('vocabulary', 'vid');
  variable_set('scholar_global_taxonomy', $vid);
}


function _vsite_flags_boot(){
  //disable the f. bookmarks flag
  module_load_include('inc', 'flag', '/includes/flag.admin');
  $flag = flag_get_flag('bookmarks');
  $flag->delete();
  $flag->disable();
  _flag_clear_cache();
}