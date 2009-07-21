Drupal.behaviors.citedistribute = function (context){
  
  $('form#cite-distribute-form').hide();	
  
  $('a#cite-distribute-link-title', context).click(function(){
		$('form#cite-distribute-form').slideToggle('slow');	
  });

}
