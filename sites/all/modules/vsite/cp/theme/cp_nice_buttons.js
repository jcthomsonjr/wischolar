Drupal.behaviors.CpNiceButton = function(context){
  $(':submit:not(.cp-nice-button-processed)', context)
  .addClass('cp-nice-button-processed')
  .each(function(){
    var element = $(this);
    //var f = this.form;
    var link = $('<a class="submit-link ' + element.attr("id") + '" href="#"><span class="button-inner"><span class="label">' + element.val() + '</span></span></a>')
               .bind('click',[element],function(e){
            	 var elem = refresh_nicebutton_element(e.data[0]);
            	 elem.trigger('click');
            	 //elem.click();
                 return false;
               }).bind('mousedown',[element],function(e){
            	 var elem = refresh_nicebutton_element(e.data[0]);
            	 elem.trigger('mousedown');
                 return true;
               }).bind('mouseup',[element],function(e){
            	 var elem = refresh_nicebutton_element(e.data[0]);
            	 elem.trigger('mouseup');
                 return true;
               });
    element.after(link).css({position:'absolute', top:'-2000px'});	  
  });
}

function refresh_nicebutton_element(elem){
	if(elem.attr("id")){
		var tmp = $('#'+elem.attr("id"));
		if(tmp.length) elem = tmp; 
	}
	
	return elem;
}
