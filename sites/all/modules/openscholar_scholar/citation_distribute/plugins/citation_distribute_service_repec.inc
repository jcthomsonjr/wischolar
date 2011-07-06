<?php 

/**
 * @file
 * Class for repec plugin
 */

class citation_distribute_service_repec extends citation_distribute_service {
	
	//repec also needs to deal with index files
	
	/**
	 * Distributes a node to chosen service(s)
	 */
	public function save($nid, $plugin){
		
	}
	
	/**
	 * Copies data from biblio and node data into array labeled for this service
	 */
	public function map_metadata($nid){
		$map = array(
			'booktm' => array(
				'ReDIF-Book 1.0' => 'Template-Type',
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
				'ReDIF-Chapter 1.0' => 'Template-Type',
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
				'ReDIF-Article 1.0' => 'Template-Type',
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
				'ReDIF-Software 1.0' => 'Template-Type',
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
				'ReDIF-Paper 1.0' => 'Template-Type',
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
		
	}
	
	/*
	 * Themes data into format appropriate for this service
	 */
	public function render($metadata){
		
	}
	
	/* Given a biblio type, return a repec label for it */
	private function _map_biblio_type($type) {
		$types = array(
			'booktm' => array('Book'),
			'bookch' => array('Book Chapter'),
			'journl' => array('Journal Article','Newspaper Article','Magazine Article', 'Web Article', 'Film','Broadcast','Artwork','Manuscript',),
			'wpaper' => array('Conference Paper', 'Conference Proceedings','Thesis','Report','Hearing','Case','Bill','Statute', 'Patent','Personal','Map','Chart','Unpublished','Database','Government Report','Classical','Legal Ruling','Miscellaneous','Miscellaneous Section','Working Paper',),
			'sftwre' => array('Software','Audiovisual',),
		);
		
		foreach ($types as $name => $arr) {
			if (in_array($type, $arr)) {
				return $name;
			}
		}
		
		return false;
	}
}

