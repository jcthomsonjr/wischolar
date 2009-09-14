/**
 * Provide the HTML to create the modal dialog.
 */
Drupal.theme.CToolsModalDialog = function () {
  var html = ''
  html += '  <div id="ctools-modal">'
  html += '    <div class="ctools-modal-content">' // panels-modal-content
  html += '      <div class="modal-header">';
  html += '        <h3 id="modal-title" class="modal-title">&nbsp;</h3>';
  html += '      </div>';
  html += '      <div id="modal-content" class="modal-content">';
  html += '      </div>';
  html += '    </div>';
  html += '    <div id="ctools-left"></div>';
  html += '    <div id="ctools-bottom"></div>';
  html += '    <div id="ctools-right"></div>';
  html += '        <a class="close" href="#">';
  html +=            Drupal.settings.CToolsModal.closeText + Drupal.settings.CToolsModal.closeImage;
  html += '        </a>';
  html += '  </div>';

  return html;
}


/**
 * AJAX responder command to place HTML within the modal.
 */
Drupal.CTools.AJAX.commands.modal_display = function(command) {
  $('#modal-title').html(command.title);
  $('#modal-content').html(command.output);
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
  Drupal.attachBehaviors($('#modal-content'));
}
