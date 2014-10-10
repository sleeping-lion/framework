// 타이틀---------
//document.title="Darae ParkTech";
// ---------타이틀


function MM_openBrWindow(theURL,winName,features) { //v2.0
  window.open(theURL,winName,features);
}
/********************************************************************************************************
//아래로 펼쳐지는 테그
********************************************************************************************************/
var old_menu = '';
function menuclick(num) {
	var submenu = eval('prdPar_' + num);

	if(old_menu != submenu) {
		if(old_menu != '') old_menu.style.display = 'none';
		submenu.style.display = 'block';
		old_menu = submenu;
	} else {
		submenu.style.display = 'none';
		old_menu = '';
	}
}



/********************************************************************************************************
		 //점선링크삭제
********************************************************************************************************/
function bluring(){
if(event.srcElement.tagName=="A"||event.srcElement.tagName=="IMG") document.body.focus();
}
document.onfocusin=bluring;

/********************************************************************************************************
	Flash_Select
********************************************************************************************************/

function SetTopMenuFlashVars(pageNum, subNum)
{
	document.topmenu.FlashVars = 'pageNum='+pageNum+'&subNum='+subNum;
}

function SetLeftMenuFlashVars(PageNum, subNum)
{
	document.leftmenu.FlashVars = 'PageNum='+PageNum+'&subNum='+subNum;
}

function SetLeftMenu_2FlashVars(PageNum, subNum)
{
	document.leftmenu_2.FlashVars = 'PageNum='+PageNum+'&subNum='+subNum;
}


//select-관련사이트 이동
function MovePage(url) {
	if(url=="#"||url=="") {

	} else {
			window.open(url,"new");
	}
}


function Select_target(sel, targetstr)
{
  var index = sel.selectedIndex;
  if (sel.options[index].value != '') {
     if (targetstr == 'blank') {
       window.open(sel.options[index].value, 'win1');
     } else {
       var frameobj;
       if (targetstr == '') targetstr = 'self';
       if ((frameobj = eval(targetstr)) != null)
         frameobj.location = sel.options[index].value;
     }
  }
}





/********************************************************************************************************
	팝업창 오픈
********************************************************************************************************/
function uf_popOpen(url) {
	var positionX = 0;
	var positionY = 0;
//	var positionX = (screen.width-450)/2;
//	var positionY = (screen.height-250)/2;
	window.open(url,"","left="+positionX+",top="+positionY+",width=300,height=300,toolbar=no,scrollbars=no" );
}





/****** 팝업창 리사이즈 **************************************************************/
function uf_popResize() {
	var thisX = document.getElementById("offsetTable").offsetWidth;
	var thisY = document.getElementById("offsetTable").offsetHeight;
	var maxThisX = screen.width - 50;
	var maxThisY = screen.height - 80;
	if (window.navigator.userAgent.indexOf("SV1") != -1){
	var marginY = 50; //마지막 수는 상황에따라 알맞게 넣으세요. (템플릿의 헤더높이 + 풋터 높이 + 알파)
	} else {
	var marginY = 29; //마지막 수는 상황에따라 알맞게 넣으세요. (템플릿의 헤더높이 + 풋터 높이 + 알파)
	}

	if (thisX > maxThisX) {
		window.document.body.scroll = "yes";
		thisX = maxThisX;
	}
	if (thisY > maxThisY - marginY) {
		window.document.body.scroll = "yes";
		thisX += 19;
		thisY = maxThisY - marginY;
	}

	var windowX = (screen.width - (thisX+10))/2;
	var windowY = (screen.height - (thisY+marginY))/2 - 20;
//	window.moveTo(windowX,windowY);
	window.resizeTo(thisX+10,thisY+marginY);
}

/****** 팝업창 리사이즈 **************************************************************/



/********************************************************************************************************
	롤오버
********************************************************************************************************/

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

///////////////////////////////////////////////////////////////


/********************************************************************************************************
레이어 효과
********************************************************************************************************/

function bt(id,after) {
	eval(id+'.filters.blendTrans.stop();');
	eval(id+'.filters.blendTrans.Apply();');
	eval(id+'.src="'+after+'";');
	eval(id+'.filters.blendTrans.Play();');
}
function DisplayMenu(lay,cnt,index) {
	var lay=lay;
	var cnt=cnt;
	var index=index;
        for (i=1; i<=cnt; i++)
        if (index == i) {
			thisMenu = eval(lay + index + ".style");
			thisMenu.display = "";
        } else {
			otherMenu = eval(lay + i + ".style");
			otherMenu.display = "none";
        }
}

function print_ok2(){
	document.getElementById("printbutton").style.display = "none";
	window.print();
}
