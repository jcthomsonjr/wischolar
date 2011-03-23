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
      if($namespace == "scholar" && $attribute == "feature" && $split[0] == "reaction" && $split[1] == "block" && isset($context->reactions['block']['blocks'])){
      	$this->merge_default_blocks($context->reactions['block']['blocks']);
      }//Merge in the default blocks for the feature context
      return $context;
    }
    return FALSE;
  }
  
  /**
   * Merge default blocks with passed blocks
   */
  protected function merge_default_blocks(&$blocks) {
    if(!is_array($blocks)) return;
    
    $default_blocks = module_invoke_all('vsite_widgets');
    $blocks = array_merge($default_blocks,$blocks);  //Everywhere plus the feature
    
    //Allow the theme to alter the default block regions
    vsite_layout_alter_theme_regions($blocks);
    
    uasort($blocks, array($this, 'sort_block_by_weight'));
  }
  
	/**
	 * Custom sort by block weight
	 */
	protected function sort_block_by_weight($a, $b) {
	  if (is_object($a)) {
	    $a = (array)$a;
	  }
	  if (is_object($b)) {
	    $b = (array)$b;
	  }
	  
	  if ($a['weight'] == $b['weight']) {
	    return 0;
	  }
	  return ($a['weight'] < $b['weight']) ? -1 : 1;
	}
}
