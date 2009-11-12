Drupal.behaviors.cp_node_forms = function (context){

  $('input#edit-pubstatus-2', context).click(function(){
		$('div#edit-pubdate-wrapper').fadeIn('fast');	
		 $('div#pubdate').removeClass('hide-puboption');  
  });

	  $('input#edit-pubstatus-0', context).click(function(){
		$('div#edit-pubdate-wrapper').fadeOut('fast');
		 $('div#pubdate').addClass('hide-puboption');  
			
	});
	
	  $('input#edit-pubstatus-1', context).click(function(){
		$('div#edit-pubdate-wrapper').fadeOut('fast');
		 $('div#pubdate').addClass('hide-puboption');  
	});

}
