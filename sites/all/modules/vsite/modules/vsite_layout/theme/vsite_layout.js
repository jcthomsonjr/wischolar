Drupal.behaviors.scholarlayout = function() {
    var layoutRegions = ["#scholarlayout-header-left","#scholarlayout-header-main", "#scholarlayout-header-right", "#scholarlayout-navbar", "#scholarlayout-left", "#scholarlayout-right"];

    scholarlayout_add_sortable(layoutRegions);


    if(!scholarlayout_change_bound){
    	scholarlayout_change_bound = true;

	    $("#edit-page-type").bind('change', function(e){
	    	if(scholarlayout_catchchanges()){
	    		$('#edit-secret-hidden-ahah').val($("#edit-page-type").val());
		    	$('#edit-secret-hidden-ahah').trigger('go_ahah');
		    	$("#edit-page-type").trigger('go_ahah');
		    	$("#scholarforms_save_warning").remove();
		    	scholarlayout_add_sortable(layoutRegions);
	    	}else{
	    		//revert
	    		$('#edit-page-type').val($("#edit-secret-hidden-ahah").val());
	    	}
	    });

	    $(".close-this").click(function(e){
	    	var parent = $(this).parent("li");
	    	parent.appendTo("#scholarlayout-top-widgets");
	    	scholarlayout_afterdrag(e,null);
	    	// set the x and y offset of the poof animation <div> from cursor position (in pixels)
        var xOffset = 24;
        var yOffset = 24;

        // remove clicked box from the document tree
        $(this).fadeOut('fast');

        // set the absolute postion of the poof animation <div>
        // uses e.pageX and e.pagY to get the cursor position
        // and offsets the poof animation from this point based on the xOffset and yOffset values set above
        $('.poof').css({
          left: e.pageX - xOffset + 'px',
          top: e.pageY - yOffset + 'px'
        }).show(); // display the poof <div>
        animatePoof(); // run the sprite animation
	    });

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
        setTimeout("$('.poof').hide()", frames * frameRate);
      }
    }
};

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
	   	$('#edit-'+region.id).val(ids);
	  });

	  if(!$("#scholarforms_save_warning").length && event) $("#vsite-layout-layoutsettings").before($('<div id="scholarforms_save_warning" class="messages error">(Your changes have not yet been saved. Click "Save Settings" for your changes to take effect)</div>'));
};

function scholarlayout_catchchanges() {
	if(!$("#scholarforms_save_warning").length || confirm("Your changes have not been saved.  Continue and loose your changes?")) return true;

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


//    $("").sortable({
//      connectWith: layoutRegions,
//      stop: scholarlayout_afterdrag
//    });
}