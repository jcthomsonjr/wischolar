<?php

/**
 * Cache blocks based on content changes
 */
class os_content_cache_context_reaction_block extends vsite_context_reaction_block {

  /**
   * Build a block's content. Largely taken from block_list().
   */
  protected function build_block($block, $reset = FALSE) {
    // We preserve the submission of forms in blocks, by fetching from cache
    // only if the request method is 'GET'.
    static $cacheable;
    if (!isset($cacheable) || $reset) {
      $cacheable = $_SERVER['REQUEST_METHOD'] == 'GET' && $block->cache == BLOCK_CACHE_CONTENT_CACHE;
    }

    if (!isset($block->content)) {
      $block->content = '';
      // Try fetching the block from cache.
      if ($cacheable && ($cid = $this->get_cache_id())) {
      	$cutoff = $this->cache_expire($block);
        if ($cache = cache_get($cid, 'cache_block') && (!$cutoff || $cache->created > $cutoff)) {
          $array = $cache->data;
        }
        else {
          $array = module_invoke($block->module, 'block', 'view', $block->delta);
          //Permanant Cache, we will clear this manually
          cache_set($cid, $array, 'cache_block', CACHE_PERMANENT);
        }
      }
      // Otherwise build block.
      else {
        $array = module_invoke($block->module, 'block', 'view', $block->delta);
      }
      if (isset($array) && is_array($array)) {
        foreach ($array as $k => $v) {
          $block->$k = $v;
        }
      }
    }
    if (!empty($block->content)) {
      // Only query for custom block title if block core compatibility is enabled.
      if (!variable_get('context_reaction_block_disable_core', FALSE)) {
        global $user, $theme_key;
        $block->title = db_result(db_query("SELECT title FROM {blocks} WHERE module = '%s' AND delta = '%s' AND theme = '%s'", $block->module, $block->delta, $theme_key));
      }
      // Override default block title if a custom display title is present.
      if (!empty($block->title)) {
        // Check plain here to allow module generated titles to keep any markup.
        $block->subject = $block->title == '<none>' ? '' : check_plain($block->title);
      }
      if (!isset($block->subject)) {
        $block->subject = '';
      }
    }
    return $block;
  }
  
  protected function get_cache_id($block){
  	global $theme, $base_root, $user;
  	
    $cid_parts = array();
    
    $vsite = vsite_get_vsite();
    $cid_parts[] = (isset($vsite->group->purl))? $vsite->group->purl:"";

    //common sub-patterns: block identification, theme, language.
    $cid_parts[] = $block->module;
    $cid_parts[] = $block->delta;
    $cid_parts[] = $theme;
    $cid_parts[] = ($user->uid == 1)?1:0; // special caching for super user.
    
    if (module_exists('locale')) {
      global $language;
      $cid_parts[] = $language->language;
    }
    
  	return implode(':', $cid_parts);
  }
  
  protected function cache_expire($block){
  	$cutoff = 0;

    // Retrieve the latest update time matching the settings on this View.
    $cid = array();
    foreach ($block->cache_keys as $key_id => $key_values) {
      if ($plugin = views_content_cache_get_plugin($key_id)) {
        $cid[$key_id] = $plugin->view_key($key_values);
      }
    }
    if (!empty($cid) && $timestamp = views_content_cache_update_get($cid)) {
      $cutoff = $timestamp;
    }

    // If there's a minimum lifetime, enforce it:
    if ((isset($this->cache_min_lifespan) && $min_lifespan = $this->cache_min_lifespan) ||
        (!isset($this->cache_min_lifespan) && $min_lifespan = variable_get('os_blocks_min_cache',0))) {
      $min_lifespan = time() - $min_lifespan;
      $cutoff = min($min_lifespan, $cutoff);
    }

    // Only enforce a maximum lifetime if it's been specifically selected:
    if ((isset($this->cache_max_lifespan) && $max_lifespan = $this->cache_max_lifespan) ||
        (!isset($this->cache_min_lifespan) && $max_lifespan = variable_get('os_blocks_max_cache',3600))) {
      if ($max_lifespan != -1) {
        $max_lifespan = time() - $max_lifespan;
        $cutoff = max($max_lifespan, $cutoff);
      }
    }
    
    return $cutoff;
  }
}
