  //Javascript to manipulate the Areas of Interest block on Garys Home Page
$(document).ready(function(){
  $('#block-iqss_gking-areas_of_research .col dt span').hover(function() {
	//window.clearTimeout(timer_block_iqss_gking_areas_of_research);
	$('#block-iqss_gking-areas_of_research .bg').remove();
	$('#block-iqss_gking-areas_of_research dt.active').removeClass('active');
	$('#block-iqss_gking-areas_of_research dd').fadeOut(180);
	$('#block-iqss_gking-areas_of_research .more').hide();
	  
    $(this).after('<div class="bg"></div>');
    $(this).parent('dt').addClass('active');
    $(this).children('.more').fadeIn("fast");
    $(this).parent('dt').next('dd').fadeIn(820);
  }, function() {
    
    //window.clearTimeout(timer_block_iqss_gking_areas_of_research);
    //timer_block_iqss_gking_areas_of_research = window.setTimeout(iqss_gking_areas_of_research_load_next, 9000);
  });
  iqss_gking_areas_of_research_load_next();
  var timer_block_iqss_gking_areas_of_research = window.setInterval(iqss_gking_areas_of_research_load_next, 9000);
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