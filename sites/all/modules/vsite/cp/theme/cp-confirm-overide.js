if(Drupal.jsEnabled){
	$(document).ready(function(){
		var s_urls = "";
		$("div#cp-content a").each(function(){
			s_urls += "paths[]="+$(this).attr('href')+"&";
		});
		
		//Make call to check the urls to replace
		$.ajax({
		   type: "POST",
		   url: location.pathname.substring(0,location.pathname.indexOf('/',1))+"/cp/allow_callback_override",
		   dataType: 'json',
		   data: s_urls+"js=1",
		   success: cp_overide_add_click,
		});
	});
}

var cp_overide_add_click = function(return_value){
	for ( href in return_value.overideable_settings) { 
		if(return_value.overideable_settings[href]){
			if(!$('#cp_confirm_dialog').length){
				$('<div id="cp_confirm_dialog" title="Please Confirm"><p><span class="ui-icon ui-icon-alert" style="float:left; margin:0 7px 20px 0;">Are you sure?</span></p></div>').appendTo("body");
				$('#cp_confirm_dialog').dialog({
		 			bgiframe: true,
		 			resizable: false,
		 			height:140,
		 			modal: true,
		 			autoOpen: false,
		 			//hide: 'slide',
		 			overlay: {
		 				backgroundColor: '#000',
		 				opacity: 0.5
		 			},
		 			buttons: {
		 				'Yes I\'m Sure': function() {
		 					$(this).dialog('close');
		 				},
		 				'Cancel': function() {
		 					$(this).dialog('close');
		 				}
		 			}
		 		  });
			}
			
			$("div#cp-content a[href^=\""+href.replace(/([#;&,\.\+\*\~':"\!\^$\[\]\(\)=>\|])/g, "\\$1")+"\"]").click(function(){
			  var link = $(this);
			  $('#cp_confirm_dialog span').html(link.html()+"<br />Are you sure?");
			  $('#cp_confirm_dialog').dialog('option' , 'buttons' ,{
	 			'Yes I\'m Sure': function() {
					$(this).dialog('close');
					window.location = link.attr('href');
				},
				'Cancel': function() {
					$(this).dialog('close');
				}});
			  $('#cp_confirm_dialog').dialog('open');
			  return false;
			});
			
			//Make sure to escape the url for the selector
		}
	}
};