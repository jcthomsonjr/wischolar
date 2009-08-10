Drupal.behaviors.scholarforms = function (context){
  
  $('div#edit-pubdate-wrapper').hide();	
  
  $('input#edit-pubstatus-pubondate', context).click(function(){
		$('div#edit-pubdate-wrapper').fadeIn('fast');	
  });

	  $('input#edit-pubstatus-save', context).click(function(){
		$('div#edit-pubdate-wrapper').fadeOut('fast');
			
	});
	
	  $('input#edit-pubstatus-publish', context).click(function(){
		$('div#edit-pubdate-wrapper').fadeOut('fast');
	});

}
