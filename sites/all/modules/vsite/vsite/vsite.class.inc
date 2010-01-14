<?php 

/**
 * extend class space_og. We would want to override
 * some of the methods.
 * TODO funciont spaces_load in spaces.module is modified
 * because it's initiating an object of type space_og
 * TODO I submitted for this http://drupal.org/node/511914
 * @see scholar_spaces_types_alter
 */


class vsite extends space_og implements space {
  
  //Set to allow feature access even if it is not enabled
  public static $override_allow_feature_access = false;
  
  /**
   * Constructor
   */
  function __construct($type, $sid = NULL, $is_active = FALSE) {
    parent::__construct($type,$sid,$is_active);
    if ($this->group->og_theme && !$this->group->theme) {
      $this->group->theme = $this->group->og_theme;
    }//This must be set on load so that when you save the value will persist
  }

  function redirect($op = 'home'){
    switch ($op) {
      case 'home' :
        if (! empty($this->purl)) {
          // Use the menu path of the selected feature as homepage
          $home = 'home';
          if (menu_get_item($home)) {
            purl_goto($home, array( 'purl' => array( 'provider' => $this->purl_provider,'id' => $this->sid)));
          }

          // The previous checks fail, there is no valid homepage set
          if ($this->admin_access() && user_access('configure spaces features')) {
            drupal_set_message(t("Please setup your group by choosing a homepage setting."));
            purl_goto("cp/settings/features", array( 'purl' => array('provider' => $this->purl_provider, 'id' => $this->sid) ));
          }
        }
        else {
          drupal_goto('node/' . $this->sid . '/edit');
        }
        menu_set_active_item('spaces-access-denied');
        break;
      case 'features' :
        purl_goto("cp/settings/features", array('purl' => array( 'provider' => $this->purl_provider, 'id' => $this->sid)));
        break;
    }
  }

  /**
   * Implementation of space->menu_access().
   * 
   * This is overridden from the default so that we can restrict menu access for 
   * nodes that have been marked "disabled" by site owners.  Non Nodes use the parent function
   */
  function menu_access($op, $object = NULL, $is_active = TRUE) {
    switch ($op) {
      case 'node':
        $node = $object;
        if (!empty($node->og_groups)) {
          // If the node does not belongs to the current active group space then return false
          if (($is_active && !in_array($this->sid, $node->og_groups))) {
            return false;
          }
        }

        if($is_active){
	        vsite_include('vsiteapi');
	        $a_scholar_types = vsite_content_types(array(1,2));
	        $form = !isset($node->nid) || isset($node->date) ? TRUE : FALSE;
	
	        if($form && !array_key_exists($node->type,$a_scholar_types)){
	          return false;
	        }//If this is disabled then you can't see it's form...sorry
        }//If you are within this vsite
      default:
      return parent::menu_access($op, $object, $is_active);
    }
  }
  
  /**
   * implementation of feature_access()
   */
  function feature_access($feature = NULL) {
    if (isset($this->features[$feature])) {
      if ($this->features[$feature] == SPACES_FEATURE_DISABLED) {
        return FALSE;
      }else if (og_is_group_member($this->sid)) {
        return TRUE;
      }else if ($this->features[$feature] == SPACES_OG_PUBLIC) {
        return TRUE; 
      }
    }elseif(self::$override_allow_feature_access){
      //allow access to all feature menu items on this page for display purposes
      return true; 
    }//Is this feature a part of the site?
    return FALSE;
  }
  
  function router($op, $object = NULL, $is_active = TRUE){
  	if(!is_object($this)) return; //Because there is a bug in spaces that calls this as a static function bug report submitted
  	parent::router($op,$object,$is_active);
  }
}