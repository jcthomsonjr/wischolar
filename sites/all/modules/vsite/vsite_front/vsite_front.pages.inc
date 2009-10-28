<?php

/**
 * Menu callback for "home"
 * Get the vsite home page settings and act accordingly
 * @return the content to be rendered in the content area of the front page
 */
function vsite_front_home(){

  $vsite = vsite_get_vsite();
  if ($vsite) {
    $front_type = $vsite->settings['front']['frontpage'];
    switch ($front_type) {
      case 'bio' :
        $bio_node = content_profile_load('bio', $vsite -> group -> uid, $lang = '');
        if ($vsite->settings['front']['bio_title']){
          drupal_set_title(t('%title', array('%title' => $bio_node->title)));
        }
        $result =  node_view($bio_node,false,true,false);

        break;
      case 'feature' :
        $node_options = $vsite->settings['front']['node_options'];
        // they may have selected a feature that some module decided not to display
        // or that feature is not public anymore.
        drupal_alter('vsite_content_types', $node_options);

        $result = vsite_front_home_feature($node_options);
        break;
      case 'html' :
        $front_nid = $vsite->settings['front']['front_nid'];
        $result = vsite_front_home_html($front_nid);
        break;
      case 'flag' :
        $result = vsite_front_home_flag();
        break;
    }

    //Add Site Name to the page title for the homepage
    //if(isset($vsite->settings['site']['headline'])) drupal_set_title(t(drupal_get_title().' | %site', array('%site' => $vsite->settings['site']['headline'])));

    if($vsite->admin_access()  && (!array_key_exists('messages_confirmed',$vsite->settings)  || !$vsite->settings['messages_confirmed']['welcome_message'])){

    	$s_hide_link = l("Forever","cp/confirm_message/welcome_message",array('attributes'=>array('class'=>'hide'),'query' => array('source'=>$_GET['q']) ));
    	$s_close_link = l("For now","",array('attributes'=>array('class'=>'close','onClick'=>'$("div#message_welcome_message").remove(); return false;')));
    	$s_features = l("Enable or disable features for your site",'cp/features');
    	$s_content = l("Add content",'cp/content');
    	$s_members = l("Manage who may use your site",'cp/users/members');
    	$s_bio = ($vsite->feature_access('scholar_biocv'))?"<li>".l("Add your bio",'node/add/bio',array('query' => array('destination'=>'biocv')))."</li>":"";
    	$result = <<<MESSAGE
    	<div id="message_welcome_message">
    	  <h3>Welcome to your new website!</h3>
    	  <p>Below are a few additional resources to help you get started. You may access the control panel at any time by clicking the link in the top right corner of the screen.</p>
    	  <ul id="resource-list">
    	    <li>{$s_features}</li>
    	    <li>{$s_content}</li>
    	    <li>{$s_members}</li>
    	    {$s_bio}
    	    <li><a href='http://scholar-docs.iq.harvard.edu/' target='_blank'>View documentation</a></li>
    	  </ul>
    	  <div class="scholar-admin">
    	    <div class="toggle"><span>Hide this box</span></div>
    	    <div class="slider">
    	      <ul class="links">
    	        <li class="first">{$s_hide_link}</li>
    	        <li>{$s_close_link}</li>
    	      </ul>
    	    </div>
    	  </div>
      </div>
    	{$result}
MESSAGE;
    }

    return $result;
  }
}

/**
 * if front page is set to bio
 * @param $bio_nid the nid of the bio node
 */
/*
function vsite_front_home_bio($bio_nid){
  $node = node_load($bio_nid);
  // TODO "include title" option not implemented here
  $result = node_view($node, $teaser = FALSE, $page = FALSE, $links = FALSE);
  return $result;
}
*/

/**
 * if front page is set to "features"
 * @param $node_options array of node types users want to be promoted to the front page
 */
function vsite_front_home_feature($node_options){

  //initialize the scholar base view
  $view = views_get_view('vsite_view_base');

  // add a filter for "node types" in the view
  $options = array();
  foreach($node_options as $o){
    $options[$o] = $o; // that's how views wants it
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
  return $view -> render();

}

/**
 * if front page is set to "html"
 * @param $front_nid the nid of the node
 */
function vsite_front_home_html($front_nid){
  $node = node_load($front_nid);
  $result = node_view($node, $teaser = FALSE, $page = FALSE, $links = FALSE);
  return $result;
}

/**
 * if front page is set to "flag"
 */
function vsite_front_home_flag(){
  return views_page("vsite_front", "default");
}