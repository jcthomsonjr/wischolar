<?php 

/**
 * @file
 * Class for sword plugin
 */

//should there be a getlink function that can link a page to the corresponding dash article?

abstract class citation_distribute_service_sword extends citation_distribute_service {
  public function __construct() {
  	parent::__construct();
  	
  	/* ensure that $location has trailing slash.  sword server won't respond to requests with a double slash */
  	if (!preg_match('/\/$/', $this->location)) {
  		$this->location .= '/';
  	}
  }
	
	/*
	 * Implementation of citation_distribute_service::save()
	 */
	public function save($nid, $plugin) {
		$metadata = $this->map_metadata($nid);
		$out = $this->render($metadata);
		$saved = $this->_push($out);
		
		return $saved;
	}
	
	/*
	 * Implementation of citation_distribute_service::render()
	 */
	public function render($metadata) {
		/* ensure we have a working directory or at least print some errors if we don't */
		$root_dir = $this->root_in . '/' . $this->subdir_in;
		if (!is_dir($root_dir)) {
			mkdir($root_dir, 0770, TRUE) || drupal_set_message('sword_meta: could not create deposit directory ' . $root_dir, 'error');
		}
			
		/* include sword lib */
		require_once(drupal_get_path('module', 'sword_meta') .	'/swordapp-php-library-1.0/packager_mets_swap.php');
		$packager = new PackagerMetsSwap($this->root_in, $this->subdir_in, $this->root_out, $this->file_out);
		
		/* add metadata to mets xml */
		foreach ($metadata as $name => $data) {
			// add to arrays
			if (is_array($data)) {
				$func = 'add' . $name;
				foreach ($data as $delta => $d) {
					if ($name == 'File') {
						$packager->$func($d['filepath'], $d['filemime']);  //	addFile takes mime as well
					} else {
						$packager->$func($d);
					}
				}
			} else {
				//set scalars if they have content
				if (strlen($data) > 0) {
	  			$func = 'set' . $name;
		  		$packager->$func($data);
				}
			}
		}
		
		/* attempt to write to xml file */
		try {
  		$packager->create();
		} catch (Exception $e) {
			drupal_set_message('sword_meta: ' . $e->getMessage(), 'error');
		return false;	
	}
	
	/* returns path to saved file */
	return $this->root_out . '/' . $this->file_out;
		
	}
	
	/*
	 * Implementation of citation_distribute_service::map_metadata()
	 */
	public function map_metadata($nid){
		$node = node_load($nid);
		
		/* copy static options and direct mappings first */
		$metadata = array(
			'Type' => 'http://purl.org/eprint/entityType/ScholarlyWork',
			'Title' => $node->title,
		  'Custodian' => $node->biblio_publisher,
	  	'Abstract' => $node->biblio_abst_e,
		);
		
		/* Add each author to Creator metadata */
		foreach($node->biblio_contributors as $delta => $cont) {
			foreach($node->biblio_contributors[$delta] as $contributor) {
				$metadata['Creator'][] = $contributor['firstname'] . ' ' . $contributor['lastname'];
			}
		}
		
		/* Add each file as well */
		foreach($node->files as $file) {
	    $metadata['File'][] = array( 
			 'filepath'=>url($file->filepath),  //TODO does mets want location or should file be included in teh zip?
			 'filemime'=>$file->filemime, 
			);
		}
		
		/* Create and add citation */
		$citation = 	theme('biblio_style', $node, variable_get('biblio_base', 'biblio'), biblio_get_style());
		$citation = strip_tags($citation);
	  $citation = preg_replace('/&nbsp;/', ' ', $citation);
		$metadata['Citation'] = $citation;
		
		/* Haven't found a mapping for these yet.
	  'Identifier' => '',
	  'DateAvailable' => '',
	  'StatusStatement' => '',
	  'CopyrightHolder' => '',
	  'Citation' => '',
	  */ 
		
		return $metadata;
	}
	
	/* send data to sword service */
	private function _push($file) {
		require_once(drupal_get_path('module', 'citation_distribute') .	'/plugins/swordapp-php-library-1.0/swordappclient.php');
		$sac = new SWORDAPPClient();
		$sac_doc = $this->_get_service_doc($sac);
		
		/* get deposit url.  unsure if there are any conditions that could result in multiple workspaces 
		 * or collections leading to multiple urls (maybe we can specify a default?  or maybe a user's taxonomy could
		 * be treated as a new collection)*/
		foreach($sac_doc->sac_workspaces as $ws) {
			foreach($ws->sac_collections as $collection) {
	  		$href = $collection->sac_href;
  	  	$xml = serialize($href);			//TODO figure out why simplexml methods aren't working.  Use that instead of regex.
  			$deposit_url = preg_replace('/.*"(http.*)".*/', '$1', $xml);
			}
		}
		
		/* attempt a deposit */
		try {
			$deposit = $sac->deposit($deposit_url, $this->username, $this->password, $this->obo, $file, '', 'application/zip');
		} catch(Exception $e) {
			drupal_set_message('Deposit error: ' . $e->getMessage, 'error');
			return false;
		}

		/* DEBUG: check the deposit status */
//		drupal_set_message($deposit->sac_statusmessage);//(string:79) Unacceptable content type in deposit request: application/x-www-form-urlencoded

		if ($deposit->sac_status != 200) { dsm($deposit); } //TODO: make some less dev-ey error messages
		
		return true;
	}
	
	private function _get_service_doc($sac) {

		/* retrieve service document from sword server */
		$service_url = $this->location . 'sword/servicedocument';
		$sac_doc = $sac->servicedocument($service_url, $this->username, $this->password, $this->obo);
	  
	  /* check status of service doc.  fix errors if possible, bail if not */
		switch($sac_doc->sac_status) {
			case 401:
				//auth problems are usually a bad on-behalf-of request.  drop the obo.  
				$sac_doc = $sac->servicedocument($service_url, $dest->username, $dest->password, '');
				//only break if we're still unauthorized.  otherwise check other cases
				if ($sac_doc->sac_status == 401) {
					drupal_set_error('Couldn\'t log in to SWORD server.', 'error');
					return false;
				}
			case 200:
				//logged in!
				break;
			default:
				//other, nonspecific error
				drupal_set_error('Error connecting to sword server', 'error');
				return false;
		}
		
		return $sac_doc;		
	}


}