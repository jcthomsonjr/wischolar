<?php
// $Id:$

/**
 * Return an array of the modules to be enabled when this profile is installed.
 *
 * @return
 *   An array of modules to enable.
 */
function scholar_profile_modules() {
  $core_modules = _scholar_core_modules();

  $contrib_modules = array(
  // sites/all
    'activity',
    'advanced_help',
    'context',
    'context_contrib',
    'context_ui',
    'filefield_paths',
    'features',
    'flag',
    'imageapi',
    'imageapi_gd',
    'jquery_ui',
    'og',
    'og_access',
    'og_views', 
    'og_vocab',
    'og_actions',
    'menu_node',
    'permissions_api',
    'profile',
    'purl',
    'spaces',
    'spaces_og',
    'spaces_user',
    'token',
    'trigger',
    'transliteration',
    'views', 
    'views_bulk_operations',
    'views_ui', 
    'views_export', 
    'vertical_tabs',
  

  //cck
    'content', 
    'content_copy',
    'diff',
    'date_timezone', 
    'date_api', 
    'date',
    'date_popup',
    'filefield',
    'fieldgroup',
    'imagecache',
    'imagecache_ui',
    'imagefield',
    'link',
    'text',


  // development
    'admin_menu',
    'ctools',
    'devel',
    'devel_generate',
    'install_profile_api',
    'strongarm',
  
    'vsite',
    'scholar',
    'vsite_content',
    'vsite_front',
    'vsite_layout',
    'vsite_menus',
    'vsite_design',
    'vsite_users',
    'vsite_vocab',
    'vsite_help',
    'vsite_activity',
    'vsite_widgets',
    
  // scholar specific
    'biblio',

    'cp',
    'scholar_feature_settings',
    //'cp_node_forms',
    'scholarboot',
    'bkn',
    'cite_distribute',
   // 'cs_meta',
    'repec_meta',
    'googlescholar_meta',
    'dyntextfield',
    'scholarregister',
    'scholar_project',
    
   // features TODO does this gets installed in the  next step (enable features?)
   // keep here for testing purposes only
    'scholar_links',
    'scholar_blog',
    'scholar_announcements',
    
  );

  return array_merge($core_modules, $contrib_modules);
}


function _scholar_core_modules(){
  return array(
    'block', 
    'blog',
  	'comment', 
    'filter', 
  	'help', 
  	'menu',
  	'node', 
  	'system',
  	'search',
  	'user', 
  	'path',
  	'php',
    'taxonomy',
  );
}

/**
 * Return a description of the profile for the initial installation screen.
 *
 * @return
 *   An array with keys 'name' and 'description' describing this profile,
 *   and optional 'language' to override the language selection for
 *   language-specific profiles.
 */
function scholar_profile_details() {
  return array(
    'name' => 'Scholar Profile',
    'description' => 'Select this profile to enable an scholar installation.'
    );
}

/**
 * Return a list of tasks that this profile supports.
 *
 * @return
 *   A keyed array of tasks the profile will perform during
 *   the final stage. The keys of the array will be used internally,
 *   while the values will be displayed to the user in the installer
 *   task list.
 */
function scholar_profile_task_list() {
  return array(
    'scholar-features' => st('Scholar features'),
    'content-generate' => st('Generate content'),
  );
}

/**
 * hook profile_tasks
 */
function scholar_profile_tasks(&$task, $url) {
  include_once(dirname(__FILE__) . '/scholar.forms.inc');
  include_once(dirname(__FILE__) . '/scholar.settings.inc');
  include_once(dirname(__FILE__) . '/scholar.testingcontent.inc');
  
  $output = '';
  
  if ($task == 'profile'){

    install_include(scholar_profile_modules());

    // create roles
    _scholar_create_roles();
    // rebuild access (required by og)
    _scholar_access_rebuild();
    // create default content types
    _scholar_profile_content_types();
    
    // configure modules  (variables table mainly)
    _scholar_variable_set();
    
    // set the theme
    _scholar_enable_themes();
    
    // for testing purposes, create nodes groups etc
    _scholar_testingcontent();

    $task = 'scholar-features';
    drupal_set_title('Enabe all the features available to each scholar site');
    return drupal_get_form('scholar_get_features_info', $url);
  }

  // task to enable features
  if ($task == 'scholar-features'){
    $form = drupal_get_form('scholar_get_features_info', $url);    
    if (variable_get('scholar_features', FALSE)){
       variable_del('scholar_features');
       $task = 'content-generate';
       variable_set('content_generate','1');  // why is this important, i have no idea!!
       
       drupal_set_title('generate some content for testing');
       return drupal_get_form('scholar_generate_content_form', $url);
    }
    else {
      return $form;
    }
  }
  
  // generate some content for testing
  if ($task == 'content-generate'){
    $form = drupal_get_form('scholar_generate_content_form', $url);    
    if (variable_get('content_generate', FALSE)){
       variable_del('content_generate');
       $task = 'profile-finished';
    }
    else {
      return $form;
    }
  }
  return $output;
}

/**
 *  Creates roles and permissions
 *  TODO: permissions
 */
function _scholar_create_roles(){
  install_add_role('scholar admin');
  install_add_role('scholar user');
}

/**
 * og requires to rebuild node_access_permission
 * after install
 * We are just making a fresh install so it's safe
 * to have $batch = FALSE as argument
 * 
 * @see http://api.drupal.org/api/function/node_access_rebuild/6
 */
function _scholar_access_rebuild(){
  node_access_rebuild();
}

/**
 * Create default content types
 */
function _scholar_profile_content_types(){
  $node_type_name = 'scholarsite';
  
  $site_type = array(
    'name' => st('Scholar site'),
    'type' => $node_type_name,
    'description' => st('Represent a Scholar web site'),
    'module' => 'node',
    'has_title' => TRUE,  // TODO check if we can set this to false
    'title_label' => st('Site title'),
    'has_body' => FALSE,
    'custom' => FALSE,
    'modified' => TRUE,
    'locked' => FALSE,
    'is_new' => TRUE,
  );
  
  node_type_save((object)$site_type);
  
  // make this a group node
  variable_set('og_content_type_usage_' . $node_type_name, 'group');
}

/**
 * enable a couple of themes
 * TODO Get all the themes automatically and enable 
 * them based on some predefined pattern (i.e. scholar_theme_*)
 *
 */
function _scholar_enable_themes(){
  // the default theme is the project theme
  install_default_theme('scholar_project');
  
  $themes = array('zen', 'cp_theme', 'scholar_base');

  $themes = array_merge($themes, __scholar_get_scholar_theme_names());
  install_enable_theme($themes);
	
  // disable all DB blocks
  db_query("UPDATE {blocks} SET status = 0, region = ''"); 
}

/**
 * Implementation of hook_form_alter().
 *
 * Allows the profile to alter the site-configuration form. This is
 * called through custom invocation, so $form_state is not populated.
 */
function scholar_form_alter(&$form, $form_state, $form_id) {
 
  if ($form_id == 'install_configure') {
    // Set default for site name field.
    $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
    $form['site_information']['site_mail']['#default_value'] = 'swap@lists.iq.harvard.edu';
    $form['admin_account']['account']['name']['#value'] = 'admin';
    $form['admin_account']['account']['mail']['#value'] = 'swap@lists.iq.harvard.edu';
    $form['admin_account']['account']['pass']['#value'] = 'sharepass';
    // dont check for updates automatically
    // TODO this is not working 
    //$form['server_settings']['update_status_module']['#default_value'] = 0;
  }
}

/**
 * return theme names starting with 'scholar_theme_'
 *
 * @return unknown
 */
function __scholar_get_scholar_theme_names(){
	$return = array();
	$sql = "SELECT * FROM {system} WHERE type = '%s' AND name LIKE '%s%%'";
	$result = db_query($sql, 'theme', 'scholar_theme_');
	while($data = db_fetch_object($result)){
		$return[] = $data -> name;
	}
	return $return;
}

