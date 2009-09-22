
function cp_updateLogo(c){
	    logoShowPreview(c);
		$('#edit-settings-logo-x-cord').val(c.x);
		$('#edit-settings-logo-y-cord').val(c.y);
		$('#edit-settings-logo-width').val(c.w);
		$('#edit-settings-logo-height').val(c.h);
}

if (Drupal.jsEnabled) {
  $(document).ready(function() {
	  var api = $.Jcrop('#logo_preview',{
		    aspectRatio: 1.2857,
		    minSize: [180,140],
		    onSelect: cp_updateLogo,
		    onChange: logoShowPreview,
		    allowSelect: true,
		    allowMove: true
		  });
	  
	  $('#live_preview_box_inner').css({
		width: $('#live_preview').attr('width') + 'px',
		height: $('#live_preview').attr('height') + 'px',
      });
	  
	  api.setSelect([5,5,180,140]);
	  
	  $('#edit-settings-logo-logo-upload').change(function() {
		  $('#cp-settings-form').submit();
	  });//Turns out the easiest solution is the best.
	  
	  $("#edit-submit").insertAfter("#edit-settings-logo-logo-upload").css({position:'relative', top:'0px'}).attr('value',"Upload");	  
	  $("a.edit-submit").remove();
	  
	  if($('#live_preview').attr('width') <= 180 || $('#live_preview').attr('height') <= 140){
		  $("a.edit-settings-logo-crop-btn").remove();
		  $("#live_preview_box").remove();
	  }
  });
}

function logoShowPreview(coords)
{
	var rx = parseInt($('#live_preview_box_inner').css('width')) / coords.w;
	var ry = parseInt($('#live_preview_box_inner').css('height')) / coords.h;

	$('#live_preview').attr("src", $('#logo_preview').attr('src')); 
	
	$('#live_preview').css({
		width: Math.round(rx * $('#logo_preview').attr('width')) + 'px',
		height: Math.round(ry * $('#logo_preview').attr('height')) + 'px',
		marginLeft: '-' + Math.round(rx * coords.x) + 'px',
		marginTop: '-' + Math.round(ry * coords.y) + 'px',
		overflow: 'hidden'
	});
};
