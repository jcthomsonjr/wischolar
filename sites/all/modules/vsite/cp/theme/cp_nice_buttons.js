Drupal.behaviors.CpNiceButton = function(context){
  $(':submit:not(.cp-nice-button-processed)', context)
  .addClass('cp-nice-button-processed')
  .each(function(){
    var $this = $(this);
    //var f = this.form;
    var link = $('<a class="submit-link ' + $this.attr("id") + '" href="#"><span class="button-inner"><span class="label">' + $this.val() + '</span></span></a>')
               .bind('click',[$this],function(e){
            	 var elem = refresh_nicebutton_element(e.data[0]);
            	 elem.click();
                 return false;
               }).bind('mousedown',[$this],function(e){
            	 var elem = refresh_nicebutton_element(e.data[0]);
            	 elem.trigger('mousedown');
                 return true;
               }).bind('mouseup',[$this],function(e){
            	 var elem = refresh_nicebutton_element(e.data[0]);
            	 elem.trigger('mouseup');
                 return true;
               });
    $this.after(link).css({position:'absolute', top:'-2000px'});	  
  });
}

function refresh_nicebutton_element(elem){
	if(elem.attr("id")){
		var tmp = $('#'+elem.attr("id"));
		if(tmp.length) elem = tmp; 
	}
	
	return elem;
}
