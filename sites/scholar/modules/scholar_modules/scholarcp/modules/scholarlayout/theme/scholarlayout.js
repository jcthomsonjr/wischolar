if (Drupal.jsEnabled) {
  $(document).ready(function() {
    var layoutRegions = ["#scholarlayout-header-left","#scholarlayout-header-main", "#scholarlayout-header-right", "#scholarlayout-navbar", "#scholarlayout-left", "#scholarlayout-right"];
    
    $.each(layoutRegions, function(i, value){
      $(value).sortable({
	  connectWith: layoutRegions
	  });
	});

    $("#scholarlayout-top-widgets").sortable({ 
      connectWith: layoutRegions
    }); 
  });
}