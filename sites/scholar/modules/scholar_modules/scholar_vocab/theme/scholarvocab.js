Drupal.ScholarVocab = Drupal.ScholarVocab || {};

Drupal.ScholarVocab.Rename = function(){
	var newTerm = prompt('new name');
    if (newTerm == null){
    	alert('nnnnnnnnnnnnnnnn');
      return false;
    }
	newTerm = $(this).attr('href') + newTerm;

	$(this).attr('href',newTerm);
	//return false;
}

Drupal.behaviors.scholarvocab = function(context) {
	$('a.admin:not(.scholarvocab-processed)', context).addClass('scholarvocab-processed').click(Drupal.ScholarVocab.Rename).click(Drupal.CTools.AJAX.clickAJAXLink);
}