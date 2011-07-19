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
  //On each title edit, suggest a new path alias
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
	
	//When a path alias is manually supplied, check its validity
	$('#edit-path').bind('blur', function() {
	  if ($('#edit-path').attr('value') != '' && !$('#edit-pathauto-perform-alias').attr('checked')) {

	    var href = 'http://' + document.location.host + '/pathauto_extra/validate_js';
	    var data = Drupal.settings.pathauto_extra;
      data.path = $('#edit-path').attr('value');

      $.getJSON(href, data, function(json) {
	      if (json.errors.length > 0) {
	        var txt = "The URL you specified has the following errors: \n\n";
	        for (i in json.errors) txt += json.errors[i] + "\n";
	        alert(txt);
	      }
	    });
	  }
	});
};


