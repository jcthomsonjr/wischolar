<?php

/**
 * @file
 * The class for "CC license" type widgets.  
 */

class os_boxes_bio extends os_boxes_default {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    //$options['license_type'] = 'cc';
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    
    $form['bio'] = array();
    /*
      '#type' => 'select', 
      '#title' => t('License Type'), 
      '#options' => array(
        'cc' => t('cc') 
      ), 
      '#required' => TRUE,
    );*/
    //options to include cv?

    $form += parent::options_form();
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    //@todo
    $block = parent::render();
    
    $vsite = vsite_get_vsite();
    if(!$vsite) return;

    // load the bio node for the owner of this vsite
    $bio_node = content_profile_load('bio', $vsite->group->uid);
    $cv_node = content_profile_load('cv', $vsite->group->uid);

  //ADD CV Link if Req
/*
    if ($cv_node && variable_get('scholar_biocv_use_pdf_as_cv', 0) && count($cv_node->field_cv_attach) && $cv_node->field_cv_attach[0]){
  	$s_filefield_alias = 'filefield_paths/alias/' . $cv_node->field_cv_attach[0]['fid'];
  	$alias = drupal_get_path_alias($s_filefield_alias);

  	if($alias && $s_filefield_alias != $alias){
  	  $s_file_path = str_replace($cv_node->field_cv_attach[0]['filepath'], $alias, file_create_url($cv_node->field_cv_attach[0]['filepath']));
  	}else{
  	 	$s_file_path = file_create_url($cv_node->field_cv_attach[0]['filepath']);
  	}

    $s_out .= t("<h3 class='cv-direct-download'>Download CV: ").l('PDF', $s_file_path)."</h3>";
  }
*/

    if ($bio_node){
      $s_out .= node_view($bio_node,false,true,true);
    }
  
    $block['content'] = $s_out;
    
    return $block;
  }

}