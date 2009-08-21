if (Drupal.jsEnabled) {
  $(document).ready(function() {
    
	$('div#cp-settings-shield legend').hide();
    
	var theSubnav = $("<div>");
    theSubnav.addClass("shield_subnav");
    theSubnav.html("<h3>Select a shield</h3><div id=\"prev\" class=\"shield-pointer\"></div>");

    var subnavList = $('<ul>');
    var n_container = 0;

    $('div#cp-settings-shield div.form-radios .form-item').each(function(){
       	var jumpLink = $("<li>");
    	jumpLink.html("&nbsp;"+(n_container+1)+"&nbsp;");
    	
    	subnavList.append(jumpLink);
    	n_container++;
    });
    
    theSubnav.append(subnavList);
    theSubnav.append('<div id="next" class="theme-pointer"></div>');
    
    $('#cp-settings-shield').prepend(theSubnav);
    $(".item-theme-picker:first").addClass('active');
    var clickRegister = $('#cp-settings-shield');
    $('div#prev,div#next,.shield_subnav li').cpSlidingContainer({containerW: 90, 
    	                                                         mainListSelector:'div.form-radios',
							    							     listItemClass: 'form-item',
							    							     listItemSelector: 'div.form-item',
							    							     navClass:'shield_subnav',
							    							     changeObject:clickRegister });
    
    clickRegister.bind("indexChanged", function(e){
        var index = e.data.index;
        
        $("div.form-item input").attr('checked',false);
        $("div.form-item:eq("+ (index+1) +") input").attr('checked',true);
    });

    
  });
}
