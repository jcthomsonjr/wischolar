Drupal.VsiteTaxonomy = Drupal.VsiteTaxonomy || {};

Drupal.VsiteTaxonomy.Rename = function(){
	var newTerm = prompt('new name');
    if (newTerm == null){
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
	//alert($(this).attr('href'));
	return false;
}

Drupal.VsiteTaxonomy.Add = function(){
	var newTerm = prompt('new name');

	var dest = $(this).attr('href');
	newDest =  dest + '/' + newTerm;
	
	$(this).attr('href',newDest);
	//alert($(this).attr('href'));
	return false;
}

Drupal.behaviors.vsitetaxonomy = function(context) {
  $('.tax-edit').click(function(){
	  
  });
  
  var rename_link = $('ul.admin a.edit:not(.vsitetaxonomy-processed)', context);
  var dest = rename_link.attr('href');	

  rename_link.click(Drupal.VsiteTaxonomy.Rename);
  rename_link.click(Drupal.CTools.AJAX.clickAJAXLink);
  
  var add_link = $('a.add:not(.vsitetaxonomy-processed)', context);

  add_link.click(Drupal.VsiteTaxonomy.Add);
  add_link.click(Drupal.CTools.AJAX.clickAJAXLink);
}

/*
Drupal.behaviors.VocabEdit = function(context){
  $('ul.admin').hide();
  
  $('.tax-edit:not(.vocabedit-processed)', context)
  .addClass('vocabedit-processed')
  .click(function(){
	  $(this).parent().parent().find('ul.admin').toggle();
	  return false;
  });	
}
*/