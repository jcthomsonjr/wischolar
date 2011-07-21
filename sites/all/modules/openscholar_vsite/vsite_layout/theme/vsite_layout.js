Drupal.behaviors.scholarlayout = function() {
  var layoutRegions = [ "#scholarlayout-header-left", "#scholarlayout-header-main", "#scholarlayout-header-right", "#scholarlayout-navbar", "#scholarlayout-left", "#scholarlayout-right", "#scholarlayout-footer" ];

  scholarlayout_add_sortable(layoutRegions);

  if (!scholarlayout_change_bound) {
    scholarlayout_change_bound = true;

    $('#cp-settings-form').submit(function() {
      scholarlayout_afterdrag(null, null);
      return true;
    });

    $("#edit-page-type").bind('change', function(e) {
      if (scholarlayout_catchchanges()) {
        $('#edit-secret-hidden-ahah').val($("#edit-page-type").val());
        $('#edit-secret-hidden-ahah').trigger('go_ahah');
        $("#edit-page-type").trigger('go_ahah');
        $("#scholarforms_save_warning").remove();
        scholarlayout_add_sortable(layoutRegions);
      } else {
        // revert
        $('#edit-page-type').val($("#edit-secret-hidden-ahah").val());
      }
    });

    $(window).resize(function() {vsite_layout_setScrollArrows();});
  }
  scholarlayout_add_removal_hooks();
  vsite_layout_setScrollArrows();
  vsite_layout_setExceptionScroller();
  vsite_layout_setWidgetAutoWidth();

  /**
   * jons developmental section. work in progress.
   * 
   * instead of shaun's approach, I'm stretching the width of the widget
   * container, but putting that in a 100% width container. now I can use the
   * browser's own scrolling features instead of something hacked together.
   * 
   */
  $('dl#scholarlayout-top-widgets').parent().width('100%');
  $('dl#scholarlayout-top-widgets').wrap('<div id="widget-wrapper"></div>');
  $('#widget-wrapper').css('overflow-x', 'hidden');
  
  // 31px of css padding? shoudl generate from code
  var widget_width = 31 + $('dl#scholarlayout-top-widgets>dd:first').width();
  
  // 1 extra widget's worth of padding, so you can scroll past the last widget
  // and see that it's the end
  var widget_count = 1 + $('dl#scholarlayout-top-widgets>dd:not(.disabled)').length;
  
  // shaun was correct to recalibrate width periodically. each time a dd pops,
  // bar gets a new width.
  $('dl#scholarlayout-top-widgets').width(widget_width * widget_count);
  
  
  
  var speed = '300'; // ms. jq.fast is 200 and jq.slow is 600
  // 31px of css padding? shoudl generate from code
  var widget_width = 31 + $('dl#scholarlayout-top-widgets>dd:first').width();

  $('div.widget-prev').click(function() {
    var s = $('#widget-wrapper').scrollLeft() - widget_width;
    s -= s % widget_width; // snap to edge of widget
    $('#widget-wrapper').animate({scrollLeft:s}, speed)
  });

  $('div.widget-next').click(function() {
    var s = $('#widget-wrapper').scrollLeft() + widget_width;
    s -= s % widget_width; // snap to edge of widget
    $('#widget-wrapper').animate({ scrollLeft:s}, speed)
  });
};

function scholarlayout_add_removal_hooks() {
  $(".close-this:not(.close-this-processed)").addClass('close-this-processed')
  .click(function(e) {
    var parent = $(this).parent("dd");
    $("body").append("<div class='poof'></div>");

    // set the x and y offset of the poof animation <div> from cursor
    // position (in pixels)
    var xOffset = 24;
    var yOffset = 24;

    $('.poof').css({
      left : e.pageX - xOffset + 'px',
      top : e.pageY - yOffset + 'px'
    }).show(); // display the poof <div>
    animatePoof(); // run the sprite animation

    parent.appendTo("#scholarlayout-top-widgets");
    scholarlayout_afterdrag(e, null);

    parent.fadeIn('fast');
  });
}

var scholarlayout_change_bound = false;

function scholarlayout_afterdrag(event, ui) {
	var item = $(this);
	//console.log(item);
	console.log(ui.item.attr('id'));
  var regions = $("#scholarlayout-container > .scholarlayout-widgets-list");
  $.each(regions, function(i, region) {
    var items = $("#" + region.id + " > .scholarlayout-item");
    var ids = "";
    $.each(items, function(i, value) {
      if (ids.length) {
        ids += "|";
      }
      ids += value.id;
    });
    $('#edit-' + region.id).val(ids);
    console.log(ids);
  });

  // Reset top box after widgets have been moved
  vsite_layout_setScrollArrows();

  // Reset widget widths
  vsite_layout_setWidgetAutoWidth();

  if (!$("#scholarforms_save_warning").length && event) {
    $("#cp-settings-layout").before(
        $('<div id="scholarforms_save_warning" class="warning"><span class="warning tabledrag-changed">*</span> Your changes have not yet been saved. Click "Save Settings" for your changes to take effect</div>')
    );
  }
};

function scholarlayout_catchchanges() {
  if (!$("#scholarforms_save_warning").length 
      || confirm("Your changes have not been saved. Continue and lose your changes?")) {
    return true;
  }    
  return false;
};

function scholarlayout_add_sortable(layoutRegions) {
  var allRegions = layoutRegions.slice();
  allRegions[allRegions.length] = "#scholarlayout-top-widgets";
  $.each(allRegions, function(i, value) {
    $(value).sortable({
      connectWith : allRegions,
      stop : scholarlayout_afterdrag,
      tolerance : 'pointer',
      over : function(event, ui) {$(event.target).addClass('active');},
      out : function(event, ui) {$(event.target).removeClass('active');}
    });
  });
}

// The jQuery Poof Effect was developed by Kreg Wallace at The Kombine Group,
// Inc. http://www.kombine.net/

function animatePoof() {
  var bgTop = 0; // initial background-position for the poof sprit is '0 0'
  var frames = 5; // number of frames in the sprite animation
  var frameSize = 32; // size of poof <div> in pixels (32 x 32 px in this example)
  var frameRate = 80; // set length of time each frame in the animation will
                      // display (in milliseconds)

  // loop through amination frames
  // and display each frame by resetting the background-position of the poof
  // <div>
  for (i = 1; i < frames; i++) {
    $('.poof').animate({backgroundPosition : '0 ' + (bgTop - frameSize) + 'px'}, frameRate);
    bgTop -= frameSize; // update bgPosition to reflect the new
                        // background-position of our poof <div>
  }

  // wait until the animation completes and then hide the poof <div>
  setTimeout("$('.poof').remove()", frames * frameRate);
}


function vsite_layout_setScrollArrows(){ 
    var nContainerWidth = $('#scholarlayout-top-widgets').parent().width();
    var nWidgetWidth = 31 + $('#scholarlayout-top-widgets dd:first').width();
    var nAllWidgetsWidth = ($('#scholarlayout-top-widgets dd:not(.disabled)').length) * nWidgetWidth;
    var scholarlayout_widgets_scroling = false;

    if(nContainerWidth > nAllWidgetsWidth){ 
        $('div.widget-prev, div.widget-next').addClass('disabled').unbind('click');

    } else { 
        $('div.widget-prev, div.widget-next').removeClass('disabled');
/*
        var keep_scroling_prev = false; 
        $('div.widget-prev').mousedown(function() {
                if(scholarlayout_widgets_scroling) return false;

                scholarlayout_widgets_scroling = keep_scroling_prev = true;
                $('#scholarlayout-top-widgets').prepend($('#scholarlayout-top-widgets dd:last')).css('marginLeft',"-"+nWidgetWidth+"px").width('125%');
                $('#scholarlayout-top-widgets').animate({ marginLeft: "0px", width: "110%" }, 750, function() { 
                    scholarlayout_widgets_scroling = false;
                    if(keep_scroling_prev && $('div.widget-prev:hover').length)
                    $('div.widget-prev').mousedown(); 
                }); 
        });

        $('div.widget-prev').mouseup(function() { keep_scroling_prev = false; });

        var keep_scroling_next = false; 
        $('div.widget-next').mousedown(function() {
                if(scholarlayout_widgets_scroling) return false;

                scholarlayout_widgets_scroling = keep_scroling_next = true;
                $('#scholarlayout-top-widgets').animate({ marginLeft: "-"+nWidgetWidth+"px", width: "125%" }, 750, function() {
                    $('#scholarlayout-top-widgets').append($('#scholarlayout-top-widgets dd:first')).css('marginLeft','0px').width('110%');
                    scholarlayout_widgets_scroling = false;
                    if(keep_scroling_next && $('div.widget-next:hover').length) $('div.widget-next').mousedown(); 
            }); 
        });
        $('div.widget-next').mouseup(function() { keep_scroling_next = false; });
        */ 
    } 
}


 // Horizontal Sliding Exceptions
function vsite_layout_setExceptionScroller() {

  $('span.toggle-exceptions').click(function() {
    $(this).siblings('div.layout-exceptions').stop().animate({
      right : '-20px'
    }, {
      queue : false,
      duration : 300
    });
  });

  $('div.layout-exceptions').click(function() {
    $(this).stop().animate({
      right : '-101%'
    }, {
      queue : false,
      duration : 300
    });
  });

}
// sets widget container width.  this changes each time a widget comes out of the available widgets list.
function vsite_layout_setWidgetAutoWidth() {
  // 31px of css padding? shoudl generate from code
  var widget_width = 31 + $('dl#scholarlayout-top-widgets>dd:first').width();
  var widget_count = 1 + $('dl#scholarlayout-top-widgets>dd:not(.disabled)').length; //1 extra for padding.  shows user they're at end of list.  
  var new_width = widget_width*widget_count;
  var _scrolled = $('#widget-wrapper').scrollLeft(); //this will be restored later, after width change

  $('dl#scholarlayout-top-widgets').width(new_width);
  $('#widget-wrapper').scrollLeft(_scrolled); //otherwise scroller goes back to 0.
}
