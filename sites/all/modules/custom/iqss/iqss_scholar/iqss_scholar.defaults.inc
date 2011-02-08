<?php

/**
 * Config variables that apply only to IQSS installations
 * @return array
 */
function _iqss_scholar_config_variables(){
  $conf =  array(
  "addthis_username" => "iqssscholar", //Username for AddThis

  //PINSERVER Config Variables
  'pinserver_pin_url' => 'https://www.pin1.harvard.edu/pin/authenticate',
  'pinserver_landing_path' => 'site/register',
  'pinserver_auth_str' => 'Good signature from "authzproxy"',
  'pinserver_support_contact' => 'scholars_dev_support@help.hmdc.harvard.edu',
  'pinserver_hash_huid' => 0,

  //Remote Content Nodes
  'iqss_remote_source_node_types' => array('cv','scholar_software_project','page'),
  'iqss_remote_source_valid_ogs' => '3633', //Enable on Garys Site
  //imageapi image quality setting
  'imageapi_jpeg_quality' => 100,
  );

  // mollom settings (default) these will be replaced by domain specific if applicable
  $conf['mollom_private_key'] = '32a73b2d09c7576f1a5d4ca73ca9dead';
  $conf['mollom_public_key'] = 'fa9e0e813449535e5fcf06d6dda0d0f3';

  return $conf;
}

function _iqss_scholar_config_by_domain(){
	$config = array();
	switch(isqq_scholar_current_location()){
		case IQSS_DEV:
	    //PINSERVER Config Variables
	    $config['pinserver_app_name'] = 'FAS_IQSS_SCHOLARSWEB_DEV'; //TODO this needs to be the application name issued by directory services
	    $config['pinserver_gpg_dir'] = '/nfs/www/edu-harvard-iq-scholar-dev3/' . '.gnupg';
	    $config['error_level'] = 1; //Log to screen and log;
	    $config['openscholar_reportverinfo'] = 0;
	  break;
		case IQSS_LOCAL_DEV:
			//PINSERVER Config Variables
      $config['pinserver_app_name'] = 'FAS_IQSS_SCHOLARSWEB_DEV';
      $config['pinserver_gpg_dir'] = '/tmp/' . '.gnupg';
      $config['error_level'] = 1; //Log to screen and log;
      $config['openscholar_reportverinfo'] = 0;
		break;
		case IQSS_STAGING:
			//PINSERVER Config Variables
      $config['pinserver_app_name'] = 'FAS_IQSS_SCHOLARSWEB_TEST';
      $config['pinserver_gpg_dir'] = '/nfs/www/edu-harvard-iq-scholar-test/' . '.gnupg';
      $config['error_level'] = 0; //Log in background only
      $config['openscholar_reportverinfo'] = 0;
	  break;
		case IQSS_PRODUCTION:
			//PINSERVER Config Variables
			$config['pinserver_app_name'] = 'FAS_IQSS_SCHOLARSWEB';
			$config['pinserver_gpg_dir'] = '/nfs/www/edu-harvard-iq-scholar/' . '.gnupg';
			$config['error_level'] = 0; //Log in background only
			// mollom settings
      $conf['mollom_private_key'] = '32a73b2d09c7576f1a5d4ca73ca9dead';
      $conf['mollom_public_key'] = 'fa9e0e813449535e5fcf06d6dda0d0f3';
	  break;
		case IQSS_PROJECT_PRODUCTION:
			$config['pinserver_app_name'] = 'FAS_IQSS_SCHOLARSWEB_PROJECTS';
			$config['pinserver_gpg_dir'] = '/nfs/www/edu-harvard-iq-projects/' . '.gnupg';
      $config['error_level'] = 0; //Log in background only
		  // mollom settings
		  $conf['mollom_private_key'] = '89a61a5f00b4f996c0133e16dc9cb857';
		  $conf['mollom_public_key'] = '8429265e3d1b10dccc1a62ebf3eddb78';
		break;
	}
	return $config;
}