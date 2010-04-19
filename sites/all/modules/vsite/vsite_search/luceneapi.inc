<?php

/**
 * @file
 *   This file contains Search Lucene-specific code, such as hook implementations.
 */

/**
 * Allows for altering of the document object before it is added to the index.
 * Invoking this hook allows developers to add additional fields, such as
 * CCK data, to the index.
 *
 * @param $doc
 *   A Zend_Search_Lucene_Document object being added to the index.
 * @param $item
 *   A mixed value modeling the content being added to the index, usually a
 *   Drupal node object.
 * @param $module
 *   A string containing the Search Lucene API module that is indexing the
 *   content.
 * @param $type
 *   A string containing the type of content indexed by $module.
 * @return
 *   NULL
 */
function vsite_search_luceneapi_document_alter($doc, $item, $module, $type = NULL) {
  if ($type == 'node') {
	  // Index group posts
	  if (!empty($item->og_groups)) {
	  	// The version of the ZF Components Search Lucene API is using does not support this feature. Unfortunately we have to delimit multiple values withing a single field.
	  	$group_nids = join(':', array_keys($item->og_groups));
	  	
	  	/**
	  	 * Adds the field to the Lucene document.  Valid field types are "keyword",
	     * "unindexed", "binary", "text", and "unstored".  See the Lucene field type
	     * documentation at http://drupal.org/node/655724 for more information on
	     * the index types.
	     */
	    luceneapi_field_add($doc, 'keyword', 'im_og_gid', $group_nids);   
	  }
  }
}

/**
 * Allows modules to append subqueries to the search query.  This hook is most
 * useful for adding filters, such as facets, to the search query.
 *
 * @param $query
 *   A Zend_Search_Lucene_Search_Query_Boolean object modeling the search query.
 * @param $module
 *   A string containing the Search Lucene API module handling the executed
 *   search.
 * @param $type
 *   A string containing the type of content $module indexes, NULL if no type.
 * @return
 *   NULL
 */
function vsite_search_luceneapi_query_alter($query, $module, $type = NULL) {

  // This example appends a subquery that filters search results to nodes of the
  // content type "page".

  // In this example, we are only concerned with node data.
  if ($type == 'node') {
    // Construct an object oriented term query that filters search results by
    // the "page" content type.  Search Lucene API queries are represented as
    // PHP objects.
    if ($type_query = luceneapi_query_get('term', 'type', 'im_og_gid')) {

      // Append the type query as a required subquery.
      luceneapi_subquery_add($query, $type_query, 'required');
    }
    else {

      // Log the error via watchdog().  This function also accepts Exception
      // objects as the first parameter, so it is encouraged to use this
      // function for consistency.
      luceneapi_throw_error(t('Error instantiating empty query.'), WATCHDOG_ERROR, $module);
    }
  }
}

/**
 * Since Lucene isn't strong at returning an entire resultset, this hook is
 * required by some realms that wish to display facets when either no search has
 * been executed or a search returns empty results.
 *
 * @param $facets
 *   An array containing facet definitions returned by hook_luceneapi_facet()
 *   implementations.
 * @param $realm
 *   A string containing the machine readable realm name the facets are being
 *   rendered in.
 * @param $module
 *   A string containing the search module that is collecting the available
 *   facets.  If Search Lucene Content is collecting facets, then $module will
 *   be "luceneapi_node".
 * @return
 *   An array of facets.
 */
function vsite_search_luceneapi_facet_empty($facets, $realm, $module) {
  $type = luceneapi_index_type_get($module);
  if ($type != 'node') {
    return;
  }
  
  switch($realm) {
    case 'block':
      $facets['type']['callback arguments'][0] = array('announcement');   
      //die('Module = '.$module.', Facets:<br><pre>'.print_r($facets,true).'</pre>');
      break;
  }
}

function vsite_search_luceneapi_facet_postrender_alter(&$items, $realm, $module, $type = NULL) {
  if ($type != 'node') {
    return;
  }
  // Additional filters, etc can be added to the query object
  $context = context_active_values();
  if(!empty($context['node'])) {
    $node_types = array_unique($context['node']);
    if(! empty($items['type']['items'])) {
    foreach($items['type']['items'] as $content_type => $item) {
        if(!in_array($content_type, $node_types)) {
          //unset($items['type']['items'][$content_type]);        
        }
      }
    }
  }
}