<?php 

/*
 * @ file defines dash as a sword destination
*/

class citation_distribute_service_sword_dash extends citation_distribute_service_sword {
	public $name = 			'dash';
	public $title = 		'DASH';
	public $location = 	'http://bachman.hul.harvard.edu:9034/';
	public $username = 	'jsagotsky@iq.harvard.edu';
	public $password =  'password';
	public $root_in  =  '/tmp/sword';
	public $subdir_in = 'dash';
	public $root_out =  '/tmp/sword';
	public $file_out =  'dash_files.zip';
}
