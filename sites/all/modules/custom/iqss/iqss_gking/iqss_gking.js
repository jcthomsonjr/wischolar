//Javascript to manipulate the Areas of Interest block on Garys Home Page
$(document).ready(function(){
  iqss_gking_research_group_tabify();

  $('#block-iqss_gking-areas_of_research .col dt span').hover(function() {
    //Rem 1 for Sticky
	window.clearTimeout(timer_block_iqss_gking_areas_of_research);

	$('#block-iqss_gking-areas_of_research dt.active').removeClass('active');
	$('#block-iqss_gking-areas_of_research dd').fadeOut('fast');
	$('#block-iqss_gking-areas_of_research .more').hide();

    $(this).parent('dt').addClass('active');

    $(this).parent('dt').next('dd').fadeIn('fast');

  });
  
  iqss_gking_areas_of_research_load_next();
  
  
});

function iqss_gking_areas_of_research_load_next(){
  if(!$('#block-iqss_gking-areas_of_research').length ||
      $('#block-iqss_gking-areas_of_research .col dt span:hover').length) return;

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
	
	$("<ul id='research-group-tablist'></ul>").insertBefore("div#content-main div.taxonomy-term-child:first");
	$('div#content-main div.taxonomy-term-child').each(function(index) {
	  $(this).addClass('tab_'+index);
	  if(index > 0) $(this).hide();
	  
	  $('ul#research-group-tablist').append("<li class='research_group_tab'>"+$(this).find('h3.taxonomy-heading').html()+"</li>");
	});
	
	$('li.research_group_tab').each(function(index) {
		$(this).click(function(){
			$('body.page-iqss-gking-research-group div#content-main div.taxonomy-term-child').hide();
			$('body.page-iqss-gking-research-group div#content-main div.taxonomy-term-child:eq('+index+')').show();
		});
	});
}