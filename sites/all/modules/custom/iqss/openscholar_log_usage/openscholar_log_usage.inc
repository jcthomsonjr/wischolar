<?php 
// $Id$

/**
 * @file
 * Functions for openscholar_log_usage_report
 *
 * This file is broken into three main functions.  They grab hosts from mysql, filter out development hosts by name, and finally ping all hosts to make sure they're active and contain openscholar code.

 /**
  * List hosts from usage log
  *
  * @param vsites
  *	  Minimum number of vsites an installation have to be considered worth looking at.  Active sites will usually have more than a single user and admin.
  * @param $age
  *	  Ignore sites whose last visit was more than $age days ago.
  * @param $verbose
  * 			If true, show debug messages
  * @return
  *	  db results from query described by vsite_min and last_visit
 */
function _openscholar_log_usage_list_hosts($vsites, $age, $verbose) {
	//table has host, host_name, vsite, age, views, version, last_visit
	$sql = 'SELECT DISTINCT host FROM {openscholar_usage_log}
		WHERE DATE_SUB(CURDATE(), INTERVAL %d DAY) <= last_visit
		GROUP BY host
		HAVING COUNT(DISTINCT vsite) >= %d
		';

	if ($verbose) {
		drush_print("\nQuerying installations visited within the last $age days and hosting $vsites or more vsites.\n");
	}

	//$result = db_query(db_rewrite_sql($sql));
	/* hook_db_rewrite_sql is adding a check for node permissions.  that's irrelevant and breaks the query because node permissions do not apply to this check. */
	$result = db_query($sql, $age, $vsites);

	return $result;	
}

/**
 * Removes hosts likely to be illegit. 
 * 
 * @param $hosts
 *	  db result containing hosts.
 * @param $verbose
 * 		   If true, show debug messages
 * @return
 *	  Array of hosts deemed valid.
 */
function _openscholar_log_usage_filter_hosts($hosts, $verbose) {
	$_hosts = array();
	while ($data = db_fetch_object($hosts)) {
		$_hosts[] = $data->host;
	}
	$host_count = count($_hosts);

	$_hosts = preg_grep( '/.*demo|dev|local|sandbox|test|\d$.*/', $_hosts, PREG_GREP_INVERT); 
	$_hosts = preg_grep('/\./', $_hosts);

	$filtered_host_count = count($_hosts);

	if ($verbose) {
		drush_print("Kept $filtered_host_count of $host_count hosts.");
	}

	return $_hosts;
}


/** 
 * Check if site content looks like openscholar
 */

function _is_openscholar($content) {
	$needle = '/http:\/\/openscholar\.harvard\.edu\/openscholar_lu\/spacer\.gif/';
	return preg_match( $needle, $content );
}

/**
 * Ping each host and make sure they still have OS code
 * Enter description here ...
 * @param unknown_type $hosts
 * 			list of hosts to ping
 * @param int $connections
 * 		how many simultaneous connections to use
 * @param $verbose
 * 			If true, show debug messages
 */
function _openscholar_log_usage_ping_hosts($hosts, $connections, $verbose) {

	$curling = array();		 //active curl handles
	$done = array();			//store finished host => content
	$mh = curl_multi_init();
	$is_running = null;

	do {
		//fill up the curl queue at start of reqs and if any urls have finished
		while (sizeof($curling) <= $connections && sizeof($hosts) > 0) {
			$host = array_pop($hosts) ;
			$curling[$host] = curl_init( $host );
			curl_setopt( $curling[$host], CURLOPT_CONNECTTIMEOUT, 10 );
			curl_setopt( $curling[$host], CURLOPT_RETURNTRANSFER, true );
			curl_multi_add_handle( $mh, $curling[$host] );

			if ($verbose) {
				drush_print("beginning\t >> $host");					
			}
		}

		// run curl
		curl_multi_exec($mh, $is_running);

		//pop finished hosts.
		//curl_multi_remove_handle also removes the downloaded data, so we stash it for later.
		$ready = curl_multi_select($mh);
		$info = curl_multi_info_read($mh);
		if ( $info && $info['msg']==CURLMSG_DONE ) {
			//copy response
			$host = curl_getinfo( $info['handle'], CURLINFO_EFFECTIVE_URL );
			$host = str_replace("HTTP://", "", $host);
			$http_code = curl_getinfo( $info['handle'], CURLINFO_HTTP_CODE );
			$content = curl_multi_getcontent( $info['handle'] );

			if ($verbose) {
				drush_print("finished\t .. $host");
			}

			/* only keep valid urls */
			if ($http_code && _is_openscholar($content) ) { 
				$done[$host] = $content;

				if ($verbose) {
					drush_print("keeping\t\t ++ $host");
				}
			} elseif ($verbose) {
				drush_print("discarding\t -- $host");
			}

			//remove from queue and close handles.
			curl_multi_remove_handle( $mh, $curling[$host] );
			curl_close( $curling[$host] );
			unset( $curling[$host] ); 

		}

	} while ($is_running>0);

	if ($verbose) {
		drush_print(" ");
	}

	return $done;
}



