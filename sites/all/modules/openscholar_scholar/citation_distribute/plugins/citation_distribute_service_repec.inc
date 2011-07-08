<?php 

/**
 * @file
 * Class for repec plugin
 */

class citation_distribute_service_repec extends citation_distribute_service {
	
	public $title = 'RePEc';
	public $inst_name = 'Jons repec test';
	public $archive_code = 'qsh';
	public $maintainer_name = 'Jon Sagotsky';	
	public $maintainer_email = 'jsagotsky@iq.harvard.edu';
	public $archive_path = '/tmp/citation_distribute/repec';
	public $archive_url = 'http://repec.iq.harvard.edu';
	public $provider_institution = 'RePEc:edi:cbrssus';  
	public $provider_homepage = 'http://scholar.harvard.edu';
	
	//repec also needs to deal with index files
	
	/**
	 * Distributes a node to chosen service(s)
	 */
	public function save($nid, $plugin){
		//rdf file for this node
		$metadata = $this->map_metadata($nid);
		$out = $this->render($metadata);
		$rdf_file = $this->_write($out, $nid); 		
		
		//index listing all nodes
		$index_file = $this->_index();
		
		//were index and rdf both successful
		return ($rdf_file && $index_file);
	}
	
	/**
	 * Copies data from biblio and node data into array labeled for this service
	 */
	public function map_metadata($nid){
		$node = node_load($nid);
		$bib_type = db_result(db_query('SELECT name FROM {biblio_types} WHERE tid = %d ', $node->biblio_type));
		$type = $this->_map_biblio_type($bib_type);
	  $out = array();
		$out['Handle'] = 'RePEc:' . $this->archive_code . ':' . $this->_get_template_type($type) . ':' .  $nid; 
	   
		//get node's URL
  	$path = 'node/'. $nid;  //using $node->nid notation here because pathauto changes URL when title changes		
	  if (module_exists('vsite') && (count($node->og_groups) == 1)){
	    $vsite = spaces_load('og', key($node->og_groups));
	    $file_url = $vsite->get_absolute_url() . $path;
	  }
	  elseif(module_exists('vsite') && (count($node->og_groups) > 1)){
	    //this should not happen
	    error_log("Alert: repec_meta has detected that node {$node->nid} belongs to multiple groups");
	    $vsite = vsite_get_vsite();    
	    $file_url = ( $vsite ) ? $vsite->get_absolute_url() . $path : '';
	  }
	  else{
	    $file_url = BASE_URL . '/' . $path;
	  }  	
	  $out['File-URL'] = $file_url;
	  
	  // add metadata to template array
	  foreach ($this->_get_type_metadata($type) as $biblio => $repec) {
	  	if (isset($node->{$biblio})) {
	  		if (is_string($node->{$biblio}) && strlen($node->{$biblio})) {
	  			//scalar values
		  		$out[$repec] = $node->{$biblio}; 
	  		
	  		} else {
	  			//arrays are special cases because each of them has various levels of nesting and the data we're trying to extract is uniquely named
					switch($biblio) {

						case 'biblio_contributors':
							$out[$biblio] = array();
							foreach($node->{$biblio} as $delta) {
								foreach($delta as $contributor) {							
		  						$out[$repec][] = $contributor['name'];
								}	
		  				}							
						break;
						
						case 'biblio_keywords':
							$out[$repec] = $node->{$biblio};
						break;
						

					}
	  		}
	  	} else {
	  		//$node->{$biblio} is not set.  this must be another exception
	  		switch ($biblio) {
  				//manipulate a string value before including it:
					case '{biblio_date}':
						$date = ($node->biblio_date) ? $node->biblio_date :  $node->biblio_year;
						//strtotime interprets '1957' as an hour not a year.  prepend 4 digit dates with a month and day.  bib_date is sometimes YYYY too, so we're doing this everywhere.
						$date = preg_replace( '/^(\d\d\d\d)$/', '01-01-$1', $date);
						$out[$repec] = date('Y-m', strtotime($date)); //yyyy-mm					
					break;
	  		}
	  	}
	  }
	  
	  return $out;
  	
	}
	
	/*
	 * Themes data into format appropriate for this service
	 */
	public function render($metadata){
		//Copy from array to string of 'key: value' format
		$out = '';
		foreach ($metadata as $key => $value) {
			if (is_string($value)) {
				$out .= $key . ': ' . trim(strip_tags($value)) . "\n";
			} elseif (is_array($value)) {
				foreach ($value as $subvalue) {
					$out .= $key . ': ' . trim(strip_tags($subvalue)) . "\n";
				}
			}
		}
		
		//Publications published by someone else need the publication-status field
		foreach (array('Publisher', 'Journal', 'Provider-Name') as $external_pub) {
			if (isset($metadata[$external_pub])) {
				$out .=  'Publication-Status: Published in ' . $metadata[$external_pub];
				break;
			}
		}
				
		return $out;
	}
	
	/* Given a biblio type, return a repec label for it */
	public function _map_biblio_type($biblio_type_name) {
		$types = array(
			'booktm' => array('Book'),
			'bookch' => array('Book Chapter'),
			'journl' => array('Journal Article','Newspaper Article','Magazine Article', 'Web Article', 'Film','Broadcast','Artwork','Manuscript',),
			'wpaper' => array('Conference Paper', 'Conference Proceedings','Thesis','Report','Hearing','Case','Bill','Statute', 'Patent','Personal','Map','Chart','Unpublished','Database','Government Report','Classical','Legal Ruling','Miscellaneous','Miscellaneous Section','Working Paper',),
			'sftwre' => array('Software','Audiovisual',),
		);
		
		foreach ($types as $name => $arr) {
			if (in_array($biblio_type_name, $arr)) {
				return $name;
			}
		}
		
		return false;
	}
	
	/* retrieves biblio -> repec metadata title mappings given a biblio type */ 
	public function _get_type_metadata($type) {
		$map = array(
			'booktm' => array(
				'biblio_contributors' => 'Editor-Name',
				'' => 'Editor-Email',
				'' => 'Editor-Workplace-Name',
				'title' => 'Title',
				'biblio_publisher' => 'Provider-Name',
				'biblio_abst_e' => 'Abstract',
				'biblio_keywords' => 'Keywords',
				'' => 'HasChapter',
				'biblio_volume' => 'Volume',
				'biblio_edition' => 'Edition',
				'biblio_year' => 'Year',
				'' => 'Month',
				'' => 'Classification-JEL',
				'' => 'File-URL',
				'' => 'File-Format',
				'' => 'Handle',
			),
			'bookch' => array(
				'biblio_contributors' => 'Author-Name',
				'' => 'Author-Email',
				'' => 'Author-Workplace-Name',
				'title' => 'Title',
				'biblio_abst_e' => 'Abstract',
				'biblio_keywords' => 'Keywords',
				'' => 'In-Book',
				'biblio_pages' => 'Pages',
				'biblio_volume' => 'Volume',
				'biblio_section' => 'Chapter',
				'biblio_edition' => 'Edition',
				'biblio_year' => 'Year',
				'' => 'Month',
				'' => 'Classification-JEL',
				'' => 'File-URL',
				'' => 'File-Format',
				'' => 'Handle',
				'biblio_publisher' => 'Publisher',
			),
			'journl' => array(
				'biblio_contributors' => 'Author-Name',
				'' => 'Author-Email',
				'' => 'Author-Workplace-Name',
				'title' => 'Title',
				'biblio_abst_e' => 'Abstract',
				'biblio_keywords' => 'Keywords',
				'biblio_secondary_title' => 'Journal',
				'biblio_pages' => 'Pages',
				'biblio_volume' => 'Volume',
				'biblio_issue' => 'Issue',
				'biblio_year' => 'Year',
				'' => 'Month',
				'' => 'Classification-JEL',
				'' => 'File-URL',
				'' => 'File-Format',
				'' => 'Handle',
			),
			'sftwre' => array(
				'biblio_contributors' => 'Author-Name',
				'' => 'Author-WorkPlace-Name',
				'' => 'Author-Email',
				'title' => 'Title',
				'' => 'Programming-Language',
				'biblio_tertiary_title' => 'Series',
				'' => 'Creation-Date',
				'biblio_pages' => 'Length',
				'' => 'Number',
				'' => 'Classification-JEL',
				'' => 'File-URL',
				'' => 'File-Format',
				'' => 'File-Function',
				'' => 'Handle',
				'biblio_publisher' => 'Publisher',
			),
			'wpaper' => array(
				'biblio_contributors' => 'Author-Name',
				'' => 'Author-X-Name-First',
				'' => 'Author-X-Name-Last',
				'' => 'Author-Email',
				'' => 'Author-Workplace-Name',
				'title' => 'Title',
				'biblio_abst_e' => 'Abstract',
				'biblio_keywords' => 'Keywords',
				'biblio_pages' => 'Length',
				'{biblio_date}' => 'Creation-Date',  //format the date before including it.
				'' => 'Revision-Date',
				'' => 'Publication-Status',
				'' => 'Number',
				'' => 'Classification-JEL',
				'' => 'File-URL',
				'' => 'File-Format',
				'' => 'File-Function',
				'' => 'Handle',
				'biblio_publisher' => 'Publisher',
			),
		);
		
		if (isset($map[$type])) {
			return $map[$type];
		} else {
			return false;
		}
	}
	
	/* gets Template-Type for this repec type */
	public function _get_template_type($repec_type) {
		$types = array(
			'wpaper' => 'ReDIF-Paper 1.0',
			'sftwre' => 'ReDIF-Software 1.0',
			'journl' => 'ReDIF-Article 1.0',
			'bookch' => 'ReDIF-Chapter 1.0',
			'booktm' => 'ReDIF-Book 1.0' ,
		);
			
		if (isset($types[$repec_type])) {
			return $types[$repec_type];
		} else {
			return false;
		}		
	}

	/* validate  */
	public function validate($a3) {
		/* ensures that we have all required metadata and a working paper */
		$tid = $a3['biblio_type']['#value'];
		$type = db_result(db_query('SELECT name FROM {biblio_types} WHERE tid = %d ', $tid));
		if ($this->_map_biblio_type($type) != 'wpaper') {
			form_set_error('biblio_type', 'The Publication Type of submissions to ' . $this->title . ' must be working paper.');
		}
		
		/* repec needs at least one author */
		$has_author = false;
		foreach ($a3['#post']['biblio_contributors'] as $bc) {
			foreach ($bc as $author) {
				if ( isset($author['name']) && strlen($author['name'])>0 ) {
					$has_author = true;
					break;
				}
			}
		}
		if (!$has_author) {
			form_set_error('biblio_contributors', 'At least one author is required for ' . $this->title . ' distribtuion');
		}
	}
	
	/* remove() when a node is unflagged, delete its rdf file */
	public function remove($nid) {
		
	}
	
	/* _write() saves rdf metadata to disk */
	public function _write($data, $nid) {
		//get the archive path
		$node = node_load($nid);
		$bib_type = db_result(db_query('SELECT name FROM {biblio_types} WHERE tid = %d ', $node->biblio_type));
		$type = $this->_map_biblio_type($bib_type);
		$path = $this->archive_path . '/' . $this->archive_code . '/' . $type . '/';
		
		//create the path if necessary.  otherwise fail.  mkdir goes to logs, but users get generic failure message
		if (!(is_dir($path)) || mkdir($path, 0775, TRUE)) {
			return false;
		}
		
		//name the file
		$file = $type . '_' . $nid . '.rdf';
		$filename = $path . '/' . $file;
		
		//write it and return the status
		return file_put_contents($filename, $data);
	}
	
	/* writes repec index file */
	public function _index() {
		//series file first
		$series_name = array(
			'sftwre' => 'Software',
			'journl' => 'Journal Article',
			'bookch' => 'Book Chapter',
			'booktm' => 'Book',
			'wpaper' => 'Working Paper',
		);
		
		//only create a listing for series that have their own folder
		//note that this means index should be run AFTER adding new rdfs.
		$path = $this->archive_path . '/' . $this->archive_code . '/';
		$all_series = array_intersect(scandir($path), array_keys($series_name));
		
		//generate series listing
		$seri = '';
		foreach ($all_series as $series) {
			$sn = $series_name[$series];
			
			$seri .= 'Template-type: ReDIF-Series 1.0' . "\n";
			$seri .= 'Name: ' . $this->inst_name . ' ' . $sn . ' Series' . "\n";
			$seri .= 'Provider-Name: '. $this->inst_name . "\n";
			$seri .= 'Provider-Homepage: ' . $this->provider_homepage . "\n";
			$seri .= 'Provider-Institution:  ' . $this->provider_institution . "\n";
			$seri .= 'Maintainer-Name: ' . $this->maintainer_name . "\n";
			$seri .= 'Maintainer-Email: ' . $this->maintainer_email . "\n";
			$seri .= 'Type: ReDIF-' . array_pop(explode(' ', $sn)) . "\n";    //only takes last word of series name...
			$seri .= 'Handle: RePEc:' . $this->archive_code . ':' . $series . "\n";
			$seri .= "\n";
		}
		
		//write to series file
		$file = $this->archive_code . 'seri.rdf';
		$filename = $path . '/' . $file;
		$series_out = file_put_contents($filename, $seri);
		
		//now for the arch file
		$arch  = 'Template-type: ReDIF-Archive 1.0' . "\n";
		$arch .= 'Handle: RePEc:' . $this->archive_code . "\n";
		$arch .= 'Name: ' . $this->inst_name . "\n";
		$arch .= 'Maintainer-Email: ' . $this->maintainer_email . "\n";
		$arch .= 'Description: ' . $this->inst_name . "\n";
		$arch .= 'URL: ' . $this->archive_url . "\n";
		
		//write
		$file = $this->archive_code . 'arch.rdf';
		$filename = $path . '/' . $file;
		$arch_out = file_put_contents($filename, $arch);

		//and done
		return ($series_out && $arch_out);
	}
}
