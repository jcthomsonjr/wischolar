<?php 
/**
 * Customizer for feature menus.
 */
class scholar_feature_settings_customizer_biblio_rows implements space_customizer {

  public static $name = 'Rows per page';

  function form($space, $feature) {
    /**
     * @todo change to scholar_publication
     */
    //$publication = spaces_features_items('scholar_publication', $feature);
    $publication = spaces_features_items('node', 'scholar_links');
    if (!empty($publication)) {
      $n_rows = variable_get('biblio_rowsperpage',25);
      $this->customize($space, $n_rows);
      
      $form = array();
      
      $form['scholar_biblio_rows'] = array(
        '#type' => 'fieldset',
        '#tree' => TRUE,
      );
   
		  $form['scholar_biblio_rows']['biblio_rowsperpage'] = array(
		  '#type' => 'textfield',
		  '#title' => t('Rows per page'),
		    '#size' => 5,
		  '#default_value' => $n_rows,
		  '#description' => t('Select the number of publication for each page (in multiple page view)'),
		  );

    }
    return $form;
  }

  function validate($space, $feature, $value) {
    return;
  }

  function submit($space, $feature, $value) {
    $customizer = $space->customizer['scholar_biblio_rows'];
    
    if(is_array($value['scholar_biblio_rows'])){
      $n_rows = intval(array_shift($value['scholar_biblio_style']));
      $customizer = ($n_rows > 0)?$n_rows:null;
    }
    
    return $customizer;
  }

  function customize($space, &$n_rows = NULL) {
    if (is_array($space->customizer) && array_key_exists('scholar_biblio_rows',$space->customizer)){
      $n_rows = $space->customizer['scholar_biblio_rows'];
    }
  }
}
