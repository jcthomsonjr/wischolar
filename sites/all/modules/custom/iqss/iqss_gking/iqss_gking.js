//Javascript to manipulate the Areas of Interest block on Garys Home Page
$(document).ready(function(){
	
  iqss_gking_research_group_tabify();

  $('#block-iqss_gking-areas_of_research .col dt span').hover(function() {
    //Rem 1 for Sticky
	window.clearTimeout(timer_block_iqss_gking_areas_of_research);
  //$(this).parents('.col').siblings('.col').queue("fx",[]);
	//$('#block-iqss_gking-areas_of_research .bg').remove();
	$('#block-iqss_gking-areas_of_research dt.active').removeClass('active');
	$('#block-iqss_gking-areas_of_research dd').fadeOut('fast');
	$('#block-iqss_gking-areas_of_research .more').hide();
    //$(this).after('<div class="bg"><\/div>');
    $(this).parent('dt').addClass('active');
    //$(this).children('.more').fadeIn("fast");
    $(this).parent('dt').next('dd').fadeIn('fast');

  });
  
  iqss_gking_areas_of_research_load_next();
  //var timer_block_iqss_gking_areas_of_research = window.setInterval(iqss_gking_areas_of_research_load_next, 9000);
  var timer_block_iqss_gking_areas_of_research = null;
  
  
});

function iqss_gking_areas_of_research_load_next(){
  if($('#block-iqss_gking-areas_of_research .col dt span:hover').length ||
    !$('#block-iqss_gking-areas_of_research').length) return;

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

function iqss_gking_research_group_tabify(){
	if(!$('body.page-iqss-gking-research-group').length) return;
	
	$("<ul id='research-group-tablist' class=\"ui-tabs-nav\"></ul>").insertBefore("div#content-main div.taxonomy-term-child:first");
	$('div#content-main div.taxonomy-term-child').each(function(index) {
	  $(this).attr("id","research_group_tab_"+index);
	  if(index > 0) $(this).hide();
	  
	  $('ul#research-group-tablist').append("<li class='research_group_tab'><a href='#research_group_tab_"+index+"'>"+$(this).find('h3.taxonomy-heading').html()+"</a></li>");
	});
	
	$("#content").tabs({ fx: { opacity: 'toggle' } });

}