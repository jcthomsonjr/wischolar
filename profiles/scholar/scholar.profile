<?php
// $Id$

/**
 * Implementation of hook_profile_details().
 */
function scholar_profile_details() {
  return array(
    'name' => 'Scholar',
    'description' => 'Scholar Web Sites by IQSS'
  );
}

/**
 * Implementation of hook_profile_modules().
 */
function scholar_profile_modules() {
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
    'upload',
  );
}

/**
 * Returns an array list of core atrium modules.
 */
function _scholar_core_modules() {
 $contrib_modules = array(
  // sites/all
    'activity',
    'advanced_help',
    'context',
    'context_contrib',
    'content_profile',
    'context_ui',
    'feedapi',
    'feedapi_node',
    'feedapi_inherit',
    'parser_common_syndication',
    'filefield_paths',
    'features',
    'flag',
    'imageapi',
    'imageapi_gd',
    'itweak_upload',
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
    //'spaces_user',
    'token',
    'trigger',
    'transliteration',
    'views', 
    'views_bulk_operations',
    'views_ui', 
    'views_export', 
    'views_attach',
    'views_gallery',
    'views_gallery_og',
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
    'nodereference',
  	'nodereference_url',
    'optionwidgets',


  // development
    'admin_menu',
    'ctools',
    'devel',
    'devel_generate',
    'install_profile_api',
    'strongarm',    
  );
  
  return $contrib_modules;
}

/**
 * Returns an array list of dsi modules.
 */
function _scholar_scholar_modules() {
  return array(
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
    'vsite_news',
    'vsite_support',
    'vsite_widgets',
    'vsite_generic_settings',
    
  // scholar specific
    'biblio',

    'cp',
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
    'scholar_classes',
    'scholar_image_gallery',
    'scholar_publications',
    'scholar_feeds',
    'scholar_software',
  );
}

/**
 * Implementation of hook_profile_task_list().
 */
function scholar_profile_task_list() {
  $tasks = array(
    'scholar-configure' => st('Scholar  configuration'),
  );
  return $tasks;
}

/**
 * Implementation of hook_profile_tasks().
 */
function scholar_profile_tasks(&$task, $url) {
  include_once(dirname(__FILE__) . '/scholar.testingcontent.inc');

  $output = '';

  if ($task == 'profile') {
    $modules = _scholar_core_modules();
    $modules = array_merge($modules, _scholar_scholar_modules());

    $files = module_rebuild_cache();
    $operations = array();
    foreach ($modules as $module) {
      $operations[] = array('_install_module_batch', array($module, $files[$module]->info['name']));
    }
    $batch = array(
      'operations' => $operations,
      'finished' => '_scholar_profile_batch_finished',
      'title' => st('Installing @drupal', array('@drupal' => drupal_install_profile_name())),
      'error_message' => st('The installation has encountered an error.'),
    );
    // Start a batch, switch to 'profile-install-batch' task. We need to
    // set the variable here, because batch_process() redirects.
    variable_set('install_task', 'profile-install-batch');
    batch_set($batch);
    batch_process($url, $url);
  }

  // Run additional configuration tasks
  // @todo Review all the cache/rebuild options at the end, some of them may not be needed
  if ($task == 'scholar-configure') {
      install_include(_scholar_core_modules());
    // create roles
    _scholar_create_roles();
    // rebuild access (required by og)
    //_scholar_access_rebuild();
    // create default content types
    _scholar_profile_content_types();
    
    // configure modules  (variables table mainly)
    _scholar_variable_set();
    
    // set the theme
    _scholar_enable_themes();
    
    // for testing purposes, create nodes groups etc
    _scholar_testingcontent();

    /*
    // Remove default input filter formats
    $result = db_query("SELECT * FROM {filter_formats} WHERE name IN ('%s', '%s')", 'Filtered HTML', 'Full HTML');
    while ($row = db_fetch_object($result)) {
      db_query("DELETE FROM {filter_formats} WHERE format = %d", $row->format);
      db_query("DELETE FROM {filters} WHERE format = %d", $row->format);
    }

    // Eliminate the access content perm from anonymous users.
    db_query("UPDATE permission set perm = '' WHERE rid = 1");

    // Create user picture directory
    $picture_path = file_create_path(variable_get('user_picture_path', 'pictures'));
    file_check_directory($picture_path, 1, 'user_picture_path');



    // Set time zone
    variable_set('date_default_timezone_name', 'US/Eastern');

    // Calculate time zone offset from time zone name and set the default timezone offset accordingly.
    // You dont need to change the next two lines if you change the default time zone above.
    $date = date_make_date('now', variable_get('date_default_timezone_name', 'US/Eastern'));
    variable_set('date_default_timezone', date_offset_get($date));

    // Set a default footer message.
    variable_set('site_footer', '&copy; 2009 '. l('IQSS', 'http://www.iq.harvard.edu', array('absolute' => TRUE)));
    */

    // Rebuild key tables/caches
    menu_rebuild();
    module_rebuild_cache(); // Detects the newly added bootstrap modules
    node_access_rebuild();
    drupal_get_schema('system', TRUE); // Clear schema DB cache
    drupal_flush_all_caches();
    db_query("UPDATE {blocks} SET status = 0, region = ''"); // disable all DB blocks

  variable_set('scholar_content_type', 'scholarsite');
  // set default to america/new yourk
  variable_set(date_default_timezone_name, "America/New_York");

    // Get out of this batch and let the installer continue
    $task = 'profile-finished';
  }
  return $output;
}

/**
 * Finished callback for the modules install batch.
 *
 * Advance installer task to language import.
 */
function _scholar_profile_batch_finished($success, $results) {
  variable_set('install_task', 'scholar-configure');
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
/*
function _scholar_access_rebuild(){
  node_access_rebuild();
}
*/

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

