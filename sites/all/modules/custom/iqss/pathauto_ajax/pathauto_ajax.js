/**
 * pathauto_ajax.js
 * 
 * retrieves path of new node from drupal, inserts it into pathauto form
 */

/* $().focusout is unavailable to live() in jQuery 1.2.6, so use behaviors for event binding instead. */
Drupal.behaviors.pathauto_ajax = function(context, settings) {
	$('#edit-title').bind('blur', function() {
		if ( $('#edit-title').attr('value') != '') {
			make_alias();
		}
	});
};

/**
 *  ajax call back to drupal
 * pass it some information from the current page, since that can't be loaded from the node yet
 * on success, replace the path with the results
 */
function make_alias() {
	data = Drupal.settings.pathauto_ajax;
	data.title_raw = $('#edit-title').attr('value');
	
	href = 'http://' + document.location.host + '/pathauto_ajax/alias_js';
	$.getJSON(href, data, function(json) {
		if (json.status && json.data.length>0) {
			$('#edit-path').attr('value', json.data);			
		}
	})
}
