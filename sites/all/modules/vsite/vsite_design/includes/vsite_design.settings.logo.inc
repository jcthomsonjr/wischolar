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
  	$this->s_logo_location = file_create_path('vsite_design_logo');
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
    $form['#title'] = 'Photo';

    $s_current = file_check_location($value['current_logo']);


    if ($s_current) {
    	drupal_add_js(drupal_get_path('module', 'vsite_design') . '/theme/jquery.Jcrop.min.js');
    	drupal_add_js(drupal_get_path('module', 'vsite_design') . '/theme/cp-logo-crop.js');
    	vsite_include('vsiteapi');
      $form['current_logo'] = array('#value' => theme('vsite_design_logo',false,'','',array('id' => 'logo_preview'),true));
      $form['x_cord'] = array('#type' => 'hidden');
	    $form['y_cord'] = array('#type' => 'hidden');
	    $form['width'] = array('#type' => 'hidden');
	    $form['height'] = array('#type' => 'hidden');
	    $form['crop'] = array('#type' => 'hidden');
	    $form['preview'] = array(
	      '#prefix' => '<div id="live_preview_box">',
	      '#suffix' => '</div>',
	      '#type' => 'item',
	      '#title' => t('Preview'),
	      '#value' => '<div id="live_preview_box_inner" style="overflow: hidden;">'.theme('vsite_design_logo','vsite_design_landscape_logo','','',array('id' => 'live_preview'),true).'</div>'
	      );

	    $form['crop_btn'] = array(
	      '#prefix' => '<div class="submit-crop">',
	      '#suffix' => '</div>',
	      '#type' => 'submit',
	      '#value' => t('Crop Image'),
        '#attributes' => array(
          'onclick' => "$('#edit-settings-logo-crop').val('1');"
        )
	    );
	    $form['logo_upload'] = array('#type' => 'file', '#title' => t('Upload new photo (or logo)'), '#size' => 48, '#description' => t('Your sites logo. '));


//	    $form['preview'] = array(
//          '#title' => 'Preview',
//          '#type' => 'fieldset',
//          '#tree' => TRUE,
//	        '#collapsible' => TRUE,
//	        '#collapsed' => true
//      );
//      $form['preview']['landscape'] = array('#type' => 'item','#title' => t('Landscape'),'#value' => theme('vsite_design_logo','vsite_design_landscape_logo'));
//      $form['preview']['square'] = array('#type' => 'item','#title' => t('Square'),'#value' => theme('vsite_design_logo','vsite_design_square_logo'));
//      $form['preview']['portrait'] = array('#type' => 'item','#title' => t('Portrait'),'#value' => theme('vsite_design_logo','vsite_design_portrait_logo'));

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

  	if($return['current_logo']){
  		self::add_imagefield_image($return['current_logo'],'field_vsite_logo',$space->group);
  	}
  	
    return $return;
  }
  
	/**
	 * Imports an image as a filefield image of a given node
	 * 
	 * Usage example:
	 * --------------
	 * $node = node_load(array('nid' => 61));
	 * $image = drupal_get_path('module', 'vsite_design').'/theme/images/default_logo.jpg';
	 * simport_node_add_imagefield_image($image, 'field_img', $node);
	 * 
	 * @param $source  the path to the source image
	 * @param $field_name the name of the cck field 
	 * @param $node the node object to upload the image to (passed by reference)
	 */
	public static function add_imagefield_image($source, $field_name, &$node){
	
	  // get the cck filefield
	  $field = content_fields($field_name, $node -> type);
	
	  // validators (can add our own validators if we want)
	  $validators = array_merge(filefield_widget_upload_validators($field), imagefield_widget_upload_validators($field));
	
	  // where to store the file
	  $files_path = filefield_widget_file_path($field);
	  
	  // create the file object
	  $file = field_file_save_file($source, $validators, $files_path);
	
	  //set uid to the node -> uid
	 // $file -> uid = $node -> uid;
	
	  // attach it to the filefield field
	  $node->$field_name = array(
	  0 => array(
	  'fid' => $file['fid'],
	  'uid' => $node -> uid,
	  'list' => 1,
	    )
	  ); 
	  
	  // save the node
	  node_save($node);
	}
}