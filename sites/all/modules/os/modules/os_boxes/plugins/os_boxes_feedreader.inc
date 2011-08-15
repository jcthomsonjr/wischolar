<?php

/**
 * @file
 * The class for "CC license" type widgets.  
 */

class os_boxes_feedreader extends os_boxes_default {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    $options['feed'] = '';
    $options['number_of_items'] = 10;
    
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    
    $form['feed'] = array(
      '#type' => 'select', 
      '#title' => t('Feed'), 
      '#options' => array(
        'all' => t('All') 
      ), 
      '#required' => TRUE,
    );
    
    
    //add this user's feeds to #options
    //$view = views_get_view('scholar_reader');
    //$view->set_display();
    $query = 'SELECT n.nid,n.title FROM {og_ancestry} og INNER JOIN {node} n on og.nid = n.nid WHERE n.type = "feed" '; //WHERE USER
    if ($vsite = vsite_get_vsite()) {
      $query .= ' AND og.group_nid = %d ';
      $uid = $vsite->id;
    } else {
      $uid = null;
    }
    $result = db_query($query, $uid);
    while ($r = db_fetch_object($result)) {
      $form['feed']['#options'] += array($r->nid => $r->title);
    }
    
    
    $form['number_of_items'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of items to display'),
      '#default_value' => $this->options['number_of_items']
    );

    $form += parent::options_form();
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    //@todo
    $view = views_get_view('scholar_reader');
    $view->set_display();
    $view->display_handler->set_option('items_per_page', $this->options['number_of_items']);
      
    if ($this->options['feed'] != 'all') {
      $view->set_arguments(array($this->options['feed']));
    }
    
    $block = parent::render();
    $block['content'] = $view->execute_display();
    return $block;
  }

}