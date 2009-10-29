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
    'contact',
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
 * Returns an array list of core contributed modules.
 */
function _scholar_core_modules() {
 $contrib_modules = array(
  // sites/all
    'activity',
    'advanced_help',
    'context',
    'context_contrib',
    'content_profile',
    'content_profile_registration',
    'context_ui',
    'feedapi',
    'feedapi_node',
    'feedapi_inherit',
    'parser_common_syndication',
    'filefield_paths',
    'file_aliases',
    'features',
    'flag',
    'imageapi',
    'imageapi_gd',
    'itweak_upload',
    'jquery_ui',
    'lightbox2',
    'og',
    'og_access',
    'og_views', 
    'og_vocab',
    'og_actions',
    'override_node_options',
    'menu_node',
    'pathauto',
    'permissions_api',
    'profile',
    'purl',
    'spaces',
    'spaces_og',
    //'spaces_user',
    'stringoverrides',
    'token',
    'trigger',
    'transliteration',
    'ucreate',
    'ucreate_og',
    'views', 
    'views_bulk_operations',
    'views_ui', 
    'views_export', 
    'views_attach',
    'vertical_tabs',
    'wysiwyg',
  

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
    'imagefield_crop',
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
    'vsite_taxonomy',
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
    'iqss_project',
    'simport',
    
   // features TODO does this gets installed in the  next step (enable features?)
   // keep here for testing purposes only
    'scholar_dvn',
    'scholar_biocv',
    'scholar_links',
    'scholar_blog',
    'scholar_announcements',
    'scholar_classes',
    'scholar_image_gallery',
    'scholar_publications',
    'scholar_feeds',
    'scholar_software',
    'scholar_pages',
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
    //_scholar_profile_content_types();

    // configure modules  (variables table mainly)
    //_scholar_variable_set();

    // for testing purposes, create nodes groups etc


    // configure wisywig/tinymce
    _scholar_wysiwyg_config();

    // configure the contact module
    _scholar_contact_config();
    /*
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

    //features_rebuild();

    // enable the themes
    _scholar_enable_themes();

    variable_set('scholar_content_type', 'vsite');
    // set default to america/new yourk
    variable_set(date_default_timezone_name, "America/New_York");

    // _scholar_testingcontent();

    //_scholar_filefield_paths_config();
    _scholar_configure_biblio();

    //import the D5 scholar data
    // simport_import();

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
  $node_type_name = 'vsite';
  
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
  
  //get list of themes to be enabled - TODO: should 'kshepsle', 'rbates' be enabled for non IQSS installs?
  $themes = array('zen', 'cp_theme', 'scholar_base', 'scholar_project', 'kshepsle', 'rbates'); 
  $themes = array_merge($themes, __scholar_get_scholar_theme_names());
  
  //enable the themes
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

function   _scholar_wysiwyg_config(){
  $settings = array (
    'default' => 1,
    'user_choose' => 0,
    'show_toggle' => 1,
    'theme' => 'advanced',
    'language' => 'en',
    'buttons' => array(
      'default' => array (
         'bold' => 1,
         'italic' => 1,
         'strikethrough' => 1,
         'bullist' => 1,
         'numlist' => 1,
         'link' => 1,
         'unlink' => 1,
         'image' => 1,
         'code' => 1,
         'cut' => 1,
         'copy' => 1,
         'paste' => 1,
         'charmap' => 1,
       ),
            
       'font' => array('formatselect' => 1),
       'fullscreen' => array('fullscreen' => 1),
       'paste' => array('pastetext' => 1),
       'table' => array('tablecontrols' => 1),
       'safari' => array('safari' => 1),
       'drupal' => array ('break' => 1),
    ),

    'toolbar_loc' => 'top',
    'toolbar_align' => 'left',
    'path_loc' => 'bottom',
    'resizing' => 1,
    'verify_html' => 1,
    'preformatted' => 0, 
    'convert_fonts_to_spans' => 1,
    'remove_linebreaks' => 1,
    'apply_source_formatting' => 0,
    'paste_auto_cleanup_on_paste' => 1,
    'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6',
    'css_setting' => 'theme',
    'css_path' => '',
    'css_classes' => '',

);

$settings = serialize($settings);

  $query = "SELECT format FROM {filter_formats} WHERE name='%s'";
  $filter_name = db_result(db_query($query,'Filtered HTML'));
  $query = "INSERT INTO {wysiwyg} (format, editor, settings) VALUES ('%d', '%s', '%s')";
  db_query($query, $filter_name, 'tinymce', $settings);
}


function _scholar_contact_config(){
  install_include(array('contact'));
  //install_contact_add_category($category, $recipients, $reply = '', $weight = 0, $selected = 0);
  install_contact_add_category('website feedback', 'scholars_dev_support@help.hmdc.harvard.edu', $reply = '', $weight = 0, $selected = 1);
  install_contact_add_category('feature request', 'scholars_dev_support@help.hmdc.harvard.edu', $reply = '', $weight = 0, $selected = 0);
  install_contact_add_category('bug report', 'scholars_dev_support@help.hmdc.harvard.edu', $reply = '', $weight = 0, $selected = 0);
}

/**
 *  Change the biblio Config
 *  TODO: permissions
 */
function _scholar_configure_biblio(){
   $a_settings = include dirname(__FILE__) . '/biblio.settings.inc';
   
   include_once(drupal_get_path('module','biblio')."/biblio.admin.inc");
   drupal_execute('biblio_admin_types_edit_form',$a_settings['common']);
   
   db_query("UPDATE `biblio_field_type` SET visible = 0 WHERE fid IN(2,3,4,5) AND visible = 1");
   db_query("UPDATE `biblio_field_type` SET visible = 0 WHERE fid = 22 AND weight = -1");
}