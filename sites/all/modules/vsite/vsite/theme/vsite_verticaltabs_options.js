if (Drupal.jsEnabled) {
  $(document).ready(function() {
	Drupal.verticalTabs.options = function() {
	  var vals = [];
	  if ($('#edit-status').attr('checked') || $('#edit-override-publishing-status').attr('checked')) {
	    vals.push(Drupal.t('Published'));
	  }
	  if ($('#edit-promote').attr('checked') || $('#edit-vsite-promote-to-front').attr('checked')) {
	    vals.push(Drupal.t('Promoted to front page'));
	  }
	  if ($('#edit-sticky').attr('checked') || $('#edit-override-publishing-sticky').attr('checked')) {
	    vals.push(Drupal.t('Sticky on top of lists'));
	  }
	  if ($('#edit-vsite-make-featured').attr('checked')) {
	    vals.push(Drupal.t('Featured'));
	  }
	  if (vals.join(', ') == '') {
	    return Drupal.t('None');
	  }
	  return vals.join(', ');
	}
  });
}
