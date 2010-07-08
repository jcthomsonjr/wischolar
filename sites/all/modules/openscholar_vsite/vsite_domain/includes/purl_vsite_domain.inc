<?php
//require_once ( drupal_get_path('module', 'purl') .'/includes/purl_domain.inc');
/**
 * Create the processor that will override the purl_domain
 */

if(!class_exists('purl_vsite_domain')){
  /**
   *  Full domain handling for scholar, will also remove purl prefix's from alias's
   */
  class purl_vsite_domain extends purl_domain implements purl_processor {
  
    public $modifier_regex = '!^[a-z0-9_\.-]+$!';
    
    /**
     * Simply match our 'q' (aka domain) against an allowed value.
     *
     * If none is found and $q starts with www. then try without
     */
    public function parse($valid_values, $q) {
      $path_elements = parent::parse($valid_values, $q);
      
      if(!count($path_elements) && strpos($q,'www.') === 0){
        //Remove www
        $q = substr($q,4);
        $path_elements = parent::parse($valid_values, $q);
      }
      
      return $path_elements;
    }
  
    public function method() {
      return PURL_VSITE_DOMAIN;
    }
  
    public function description() {
      return t('Enter a domain registered for this scholar site, such as "www.example.edu".  Do not include http://');
    }
  
    private function remove_scholar_purl($path){
      if(!($vsite = vsite_get_vsite()) || !strlen($vsite->purl)) return $path;
      $args = explode('/', $path);
  
      // Remove the value from the front of the query string
      if (current($args) === (string) $vsite->purl) {
        array_shift($args);
      }
      return implode('/', $args);
    }
    
    /**
     * Either force the url, or set it back to the base.
     */
    public function rewrite(&$path, &$options, $element) {
      $options['absolute'] = TRUE;
      if (!_purl_skip($element, $options)) {
        $path = $this->remove_scholar_purl($path);
        $options['base_url'] = "http://{$element->value}";
      }else {
        $options['base_url'] = variable_get('purl_base_domain', $base_url);
      }
    }
    
    /**
     * If a purl_path/domain has been set we should rewrite the current url
     * so that aliased paths will be picked up
     */
    public function adjust(&$value, $item, &$q) {
      if(!($vsite = vsite_get_vsite()) || !strlen($vsite->purl)) return;
      
      if ($_GET['q'] == trim($_REQUEST['q'], '/')) {
        purl_vsite_path::$a_disabled[$vsite->purl] = $vsite->purl;
        $args = explode('/', $_GET['q']);
  
        // Add the value to the front of the query string
        if (current($args) !== (string) $vsite->purl) array_unshift($args,$vsite->purl);
        
        $qstring = implode('/', $args); //String with purl added
        $qstring_alias = drupal_lookup_path('source', $qstring); //Alias of that url
        if($qstring_alias && $qstring != $qstring_alias){
        	$q = $qstring;
        }
//          $_REQUEST['q'] = $_GET['q'] = $qstring_alias;
//        }else{
//          //Sudo alias to prevent path rewrites
//          $_REQUEST['q'] = $qstring_alias;
//        }
      }//It has not been aliased yet
      
    }
  }
}