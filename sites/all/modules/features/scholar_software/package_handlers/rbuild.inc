<?php 
require_once(drupal_get_path('module', 'scholar_software') . "/package_handlers/scholar_software_handler.inc");

class rbuild implements scholar_software_handler{
  
	private static $a_cached_packages = array();
	
  private $a_packages = array();
  private $s_app_key = false;
  private $s_url = false;

  function __construct($s_url, $s_app_key = false){
  	
  	if(!array_key_exists($this->create_url($s_url),self::$a_cached_packages)){
  		self::$a_cached_packages[$this->create_url($s_url)] = $this->rbuild_parse( $this->create_url($s_url));
  	}//Cache all projects
  	
  	if(count(self::$a_cached_packages[$this->create_url($s_url)])){
  		$this->a_packages = self::$a_cached_packages[$this->create_url($s_url)];
  	}else{
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
  	$node->title = $a_package['title'];
  	$node->body = $a_package['description'];
  }
  
  /**
   * Create the initial batch of release files
   * @param $project_node
   */
  public function initReleases($project_node){
  	if(!$project_node->is_new || !$project_node->nid) return;
  	
  	$a_releases  = $this->rbuild_get_release_files();
  	$a_package = $this->getPackage();
  	
  	foreach ($a_releases as $s_version => $s_file_name){
  		$release_node = new stdClass();
  		$release_node->type = 'scholar_software_release';
  		$release_node->uid = $project_node->uid;
  		$release_node->pathauto_perform_alias = 1;
  		$release_node->og_initial_groups = $project_node->og_initial_groups;
  		$release_node->spaces_og = $project_node->spaces_og;
  		$release_node->status = 1;
  		$release_node->active = 1;
  		$release_node->field_scholar_software_project[0]['nid'] = $project_node->nid;
  		list($major,$patch,$extra) = $this->parseVersion($s_version);
  		$release_node->field_versionmajor[0]['value'] = $major;
  		$release_node->field_versionpatch[0]['value'] = $patch;
  		$release_node->field_versionextra[0]['value'] = $extra;
  		$release_node->field_scholar_software_recommend[0]['value'] = ($s_version == $a_package['version'])?1:0;
  		$release_node->field_scholar_software_security[0]['value'] = 0;
  		
  		$file = $this->importFile($this->s_url."/".$s_file_name, $s_file_name, $project_node->uid);
  		$release_node->field_scholar_software_file[0] = array(
	      'fid' => $file->fid,
	      'title' => basename($file->filename),
	      'filename' => $file->filename,
	      'filepath' => $file->filepath,
	      'filesize' => $file->filesize,
	      'mimetype' => $file->filemime,
	      'description' => basename($file->filename),
	      'list' => 1,
	    );
  		//Save the new release to db
	    node_save($release_node);
  	}
  	
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
	  if ($index_file = file_get_contents($this->s_url."/")) {
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
  
  /**
   * Parse the version components from a version string
   * @param $s_version 
   * @return array
   */
  private function parseVersion($s_version){
  	$extra = "";
  	list($major,$patch) = explode(".",$s_version,2);
  	
  	if(strstr($patch,"-")) list($patch,$extra) = explode("-",$patch,2); 
  	
  	return array(intval($major),intval($patch),strval($extra));
  }
  
  /**
   * Import a release file from an external server
   * @param $s_external_path
   * @param $uid
   * @return (object) file
   */
  private function importFile($s_external_path, $s_file_name, $uid){
  	$mime = 'application/octet-stream'; //GZip Files

  	$s_contents = file_get_contents($s_external_path);
	  $s_filepath = file_save_data($s_contents,$s_file_name);
	
	  $file = new stdClass();
	  $file->filename = basename($s_filepath);
	  $file->filepath = $s_filepath;
	  $file->filemime = $mime;
	  $file->filesize = filesize($s_filepath);
	
	  $file->uid = $uid;
	  $file->status = FILE_STATUS_PERMANENT;
	  $file->timestamp = time();
	  drupal_write_record('files', $file);
	  $file->fid = db_result(db_query("SELECT fid FROM {files} WHERE filepath = '%s'", $file->filepath));
	  
	  return $file;
  }
  
}