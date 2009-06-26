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
    'filefield_paths',
    'jquery_ui', 
    'token',
    'views', 
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
    'imagecache',
    'imagecache_ui',
    'imagefield',
    'text',


  // development
    'admin_menu',
    'ctools',
    'devel',
    'install_profile_api', 
  
  // scholar specific
    'biblio',
    'scholarforms',
  );

  return array_merge($core_modules, $contrib_modules);
}


function _scholar_core_modules(){
  return array('color', 'comment', 'help', 'menu','block', 'filter', 'node', 'system', 'user', 'path','php');
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
}

/**
 * hook profile_tasks
 */
function scholar_profile_tasks(&$task, $url) {


  install_include(scholar_profile_modules());
  
  // create roles
  _scholar_create_roles();

  //scholar_profile_create_content_types();

  // configure modules  (variables table mainly)

  // set the theme


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
 * Implementation of hook_form_alter().
 *
 * Allows the profile to alter the site-configuration form. This is
 * called through custom invocation, so $form_state is not populated.
 */
function scholar_form_alter(&$form, $form_state, $form_id) {

  if ($form_id == 'install_configure') {
    //print_r($form);
    // Set default for site name field.
    $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
    // dont check for updates automatically
    $form['server_settings']['update_status_module']['#default_value'] = 0;
  }
}


