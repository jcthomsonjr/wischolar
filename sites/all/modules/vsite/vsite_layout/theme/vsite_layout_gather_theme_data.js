Drupal.behaviors.scholarlayoutGatherThemeData = function() {
    var layoutRegions = { header_left:"#header-left", header_main:"#header-main", header_right:"#header-right", navbar:"#navbar", left:"#sidebar-left", right:"#sidebar-right", content_main:"#content-main"};

    
    scholar_layout_send_region_data(layoutRegions);

};

function scholar_layout_send_region_data(layoutRegions){
	
	var containerOffset = $('#container').offset();
    $.each(layoutRegions, function(key, value){
  	  var offset = $(value).offset();
  	  
  	  var data = {theme:Drupal.settings.scholarlayoutGatherThemeData.theme_name ,name:key, height: Math.min($(value).height(),350), width: $(value).width(), left:(offset.left - containerOffset.left), top:(offset.top - containerOffset.top)  };
  	  
  	  delete layoutRegions[key];
  	  $.post(Drupal.settings.scholarlayoutGatherThemeData.theme_data_path, data,
  	    function(data){
  	      $('#content').append("<h4>Sent: "+data+"</h4>");
  	    scholar_layout_send_region_data(layoutRegions);
  	    }
  	  );
  	  return false;
  	});
	
}