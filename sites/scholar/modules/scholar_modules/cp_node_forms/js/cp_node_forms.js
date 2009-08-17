Drupal.behaviors.cp_node_forms = function (context){

  $('input#edit-pubstatus-pubondate', context).click(function(){
		$('div#edit-pubdate-wrapper').fadeIn('fast');	
		 $('div#pubdate').removeClass('hide-pubdate');  
  });

	  $('input#edit-pubstatus-save', context).click(function(){
		$('div#edit-pubdate-wrapper').fadeOut('fast');
		 $('div#pubdate').addClass('hide-pubdate');  
			
	});
	
	  $('input#edit-pubstatus-publish', context).click(function(){
		$('div#edit-pubdate-wrapper').fadeOut('fast');
		 $('div#pubdate').addClass('hide-pubdate');  
	});

}
