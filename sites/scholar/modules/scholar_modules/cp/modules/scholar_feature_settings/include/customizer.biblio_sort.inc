<?php 
/**
 * Customizer for feature menus.
 */
class scholar_feature_settings_customizer_biblio_sort implements space_customizer {

  var $name = 'Sort';

  function form($space, $feature) {
    /**
     * @todo change to scholar_publication
     */
    //$publication = spaces_features_items('scholar_publication', $feature);
    $publication = spaces_features_items('node', 'scholar_links');
    if (!empty($publication)) {
      $s_sort = variable_get('biblio_sort','year');
      $this->customize($space, 'biblio_sort', $s_sort);
      $a_sort_tabs = variable_get('biblio_sort_tabs', array('author'=>'author', 'title'=>'title', 'type'=>'type', 'year'=>'year', 'keyword'=>'keyword'));
      $this->customize($space, 'biblio_sort_tabs', $a_sort_tabs);
      $s_order = variable_get('biblio_order', 'DESC');
      $this->customize($space, 'biblio_order', $s_order);
      
      $form = array();
      
      $form['scholar_biblio_sort'] = array(
        '#type' => 'fieldset',
        '#tree' => TRUE,
      );
      $form['scholar_biblio_sort']['biblio_sort'] = array(
        '#type' => 'radios',
        '#title' => t('Sort by'),
        '#default_value' => $s_sort,
        '#options' => array('author' => t('Author'), 'keyword' => t('Keyword'), 'title' => t('Title'), 'type' => t('Type'), 'year' => t('Year')),
      );
      $form['scholar_biblio_sort']['biblio_sort_tabs'] = array(
        '#type' => 'checkboxes',
        '#title' => t('Show sort links'),
        '#default_value' => $a_sort_tabs,
        '#options' => array('author' => t('Author'), 'keyword' => t('Keyword'), 'title' => t('Title'), 'type' => t('Type'), 'year' => t('Year')),
        '#description' => t('You turn the sorting links at the top of the /biblio page here.'),
      );
      $form['scholar_biblio_sort']['biblio_order'] = array(
        '#type' => 'radios',
        '#title' => t('Order'),
        '#default_value' => $s_order,
        '#options' => array('DESC' => t('Descending'), 'ASC' => t('Ascending')),
      );

    }
    return $form;
  }

  function validate($space, $feature, $value) {
    return;
  }

  function submit($space, $feature, $value) {
    $customizer = $space->customizer['scholar_biblio_sort'];
    if(!is_array($customizer)) $customizer = array();
    
    if(is_array($value['scholar_biblio_sort'])){
      foreach ($value['scholar_biblio_sort'] as $k => $v) {
        if(array_key_exists($k,$value['scholar_biblio_sort'])) $customizer[$k] = $v;
      }
    }
    
    return $customizer;
  }

  function customize($space, $var, &$s_setting = NULL) {
    if ($space->customizer['scholar_biblio_sort'] && array_key_exists($var,$space->customizer['scholar_biblio_sort'])){
      $s_setting = $space->customizer['scholar_biblio_sort'][$var];
    }
  }
}
