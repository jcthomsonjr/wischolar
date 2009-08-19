(function($){  
 $.fn.cpSlidingContainer = function(options) {  
  
  var defaults = {  
    prevImageID: "#prev",
    nextImageID: "#next",
    containerW: 50,
    duration: 1000,
    mainListClass: '',
    listItemClass: '',
    navClass: '' 
  };  
  var options = $.extend(defaults, options);  
  var currentIndex = 0;
  var noOfContainer = $("li."+options.listItemClass).length;
  
  var jumpLinkIndex = 0;
  return this.each(function() {  
    var obj = $(this);
    
    switch(obj.attr('id')){
      case options.prevImageID.replace("#",""):
    	  obj.click(function(){
    	    currentIndex++;
    	    if(currentIndex > 0) currentIndex = (0-(noOfContainer)) + 1;
    	    
    	    $("ul."+options.mainListClass).animate({marginLeft: currentIndex * options.containerW +"px"}, options.duration);
    	    $("."+options.navClass+" li" ).removeClass('active');
    		$("."+options.navClass+" li:eq("+(currentIndex*-1)+")" ).addClass('active');
    	    $("."+options.listItemClass).removeClass('active');
    	    $("."+options.listItemClass+":eq("+(currentIndex*-1)+")").addClass('active');
    	    return false;
    	  });
      break;
      case options.nextImageID.replace("#",""):
    	  obj.click(function(){
	        currentIndex--;
	        if(currentIndex < (0-(noOfContainer-1))) currentIndex=0;
	        
	        $("ul."+options.mainListClass).animate({marginLeft: currentIndex * options.containerW +"px"}, options.duration);
		    $("."+options.navClass+" li" ).removeClass('active');
			$("."+options.navClass+" li:eq("+(currentIndex*-1)+")" ).addClass('active');
		    $("."+options.listItemClass).removeClass('active');
		    $("."+options.listItemClass+":eq("+(currentIndex*-1)+")").addClass('active');
		    return false;
    	  });
      break;   
      default:
    	 obj.bind("click", {index:jumpLinkIndex} , function(e){
  			$("ul."+options.mainListClass).animate({marginLeft: e.data.index * options.containerW *-1+"px"},options.duration);
  			$("."+options.navClass+" li" ).removeClass('active');
  			$("."+options.navClass+" li:eq("+ e.data.index +")" ).addClass('active');
  			$("."+options.listItemClass).removeClass('active');
  			$("."+options.listItemClass+":eq("+ e.data.index +")").addClass('active');
  			currentIndex = -1* e.data.index;
  			
  			return false;
  		});
        if($("li."+options.listItemClass+":eq("+ jumpLinkIndex +")").hasClass('checked')){
          obj.click();	
        }
        jumpLinkIndex++;
      break;
    }
  });  
 };  
})(jQuery);
