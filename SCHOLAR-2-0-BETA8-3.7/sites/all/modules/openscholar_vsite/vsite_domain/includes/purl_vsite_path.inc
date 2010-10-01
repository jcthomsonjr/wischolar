<?php
//require_once ( drupal_get_path('module', 'purl') .'/includes/purl_path.inc');
/**
 * Create the processor that will override the purl_path enables path + domain
 */
if (!class_exists('purl_vsite_path')) {
  
  /**
   *  Full path + domain handling for scholar
   */
  class purl_vsite_path extends purl_path implements purl_processor {
    
    public static $a_disabled = array();
    //allowing domain suffix to have alphanumeric chars, hyphens, underscores, minimum of 3 chararcters long
    public $modifier_regex = '!^[a-z0-9_-]{3,}+$!';
     
    public function method() {
      return PURL_VSITE_PATH;
    }
    
    /**
     * Make sure the domain is valid
     */
    public function parse($valid_values, $q) {
      $valid_values = array_diff_key($valid_values, vsite_domain_processed_purls());
      $a_parsed = parent::parse($valid_values, $q);
      
      foreach ($a_parsed as $s_site => $a_settings) {
        if ($a_settings->provider == 'spaces_og' && variable_get('purl_base_domain', FALSE)) {
          $vsite = spaces_load('og', $a_settings->id);
          if (in_array($a_settings->value, self::$a_disabled) ||
             (strlen($vsite->settings['generic']['vsite_domain']) &&
             str_replace('http://', '', $_SERVER['HTTP_HOST']) != $vsite->settings['generic']['vsite_domain']) ||
             (!strlen($vsite->settings['generic']['vsite_domain']) &&
             str_replace('http://', '', $_SERVER['HTTP_HOST']) != str_replace('http://', '', variable_get('purl_base_domain', 'scholar.iq.harvard.edu')))
             ) {
            unset($a_parsed[$s_site]);
          }
        }
      }//Do not return space's without the correct domain
      return $a_parsed;
    }
  }
}
