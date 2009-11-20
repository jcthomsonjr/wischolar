if (Drupal.jsEnabled) {
  $(document).ready(function() {

    var n_container = $('#cp-settings-form .form-radios .form-item').length;
    
    $(".item-theme-picker:first").addClass('active');
    $('div#prev,div#next,.theme_subnav li').cpSlidingContainer({containerW: 600, 
    															mainListSelector:'ul.theme-picker',
						    								    listItemClass: 'item-theme-picker', 
						    								    navClass:'theme_subnav'});
    
    $('li.item-theme-picker').click(function(){
    	// remove the active class from every li first
    	$(".item-theme-picker").removeClass('checked');
    	// add the class to this one
    	$(this).addClass('checked');
    	$("#edit-settings-theme-" + $(this).attr('id')).attr("checked", "checked").change(); 
    });
    
  });
}
