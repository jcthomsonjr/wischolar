<?php
// $Id: template.php,v 1.2 2008/12/23 15:36:05 falimadh Exp $


/**
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return a string containing the breadcrumb output.
 */
function iqss_base_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
// uncomment the next line to enable current page in the breadcrumb trail
//    $breadcrumb[] = drupal_get_title();
	unset($breadcrumb[0]);
	array_unshift($breadcrumb, array_shift($breadcrumb) );
    return '<div class="breadcrumb">'. implode('', $breadcrumb) .'</div>';
  }
}

/**
 * Allow themable wrapping of all comments.
 */
function iqss_base_comment_wrapper($content, $node) {
  if (!$content || $node->type == 'forum') {
    return '<div id="comments">'. $content .'</div>';
  }
  else {
    return '<div id="comments"><h2 class="comments">'. t('Comments') .'</h2>'. $content .'</div>';
  }
}

/**
 * Modify theme variables
 */
function phptemplate_preprocess(&$vars) {
	//dpm('hook preprocess');
  /**
   * Convention: The roles are single words or separated 
   * with space (no underscore, e.g. "site admin" not site_admin)
   * In your template file you should be able to write:
   * if ($is_site_admin) {
   * 	....
   * }
   * And that's for any role!
   */
  global $user;                                            // Get the current user
  
  $all_roles = user_roles();
  foreach ($all_roles as $role) {
    $tmp = explode(" ", $role);
    $vars['is_'.implode('_',$tmp)] = in_array($role, $user -> roles);
  }
  
  //dpm($vars);
  // special case: is the user logged in?
  $vars['logged_in'] = ($user->uid > 0) ? TRUE : FALSE;
}

function phptemplate_preprocess_node(&$vars) {

	// body classes
	
	// Build array of handy node classes
	$node_classes = array();
	$node_classes[] = $vars['zebra'];                                      // Node is odd or even
	$node_classes[] = (!$vars['node']->status) ? 'node-unpublished' : '';  // Node is unpublished
	$node_classes[] = ($vars['sticky']) ? 'sticky' : '';                   // Node is sticky
	$node_classes[] = (isset($vars['node']->teaser)) ? 'teaser' : 'full-node';    // Node is teaser or full-node
	$node_classes[] = 'node-type-'. $vars['node']->type;                   // Node is type-x, e.g., node-type-page
	

	
	$node_classes = array_filter($node_classes);                           // Remove empty elements
	$vars['swapbase_node_classes'] = implode(' ', $node_classes);                   // Implode class list with spaces


	// Node Links. Add links here if we want!
	//dpm($vars['node']->links);
	 
	$vars['links'] = theme('links', $vars['node']->links, array('class' => 'links inline')); 
}

/**
 * Hook preprocess_page for this theme
 *
 * @param unknown_type $vars
 */
function phptemplate_preprocess_page(&$vars){
  $body_classes = array();
   
    
    
	if (arg(0) == "node" && is_numeric(arg(1)) && arg(2) == "edit"){
	  $body_classes[] = "node-edit-mode";
	  $n = node_load(array('nid' => arg(1)));
	  $n_type = $n -> type;
	  $vars['body_classes'] = str_replace("node-type-" . $n_type, "node-type-".$n_type . '-edit',$vars['body_classes']);
	}
	
	if (arg(0) == "node" && arg(1) == "add"){
	  $body_classes[] = "node-add-mode";
	}

	 $vars['body_classes'] = $vars['body_classes'] . ' '. implode(' ', $body_classes);
	
	
	
	if ($vars['is_front']) {
	  $vars['body_classes'] = str_replace("page-node",'',$vars['body_classes']);
	}

}

/**
 * Returns the rendered local tasks. The default implementation renders
 * them as tabs. Overridden to split the secondary tasks.
 *
 * @ingroup themeable
 */
function iqss_base_menu_local_tasks() {
  return menu_primary_local_tasks();
}

function iqss_base_comment_submitted($comment) {
  return t('by <strong>!username</strong> | !datetime',
    array(
      '!username' => theme('username', $comment),
      '!datetime' => format_date($comment->timestamp)
    ));
}

function iqss_base_node_submitted($node) {
  return t('by <strong>!username</strong> | !datetime',
    array(
      '!username' => theme('username', $node),
      '!datetime' => format_date($node->created, 'custom', 'F j, Y'),
    ));
	}

/**
 * Override username theming
 */
/**
 * Override username theming to display/hide 'not verified' text
 */
function phptemplate_username($object) {
  if ($object->uid && $object->name) {
        //defaults
    	$name = $object->name;
    	$link = 'user/'. $object->uid;
        
     // if content profile then show firstname lastname
    if (module_exists('content_profile')){
    	if ($profile_node = content_profile_load('profile', $object -> uid)){
    	//dpm($profile_node);
    	$name = $profile_node -> field_profile_firstname[0]['value'] . " ". 
    	        $profile_node -> field_profile_lastname[0]['value'];
    	 $link = "node/".$profile_node -> nid;
    	}
    }

    
    // Shorten the name when it is too long or it will break many tables.
    if (drupal_strlen($object->name) > 20) {
      $name = drupal_substr($object->name, 0, 15) .'...';
    }
    
    if (user_access('access user profiles')) {
      $output = l($name, $link, array('attributes' => array('title' => t('View user profile.'))));
    }
    else {
      $output = check_plain($name);
    }
  }
  else if ($object->name) {
    // Sometimes modules display content composed by people who are
    // not registered members of the site (e.g. mailing list or news
    // aggregator modules). This clause enables modules to display
    // the true author of the content.
    if (!empty($object->homepage)) {
      $output = l($object->name, $object->homepage, array('attributes' => array('rel' => 'nofollow')));
    }
    else {
      $output = check_plain($object->name);
    }
    // Display or hide 'not verified' text
    if (theme_get_setting('user_notverified_display') == 1) {
      $output .= ' ('. t('not verified') .')';
    }
  }
  else {
    $output = variable_get('anonymous', t('Anonymous'));
  }
  return $output;
}



/**
 * Generates IE CSS links.
 */
function iqss_base_get_ie_styles() {
  $iecss = '<link type="text/css" rel="stylesheet" media="all" href="'. base_path() . path_to_theme() .'/fix-ie.css" />';
  return $iecss;
}

function iqss_base_get_ie6_styles() {
  $iecss = '<link type="text/css" rel="stylesheet" media="all" href="'. base_path() . path_to_theme() .'/fix-ie6.css" />';
  return $iecss;
}

/**
 * Override from imagefield module. We want 
 * to have the name of the file in the image preview thumbnail
 *
 * @param unknown_type $item
 * @return unknown
 */
function phptemplate_imagefield_admin_thumbnail($item = null) {
  if (is_null($item) || empty($item['filepath'])) {
    return '<!-- link to default admin thumb -->';
  }
  $thumb_path = imagefield_file_admin_thumb_path($item);
  return '<div id="'.basename($item['filepath']).'" class="swap-inline"><img src="'. file_create_url($thumb_path) .'" />'.'<p class="hmdc-inline">'.basename($item['filepath']).' (duble click the image to include it in the content area (inline))</p></div>';
}

