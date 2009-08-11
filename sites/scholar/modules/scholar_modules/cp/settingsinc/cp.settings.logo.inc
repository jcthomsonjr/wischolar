<?php 
/**
 * Provides theme selection for each site
 */
class cp_setting_logo implements space_setting {
  
	public $s_logo_location = false;
	public static $validators = array(
      'file_validate_is_image' => array(),
      //'file_validate_image_resolution' => array(variable_get('user_picture_dimensions', '85x85')),
      //'file_validate_size' => array(variable_get('user_picture_file_size', '30') * 1024),
  );
    
  var $id;
  function __construct($id = NULL) {
  	$this->s_logo_location = file_create_path('scholar_logos');
  	file_check_directory($this->s_logo_location,FILE_CREATE_DIRECTORY);
  	
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'logo';
    }
  }

  function form($space, $value = array()) {
    $form = array();
    $form['#title'] = 'Logo';

    $s_current = file_check_path($value['current_logo']);
    
    $form['logo_upload'] = array('#type' => 'file', '#title' => t('Upload Logo'), '#size' => 48, '#description' => t('Your sites logo. '));
    if ($s_current) {
      $form['current_logo'] = array('#value' => "<img src='/{$value['current_logo']}/{$s_current}?v=".time()."' />");
    }
    
    return $form;
  }

  function validate($space, $value) {
  	if(!$space) return false;
    
  	$value['logo_upload'] = file_save_upload('settings', self::$validators);
  	
    if(!$value['logo_upload']){
      form_set_error('logo_upload', t("No image selected for upload."));
    }
      
  }

  function submit($space, $value) {
  	$return = array();
  	if(!$space) return;
  	
  	$value['logo_upload'] = file_save_upload('settings',self::$validators);
  	//$return['logo'] = OLD_PATH;
  	if($value['logo_upload']){
  		
  		$info = image_get_info($value['logo_upload']->filepath);
  		
  		$destination = file_create_path($this->s_logo_location."/".$space->group->nid);
  		file_check_directory($destination,FILE_CREATE_DIRECTORY);
  		
  		//Delete cached files
      file_scan_directory($destination, '.*', array('.', '..'), 'file_delete', TRUE);
      
  		$destination = $destination."/".$space->group->nid.".".$info['extension'];
  		//require_once drupal_get_path('module', 'imageapi_imagemagick') .'/imageapi_imagemagick.module';
  		//$o_image = imageapi_image_open($value['logo_upload']->filepath);//,'imageapi_imagemagick');
  		
  	  if (file_copy($value['logo_upload'], $destination, FILE_EXISTS_REPLACE)) {
        $value['logo_upload'] = "";
        $return['current_logo'] = $destination;
      }else {
        form_set_error('logo_upload', t("Failed to upload the picture image; the %directory directory doesn't exist or is not writable.", array('%directory' => variable_get('user_picture_path', 'pictures'))));
      }
  	}
  	
    return $return;
  }
}