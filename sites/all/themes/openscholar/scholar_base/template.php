<?php

/**
 * Implements HOOK_theme().
 */
function scholar_base_theme(&$existing, $type, $theme, $path) {
  // When #341140 is fixed, replace _scholar_base_path() with drupal_get_path().
  include_once './' . _scholar_base_path() . '/includes/template.theme-registry.inc';
  return _scholar_base_theme($existing, $type, $theme, $path);
}

/**
 * Duplicate of theme_menu_local_tasks() but adds clearfix to tabs.
 */
function scholar_base_menu_local_tasks() {
  $output = '';

  // CTools requires a different set of local task functions.
  if (module_exists('ctools')) {
    ctools_include('menu');
    $primary = ctools_menu_primary_local_tasks();
    $secondary = ctools_menu_secondary_local_tasks();
  }
  else {
    $primary = menu_primary_local_tasks();
    $secondary = menu_secondary_local_tasks();
  }

  if ($primary) {
    $output .= '<ul class="tabs primary clearfix">' . $primary . '</ul>';
  }
  if ($secondary) {
    $output .= '<ul class="tabs secondary clearfix">' . $secondary . '</ul>';
  }

  return $output;
}


/**
 * Override or insert variables into templates before other preprocess functions have run.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered.
 */
function scholar_base_preprocess(&$vars, $hook) {
  // In D6, the page.tpl uses a different variable name to hold the classes.
  $key = ($hook == 'page' || $hook == 'maintenance_page') ? 'body_classes' : 'classes';

  // Create a D7-standard classes_array variable.
  if (array_key_exists($key, $vars)) {
    // Views (and possibly other modules) have templates with a $classes
    // variable that isn't a string, so we leave those variables alone.
    if (is_string($vars[$key])) {
      $vars['classes_array'] = explode(' ', $vars[$key]);
      unset($vars[$key]);
    }
  }
  else {
    $vars['classes_array'] = array($hook);
  }
}

/**
 * Override or insert variables into the page templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function scholar_base_preprocess_page(&$vars, $hook) {

  // Classes for body element. Allows advanced theming based on context
  // (home page, node of certain type, etc.)
  // Remove the mostly useless page-ARG0 class.
  if ($index = array_search(preg_replace('![^abcdefghijklmnopqrstuvwxyz0-9-_]+!s', '', 'page-'. drupal_strtolower(arg(0))), $vars['classes_array'])) {
    unset($vars['classes_array'][$index]);
  }
  if (!$vars['is_front']) {
    // Add unique class for each page.
    $path = drupal_get_path_alias($_GET['q']);
    //The following is for drupal 7
    $vars['classes_array'][] = drupal_html_class('page-' . $path);
    // Add unique class for each website section.
    list($section, ) = explode('/', $path, 2);
    if (arg(0) == 'node') {
      if (arg(1) == 'add') {
        $section = 'node-add';
      }
      elseif (is_numeric(arg(1)) && (arg(2) == 'edit' || arg(2) == 'delete')) {
        $section = 'node-' . arg(2);
      }
    }
    $vars['classes_array'][] = drupal_html_class('section-' . $section);
  }

  // We need to re-do the $layout and body classes because
  // template_preprocess_page() assumes sidebars are named 'left' and 'right'.
  $vars['layout'] = 'none';
  if (!empty($vars['left'])) {
    $vars['layout'] = 'sidebar-left';
  }
  if (!empty($vars['right'])) {
    $vars['layout'] = ($vars['layout'] == 'right') ? 'both' : 'sidebar-right';
  }
  // If the layout is 'none', then template_preprocess_page() will already have
  // set a 'no-sidebars' class since it won't find a 'left' or 'right' sidebar.
  if ($vars['layout'] != 'none') {
    // Remove the incorrect 'no-sidebars' class.
    if ($index = array_search('no-sidebars', $vars['classes_array'])) {
      unset($vars['classes_array'][$index]);
    }
    // Set the proper layout body classes.
    if ($vars['layout'] == 'both') {
      $vars['classes_array'][] = 'two-sidebars';
    }
    else {
      $vars['classes_array'][] = 'one-sidebar';
      $vars['classes_array'][] = 'sidebar-' . $vars['layout'];
    }
  }

  //Adds OpenScholar header region awareness to body classes

  $regions = array (   // TODO do this programatically
    'left' => $vars['header_left'],
    'main' => $vars['header_main'],
    'right' => $vars['header_right'],
  );

  $non_empty_regions = array_filter($regions, "__scholar_base_is_empty");
  $header_classes = 'header-';
  if (count($non_empty_regions)) {
    $header_classes .= implode('-', array_keys($non_empty_regions));
   }
  else {
    $header_classes .= 'none';
  }
  $vars['classes_array'][] = $header_classes;

  // Store the menu item since it has some useful information.
  $vars['menu_item'] = menu_get_item();
  switch ($vars['menu_item']['page_callback']) {
    case 'views_page':
      // Is this a Views page?
      $vars['classes_array'][] = 'page-views';
      break;
  }
}

function __scholar_base_is_empty($s){
  return $s ? TRUE : FALSE;
}

/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
function scholar_base_preprocess_maintenance_page(&$vars, $hook) {

  // Classes for body element. Allows advanced theming based on context
  // (home page, node of certain type, etc.)
  $vars['body_classes_array'] = explode(' ', $vars['body_classes']);
}

/**
 * Override or insert variables into the node templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function scholar_base_preprocess_node(&$vars, $hook) {
  // Create the build_mode variable.
  switch ($vars['node']->build_mode) {
    case NODE_BUILD_NORMAL:
      $vars['build_mode'] = $vars['teaser'] ? 'teaser' : 'full';
      break;
    case NODE_BUILD_PREVIEW:
      $vars['build_mode'] = 'preview';
      break;
    case NODE_BUILD_SEARCH_INDEX:
      $vars['build_mode'] = 'search_index';
      break;
    case NODE_BUILD_SEARCH_RESULT:
      $vars['build_mode'] = 'search_result';
      break;
    case NODE_BUILD_RSS:
      $vars['build_mode'] = 'rss';
      break;
    case NODE_BUILD_PRINT:
      $vars['build_mode'] = 'print';
      break;
  }

  // Create the Drupal 7 $display_submitted variable.
  $vars['display_submitted'] = theme_get_setting('toggle_node_info_' . $vars['node']->type);

  // Special classes for nodes.
  // Class for node type: "node-type-page", "node-type-story", "node-type-my-custom-type", etc.
  $vars['classes_array'][] = drupal_html_class('node-type-' . $vars['type']);
  if ($vars['promote']) {
    $vars['classes_array'][] = 'node-promoted';
  }
  if ($vars['sticky']) {
    $vars['classes_array'][] = 'node-sticky';
  }
  if (!$vars['status']) {
    $vars['classes_array'][] = 'node-unpublished';
    $vars['unpublished'] = TRUE;
  }
  else {
    $vars['unpublished'] = FALSE;
  }
  if ($vars['uid'] && $vars['uid'] == $GLOBALS['user']->uid) {
    $vars['classes_array'][] = 'node-by-viewer'; // Node is authored by current user.
  }
  if ($vars['teaser']) {
    $vars['classes_array'][] = 'node-teaser'; // Node is displayed as teaser.
  }
  if (isset($vars['preview'])) {
    $vars['classes_array'][] = 'node-preview';
  }
}


/**
 * Override or insert variables into the block templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
function scholar_base_preprocess_block(&$vars, $hook) {
  $block = $vars['block'];

  // Drupal 7 uses a $content variable instead of $block->content.
  $vars['content'] = $block->content;
  // Drupal 7 should use a $title variable instead of $block->subject.
  $vars['title'] = $block->subject;

  // Special classes for blocks.
  $vars['classes_array'][] = 'block-' . $block->module;
  $vars['classes_array'][] = 'region-' . $vars['block_zebra'];
  $vars['classes_array'][] = $vars['zebra'];
  $vars['classes_array'][] = 'region-count-' . $vars['block_id'];
  $vars['classes_array'][] = 'count-' . $vars['id'];

  // Create the block ID.
  $vars['block_html_id'] = 'block-' . $block->module . '-' . $block->delta;

  $vars['edit_links_array'] = array();
}


/**
 * Override or insert variables into templates after preprocess functions have run.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered.
 */
function scholar_base_process(&$vars, $hook) {
  // Don't clobber Views 3 classes.
  if (array_key_exists('classes_array', $vars) && !array_key_exists('classes', $vars)) {
    $vars['classes'] = implode(' ', $vars['classes_array']);
  }
}


if (!function_exists('drupal_html_class')) {
  /**
   * Prepare a string for use as a valid class name.
   * See http://www.w3.org/TR/CSS21/syndata.html#characters
   * and http://www.w3.org/TR/html4/types.html
   * Do not pass one string containing multiple classes as they will be
   * incorrectly concatenated with dashes, i.e. "one two" will become "one-two".
   *
   * @param $class
   *   The class name to clean.
   * @return
   *   The cleaned class name.
   */
  function drupal_html_class($class) {
    // By default, we filter using Drupal's coding standards.
    $class = strtr(drupal_strtolower($class), array(' ' => '-', '_' => '-', '/' => '-', '[' => '-', ']' => ''));

    // We strip out any non-valid character
    $class = preg_replace('/[^\x{002D}\x{0030}-\x{0039}\x{0041}-\x{005A}\x{005F}\x{0061}-\x{007A}\x{00A1}-\x{FFFF}]/u', '', $class);

    return $class;
  }
} /* End of drupal_html_class conditional definition. */

if (!function_exists('drupal_html_id')) {
  /**
   * Prepare a string for use as a valid HTML ID and guarantee uniqueness.
   *
   * @param $id
   *   The ID to clean.
   * @return
   *   The cleaned ID.
   */
  function drupal_html_id($id) {
    $id = strtr(drupal_strtolower($id), array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
    // Only contain letters, digits ([0-9]), hyphens ("-"), underscores ("_"),
    // colons (":"), and periods ("."). Others are stripped out.
    $id = preg_replace('/[^A-Za-z0-9\-_]/', '', $id);

    return $id;
  }
}

/**
 * Generates a themed set of links for node types associated with
 * the current active contexts.
 */
function scholar_base_context_links($links) {
  $output = array();
  foreach ($links as $link) {
    $options = $link;
    $options['attributes']['class'] = isset($link['attributes']['class']) ? $link['attributes']['class'] : 'context-button';
    //if(!is_array($options['query'])) $options['query'] = array();
    //$options['query']['destination'] = $_GET['q'];

    if (!empty($link['custom'])) {
      $output[]= l($link['title'], $link['href'], $options);
    }
    else {
      $output[]= l(t('Add !type', array('!type' => $link['title'])), $link['href'], $options);
    }
  }

  if($output){
    $output = theme('item_list', $output,  $title = NULL, $type = 'ul', $attributes = array("class" => "context-links"));
    //$output = '<div class = "context-links">' . $output . '</div>';
  }
  return $output;
}

/**
 * Returns the path to the scholar_base theme.
 *
 * drupal_get_filename() is broken; see #341140. When that is fixed in Drupal 6,
 * replace _scholar_base_path() with drupal_get_path('theme', 'scholar_base').
 */

function _scholar_base_path() {
  static $path = FALSE;
  if (!$path) {
    $matches = drupal_system_listing('scholar_base\.info$', 'themes', 'name', 0);
    if (!empty($matches['scholar_base']->filename)) {
      $path = dirname($matches['scholar_base']->filename);
    }
  }
  return $path;
}

function scholar_base_node_submitted($node){
  return t('@datetime',
   array(
    //'!username' => theme('username', $node),
     '@datetime' => format_date($node->created),
  ));
}