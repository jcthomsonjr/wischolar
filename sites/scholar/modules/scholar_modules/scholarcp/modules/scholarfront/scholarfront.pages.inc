<?php

/**
 * frontpage form definition
 */
function scholarcp_frontpage_form(){
  $space = spaces_get_space();

  //dpm(spaces_settings());
  scholar_include('nodeautocomplete');
  scholar_include('scholarapi');
  ctools_include ( 'dependent' );
  ctools_include ( 'form' );
  
  // the outer fieldset
  $form ['frontpage_settings'] = array (
  	'#type' => 'fieldset', 
  	'#title' => t ( 'Menu settings' ), 
  	'#tree' => TRUE 
  );
  
  // the "add new *" links
  $items = scholar_create_links();
  $links = theme ( 'ctools_dropdown', t ( 'add new' ), $items, FALSE, 'panels-display-links' );
  
  $default_value = 'feature';

  if (isset($form_state['post']['frontpage_settings']['frontpage'])){
    dpm('yes');
    
    $default_value = $form_state['post']['frontpage_settings']['frontpage'];
    dpm($default_value . 'xxx');
  }

  // main options
  $form ['frontpage_settings'] ['frontpage'] = array (
    '#title' => t ( 'What do you want in the main content area of your front page?' ), 
    '#type' => 'radios', 
    '#options' => array (
      'bio' => t('Your Bio page'), 
      'feature' => t ('Posts from some specific feature(s)'), 
      'post' => t ('One of your posts'),
      'flagedposts' => t('Hand-pick content as I go'), 
    ), 
    '#default_value' => isset($default_value) ? $default_value : 'bio' , 
    '#tree' => TRUE 
  );
  
  // dependencies
  
  // post
  $auto_element = scholar_node_autocomplete_element();
  $auto_element['#description'] = t ( 'Select the post your want to set as a front page or create a new one' ) . $links;
  $auto_element['#process'] = array ('ctools_dependent_process' ); 
  $auto_element['#dependency'] = array ('radio:frontpage_settings[frontpage]' => array ('post' ) );
  
  $form ['frontpage_settings'] ['front_nid'] = $auto_element;


  $options = array(
    'news' => t('News'),
    'announcements' => t('Announcements'),
  );

  $form['frontpage_settings']['node_options'] = array(
		'#prefix' => '<div id="edit-frontpage-settings-node-options-wrapper">',
  	'#suffix' => '</div>',
  	'#type' => 'checkboxes',
  	'#title' => t('Default options'),
  	'#options' => $options,
    '#default_value' => array_keys($options),
  	'#description' => t('Users with the <em>administer nodes</em> permission will be able to override these options.'),
    '#process' => array ('expand_checkboxes', 'ctools_dependent_process' ), 
    '#dependency' => array ('radio:frontpage_settings[frontpage]' => array ('feature' ) ) 
  );
  
  // bio
  $form['frontpage_settings']['bio'] = array(
  '#input' => TRUE,
  '#type' => 'item',
  '#value' => t('create a new one ... etc...'),
  '#process' => array ('ctools_dependent_process' ),
  '#dependency' => array ('radio:frontpage_settings[frontpage]' => array ('bio' ) ),
  );
  
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value'=> t('submit'),
  );

  return $form;
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

function scholarcp_frontpage_form_submit($form, &$form_state){
  switch ($form_state['values']['frontpage_settings']['frontpage']) {
  	case 'feature':
  	  dpm('feature');
  	break;
  	
  	case 'bio':
  	  dpm('bio');
  	break;
  	
  	case 'post':
  	  dpm('post');
  	break;
  	
  	case 'flaggedposts':
  	  dpm('flagged posts');
  	break;
  }
  
  //dpm($form_state);
}
