// $Id: activity_comments.js,v 1.1.2.1 2010/01/13 05:25:29 scottreynolds Exp $

(function ($) {
  /**
   * Behavior to attach to the show all class.
   */
  Drupal.behaviors.activityCommentsShowAll = function (context) {
    $('.activity-comment-show-all:not(.activity-comment-show-all-processed)').each(function (i) {
      $(this).click(function() {
        // remove the hide comments class so everything is shown below.
        $(this).parents('.activity-comments-hide-comments').removeClass('activity-comments-hide-comments');
        return false;
      });
    }).addClass('activity-comment-show-all-processed');
  };
  
  /**
   * Handles the default text in the comment text field.
   */
  Drupal.behaviors.activityDefaultText = function (context) {
    $('input.activity-comment-text:not(.activity-default-text-processed)').each(function (i) {
      // we you focus on the form area, hide the default text.
      $(this).focus(function() {
        if ($(this).val() == Drupal.settings.activity_comments.default_text) {
          $(this).val('');
        }
      });
      // we you leave focus of the form area and you haven't entered anything
      // add back in the default text.
      $(this).blur(function() {
        if ($(this).val() == '') {
          $(this).val(Drupal.settings.activity_comments.default_text);
        }
      });
    }).addClass('activity-default-text-processed');
  };
  
  /**
   * Hanldes the destination for the delete link.
   */
  Drupal.behaviors.activityDestination = function(context){
    $('.activity-comments-delete a:not(.activity-destination-processed)').each(function() {
      var href = $(this).attr('href').split('?destination=')[0] + '?' + Drupal.settings.activity_comments.destination;
      $(this).attr('href', href).addClass('activity-destination-processed');
    });
  };
})(jQuery);
