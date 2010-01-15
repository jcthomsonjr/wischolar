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
    
    if($this->group){
    	$this->sid = $sid;
    }//If the group was loaded correctly set the sid
    
    if(!$is_active){
    	$this->set_purl_provider();
    }
  }

  public function redirect($op = 'home'){
    switch ($op) {
      case 'home' :
        if (! empty($this->purl)) {
        	
        	$home = 'home';  //Hardcoded for now
        	//$home = $this->settings['home'];
        	
          // Use the menu path of the selected feature as homepage
          if (menu_get_item($home)) {
            purl_goto($home, array( 'purl' => array( 'provider' => $this->purl_provider,'id' => $this->sid)));
            break; //if we get here we have an infinate redirect situation and are on the correct page
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
  public function menu_access($op, $object = NULL, $is_active = TRUE) {
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
  public function feature_access($feature = NULL) {
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
  
  /**
   * Return the absolute URL to this vsite
   */
	public function get_absolute_url($path = ""){
	  
	  return url($path, array( 'purl' => array( 'provider' => $this->purl_provider,'id' => $this->sid), 'absolute' => true));
	  
	}
	
	/**
	 * Returns the vocabularies associated with a vsite.
	 * If a content type is provided, return vocabs associated 
	 * with that content type only.
	 * @param $node_type
	 * @return array
	 */
	public function get_vocabs($node_type = NULL){
	  
	  if ($this->group) {
	    
	    if (isset($this->group->og_vocabularies)) {
	      if (!$node_type) {
	        return $this->group->og_vocabularies;
	      }
	      
	      $result = array();
	      
	      foreach ( $this->group->og_vocabularies as $v ) {
	        if (in_array($node_type, array_keys($v->nodes))) {
	          $result[$v->vid] = $v;
	        }
	      }
	      
	      return $result;
	    }
	  }
	}
	
	/**
	 * PRIVATE FUNCTIONS
	 */
	
	/**
	 * If this space is loaded outside a active context (ie) externally from the home page
	 * then determine which purl_provider would be best
	 * 
	 * domain if they have that set otherwise path
	 */
	private function set_purl_provider(){
		//This line checks to see if a domain modifier has been set for this site
		if(purl_load(array('provider' => 'vsite_domain', 'id'=> $this->sid))){  
		  $this->purl_provider = 'vsite_domain';
		}//If this site is configured for domains use that as default, otherwise leave the default as "spaces_og"
	}
}