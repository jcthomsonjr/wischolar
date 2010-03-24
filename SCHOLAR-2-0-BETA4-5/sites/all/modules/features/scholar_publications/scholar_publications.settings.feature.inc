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

    $form['no_publication_date'] = array(
      '#type' => 'textfield',
      '#title' => t('Unpublished Label'),
      '#default_value' => !array_key_exists('no_publication_date',$value)?variable_get('biblio_no_year_text', t('Submitted')):$value['no_publication_date'],
      '#description' => t('This label will show if you do not enter a publication date.'),
    );

    $form['style'] = array(
      '#type' => 'radios',
      '#title' => t('Select your preferred bibliographic format'),
      //'#description' => t('This alters the bibliographic format of your publications.'),
      '#default_value' => !array_key_exists('style',$value)?$s_style:$value['style'],
      '#options' => _biblio_admin_get_styles(),
    );

    $form['export_links'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Select which export formats should accompany each bibliographic record'),
      '#default_value' => !array_key_exists('export_links',$value)?variable_get('biblio_export_links', array('tagged', 'xml', 'bibtex')):$value['export_links'],
      '#options' => array(
        'tagged'  => t('EndNote Tagged'),
        'xml'     => t('EndNote XML'),
        'bibtex'  => t('BibTex'),
      ),
      '#description' => t('Each selected format will appear in its own export link.'),
    );

    $form['google_link'] = array(
      '#type' => 'checkbox',
      '#title' => t('Link to Google Scholar'),
      '#return_value' => 1,
      '#default_value' => !array_key_exists('google_link',$value)?variable_get('biblio_google_link', 1):$value['google_link'],
      '#description' => t('This adds the necessary metadata to your web site to allow Google Scholar to properly index your publication.'),
    );

    /*
    $form['links_target_new_window'] = array(
      '#type' => 'checkbox',
      '#title' => t('Open links in new browser'),
      '#return_value' => 1,
      '#default_value' => !array_key_exists('links_target_new_window',$value)?variable_get('biblio_links_target_new_window', 0):$value['links_target_new_window'],
      '#description' => t('Links in your publication entry would be opened in a new browser window ')
    );


    $form['inlinemode_in_links'] = array(
        '#type' => 'checkbox',
        '#title' => t('Carry "inline" mode through to all links'),
        '#return_value' => 1,
        '#default_value' => !array_key_exists('inlinemode_in_links',$value)?variable_get('biblio_inlinemode_in_links', 0):$value['inlinemode_in_links'],
        '#description' => t('This allows an "inline" mode to be applied to all links such as titles, authors and keywords')
    );
        */

//    $form['link_title_url'] = array(
//      '#type' => 'checkbox',
//      '#title' => t('Create hyperlinks to external URLs (if they are available)'),
//      '#return_value' => 1,
//      '#default_value' => !array_key_exists('link_title_url',$value)?variable_get('biblio_link_title_url', 0):$value['link_title_url'],
//      '#description' => t('If an off-site URL is available, users clicking on the title of the publication would be directed to the off-site URL. This could be useful if the complete work is available online.'),
//    );

//    $form['author_links'] = array(
//      '#type' => 'checkbox',
//      '#title' => t('Create hyperlinks to authors'),
//      '#return_value' => 1,
//      '#default_value' => !array_key_exists('author_links',$value)?variable_get('biblio_author_links', 1):$value['author_links'],
//      '#description' => t('Creates a hyperlink on each author name which, when clicked, selects all entries which contain that author'),
//    );

    $form['rowsperpage'] = array(
      '#type' => 'textfield',
      '#title' => t('Publications per page'),
      '#size' => 5,
      '#default_value' => !array_key_exists('rowsperpage',$value)?variable_get('biblio_rowsperpage',25):$value['rowsperpage'],
      '#description' => t('Select the number of publication to be displayed on each page.'),
    );

    $form['sort'] = array(
      '#type' => 'radios',
      '#title' => t('By default, sort publications by which category'),
      '#default_value' => !array_key_exists('sort',$value)?variable_get('biblio_sort','year'):$value['sort'],
      '#options' => array('author' => t('Author'), 'keyword' => t('Keyword'), 'title' => t('Title'), 'type' => t('Type'), 'year' => t('Year')),
    );
      $form['order'] = array(
      '#type' => 'radios',
      '#title' => t('Select default order of the sort category'),
      '#default_value' => !array_key_exists('order',$value)?variable_get('biblio_order', 'DESC'):$value['order'],
      '#options' => array('DESC' => t('Descending'), 'ASC' => t('Ascending')),
      
    );

    $form['sort_tabs'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Allow additional sorting of your publications by'),
      '#default_value' => !array_key_exists('sort_tabs',$value)?variable_get('biblio_sort_tabs', array('author'=>'author', 'title'=>'title', 'type'=>'type', 'year'=>'year', 'keyword'=>'keyword')):$value['sort_tabs'],
      '#options' => array('author' => t('Author'), 'keyword' => t('Keyword'), 'title' => t('Title'), 'type' => t('Type'), 'year' => t('Year')),
      //'#description' => t('You turn the sorting links at the top of the /biblio page here.'),
    );

    $form['bkn'] = array(
     '#type' => 'item',
    '#title' =>t('Author Lookup Services'),
    );

    $form['bkn_enabled'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable co-author auto-search'),
      '#default_value' => !array_key_exists('bkn_enabled',$value)?(variable_get('bkn_contrib_lookup_mode', 1) < 2):$value['bkn_enabled'],
      '#return_value' => 1,
      '#description' => t('This searches Berkley\'s Database for matching names'),
     );
    $form['bkn_contrib_lookup_allow_autocomplete'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable autocomplete on author fields'),
      '#default_value' => !array_key_exists('bkn_contrib_lookup_allow_autocomplete',$value)?variable_get('bkn_contrib_lookup_allow_autocomplete',1):$value['bkn_contrib_lookup_allow_autocomplete'],
      '#return_value' => 1,
      '#description' => t('When checked the search results are provided to you as you type')
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