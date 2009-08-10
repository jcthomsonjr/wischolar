<?php 
/**
 * Customizer for feature menus.
 */
class scholar_feature_settings_customizer_biblio_style implements space_customizer {

  var $name = 'Style';

  function form($space, $feature) {
    /**
     * @todo change to scholar_publication
     */
    //$publication = spaces_features_items('scholar_publication', $feature);
    $publication = spaces_features_items('node', 'scholar_links');
    if (!empty($publication)) {
      $form = array();
      include_once drupal_get_path('module', 'biblio') .'/biblio.admin.inc';
      
      $s_style = biblio_get_style();
      $this->customize($space, $s_style);
      $form['scholar_biblio_style'] = array(
            //'#title' => 'Style',
            '#type' => 'fieldset',
            '#tree' => TRUE,
      );
      $form['scholar_biblio_style'][] = array(
        '#type' => 'radios',
        '#title' => t('Select Style'),
        '#default_value' => $s_style,
        '#options' => _biblio_admin_get_styles(),
        '#description' => t('This alters the layout of the "list" (short) view.'),
      );

    }
    return $form;
  }

  function validate($space, $feature, $value) {
    return;
  }

  function submit($space, $feature, $value) {
    $customizer = $space->customizer['scholar_biblio_style'];
    
    $customizer = is_array($value['scholar_biblio_style'])?array_shift($value['scholar_biblio_style']):null;
    
    return $customizer;
  }

  function customize($space, &$s_style = NULL) {
    if (is_array($space->customizer) && array_key_exists('scholar_biblio_style',$space->customizer)){
      $s_style = $space->customizer['scholar_biblio_style'];
    }
  }
}
