<?php
// $Id: luceneapi_dym.index.inc,v 1.5 2009/12/12 01:40:23 cpliakas Exp $

/**
 * @file
 * Index maintenance functions for Search Lucene DidYouMean.
 *
 * @ingroup luceneapi_dym
 */

/**
 * Returns an array of terms in the Search Lucene Content index.
 *
 * @return
 *   An array of terms.
 */
function luceneapi_dym_node_terms_get() {
  $node_terms = array();
  try {
    if (!$index = luceneapi_index_open('luceneapi_node', $errstr)) {
      throw new LuceneAPI_Exception($errstr);
    }

    // gets all searchable fields to harvest terms from
    $available = array_merge(
      module_invoke_all('luceneapi_node_bias_fields'),
      module_invoke_all('luceneapi_node_bias_tags')
    );
    $fields = array();
    foreach ($available as $field => $info) {
      $variable = sprintf('luceneapi_node:bias:%s', $field);
      if (variable_get($variable, $info['default'])) {
        $fields[] = $field;
      }
    }

    // gets terms in the enabled fields
    foreach (luceneapi_index_terms_get($index, TRUE) as $term) {
      if (in_array($term->field, $fields, TRUE)) {
        $node_terms[] = $term->text;
      }
    }
  }
  catch (Exception $e) {
    luceneapi_throw_error($e, WATCHDOG_ERROR, 'luceneapi_node');
  }
  return array_unique($node_terms);
}

/**
 * Returns an array of terms in the DidYouMean dictionary index.
 *
 * @return
 *   An array of terms.
 */
function luceneapi_dym_dictionary_terms_get() {
  $dictionary_terms = array();
  try {
    if (!$dictionary = luceneapi_index_open('luceneapi_dym', $errstr)) {
      throw new LuceneAPI_Exception($errstr);
    }
    foreach (luceneapi_index_terms_get($dictionary, TRUE) as $term) {
      if ($term->field === 'word') {
        $dictionary_terms[] = $term->text;
      }
    }
  }
  catch (Exception $e) {
    luceneapi_throw_error($e, WATCHDOG_ERROR, 'luceneapi_dym');
  }
  return array_unique($dictionary_terms);
}

/**
 * Updates the DidYouMean index.
 *
 * @return
 *   NULL
 * @see luceneapi_dym_update_index
 */
function _luceneapi_dym_update_index() {
  try {
    if (!$index = luceneapi_index_open('luceneapi_dym', $errstr)) {
      throw new LuceneAPI_Exception($errstr);
    }

    // gets terms in luceneapi_node, luceneapi_dym indexes
    $node_terms = luceneapi_dym_node_terms_get();
    $dictionary_terms = luceneapi_dym_dictionary_terms_get();

    // finds the differences in the indexes
    if (empty($node_terms)) {
      $diff = array();
      luceneapi_index_wipe($index);
    }
    elseif (empty($dictionary_terms)) {
      $diff = $node_terms;
    }
    else {
      $diff = array_diff($node_terms, $dictionary_terms);
    }
    if (!empty($diff)) {
      register_shutdown_function(
        'cache_clear_all', 'luceneapi_dym:', LUCENEAPI_CACHE_TABLE, TRUE
      );
    }

    // truncates diff to $limit
    $limit = luceneapi_variable_get('luceneapi_dym', 'update_limit');
    $diff = array_slice($diff, 0, $limit);

    // adds or removes terms from dictionary
    foreach ($diff as $word) {
      if (in_array($word, $node_terms)) {
        if ($document = luceneapi_dym_document_get($word)) {
          luceneapi_document_add($index, $document, $word, TRUE);
        }
      }
      else {
        luceneapi_document_delete($index, $word, 'word', $word, TRUE);
      }
    }

    // optimizes luceneapi_dym index if option is set
    if (luceneapi_variable_get('luceneapi_dym', 'optimize_on_update')) {
      luceneapi_index_optimize($index, TRUE);
      if (luceneapi_log_level_compare(WATCHDOG_INFO)) {
        watchdog('luceneapi_dym', 'Index optimized.', array(), WATCHDOG_INFO);
      }
    }
    else {
      luceneapi_index_commit($index, TRUE);
    }

  }
  catch (Exception $e) {
    luceneapi_throw_error($e, WATCHDOG_ERROR, 'luceneapi_dym');
  }
}
