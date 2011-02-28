<?php

/**
 * Override or insert variables into the page templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function openscholar_theme_preprocess_page(&$vars, $hook) {

  $vars['footer_message'] = t("&copy; President & Fellows Harvard University. IQSS, 1737 Cambridge Street, Cambridge, MA, 02138 p: (617) 496-2450");
}