
function bknSetFormData(base, id_name_url, lockField){
  if(!id_name_url.length) bknUnsetFormData(base);

  var meta = id_name_url.split("|", 3);
  
  $('#'+base+'bkn-id').val(meta[0]);
  $('#'+base+'bkn-name').val(meta[1]);
  $('#'+base+'bkn-url').val(meta[2]);
  
  $('#'+base+'name').val(meta[1]);
  if(lockField) $('#'+base+'name').attr("readonly", "readonly");
  
  if ( $('#'+base+'displayExtra').length <= 0 ) {
    $('#'+base+'name').after("<div id='"+ base +"displayExtra'><span>("+meta[0]+") "+meta[0]+" ["+meta[2]+"]</span></div>");
  }else{
    $('#'+base+'displayExtra').html("<span>("+meta[0]+") "+meta[1]+" ["+meta[2]+"]</span>");
  }
  
}

function bknUnsetFormData(base){
	  
	  $('#'+base+'bkn-id').val('');
	  $('#'+base+'bkn-name').val('');
	  $('#'+base+'bkn-url').val('');
	  
	  $('#'+base+'name').removeAttr("disabled");
	  
	  $('#'+base+'displayExtra').html("");	
	  
}

Drupal.behaviors.bknGetContrbutors = function(context) {

  //Each contributor button
  $('#node-form input.bknContributorCheck:not(.bknGetContrbutors-processed)', context).addClass('bknGetContrbutors-processed').each(function() {
  
    var check_id = $(this).attr('id');
    var base = check_id.replace('check-bkn', '');  // rem 'check-bkn' from end
    
    $(this).click(function() {

    	if(! $(this).is(':checked')){
    	  bknUnsetFormData(base);
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
    	
    	$.getJSON("/bkn/getContributors/js",
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
    				  
	    			  iHTML = "<select onchange='bknSetFormData(\""+base+"\",this.value,true);' ><option>Select Author</option>"+iHTML+"</select>";
	    			  $('#'+base+'displayExtra').html(iHTML);
    				  
    			  });
    	
        return true;
    });
    
    $('#'+base+'name').keyup(function() { 
    	if($('#'+base+'check-bkn').is(':checked')){
    		bknUnsetFormData(base);
    		$('#'+base+'check-bkn').attr('checked', false); 
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
			  bknSetFormData(this.input.id.replace('name', ''), node.autocompleteValue,false);
		  }else{
			  this.input.value = node.autocompleteValue;
		  }
	  };
	  
	  Drupal.jsAC.prototype.hidePopup = function (keycode) {
		  // Select item if the right key or mousebutton was pressed
		  if (this.selected && ((keycode && keycode != 46 && keycode != 8 && keycode != 27) || !keycode)) {
			  if(this.selected.autocompleteValue.indexOf('|') != -1){
				  bknSetFormData(this.input.id.replace('name', ''), this.selected.autocompleteValue,false);
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
