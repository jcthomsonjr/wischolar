<?php 

/**
 * Config variables that apply only to IQSS installations
 * @return array
 */
function _iqss_scholar_config_variables(){
  return array(
  "addthis_username" => "iqssscholar", //Username for AddThis

  //PINSERVER Config Variables
  'pinserver_pin_url' => 'https://www.pin1.harvard.edu/pin/authenticate',
  'pinserver_landing_path' => 'site/register',
  'pinserver_auth_str' => 'Good signature from "authzproxy"',
  'pinserver_support_contact' => 'scholars_dev_support@help.hmdc.harvard.edu',
  'pinserver_hash_huid' => 0,
  
  //Remote Content Nodes
  'iqss_remote_source_node_types' => array('cv'),
  );
}

function _iqss_scholar_config_by_domain(){
	$config = array();
	switch(isqq_scholar_current_location()){
		case IQSS_DEV:
	    //PINSERVER Config Variables
	    $config['pinserver_app_name'] = 'FAS_IQSS_SCHOLARSWEB_DEV'; //TODO this needs to be the application name issued by directory services
	    $config['pinserver_gpg_dir'] = '/nfs/www/edu-harvard-iq-scholar-dev3/' . '.gnupg';
	    $config['error_level'] = 1; //Log to screen and log;
	  break;
		case IQSS_LOCAL_DEV:
			//PINSERVER Config Variables
      $config['pinserver_app_name'] = 'FAS_IQSS_SCHOLARSWEB_DEV'; 
      $config['pinserver_gpg_dir'] = '/tmp/' . '.gnupg';
      $config['error_level'] = 1; //Log to screen and log;
		break;
		case IQSS_STAGING:
			//PINSERVER Config Variables
      $config['pinserver_app_name'] = 'FAS_IQSS_SCHOLARSWEB_TEST';
      $config['pinserver_gpg_dir'] = '/nfs/www/edu-harvard-iq-scholar-test/' . '.gnupg';
      $config['error_level'] = 0; //Log in background only
	  break;
		case IQSS_PRODUCTION:
			//PINSERVER Config Variables
			$config['pinserver_app_name'] = 'FAS_IQSS_SCHOLARSWEB';
			$config['pinserver_gpg_dir'] = '/nfs/www/edu-harvard-iq-scholar/' . '.gnupg';
			$config['error_level'] = 0; //Log in background only
	  break;
		case IQSS_PROJECT_PRODUCTION:
			$config['pinserver_app_name'] = 'FAS_IQSS_SCHOLARSWEB_PROJECTS';
			$config['pinserver_gpg_dir'] = '/nfs/www/edu-harvard-iq-projects/' . '.gnupg';
      $config['error_level'] = 0; //Log in background only
		break;
	}
	return $config;
}