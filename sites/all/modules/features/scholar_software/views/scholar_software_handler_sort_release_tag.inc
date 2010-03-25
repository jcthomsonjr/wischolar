<?php
// $Id$

/**
 * Sort handler for release tag.
 */
class scholar_software_handler_sort_release_tag extends views_handler_sort {
  /**
   * Called to add the sort to a query.
   */
  function query() {
    $table = 'node_data_field_scholar_software_project';
    $table_alias = $this->query->ensure_table($table, $this->relationship);

    // Order by:
    // 1. no_extra pseudo-field (e.g. 2.0 before 2.0-beta1).
    // 2. versionmajor (2.x before 1.x).
    // 3. versionpatch (2.1 before 2.0).
    // 4. versionextra (2.1-beta1 before 2.1-alpha1).

    // 2.
    $this->query->add_field(NULL, "IF ({$table}.field_versionextra_value IS NULL, 1, 0)", "{$table}_no_extra");
    $this->query->add_orderby(NULL, NULL, $this->options['order'], "{$table}_no_extra");

    // 3-5.
    $fields = array(
      array('field_name' => 'field_versionmajor'),
      array('field_name' => 'field_versionpatch'),
      array('field_name' => 'field_versionextra'),
    );
    foreach ($fields as $field) {
      $column = $field['field_name'] .'_value';
      $this->query->add_orderby($table_alias, $column, $this->options['order']);
    }
  }
}
