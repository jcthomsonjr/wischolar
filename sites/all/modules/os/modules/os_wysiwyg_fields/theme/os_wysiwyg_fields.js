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
		
		$('#edit-' + id.replace('_', '-', 'g') + '-' + delta + '-wysiwyg-fields-ahah-wrapper').appendTo()
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
	
	var hasRun = false;
	Drupal.behaviors.adjustWysiwygSettings = function () {
		
		// set extended valid settings to include id for spans
		// prevents error with inserted items ending up in helper elements that are removed later
		// run this every time incase an ahah call replaces it
		var settings = Drupal.settings.wysiwyg.configs.tinymce;
		
		if (typeof settings.format1 == 'object')
			settings = settings.format1;
		else if (typeof settings.format6 == 'object')
			settings = settings.format6;
		else if (typeof settings.format5 == 'object') 
			settings = settings.format5;
		else return;
		
		var eve = settings.extended_valid_elements.split(',');
		jQuery.each(eve, function(i, item) {
			if (item.indexOf('span') != -1 && item.indexOf('id') == -1) {
				var t = item;
				t = t.replace('span[', '').replace(']','').split('|');
				t.push('id');
				eve[i] = 'span['+t.join('|')+']';
			}
		});
		settings.extended_valid_elements = eve.join(',');
		
		if (!hasRun) {
			// prevent wysiwyg_fields from stripping out the oembed code and replacing it with empty token
			Drupal.wysiwyg.plugins.wysiwyg_fields_field_os_inline_oembed.detach = function (content, settings, instanceId) {
				return Drupal.wysiwygFields.wysiwygDetach('zzzzz_do_not_find_me', content, settings, instanceId);
			};
		}
		
		// pull the Insert button out of a div and next to remove
		if (hasRun) {
			$('.widget-edit:visible').each(function (item) {
				var btn = this.getElementsByClassName('insert-button')[0];
				if (!btn) return;
				btn.parentNode.removeChild(btn);
				
				$('input[value="Remove"]', this).before(btn);
			});
		}
		hasRun = true;
	};
})(jQuery);