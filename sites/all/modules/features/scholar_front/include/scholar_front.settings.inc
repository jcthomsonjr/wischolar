<?php

/**
 * Provides front page settings for each site
 */
class scholar_front_settings_front implements space_setting {
  var $id;

  function __construct($id = NULL){
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'front';
    }
  }

  function form($vsite, $value = array()){
    $vsite = vsite_get_vsite();
    vsite_include('nodeautocomplete');
    vsite_include('vsiteapi');
    ctools_include('dependent');
    ctools_include('form');
    
    // the "add new *" links
    $items = vsite_create_links('/front');
    $links = theme('ctools_dropdown', t('add new'), $items, FALSE, 'panels-display-links');
    
    $form = array(
      '#title' => 'Front Page'
    );

    if(!$vsite) return $form;

    /**
     * main options
     * 1. your bio page
     * 2. one of your feature / content types
     * 3. one of your posts
     * 4. Hand-pick as you go
     */
    
    //Init the dependent dropdown (called here in case we are in a modal popup)

    // is scholar_biocv feature turned on for this vsite ?
    $biocv_feature = array_key_exists("scholar_biocv", $vsite->features);
    $options = array(
      'bio' => t('Your bio page'),
      'feature' => t('Posts from specific feature(s)'),
      'html' => t('One of your posts'),
      'flag' => t('Hand-pick content as you go')
    );
    if (!$biocv_feature){
      unset($options['bio']);
    }

    $form['frontpage'] = array(
      '#title' => t('What do you want in the main content area of your front page?'),
      '#type' => 'radios',
      '#options' => $options,
      '#default_value' => isset($value['frontpage']) ? $value['frontpage'] : 'bio',
      '#tree' => TRUE,
      '#weight' => 1,
    );

    // BIO
    // only if they have selected bio as feature
    if ($biocv_feature) {
      $bio_node = content_profile_load("bio", $vsite->group->uid);
      //$bio_nid = (isset($vsite -> settings['bio']['nid']) && is_numeric($vsite -> settings['bio']['nid'])) ? $vsite -> settings['bio']['nid'] : '';
      if ($bio_node) {
        $link = l('Bio', "node/" . $bio_node->nid);
        $description = "Your " . $link . " will be used as your front page";
      }
      else {
        $link = l(t('Create'), "node/add/bio", array(
          'query' => array(
            'destination' => $_GET['q']
          )
        ));
        $description = "You dont have a bio yet. $link one now";
      }

      // do they want to include the bio title
      $form['bio_title'] = array(
        '#type' => 'checkbox',
        '#title' => t('Include title'),
        '#description' => t('Do you want to include the title of the post in the page?')."<br /><br /><div class='info'>{$description}</div>",
        '#default_value' => isset($value['bio_title']) ? $value['bio_title'] : 1,
        '#process' => array(
          'ctools_dependent_process'
        ),
        '#dependency' => array(
          'radio:settings[front][frontpage]' => array(
            'bio'
          )
        ),
        '#weight' => 2,
      );
    }
    
    // Do they want to Select A Post
    $auto_element = vsite_node_autocomplete_element("Select a post");
    $auto_element['#description'] = t('Select the post your want to set as a front page or create a new one') . $links;
    $auto_element['#process'] = array(
      'ctools_dependent_process'
    );
    $auto_element['#dependency'] = array(
      'radio:settings[front][frontpage]' => array(
        'html'
      )
    );
    $auto_element['#weight'] = 2;
    
    
    $def_node = intval($value['front_nid']) ? node_load($value['front_nid']) : false;
    if ($def_node)
      $auto_element['#default_value'] = $def_node->title . " [nid:{$value['front_nid']}]";

    $form['front_nid'] = $auto_element;

    $options = vsite_content_types();
    drupal_alter('vsite_content_types', $options);
    $default_value = $value['node_options'] ? array_keys(array_filter($value['node_options'])) : array_keys($options);

    $form['node_options'] = array(
      '#prefix' => '<div id="edit-settings-front-node-options-wrapper">',  // needed by ctools
      '#suffix' => '</div>',
      '#type' => 'checkboxes',
      '#title' => t('Select features / content types'),
      '#options' => $options,
      '#default_value' => $default_value,
      '#description' => t("Select the features that you would like to provide content for your home page."),
      '#process' => array(
        'expand_checkboxes',
        'ctools_dependent_process'
      ),
      '#dependency' => array(
        'radio:settings[front][frontpage]' => array(
          'feature'
        )
      ),
      '#weight' => 2,
    );

    return $form;
  }

  function validate($vsite, $value){
    switch ($value['frontpage']) {
      case 'bio' :
        $bio_node = content_profile_load("bio", $vsite->group->uid);
        //$bio_nid = (isset($vsite -> settings['bio']['nid']) && is_numeric($vsite -> settings['bio']['nid'])) ? $vsite -> settings['bio']['nid'] : '';
        if (! $bio_node)
          form_set_error('frontpage', "You must create a bio before you can select this option");
        break;
      case 'feature' :
        $exists = false;
        foreach ( $value['node_options'] as $opt )
          if ($opt)
            $exists = true;
        if (! $exists)
          form_set_error('frontpage', "You must select at least one feature.");
        break;
      case 'html' :
        if (! $value['front_nid']) {
          form_set_error('frontpage', "You must select a post to display.");
        }
        break;
      case 'flag' :
      default :
      //do nothing
    }
    return $value;

  }

  function submit($vsite, $value){
    $save = array(
      'frontpage' => $value['frontpage']
    );
    switch ($value['frontpage']) {
      case 'bio' :
        $save['bio_title'] = $value['bio_title'];
        break;
      case 'feature' :
        $save['node_options'] = $value['node_options'];
        break;
      case 'html' :
        //$matches=array();
        //preg_match("/\[nid:\d+\]/",$value['front_nid'],$matches);
        //$save['front_nid'] = substr($matches[0],5,-1);
        $save['front_nid'] = _vsite_node_autocomplete_title_to_nid($value['front_nid']);
        break;
      case 'flag' :
        //nothing extra to save
        break;
    }
    return $save;
  }
}

