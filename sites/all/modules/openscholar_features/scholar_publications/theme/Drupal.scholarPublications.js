
Drupal.behaviors.scholarPublications = function() {
	
	if($('div#biblio-authors-wrapper').length){
		scholarPublicationsMonitorAuthors();
	}
};

scholarPublicationsMonitorAuthors  = function() {
  
  $('div#biblio-authors-wrapper input:text:last').change(function(){
    if($(this).val() && !$(this).hasClass('no-more-authors') && !$(this).next('div#biblio-authors-wrapper input:text').length){
      $(this).addClass('no-more-authors');
      window.setTimeout('$("input#edit-contributors1-wrapper-biblio-authors-more").mousedown();', 200);
	}
  });
  
  $('div#biblio-secondary-authors-wrapper input:text:last').change(function(){
    if($(this).val() && !$(this).hasClass('no-more-authors') && !$(this).next('div#biblio-secondary-authors-wrapper input:text').length){
      $(this).addClass('no-more-authors');
      window.setTimeout('$("input#edit-contributors2-wrapper-biblio-secondary-authors-more").mousedown();', 200);
    }
  });
};
