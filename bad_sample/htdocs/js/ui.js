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

/* guideToggle */
function guidetoggle(e){
	var menu = parentEle(e, "h1");
	menu = next(menu);
	toggles(menu);
	return false;
}

/* Class */
function hasClass(element,value) {
    var re = new RegExp("(^|\\s)" + value + "(\\s|$)");
    return re.test(element.className);
}
function addClass(element,value) {
    if (!element.className)
		element.className = value;
    else
        if (!hasClass(element,value)) element.className += " " + value;
}
function removeClass(element,value) {
    if (element.className && hasClass(element,value)) {
        var re = new RegExp("(^|\\s)" + value);
        element.className = element.className.replace(re,"");
    }
}


/* Event */
function addEvent(obj,evt,fn){
	evt = (evt.indexOf(" ") != -1) ? evt.split(" ") : [evt];
	for(i in evt){
		var e = evt[i];
		if(e == "mousewheel"){
			if(obj.addEventListener) obj.addEventListener('DOMMouseScroll', fn, false);
			obj.onmousewheel = fn;
			break;
		}
		if(obj.addEventListener) obj.addEventListener( (e=="mousewheel") ? "DOMMouseScroll" : e,fn,false );
		else if(obj.attachEvent) obj.attachEvent('on'+e,fn);
	}
}
function removeEvent(obj,evt,fn){
	evt = (evt.indexOf(" ") != -1) ? evt.split(" ") : [evt];
	for(i in evt){
		var e = evt[i];
		if(e == "mousewheel"){
			if(obj.removeEventListener) obj.removeEventListener('DOMMouseScroll', fn, false);
			obj.onmousewheel = null;
			break;
		}
		if(obj.removeEventListener) obj.removeEventListener( (e=="mousewheel") ? "DOMMouseScroll" : e,fn,false );
		else if(obj.detachEvent) obj.detachEvent('on'+e,fn);
	}
}
function fireEvent(ele, type){
	if( document.createEventObject ){ // ie
		var evt = document.createEventObject();
		return ele.fireEvent('on'+type, evt);
		
	}else{ // ff, ch, sa, op
		var evt = document.createEvent("HTMLEvents");
		evt.initEvent(type, true, true);
		return !ele.dispatchEvent(evt);
	}
};
function stopBubble(e){
	if (e.stopPropagation) e.stopPropagation();
	else window.event.cancelBubble = true;
}
function stopDefault(e){
    if (e.preventDefault) e.preventDefault();
	else event.returnValue = false;
    return false;
}

/* 노드탐색관련 */
function id(id){
	return document.getElementById(id);
}
function next(ele){
	do{
		ele = ele.nextSibling;
	}while(ele && ele.nodeType!=1)
	return ele;
}
function prev(ele){
	do{
		ele = ele.previousSibling;
	}while(ele && ele.nodeType!=1)
	return ele;
}
function first(ele){
	ele = ele.firstChild;
	return ele && ele.nodeType!=1 ? next(ele) : ele;
}
function last(ele){
	ele = ele.lastChild;
	return ele && ele.nodeType!=1 ? prev(ele) : ele;
}

/* getElementsByClass('노드/생략[윈도우]', '태그/생략[*]', '클래스명'); */
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

/* 자신을 덮고있는태그 선택하기(클래스명 분류가능) */
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

/* insertBefore = target의 형제레벨로 앞쪽에 삽입 */
function insertBefore(source, target){
    target.parentNode.insertBefore(source, target);
}

/* insertAfter - target의 형제레벨로 뒤쪽에 삽입 */
function insertAfter(source, target) {
    var parent = target.parentNode;
    if(parent.lastChild == target)
        parent.appendChild(source);
    else
        parent.insertBefore(source, target.nextSibling);
}

/* appendTo = 자식요소로 앞쪽에 삽입 */
function appendTo(source, target){
    var first = target.firstChild;
    first.parentNode.insertBefore(source, first);
}

/* appendChild = 자식요소로 뒤쪽에 삽입 */
function append(source, target){
	target.appendChild(source);
}

/* 노드교체 */
function replaceNode(newNode, oldNode){
	return oldNode.parentNode.replaceChild(newNode, oldNode);	
}

/* 노드지우기 */
function removeNode(ele){
	return ele.parentNode.removeChild(ele);
}

/* 노드비우기 */
function emptyNode(oldNode){
	var newNode = oldNode.cloneNode(false);
	return oldNode.parentNode.replaceChild(newNode, oldNode);
}

/* create */
function create( elem ) {
    return document.createElementNS ?
        document.createElementNS( 'http://www.w3.org/1999/xhtml', elem ) :
        document.createElement( elem );
}
/* checkElem */
function checkElem( elem ) {
    return elem && elem.constructor == String ?
        document.createTextNode( elem ) : elem;
}

/* attr */
function attr(elem, name, value) {
    if ( !name || name.constructor != String ) return '';

    name = { "for":"htmlFor", "class":"className" }[name] || name;
    if (value != null){
        if (elem[name]) elem[name] = value;
        if (elem.setAttribute)
            elem.setAttribute(name,value);
    }
    return elem[name] || elem.getAttribute(name) || '';
}

/* text */
function text(e){
	var t = "";
	e = e.childNodes;
	
	for(var i=0; i<e.length; i++){
		if(e[i].nodeType == 8) continue;
		t += ( e[i].nodeType!=1 ) ? e[i].nodeValue : text(e[i]);
	}
	return t;
}

/* setOpacity */
function setOpacity(ele, value){
	if(typeof ele =='string') ele=document.getElementById(ele);
	ele.style.opacity = (value / 100);
	ele.style.filter = "alpha(opacity="+value+")";
}

/* position */
function posX(elem){ return parseInt(getStyle(elem, "left")); }
function posY(elem){ return parseInt(getStyle(elem, "top")); }
function setX(elem, pos){ elem.style.left = pos+"px"; }
function setY(elem, pos) { elem.style.top = pos +"px"; }

/* offset */
function pageX(elem){
    var p = 0;
    while ( elem.offsetParent ){
        p += elem.offsetLeft;
        elem = elem.offsetParent;
    }
    return p;
}
function pageY(elem){
    var p = 0;
    while ( elem.offsetParent ) {
        p += elem.offsetTop;
        elem = elem.offsetParent;
    }
    return p;
}
function parentX(elem){ return elem.parentNode == elem.offsetParent ? elem.offsetLeft : pageX(elem) - pageX(elem.parentNode); }
function parentY(elem){ return elem.parentNode == elem.offsetParent ? elem.offsetTop : pageY(elem) - pageY(elem.parentNode); }

function getX(e) { e = e || window.event; return e.pageX || (e.clientX + document.documentElement.scrollLeft || document.body.scrollLeft || 0); }
function getY(e) { e = e || window.event; return e.pageY || (e.clientY + document.documentElement.scrollTop || document.body.scrollTop || 0); }

function getElementX(e){ return ( e && e.layerX ) || window.event.offsetX; }
function getElementY(e){ return ( e && e.layerY ) || window.event.offsetY; }

function scrollX(){ var de = document.documentElement; return self.pageXOffset || ( de && de.scrollLeft ) || document.body.scrollLeft; }
function scrollY(){ var de = document.documentElement; return self.pageYOffset || ( de && de.scrollTop ) || document.body.scrollTop; }

function pageWidth(){ return document.body.scrollWidth; }
function pageHeight(){ return document.body.scrollHeight; }

function windowWidth(){ var de = document.documentElement; return self.innerWidth || ( de && de.clientWidth ) || document.body.clientWidth; }
function windowHeight(){ var de = document.documentElement; return self.innerHeight || ( de && de.clientHeight ) || document.body.clientHeight; }

function getHeight(elem){ return parseInt(getStyle(elem, "height")) }
function getWidth(elem) { return parseInt( getStyle(elem, "width")) }

function fullWidth(elem) {
    if (getStyle(elem, 'display') != 'none') return elem.offsetWidth || getWidth(elem);
	var old = resetCSS(elem, {display:'block', visibility: 'hidden', position: 'absolute'});
    var w = elem.clientWidth || getWidth(elem);
    restoreCSS(elem, old);
    return w;
}
function fullHeight(elem) {
    if (getStyle(elem, 'display') != 'none') return elem.offsetHeight || getHeight(elem);
	var old = resetCSS(elem, {display: 'block', visibility: 'hidden', position: 'absolute'});
    var h = elem.clientHeight || getHeight(elem);
    restoreCSS(elem, old);
    return h;
}

function resetCSS(elem, prop) {
    var old = {};
	for ( var i in prop ){
        old[i] = elem.style[i];
        elem.style[i] = prop[i];
    }
    return old;
}
function restoreCSS(elem, prop) {
    for ( var i in prop )
        elem.style[i] = prop[i];
}

/* getStyle */
function getStyle(ele, what){
	if(typeof ele == "string") var ele = document.getElementById(ele);
    if(ele.style[what]) return ele.style[what];
	
	var value = "";
	if(ele.currentStyle)
		value = ele.currentStyle[what];
	else if(document.defaultView.getComputedStyle)
		value = document.defaultView.getComputedStyle(ele,null)[what];
		
	return value;
}

/* insertCSS */
function insertCSS(str){
    var style = document.createElement("style");
    style.setAttribute("type","text/css");
    var css_code = str;
    if (style.styleSheet) {
		// Only For IE6, IE7, IE8
        style.styleSheet.cssText = css_code;
    } else {
        css_code = document.createTextNode(css_code);
        style.appendChild(css_code);
    }
    var head = document.getElementsByTagName("head")[0];
    head.appendChild(style);
}

/* 노드 감추기/보이기 */
function toggles(ele){
	if(typeof ele == "string") ele = document.getElementById(ele);
	var value = null;
	if(ele.currentStyle) var value = ele.currentStyle['display'];
	else if(document.defaultView.getComputedStyle) var value = document.defaultView.getComputedStyle(ele,null)['display'];

	if(value != "none") (ele.style.display != 'none') ? ele.style.display = 'none' : ele.style.display = '';
	else (ele.style.display != 'block') ? ele.style.display = 'block' : ele.style.display = ''
	return false;
}
function eleshow(ele) {
	if(typeof ele == "string") ele = document.getElementById(ele);
	ele.style.display = 'block';
	return false;
}
function elehide(ele) {
	if(typeof ele == "string") ele = document.getElementById(ele);
	ele.style.display = 'none';
	return false;
}

/* Cookie */
function ui_getCookie(name){
	// var allCookies = decodeURIComponent(document.cookie);
	var allCookies = document.cookie;
	var strCnt = name.length;
	var pos = allCookies.indexOf(name+"=");

	if(pos == -1) return undefined;

	var start = pos + strCnt+1;
	var end = allCookies.indexOf(";", start);
	if(end == -1) end = allCookies.length;
	var value = allCookies.substring(start, end);
	return value = decodeURIComponent(value);
}
function ui_setCookie(name,value,max_age,cPath,cDomain){
	var pathStr = (cPath) ? "; path=" + cPath : "; path=/";
	var domainStr = (cDomain) ? "; domain=" + cDomain : "";
	max_age = max_age || 1;

	var today = new Date();
	var expires = new Date();
	expires.setTime( today.getTime() + (1000*60*60*24*max_age) );

	document.cookie = encodeURIComponent(name) + "=" + encodeURIComponent(value)
							+ pathStr
							+ domainStr
							+ "; expires=" + expires.toGMTString();
							// + "; max-age=" + (60*60*24*max_age);
}
function ui_removeCookie(name){ ui_setCookie(name, "", -1); }

/* motion */
function motion(){
	var target;
	var _root = this;
	var mSpeed;
	var mSpeedRatio;

	this.animate = function(ele, obj, fn){
		target = (typeof ele =='string') ? document.getElementById(ele) : ele;
		
		if(fn) target.AfterFnc = fn;
		target.afChkLength = 0;
		target.afChkCnt = 0;
		
		mSpeed = obj["speed"] || 15;
		mSpeedRatio = obj["speedRatio"] || 0.2;

		for(i in obj){
			if( i == "speed" || i == "speedRatio" ) continue;

			clearInterval(target[String(i)+"Timer"]);
			_root[String(i)](obj);
			++target.afChkLength;
		}
	}

	this.getStyle = function(ele, what){
		var value = "";
		if(ele.currentStyle){
			value = ele.currentStyle[what];
		}else if(window.getComputedStyle){
			value = window.getComputedStyle(ele,null)[what];
		}
		return parseFloat(value);
	}

	this.top = function(obj){ _root.motions(obj, "top") };
	this.left = function(obj){ _root.motions(obj, "left") };
	this.width = function(obj){
		if( String(_root.getStyle(target, "width"))==="NaN" )
			target.style.width = target.offsetWidth - _root.getStyle(target, "paddingLeft") - _root.getStyle(target, "paddingRight") + "px";
		_root.motions(obj, "width")
	};
	this.height = function(obj){
		if( String(_root.getStyle(target, "height"))==="NaN" )
			target.style.height = target.offsetHeight - _root.getStyle(target, "paddingTop") - _root.getStyle(target, "paddingBottom") + "px";
		_root.motions(obj, "height");
	};
	this.marginTop = function(obj){ _root.motions(obj, "marginTop") };
	this.marginBottom = function(obj){ _root.motions(obj, "marginBottom") };
	this.paddingTop = function(obj){ _root.motions(obj, "paddingTop") };
	this.paddingBottom = function(obj){ _root.motions(obj, "paddingBottom") };

	// top, left, width, height 움직임
	this.motions = function(obj, evtName){
		(function(){
			var ele = target;
			var to = obj[String(evtName)];
			var from, speed;
			
			ele[evtName+"Timer"] = setInterval(function(){
				from = _root.getStyle(ele, String(evtName));
				from = parseFloat(from);
				
				speed = (to-from)*mSpeedRatio;
				speed = (to>from) ? Math.ceil(speed) : Math.floor(speed);
				
				try{ ele.style[String(evtName)] = from+speed+"px"; }catch(e){}
				
				if( to==from || Math.abs(from)==1 ){
					clearInterval(ele[evtName+"Timer"]);
					try{ ele.style[String(evtName)] = to+"px"; }catch(e){}
					++ele.afChkCnt;
					if(ele.afChkLength == ele.afChkCnt && ele.AfterFnc) ele.AfterFnc();
					return;
				}
			}, mSpeed);
		})();
	}
	
	// opacity
	this.opacity = function(obj){
		(function(){
			var ele = target;
			var to = obj.opacity*100;
			var from, speed;

			if( String(_root.getStyle(ele, "opacity"))==="NaN" ){
				ele.style.filter = "alpha(opacity=100)";
				ele.style.opacity = 0.1;
			}
			
			ele.opacityTimer = setInterval(function(){
				from = _root.getStyle(ele, "opacity")*100;
				speed = (to-from)*mSpeedRatio;
				speed = (to>from) ? Math.ceil(speed) : Math.floor(speed);
				
				var v = from+speed;
				if(v<0) v = 0;
				ele.style.filter = "alpha(opacity=" + v + ")";
				ele.style.opacity = (v)/100;

				if(from == to){
					clearInterval(ele.opacityTimer);
					ele.style.filter = "alpha(opacity=" + to + ")";
					ele.style.opacity = (to)/100;
					++target.afChkCnt;
					if(target.afChkLength == target.afChkCnt && target.AfterFnc) target.AfterFnc();
				}
			}, mSpeed);
		})();
	}
}
var motion = new motion;

// silde
function sildeDown(target){
	if(typeof target =='string') target=document.getElementById(target);
	if(target.slideDir == "down") return false;
	if(!target.slideDir && getStyle(target, "display") != "none") target.slideDir = "down";
	
	var h, mgt, mgb, pdt, pdb;
	if(target.slideDoing){
		h = target.slideFufllHeight;
		mgt = target.slideMgt;
		mgb = target.slideMgb;
		pdt = target.slidePdt;
		pdb = target.slidePdb;
	}else{
		h = target.slideFufllHeight = fullHeight(target);
		mgt = target.slideMgt = parseFloat(getStyle(target, "marginTop"));
		mgb = target.slideMgb = parseFloat(getStyle(target, "marginBottom"));
		pdt = target.slidePdt = parseFloat(getStyle(target, "paddingTop"));
		pdb = target.slidePdb  = parseFloat(getStyle(target, "paddingBottom"));
	}
	h = h - pdt - pdb;
	
	if(target.slideDoing) resetCSS(target, {display:"block", overflow:"hidden"});
	else resetCSS(target, {display:"block", overflow:"hidden", height:0 , marginTop:0, marginBottom:0, paddingTop:0, paddingBottom:0});

	target.slideDir = "down";
	target.slideDoing = true;
	
	motion.animate(target, { height : h, marginTop : mgt, marginBottom : mgb, paddingTop : pdt, paddingBottom : pdb }, function(){
		resetCSS(target, {overflow:"", height:"", marginTop:"", marginBottom:"", paddingTop:"", paddingBottom:"" });																														
		target.slideDoing = false;
	});
}
function sildeUp(target){
	if(typeof target =='string') target=document.getElementById(target);
	if(target.slideDir == "up") return false;
	if(!target.slideDir && getStyle(target, "display") == "none") target.slideDir = "up";

	if(!target.slideFufllHeight){
		target.slideFufllHeight = fullHeight(target);
		target.slideMgt = parseFloat(getStyle(target, "marginTop"));
		target.slideMgb = parseFloat(getStyle(target, "marginBottom"));
		target.slidePdt = parseFloat(getStyle(target, "paddingTop"));
		target.slidePdb  = parseFloat(getStyle(target, "paddingBottom"));
	}

	resetCSS(target, {display:"block", overflow:"hidden"});

	target.slideDir = "up";
	target.slideDoing = true;
	
	motion.animate(target, {height:0, marginTop:0, marginBottom:0, paddingTop:0, paddingBottom:0}, function(){
		restoreCSS(target, {display:"none", overflow:"", height:"", marginTop:"", marginBottom:"", paddingTop:"", paddingBottom:""});
		target.slideDoing = false;
	});
}
function slidetoggles(target){
	if(typeof target =='string') target=document.getElementById(target);
	if(!target.slideDir && getStyle(target, "display") == "none") target.slideDir = "up";
	if(target.slideDir == "up") sildeDown(target);
	else sildeUp(target);	
}

/*
팝업창 사용법
<a target="_blank" href="#" onclick="popup({ url:this.href, name:'popup', width:300, height:300, position:'center', scroll:false });return false;">
<a target="_blank" href="http://www.ondisk.co.kr" onclick="popup({ url:this.href, name:'popup2', width:300, height:300, position:{top : 100, left : 100}, scroll:false });return false;">팝업2</a>
*/
function popup(obj){
	var url = obj.url;
	var name = obj.name || "popup";
	var w = obj.width || 450;
	var h = obj.height || 650;	
	var position = obj.position;
	var scroll = obj.scroll;

	var tlOpt = 'top=0, left=0';
	if(position == "center"){
		var top = screen.height/2 - h/2 - 100;
		var left = screen.width/2 - w/2;
		if(top<0) top=0;
		if(left<0) left=0;
		tlOpt = ',top='+top +',left='+left;
		
	}else if( Object.prototype.toString.call(position) == "[object Object]" && "top" in position && "left" in position ){
		tlOpt = ',top='+position.top+',left='+position.left;
	}
	
	if( navigator.userAgent.toLowerCase().indexOf("msie 9") != -1 ) w -= 4;
	
	sOpt = (scroll == "scroll" || scroll === true) ? ",scrollbars=yes" :  ""; // 창스크롤
	winOptions = tlOpt+',width='+w +',height='+h +sOpt +', resizable=yes'; // top, left, width, height, location, menubar, resizable, scrollbar, status
	
	var popWin = window.open(url,name,winOptions);
	return popWin;
}

// 팝업창 리사이즈
function popupResizeWrap(ele){
	ele = document.getElementById(ele);
	function action(){
		var eleH = ele.offsetHeight;
		var popH = document.documentElement.scrollHeight;
		var visualH = document.documentElement.clientHeight;
	
		var y;
		if(popH > eleH) y = eleH - popH;
		if(eleH >= popH && popH > visualH) y = popH - visualH;
		window.resizeBy(0,y);
	}
	action();
	setTimeout(function(){ action() }, 1000);
}
function popupResizeTo(w,h) {
	document.body.style.overflow='hidden';
	if ( window.innerWidth )
		window.resizeBy(w-window.innerWidth, h-window.innerHeight);
	else
		window.resizeBy(w-document.body.clientWidth, h-document.body.clientHeight);
}

/* quicks */
function quicks(ele){
	var target = document.getElementById(ele); /* 퀵메뉴 */
	var limitB = false; /* 퀵메뉴가 하단 어느부분까지 내려올지 */
	var intTop = 0; /* 퀵메뉴 초기 top위치 기억 */
	var _root = this;
	var yMenuFrom, yMenuTo, speed;
	
	this.getStyle = function(element, what){
		var value = "";
		if(element.currentStyle) value = element.currentStyle[what];
		else if(window.getComputedStyle) value = window.getComputedStyle(element,null)[what];
		return value;
	}

	this.int = function(){
		var temp = _root.getStyle(target, "top");
		target.style.top = temp;
		intTop = parseFloat(temp);
	}

	this.limitBottom = function(num){
		limitB = (document.body.scrollHeight || document.documentElement.scrollHeight) - target.offsetHeight - num;
	}

	this.move = function(){
		var scrollTop = parseFloat(document.body.scrollTop || document.documentElement.scrollTop);
		yMenuFrom = parseFloat(target.style.top);
		
		// yMenuTo = intTop + scrollTop; // 초기위치에 고정
		yMenuTo = (intTop > scrollTop) ? intTop : scrollTop + 15; // 초기시작점 제외하고 화면 상단 15px에 붙어있기
		
		if(limitB){
			if(yMenuTo >= limitB) yMenuTo = limitB;
		}
		if(yMenuFrom == yMenuTo){
			return setTimeout(function(){_root.move();}, 70); /* 스크롤의 반응속도 */
		}else{
			speed = Math.floor((yMenuTo - yMenuFrom) *0.2);
			target.style.top = (yMenuFrom + speed) + "px";
			return setTimeout(function(){_root.move();}, 45); /* 퀵속도 */
		}
	}
}

/* 롤오버 */
function menuOver(ele) { 
	var img = ele.getElementsByTagName("img")[0];
	img.src = img.src.replace("_on", "");
	img.src = img.src.replace(/\.(?=gif|jpg|png)/, "_on.");

	
}
function menuOut(ele) { var img = ele.getElementsByTagName("img")[0]; img.src = img.src.replace(/_on\.(?=gif|jpg|png)/, "."); }
function menusOver(ele) {
	var eleWrap = document.getElementById(ele);
	var alink = eleWrap.getElementsByTagName("A");
	for (i=0; i<alink.length; i++) {
		if(alink[i].getElementsByTagName("img").length == 0) continue;		
		if(alink[i].getElementsByTagName("img")[0].src.indexOf("_on.") != -1 ) continue;	
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

/* SWFLoader */
function SWFLoader() {
	this.id = "";
	this.title = undefined;
	this.wmode = "window";
	this.flashvars = "";
	this.classId = 'clsid:d27cdb6e-ae6d-11cf-96b8-444553540000';
	this.codeBase = 'http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=9,0,0,0';
	this.pluginSpage = 'http://www.macromedia.com/go/getflashplayer';
	this.embedType = 'application/x-shockwave-flash';
	this.flashvars = "";
}
SWFLoader.prototype.setting = function(obj){
	for(var property in obj){
		this[property] = obj[property];
	}
	if(this.alternate && document.getElementById(this.alternate)){
		var node = document.getElementById(this.alternate);
		this.alternate = node.innerHTML;
		node.style.display = "none";
	}else{
		this.alternate = "";
	}
	this.parameter = "";
	this.parameter += "<param name='allowScriptAccess' value='always' />";
	this.parameter += "<param name='allowFullScreen' value='false' />";
	this.parameter += "<param name='movie' value='"+this.url+this.flashvars+"' />";
	this.parameter += "<param name='wmode' value='"+ this.wmode +"' />";
	this.parameter += "<param name='quality' value='best'/>";
	this.parameter += "<param name='base' value='.'>";
	this.parameter += "<param name='scale' value='noscale'/>";
	this.parameter += "<param name='expressinstall' value='Scripts/expressInstall.swf' />";
}
SWFLoader.prototype.addParameter = function(name, value){
	this.parameter += "<param name='"+name+"' value='"+value+"'/>";
}
SWFLoader.prototype.show = function(ele){
	var str = "";
	var title = (this.title) ? ' title="'+this.title+'"' : "";

	if( navigator.userAgent.toLowerCase().indexOf("msie")!=-1 )	{
		str += '<object id="'+this.id+'" name="'+this.id+'" width="'+this.width+'" height="'+this.height+'" classid="'+this.classId+'" codebase="'+this.codeBase+'" title="'+ title+'">';
		str += this.parameter;
		str += this.alternate;
		str += '</object>';		
	}else{
		str += '<object id="'+this.id+'" name="'+this.id+'" type="application/x-shockwave-flash" data="'+this.url+this.flashvars+'" width="'+this.width+'" height="'+this.height+'" title="'+ title+'">';
		str += this.parameter;
		str += this.alternate;
		str += '</object>';
	}
	(ele != undefined) ? ele.innerHTML = str : document.write(str);
}



