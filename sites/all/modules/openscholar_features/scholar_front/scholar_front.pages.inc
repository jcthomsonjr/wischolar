<?php

/**
 * Settings form for configureing your scholar front page
 * @param vsite $space
 */
function scholar_front_settings($form_state) {

	$vsite = vsite_get_vsite();
	vsite_include('nodeautocomplete');
  vsite_include('vsiteapi');
  ctools_include('dependent');
  ctools_include('form');

  $form['frontpage'] = array(
    '#type' => 'fieldset',
  );

  $front_page = variable_get('site_frontpage', 'scholar_front/features');
  $spaces_features = variable_get('spaces_features',array());

  $options = array(
    'scholar_front/features' => t('Posts from specific feature(s)'),
    'html' => t('Use an Existing or Create a new post'),
    'path' => t('Enter a path'),
    'scholar_front/flag' => t('Hand-pick content as you go')
  );

  $s_bio_option;
  if (($bio_node = content_profile_load("bio", $vsite->group->uid)) && $spaces_features['scholar_biocv']){
    $options["node/".$bio_node->nid] = t('Your bio page');
    if($front_page == "scholar_front_welcome") $front_page = "node/".$bio_node->nid;
  }elseif ($spaces_features['scholar_biocv']){
  	$options["create_bio"] = t('Your bio page');
  	if($front_page == "scholar_front_welcome") $front_page = "create_bio";
  }

  $def_html_node = false;
  if(!isset($options[$front_page]) && ($menu_item = menu_get_item($front_page)) && $menu_item['path'] == "node/%"){
  	$def_html_node = $menu_item['page_arguments'][0];
  	$front_page = 'html';
  }

  $s_html_path = "";
  if(strlen($front_page) && !isset($options[$front_page])){
  	$s_html_path = $front_page;
  	$front_page = 'path';
  }

  $form['frontpage']['site_frontpage'] = array(
    '#type' => 'select',
    '#options' => $options,
    '#title' => t('What do you want in the main content area of your front page?'),
    '#default_value' => isset($options[$front_page]) ? $front_page : $s_bio_option,
    '#element_validate' => array('scholar_front_settings_validate'),
  );

  $items = vsite_create_links();
  foreach($items as &$item){
    $item['query'] = 'action=setfront';
  }

  // Do they want to Select A Post
  $form['frontpage']['scholar_front_frontpage_nid'] = vsite_node_autocomplete_element("Select a post");
  $form['frontpage']['scholar_front_frontpage_nid']['#element_validate'] = array('scholar_front_settings_frontpage_nid_validate');
  $form['frontpage']['scholar_front_frontpage_nid']['#description'] = t('Select the post your want to set as a front page or create a new one') .
                                                         theme('ctools_dropdown', t('add new'), $items, FALSE, 'context-links');
  $form['frontpage']['scholar_front_frontpage_nid']['#process'] = array('ctools_dependent_process');
  $form['frontpage']['scholar_front_frontpage_nid']['#dependency'] = array('edit-site-frontpage' => array('html'));

  if ($def_html_node) $form['frontpage']['scholar_front_frontpage_nid']['#default_value'] = $def_html_node->title . " [nid:{$def_html_node->nid}]";

  // Do they want to Select A Post
  $form['frontpage']['scholar_front_frontpage_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter a path'),
    '#maxlength' => 80,
    '#field_prefix' => $vsite->get_absolute_url(),
    '#description' => t('Enter the path to the page that you would like to display as the homepage. Do not re-enter ('.$vsite->get_absolute_url().')'),
    '#default_value' => $s_html_path,
  );
  $form['frontpage']['scholar_front_frontpage_path']['#process'] = array('ctools_dependent_process');
  $form['frontpage']['scholar_front_frontpage_path']['#dependency'] = array('edit-site-frontpage' => array('path'));

  if ($def_html_node) $form['scholar_front_frontpage_nid']['#default_value'] = $def_html_node->title . " [nid:{$def_html_node->nid}]";


  //If they have selected bio/node as feature
  $form['frontpage']['scholar_front_show_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include title'),
    '#description' => t('Do you want to include the post/page title on the front page?'),
    '#default_value' => variable_get('scholar_front_show_title',1),
    '#process' => array('ctools_dependent_process'),
    '#dependency' => array(
      'edit-site-frontpage' => array("node/".$bio_node->nid, "html", "path")),
  );

  $bio_create_link = l(t('Create'), "node/add/bio", array('query' => array('action' => 'setfront')));

  //If they have selected bio/node as feature
  $form['scholar_front_create_bio'] = array(
    '#prefix' => '<div id="edit-scholar-front-create-bio-wrapper">',  // needed by ctools
    '#suffix' => '</div>',
    '#type' => 'fieldset',
    '#title' => "Create a Bio",
    '#input' =>true,
    '#process' => array('ctools_dependent_process'),
    '#dependency' => array('edit-site-frontpage' => array("create_bio")),
    '#collapsable' => false,
  );
  $form['scholar_front_create_bio']['link']['#value'] = "<p>You dont have a bio yet. $bio_create_link one now.</p>";

  $form['scholar_front_hand_pick_help'] = array(
    '#prefix' => '<div id="edit-scholar-front-hand-pick-help-wrapper">',  // needed by ctools
    '#suffix' => '</div>',
    '#type' => 'fieldset',
    '#title' => "Using: Hand Picked Content",
    '#input' =>true,
    '#process' => array('ctools_dependent_process'),
    '#dependency' => array('edit-site-frontpage' => array("scholar_front/flag")),
    '#collapsable' => false,
  );
  $form['scholar_front_hand_pick_help']['link']['#value'] = "<p>When you save or edit a post select \"Promote to front page\" to include it on the front of your site.</p>";

  $options = vsite_content_types();
  drupal_alter('vsite_content_types', $options);

  $default_value = variable_get('scholar_front_feature_nodes',array_keys($options));

  $form['frontpage']['scholar_front_feature_nodes'] = array(
    '#prefix' => '<div id="edit-scholar-front-feature-nodes-wrapper">',  // needed by ctools
    '#suffix' => '</div>',
    '#type' => 'checkboxes',
    '#title' => t('Select features / content types'),
    '#options' => $options,
    '#default_value' => $default_value,
    '#description' => t("Select the features that you would like to provide content for your home page."),
    '#process' => array(
      'expand_checkboxes',
      'ctools_dependent_process'
    ),
    '#dependency' => array('edit-site-frontpage' => array('scholar_front/features')),
  );

  if (!($new_title = variable_get('scholar_front_site_title', ''))) {
    $vsite = vsite_get_vsite();
    $new_title = $vsite->group->title;
  }

  $form['site_title'] = array(
    '#type' => 'fieldset',
    'scholar_front_site_title' => array(
      '#type' => 'textfield',
      '#title' => t('Site Title'),
      '#description' => t('This title will appear in the title bar of your browser.'),
      '#default_value' => $new_title,
    ),
  );

  return system_settings_form($form);
}

function scholar_front_settings_validate($element, &$form_state){
	$vsite = vsite_get_vsite();

	switch ($element['#value']) {
      case 'scholar_front/features' :
        $exists = false;
        foreach ( $form_state['values']['scholar_front_feature_nodes'] as $opt )  if ($opt) $exists = true;

        if (! $exists) form_set_error('frontpage', "You must select at least one feature.");
        break;
      case 'html' :
        if (!$form_state['values']['scholar_front_frontpage_nid']) {
        	form_set_error('frontpage', "You must select a post to display.");
        }elseif (!($nid = _vsite_node_autocomplete_title_to_nid($form_state['values']['scholar_front_frontpage_nid']))){
        	form_set_error('scholar_front_frontpage_nid', "Unable to find the post entered.");
        }else{
        	$form_state['values']['site_frontpage'] = "node/".$nid;
        }
      break;
      case 'path' :
        if (!$form_state['values']['scholar_front_frontpage_path']) {
          form_set_error('frontpage', "You must enter a path to display.");
        }elseif(!(menu_get_item($form_state['values']['scholar_front_frontpage_path']) || drupal_lookup_path('source', $form_state['values']['scholar_front_frontpage_path'])) || $form_state['values']['scholar_front_frontpage_path'] == 'welcome'){
        	form_set_error('scholar_front_frontpage_path', "Unknown path, please make sure you did not include [{$vsite->get_absolute_url()}].");
        }else{
          $form_state['values']['site_frontpage'] = $form_state['values']['scholar_front_frontpage_path'];
        }
      break;
      case 'flag' :
      default :
      //do nothing
  }
}

function scholar_front_settings_frontpage_nid_validate($element, $form_state) {
  if ($form_state['values']['site_frontpage'] == 'html') {
    vsite_node_autocomplete_validate($element, $form_state);
  }
}


/**
 * Menu callback for post from features "home"
 *
 * @return the content to be rendered in the content area of the front page
 */
function scholar_front_features(){

	vsite_include('vsiteapi');
  $node_options = variable_get('scholar_front_feature_nodes', false);

  if (!$node_options){
    $node_options = vsite_content_types();
  }

  // they may have selected a feature that some module decided not to display
  // or that feature is not public anymore.
  drupal_alter('vsite_content_types', $node_options);

  //initialize the scholar base view
  $view = views_get_view('vsite_view_base');

  // add a filter for "node types" in the view
  $options = array();
  foreach($node_options as $type => $value){
    if ($value){
      $options[$type] = $type; // that's how views wants it
    }
  }

  $view -> display['default'] -> display_options['filters']['type'] = array(
    'operator' => 'in',
    'value' => $options,

    'group' => 0,
    'exposed' => FALSE,
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'relationship' => 'none',
  );
  $view->init();
  $view->set_display('default');
  $view -> execute();

  return  _scholar_front_admin_frontpage() . $view->render();
}



/**
 * Add the admin links and message box to the top of the vsite front page
 */
function _scholar_front_admin_frontpage(){
	  $vsite = vsite_get_vsite();
	  $result = '';

    $a_messages_confirmed_settings = variable_get('vsite_setting_messages_confirmed',array());
    if($vsite && $vsite->access_admin()  && (!is_array($a_messages_confirmed_settings)  || !$a_messages_confirmed_settings['welcome_message'])){

      $s_hide_link = l("Forever","cp/confirm_message/welcome_message",array('attributes'=>array('class'=>'hide'),'query' => array('source'=>$_GET['q']) ));
      $s_close_link = l("For now","",array('attributes'=>array('class'=>'close','onClick'=>'$("div#message_welcome_message").remove(); return false;')));

      $s_info = l("Add/edit your site information",'cp/settings/site_info/'.$vsite->id);
      $s_features = l("Enable or disable features for your site",'cp/build/features');
      $s_members = l("Manage who may use your site",'cp/users');
      $s_theme = l("Change the look of your site",'cp/appearance');
      $s_layout = l("Move elements in your page layout",'cp/build/layout');
      $s_docs = l("View documentation","help/vsitehelp/OpenScholar-Documentation");

      //Created in the last 26 hours?
      $s_welcome_message = (time() - $vsite->group->created < 93600)?"Welcome to your new website!":"";
      $s_short_message = (time() - $vsite->group->created < 93600)?"Not sure what to do now? Need help <span>getting started?</span>":"Need quick access to <span>common settings?</span>";
      drupal_add_js(drupal_get_path('module', 'vsite').'/theme/vsite.js', 'module');

      //Add Content
      $s_content = l("Add/manage content",'cp/content');
      $s_bio = ($vsite->access_feature($op = 'view', 'scholar_biocv') && !content_profile_load('bio', $vsite->group->uid))?"<li>".l("Add your bio",'node/add/bio',array('query' => array('destination'=>'biocv')))."</li>":"";
      $s_cv = ($vsite->access_feature($op = 'view', 'scholar_biocv')  && !content_profile_load('cv', $vsite->group->uid))?"<li>".l("Add your cv",'node/add/cv',array('query' => array('destination'=>'biocv')))."</li>":"";

      $result = <<<MESSAGE
      <div id="message_welcome_message">
        <div class="toggle">$s_short_message</div>
        <div id="welcome_wrapper" class="slider">
          <h3>{$s_welcome_message}</h3>
          <p>Below are a few additional resources to help you. You may access the control panel at any time by clicking the link in the top right corner of the screen.</p>
          <ul id="resource-list">
            <li>{$s_info}</li>
            <li>{$s_features}</li>
            <li>{$s_content}</li>
            <li>{$s_members}</li>
            <li>{$s_theme}</li>
            <li>{$s_layout}</li>
            {$s_bio}
            {$s_cv}
            <li>{$s_docs}</li>
          </ul>
          <div class="vsite-admin">
            <div class="toggle"><span>Hide this message</span></div>
            <div class="slider">
              <ul class="links">
                <li class="first">{$s_hide_link}</li>
                <li>{$s_close_link}</li>
              </ul>
            </div>
          </div>
        </div> <!-- SLIDER -->
      </div>
      {$result}
MESSAGE;
    }

    return $result;
}

/**
 * if front page is set to "flag"
 */
function scholar_front_home_flag(){
  return _scholar_front_admin_frontpage().
         views_page("scholar_front", "default");
}

/**
 * Redirect to the home page
 */
function scholar_front_redirect_home(){
	if(!drupal_is_front_page()){
	  drupal_goto("<front>");
	}
}

/**
 * Default front page when a site is created
 */
function scholar_front_welcome(){
	$vsite = vsite_get_vsite();
	if(!$vsite || !$vsite->access_admin()) return "";
	$spaces_features = variable_get('spaces_features',array());

	$bio_link = $spaces_features["scholar_biocv"]?l("Setup your bio now","node/add/bio")." or":"The bio feature is disabled";
	$front_settings = l("change the display settings","cp/features",array("query" => array("open_feature_settings" => "scholar_front")));
	$result = <<<MESSAGE
        <div id="welcome_front_wrapper">
          <h3>Welcome to your new site.</h3>
          <p>Your sites front page is set to display your bio by default.  {$bio_link} {$front_settings} for the front of your site.</p>
        </div>
MESSAGE;

    return _scholar_front_admin_frontpage().$result;
}