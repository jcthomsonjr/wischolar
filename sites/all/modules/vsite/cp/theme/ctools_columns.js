if (Drupal.jsEnabled) {
  Drupal.cpAddCToolsColumns = function() {
	  var container = $('#modal-content');
	  var form = $('#modal-content > form');
	  if(container.length && form.length && container.height() < form.height()){
		  if(form.find('fieldset').length == 1){
			  var col = $("<div class='modal_col'></div>");
			  var col_height = (form.height() > (container.height() * 2))?Math.round(form.height()/2):container.height();
			  form.find('fieldset').prepend(col);
			  form.find('fieldset .form-item').each(function(index,domElement) {
				  var el = $(domElement);
				  var tmp_h = $('.modal_col:last').height();
				  var tmp_hc = container.height();
				  if((el.height() + $('.modal_col:last').height()) > col_height && $('.modal_col').length < 2){
					col = $("<div class='modal_col'></div>");
				    $('.modal_col:last').after(col);
				  }
				  $('.modal_col:last').append(el);
				  if($('.modal_col').length == 2 && $('.modal_col:last').height() > $('.modal_col:first').height()){
					  $('.modal_col:first').append($('.modal_col:last .form-item:first'));
				  }
			  });
			  
		  }//Don't try this if there are a lot of fieldsets / or none
	  }
  }
}