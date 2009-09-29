if (Drupal.jsEnabled) {
  $(document).ready(function() {
	  vsite_generic_grey_out($('#edit-settings-generic-disable-shield'));
  });
}

function vsite_generic_grey_out(element){
	if($(element).is(':checked')){
	  $('.shield_wrapper').prepend("<div id=\'shield_screen\'></div>").css({ 'position': 'relative', 'overflow': 'hidden' }); 
		$('#shield_screen').css({ 'opacity': 0.5, 
			               'width':$('.shield_wrapper').width(),
			               'height':'400px',
			               'position': 'absolute',
			               'margin':'0px 0px 0px 0px',
			               'background':'#000'
		});
	}else{
	  $('#shield_screen').remove();
	}
}