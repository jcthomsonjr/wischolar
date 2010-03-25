// $Id$

/**
 * JS behaviors for scholar_software.
 */
Drupal.behaviors.scholar_software = function() {
  $('#edit-field-scholar_software-method-value:not(.processed)').each(function() {
    $(this).addClass('processed');
    $(this).change(function() {
      switch ($(this).val()) {
        case '0':
          $('#edit-field-scholar_software-repository-0-value-wrapper').hide();
          break;
        default:
          $('#edit-field-scholar_software-repository-0-value-wrapper').show();
          break;
      }
    });
    $(this).change();
  });
};
