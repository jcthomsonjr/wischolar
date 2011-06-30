<?php

/**
 * @file
 * The class for "list" type widgets.  It allows users to define widgets that are 
 * list of posts (i.e. latest anouncements, blogs etc).
 * It's simply an interface to an existing view (as in views module)
 */

class os_boxes_list extends os_boxes_default {

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults(){
    $options = parent::options_defaults();
    
    $options['filter'] = 'all nodes';
    $options['number_of_posts'] = 8; //@todo whats a good default ?
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    
    $simpleview = $this->options;
    
    $form['filter'] = array(
      '#type' => 'select', 
      '#title' => t('Display'), 
      '#options' => array(
        'all' => t('All posts') 
      ), 
      '#required' => TRUE, 
      '#default_value' => $simpleview['filter'] 
    );
    
    vsite_include('vsiteapi');
    //$vsite_option = vsite_content_types();
    $vsite_option = node_get_types('names'); //@todod for testing only; delete and uncomment the line above
    
    foreach ( $vsite_option as $type => $name ) {
      $form['filter']['#options'][$type] = t('!type posts', array(
        '!type' => $name 
      ));
    }
    
    $form['number_of_posts'] = array(
      '#type' => 'textfield', 
      '#title' => t('Nr of posts'), 
      '#required' => TRUE, 
      '#default_value' => $simpleview['number_of_posts'] 
    );
    
    $form += parent::options_form();
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render(){
    $simpleview = $this->options;
    
    //if (notincache()){
      $output = $this -> execute_view($simpleview);
      // set in cache
    //}
    //else {
      // get from cache
    //}
    
    $block = parent::render();
    $block['content'] = $output;
    return $block;
  }

  // temporary
  private function execute_view($simpleview){

    //initialize the scholar base view
    $view = views_get_view('vsite_view_base');
    $type = $simpleview['filter'];

    $view->display['default']->display_options['filters']['type'] = array(
      'operator' => 'in', 
      'value' => array($type => $type), 
      
      'group' => 0, 
      'exposed' => FALSE, 
      'id' => 'type', 
      'table' => 'node', 
      'field' => 'type', 
      'relationship' => 'none' 
    );
    
    $view->init();
    $view->set_display('default');
    $view->display['default']->handler->options['items_per_page'] = $simpleview['number_of_posts'];
    
    return $view->execute_display();
  }

}



