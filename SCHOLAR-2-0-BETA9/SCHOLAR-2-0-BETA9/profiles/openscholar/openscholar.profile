<?php
// $Id: openscholar.profile,v 1.1.2.28 2010/10/28 16:07:32 rbrandon Exp $

/**
 * Implementation of hook_profile_details().
 */
function openscholar_profile_details() {
  return array(
    'name' => 'OpenScholar',
    'description' => 'OpenScholar distribution by IQSS at Harvard'
  );
}

/**
 * Implementation of hook_profile_modules().
 */
function openscholar_profile_modules() {
  return array(
    //core
    'block', 'book', 'comment', 'contact', 'filter', 'help',
    'menu', 'node', 'system', 'search', 'user', 'path', 'php',
    'taxonomy', 'upload',
  
    //admin menu
    'admin_menu',
    //views
    'views',
    //og
    'og', 'og_access', 'og_actions', 'og_views', 'og_vocab',
    //ctools
    'ctools',
    // context
    'context', 'context_contrib', 'context_ui',
    // date
    'date_api', 'date_timezone',
    // features
    'features',
    // image
    'imageapi', 'imageapi_gd', 'imagecache',
    // token
    'token',
    //trigger
    'trigger',
    // transliteration
    'transliteration',
    // purl
    'purl',
    // spaces
    'spaces', 'spaces_og',
    // ucreate
    'ucreate', 'ucreate_og',
  
    
  );
}

/**
 * Returns an array list of core contributed modules.
 */
function _openscholar_core_modules() {
 $contrib_modules = array(

    'addthis', 'advanced_help', 'install_profile_api', 'biblio', 'auto_nodetitle',
    'diff', 'menu_node', 'override_node_options', 'schema', 'stringoverrides',
    'strongarm', 'twitter_pull',
 
    // cck
    'content', 'content_copy', 'fieldgroup', 'filefield', 'filefield_paths',
    'link', 'number', 'text', 'optionwidgets', 'nodereference', 'nodereference_url',
    'dyntextfield',  'imagefield',
 
    // flag
    'flag',
 
    //date, calendar
    'date', 'date_popup', 'litecal',
    
    //js, jquery
    'jquery_update', 'jquery_ui', 'lightbox2', 'vertical_tabs', 'itweak_upload',
    'dialog', 'imagefield_crop',
 
    //views
    'views_attach', 'views_bulk_operations', 'views_export', 'views_ui',
    
    // signup
    'signup', 'signup_confirm_email',
 
    // content profile
    'content_profile', 'content_profile_registration',

    // data / feeds
    'data', 'data_node', 'data_ui', 'feeds', 'feeds_defaults',
 
  
    // other

    'wysiwyg',
    'activity',
    'imagecache_ui',
    'pathauto',
    'file_aliases',
    'better_formats',


  );
  
  return $contrib_modules;
}

/**
 * Returns an array list of openscholar specific modules.
 */
function _openscholar_scholar_modules() {
  return array(
    'vsite',
    'vsite_widgets',
    'vsite_content',
    'vsite_domain',
    'scholar_events',
    'scholar_events_signup',
    'vsite_ga',
    'vsite_layout',
    'vsite_menus',
    'vsite_design',
    'vsite_users',
    'vsite_taxonomy',
    'vsitehelp',
    'vsite_news',
    'vsite_support',

    'vsite_generic_settings',
    'vsite_comments',
    
    'cp',
    'bkn',
    'cite_distribute',
    'repec_meta',
    'googlescholar_meta',

  
    //Install-Wide Pages
    'scholarregister',
    'openscholar_front',

    // features
    'scholar_dvn',
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
  global $conf;
  $conf['site_name'] = 'OpenScholar';
  $conf['site_footer'] = '<a href="http://openscholar.harvard.edu">OpenScholar</a> by <a href="http://iq.harvard.edu">IQSS</a> at Harvard University';
  
  
  $tasks = array(
    'openscholar-flavor' => st('OpenScholar  flavor'),
    'openscholar-configure' => st('Openscholar  configuration'),
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
  
  // chose an openscholar flavor to install
  if ($task == 'openscholar-flavor') {
      $output = drupal_get_form('_openscholar_flavors_form', $url);
    if (! variable_get('openscholar_flavor_form_executed', FALSE)) {
      drupal_set_title('How will this OpenScholar installation be used?');
      return $output;
    }
    else {
      $task = 'openscholar-configure';
    }
  }

  // Run additional configuration tasks
  if ($task == 'openscholar-configure') {
    //Include Modules that have been enabled
    //We don't need to use install_include since the system table has been enabled
    module_load_all();
    
    // create roles
    _openscholar_create_roles();
    
    // create a default contact form
    _vsite_default_contact_form();
    
    // disable some flags
    _openscholar_flags();
     
    // configure wisywig/tinymce
    _openscholar_wysiwyg_config();
    


    // Rebuild key tables/caches
    menu_rebuild();
    module_rebuild_cache(); // Detects the newly added bootstrap modules
    node_access_rebuild();
    drupal_get_schema('system', TRUE); // Clear schema DB cache
    drupal_flush_all_caches();
    db_query("UPDATE {blocks} SET status = 0, region = ''"); // disable all DB blocks
    
    // create a global taxonomy (not really used right now)
    // _vsite_global_taxonomy();
    
    //filefield_path /alias config
    _openscholar_filefield_paths_config();
    
    // biblio configuraitons
    _openscholar_configure_biblio();
    
    if (function_exists('strongarm_init')) {
      strongarm_init();
    }

    variable_set('scholar_content_type', 'vsite');
    variable_set('site_frontpage', 'welcome');

    // Rebuild the caches
    drupal_flush_all_caches();
    
    //Make theme modifications last so that clearing the cache here does not mess up our work
    
    //Reset Theme Info
    _openscholar_system_theme_data();
    
    // enable the themes
    _openscholar_enable_themes();
    
    // we are done let the installer know
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
  //variable_set('install_task', 'openscholar-configure');
  variable_set('install_task', 'openscholar-flavor');
}

/**
 * enable a couple of themes
 */
function _openscholar_enable_themes(){
  
  $themes = array(
    'openscholar_default', //Default theme
    'zen',
    'cp_theme',
    'scholar_base',
    'scholar_airstream',
    'scholar_bigpic',
    'scholar_bunchy',
    'scholar_burroughs',
    'scholar_cayley',
    'scholar_collector',
    'scholar_density',
    'scholar_eloquent',
    'scholar_nortony',
    'scholar_quinn',
    'scholar_redhead',
    'scholar_stripy',
    'scholar_weft'
  );
  
  //enable the themes
  foreach($themes as $theme){
    db_query("UPDATE {system} SET status = 1 WHERE type = 'theme' and name = '%s'", $theme);
    system_initialize_theme_blocks($theme);
  }
  
  //Set default theme
  global $theme_key;
  variable_set('theme_default', 'openscholar_default');
  // update the global variable too,
  // mainly so that block functions work correctly
  $theme_key = $theme;
  
  // disable all DB blocks
  db_query("UPDATE {blocks} SET status = 0, region = ''");

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

/**
 * disable the bookmarks flag
 */
function _openscholar_flags(){
  //disable the f. bookmarks flag
  module_load_include('inc', 'flag', '/includes/flag.admin');
  $flag = flag_get_flag('bookmarks');
  if(!$flag) return;
  $flag->delete();
  //$flag->disable();
  _flag_clear_cache();
}

/**
 *  Change the biblio Config
 */
function _openscholar_configure_biblio(){
  
	if(!file_exists(drupal_get_path('module', 'scholar_publications') .'/includes/biblio_settings.inc')) return;
	
  list($biblio_field_type, $biblio_field_type_data, $biblio_contributor_type, $biblio_contributor_type_data) = include(drupal_get_path('module', 'scholar_publications') .'/includes/biblio_settings.inc');
  
  db_query('DELETE FROM {biblio_field_type}');
  foreach($biblio_field_type as $type){
    drupal_write_record('biblio_field_type', $type);
  }
  
  db_query('DELETE FROM {biblio_field_type_data}');
  foreach($biblio_field_type_data as $type_data){
    drupal_write_record('biblio_field_type_data', $type_data);
  }

  db_query('DELETE FROM {biblio_contributor_type}');
  foreach($biblio_contributor_type as $contrib_type){
    drupal_write_record('biblio_contributor_type', $contrib_type);
  }

  db_query('DELETE FROM {biblio_contributor_type_data}');
  foreach($biblio_contributor_type_data as $contrib_type_data){
    //Run the query manually to override the serials
    db_query("INSERT INTO {biblio_contributor_type_data} (auth_type, title, hint) VALUES ( %d, '%s', '%s')",array($contrib_type_data['auth_type'],$contrib_type_data['title'],$contrib_type_data['hint']));
  }
}

/**
 * wysiwyg configurations
 */
function _openscholar_wysiwyg_config(){
  $wysiwyg_presets = _openscholar_wysiwyg_presets();
  foreach ( $wysiwyg_presets as $filter_name => $settings ) {
    $settings = serialize($settings);
    
    $query = "SELECT format FROM {filter_formats} WHERE name='%s'";
    $format = db_result(db_query($query, $filter_name));
    $query = "INSERT INTO {wysiwyg} (format, editor, settings) VALUES ('%d', '%s', '%s')";
    db_query($query, $format, 'tinymce', $settings);
  }
}

/**
 *  Creates roles and permissions
 */
function _openscholar_create_roles(){
  install_add_role('scholar admin');
  install_add_role('scholar user');
}

/**
 * Form definition for OS flavors
 */
function _openscholar_flavors_form($form_state, $url){
  
  $form = array();
  
  $form['#action'] = $url;
  $form['#redirect'] = FALSE;
  
  $form['flavor'] = array(
    '#tree' => TRUE,
    '#type' => 'radios',
    '#title' => t('Options'),
    '#default_value' => 0,
    '#options' => array(
      t('Scholars Personal Sites'),
      t('Project Sites'),
      t('Openscholar Development')
    ),
    '#description' => t('Chose a site type to install, each type can be customized further after install by enabling/disabling modules.')
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('OK')
  );
  
  return $form;
}

/**
 * Submit handler for the flavor form
 */
function _openscholar_flavors_form_submit(&$form, &$form_state){

  install_include(array('user'));
  $flavor = $form_state['values']['flavor'];

  switch($flavor){
    case 0:       // personal
      $flavor = 'personal';
      $modules = array('scholar', 'scholar_biocv');
      $vsite_node_type = 'vsite';  // for historical reasons
      break;
    case 1:       // project
      $flavor = 'project';
      $modules = array('scholar_project');
      $vsite_node_type = 'project';
      break;
      
    case 2:       // dev
      $flavor = 'development';
      $modules = array('scholar', 'scholar_biocv', 'devel', 'cvs_deploy');
      install_add_permissions(1, array('switch users')); //  yes anon users can switch users!!
      break;
  
  }

  // install extra modules for each flavor
  include_once './includes/install.inc';
  drupal_install_modules($modules);
  
  // create vsite vocabs (interest, affiliation)
  _openscholar_vsite_vocabs($vsite_node_type);
  
  variable_set('openscholar_flavor_installed', $flavor);
  variable_set('openscholar_flavor_form_executed', TRUE);
}

function _openscholar_filefield_paths_config(){

  $types = _openscholar_group_posts();
  
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
  
  
  foreach ( $types as $type ) {
    $file_alias['display'] = ($type == 'image')?0:1; //turn on display for all but image
    db_query("INSERT INTO {filefield_paths} (type, field, filename, filepath, filealias) VALUES ('%s', '%s', '%s', '%s', '%s')", $type, "upload", serialize($file_name), serialize($file_path), serialize($file_alias));
  }
  
  //set the "filefield" paths
  reset($types);
  foreach ( content_fields() as $field ) {
    if (($field['module'] == 'filefield') && in_array($field['type_name'], $types)) {
      //add settings to database if applicable
      $alias = (empty($field['widget']['module']) || $field['widget']['module'] != 'imagefield')? serialize($file_alias):"";
      db_query("INSERT INTO {filefield_paths} (type, field, filename, filepath, filealias) VALUES ('%s', '%s', '%s', '%s', '%s')", $field['type_name'], $field['field_name'], serialize($file_name), serialize($file_path), $alias);
    }
  }
  
}

/**
 * Get an array of 'group_posts' content types names
 */
function _openscholar_group_posts(){
  //$types = og_get_types('group_post');  // not working !
  
  // get all 'group_post' content types
  $group_types = array();
  $map = spaces_features_map('node');
  $features = spaces_features('og');
  foreach ( $map as $type => $feature ) {
    if (! empty($features[$feature])) {
      $group_types[] = $type;
    }
  }
  
  return $group_types;
}

/**
 * Create the taxonomy's that will be used by the vsite object
 * @return success
 */
function _openscholar_vsite_vocabs($vsite_node_type){
  
  install_include(array(
    'taxonomy'
  ));
  
  // Create the vsite tax for affiliation
  $vocab = array(
    'name' => 'Affiliation / Department',
    'multiple' => 1,
    'required' => 0,
    'hierarchy' => 0,
    'relations' => 0,
    'module' => 'taxonomy',
    'weight' => 0,
    'nodes' => array(
      $vsite_node_type => 1
    ),
    'tags' => false,
    'help' => t('Affiliation'),
    'description' => t("A comma-separated list of affiliation that your site may have, for ex.(Math department)")
  );
  taxonomy_save_vocabulary($vocab);
  
  $vid = db_last_insert_id('vocabulary', 'vid');
  variable_set('vsite_taxonomy_affiliation', $vid);
  
  // Create the vsite tax for intrests
  $vocab = array(
    'name' => 'Related Interests',
    'description' => t("A comma-separated list of topics that may relate to the content of your site. ex.(zoology, evolutionary biology, casual inference)"),
    'multiple' => 0,
    'required' => 0,
    'hierarchy' => 0,
    'relations' => 0,
    'module' => 'taxonomy',
    'weight' => 0,
    'nodes' => array(
      $vsite_node_type => 1
    ),
    'tags' => TRUE,
    'help' => t("A comma-separated list of topics that may relate to the content of your site. ex.(zoology, evolutionary biology, casual inference)"),
  );
  taxonomy_save_vocabulary($vocab);
  
  $vid = db_last_insert_id('vocabulary', 'vid');
  variable_set('vsite_taxonomy_interests', $vid);
}


/**
 * Reimplementation of system_theme_data(). The core function's static cache
 * is populated during install prior to active install profile awareness.
 * This workaround makes enabling themes in profiles/[profile]/themes possible.
 */
function _openscholar_system_theme_data() {

  // Find themes
  $themes = drupal_system_listing('\.info$', 'themes');
  // Find theme engines
  $engines = drupal_system_listing('\.engine$', 'themes/engines');

  $defaults = system_theme_default();

  $sub_themes = array();
  // Read info files for each theme
  foreach ($themes as $key => $theme) {
    $themes[$key]->info = drupal_parse_info_file($theme->filename) + $defaults;

    // Invoke hook_system_info_alter() to give installed modules a chance to
    // modify the data in the .info files if necessary.
    drupal_alter('system_info', $themes[$key]->info, $themes[$key]);

    if (!empty($themes[$key]->info['base theme'])) {
      $sub_themes[] = $key;
    }
    if (empty($themes[$key]->info['engine'])) {
      $filename = dirname($themes[$key]->filename) .'/'. $themes[$key]->name .'.theme';
      if (file_exists($filename)) {
        $themes[$key]->owner = $filename;
        $themes[$key]->prefix = $key;
      }
    }
    else {
      $engine = $themes[$key]->info['engine'];
      if (isset($engines[$engine])) {
        $themes[$key]->owner = $engines[$engine]->filename;
        $themes[$key]->prefix = $engines[$engine]->name;
        $themes[$key]->template = TRUE;
      }
    }

    // Give the stylesheets proper path information.
    $pathed_stylesheets = array();
    foreach ($themes[$key]->info['stylesheets'] as $media => $stylesheets) {
      foreach ($stylesheets as $stylesheet) {
        $pathed_stylesheets[$media][$stylesheet] = dirname($themes[$key]->filename) .'/'. $stylesheet;
      }
    }
    $themes[$key]->info['stylesheets'] = $pathed_stylesheets;

    // Give the scripts proper path information.
    $scripts = array();
    foreach ($themes[$key]->info['scripts'] as $script) {
      $scripts[$script] = dirname($themes[$key]->filename) .'/'. $script;
    }
    $themes[$key]->info['scripts'] = $scripts;
    // Give the screenshot proper path information.
    if (!empty($themes[$key]->info['screenshot'])) {
      $themes[$key]->info['screenshot'] = dirname($themes[$key]->filename) .'/'. $themes[$key]->info['screenshot'];
    }
  }

  // Now that we've established all our master themes, go back and fill in
  // data for subthemes.
  foreach ($sub_themes as $key) {
    $themes[$key]->base_themes = system_find_base_themes($themes, $key);
    // Don't proceed if there was a problem with the root base theme.
    if (!current($themes[$key]->base_themes)) {
      continue;
    }
    $base_key = key($themes[$key]->base_themes);
    foreach (array_keys($themes[$key]->base_themes) as $base_theme) {
      $themes[$base_theme]->sub_themes[$key] = $themes[$key]->info['name'];
    }
    // Copy the 'owner' and 'engine' over if the top level theme uses a
    // theme engine.
    if (isset($themes[$base_key]->owner)) {
      if (isset($themes[$base_key]->info['engine'])) {
        $themes[$key]->info['engine'] = $themes[$base_key]->info['engine'];
        $themes[$key]->owner = $themes[$base_key]->owner;
        $themes[$key]->prefix = $themes[$base_key]->prefix;
      }
      else {
        $themes[$key]->prefix = $key;
      }
    }
  }

  // Extract current files from database.
  system_get_files_database($themes, 'theme');
  db_query("DELETE FROM {system} WHERE type = 'theme'");
  foreach ($themes as $theme) {
    $theme->owner = !isset($theme->owner) ? '' : $theme->owner;
    db_query("INSERT INTO {system} (name, owner, info, type, filename, status, throttle, bootstrap) VALUES ('%s', '%s', '%s', '%s', '%s', %d, %d, %d)", $theme->name, $theme->owner, serialize($theme->info), 'theme', $theme->filename, isset($theme->status) ? $theme->status : 0, 0, 0);
  }
}


function _openscholar_wysiwyg_presets(){
  $settings = array();

  
  $settings['Filtered HTML'] = array(
    'default' => 1,
    'user_choose' => 0,
    'show_toggle' => 1,
    'theme' => 'advanced',
    'language' => 'en',
    'buttons' => array(
      'default' => array(
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
        'charmap' => 1
      ),
      
      'font' => array(
        'formatselect' => 1
      ),
      'fullscreen' => array(
        'fullscreen' => 1
      ),
      'paste' => array(
        'pastetext' => 1
      ),
      'table' => array(
        'tablecontrols' => 1
      ),
      'safari' => array(
        'safari' => 1
      ),
      'drupal' => array(
        'break' => 1
      )
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
    'css_classes' => ''
  );
  
  return $settings;
}
