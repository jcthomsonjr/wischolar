Drupal.behaviors.scholarlayout = function() {
    var layoutRegions = ["#scholarlayout-header-left","#scholarlayout-header-main", "#scholarlayout-header-right", "#scholarlayout-navbar", "#scholarlayout-left", "#scholarlayout-right"];

    scholarlayout_add_sortable(layoutRegions);


    if(!scholarlayout_change_bound){
    	scholarlayout_change_bound = true;

    	$('#cp-settings-form').submit(function() {
    		scholarlayout_afterdrag(null,null);
    		return true;
    	});


	    $("#edit-settings-layout-page-type").bind('change', function(e){
	    	if(scholarlayout_catchchanges()){
	    		$('#edit-settings-layout-secret-hidden-ahah').val($("#edit-settings-layout-page-type").val());
		    	$('#edit-settings-layout-secret-hidden-ahah').trigger('go_ahah');
		    	$("#edit-settings-layout-page-type").trigger('go_ahah');
		    	$("#scholarforms_save_warning").remove();
		    	scholarlayout_add_sortable(layoutRegions);
	    	}else{
	    		//revert
	    		$('#edit-settings-layout-page-type').val($("#edit-settings-layout-secret-hidden-ahah").val());
	    	}
	    });
	    
	    $(window).resize(function() { vsite_layout_setScrollArrows(); });

    }
    scholarlayout_add_removal_hooks();
    vsite_layout_setScrollArrows();
};

function scholarlayout_add_removal_hooks(){
	$(".close-this:not(.close-this-processed)").addClass('close-this-processed').click(function(e){
    	var parent = $(this).parent("li");
    	$("body").append("<div class='poof'></div>");

    	// set the x and y offset of the poof animation <div> from cursor position (in pixels)
        var xOffset = 24;
        var yOffset = 24;

        $('.poof').css({
          left: e.pageX - xOffset + 'px',
          top: e.pageY - yOffset + 'px'
        }).show(); // display the poof <div>
        animatePoof(); // run the sprite animation

        parent.appendTo("#scholarlayout-top-widgets");
    	scholarlayout_afterdrag(e,null);

        parent.fadeIn('fast');
    });
}

var scholarlayout_change_bound = false;
function scholarlayout_afterdrag(event, ui) {
	  var regions = $("#scholarlayout-container > ul.scholarlayout-widgets-list");
	  $.each(regions, function(i, region){
	    var items = $("#"+region.id+" > .scholarlayout-item");
	    var ids = "";
	    $.each(items, function(i, value){
	      if(ids.length) ids += "|";
	      ids += value.id;
	    } );
	   	$('#edit-settings-layout-'+region.id).val(ids);
	  });
	  
	  //Reset top box after widgets have been moved
	  vsite_layout_setScrollArrows();

	  if(!$("#scholarforms_save_warning").length && event) $("#cp-settings-layout").before($('<div id="scholarforms_save_warning" class="warning"><span class="warning tabledrag-changed">*</span> Your changes have not yet been saved. Click "Save Settings" for your changes to take effect</div>'));
};

function scholarlayout_catchchanges() {
	if(!$("#scholarforms_save_warning").length || confirm("Your changes have not been saved. Continue and lose your changes?")) return true;

	return false;
};

function scholarlayout_add_sortable(layoutRegions){
	var allRegions = layoutRegions.slice();
	allRegions[allRegions.length] = "#scholarlayout-top-widgets";
	$.each(allRegions, function(i, value){
	  $(value).sortable({
        connectWith: allRegions,
	    stop: scholarlayout_afterdrag
	  });
	});

}

//The jQuery Poof Effect was developed by Kreg Wallace at The Kombine Group, Inc. http://www.kombine.net/

function animatePoof() {
    var bgTop = 0; // initial background-position for the poof sprit is '0 0'
    var frames = 5; // number of frames in the sprite animation
    var frameSize = 32; // size of poof <div> in pixels (32 x 32 px in this example)
    var frameRate = 80; // set length of time each frame in the animation will display (in milliseconds)

    // loop through amination frames
    // and display each frame by resetting the background-position of the poof <div>
    for(i=1;i<frames;i++) {
      $('.poof').animate({
        backgroundPosition: '0 ' + (bgTop - frameSize) + 'px'
      }, frameRate);
      bgTop -= frameSize; // update bgPosition to reflect the new background-position of our poof <div>
    }
    // wait until the animation completes and then hide the poof <div>
    setTimeout("$('.poof').remove()", frames * frameRate);
}

function vsite_layout_setScrollArrows(){
	var nContainerWidth = $('ul#scholarlayout-top-widgets').width();
	var nWidgetWidth = $('ul#scholarlayout-top-widgets li:not(.disabled)').length * $('ul#scholarlayout-top-widgets li:first').width();
	
	if(nContainerWidth > nWidgetWidth){
      $('div.widget-prev, div.widget-next').addClass('disabled').unbind('click');
      
	}else{
      $('div.widget-prev, div.widget-next').removeClass('disabled');
	  $('div.widget-prev').click(function() {
		  $('ul#scholarlayout-top-widgets').prepend($('ul#scholarlayout-top-widgets li:last'));
	  });
	  $('div.widget-next').click(function() {
		  $('ul#scholarlayout-top-widgets').append($('ul#scholarlayout-top-widgets li:first'));
	  });
	}
}