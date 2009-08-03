<?php 
/**
 * Customizer for feature menus.
 */
class scholar_feature_settings_customizer_bkn implements space_customizer {

  var $name = 'BKN Settings';

  function form($space, $feature) {
    /**
     * @todo change to scholar_publication
     */
    //$publication = spaces_features_items('scholar_publication', $feature);
    $publication = spaces_features_items('node', 'scholar_links');
    if (!empty($publication)) {
      $form = array();
      
      $b_autocomplete = variable_get('bkn_contrib_lookup_allow_autocomplete',1);
      $this->customize($space, 'bkn_contrib_lookup_allow_autocomplete', $b_autocomplete);
      $n_lookup_mode = variable_get('bkn_contrib_lookup_mode', 1);
      $this->customize($space, 'bkn_contrib_lookup_mode', $n_lookup_mode);
      
      $form['scholar_bkn'] = array(
            //'#title' => 'Style',
            '#type' => 'fieldset',
            '#tree' => TRUE,
      );
      $form['scholar_bkn']['bkn_contrib_lookup_allow_autocomplete'] = array(
        '#type' => 'checkbox',
        '#title' => t('Enable Autocomplete'),
        '#default_value' => $b_autocomplete,
        '#return_value' => 1,
        '#description' => t('Should contributor field use autocomplete?')
      );
      $form['scholar_bkn']['bkn_contrib_lookup_mode'] = array(
        '#type' => 'radios',
        '#title' => t('How should the data be retrieved from BKN?'),
        '#default_value' => $n_lookup_mode,
        '#options' => array(t('Lookup via autocomplete (many requests to bkn)'), t('User Initiated (single request)'), t('Disabled')),
      );

    }
    return $form;
  }

  function validate($space, $feature, $value) {
    return;
  }

  function submit($space, $feature, $value) {
    $customizer = $space->customizer['scholar_bkn'];
    if(!is_array($customizer)) $customizer = array();
    
    if(is_array($value['scholar_bkn'])){
      foreach ($value['scholar_bkn'] as $k => $v) {
      	if(array_key_exists($k,$value['scholar_bkn'])) $customizer[$k] = $v;
      }
    }
    
    return $customizer;
  }

  function customize($space, $var, &$s_setting = NULL) {
    if ($space->customizer['scholar_bkn'] && array_key_exists($var,$space->customizer['scholar_bkn'])){
      $s_setting = $space->customizer['scholar_bkn'][$var];
    }
  }
  
}
