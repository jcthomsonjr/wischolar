//Javascript to manipulate the Areas of Interest block on Garys Home Page
Drupal.behaviors.iqss_gking = function() {

  iqss_gking_research_group_tabify();
  
  iqss_gking_taxonomy_alter_sort_links();

  $('.front #block-iqss_gking-areas_of_research .col dt span').hover(function() {
    //Rem 1 for Sticky
	window.clearTimeout(timer_block_iqss_gking_areas_of_research);

  $('.front #block-iqss_gking-areas_of_research dt.active').removeClass('active');
	$('.front #block-iqss_gking-areas_of_research dd').fadeOut('fast');
	$('.front #block-iqss_gking-areas_of_research .more').hide();

    $(this).parent('dt').addClass('active');

    $(this).parent('dt').next('dd').fadeIn('fast');

  });

  iqss_gking_areas_of_research_load_next();

  var timer_block_iqss_gking_areas_of_research = null;


};

function iqss_gking_areas_of_research_load_next(){
  if($('.front #block-iqss_gking-areas_of_research .col dt span:hover').length ||
    !$('.front #block-iqss_gking-areas_of_research').length) return;

  var next_el = false;
  var found_active = false;
  $('.front #block-iqss_gking-areas_of_research .col dt span').each(function(index) {
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

	var terms = Drupal.settings.iqss_gking.research_group_terms;
	for (var i=0;i<terms.length;i++)
	{
	  var url = "#iqss_gking_term_"+terms[i].tid;

	  $('ul#research-group-tablist').append("<li class='research_group_tab'><a href='"+url+"'>"+terms[i].name+"</a></li>");
	}


	$("#content").tabs({ fx: { opacity: 'toggle' }, cache: true, load: function(event, ui) { Drupal.behaviors.CToolsDropdown(); } });

}

function iqss_gking_taxonomy_alter_sort_links(){
	if(!$('body.page-taxonomy').length) return;
	
	$('a.term-admin-sort-link').click(function(){ window.scroll(0,0); })
}