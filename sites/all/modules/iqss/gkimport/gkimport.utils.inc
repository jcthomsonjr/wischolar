<?php


function gkimport_taxonomy_get_tid($name, $vid = 0, $parent_tid = 0) {
  $tids = array();
  // if a vid is passed in, limit to it
  if ($vid) {
    $res = db_query("SELECT tid FROM {term_data} WHERE name = '%s' and vid = %d", $name, $vid);
    while($data = db_fetch_object($res)){
      $tids[] = $data -> tid;
    }
  }
//return drush_print_r($tids);
  if (count($tids) == 1){
    return $tids[0];
  }
  else {
    if(!count($tids)){
      drush_print("term: $name not found");
      return NULL;
    }
    else{
      $children =  taxonomy_get_children($parent_tid, $vid, $key = 'tid');
      foreach($children as $term){
        if ($term ->name == $name) return $term -> tid;
      }
    }
  }
}


function  gkimport_get_term_tid($term_name, $parent_name, $parent_tid = NULL, $tree){
  install_include(array('taxonomy'));
  $ri_vid = variable_get('gkimport_ri_vocab_id', '');
  //check for level 2 match
  if($parent_tid){
    $parent_matches = taxonomy_get_term_by_name($parent_tid);
    if (count($parent_matches)){
      foreach ($parent_matches as $parent){
        if ($parent-> vid == $ri_vid && $parent -> name  == $parent_name){
          //level 2 match
          return $parent_tid;
        }
      }
    }
    //check for sub terms
    reset($tree);
    foreach($tree as $level_1){
      foreach($level_1->children as $level_2) {
        if (count($level_2 -> children)){
          foreach($level_2 -> children as $level_3){
            if ($level_3-> name ==  $term_name) return $level_3 -> tid;
            if (count($level_3->children)){
              foreach ($level_3->children as $level_4){
                if ($level_4-> name ==  $term_name) return $level_4 -> tid;
              }
            }
          }
        }
      }
    }
  }
  else{
    return NULL;
  }
}
 
 function taxonomy_get_nested_tree($terms = array(), $max_depth = NULL, $parent = 0, $parents_index = array(), $depth = 0) {
  if (is_int($terms)) {
    $terms = taxonomy_get_tree($terms);
  }

  foreach($terms as $term) {
    foreach($term->parents as $term_parent) {
      if ($term_parent == $parent) {
        $return[$term->tid] = $term;
      }
      else {
        $parents_index[$term_parent][$term->tid] = $term;
      }
    }
  }

  foreach($return as &$term) {
    if (isset($parents_index[$term->tid]) && !is_null($max_depth) && $depth < $max_depth) {
      $term->children = taxonomy_get_nested_tree($parents_index[$term->tid], $max_depth, $term->tid, $parents_index, $depth + 1);
    }
  }

  return $return;
}
 

/**
 * Utility function - used to generate table data for biblio notes
 */
function gkimport_add_notes(){
  $filepath = GKIMPORT_FS_PATH . '/' . drupal_get_path('module', 'gkimport') . '/files/generate_pubnotes.txt';
  $data = unserialize(file_get_contents($filepath));
  //return dpm($data);

 foreach ($data as $info){
  db_query("INSERT INTO {biblio_notes_import} (title, notes) VALUES ('%s', '%s' ) ", $info['title'], $info['notes']);
  }

  foreach(_gkimport_generate_pubnotes_additional() as $info){
  db_query("INSERT INTO {biblio_notes_import} (title, notes) VALUES ('%s', '%s' ) ", $info['title'], $info['notes']);
  }
}
/**
 * Utility function - used to generate serialized data pubnotes file
 */
function gkimport_generate_notes_file(){
  $filepath = GKIMPORT_FS_PATH . '/' . drupal_get_path('module', 'gkimport') . '/files/generate_pubnotes.txt';
  $data_arr = array();
  $res=  db_query("SELECT * FROM {biblio_notes_import}");
  while ($data = db_fetch_object($res)){
    $data_arr[] = array('title' => $data -> title, 'notes' => $data -> notes);
  }
  $str = serialize($data_arr);
  file_put_contents($filepath, $str);
}
 
function gkimport_test_term_assignments(){
  $res = db_query("SELECT nid, biblio_type FROM biblio");
while($data = db_fetch_object($res)){

$match = db_result(db_query("SELECT * FROM term_node WHERE nid = %d", $data -> nid));

if($match){
$matches[] = $data -> nid;
}

else{
$node = node_load($data -> nid);
$nonmatches[] = $data -> nid . ' ' . $data ->biblio_type . ' ' . $node -> title;

$arr = array(100,101);

if (!in_array($data -> biblio_type, $arr)){
  
  $relnonmatches[] = $data -> nid . ' ' . $data ->biblio_type . ' ' . $node -> title;
  }
}

}
dpm($matches);
dpm($nonmatches);
dpm($relnonmatches);
  
}
