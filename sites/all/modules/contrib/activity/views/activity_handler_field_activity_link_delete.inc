<?php
// $Id: activity_handler_field_activity_link_delete.inc,v 1.1.2.1 2009/08/25 18:34:42 sirkitree Exp $
/**
 * Field handler to present a link to delete an activity.
 */
class activity_handler_field_activity_link_delete extends activity_handler_field_activity_link {
  function construct() {
    parent::construct();
    $this->additional_fields['aid'] = 'aid';
    $this->additional_fields['uid'] = 'uid';
    $this->additional_fields['op'] = 'op';
    $this->additional_fields['type'] = 'type';
    $this->additional_fields['nid'] = 'nid';
  }

  function render($values) {
    // ensure user has access to edit this node.
    $activity = new stdClass();
    $activity->aid = $values->{$this->aliases['aid']};
    $activity->uid = $values->{$this->aliases['uid']};
    $activity->op = $values->{$this->aliases['op']};
    $activity->type = $values->{$this->aliases['type']};
    $activity->nid = $values->{$this->aliases['nid']};
    
    if (user_access('administer activity') || $GLOBALS['user']->uid == $activity->uid) {
      $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
      return l($text, "activity/$activity->aid/delete", array('query' => drupal_get_destination()));
    }
    else {
      return;
    }
  }
}

