
function berkleySetFormData(base, id_name_url, lockField){
  if(!id_name_url.length) berkleyUnsetFormData(base);

  var meta = id_name_url.split("|", 3);
  
  $('#'+base+'berkley-id').val(meta[0]);
  $('#'+base+'berkley-name').val(meta[1]);
  $('#'+base+'berkley-url').val(meta[2]);
  
  $('#'+base+'name').val(meta[1]);
  if(lockField) $('#'+base+'name').attr("readonly", "readonly");
  
  if ( $('#'+base+'displayExtra').length <= 0 ) {
    $('#'+base+'name').after("<div id='"+ base +"displayExtra'><span>("+meta[0]+") "+meta[0]+" ["+meta[2]+"]</span></div>");
  }else{
    $('#'+base+'displayExtra').html("<span>("+meta[0]+") "+meta[1]+" ["+meta[2]+"]</span>");
  }
  
}

function berkleyUnsetFormData(base){
	  
	  $('#'+base+'berkley-id').val('');
	  $('#'+base+'berkley-name').val('');
	  $('#'+base+'berkley-url').val('');
	  
	  $('#'+base+'name').removeAttr("disabled");
	  
	  $('#'+base+'displayExtra').html("");	
	  
}

Drupal.behaviors.berkleyGetContrbutors = function(context) {

  //Each contributor button
  $('#node-form input.berkleyContributorCheck:not(.berkleyGetContrbutors-processed)', context).addClass('berkleyGetContrbutors-processed').each(function() {
  
    var check_id = $(this).attr('id');
    var base = check_id.replace('check-berkley', '');  // rem 'check-berkley' from end
    
    $(this).click(function() {

    	if(! $(this).is(':checked')){
    	  berkleyUnsetFormData(base);
    	  return true;
    	}
    	
    	var searchName = $('#'+base+'name').val();
    	
    	if ( $('#'+base+'displayExtra').length <= 0 ) {
    		$(this).parent().after("<div id='"+ base +"displayExtra'>Loading...</div>");
     	}
    	
    	if(!searchName.length){
    		$('#'+base+'displayExtra').html("<span class='red'>You must enter a name to search for.</span>");
    		return false;
    	}
    	
    	$.getJSON("/berkley_contrib_lookup/getContributors/js",
    			  { name: searchName },
	    	      function(data){

  					  var iHTML = "";
    				  jQuery.each(data, function(id,item){
    					  iHTML += "<option value='"+id+"|"+item[0]+"|"+item[1]+"'>"+item[0]+", "+item[1]+"</option>";
		
	    			  });
    				  
    				  if(!iHTML.length){
    					  $('#'+base+'displayExtra').html("<span class='red'>No results returned for ["+searchName+"].</span>");
    					  return false;
    				  }
    				  
	    			  iHTML = "<select onchange='berkleySetFormData(\""+base+"\",this.value,true);' ><option>Select Author</option>"+iHTML+"</select>";
	    			  $('#'+base+'displayExtra').html(iHTML);
    				  
    			  });
    	
        return true;
    });
    
    $('#'+base+'name').keyup(function() { 
    	if($('#'+base+'check-berkley').is(':checked')){
    		berkleyUnsetFormData(base);
    		$('#'+base+'check-berkley').attr('checked', false); 
    	}
    });
    
  });

}

if(Drupal.jsAC){
	 /**
	  * Overide some autocomplete functionality
	  */
	  Drupal.jsAC.prototype.select = function (node) { 
		  if(node.autocompleteValue.indexOf('|') != -1){
			  berkleySetFormData(this.input.id.replace('name', ''), node.autocompleteValue,false);
		  }else{
			  this.input.value = node.autocompleteValue;
		  }
	  };
	  
	  Drupal.jsAC.prototype.hidePopup = function (keycode) {
		  // Select item if the right key or mousebutton was pressed
		  if (this.selected && ((keycode && keycode != 46 && keycode != 8 && keycode != 27) || !keycode)) {
			  if(this.selected.autocompleteValue.indexOf('|') != -1){
				  berkleySetFormData(this.input.id.replace('name', ''), this.selected.autocompleteValue,false);
			  }else{
				  this.input.value = this.selected.autocompleteValue;
			  }
		  }
		  // Hide popup
		  var popup = this.popup;
		  if (popup) {
		    this.popup = null;
		    $(popup).fadeOut('fast', function() { $(popup).remove(); });
		  }
	    this.selected = false;
	  };
 }
