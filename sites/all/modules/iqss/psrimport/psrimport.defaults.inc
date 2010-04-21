<?php


function psrimport_vocabulary_defaults(){

  $vocabs = array();  
    //include these vocabularies
  $vocabs['standard'] =  array(
  3 => 'link', // 'Type of resource', //tags - Links/ Internet Resource or Tip
  7 => 'event', //tags - Event/ Event
  9 => 'announcement', //tags - Annoucements/ News
  5 => 'person',  //tags Profiles  
 10 => 'link', //combine with vocab 3 (term id 54, 55)'
  );  
    //new vocab type of page
 $vocabs['custom'] = array(
  1 => 'FAQ Topics', //Page
  6 => 'Opportunity Type', //Page
  );

  return $vocabs;
}