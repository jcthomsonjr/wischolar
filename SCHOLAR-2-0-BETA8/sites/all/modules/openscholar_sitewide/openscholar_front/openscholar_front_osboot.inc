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
			'preset' => variable_get('scholar_default_preset', 'scholar'),
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

function _vsite_filefield_paths_config($type = NULL){
  $return = array();
  $types = og_get_types('group_post');
  
  $file_name = array(
    'value' => '[filefield-onlyname-original].[filefield-extension-original]',
    'tolower' => 0,
    'pathauto' => 0,
    'transliterate' => 0
  );
  
  $file_path = array(
    'value' => '[space-og-path-raw]/files',
    'tolower' => 0,
    'pathauto' => 0,
    'transliterate' => 0
  );
  
  $file_alias = array(
    'value' => '[space-og-path-raw]/files/[filefield-onlyname-original].[filefield-extension-original]',
    'tolower' => 0,
    'pathauto' => 0,
    'transliterate' => 0,
    'display' => 1,
  );
 
  //set the paths for upload fields
  if ($type){
    $field_exists = db_result(db_query("SELECT field FROM {filefield_paths} WHERE type = '%s' AND field = '%s' ",  $type, 'upload'));
    if($field_exists){
      db_query("UPDATE {filefield_paths} SET filename = '%s',  filepath = '%s', filealias = '%s' WHERE type = '%s' AND field = '%s' ",
      serialize($file_name), serialize($file_path), serialize($file_alias) , $type,  'upload');
    }
    else{
      db_query("INSERT INTO {filefield_paths} (type, field, filename, filepath, filealias) VALUES ('%s', '%s', '%s', '%s', '%s')", $type, 'upload',
      serialize($file_name), serialize($file_path), serialize($file_alias));
    }
  }

  else{
    foreach ( $types as $content_type ) {
      $field_exists = db_result(db_query("SELECT field FROM {filefield_paths} WHERE type = '%s' AND field = '%s' ",  $content_type, 'upload'));
      if($field_exists){
        db_query("UPDATE {filefield_paths} SET filename = '%s',  filepath = '%s', filealias = '%s' WHERE type = '%s' AND field = '%s' " ,
        serialize($file_name), serialize($file_path), serialize($file_alias) , $content_type, 'upload');
      }
      else{
        db_query("INSERT INTO {filefield_paths} (type, field, filename, filepath, filealias) VALUES ('%s', '%s', '%s', '%s', '%s')", $content_type, 'upload',
        serialize($file_name), serialize($file_path), serialize($file_alias));
      }
    }
    reset($types);
  }
    
  //set the paths for filefield fields
  foreach ( content_fields() as $field ) {
    //special case - do not update 'path' field_user_profile_photo
    if( $field['field_name'] == 'field_user_profile_photo' ); {
      db_query("UPDATE {filefield_paths} SET filename = '%s', filealias = '%s' WHERE field = '%s' " ,
      serialize($file_name), serialize($file_alias) ,$field['field_name']);
      continue;
    }

    if (($field['module'] == 'filefield') && in_array($field['type_name'], $types)) {
      //if specific type has been specified as parameter, then do no update other types filefield paths
      if(($type) && $type !==$field['type_name']) continue;

      $field_exists = db_result(db_query("SELECT field FROM {filefield_paths} WHERE field = '%s' ", $field['field_name']));
      if($field_exists){
        db_query("UPDATE {filefield_paths} SET filename = '%s',  filepath = '%s', filealias = '%s' WHERE field = '%s' " ,
        serialize($file_name), serialize($file_path), serialize($file_alias) ,$field['field_name']);
      }
      else{
        db_query("INSERT INTO {filefield_paths} (type, field, filename, filepath, filealias) VALUES ('%s', '%s', '%s', '%s', '%s')", $field['type_name'], $field['field_name'],
        serialize($file_name), serialize($file_path), serialize($file_alias));
      }
    }
  }

  $return[] = array(
    'success' => TRUE,
    'query' => t('The upload and filefield file paths were updated for %t', array('%t'  => ($type) ? "$type content type" : 'all vsite content types' )),
  );
  
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
  if(!$flag) return;
  $flag->delete();
  $flag->disable();
  _flag_clear_cache();
}


function _vsite_variables_default(){
    
  // site performance
  variable_set("cache", "0");
  variable_set("preprocess_css", "1");
  variable_set("preprocess_js", "1");
}

/**
 * Create the taxonomy's that will be used by the vsite object
 * @return success
 */
function _vsite_object_create_taxonomys(){
  
	install_include(array('taxonomy'));
    
	// Create the vsite tax for affiliation
  $vocab = array(
    'name' => 'Sites Affiliation / Department',
    'multiple' => 1,
    'required' => 0,
    'hierarchy' => 0,
    'relations' => 0,
    'module' => 'taxonomy',
    'weight' => 0,
    'nodes' => array('vsite' => 1),
    'tags' => false,
    'help' => t('Vsite Affiliation taxonomy'),
    'description' => t("A comma-separated list of affiliation that your site may have, for ex.(IQSS or 'Harvard Business School')"),
  );
  taxonomy_save_vocabulary($vocab);
  
  $vid = db_last_insert_id('vocabulary', 'vid');
  variable_set('vsite_taxonomy_affiliation', $vid);
  
  $a_terms = array ( array('name' => 'IQSS', 'description' => "The Institute for Quantitive Social Science at Harvard University", 'properties' => array('synonyms' => "Institute for Quantitive Social Science\nThe Institute for Quantitive Social Science\nThe Institute for Quantitive Social Science at Harvard University")),
                     array('name' => 'HBS', 'description' => "Harvard Business School", 'properties' => array('synonyms'=> "Harvard Business School\nBusiness School at Harvard University")) );
                     
  foreach($a_terms as $a_term) install_taxonomy_add_term($vid, $a_term['name'], $a_term['description'], $a_term['properties']);
  
  
  // Create the vsite tax for intrests
  $vocab = array(
    'name' => 'Related Interests',
    'description' => t("A comma-separated list of topics that may relate to the content of your site. ex.(statistics, casual inference)"),
    'multiple' => 0,
    'required' => 0,
    'hierarchy' => 0,
    'relations' => 0,
    'module' => 'taxonomy',
    'weight' => 0,
    'nodes' => array('vsite' => 1),
    'tags' => TRUE,
    'help' => t('A comma-separated list of topics that may relate to the content of your site. ex.(statistics, casual inference)'),
  );
  taxonomy_save_vocabulary($vocab);
  
  $vid = db_last_insert_id('vocabulary', 'vid');
  variable_set('vsite_taxonomy_interests', $vid);
}

/**
 * Create a default sitewide contact form using
 * 'site_mail' variable as email recipient
 */
function _vsite_default_contact_form(){
  $sitewide_contact_form = new stdClass();
  $sitewide_contact_form -> category = 'website feedback';
  $sitewide_contact_form -> recipients = variable_get('site_mail', '');
  $sitewide_contact_form -> selected = 1;
  if (strlen($sitewide_contact_form -> recipients)) {
    drupal_write_record('contact', $sitewide_contact_form);
  }
}