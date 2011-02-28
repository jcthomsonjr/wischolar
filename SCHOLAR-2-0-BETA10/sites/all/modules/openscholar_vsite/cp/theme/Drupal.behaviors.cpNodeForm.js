Drupal.behaviors.cpNodeForm = function() {

  if($('form#node-form fieldset.vt-advanced-options').length < 1){
    $('form#node-form div.vertical-tabs').wrap('<fieldset class="vt-advanced-options collapsible collapsed" />');
    $('form#node-form fieldset.vt-advanced-options').prepend('<legend>Advanced Options</legend>')
  }
};