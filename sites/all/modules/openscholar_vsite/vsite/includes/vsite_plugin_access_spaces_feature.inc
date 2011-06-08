<?php

/**
 * Provides access control for views by checking against the current space's
 * feature settings. Optionally allows a permission to be checked in addition
 * to the first feature access control check.
 *
 * This access plugin delegates access control first to spaces_feature_access()
 * which will check whether the user can first access content, then the active
 * space type's 'feature_access' method will be called.  If implementing your
 * own space type you have the ability to define your own access control.  See
 * 'space_og' class in Spaces OG module for an example implementation.
 */
class vsite_plugin_access_spaces_feature extends spaces_plugin_access_spaces_feature {
  /**
   * Check access directly.
   */
  function access($account) {
    $feature = $this->options['spaces_feature'] == 0 ? $this->get_my_feature() : $this->options['spaces_feature'];
    if (!empty($this->options['perm'])) {
      return vsite_access_feature('view', $feature, NULL, NULL, array($this->options['perm']));
    }
    return vsite_access_feature('view', $feature, NULL);
  }

  /**
   * Provide the access check as a callback.
   */
  function get_access_callback() {
    $feature = $this->options['spaces_feature'] == 0 ? $this->get_my_feature() : $this->options['spaces_feature'];
    if (!empty($this->options['perm'])) {
      return array('vsite_access_feature', array('view', $feature, NULL, NULL, array($this->options['perm'])));
    }
    return array('vsite_access_feature', array('view', $feature, NULL));
  }

  /**
   * Display for Views UI.
   */
  function summary_title() {
    $features = spaces_features();
    if (isset($features[$this->options['spaces_feature']])) {
      return t('Feature: @feature', array('@feature' => $features[$this->options['spaces_feature']]->info['name']));
    }
    return $options['spaces_feature'] == 0 ? t('Autodetect') : t('Broken');
  }
}
