if (Drupal.jsEnabled) {
  $(document).ready(function() {
    $('#scholarcp-settings-theme .form-radios ').hide();

    var theList = '<ul class = "theme-picker">'; // important, RSC depend on it
    
    function getLi(liId, liChecked, liContent){
    	return '<li class = "item-theme-picker  ' + liChecked + '" id="' + liId  + '">' + liContent + '</li>';
    	
    }
    $('#scholarcp-settings-form .form-radios .form-item').each(function(){
    	var liIdArr = $(this).attr('id').split('-');
    	var liId = liIdArr[3] + '-' + liIdArr[4] + '-' + liIdArr[5];
    	var liChecked = $(this).find('input').attr('checked') ? 'checked' : '';

    	// get the whole img div
    	var liContent = $(this).find('.item-theme-picker').html();

    	theList = theList + getLi(liId, liChecked, liContent);
    });
    
    theList = theList + '</ul>';
    
    theList = theList + '<div id="prev"></div>';
    theList = theList + '<div id="next"></div>';
    
    
    $('#scholarcp-settings-theme').prepend(theList);
    
    
    $('div#prev, div#next').RSC();
    
    $('li.item-theme-picker').click(function(){
    	// remove the active class from every li first
    	$(".item-theme-picker").removeClass('checked');
    	// add the class to this one
    	$(this).addClass('checked');
    	
    	var id = $(this).attr('id');
    	$(".form-radio").removeAttr("checked");
    	$("#edit-settings-theme-" + id).attr("checked", "checked"); 
    });
    
  });
}
