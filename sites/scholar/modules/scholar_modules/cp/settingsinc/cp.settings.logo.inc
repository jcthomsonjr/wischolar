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

    $s_current = file_check_location($value['current_logo']);
    
    $form['logo_upload'] = array('#type' => 'file', '#title' => t('Upload Logo'), '#size' => 48, '#description' => t('Your sites logo. '));
    if ($s_current) {
    	drupal_add_js(drupal_get_path('module', 'cp') . '/theme/jquery.jcrop.min.js');
    	drupal_add_js(drupal_get_path('module', 'cp') . '/theme/cp-logo-crop.js');
    	drupal_add_js("$(function() {
											  $('#logo_preview').Jcrop({
											    aspectRatio: 1.2857,
											    minSize: [180,140],
                          onSelect: updateLogo
											  });
											}); ","inline");
    	scholar_include('scholarapi');
      $form['current_logo'] = array('#value' => theme('scholar_logo',false,'','',array('id' => 'logo_preview')));
      $form['x_cord'] = array('#type' => 'hidden');
	    $form['y_cord'] = array('#type' => 'hidden');
	    $form['width'] = array('#type' => 'hidden');
	    $form['height'] = array('#type' => 'hidden');
	    $form['crop'] = array('#type' => 'hidden');
	    $form['crop_btn'] = array(
	      '#type' => 'submit',
	      '#value' => t('Crop Image'),
        '#attributes' => array(
          'onclick' => "$('#edit-settings-logo-crop').val('1');"
        )
	    );
	    
	    $form['preview'] = array(
          '#title' => 'Preview',
          '#type' => 'fieldset',
          '#tree' => TRUE,
	        '#collapsible' => TRUE,
	        '#collapsed' => true
      );
      $form['preview']['landscape'] = array('#type' => 'item','#title' => t('Landscape'),'#value' => theme('scholar_logo','landscape_scholar_logo'));
      $form['preview']['square'] = array('#type' => 'item','#title' => t('Square'),'#value' => theme('scholar_logo','square_scholar_logo'));
      $form['preview']['portrait'] = array('#type' => 'item','#title' => t('Portrait'),'#value' => theme('scholar_logo','portrait_scholar_logo'));
      
    }
    
    
    return $form;
  }

  function validate($space, $value) {
  	if(!$space) return false;
    
  	if(!$value['crop']){
	  	$value['logo_upload'] = file_save_upload('settings', self::$validators);
	  	
	    if(!$value['logo_upload']){
	      form_set_error('logo_upload', t("No image selected for upload."));
	    }
  	}else{
  		if(!$value['x_cord'] || !$value['y_cord'] || !$value['width'] || !$value['height']){
  			form_set_error('current_logo', t("You must select a region to crop."));
  		}
  	}
      
  }

  function submit($space, $value) {
  	$return = array();
  	if(!$space) return;
  	if(!$value['crop']){
	  	$value['logo_upload'] = file_save_upload('settings',self::$validators);
	  	//$return['logo'] = OLD_PATH;
	  	if($value['logo_upload']){
	  		if($space->settings['logo'] && $space->settings['logo']['current_logo']){
	  		  imagecache_image_flush($space->settings['logo']['current_logo']);
	  		}
	  		
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
  	
  	}else{
  		if(!$space->settings['logo'] && !$space->settings['logo']['current_logo']) return $return;
  		
  	  $o_image = imageapi_image_open($space->settings['logo']['current_logo'],'imageapi_gd');
  	  imageapi_toolkit_invoke('crop',$o_image,array($value['x_cord'],$value['y_cord'],$value['width'],$value['height']));
  	  imageapi_toolkit_invoke('close',$o_image,array($space->settings['logo']['current_logo']));
  	
  	  $return['current_logo'] = $space->settings['logo']['current_logo'];
  	}//Crop or save source
  	
    return $return;
  }
}