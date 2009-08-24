<?php 
/**
 * Provides theme selection for each site
 */
class vsite_design_settings_logo implements space_setting {
  
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
    	drupal_add_js(drupal_get_path('module', 'vsite_design') . '/theme/jquery.Jcrop.min.js');
    	drupal_add_js(drupal_get_path('module', 'vsite_design') . '/theme/cp-logo-crop.js');
    	vsite_include('vsiteapi');
      $form['current_logo'] = array('#value' => theme('scholar_logo',false,'','',array('id' => 'logo_preview'),true));
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
	    $form['preview'] = array('#type' => 'item','#title' => t('Preview'),'#value' => theme('scholar_logo','vsite_design_landscape_logo','','',array(),true));
	    
//	    $form['preview'] = array(
//          '#title' => 'Preview',
//          '#type' => 'fieldset',
//          '#tree' => TRUE,
//	        '#collapsible' => TRUE,
//	        '#collapsed' => true
//      );
//      $form['preview']['landscape'] = array('#type' => 'item','#title' => t('Landscape'),'#value' => theme('scholar_logo','vsite_design_landscape_logo'));
//      $form['preview']['square'] = array('#type' => 'item','#title' => t('Square'),'#value' => theme('scholar_logo','vsite_design_square_logo'));
//      $form['preview']['portrait'] = array('#type' => 'item','#title' => t('Portrait'),'#value' => theme('scholar_logo','vsite_design_portrait_logo'));
      
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
	  		
	  		$destination = file_create_path($this->s_logo_location."/".$space->purl);
	  		file_check_directory($destination,FILE_CREATE_DIRECTORY);
	  		
	  		//Delete cached files
	      file_scan_directory($destination, '.*', array('.', '..'), 'file_delete', TRUE);
	      
	  		$destination = $destination."/".$space->purl.".".$info['extension'];
	  		$fullsize_preset = imagecache_preset_by_name('vsite_design_default_logo');
	  		//$o_image = imageapi_image_open($value['logo_upload']->filepath);//,'imageapi_imagemagick');
	  		
	  		if (imagecache_build_derivative($fullsize_preset['actions'], $value['logo_upload']->filepath, $destination)) {
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
  	  imagecache_image_flush($return['current_logo']);
  	}//Crop or save source
  	
    return $return;
  }
}