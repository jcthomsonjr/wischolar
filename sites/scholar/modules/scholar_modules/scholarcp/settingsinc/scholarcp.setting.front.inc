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

  //dpm(spaces_settings());
  scholar_include('nodeautocomplete');
  scholar_include('scholarapi');
  ctools_include ('dependent' );
  ctools_include ('form' );
  

  
  // the "add new *" links
  $items = scholar_create_links();
  $links = theme ( 'ctools_dropdown', t ( 'add new' ), $items, FALSE, 'panels-display-links' );
  
  // main options
  $form = array (
		//'#prefix' => '<div id="edit-settings-wrapper">',
  	//'#suffix' => '</div>',
    '#title' => t ( 'Front page -- trying' ), 
    '#type' => 'radios', 
    '#options' => array (
      'bio' => t('Your Bio page'), 
      'feature' => t ('Posts from some specific feature(s)'), 
      'post' => t ('One of your posts'),
      'flagedposts' => t('Hand-pick content as I go'), 
    ), 
    //'#default_value' => isset($value) ? $value : 'bio' , 
    '#tree' => TRUE 
  );
  
  // post
  $auto_element = scholar_node_autocomplete_element();
  $auto_element['#description'] = t ( 'Select the post your want to set as a front page or create a new one' ) . $links;
  $auto_element['#process'] = array ('ctools_dependent_process' ); 
  $auto_element['#dependency'] = array ('radio:settings[front]' => array ('post' ) );
  
  $form['front_nid'] = $auto_element;
  
  $options = array(
    'news' => 'News',
    'announcements' => 'Announcements',
  );


  
  // bio
  $form['bio1'] = array(
  '#input' => TRUE,
  '#type' => 'item',
  '#value' => t('create a new one ... etc...'),
  '#process' => array ('ctools_dependent_process' ),
  '#dependency' => array ('radio:settings[front]' => array ('bio' ) ),
  );
  
  dpm($form);
  return $form;
  }

  function validate($space, $value) {

  }

  function submit($space, $value) {
    return $value;
  }
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