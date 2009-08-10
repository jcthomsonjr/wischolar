<?php 
/**
 * Provides theme selection for each site
 */
class scholarcp_setting_logo implements space_setting {
  
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
    
      //Check if the old pic exists
//    $account = $variables['account'];
//    if (!empty($account->picture) && file_exists($account->picture)) {
//      $picture = file_create_url($account->picture);
//    }
//    else if (variable_get('user_picture_default', '')) {
//      $picture = variable_get('user_picture_default', '');
//    }
//
//    if (isset($picture)) {
//      $alt = t("@user's picture", array('@user' => $account->name ? $account->name : variable_get('anonymous', t('Anonymous'))));
//      $variables['picture'] = theme('image', $picture, $alt, $alt, '', FALSE);
//      if (!empty($account->uid) && user_access('access user profiles')) {
//        $attributes = array('attributes' => array('title' => t('View user profile.')), 'html' => TRUE);
//        $variables['picture'] = l($variables['picture'], "user/$account->uid", $attributes);
//      }
//    }

    $s_current = file_check_location($space->group->nid.".png",$this->s_logo_location."/".$space->group->nid);
    if ($s_current) {
      $form['current_logo'] = array('#type' => 'value', '#value' => $s_current);
    }
    $form['logo_upload'] = array('#type' => 'file', '#title' => t('Upload Logo'), '#size' => 48, '#description' => t('Your sites logo. '));
    
    return $form;
  }

  function validate($space, $value) {
  	if(!$space) return false;
    
  	$value['logo_upload'] = file_save_upload('settings', self::$validators);
  	
    if(!$value['logo_upload']){
      form_set_error('logo_upload', t("No image selected for upload."));
    }
      
  }
  
//	function validate_picture(&$form, &$form_state) {
//	  // If required, validate the uploaded picture.
//	  $validators = array(
//	    'file_validate_is_image' => array(),
//	    //'file_validate_image_resolution' => array(variable_get('user_picture_dimensions', '85x85')),
//	    //'file_validate_size' => array(variable_get('user_picture_file_size', '30') * 1024),
//	  );
//	  
//	  if ($file = file_save_upload('picture_upload', $validators)) {
//	   
//	    // The image was saved using file_save_upload() and was added to the
//	    // files table as a temporary file. We'll make a copy and let the garbage
//	    // collector delete the original upload.
//	    $info = image_get_info($file->filepath);
//	    $destination = variable_get('user_picture_path', 'pictures') .'/picture-'. $form['#uid'] .'.'. $info['extension'];
//	    
//	  }
//	}

  function submit($space, $value) {
  	$return = array();
  	if(!$space) return;
  	
  	$value['logo_upload'] = file_save_upload('settings',self::$validators);
  	//$return['logo'] = OLD_PATH;
  	if($value['logo_upload']){
  		
  		$info = image_get_info($value['logo_upload']->filepath);
  		
  		$destination = file_create_path($this->s_logo_location."/".$space->group->nid);
  		file_check_directory($destination,FILE_CREATE_DIRECTORY);
  		
  		$destination = $destination."/".$space->group->nid.".png";
  		
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