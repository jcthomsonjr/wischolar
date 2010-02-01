if (Drupal.jsEnabled) {
  Drupal.cpAddCToolsColumns = function() {
	  var container = $('#modal-content');
	  var form = $('#modal-content > form');
	  if(container.length && form.length && container.height() < form.height()){
		  if(form.find('fieldset').length == 1){
			  var col = $("<div class='modal_col'></div>");
			  var col_height = (form.height() > (container.height() * 2))?Math.round(form.height()/2):container.height();
			  
			  //Add the wrapper
			  if(form.find('fieldset div.fieldset-wrapper').length == 0) form.find('fieldset').wrapInner("<div class='fieldset-wrapper'></div>");
			  if(form.find('fieldset div.fieldset-wrapper > div.description').length != 0) form.find('fieldset').prepend(form.find('fieldset div.fieldset-wrapper > div.description'));
		      if(form.find('fieldset div.fieldset-wrapper > legend').length != 0) form.find('fieldset').prepend(form.find('fieldset div.fieldset-wrapper > legend'));
			  
		      if(form.find('fieldset div.fieldset-wrapper table').length == 0  && form.find('fieldset div.fieldset-wrapper .no_modal_col').length == 0){
				  form.find('fieldset div.fieldset-wrapper').prepend(col);
				  form.find('fieldset > .form-item').each(function(index,domElement) {
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
		      }//Make sure there are no tables, and we havn't explicitly said no modal cols, we don't mess with those
			  
		  }//Don't try this if there are a lot of fieldsets / or none
		  
		  if(form.find('fieldset').length > 1){
			form.find('fieldset').each(function() {
				var cur_fs = $(this);
				//Add the wrapper
				if(cur_fs.find('div.fieldset-wrapper').length == 0) cur_fs.wrapInner("<div class='fieldset-wrapper'></div>");
				if(cur_fs.find('div.fieldset-wrapper > div.description').length != 0) cur_fs.prepend(cur_fs.find('div.fieldset-wrapper > div.description'));
				if(cur_fs.find('div.fieldset-wrapper > legend').length != 0) cur_fs.prepend(cur_fs.find('div.fieldset-wrapper > legend'));
				
				cur_fs = cur_fs.find('div.fieldset-wrapper');
				
				if(cur_fs.find('table').length == 0 && cur_fs.find('.no_modal_col').length == 0){
					if(cur_fs.find('.form-item').length > 3){
						var col = $("<div class='modal_col'></div>");
						var col_height = (form.height() > (cur_fs.height() * 2))?Math.round(form.height()/2):cur_fs.height();
						cur_fs.prepend(col);
						cur_fs.find('.form-item').each(function(index,domElement) {
					      var el = $(domElement);
						  var tmp_h = cur_fs.find('.modal_col:last').height();
						  var tmp_hc = cur_fs.height();
						  if((el.height() + tmp_h) > col_height && cur_fs.find('.modal_col').length < 2){
							col = $("<div class='modal_col'></div>");
							cur_fs.find('.modal_col:last').after(col);
						  }
						  cur_fs.find('.modal_col:last').append(el);
						  if(cur_fs.find('.modal_col').length == 2 && cur_fs.find('.modal_col:last').height() > cur_fs.find('.modal_col:first').height()){
							  cur_fs.find('.modal_col:first').append(cur_fs.find('.modal_col:last .form-item:first'));
						  }
						});
					}
			    }//Make sure there are no tables, and we havn't explicitly said no modal cols, we don't mess with those
		    });
		  }
	  }else{
		  form.find('fieldset').each(function() {
				var cur_fs = $(this);
				//Add the wrapper
				if(cur_fs.find('div.fieldset-wrapper').length == 0) cur_fs.wrapInner("<div class='fieldset-wrapper'></div>");
				
				//Move the label and description back into place
				if(cur_fs.find('div.fieldset-wrapper > div.description').length != 0) cur_fs.prepend(cur_fs.find('div.fieldset-wrapper > div.description'));
				if(cur_fs.find('div.fieldset-wrapper > legend').length != 0) cur_fs.prepend(cur_fs.find('div.fieldset-wrapper > legend'));
		  });
	  }//Just add the needed wrappers if we don't want to make 2 cols (ie. the data is already < one page
	  
	  form.find('.form-checkboxes').each(function(index,domElement) {
		  var el = $(domElement);
		  if(el.find('.form-item').length <=5){
			  el.find('.form-item').each(function(index,domElement) {
				 $(domElement).addClass('horizontal');
			  });
		  }
	  });//add horizontal to checkboxes with < 5 elements
  }
}