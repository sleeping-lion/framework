

jQuery(function($){
 var layerWindow = $('.mw_layer');
 var layer = $('#layer');
 // Show Hide
 $('.layer_trigger').click(function(){
  layerWindow.addClass('open');
 });
 $('.close').click(function(){
  layerWindow.removeClass('open');
 });
 // ESC Event
 $(document).keydown(function(event){
  if(event.keyCode != 27) return true;
  if (layerWindow.hasClass('open')) {
   layerWindow.removeClass('open');
  }
  return false;
 });
 // Hide Window
 layerWindow.find('>.bg').mousedown(function(event){
  //layerWindow.removeClass('open');
  return false;
 });
 layerWindow.addClass('open');
});

//GNB
 $(document).ready(function() {
		$(".gnb-sub").css({display: "none"});
 var useragent = navigator.userAgent;

  // IE7이 아니고 IE6일때는
	if ((useragent.indexOf('MSIE 6')>0) && (useragent.indexOf('MSIE 7')==-1))
	{
		$("ul.topmenu li").hover(function() {
			$(".gnb-sub").slideDown();
		});
		$(".gnb-sub").hover(function() {
			$(this).show();
	   
		},function(){
			//$(this).hide();
			$("#header").mouseleave(function() {
				$(".gnb-sub").hide();
			});
		})
	
	} else {	
		$("ul.topmenu li").hover(function() {
			$(".gnb-sub").slideDown(350);
		});
		$(".gnb-sub").hover(function() {
			$(this).show();
	   
		},function(){
			//$(this).slideUp(300);
			$("#header").mouseleave(function() {
				$(".gnb-sub").slideUp(350);
			});
		})		
	}
 });

//<![CDATA[
// 롤오버 1차방법
function menuOver(ele) { 
	var img = ele.getElementsByTagName("img")[0]; 
	img.src = img.src.replace(/_on\.(?=gif|jpg|png)/, "."); // default 마우스 오버 때문에 추가 2013-02-22 김정득
	img.src = img.src.replace(/\.(?=gif|jpg|png)/, "_on.");
}

function menuOut(ele) { 
	var img = ele.getElementsByTagName("img")[0]; 
	img.src = img.src.replace(/_on\.(?=gif|jpg|png)/, ".");
}
//]]>



