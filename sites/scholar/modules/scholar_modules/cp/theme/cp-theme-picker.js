if (Drupal.jsEnabled) {
  $(document).ready(function() {
    $('#-settings-theme .form-radios ').hide();

    var theSubnav = $("<div>");
    theSubnav.addClass("theme_subnav");
    theSubnav.html("<span class='label'>Select a Theme</span>");

    var theList = '<ul class = "theme-picker">'; // important, RSC depend on it
    var n_containers = 0;
    
    function getLi(liId, liChecked, liContent){
    	return '<li class = "item-theme-picker  ' + liChecked + '" id="' + liId  + '">' + liContent + '</li>';
    	
    }
    $('#-settings-form .form-radios .form-item').each(function(){
    	var liIdArr = $(this).attr('id').split('-');
    	var liId = liIdArr[3] + '-' + liIdArr[4] + '-' + liIdArr[5];
    	var liChecked = $(this).find('input').attr('checked') ? 'checked' : '';

    	// get the whole img div
    	var liContent = $(this).find('.item-theme-picker').html();

    	theList = theList + getLi(liId, liChecked, liContent);
    	
    	var jumpLink = $("<a>");
    	jumpLink.html("&nbsp;"+(n_containers+1)+"&nbsp;");
    	jumpLink.RSC_Jump(n_containers,{ containerW: 600 });
    	
    	theSubnav.append(jumpLink);
    	n_containers++;
    });
    
    theList = theList + '</ul>';
    
    theList = theList + '<div id="prev"></div>';
    theList = theList + '<div id="next"></div>';
    
    
    $('#-settings-theme').prepend(theList);
    $('#-settings-theme').prepend(theSubnav);
    $(".item-theme-picker:first").addClass('active');
    
    $('div#prev, div#next').RSC({ containerW: 600, noOfContainer: n_containers });
    
    $('li.item-theme-picker').click(function(){
    	// remove the active class from every li first
    	$(".item-theme-picker").removeClass('checked');
    	// add the class to this one
    	$(this).addClass('checked');
    	
    	var id = $(this).attr('id');
    	$(".form-radio").removeAttr("checked");
    	$("#edit-settings-theme-" + id).attr("checked", "checked"); 
    });
    
  });
}
