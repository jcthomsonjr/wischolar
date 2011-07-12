/**
 * Overrides some of wysiwyg_fields' functions to be more intuitive
 */
(function ($) {
	if (typeof Drupal.wysiwyg == 'undefined')
		return;
	
	function cleanUp(id) {
		// remove the 'Expand' button. There's nothing hidden to Expand.
		$('.ui-dialog-titlebar .wysiwyg_fields-icon-expand').remove();
		
		// remove the Insert button added by wysiwyg_fields.
		// The button provided by Insert is more useful.
		$('.ui-dialog-buttonpane').not('#wysiwyg_fields-field_os_inline_oembed-dialog .ui-dialog-buttonpane').remove();
		
		// Show the table
		$('#' + id.replace('_', '-', 'g') + '-items, #wysiwyg_fields-' + id + '-wrapper table').show();
	}
	
	// store the current functions
	var dialogShowDefaultOld = Drupal.wysiwygFields.dialogShowDefault,
		dialogShowUpdateOld = Drupal.wysiwygFields.dialogShowUpdate;
	
	// overwrite current functions with new ones that call the current funcs and tweak the results.
	Drupal.wysiwygFields.dialogShowDefault = function (id) {
		dialogShowDefaultOld.call(Drupal.wysiwygFields, id);
		cleanUp(id);
	}
	
	Drupal.wysiwygFields.dialogShowUpdate = function (id) {
		dialogShowDefaultUpdate.call(Drupal.wysiwygFields, id);
		cleanUp(id);
	}
})(jQuery);