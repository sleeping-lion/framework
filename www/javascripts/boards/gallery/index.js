$(document).ready(function() {	
	$('#sl_gallery_right li a').hover(function(){
		$(this).find('img').stop().animate({opacity:'0.8',width:'120%', height:'120%', marginTop:'-10%', marginLeft:'-10%'},400);
	},function(){
		$(this).find('img').stop().animate({opacity:'1',width:'100%', height:'100%', marginTop:'0%', marginLeft:'0%'},400);
	});
	
	$("#sl_gallery_left  span").css({opacity:'0.8'});
	$("#sl_gallery_right li a").click(clickThumbnail);
	
	//Fancybox for image gallery
	$("a.simple_image").fancybox({
			'opacity'		: true,
			'overlayShow'	       : true,
			'overlayColor': '#000000',
			'overlayOpacity'     : 0.9,
			'titleShow':true,
			'transitionIn'	: 'elastic',
			'transitionOut'	: 'elastic'
	});	
	
	function clickThumbnail(){
		$("#sl_gallery_left span").text($(this).attr('title')).css('bottom',-30);
		$("#sl_gallery_left img").attr('src',$(this).attr('href')).animate({ opacity: "1" }, 400,function(){	$("#sl_gallery_left span").animate({bottom:5,opacity:'0.8'},400);});
		/*
		$("#sl_gallery_left li span").css({'opacity':0,'bottom':'-30px'});
		*/
		return false;
	}	
});