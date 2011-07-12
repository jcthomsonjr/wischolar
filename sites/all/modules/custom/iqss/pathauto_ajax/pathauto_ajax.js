/**
 * pathauto_ajax.js
 * 
 * retrieves path of new node from drupal, inserts it into pathauto form
 */

$(document).ready( function() {
	$('a.vertical-tabs-list-path').click(function(){
		make_alias();	
	});
});

function make_alias() {
	data = {};
	href = 'http://' + document.location.host + '/pathauto_ajax/alias_js';
	$.getJSON(href, data, function(json) {
		if (json.status) {
			$('#edit-path').attr('value', json.data);			
		}
	})
}
