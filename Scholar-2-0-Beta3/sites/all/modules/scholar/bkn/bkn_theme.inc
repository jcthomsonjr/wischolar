<?php

module_load_include('inc','bkn');

/**
 * @param $form
 * @return unknown_type
 */
function theme_bkn_contributors($form) {
  $rows = array();
  if ($form['#hideRole']) $headers = array('', t('Name'));
  else $headers = array('', t('Name'), t('Role'));
  //drupal_add_tabledrag($form['#id'], 'order', 'sibling', 'rank');

  foreach (element_children($form) as $key) {
    // No need to print the field title every time.
    unset ($form[$key]['name']['#title'], $form[$key]['auth_type']['#title']);
    // Add class to group weight fields for drag and drop.
    //$form[$key]['rank']['#attributes']['class'] = 'rank';

    // Build the table row.
    $row = array('');
    $row[] = array('data' => drupal_render($form[$key]['name']).
                             drupal_render($form[$key]['check_bkn']),
              		 'class' => 'biblio-contributor');
    if (!$form['#hideRole']) {
      $row[] = array('data' => drupal_render($form[$key]['auth_type']),
      							 'class' => 'biblio-contributor-type');
    }
    //$row[] = drupal_render($form[$key]['rank']);
    $rows[] = array('data' => $row);
  }
  $output = theme('table', $headers, $rows, array('id' => $form['#id']));
  $output .= drupal_render($form);
  return $output;
}

