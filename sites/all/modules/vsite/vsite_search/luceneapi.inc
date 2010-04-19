<?php

/**
 * @file
 *   This file contains Search Lucene-specific code, such as hook implementations.
 */

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