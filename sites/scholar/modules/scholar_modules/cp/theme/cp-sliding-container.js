(function($){  
 $.fn.cpSlidingContainer = function(options) {  
  
  var defaults = {  
    prevImageID: "#prev",
    nextImageID: "#next",
    containerW: 50,
    duration: 1000,
    mainListSelector: '',
    listItemClass: '',
    listItemSelector: '', //optional
    navClass: '',
    changeObject: false
  };  
  var options = $.extend(defaults, options);  
  var currentIndex = 0;
  var noOfContainer = $("li."+options.listItemClass).length;
  if(options.listItemSelector){
	  noOfContainer = $(options.listItemSelector).length - 1;
  }
  
  var jumpLinkIndex = 0;
  return this.each(function() {  
    var obj = $(this);
    
    switch(obj.attr('id')){
      case options.prevImageID.replace("#",""):
    	  obj.click(function(){
    	    currentIndex++;
    	    if(currentIndex > 0) currentIndex = (0-(noOfContainer)) + 1;
    	    
    	    $(options.mainListSelector).animate({marginLeft: currentIndex * options.containerW +"px"}, options.duration);
    	    $("."+options.navClass+" li" ).removeClass('active');
    		$("."+options.navClass+" li:eq("+(currentIndex*-1)+")" ).addClass('active');
    	    $("."+options.listItemClass).removeClass('active');
    	    $("."+options.listItemClass+":eq("+(currentIndex*-1)+")").addClass('active');
		    if(options.changeObject) options.changeObject.trigger('indexChanged',{index:currentIndex});
    	    return false;
    	  });
      break;
      case options.nextImageID.replace("#",""):
    	  obj.click(function(){
	        currentIndex--;
	        if(currentIndex < (0-(noOfContainer-1))) currentIndex=0;
	        
	        $(options.mainListSelector).animate({marginLeft: currentIndex * options.containerW +"px"}, options.duration);
		    $("."+options.navClass+" li" ).removeClass('active');
			$("."+options.navClass+" li:eq("+(currentIndex*-1)+")" ).addClass('active');
		    $("."+options.listItemClass).removeClass('active');
		    $("."+options.listItemClass+":eq("+(currentIndex*-1)+")").addClass('active');
		    if(options.changeObject) options.changeObject.trigger('indexChanged',{index:currentIndex});
		    return false;
    	  });
      break;   
      default:
    	 obj.bind("click", {index:jumpLinkIndex} , function(e){
  			$(options.mainListSelector).animate({marginLeft: e.data.index * options.containerW *-1+"px"},options.duration);
  			$("."+options.navClass+" li" ).removeClass('active');
  			$("."+options.navClass+" li:eq("+ e.data.index +")" ).addClass('active');
  			$("."+options.listItemClass).removeClass('active');
  			$("."+options.listItemClass+":eq("+ e.data.index +")").addClass('active');
  			currentIndex = -1* e.data.index;
		    if(options.changeObject) options.changeObject.trigger('indexChanged',{index:currentIndex});
  			return false;
  		});
        if($("li."+options.listItemClass+":eq("+ jumpLinkIndex +")").hasClass('checked')){
          obj.click();	
        }else{
	        if(options.listItemSelector && $(options.listItemSelector+":eq("+ (jumpLinkIndex+1) +") input").attr('checked')) {  
	        	obj.click();
	        }
        }
        jumpLinkIndex++;
      break;
    }
  });  
 };  
})(jQuery);
