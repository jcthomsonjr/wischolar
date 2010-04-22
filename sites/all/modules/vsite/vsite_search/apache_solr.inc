<?php
// $Id$

/**
 * @file
 *   This file contains Apache Solr-specific code, such as hook implementations.
 */

/**
 * Implementation of hook_apachesolr_modify_query()
 * 
 * @param object $query
 *   Reference to the Solr_Base_Query object
 * @param mixed $params
 *   Controlling params for the query object
 */
function vsite_search_apachesolr_modify_query(&$query, &$params, $caller) {
  // Additional filters, etc can be added to the query object
  $context = context_active_values();
  if(!empty($context['node'])) {
    $node_types = array_unique($context['node']);
    /**
     * If there is more than one content type active in this context, additional filters need to be applied to the Solr query object
     * as an "or" condition instead of an "an" condition.  To do this, we need to utilize a Solr subquery.
     * 
     * If there's only one content type to filter by, simply add the new filter.
     */
    if(count($node_types) > 1) {
      $subquery = apachesolr_drupal_query();
      foreach($node_types as $type) {
        $subquery->add_filter('type', $type);
        $query->add_subquery($subquery, 'OR');
      }
    }
    else {
      $query->add_filter('type', $node_types[0]);
    }
  }
  
  /**
   * Retrieve the current group context.  If the user is viewing content within a group context, use the group's nid as a filter for the facets
   * to restrict results to within this group.  Searches performed outside of a vsite (top level) will not be filtered by group.
   */
  $vsite = vsite_get_vsite();
  if(!empty($vsite)) {
  	// Add filter for group_id
    $query->add_filter('im_og_gid', $vsite->group->nid);
    
    // Add filters based on the vsite vocabularies
  }
}

/**
 * Implementation of hook_apachesolr_facets().
 */
function vsite_search_apachesolr_facets() {
  $vsite = vsite_get_vsite();
  if(! empty($vsite)) {
    foreach($vsite->group->og_vocabularies as $tid => $term) {
      $key = 'im_vid_'.$term->vid;
      $facets[$key] = array(
        'info' => t('vSite Search: Filter by '.$term->name),
        'facet_field' => $key,
	    );
    }
  }
  return $facets;
}