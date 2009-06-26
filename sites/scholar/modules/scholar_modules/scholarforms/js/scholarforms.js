

Drupal.behaviors.scholarforms = function (context){
  
  $('div#edit-pubdate-wrapper').hide();	
  
  $('input#edit-pubstatus-saveondate', context).click(function(){
		$('div#edit-pubdate-wrapper').fadeIn('fast');	
  });

	  $('input#edit-pubstatus-save', context).click(function(){
		$('div#edit-pubdate-wrapper').hide();
			
	});
	
	  $('input#edit-pubstatus-publish', context).click(function(){
		$('div#edit-pubdate-wrapper').hide();	
	});

}
