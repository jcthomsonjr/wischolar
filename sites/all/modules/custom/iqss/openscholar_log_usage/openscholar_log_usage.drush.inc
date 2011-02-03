<?php
// $Id$

/** 
 * @file  openscholar log viewer drush commands
 */

/**
 * Implementation of drush_help
 */

function openscholar_log_usage_drush_help($section) {
    switch ($section) {
    case 'drush:check_installations':
        return dt("Check which OpenScholar installation sites appear active.");
    }
}

/**
 * Implementation of drush_command
 */
function openscholar_log_usage_drush_command() {
	$items = array();
	
	$items['check-installations'] = array(
		'description' => "Poke logged installations, check their validity",
		'options' => array(
			'vsites' => 'Minimum number of vsites an installation can have. (default=5)',
			'age' => 'Days since last visit.  Sites with last visits older than this value will be disregarded. (default=90)',
			'connections' => 'How many simultaneous connections to use when pinging servers.  File handle limits vary from system to system.  (default=16)',
			'verbose' => 'Show debugging output (default=FALSE).',
		),
		'examples' => array(
			'drush @site check-installations --vsites=5 --age=30' => 'Check logs on @site for OpenScholar installations with at least 5 vsites and visited within the last 30 days.',
		),
		'aliases' => array('ci'),
		'bootstrap' => 'DRUSH_BOOTSTRAP_DRUPAL_DATABASE', 
	);
	
	return $items;
}

/**
 * implementation of drush_COMMAND_validate
 * 
 * Breaks if any variables are invalid
  */

function drush_openscholar_log_usage_check_installations_validate() {
	
	$vsites =      (int)_drush_get_option_type('vsites', 'int', 5);
	$age =         (int)_drush_get_option_type('age', 'int', 90);
	$connections = (int)_drush_get_option_type('connections','int', 16);
	$verbose =     (bool)_drush_get_option_type('verbose', 'boolean', FALSE);
	
	if ( $vsites < 0 ) {
		return drush_set_error('INVALID_VSITE', dt('vsite must be a non-negative integer number'));
	}

	if ( $age < 0 ) {
		return drush_set_error('INVALID_AGE', dt('age must be a non-negative integer number'));
	}
	
	if ( $connections <= 0 ) {
		return drush_set_error('INVALID_CONNECTIONS', dt('connections must be a positive number'));
	}
	
}


/**
 * Checks known openscholar installations
 *
 * @returns List of urls
 */
function drush_openscholar_log_usage_check_installations() {
	require_once drupal_get_path('module','openscholar_log_usage').'/openscholar_log_usage.inc';

	$vsites =      (int)_drush_get_option_type('vsites', 'int' , 5);
	$age =         (int)_drush_get_option_type('age', 'int', 90);
	$connections = (int)_drush_get_option_type('connections', 'int', 16);
	$verbose =     (bool)_drush_get_option_type('verbose', 'boolean', FALSE);
			
	$_hosts    = _openscholar_log_usage_list_hosts($vsites, $age, $verbose);
	$_filtered = _openscholar_log_usage_filter_hosts($_hosts, $verbose);
	$_os_hosts = _openscholar_log_usage_ping_hosts($_filtered, $connections, $verbose);
	
	foreach ($_os_hosts as $host => $content) {
            echo "$host\n";
	}
	//return TRUE;
}

/**
 * Gets an option and assigns a type.  Makes sure php casting preserves some semblance of original value intead of converting "string" to 0 on an (int) cast.
 * 
 * @param $option
 *   Which command line arg to retrive
 * @param $type
 *   Cast $option to this type or die trying
 * @param $default
 *   If unspecified, use this value
 * @param $context
 *   See drush's context explanation
 *   
 * @return
 *   Either returns the value of the option or a drupal_set_error (which breaks the script if called in drush_COMMAND_validate.
 */
function _drush_get_option_type($option, $type, $default = NULL, $context = NULL) {
	$value = drush_get_option( $option, $default, $context );

	switch($type) {
		
		case 'int':
			$value_cast = (int)$value;
			if ($value != (string)$value_cast) {
				return drush_set_error('BAD_CAST_INT', dt('Could not cast option '.$option.' to type '.$type.' without losing value.'));
			} else {
				return $value_cast;
			}	
			break;

			
		case 'boolean':
		case 'bool':
				$_truth_values = array('t', 'true',  'True',  'T', 'TRUE',  "1");
				$_false_values = array('f', 'false', 'False', 'F', 'FALSE', "0");
				
				if (in_array($value, $_truth_values)) {
					return TRUE;
				} elseif (in_array($value, $_false_values)) {
					return FALSE;
				} else {
					return drush_set_error('BAD_CAST_BOOL', dt('Could not cast option '.$option.' to type '.$type));
				}
			break;
                default:
                    return drush_set_error('BAD_TYPE', dt('_drush_get_option_type does not yet support type '.$type));
			
	}
}

