if (Drupal.jsEnabled) {
  $(document).ready(function() {
    $('#scholarcp-settings-theme #scholarcp-settings-form ').hide();
    
    var theList = '<ul class = "theme-picker">';
    
    function getLi(liId, liChecked, liContent){
    	return '<li class = "item-theme-picker  ' + liChecked + '" id="' + liId  + '">' + liContent + '</li>';
    	
    }
    $('#scholarcp-settings-form .form-radios .form-item').each(function(){
    	var liId = $(this).attr('id');
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
    
  });
}
