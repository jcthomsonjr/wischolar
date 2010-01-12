<?php
// $Id: pageroute.api.php,v 1.1.2.1 2009/12/23 12:18:28 sgilits Exp $
/**
 * @file
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 * It also contains documentation for creating own page types.
 */

/**
 * @defgroup pageroute hooks
 * Hook that can be implemented by other modules in order to extend rules.
 */

/**
 * Modify parameters or the pageroute it self.
 * 
 * This hook allows you to modify the parameters, the access to the pages or the pageroute it self. 
 * 
 * @param $route
 *   The pageroute object. You can modify the settings of the given pageroute. For example you can 
 *   restrict the access to a page from your Pageroute depending on the role the user has. To do so
 *   you have to set the pageAccess array to false with the pageid as key.
 *   
 * @param $user
 *   The user, currently using the pageroute.
 * 
 * @param $uid
 *   The user id used by the page.
 *   
 * @param $nid
 *   The node id used by the page.
 * 
 */
function pageroute_test_pageroute_view($route, $user, $uid, $nid) {
  if ($route->path == 'pageroute_test_route3' && !in_array('pageroute_access', $user->roles)) {
    $route->pageAccess["p1"] = FALSE;
    $route->pageAccess["p3"] = FALSE;
  }
}

/**
 * @defgroup Page types
 */

/**
 * Pageroute needs the following naming convetion to recognice your pagetype:
 * PageroutePage[name]
 * 
 * Further page types have to be in an own file which have the following naming convention:
 * [module].page_[name]
 * 
 * So for our sample page type the filename wourld have to be called:
 * testmodule.page_sample
 * 
 * Pageroute automaticly deletes undescores in module names, so following name would be acceptable:
 * test_module.page_sample
 * 
 * A page type needs to extend to the base class PageroutePage defined in pageroute.route.inc so you'll have 
 * to include this file.
 */
include_once(drupal_get_path('module', 'pageroute') . '/pageroute.route.inc');

/**
 * This is a sample page type
 * This class would be typical for a pageroute type.
 */
class PageroutePageSample extends PageroutePage {
  /**
   * Adds the form that displays the page to $form array.
   * 
   * @param $form The form which be displayed.
   * @param $form_state The current form_state
   * @param $args This array contains the uid and the nid, if it was set.
   */
  public function getForm(&$form, &$form_state, &$args);

  /**
   * Adds the configuration form for the page type to $form array.
   * 
   * @param $page The page that will be should be configured and that contains the options.
   * @param $form current form
   */
  public function getAdminForm($page, $form);

  /**
   * Provides a help text for the pageroute user interface.
   *  @return string t('Help text.')
   */
  public static function help();

  /**
   * Describes the page type.
   *  @return array array('name' => t('Human readable page type name'));
   */
  public static function info();


  public function getCancelTarget();

  /**
   * This function initializes the Page type. 
   * Here you can load stuff or include files needed for your page type.
   */
  public function setUp();

  /**
   * Returns the default submit handler from drupal for your specific content type.
   * 
   * @return string function name, for example: 'user_profile_form_submit';
   */
  public static function getDefaultSubmitHandler($form) { }

  /**
   * Returns the default validation handler from drupal.
   * 
   * @return string function name
   */
  public static function getDefaultValidateHandler($form) { }
}


/**
 * If you would like to know more about how creating your own page type, please take a look 
 * on the build-in classes in pageroute or the content profile pageroute integration. 
 */


