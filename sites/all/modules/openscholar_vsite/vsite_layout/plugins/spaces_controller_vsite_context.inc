<?php

/**
 * Context controller.
 */
class spaces_controller_vsite_context extends spaces_controller_context {

  /**
   * Load the context described by an override identifier like
   * 'foo:reaction:block'.
   */
  protected function load_from_override($override_id) {
    if ($split = explode(':', $override_id)) {
      $context_name = array_shift($split);
      $context = context_load($context_name);

      list($namespace, $attribute, $value) = explode("-",$context_name);
      if($namespace == "openscholar" && $attribute == "feature" && $split[0] == "reaction" && $split[1] == "block"){
      	if(!isset($context->reactions['block']['blocks'])){
      		$context->reactions['block']['blocks'] = array();
      	}
      	//$this->merge_default_blocks($context->reactions['block']['blocks']);
      }//Merge in the default blocks for the feature context
      return $context;
    }
    return FALSE;
  }

  
}
