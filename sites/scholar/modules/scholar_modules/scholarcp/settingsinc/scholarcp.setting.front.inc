<?php

/**
 * Provides theme selection for each site
 */
class scholarcp_setting_front implements space_setting {
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
  


  /**
   * main options
   * 1. your bio page
   * 2. one of your feature / content types 
   * 3. one of your posts
   * 4. Hand-pick as you go
   */
  $form  ['frontpage'] = array (
    '#title' => t ( 'Front page options' ), 
    '#type' => 'radios', 
    '#options' => array (
      'bio' => t('Your Bio page'), 
      'feature' => t ('Posts from some specific feature(s)'), 
      'html' => t ('One of your posts'),
      'flag' => t('Hand-pick content as I go'), 
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
    $link = l('Create', "node/add/page");  // TODO add a variable here (in option) ?frontpage=yes ..etc
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
  $auto_element = scholar_node_autocomplete_element();
  $auto_element['#description'] = t('Select the post your want to set as a front page or create a new one') . $links;
  $auto_element['#process'] = array ('ctools_dependent_process' ); 
  $auto_element['#dependency'] = array ('radio:settings[front][frontpage]' => array ('html'));
  
  $form['front_nid'] = $auto_element;

  $options = scholar_content_types();
  $default_value = $value['node_options'] ? array_keys(array_filter($value['node_options'])) : array_keys($options);
  //dpm(array_filter($value['node_options'], '__scholarcp_nonzero' ));
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

  }

  function submit($space, $value) {
    switch ($value['frontpage']){
      case 'bio':
        $value['node_options'] = array();
        break;
      case 'feature':
        break;
      case 'html':
        $value['bio_title'] = '';
        break;
      case 'flag':
        break;        
    }
    dpm($space);
    dpm($value);
    return $value;
  }
}

function __scholarcp_nonzero($el){
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