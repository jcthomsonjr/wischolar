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
	public $archive_path = '/tmp/cite_distribute/repec';
	public $archive_url = 'http://repec.iq.harvard.edu';
	public $provider_institution = 'RePEc:edi:cbrssus';  
	
	//repec also needs to deal with index files
	
	/**
	 * Distributes a node to chosen service(s)
	 */
	public function save($nid, $plugin){
		$metadata = $this->map_metadata($nid);
		$out = $this->render($metadata);
		$this->save($nid, $plugin);
		
		//don't forget index files!
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
						break;
					}
	  		}
	  	}
	  }
	  
	  return $out;
  	
	}
	
	/*
	 * Themes data into format appropriate for this service
	 */
	public function render($metadata){
		//save metadata to file
		$out = '';
		foreach ($metadata as $key => $value) {
			if (is_string($value)) {
				$out .= $key . ': ' . strip_tags($value) . '\n';
			} elseif (is_array($value)) {
				foreach ($value as $subvalue) {
					$out .= $key . ': ' . strip_tags($subvalue) . '\n';
				}
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
				'biblio_date' => 'Creation-Date',
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
}
