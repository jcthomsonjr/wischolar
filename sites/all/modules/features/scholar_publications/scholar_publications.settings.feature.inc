<?php 
/**
 * Provides theme selection for each site
 */
class scholar_publications_settings_feature implements space_setting {
  
  //Remove From Menu
  public $menu_name = false;
  
  var $id;
  function __construct($id = NULL) {
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'scholar_publications';
    }
  }

  function form($space, $value = array()) {
    
  	if(!is_array($value)) $value = array();
    include_once drupal_get_path('module', 'biblio') .'/biblio.admin.inc';
    
    $s_style = biblio_get_style();
    $form['style'] = array(
      '#type' => 'radios',
      '#title' => t('Select Style'),
      '#default_value' => !array_key_exists('style',$value)?$s_style:$value['style'],
      '#options' => _biblio_admin_get_styles(),
      '#description' => t('This alters the layout of the "list" (short) view.'),
    );

    $form['export_links'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Show export links'),
      '#default_value' => !array_key_exists('export_links',$value)?variable_get('biblio_export_links', array('tagged', 'xml', 'bibtex')):$value['export_links'],
      '#options' => array(
        'tagged'  => t('EndNote Tagged'),
        'xml'     => t('EndNote XML'),
        'bibtex'  => t('BibTex'),
      ),
      '#description' => t('You can select which export links to display here.')
    );
      
    $form['google_link'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show Google Scholar links'),
      '#return_value' => 1,
      '#default_value' => !array_key_exists('google_link',$value)?variable_get('biblio_google_link', 1):$value['google_link'],
      '#description' => t('Selecting this option will display a link to Google Scholar beside each entry.  Clicking this link searches Google Scholar using the title and first author of the current biblio entry.')
    );
    
    $form['links_target_new_window'] = array(
      '#type' => 'checkbox',
      '#title' => t('Links open in new browser'),
      '#return_value' => 1,
      '#default_value' => !array_key_exists('links_target_new_window',$value)?variable_get('biblio_links_target_new_window', 0):$value['links_target_new_window'],
      '#description' => t('This causes related URLs to open in a new browser window')
    );
      
    $form['inlinemode_in_links'] = array(
        '#type' => 'checkbox',
        '#title' => t('Carry "inline" mode through to all links'),
        '#return_value' => 1,
        '#default_value' => !array_key_exists('inlinemode_in_links',$value)?variable_get('biblio_inlinemode_in_links', 0):$value['inlinemode_in_links'],
        '#description' => t('This causes the "inline" mode to be applied to all links such as titles, authors and keywords')
    );
    
    $form['link_title_url'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hyperlink titles using supplied URL if available'),
      '#return_value' => 1,
      '#default_value' => !array_key_exists('link_title_url',$value)?variable_get('biblio_link_title_url', 0):$value['link_title_url'],
      '#description' => t('Selecting this links the titles to the supplied URL (if available) rather than the "node" view.')
    );
    
    $form['author_links'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hyperlink author names'),
      '#return_value' => 1,
      '#default_value' => !array_key_exists('author_links',$value)?variable_get('biblio_author_links', 1):$value['author_links'],
      '#description' => t('This creates a hyperlink on author names which, when clicked, will select entries which contain that author')
    );
   
    $form['rowsperpage'] = array(
      '#type' => 'textfield',
      '#title' => t('Rows per page'),
      '#size' => 5,
      '#default_value' => array_key_exists('rowsperpage',$value)?variable_get('biblio_rowsperpage',25):$value['rowsperpage'],
      '#description' => t('Select the number of publication for each page (in multiple page view)'),
    );
      
    $form['sort'] = array(
      '#type' => 'radios',
      '#title' => t('Sort by'),
      '#default_value' => !array_key_exists('sort',$value)?variable_get('biblio_sort','year'):$value['sort'],
      '#options' => array('author' => t('Author'), 'keyword' => t('Keyword'), 'title' => t('Title'), 'type' => t('Type'), 'year' => t('Year')),
    );
    $form['sort_tabs'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Show sort links'),
      '#default_value' => !array_key_exists('sort_tabs',$value)?variable_get('biblio_sort_tabs', array('author'=>'author', 'title'=>'title', 'type'=>'type', 'year'=>'year', 'keyword'=>'keyword')):$value['sort_tabs'],
      '#options' => array('author' => t('Author'), 'keyword' => t('Keyword'), 'title' => t('Title'), 'type' => t('Type'), 'year' => t('Year')),
      '#description' => t('You turn the sorting links at the top of the /biblio page here.'),
    );
    $form['order'] = array(
      '#type' => 'radios',
      '#title' => t('Order'),
      '#default_value' => !array_key_exists('order',$value)?variable_get('biblio_order', 'DESC'):$value['order'],
      '#options' => array('DESC' => t('Descending'), 'ASC' => t('Ascending')),
    );
    
    $form['bkn_enabled'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable Contributor Lookup'),
      '#default_value' => !array_key_exists('bkn_enabled',$value)?(variable_get('bkn_contrib_lookup_mode', 1) < 2):$value['bkn_enabled'],
      '#return_value' => 1,
      '#description' => t('Uncheck to disable all external lookups?')
    );
    $form['bkn_contrib_lookup_allow_autocomplete'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable Autocomplete'),
      '#default_value' => !array_key_exists('bkn_contrib_lookup_allow_autocomplete',$value)?variable_get('bkn_contrib_lookup_allow_autocomplete',1):$value['bkn_contrib_lookup_allow_autocomplete'],
      '#return_value' => 1,
      '#description' => t('Should contributor field use autocomplete?')
    );
    
    return $form;
  }

  function validate($space, $value) {
    // autocomplete has its own validation
  }

  function submit($space, $value) {
    
    return $value;
  }
  
  public static function customize($space, $s_key, &$var = NULL) {
    if (is_array($space->settings) && array_key_exists('scholar_publications',$space->settings) && array_key_exists($s_key,$space->settings['scholar_publications'])){
      $var = $space->settings['scholar_publications'][$s_key];
    }
  }
}