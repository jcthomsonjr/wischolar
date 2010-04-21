<?php

/**
 * @file
 *   This file contains Search Lucene-specific code, such as hook implementations.
 */

/**
 * Provides access to the facets before they are rendered.
 *
 * @param &$facets
 *   An array containing facet definitions returned by hook_luceneapi_facet()
 *   implementations.
 * @param $realm
 *   A string containing the machine readable realm name the facets are being
 *   rendered in.
 * @param $module
 *   A string containing the search module that is collecting the available
 *   facets.  If Search Lucene Content is collecting facets, then $module will
 *   be "luceneapi_node".
 * @param $type
 *   A string containing the type of content $module indexes, NULL if no type.
 * @return
 *   NULL
 */
function vsite_search_luceneapi_facet_alter(&$facets, $realm, $module, $type = NULL) {
	if($realm == 'block') {
		$vsite = vsite_get_vsite();
		if(!empty($vsite)) {
			// Remove the taxonomy facets for vocabularies that are not assigned to this vsite
		  foreach($vsite->group->og_vocabularies as $tid => $term) {
        $category_name = 'category_'.$term->vid;
        if(in_array($category_name, array_keys($facets))) {
          //unset($facets[$category_name]);
        }
		  }

		  // Define the taxonomy facets for vocabularies assigned to this vsite
			foreach($vsite->group->og_vocabularies as $tid => $term) {
        $facets['category_'. $term->vid] = array(
	        'title' => $term->name,
	        'element' => 'category',
	        'field' => 'category_'. $term->vid,
	        'type' => 'select',
	        'callback' => 'luceneapi_facet_multiterm_callback',
	        'callback arguments' => array(
	          luceneapi_facet_value_get('category', array()), 'category', TRUE
	        ),
	        'delimiter' => ' ',
	        'description' => t(
	          'Filter by terms in the %vocabulary vocabulary.',
	          array('%vocabulary' => $term->name)
	        ),
	      );
			}
		}
	}
}

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
	    luceneapi_field_add($doc, 'keyword', 'im_og_gid', $item->og_groups);   
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
	// Load the current vsite
  $vsite = vsite_get_vsite();
  if(!empty($vsite)) {
		if($type == 'node') {
			// Add a filter to the query to limit results to nodes belonging to this vsite
	    luceneapi_subquery_add($query, luceneapi_query_get('term', $vsite->group->nid, 'im_og_gid'));
		}
  }

  /**
   * Features have a status of public, private, or disabled.  This extra layer of privacy does not implement node_access, and so for features that
   * are marked as private, the content types for these features need to be excluded from search.
   */
  $vsite = vsite_get_vsite();
  foreach($vsite->features as $feature => $status) {
  	switch($status) {
  		case 0:
  			// disabled
  			break;
  		case 1:
  			// private
  			break;
  		case 2:
  			// public
  			break;
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
	// The following example is a simplified version of code in the
  // luceneapi_node_luceneapi_facet_empty() function.  It allows the "Content
  // type" facet to be displayed in the "block" realm even if no search has been
  // executed.

  // The example is only valid for "node" content in the "block" realm.
  $type = luceneapi_index_type_get($module);
  if ('node' != $type || 'block' != $realm) {
    return;
  }

  // Initializes return array.
  $items = array();

  $context = context_active_values();
  // Load the current vsite and use the group id as a filter to only show content/facets for this particular vsite
  $vsite = vsite_get_vsite();
  if(!empty($vsite)) {
  	$items += vsite_search_luceneapi_facet_empty_content_types($vsite->group->nid, $context['node']);
  	//$items += vsite_search_luceneapi_facet_empty_authors($gid, $context['node']);
  	$items += vsite_search_luceneapi_facet_empty_taxonomy(array_keys($vsite->group->og_vocabularies), $context['node']);
  }
  return $items;
}

function vsite_search_luceneapi_facet_empty_content_types($gid=0, $content_types=array()) {
	if($gid) {
    $sql = 'SELECT n.type, COUNT(*) AS num'
         .' FROM {node} n'
         .' LEFT JOIN {node_type} t ON n.type = t.type'
         .' LEFT JOIN {og_ancestry} og ON og.nid = n.nid'
         .' WHERE n.status = 1'
         .' AND n.type IN ('.db_placeholders($content_types, 'varchar').')'
         .' AND og.group_nid = %d'
         .' GROUP BY n.type'
         .' ORDER BY num DESC';
    $result = db_query(db_rewrite_sql($sql), $content_types, $gid);
  }
  
  // Initializes the array containing facet information.  The array mimics how
  // the luceneapi_facet_block_realm_render() function renders facets.
  $items['group_type'] = array(
    'title' => $facets['type']['title'],
    'field' => $facets['type']['field'],
    'element' => $facets['type']['element'],
    'selected' => array(),
    'count' => array(),
    'items' => array(),
  );

  // Executes query and adds facet items to the $items array.
  if ($result) {
    while ($row = db_fetch_object($result)) {
      $items['group_type']['items'][$row->type] = array(
        'function' => 'luceneapi_facet_link',
        'text' => $row->type,
        'path' => sprintf('search/%s/%s:%s', $module, $facets['type']['element'], $row->type),
        'options' => array(),
        'count' => $row->num,
    	  'gid' => $gid,
      );
    }
  }
  //die('Items:<br><pre>'.print_r($items,true).'</pre>');
  return $items;
}

function vsite_search_luceneapi_facet_empty_authors($gid, $content_types) {
	$items = array();
	
	return $items;
}

function vsite_search_luceneapi_facet_empty_taxonomy($og_vocabs=array(), $content_types=array()) {
	$items = array();
	foreach($og_vocabs as $vid) {
		$items['group_category_'.$vid] = array(
	    'title' => t('Group Categories'),
	    'field' => 'category_'.$vid,
	    'element' => 'select',
	    'selected' => array(),
	    'count' => array(),
	    'items' => array(),
	  );
	  
	  if(empty($content_types)) {
      $sql = 'SELECT tn.vid as vid, tn.tid AS id, td.name as name, COUNT(*) AS num'
           .' FROM {node} n'
           .' LEFT JOIN {term_node} tn ON n.vid = tn.vid'
           .' LEFT JOIN {term_data} td ON tn.tid = td.tid'
           .' WHERE n.status = 1 '
           .' AND td.vid IN ('. db_placeholders($og_vocabs, 'int').')'
           .' GROUP BY tn.vid, tn.tid'
           .' ORDER BY num DESC';
      $result = db_query(db_rewrite_sql($sql), $og_vocabs);
	  }
	  else {
	  	$sql = 'SELECT tn.vid as vid, tn.tid AS id, td.name as name, COUNT(*) AS num'
           .' FROM {node} n'
           .' LEFT JOIN {term_node} tn ON n.vid = tn.vid'
           .' LEFT JOIN {term_data} td ON tn.tid = td.tid'
           .' WHERE n.status = 1'
           .' AND td.vid = %d'
           .' AND n.type IN ('.db_placeholders($content_types, 'varchar').')'
           .' GROUP BY tn.vid, tn.tid'
           .' ORDER BY num DESC';
      $result = db_query(db_rewrite_sql($sql), $vid, $content_types);
	  }
    if($result) {
    	while($row = db_fetch_object($result)) {
    		$items['group_category_'.$vid]['items'][$row->id] = array(
		      'function' => 'luceneapi_facet_link',
		      'text' => $row->name,
          'path' => sprintf('search/%s/%s:%s', 'luceneapi_node', 'category', $row->id),
	        'options' => array(),
    			'count' => $row->num,
		    );
      }
    }
	}
	return $items;
}