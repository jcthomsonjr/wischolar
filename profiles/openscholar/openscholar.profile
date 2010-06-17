<?php
// $Id$

/**
 * Implementation of hook_profile_details().
 */
function openscholar_profile_details() {
  return array(
    'name' => 'OpenScholar',
    'description' => 'OpenScholar project by IQSS at Harvard University'
  );
}

/**
 * Implementation of hook_profile_modules().
 */
function openscholar_profile_modules() {
  return array(
    'block',
    'blog',
    'book',
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
function _openscholar_core_modules() {
 $contrib_modules = array(
  // sites/all
    'activity',
    'addthis',
    'advanced_help',
    'calendar',
    'litecal',
    'context',
    'context_contrib',
    'content_profile',
    'content_profile_registration',
    'context_ui',
    'ctools',
    'data',
    'data_node',
    'data_ui',
    'dialog',
    'feeds',
    'feeds_defaults',
    'filefield_paths',
    'file_aliases',
    'features',
    'flag',
    'imageapi',
    'imageapi_gd',
    'itweak_upload',
    'jquery_ui',
    'jquery_update',
    'lightbox2',
    'mollom',
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
    'stringoverrides',
    'token',
    'trigger',
    'transliteration',
    'twitter_pull',
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
    'number',
    'nodereference',
    'nodereference_url',
    'optionwidgets',


  // development
    'admin_menu',
    'devel',
    'devel_generate',
    'install_profile_api',
    'schema',
    'strongarm',
  );
  
  return $contrib_modules;
}

/**
 * Returns an array list of dsi modules.
 */
function _openscholar_scholar_modules() {
  return array(
    'vsite',
    'scholar',
    'vsite_content',
    'vsite_domain',
    'scholar_events',
    'vsite_ga',
    'vsite_layout',
    'vsite_menus',
    'vsite_design',
    'vsite_users',
    'vsite_taxonomy',
    'vsitehelp',
    'vsite_news',
    'vsite_support',
    'vsite_widgets',
    'vsite_generic_settings',
    
  // scholar specific
    'biblio',
    'auto_nodetitle',

  //IQSS Specific
    'iqss_scholar',
  
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

    // features
    'scholar_dvn',
    'scholar_biocv',
    'scholar_links',
    'scholar_blog',
    'scholar_book',
    'scholar_announcements',
    'scholar_classes',
    'scholar_image_gallery',
    'scholar_publications',
    'scholar_software',
    'scholar_pages',
    'scholar_reader',
    'scholar_front',
    'scholar_profiles',
  );
}

/**
 * Implementation of hook_profile_task_list().
 */
function openscholar_profile_task_list() {
  $tasks = array(
    'openscholar-configure' => st('openscholar  configuration'),
  );
  return $tasks;
}

/**
 * Implementation of hook_profile_tasks().
 */
function openscholar_profile_tasks(&$task, $url) {

  $output = '';

  if ($task == 'profile') {
    $modules = _openscholar_core_modules();
    $modules = array_merge($modules, _openscholar_scholar_modules());

    $files = module_rebuild_cache();
    $operations = array();
    foreach ($modules as $module) {
      $operations[] = array('_install_module_batch', array($module, $files[$module]->info['name']));
    }
    $batch = array(
    'operations' => $operations,
    'finished' => '_openscholar_profile_batch_finished',
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
  if ($task == 'openscholar-configure') {
    include_once 'profiles/openscholar_profiles_common.inc';
    install_include(_openscholar_core_modules());
    // create roles
    _openscholar_profiles_create_roles();

    // configure wisywig/tinymce
    _openscholar_profiles_wysiwyg_config();

    // configure the contact module
    _openscholar_profiles_contact_config();
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
    _openscholar_enable_themes();

    variable_set('scholar_content_type', 'vsite');
    // set default to america/new yourk
    variable_set(date_default_timezone_name, "America/New_York");

    //_scholar_filefield_paths_config();
    _openscholar_profiles_configure_biblio();

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
function _openscholar_profile_batch_finished($success, $results) {
  variable_set('install_task', 'openscholar-configure');
}

/**
 * enable a couple of themes
 */
function _openscholar_enable_themes(){
  
  // the default theme is the project theme
  install_default_theme('scholar_project');
  
  $themes = array(
    'zen',
    'cp_theme',
    'scholar_base',
    'scholar_project',
    'scholar_theme_01',
    'scholar_theme_02',
    'scholar_theme_03',
    'scholar_theme_04',
    'scholar_theme_05',
    'scholar_theme_06',
    'scholar_theme_07',
    'scholar_theme_08',
    'scholar_theme_09',
    'scholar_theme_10',
    'scholar_theme_11',
    'scholar_theme_12'
  );
  
  //enable the themes
  install_enable_theme($themes);
	
  // disable all DB blocks
  db_query("UPDATE {blocks} SET status = 0, region = ''");
}

