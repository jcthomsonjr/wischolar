<?php 
/**
 * Customizer for feature menus.
 */
class scholar_feature_settings_customizer_biblio_links implements space_customizer {

  var $name = 'Links';

  function form($space, $feature) {
    /**
     * @todo change to scholar_publication
     */
    //$publication = spaces_features_items('scholar_publication', $feature);
    $publication = spaces_features_items('node', 'scholar_links');
    if (!empty($publication)) {
      $form = array();
      include_once drupal_get_path('module', 'biblio') .'/biblio.admin.inc';
      
      $a_export_links = variable_get('biblio_export_links', array('tagged', 'xml', 'bibtex'));
      $this->customize($space,'export_biblio_export_links', $a_export_links);
      
      $b_google_link = variable_get('biblio_google_link', 1);
      $this->customize($space,'google_biblio_google_link', $b_google_link);
      
      $b_target_new_window = variable_get('biblio_links_target_new_window', 0);
      $this->customize($space,'biblio_links_target_new_window', $b_target_new_window);
      
      $b_inline_mode_in_links = variable_get('biblio_inlinemode_in_links', 0);
      $this->customize($space,'biblio_inlinemode_in_links', $b_inline_mode_in_links);
      
      $b_link_title_url = variable_get('biblio_link_title_url', 0);
      $this->customize($space,'biblio_link_title_url', $b_link_title_url);
      
      $b_author_links = variable_get('biblio_author_links', 1);
      $this->customize($space,'biblio_author_links', $b_author_links);
      
      
      $form['scholar_biblio_links'] = array(
		    '#type' => 'fieldset',
		    '#collapsible' => TRUE,
		    '#collapsed' => TRUE,
        '#tree' => TRUE,
		  );
		  $form['scholar_biblio_links']['export'] = array(
		    '#type' => 'fieldset',
		    '#collapsible' => TRUE,
		    '#collapsed' => FALSE,
		    '#title' => t('Export Links')
		  );
		  $form['scholar_biblio_links']['export']['biblio_export_links'] = array(
		    '#type' => 'checkboxes',
		    '#title' => t('Show export links'),
		    '#default_value' => $a_export_links,
		    '#options' => array(
		      'tagged'  => t('EndNote Tagged'),
		      'xml'     => t('EndNote XML'),
		      'bibtex'  => t('BibTex'),
		    ),
		    '#description' => t('You can select which export links to display here.')
		  );
		  $form['scholar_biblio_links']['google'] = array(
		    '#type' => 'fieldset',
		    '#collapsible' => TRUE,
		    '#collapsed' => FALSE,
		    '#title' => t('Google Scholar Link')
		  );
		  $form['scholar_biblio_links']['google']['biblio_google_link'] = array(
		    '#type' => 'checkbox',
		    '#title' => t('Show Google Scholar links'),
		    '#return_value' => 1,
		    '#default_value' => $b_google_link,
		    '#description' => t('Selecting this option will display a link to Google Scholar beside each entry.  Clicking this link searches Google Scholar using the title and first author of the current biblio entry.')
		  );
		
		  $form['scholar_biblio_links']['biblio_links_target_new_window'] = array(
		    '#type' => 'checkbox',
		    '#title' => t('Links open in new browser'),
		    '#return_value' => 1,
		    '#default_value' => $b_target_new_window,
		    '#description' => t('This causes related URLs to open in a new browser window')
		  );
		  $form['scholar_biblio_links']['biblio_inlinemode_in_links'] = array(
		      '#type' => 'checkbox',
		      '#title' => t('Carry "inline" mode through to all links'),
		      '#return_value' => 1,
		      '#default_value' => $b_inline_mode_in_links,
		      '#description' => t('This causes the "inline" mode to be applied to all links such as titles, authors and keywords')
		  );
		
		  $form['scholar_biblio_links']['biblio_link_title_url'] = array(
		    '#type' => 'checkbox',
		    '#title' => t('Hyperlink titles using supplied URL if available'),
		    '#return_value' => 1,
		    '#default_value' => $b_link_title_url,
		    '#description' => t('Selecting this links the titles to the supplied URL (if available) rather than the "node" view.')
		  );
		  $form['scholar_biblio_links']['biblio_author_links'] = array(
		    '#type' => 'checkbox',
		    '#title' => t('Hyperlink author names'),
		    '#return_value' => 1,
		    '#default_value' => $b_author_links,
		    '#description' => t('This creates a hyperlink on author names which, when clicked, will select entries which contain that author')
		  );

    }
    return $form;
  }

  function validate($space, $feature, $value) {
    return;
  }

  function submit($space, $feature, $value) {
    $customizer = $space->customizer['scholar_biblio_links'];
    if(!is_array($customizer)) $customizer = array();
    
    if(is_array($value['scholar_biblio_links'])){
      foreach ($value['scholar_biblio_links'] as $k => $v) {
      	if(in_array($k,array('google','export'))){
      		foreach ($v as $k2 => $v2) $customizer["{$k}_{$k2}"] = $v2;
      	}else{
      		$customizer[$k] = $v;
      	}
      }
    }
    
    return $customizer;
  }

  function customize($space, $var, &$s_setting = NULL) {
    if ($space->customizer['scholar_biblio_links'] && array_key_exists($var,$space->customizer['scholar_biblio_links'])){
      $s_setting = $space->customizer['scholar_biblio_links'][$var];
    }
  }
}
