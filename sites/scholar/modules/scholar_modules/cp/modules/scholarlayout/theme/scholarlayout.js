if (Drupal.jsEnabled) {
  $(document).ready(function() {
    var layoutRegions = ["#scholarlayout-header-left","#scholarlayout-header-main", "#scholarlayout-header-right", "#scholarlayout-navbar", "#scholarlayout-left", "#scholarlayout-right"];
    
    $.each(layoutRegions, function(i, value){
      $(value).sortable({
	    connectWith: layoutRegions,
	    stop: function(event, ui) { 
    	  $.each(layoutRegions, function(i, value){ 
	    	var items = $(value+" > .scholarlayout-item");
	    	var ids = "";
	    	$.each(items, function(i, value){ 
	    		if(ids.length) ids += "|";
	    		ids += value.id; 
	    	} );
	    	$(value.replace('#','#edit-')).val(ids);
	      }) }
	  });
	});

    $("#scholarlayout-top-widgets").sortable({ 
      connectWith: layoutRegions,
      stop: function(event, ui) { 
    	  $.each(layoutRegions, function(i, value){ 
	    	var items = $(value+" > .scholarlayout-item");
	    	var ids = "";
	    	$.each(items, function(i, value){ 
	    		if(ids.length) ids += "|";
	    		ids += value.id; 
	    	} );
	    	$(value.replace('#','#edit-')).val(ids);
	      }) }
    }); 
  });
}