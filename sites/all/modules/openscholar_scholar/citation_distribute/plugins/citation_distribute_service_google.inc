<?php 

/*
 * @file
 * google scholar class provides publication methods to theme biblio nodes with google metadata
 */

class citation_distribute_service_google extends citation_distribute_service {

	
  public function save($nid, $plugin) {
  	/* google_scholar themes a node if it has an entry in {citation_distribute} with type=google_scholar
  	 * to reach this point that must have happened, so the change is already saved.
  	 */
		return true;
  }

  public function map_metadata($nid) {
    $metadata = array(
      'citation_journal_title'        => $node->biblio_secondary_title,
      'citation_publisher'            => $node->biblio_publisher,
      'citation_title'                => $node->title,
      'citation_year'                 => $node->biblio_year,
      'citation_volume'               => $node->biblio_volume,
      'citation_issue'                => $node->biblio_issue,
      'citation_firstpage'            => $node->biblio_section,
      'citation_lastpage'             => $node->biblio_section,
      'citation_issn'                 => $node->biblio_issn,
      'citation_isbn'                 => $node->biblio_isbn,
      'citation_language'             => $node->biblio_language,
      'citation_abstract'             => $node->biblio_abstract,
      'citation_abstract_html_url'    => $node->biblio_url,
      'citation_pmid'                 => $node->biblio_url,
      'citation_keywords'             => googlescholar_meta_keywords($node->biblio_keywords),
      'citation_pdf_url'              => check_plain($node->biblio_url),
      'citation_date'                 => googlescholar_meta_date($node->biblio_date),
      'citation_authors'              => googlescholar_meta_authors($node->biblio_contributors[1]),
    );
    
    return $metadata;
  }

  public function render($metadata) {

  }

}

