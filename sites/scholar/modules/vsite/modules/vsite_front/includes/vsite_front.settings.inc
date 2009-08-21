<?php

/**
 * Provides front page settings for each site
 */
class vsite_front_settings_front implements space_setting {
  var $id;
  function __construct($id = NULL) {
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'front';
    }
  }

  function form($space, $value = array()) {
  $space = spaces_get_space();

  scholar_include('nodeautocomplete');
  scholar_include('scholarapi');
  ctools_include ('dependent');
  ctools_include ('form');
  
  // the "add new *" links
  $items = scholar_create_links();
  $links = theme ( 'ctools_dropdown', t ( 'add new' ), $items, FALSE, 'panels-display-links' );
  
  $form = array(
    '#title' => 'Front Page',
  );


  /**
   * main options
   * 1. your bio page
   * 2. one of your feature / content types 
   * 3. one of your posts
   * 4. Hand-pick as you go
   */
  $form  ['frontpage'] = array (
    '#title' => t ( 'What do you want in the main content area of your front page?' ), 
    '#type' => 'radios', 
    '#options' => array (
      'bio' => t('Your bio page'), 
      'feature' => t ('Posts from specific feature(s)'), 
      'html' => t ('One of your posts'),
      'flag' => t('Hand-pick content as you go'), 
    ), 
    '#default_value' => isset($value['frontpage']) ? $value['frontpage'] : 'bio' , 
    '#tree' => TRUE 
  );
  
  // dependencies  
  /*
  $form['bio'] = array(
    '#input' => TRUE,
    '#type' => 'item',
    '#description' => $description,
    '#process' => array ('ctools_dependent_process' ),
    '#dependency' => array ('radio:settings[front][frontpage]' => array ('bio' ) ),
  );
  */
  
    // do they have any bio settings?
  $bio_nid = (isset($space -> settings['bio']['nid']) && is_numeric($space -> settings['bio']['nid'])) ? $space -> settings['bio']['nid'] : '';
  if ($bio_nid){
    $link = l('bio', "node/$bio_nid");
    $description = "Your " . $link . " will be used as your front page";
  } else {
    $link = l(t('Create'), "node/add/page" , array('query' => array('frontpage' => 'true'))); //added option in url to indicate bio will be on frontpage
    $description = "You dont have a bio yet. $link one now"; 
  }
  
  // do they want to include the bio title
  $form['bio_title'] = array(
    '#prefix' => '<div id="edit-settings-front-bio-title-wrapper" class="description">' . $description,
    '#suffix' => '</div>',
    '#type' => 'checkbox',
    '#title' => t('Include title'),
    '#description' => t('Do you want to include the title of the post in the page?'),
    '#default_value' => $value['bio_title'] ? $value['bio_title'] : 0,
    '#process' => array ('ctools_dependent_process' ),
    '#dependency' => array ('radio:settings[front][frontpage]' => array ('bio' ) ),
  );
  
  // post
  $auto_element = scholar_node_autocomplete_element("Select a post");
  $auto_element['#description'] = t('Select the post your want to set as a front page or create a new one') . $links;
  $auto_element['#process'] = array ('ctools_dependent_process' ); 
  $auto_element['#dependency'] = array ('radio:settings[front][frontpage]' => array ('html'));
  $def_node = intval($value['front_nid'])?node_load($value['front_nid']):false;
  if($def_node) $auto_element['#default_value'] = $def_node->title." [nid:{$value['front_nid']}]";
  
  $form['front_nid'] = $auto_element;

  $options = scholar_content_types();
  $default_value = $value['node_options'] ? array_keys(array_filter($value['node_options'])) : array_keys($options);
  //dpm(array_filter($value['node_options'], '__cp_nonzero' ));
  $form['node_options'] = array(
		'#prefix' => '<div id="edit-settings-front-node-options-wrapper">',  // needed by ctools
  	'#suffix' => '</div>',
  	'#type' => 'checkboxes',
  	'#title' => t('Select features / content types'),
  	'#options' => $options,
    '#default_value' => $default_value,
  	'#description' => t('Select the content types .... TODO better descriptions here'),
    '#process' => array ('expand_checkboxes', 'ctools_dependent_process' ), 
    '#dependency' => array ('radio:settings[front][frontpage]' => array ('feature' ) ) 
  );
  

  
  return $form;
  }

  function validate($space, $value) {
  	switch ($value['frontpage']){
      case 'bio':
      	$bio_nid = (isset($space -> settings['bio']['nid']) && is_numeric($space -> settings['bio']['nid'])) ? $space -> settings['bio']['nid'] : '';
        if(!$bio_nid) form_set_error('frontpage',"You must create a bio before you can select this option");
      break;
      case 'feature':
      	$exists = false;
      	foreach ($value['node_options'] as $opt) if($opt) $exists = true;
      	if(!$exists) form_set_error('frontpage',"You must select at least one feature.");
      break;
      case 'html':
      	if(!$value['front_nid'] || !preg_match("/\[nid:\d+\]/",$value['front_nid'])){
      		form_set_error('frontpage',"You must select a post to display.");
      	} 
      break;
      case 'flag':
      default:
      	//do nothing        
    }
    return $value;

  
  }

  function submit($space, $value) {
    $save = array('frontpage' => $value['frontpage']);
  	switch ($value['frontpage']){
      case 'bio':
        //nothing extra to save  
      break;
      case 'feature':
      	$save['node_options'] = $value['node_options'];
      break;
      case 'html':
      	$matches=array();
        preg_match("/\[nid:\d+\]/",$value['front_nid'],$matches);
        $save['front_nid'] = substr($matches[0],5,-1);
      break;
      case 'flag':
        //nothing extra to save  
      break;        
    }
    return $save;
  }
}

function __cp_nonzero($el){
  print_r($el);
  return $el != 0 ? TRUE : FALSE;
}

/**
 * return "add content type" links
 * TODO: What would be the right condition for excluding 
 * some content types here. For example, if a content type
 * is part of a feature that user has not selected, that 
 * content type should not be part of the list
 */
function scholarfront_create_links() {
  global $user;
  $site = spaces_get_space();
  
  $post_types = og_get_types('group_post');
  $types = node_get_types();
  foreach ($post_types as $post_type) {
    $type_name = $types[$post_type]->name;
    $type_url_str = str_replace('_', '-', $post_type);
    if (module_invoke($types[$post_type]->module, 'access', 'create', $post_type, $user)) {
      $links[] = array(
        'title' => t('!type', array('!type' => $type_name)),
        'href' => "node/add/$type_url_str",
      );
    }
  }
  return isset($links) ? $links : array();
}