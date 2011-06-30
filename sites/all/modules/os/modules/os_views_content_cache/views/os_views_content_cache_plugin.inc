<?php
// $Id: os_performance_plugin_cache.inc

/**
 * Simple caching of query results for Views displays in OpenScholar sites.
 */
class os_views_content_cache_plugin extends views_content_cache_plugin_cache {
  
	function option_defaults(&$options) {
    $options['results_min_lifespan'] = 0; //Forever
    $options['results_max_lifespan'] = 0; //Forever
    $options['output_min_lifespan'] = 3600; //One Hour
    $options['output_max_lifespan'] = 3600; //One Hour
    $options['keys'] = array();
  }

  function summary_title() {
    return "OpenScholar Content cache";
  }
  
  function get_results_key() {
    global $user;

    if (!isset($this->_results_key)) {

      // This is a fix for the build info not including the actual query run:
      $execute_info = $this->view->build_info;

      $execute_info['query'] = db_rewrite_sql($execute_info['query'], $this->view->base_table, $this->view->base_field, array('view' => &$this->view));
      $execute_info['count_query'] = db_rewrite_sql($execute_info['count_query'], $this->view->base_table, $this->view->base_field, array('view' => &$this->view));
      $replacements = module_invoke_all('views_query_substitutions', $this->view);
      $execute_info['query'] = str_replace(array_keys($replacements), $replacements, $execute_info['query']);
      $execute_info['count_query'] = 'SELECT COUNT(*) FROM (' . str_replace(array_keys($replacements), $replacements, $execute_info['count_query']) . ') count_alias';
      // End generating the execution info.

      $key_data = array(
        'execute_info' => $execute_info,
        'roles' => array_keys($user->roles),
        'super-user' => $user->uid == 1, // special caching for super user.
        'language' => $GLOBALS['language'],
      );
      foreach (array('exposed_info', 'page', 'sort', 'order') as $key) {
        if (isset($_GET[$key])) {
          $key_data[$key] = $_GET[$key];
        }
      }
      
      //Include the Current Site in the Key if there is one:
      $vsite = vsite_get_vsite();
      $s_site = ($vsite && $vsite->group->purl)? $vsite->group->purl.":":"";
      
      $this->_results_key = $s_site . $this->view->name . ':' . $this->display->id . ':results:' . md5(serialize($key_data));
    }

    return $this->_results_key;
  }
  

  function get_output_key() {
    global $user;
    if (!isset($this->_output_key)) {
    	
      $key_data = array(
        'result' => $this->view->result,
        'roles' => array_keys($user->roles),
        'super-user' => $user->uid == 1, // special caching for super user.
        'theme' => $GLOBALS['theme'],
        'language' => $GLOBALS['language'],
      );

      //Include the Current Site in the Key if there is one:
      $vsite = vsite_get_vsite();
      $s_site = ($vsite && $vsite->group->purl)? $vsite->group->purl.":":"";
      
      $this->_output_key = $s_site . $this->view->name . ':' . $this->display->id . ':output:' . md5(serialize($key_data));
    }

    return $this->_output_key;
  }
}
