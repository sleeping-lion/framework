//window.onload = addFavorite;   //페이지 로드시 실행
		
// 글로벌 메뉴 

function toggle_MainMenuover( idx )
{
	var obj;	

	for (var z=1; z<7; z++){
		obj = document.getElementById('gms_' + z);				

		if (z == idx){			    
			obj.style.display="block";
		} else {
			obj.style.display="none";
		}
	}
	onMainMenu(idx);
	return;
}	



function setMenu(idx)
{
	for ( mg=1; mg <= 6; mg++ ) 
	{
		if ( idx != mg ) 
		{
			MM_swapImage("tmenu_" + mg ,"","/images/menu/menu"+mg+".png",1);
		}
	}
	MM_swapImage("tmenu_" + idx ,"","/images/menu/menu"+idx+"ov.png",1);
	toggle_MainMenuover2(idx);
}


function setMenu_init()
{


	var obj;	

	for (var z=1; z<=6; z++){

		MM_swapImage("tmenu_" + z ,"","/images/menu/menu"+z+".png",1);

		obj = document.getElementById('gms_' + z);				

			obj.style.display="none";
	}


}


function setsubmenu(mObj, fileNm)
{
	MM_swapImage(mObj,"","/images/menu/"+fileNm+".png",1);
}




function toggle_MainMenuover2( idx )
{
	var obj;	

	for (var z=1; z<=6; z++){
		obj = document.getElementById('gms_' + z);				

		if (z == idx){			    
			obj.style.display="block";
		} else {
			obj.style.display="none";
		}
	}
}



function onMainMenu( idx ) 
{
	for ( i=1 ; i <=6 ; i++ )
	{
		obj = document.getElementById( "gm_" + i );
		
		if ( i == idx )
		{
			if ( obj.style.backgroundImage != "url(/images/menu/menu" + i + "ov.png)")
			{
				obj.style.backgroundImage = "url(/images/menu/menu" + i + "ov.png)";
			}
		}
		else
		{
			if ( obj.style.backgroundImage != "url(/images/menu/menu" + i + ".png)")
			{
				obj.style.backgroundImage = "url(/images/menu/menu" + i + ".png)";
			}
		}

		
	}
	

}


//기본 스크립트
function MM_swapImgRestore() { //v3.0
  var i,x,a=document.MM_sr; for(i=0;a&&i<a.length&&(x=a[i])&&x.oSrc;i++) x.src=x.oSrc;
}

function MM_preloadImages() { //v3.0
  var d=document; if(d.images){ if(!d.MM_p) d.MM_p=new Array();
    var i,j=d.MM_p.length,a=MM_preloadImages.arguments; for(i=0; i<a.length; i++)
    if (a[i].indexOf("#")!=0){ d.MM_p[j]=new Image; d.MM_p[j++].src=a[i];}}
}

function MM_findObj(n, d) { //v4.01
  var p,i,x;  if(!d) d=document; if((p=n.indexOf("?"))>0&&parent.frames.length) {
    d=parent.frames[n.substring(p+1)].document; n=n.substring(0,p);}
  if(!(x=d[n])&&d.all) x=d.all[n]; for (i=0;!x&&i<d.forms.length;i++) x=d.forms[i][n];
  for(i=0;!x&&d.layers&&i<d.layers.length;i++) x=MM_findObj(n,d.layers[i].document);
  if(!x && d.getElementById) x=d.getElementById(n); return x;
}

function MM_swapImage() { //v3.0
  var i,j=0,x,a=MM_swapImage.arguments; document.MM_sr=new Array; for(i=0;i<(a.length-2);i+=3)
   if ((x=MM_findObj(a[i]))!=null){document.MM_sr[j++]=x; if(!x.oSrc) x.oSrc=x.src; x.src=a[i+2];}
}


//텝메뉴관련

function MM_showHideLayers() { //v9.0
  var i,p,v,obj,args=MM_showHideLayers.arguments;
  for (i=0; i<(args.length-2); i+=3) 
  with (document) if (getElementById && ((obj=getElementById(args[i]))!=null)) { v=args[i+2];
    if (obj.style) { obj=obj.style; v=(v=='show')?'visible':(v=='hide')?'hidden':v; }
    obj.visibility=v; }
}


function initTabMenu(tabContainerID) {
	var tabContainer = document.getElementById(tabContainerID);
	var tabAnchor = tabContainer.getElementsByTagName("a");
	var i = 0;

	for(i=0; i<tabAnchor.length; i++) {
		if (tabAnchor.item(i).className == "tab")	thismenu = tabAnchor.item(i);
		else										continue;

		thismenu.container = tabContainer;
		thismenu.targetEl = document.getElementById(tabAnchor.item(i).href.split("#")[1]);
		thismenu.targetEl.style.display = "none";
		thismenu.imgEl = thismenu.getElementsByTagName("img").item(0);
		
		if (thismenu.imgEl) {
			thismenu.onmouseover = function () {
				//this.onclick();
			}
		}
		thismenu.onclick = tabMenuClick;
		
		
		if (!thismenu.container.first)	thismenu.container.first = thismenu;
	}
	tabContainer.first.onclick();
}

function tabMenuClick() {
	currentmenu = this.container.current;
	if (currentmenu != this) {
		if (currentmenu) {
			currentmenu.targetEl.style.display = "none";
			if (currentmenu.imgEl) {
				currentmenu.imgEl.src = currentmenu.imgEl.src.replace("_on.jpg", ".jpg");
			} else {
				currentmenu.className = currentmenu.className.replace(" on", "");
			}
		}

		this.targetEl.style.display = "block";
		if (this.imgEl) {
			this.imgEl.src = this.imgEl.src.replace(".jpg", "_on.jpg");
		} else {
			this.className += " on";
		}
		this.container.current = this;
	}
	return false;
}


//============================================================================================================================

//============================================================================================================================

function imgChg(obj){
	var img = null;
	var imgName = null;
	
	
	
	if(obj != null){
		for(i=0; i<obj.childNodes.length; i++){
			if(obj.childNodes[i].nodeName == "IMG"){
				img = obj.childNodes[i];
			}
		}
	}

	if(img != null){
		imgName = img.src;
		if(imgName.indexOf("_on") > -1){
			img.src = imgName.replace(/_over\.jpg/g, ".jpg");
		}else{
			img.src = imgName.replace(/\.jpg/g, "_on.jpg");
		}
	}
}

//ex) tabOn(1,1);
moreLink = new Array(6);
moreClick = new Array(6);
for (i=0;i<6;i++) {
	moreLink[i] = new Array(6);
	moreClick[i] = new Array(6);
}
moreLink[0][0]="#null"; moreClick[0][0]=""; //
moreLink[0][1]="#null"; moreClick[0][1]=""; //
moreLink[0][2]="#null"; moreClick[0][2]=""; //
moreLink[1][0]="#null"; moreClick[1][0]=""; //
moreLink[1][1]="#null"; moreClick[1][1]=""; //
moreLink[1][2]="#null"; moreClick[1][2]=""; //
moreLink[1][3]="#null"; moreClick[1][3]=""; //


function tabOn(tabid,a) {

	for (i=1;i<=5;i++) {
		if(i<10){inn="0"+i;} else {inn=""+i;}
		tabMenu = document.getElementById("tab"+tabid+"m"+i);
		tabContent = document.getElementById("tab"+tabid+"c"+i);
		if (tabMenu) { 
			if (tabMenu.tagName=="IMG") { tabMenu.src = tabMenu.src.replace("_on.jpg", ".jpg"); } 
			if (tabMenu.tagName=="A") { tabMenu.className=""; } 
		}
		if (tabContent) { tabContent.style.display="none"; }
	}
	if(a<10){ann="0"+a;} else {ann=""+a;}
	tabMenu = document.getElementById("tab"+tabid+"m"+a);
	tabContent = document.getElementById("tab"+tabid+"c"+a);
//	alert(tabMenu.tagName);
	if (tabMenu) { 
		if (tabMenu.tagName=="IMG") { tabMenu.src = tabMenu.src.replace(".jpg", "_on.jpg"); } 
		if (tabMenu.tagName=="A") { tabMenu.className="on"; } 
	}
	if (tabContent) { tabContent.style.display="block"; }
	tabMore = document.getElementById("tab"+tabid+"more");
}

/*png ie 6.0적용

        function setPng24(obj) {
            obj.width = obj.height = 1;
            obj.className = obj.className.replace(/\bpng24\b/i, '');
            obj.style.filter =
        "progid:DXImageTransform.Microsoft.AlphaImageLoader(src='" + obj.src + "',sizingMethod='image');"
            obj.src = '';
            return '';
        }*/



/*이미지 롤오버*/

//<![CDATA[
function menusOver(ele , pcode) {
	var eleWrap = document.getElementById(ele);
	var alink = eleWrap.getElementsByTagName("A");

	for (i=0; i<alink.length; i++) {
	
		if(alink[i].getElementsByTagName("img").length == 0) continue;		
		if(alink[i].getElementsByTagName("img")[0].src.indexOf("_on.") != -1 ) continue;	
		

		
			subImage = alink[i].getElementsByTagName("img")[0];

			if(getLeftMenuOn ( subImage.name , pcode) ) {
				subImage.src = subImage.src.replace(/\.(?=gif|jpg|png)/,"_on.");

				continue;
			}	

		alink[i].onmouseover = alink[i].onfocus = function() {
			subImage = this.getElementsByTagName("img")[0];
			if (subImage.src.indexOf("_on.") != -1) return false;
			subImage.src = subImage.src.replace(/\.(?=gif|jpg|png)/,"_on.");
			//alert(subImage.src);
		}
		
		alink[i].onmouseout = alink[i].onblur = function() {
				subImage = this.getElementsByTagName("img")[0];
				subImage.src = subImage.src.replace(/_on\.(?=gif|jpg|png)/, ".");
		}
	}

}
//]]>

function getLeftMenuOn(subImagename , pcode){
	
	if(pcode) {

		var arr_pcode = pcode.split("_");
		var l_pcode = arr_pcode[0];
		var m_pcode = arr_pcode[1];
		var s_pcode = arr_pcode[2];
		
		var tm_pcode = "lmenu_" + pcode.substring(0,3) + "_0";

		
		if(  (subImagename == "lmenu_" + pcode) || (subImagename == tm_pcode) ) {
			return true;
		}else{
			return false;
		}
		
		return false;
	
	}else{
		return false;
	}
}


//<![CDATA[
// tabRolling2
function tabRolling2(obj) {
	var _root = this;
	var index = obj.index || 0;
	var speed = obj.speed || 3000;
	var tabContainer = document.getElementById(obj.wrap);
	var tabAnchor = tabContainer.getElementsByTagName("A");
	var rollTimer = null;

	// 탭을 제외한 모든링크 오버시 롤링 정지
	var tabA = new Array;
	for(var i=0; i<tabAnchor.length; i++) {
		if (hasClass(tabAnchor[i], "tab")){
			tabA.push(tabAnchor[i]);
		}
		
		var etcLink = tabAnchor[i];
		addEvent(etcLink, "mouseover focus", function(e){
			_root.actionStop();
			var e = e || window.event;
			stopBubble(e);
			return stopDefault(e);
		});
		
		addEvent(etcLink, "blur", function(e){
			_root.actionStart();
		});
	}
	
	// 탭링크 클릭/오버시 동작 설정
	for(var i=0; i<tabA.length; i++) {
		var alink = tabA[i];
		alink.container = tabContainer;
		alink.targetEl = document.getElementById(alink.href.split("#")[1]);
		alink.targetEl.style.display = "none";
		alink.targetEl.style.filter = "alpha(opacity=0)";
		alink.targetEl.style.opacity = 0;

		alink.imgEl = alink.getElementsByTagName("img")[0];
		alink.cnt = i;

		alink.onclick = function(){
			_root.actionStop();
			alinkAction.call(this);
			return false;
		}
		if(!alink.container.first) alink.container.first = tabA[index];
	}
	if(tabContainer.first) alinkAction.call(tabContainer.first); // 초기 첫번째메뉴 활성화
	
	function alinkAction(e){
		rollActive = this.cnt;
		
		var oldActive = this.container.current;
		if(oldActive == this) return false;

		if(oldActive && oldActive.targetEl){
			oldActive.targetEl.style.display = "";
			motion.animate(oldActive.targetEl, { opacity:0, speed:30, speedRatio:0.07}, function(){
				oldActive.targetEl.style.display = "none";
			});

			if(oldActive.imgEl && oldActive.imgEl.src.indexOf("on.") != -1) oldActive.imgEl.src = oldActive.imgEl.src.replace(".", ".");
			removeClass(parentEle(oldActive, "LI"), "current");
		}
		
		var scopeA = this;
		this.targetEl.style.display = "block";
		motion.animate(this.targetEl, { opacity:1, speed:30, speedRatio:0.07 }, function(){
			scopeA.targetEl.style.display = "block";
		});
		
		if(this.imgEl &&  this.imgEl.src.indexOf("on.") == -1) this.imgEl.src = this.imgEl.src.replace(/\.(?=gif|jpg|png)/, ".");
		addClass(parentEle(this, "LI"), "current");

		this.container.current = this;
		return false;
	};

	// 오버시멈추고 / 마우스아웃시 롤링시작
	var rollActive = index || 0;
	addEvent(tabContainer, "mouseover", function(e){  _root.actionStop();  });
	addEvent(tabContainer, "mouseout", function(e){  _root.actionStart();  });
	
	function rollAction(){		
		rollActive++;
		if(rollActive >= tabA.length) rollActive = 0;
		alinkAction.call( tabA[rollActive] );
	}
	
	this.actionStart = function(){
		if( ! rollTimer ) rollTimer = setInterval(function(){  rollAction();  }, speed);
	}
	this.actionStop = function(){
		clearInterval( rollTimer );
		rollTimer = null;
	}
	_root.actionStart();
}
//]]>	



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




//<![CDATA[
// snbMenu
function snbMenu(containderID,on_target) {
	var objwrap = document.getElementById(containderID);
	var MenuAlink = objwrap.getElementsByTagName("A");

	var oldActive = null;
	var oldSubActive = null;

	objwrap.onmouseover = function(){ clearTimeout(wrapTimer); }
	objwrap.onmouseout = function(){ wrapAction(); }
	
	// 메뉴에서 완전히 마우스아웃 했을 경우 초기화
	var wrapTimer;
	function wrapAction(){
		wrapTimer = setTimeout(function(){
			if(oldActive && oldActive.id != "lm"+on_target){
				if(oldActive){
					imgOff(oldActive.img);
					removeClass(oldActive.parentNode, "current");
					if(oldActive.hasSub) sildeUp( next(oldActive) );
				}
				
				if(oldSubActive){
					imgOff(oldSubActive.img);
					removeClass(oldSubActive.parentNode, "current");
				}
			}
			oldActive = null;
			oldSubActive = null;
		}, 0);
	}
	
	function imgOn(targetImg){ if(targetImg && targetImg.src.indexOf("_on") == -1) targetImg.src = targetImg.src.replace(".gif","_on.gif") }
	function imgOff(targetImg){ if(targetImg) targetImg.src = targetImg.src.replace("_on.gif",".gif") }

	for (var i=0; i<MenuAlink.length; i++) {
		var alink = MenuAlink[i];
		alink.img = alink.getElementsByTagName("img")[0];
		
		// 이미지 프리로딩
		var preloding = new Image();
		preloding = ( alink.img && alink.img.src.indexOf("_on.gif") == -1 ) ? alink.img.src.replace(".gif","_on.gif") : "";

		// 메뉴뎁스 파악
		var dep = 0;
		var depNode = alink.parentNode;
		while( depNode != objwrap ){
			if( depNode.nodeName == "LI" ) dep++;
			depNode = depNode.parentNode;	
		}
		alink.dep = dep;
		
		// 하위메뉴가 있는지 파악
		var node = next(alink);
		if( node && node.nodeName == "UL" ) alink.hasSub = true;
		
		var oldActive;
		if( alink.dep == 1 ){
			alink.onmouseover = alink.onfocus = function() {
				alink.scope = this;
				setTimeout(function(){
					menuAction.call( alink.scope );
				}, 0);
			} // onmouseover
		} // end - if

		function menuAction(){
			clearTimeout(wrapTimer);
			
			if(oldActive == this) return false;
			if(oldActive){
				imgOff(oldActive.img);
				if(oldActive.id != "lm"+on_target){
					removeClass(oldActive.parentNode, "current");
				}
		
				if( oldActive.hasSub )
					sildeUp( next(oldActive) );
			}
	
			imgOn(this.img);
			addClass(this.parentNode, "current");
			
			if( this.hasSub)
				sildeDown( next(this) );
			
			oldActive = this;		
		}

		var oldSubActive;
		if( alink.dep == 2 ){
			alink.onmouseover = alink.onfocus = function() {
				clearTimeout(wrapTimer);
				oldSubActive = this;

				imgOn(this.img);
				addClass(this.parentNode, "current");
			}
			alink.onmouseout = alink.onblur = function() {
				imgOff(this.img);
				removeClass(this.parentNode, "current");
			}
		} // end - if
	
		if(alink.id=="lm"+on_target){
			addClass(alink.parentNode, "current");
			if( alink.hasSub)
				sildeDown( next(alink) );
		}
	} // end - for
}

//]]>



//따라다니는 퀵메뉴


function initMoving(target, position, topLimit, btmLimit) {
if (!target)
return false;

var obj = target;
obj.initTop = position;
obj.topLimit = topLimit;
obj.bottomLimit = Math.max(document.documentElement.scrollHeight, document.body.scrollHeight) - btmLimit - obj.offsetHeight;

obj.style.position = "absolute";
obj.top = obj.initTop;
obj.left = obj.initLeft;

if (typeof(window.pageYOffset) == "number") { //WebKit
obj.getTop = function() {
return window.pageYOffset;
}
} else if (typeof(document.documentElement.scrollTop) == "number") {
obj.getTop = function() {
return Math.max(document.documentElement.scrollTop, document.body.scrollTop);
}
} else {
obj.getTop = function() {
return 0;
}
}

if (self.innerHeight) { //WebKit
obj.getHeight = function() {
return self.innerHeight;
}
} else if(document.documentElement.clientHeight) {
obj.getHeight = function() {
return document.documentElement.clientHeight;
}
} else {
obj.getHeight = function() {
return 500;
}
}

obj.move = setInterval(function() {
if (obj.initTop > 0) {
pos = obj.getTop() + obj.initTop;
} else {
pos = obj.getTop() + obj.getHeight() + obj.initTop;
//pos = obj.getTop() + obj.getHeight() / 2 - 15;
}

if (pos > obj.bottomLimit)
pos = obj.bottomLimit;
if (pos < obj.topLimit)
pos = obj.topLimit;

interval = obj.top - pos;
obj.top = obj.top - interval / 3;
obj.style.top = obj.top + "px";
}, 30)
}




//쇼핑몰 탭

//<![CDATA[
// hasClass
function hasClass(element,value) {
	var re = new RegExp("(^|\\s)" + value + "(\\s|$)");
	return re.test(element.className);
}

// addClass
function addClass(element,value) {
	if (!element.className) {
			element.className = value;
	}else{
		var new_class_name = element.className;
		if (!hasClass(element,value)) {
			element.className += " " + value;
		}
	}
}

// removeClass
function removeClass(element,value) {
	if (element.className && hasClass(element,value)) {
		var re = new RegExp("(^|\\s)" + value);
		element.className = element.className.replace(re,"");
	}
}

// getElementsByClass('노드/생략[윈도우]', '태그/생략[*]', '클래스명');
function getElementsByClass(node, tagName, srchClass) {
    node = node || window.document;
    tagName = tagName ? tagName.toUpperCase() : "*";
    var eles = node.getElementsByTagName(tagName);
	
	if(!srchClass) return eles;

    var arr = new Array;
    for (var i=0; i<eles.length; i++) {
        if (hasClass(eles[i],srchClass)) arr.push(eles[i]);
    }
    return arr;
}

// 자신을 덮고있는태그 선택하기(클래스명 분류가능)
function parentEle(ele, tagName, srchClass){
	if(typeof tagName=="number"){
		for(var i=0; i<tagName; i++){
			if(ele!=null) ele = ele.parentNode;
		}
		return ele;
	}	
	
	tagName = tagName ? tagName.toUpperCase() : "*";
	if(srchClass){
		if(tagName!="*"){
			while((ele.nodeName!=tagName || !hasClass(ele,srchClass)) && ele.nodeName!="BODY")
				ele = ele.parentNode;
		}else{
			while(!hasClass(ele,srchClass) && ele.nodeName!="BODY")
				ele = ele.parentNode;
		}
	}else{
		if(tagName!="*"){
			while(ele.nodeName!=tagName && ele.nodeName!="BODY")
				ele = ele.parentNode;
		}else{
			ele = ele.parentNode;
		}
	}
	return ele;
}

// tabList
function tabList(tabContainerID, index) {
	index = index || 0;
	var tabContainer = document.getElementById(tabContainerID);
	var tabAnchor = tabContainer.getElementsByTagName("A");
	var i = 0;

	var tabA = new Array;
	for(i=0; i<tabAnchor.length; i++) {
		if (hasClass(tabAnchor[i], "tab")){
			var alink = tabAnchor.item(i);
			tabA.push(tabAnchor[i]);
		}else{
			continue;
		}

		alink.container = tabContainer;
		alink.targetEl = document.getElementById(tabAnchor[i].href.split("#")[1]);
		alink.targetEl.style.display = "none";
		alink.imgEl = alink.getElementsByTagName("img")[0];
		
		if(getElementsByClass(alink.targetEl, "P", "more")[0])
			getElementsByClass(alink.targetEl, "P", "more")[0].style.position = "absolute";
			
		alink.onclick = function(){
			oldActive = this.container.current;
			if(oldActive == this) return false;

			if(oldActive){
				oldActive.targetEl.style.display = "none";
				if(oldActive.imgEl) oldActive.imgEl.src = oldActive.imgEl.src.replace("_on.", ".");
				removeClass(parentEle(oldActive, "LI"), "current");
			}
			
			this.targetEl.style.display = "";
			if(this.imgEl) this.imgEl.src = this.imgEl.src.replace("/\.(?=gif|jpg|png)/", "_on.");
			addClass(parentEle(this, "LI"), "current");

			this.container.current = this;
			return false;
		};

		if(!alink.container.first) alink.container.first = tabA[index];
	}
	if(tabContainer.first) tabContainer.first.onclick();
	
	/* 탭a태그 노드들을 배열로 반환 */
	return tabA;
}
//]]>


/*
guideToggle - html_guide 메뉴하무

[클래스관련]
hasClass, addClass, removeClass

[이벤트관련]
addEvent, removeEvent, eventStopBubble

[dom관련함수]
id, next, prev, first, last, getElementsByClass, parentEle

[노드 삽입/삭제 관련]
insertBefore, insertAfter
appendTo, append
replaceChild, removeChild, empty

[노드 생성/속성]
create, checkElem, attr, text

[css 관련]
getStyle
insertCSS

[노드 보이기/감추기]
toggles, eleshow, elehide

[쿠기]
ui_getCookie, ui_setCookie, ui_removeCookie

[이미지 롤오버]
menuOver, menuOut, imgMenuOver

[기타]
popup
quicks
SWFLoader
*/

