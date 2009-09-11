
function cp_updateLogo(c){
		$('#edit-settings-logo-x-cord').val(c.x);
		$('#edit-settings-logo-y-cord').val(c.y);
		$('#edit-settings-logo-width').val(c.w);
		$('#edit-settings-logo-height').val(c.h);
}

if (Drupal.jsEnabled) {
  $(document).ready(function() {
	  $('#logo_preview').Jcrop({
	    aspectRatio: 1.2857,
	    minSize: [180,140],
	    onSelect: cp_updateLogo,
	    allowMove: true
	  });
	  
	  $('#edit-settings-logo-logo-upload').change(function() {
		  $('#cp-settings-form').submit();
	  });//Turns out the easiest solution is the best.
  });
}