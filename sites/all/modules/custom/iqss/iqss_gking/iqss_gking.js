  //Javascript to manipulate the Areas of Interest block on Garys Home Page
$(document).ready(function(){


  $('#block-iqss_gking-areas_of_research .col dt span').hover(function() {
    //Rem 1 for Sticky
	window.clearTimeout(timer_block_iqss_gking_areas_of_research);
  //$(this).parents('.col').siblings('.col').queue("fx",[]);
	$('#block-iqss_gking-areas_of_research .bg').remove();
	$('#block-iqss_gking-areas_of_research dt.active').removeClass('active');
	$('#block-iqss_gking-areas_of_research dd').fadeOut(180);
	$('#block-iqss_gking-areas_of_research .more').hide();
    $(this).after('<div class="bg"></div>');
    $(this).parent('dt').addClass('active');
    $(this).children('.more').fadeIn("fast");
    $(this).parent('dt').next('dd').fadeIn(820);
    $(this).parents('.col').siblings('.col').css({'opacity':.3});
  }, function() {
   $(this).parents('.col').siblings('.col').css({'opacity':1});
    //Rem if for stickey
	//if($('#block-iqss_gking-areas_of_research .col dt span').index($(this)) != 0){
	  // Use This if you want hover
	  //$(this).next('.bg').remove();
	  //$(this).parent('dt').removeClass('active');
	  //$(this).children('.more').fadeOut("fast");
	  //$(this).parent('dt').next('dd').fadeOut(180);

	  //Select First code
	  //window.setTimeout(iqss_gking_areas_of_research_load_next, 290);
	//}
  });
  iqss_gking_areas_of_research_load_next();
  //var timer_block_iqss_gking_areas_of_research = window.setInterval(iqss_gking_areas_of_research_load_next, 9000);
  var timer_block_iqss_gking_areas_of_research = null;
});

 false;
function iqss_gking_areas_of_research_load_next(){
	if($('#block-iqss_gking-areas_of_research .col dt span:hover').length) return;

	var next_el = false;
	var found_active = false;
	$('#block-iqss_gking-areas_of_research .col dt span').each(function(index) {
		if(!next_el) next_el = $(this);
		if(found_active){
			next_el = $(this);
			found_active = false;
		}

		if($(this).parent('dt').hasClass('active')) found_active = true;
	});
	next_el.hover();
}