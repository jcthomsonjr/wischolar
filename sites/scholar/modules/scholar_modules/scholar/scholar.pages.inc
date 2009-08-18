<?php

function scholar_home(){

  $vsite = scholar_get_scholar();
  if ($vsite){
    $front_type = $vsite -> settings['front']['frontpage'];
   	switch ($front_type){
      case 'bio':
        $bio_nid = $vsite -> settings['bio']['nid'];
        $result = scholar_home_bio($bio_nid);
      break;
      case 'feature':
        $node_options = $vsite -> settings['front']['node_options'];
        $result = scholar_home_feature($node_options);
      break;
      case 'html':
        $front_nid = $vsite -> settings['front']['front_nid'];
        $result = scholar_home_html($front_nid);
      break;
      case 'flag':
        $result = scholar_home_flag();
      break;        
    }
    return $result;
  }
}

function scholar_home_bio($bio_nid){
  $node = node_load($bio_nid);
  $result = node_view($node, $teaser = FALSE, $page = FALSE, $links = FALSE);
  return $result;
}

function scholar_home_feature($node_options){

  return $result;
}

function scholar_home_html($front_nid){
  $node = node_load($front_nid);
  $result = node_view($node, $teaser = FALSE, $page = FALSE, $links = FALSE);
  return $result;
}

function scholar_home_flag(){
  return views_page("scholar_frontpage", "default");
}