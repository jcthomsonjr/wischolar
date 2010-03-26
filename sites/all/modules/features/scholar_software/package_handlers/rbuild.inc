<?php 

class rbuild {
  
  private $a_packages = array();
  private $s_app_key = false;

  function __construct($s_url, $s_app_key = false){
    $this->a_packages = $this->rbuild_parse( $this->create_url($s_url,$s_app_key));
    
    return count($this->a_packages)?true:false;
  }
  
  /**
   * @return the $packages
   */
  public function getPackage(){
    return $this->a_packages;
  }

  /**
   * Simple util function to create the url path
   * 
   * @param string $s_url
   * @param string $s_app_key
   * @return string
   */
  private function create_url($s_url, $s_app_key = false){
  	$s_path = rtrim($s_url,"/ ")."/PACKAGES";
  	
  	//Add App Key if given
    $s_path .= strlen($s_app_key)? ".$s_app_key":"";	
    
    return $s_path;
  }
  

  /**
   * Used to parse a package file and retrieve the avalible packages
   * @param $url
   * @return array
   */
  private function rbuild_parse($url){
    $package_file = file_get_contents($url);
    
    $packages_raw = split("\n\n\n", $package_file);
    
    $a_packages = array();
    foreach ( $packages_raw as $package_raw ) {
    	$a_package_info = array();
    	$package_name = false;
    	
    	$package_raw = trim($package_raw);
      $lines = split("\n", $package_raw);
      foreach ( $lines as $line ) {
        $line_elements = (explode(':', $line, 2));
        if (count($line_elements) == 2) {
          $current_key = trim($line_elements[0]);
          if ($current_key == 'Package') {
            $package_name = trim($line_elements[1]);
          }
          $a_package_info[$current_key] = trim($line_elements[1]);
        }
        elseif ($current_key) {
          $a_package_info[$current_key] .= ' ' . trim($line_elements[0]);
        }
      }
      if($package_name && count($a_package_info)){
      	$a_packages[$package_name] = $a_package_info;
      }
    }
    
    return $a_packages;
  }
}