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
    'context',
    'context_contrib',
    'context_ui',
    'filefield_paths',
    'features',
    'imageapi',
    'imageapi_gd',
    'jquery_ui',
    'og',
    'og_access',
    'og_views', 
    'purl',
    'spaces',
    'spaces_og',
    'token',
    'transliteration',
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
  return array(
    'block', 
    'blog',
  	'comment', 
    'filter', 
  	'help', 
  	'menu',
  	'node', 
  	'system', 
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
  );
}

/**
 * hook profile_tasks
 */
function scholar_profile_tasks(&$task, $url) {
  include_once(dirname(__FILE__) . '/scholar.forms.inc');

  if ($task == 'profile'){

    install_include(scholar_profile_modules());

    // create roles
    _scholar_create_roles();
    // rebuild access (required by og)
    _scholar_access_rebuild();
    // create default content types
    _scholar_profile_content_types();
    // configure modules  (variables table mainly)
    // set the theme

    $task = 'scholar_features';
    return drupal_get_form('scholar_get_features_info', $url);
    //drupal_set_title('helllo form');
    //return drupal_get_form('myform', $url);
  }

  if ($task == 'scholar_features'){
    $form = drupal_get_form('scholar_get_features_info', $url);    
    if (variable_get('scholar_features', FALSE)){
       variable_del('scholar_features');
       $task = 'profile-finished';
      // see if the form was processed
    }
    else {
      return $form;
    }
  }

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
  $node_type_name = 'scholar_site';
  
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
    // TODO this is not working 
    //$form['server_settings']['update_status_module']['#default_value'] = 0;
  }
}



function myform($form_state, $url){

  $form['#action'] = $url;
  $form['#redirect'] = FALSE;
  $form['department_code'] = array(
    '#type' => 'select',
    '#title' => st('Departmental code'),
    '#description' => st('Please select the correct code for your department.'),
    '#options' => array('BIOL', 'CHEM', 'COMP', 'ENGI', 'ENGL', 'HIST', 'MATH', 'LANG', 'PHYS', 'PHIL'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Save and Continue'),
    //'#submit' => 'myform_submit',
  
  );
  

  return $form;

}

function myform_submit($form, &$form_state) {
     global $redirect_url;
  variable_set('department_code', $form_state['values']['department_code']);

    drupal_goto($redirect_url);
   
}
