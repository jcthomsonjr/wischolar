/**
 * pathauto_extra.js
 * 
 * retrieves path of new node from drupal, inserts it into pathauto form
 */

/*
 * $().focusout is unavailable to live() in jQuery 1.2.6, so use behaviors for
 * event binding instead.
 */

Drupal.behaviors.pathauto_extra = function(context, settings) {
	$('#edit-title').bind('blur', function() {
		if ($('#edit-title').attr('value') != '') {
			
		  //collect some data to pass back to pathauto_extra_alias_js
		  var data = Drupal.settings.pathauto_extra;
		  data.title = $.trim($('#edit-title').attr('value'));

		  //send data by ajax.  callback places result in #edit-path's value attribute
		  var href = 'http://' + document.location.host + '/pathauto_extra/alias_js';
		  $.getJSON(href, data, function(json) {
		    if (json.status && json.data.length > 0) {
		      $('#edit-path').attr('value', json.data);
		    }
		  })
		  
		}
	});
};


