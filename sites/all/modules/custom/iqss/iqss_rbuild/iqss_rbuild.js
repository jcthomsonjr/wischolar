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
          
          if(!$('#rbuild-autopopulate-wrapper').length) $('#edit-field-scholar-software-method-value-wrapper').after('<div class="form-item" id="rbuild-autopopulate-wrapper"><label for="rbuild-autopopulate">Automatically Populate Fields:</label><input class="form-checkbox" id="rbuild-autopopulate" type="checkbox" checked="checked" /><div class="description">Auto populate this projects title and body fields from the rbuild repository.</div></div>');
          
          
          
          $('#rbuild-autopopulate').change(function() { 
        	  if ($('#rbuild-autopopulate').attr('checked')) {
        		$('#edit-title-wrapper').hide();
                $('#edit-body-wrapper').hide();
              }else{
                $('#edit-title-wrapper').show();
                $('#edit-body-wrapper').show();
              }
          });
          $('#edit-title-wrapper').hide();
          $('#edit-body-wrapper').hide();
          
          if(!$('#edit-iqss-remote-source-path').val()){
        	  $('#rbuild-autopopulate').attr('checked',false);
        	  $('#rbuild-autopopulate').change();
          }
          break;
        default:
        	$('#rbuild-autopopulate-wrapper').remove();
        	$('#edit-field-scholar-software-repo-0-value').removeAttr('disabled');
            if(Drupal.settings.iqss_rbuild.repo_url && Drupal.settings.iqss_rbuild.repo_url == $('#edit-field-scholar-software-repo-0-value').val()) $('#edit-field-scholar-software-repo-0-value').val("");
            $('#edit-title-wrapper').show();
            if(Drupal.settings.iqss_rbuild.title_default && Drupal.settings.iqss_rbuild.title_default == $('#edit-title').val()) $('#edit-title').val("");
            //$('#edit-field-scholar-software-name-0-value-wrapper').hide();
            $('#edit-body-wrapper').show();
          break;
      }
    });
    $(this).change();
  });
};