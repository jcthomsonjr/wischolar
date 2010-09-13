<?php
require_once(drupal_get_path('module', 'scholar_software') . "/package_handlers/scholar_software_handler.inc");

class rbuild implements scholar_software_handler{
  
	private static $a_cached_packages = array();
	
  private $a_packages = array();
  private $s_app_key = false;
  private $s_url = false;

  function __construct($s_url, $s_app_key = false){
  	
  	if($s_url && !array_key_exists($this->create_url($s_url),self::$a_cached_packages)){
  		self::$a_cached_packages[$this->create_url($s_url)] = $this->rbuild_parse( $this->create_url($s_url));
  	}//Cache all projects
  	
  	if(count(self::$a_cached_packages[$this->create_url($s_url)])){
  		$this->a_packages = self::$a_cached_packages[$this->create_url($s_url)];
  	}elseif($s_url){
  		$this->a_packages = $this->rbuild_parse( $this->create_url($s_url,$s_app_key));
  	}//Use cached packages or try this project directly
    $this->s_app_key = $s_app_key;
    $this->s_url = rtrim($s_url,"/ ");
    
    return count($this->a_packages)?true:false;
  }
  
  /**
   * @return the $packages
   */
  public function getPackages(){
    return $this->a_packages;
  }

  /**
   * @return the $package
   */
  public function getPackage(){
  	if(!$this->s_app_key || !array_key_exists($this->s_app_key,$this->a_packages)) return false;
    return $this->a_packages[$this->s_app_key];
  }
  
  /**
   * Alter a project node before it is saved
   * @param $node
   */
  public function alterProject(&$node){
  	if(!($a_package = $this->getPackage())) return;
  	
  	//Update the title with what is in rbuild
  	if(!strlen($node->title)){
	  	$s_key = (strlen($this->s_app_key) && strtolower(substr($a_package['title'],0,strlen($this->s_app_key))) != strtolower($this->s_app_key))?"$this->s_app_key: ":"";
	  	$node->title = $s_key.$a_package['title'];
  	}
  	
  	if(!strlen($node->body)){
	  	$s_remote_body = "http://r.iq.harvard.edu/docs/".strtolower($this->s_app_key)."/".$a_package['version']."/index.shtml";
	  	$a_remote_body_headers = _iqss_rbuild_get_file_headers($s_remote_body);
	  	if(!module_exists('iqss_remote_source') || strstr($a_remote_body_headers[0],'404 Not Found')){
		  	$s_contributors  = strlen($a_package['author'])?"Contributors: ".strip_tags(trim($a_package['author'],' ,'))."<br /><br />":"";
		  	$node->body = "<!-- RBuild Docs -->".$s_contributors.$a_package['description'];
	  	}else{
	  	  $node->iqss_remote_source_path = $s_remote_body;
	  	}
  	}
  }
  
  /**
   * Create the initial batch of release files
   * @param $project_node
   */
  public function initReleases($project_node){
  	if(!$project_node->is_new || !$project_node->nid) return;
  	
  	$a_releases  = $this->rbuild_get_release_files();
  	$a_package = $this->getPackage();
  	
  	$a_operations = array();
  	foreach ($a_releases as $s_version => $s_file_name){
  		//Create Release
  		$a_operations[] = array('iqss_rbuild_add_release_node', array($project_node, $s_version,$s_file_name,$a_package, $this->s_url));
  	}
  	
  	$a_batch = array(
			'title' => t('Importing'),
			'operations' => $a_operations,
			'finished' => 'iqss_rbuild_batch_finished',
		);
		
  	batch_set($a_batch);
    //batch_process();
  }
  
  /**
   * Validate the rbuild submission
   */
  public function validate(){
    if(!($a_package = $this->getPackage())){
      form_set_error('rbuild identifier',"Invalid Application Shortname [$this->s_app_key] not found at [$this->s_url]");
    }
  }
  
  /**
   * Proccess Cron Update
   */
  public function proccessCron(&$node){
    if(!($a_package = $this->getPackage())) return;
    
    //Refresh Title and Description
    $this->alterProject($node);
    
    //Add any new releases
    list($major,$patch,$extra) = _iqss_rbuild_parseVersion($a_package['version']);
    $result = db_result(db_query("SELECT nid FROM {content_type_scholar_software_release}
                                  WHERE field_scholar_software_project_nid = %d AND field_versionmajor_value = %d AND field_versionpatch_value = %d AND field_versionextra_value <=> NULLIF('%s','') ",
                                  array($node->nid,$major,$patch,$extra)));

    $a_results = array();
    if(!$result){
    	//Add new Release
    	iqss_rbuild_add_release_node($node, $a_package['version'], $this->s_app_key."_".$a_package['version'].".tar.gz", $a_package, $this->s_url, $a_results);
    }
    
    return $a_results;
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
    $package_file = _iqss_rbuild_get_file_contents($url);
    
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
          $current_key = strtolower(trim($line_elements[0]));
          if ($current_key == 'package') {
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
  
  /**
   * Used to parse a packages files
   * @param $url
   * @return array
   */
  private function rbuild_get_release_files(){
  	
  	$a_releases = array();
	  if ($index_file = _iqss_rbuild_get_file_contents($this->s_url."/")) {
	  	$a_matches = array();
	  	preg_match_all('/(a href\=")('.$this->s_app_key.'([\._-\d]*)\.tar\.gz)(")/i',$index_file,$a_matches);
	    foreach ($a_matches[2] as $n_index => $filename){
	    	$a_releases[trim($a_matches[3][$n_index],"_")] = $filename;
	    }
	  }
    
	  if(!count($a_releases)){
	  	$a_package = $this->getPackage();
	  	$s_default = $this->s_url."/".$this->s_app_key."_".$a_package['version'].".tar.gz";
	  	if(file_exists($s_default)) $a_releases[$a_package['version']] = $s_default;
	  }
	  
	  return $a_releases;
  }
  

  
}