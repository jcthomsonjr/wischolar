<?php 
require_once(drupal_get_path('module', 'cp')  .'/settingsinc/cp.settings.site.inc');

/**
 * Provides theme selection for each site
 */
class scholar_setting_site extends cp_setting_site implements space_setting {

  function form($space, $value = array()) {
    $form = array('#title'=>'Site Information' );
    
    $form['scholar_headline'] = array(
      '#type' => 'textfield',
      '#title' => t('Main Headline'),
      '#default_value' => isset($value['scholar_headline'])?$value['scholar_headline']:'',
      '#size' => 60,
      '#description' => 'Ususally: First and Last name ex.(John Q. Smith)',
      '#maxlength' => 128,
      '#required' => TRUE,
    );
    $form['scholar_link_to_home'] = array(
      '#type' => 'checkbox',
      '#title' => t('Link to Home Page'),
      '#default_value' => isset($value['scholar_link_to_home'])?$value['scholar_link_to_home']:0,
    );
    $form['sub_heading'] = array(
      '#type' => 'textfield',
      '#title' => t('Sub Headline'),
      '#default_value' => isset($value['sub_heading'])?$value['sub_heading']:'',
      '#size' => 60,
      '#description' => 'Ususally: Title  ex.(Director of Mathmatics)',
      '#maxlength' => 128,
      '#required' => TRUE,
    );
    $form['scholar_sub_heading_extra'] = array(
      '#type' => 'textfield',
      '#title' => t('Address Line'),
      '#default_value' => isset($value['scholar_sub_heading_extra'])?$value['scholar_sub_heading_extra']:'',
      '#size' => 60,
      '#description' => 'Ususally: Your Address ex.(Cambridge, MA 02118)',
      '#maxlength' => 128,
      '#required' => FALSE,
    );
    $form['scholar_link_to_contact'] = array(
      '#type' => 'checkbox',
      '#attributes' => array('disabled' => 'disabled'), //disable till we get og_contacts in place
      '#title' => t('Add Link to contact form?'),
      '#default_value' => isset($value['scholar_link_to_contact'])?$value['scholar_link_to_contact']:0,
    );
    
    $form['example'] = array(
      '#type' => 'item',
      '#prefix' => "<div style='clear:both;'></div>",
      '#title' => t('Example'),
      '#value' => theme('image',drupal_get_path('module', 'scholar')  .'/theme/SiteInfoEx.png'),
    );
  
    return $form;
  }
  
  function submit($space, $value) {

    $value['headline'] = $value['scholar_link_to_home']?"<a href=\"".url("home")."\">{$value['scholar_headline']}</a>":$value['scholar_headline'];
    $value['sub_heading_extra'] = $value['scholar_link_to_contact']?$value['scholar_sub_heading_extra']." <a href='mailto:john@h.com'>(email)</a>":$value['scholar_sub_heading_extra'];
   
    return $value;
  }
  
}