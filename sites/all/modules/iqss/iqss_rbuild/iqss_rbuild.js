/**
 * JS behaviors for iqss_rbuild.
 */
Drupal.behaviors.iqss_rbuild = function() {
  $('#edit-field-scholar-software-method-value:not(.rbuild_processed)').each(function() {
    $(this).addClass('rbuild_processed');
    $(this).change(function() {
      switch ($(this).val()) {
        case 'rbuild':
          $('#edit-field-scholar-software-repo-0-value').attr('disabled', 'disabled');
          $('#edit-field-scholar-software-repo-0-value').val(Drupal.settings.iqss_rbuild.repo_url); 
          $('#edit-title-wrapper').hide();
          $('#edit-title').val(Drupal.settings.iqss_rbuild.title_default); 
          $('#edit-field-scholar-software-name-0-value-wrapper').show();
          $('#edit-body-wrapper').hide();
          break;
        default:
        	$('#edit-field-scholar-software-repo-0-value').removeAttr('disabled');
            if(Drupal.settings.iqss_rbuild.repo_url && Drupal.settings.iqss_rbuild.repo_url == $('#edit-field-scholar-software-repo-0-value').val()) $('#edit-field-scholar-software-repo-0-value').val("");
            $('#edit-title-wrapper').show();
            if(Drupal.settings.iqss_rbuild.title_default && Drupal.settings.iqss_rbuild.title_default == $('#edit-title').val()) $('#edit-title').val("");
            $('#edit-field-scholar-software-name-0-value-wrapper').hide();
            $('#edit-body-wrapper').show();
          break;
      }
    });
    $(this).change();
  });
};