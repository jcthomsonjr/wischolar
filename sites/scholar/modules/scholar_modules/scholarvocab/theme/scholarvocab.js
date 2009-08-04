Drupal.ScholarVocab = Drupal.ScholarVocab || {};

Drupal.ScholarVocab.Rename = function(){
	var newTerm = prompt('new name');
    if (newTerm == null){
    	alert('nnnnnnnnnnnnnnnn');
      return false;
    }
    var dest = $(this).attr('href');
    var slices = dest.split('/');
    
    var newDest = '';
    for (var i = 0; i < slices.length -1 ; i++ ){
    	newDest = newDest + slices[i] +  '/';
    }
    
	newDest =  newDest + newTerm;
	
	$(this).attr('href',newDest);
	return false;
}

Drupal.behaviors.scholarvocab = function(context) {
	$('ul.admin a.rename:not(.scholarvocab-processed)', context).addClass('scholarvocab-processed').click(Drupal.ScholarVocab.Rename).addClass('ctools-use-ajax');
	//click(Drupal.CTools.AJAX.clickAJAXLink);
}