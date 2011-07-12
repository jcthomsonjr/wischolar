/**
 * pathauto_ajax.js
 * 
 * retrieves path of new node from drupal, inserts it into pathauto form
 */

/* attach a click even to the path tab */
$(document).ready( function() {
	$('a.vertical-tabs-list-path').click(function(){
		if ($('#edit-path').attr('value') == '') {
			make_alias();
		}
	});
});

/**
 *  ajax call back to drupal
 * pass it some information from the current page, since that can't be loaded from the node yet
 * on success, replace the path with the results
 */
function make_alias() {
	data = {};
	data.type =  document.URL.split('/').pop().split('?').shift();
	data.title_raw = $('#edit-title').attr('value');
	data.space_og_path = document.URL.split('/')[3];
	
	href = 'http://' + document.location.host + '/pathauto_ajax/alias_js';
	$.getJSON(href, data, function(json) {
		if (json.status) {
			$('#edit-path').attr('value', json.data);			
		}
	})
}
