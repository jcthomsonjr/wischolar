Drupal.behaviors.CpNiceButton = function(context){
  $(':submit:not(.cp-nice-button-processed)', context)
  .addClass('cp-nice-button-processed')
  .each(function(){
    var element = $(this);
    //var f = this.form;
    var link = $('<a class="submit-link ' + element.attr("id") + '" href="#"><span class="button-inner"><span class="label">' + element.val() + '</span></span></a>')
               .bind('click',[element],function(e){
            	 var elem = refresh_nicebutton_element(e.data[0],$(e.target));
            	 if(elem.is(".ctools-use-modal-processed")){
            	   elem.triggerHandler('click');
            	   $("#modal-content form").submit();
            	 }else{
            	   elem.trigger('click');
            	 }//This is a hack till we fix the html error that is submiting the wrong form
                 return false;
               }).bind('mousedown',[element],function(e){
            	 var elem = refresh_nicebutton_element(e.data[0],$(e.target));
            	 elem.trigger('mousedown');
                 return true;
               }).bind('mouseup',[element],function(e){
            	 var elem = refresh_nicebutton_element(e.data[0],$(e.target));
            	 elem.trigger('mouseup');
                 return true;
               });
    element.after(link).css({position:'absolute', top:'-2000px'});	  
  });
}

function refresh_nicebutton_element(elem,clicked){
	if(elem.attr("id")){
		var par = clicked.parent().parent().parent(); //Get outside Nice button
		if(par.length && par.find('#'+elem.attr("id")).length){
			elem = par.find('#'+elem.attr("id"));
		}else{
		  var tmp = $('#'+elem.attr("id"));
		  if(tmp.length) elem = tmp;
		}
	}
	
	return elem;
}
