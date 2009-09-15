<?php



/**
 * Form theming for the block customizer settings form.
 * 
 * Overridden to remove tabledrag and the weights from this customizer
 */
function cp_theme_spaces_block_customizer_settings_form($form) {
  // Add draggable weights
  drupal_add_js('misc/tableheader.js');
  drupal_add_css(drupal_get_path('module', 'spaces') .'/spaces.css');
  $output = '';

  $contexts = element_children($form['contexts']);
  foreach ($contexts as $identifier) {
    $output .= "<div class='spaces-block-customizer clear-block'>";

    // Add a context heading if there is more than 1 context in this feature
    if (count($contexts) > 1) {
      $output .= "<h3>{$form['contexts'][$identifier]['#title']}</h3>";
    }

    // List of block regions that should force an empty display
    $force_empty = array('content');
    global $theme_key;
    init_theme();
    $regions = system_region_list($theme_key);
    foreach ($force_empty as $region) {
      if (empty($form['contexts'][$identifier][$region]) && !empty($regions[$region])) {
        $output .= "<div class='region-{$region}'>";
        $output .= "<strong class='region'>{$regions[$region]}</strong>";
        $output .= "<div class='spaces-empty'>". t('There are no options available for this region.') ."</div>";
        $output .= "</div>";
      }
    }

    foreach (element_children($form['contexts'][$identifier]) as $a) {
      $rows = array();
      foreach (element_children($form['contexts'][$identifier][$a]) as $b) {
        $form['contexts'][$identifier][$a][$b]['weight']['#type'] = "hidden";
        $row = array(
          'status' => drupal_render($form['contexts'][$identifier][$a][$b]['status']),
          'title' => array('data' => drupal_render($form['contexts'][$identifier][$a][$b]['subject']).drupal_render($form['contexts'][$identifier][$a][$b]['weight']), 'class' => 'fill'),
        );
        $rows[] = array('data' => $row);
      }
      $output .= "<div class='region-{$a}'>";
      $output .= "<strong class='region'>{$form['contexts'][$identifier][$a]['#title']}</strong>";
      $output .= theme('table', array(), $rows, array('id' => "spaces-customizer-blocks-{$identifier}-{$a}"));
      $output .= "</div>";
    }

    $output .= "</div>";
  }

  $output .= drupal_render($form);
  return $output;
}

/**
 * Form theme function for customization items.
 * 
 * Overridden: So that they remain in fieldsets
 */
function cp_theme_spaces_customize_item($form) {
	$output = '';
  foreach (element_children($form) as $element) {
    if ($form[$element]['#type'] == 'fieldset') {
      $title = $form[$element]['#title'];
      unset($form[$element]['#title']);
      unset($form[$element]['#type']);
      $output .= "<div class='fieldset-wrapper'>".drupal_render($form[$element])."</div>";
    }
  }
  return $output;
}

/**
 * Change the link to users on the og memebers view
 * @param $view
 * @param $field
 * @param $row
 * @return unknown_type
 */
function cp_theme_views_view_field__og_members__name($view, $field, $row) {
	return ctools_modal_text_button(check_plain($row->{$field->field_alias}), 'cp/users/edit/'. $row->{$field->aliases['uid']} , 'edit '.$row->{$field->field_alias});
}
