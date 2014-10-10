$(document).ready(function() {	 
	var tn1 = $('.mygallery').tn3({
		skinDir:"/images/tn3",
		autoplay:true,
		width:760,
		delay:5000,
		skin:"tn3e",
		imageClick:"url",
		image:{
			crop:true,
			transitions:[{
				type:"slide",
				duration:430,
				easing:"easeInOutExpo"}]
		}
	});
});