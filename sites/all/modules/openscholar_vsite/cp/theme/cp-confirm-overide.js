Drupal.behaviors.cp_confirm_overide_handler = function (context) {
		var s_urls = "";
		var s_container = $("div#cp-content").length ? "div#cp-content":"div#container";
		var links = $(s_container+" a:not(.cp_confirm_overide_handler-processed)");
		links.addClass('cp_confirm_overide_handler-processed');
		links.each(function(){
			var url = $(this).attr('href');
			if (typeof (url) == 'string') {
			  if (url.indexOf('/') == 0) {
				url = url.replace(Drupal.settings.basePath, '');
			  }
			  s_urls += "paths[]="+url+"&";
			}
		});

		//Make call to check the urls to replace
		if(s_urls.length) cp_override_url_check(s_urls);

//		var confirm = new Array();
//		$(s_container+" a.cp-confirm:not(.cp_overide_checked)").each(function(){
//			$(this).addClass('cp_overide_checked');
//			confirm[$(this).attr('href')] = true;
//		});
//		cp_overide_add_click(confirm);
}

var cp_overide_add_click = function(return_value){
	cp_override_processing_ajax = false;

	var s_container = $("div#cp-content").length ? "div#cp-content":"div#container";
	for (var href in return_value.overideable_settings) {
		if(return_value.overideable_settings[href]){
			cp_add_dialog();

			if (href.indexOf('http:') == -1) {
				href = Drupal.settings.basePath + href;
			}
			href = href.replace(href.substr(href.indexOf('?')), '');
			var selector = s_container+' a[href*='+href.replace(/([#;&,\.\+\*\~':"\!\^$\[\]\(\)=>\|])/g, "\\$1")+']';
			$(selector).click(function(event){
			  if(!$('#cp_confirm_dialog').dialog('isOpen')){
				  var link = $(this);
				  $('#cp_confirm_dialog span').html(link.html()+". Are you sure?");
				  $('#cp_confirm_dialog').dialog('option' , 'buttons' ,{
		 			'Yes I\'m Sure': function() {
					  $(this).dialog('close');
					  window.location = link.attr('href');
					},
					'Cancel': function() {
					  $(this).dialog('close');
					}});
				  $('#cp_confirm_dialog').dialog('open');

				  if($('div.ui-dialog-overlay').length && $('div.ui-dialog-overlay').width() && !$('div.ui-dialog-overlay').height()){
					  $('div.ui-dialog-overlay').height(1000);
				  }//If jquery fails to set the height lets do it for them
				  return false;
			  }
		  });
		}
	}
};

var cp_add_dialog = function(){
	if(!$('#cp_confirm_dialog').length){
		$('<div id="cp_confirm_dialog" title="Please Confirm"><p>Are you sure?</p></div>').appendTo("body");
		$('#cp_confirm_dialog').dialog({
 			bgiframe: true,
 			resizable: false,
 			draggable: false,
 			width: 468,
 			height:185,
 			position:top,
 			modal: true,
 			autoOpen: false,
 			//show:'slide',
 			//hide: 'slide',
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
};

var cp_override_processing_ajax = false;
//Make the AJAX call to check the urls
var cp_override_url_check = function(s_urls){
	if(cp_override_processing_ajax) return;
	cp_override_processing_ajax = true;
	var vsite = Drupal.settings.og.group_context.title;
	var url = 'http://'+location.host+Drupal.settings.basePath+vsite+'/cp/allow_callback_override';
	$.ajax({
	   type: "POST",
	   url: url,
	   dataType: 'json',
	   data: s_urls+"js=1",
	   success: cp_overide_add_click
    });
};

function cp_override_getEventTarget(e) {
  e = e || window.event;
  return e.target || e.srcElement;
}