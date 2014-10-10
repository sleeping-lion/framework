<!-- 스크롤 배너 내용 끝 -->

<!-- 스크롤 배너 스크립트 시작 -->
<!--
var bNetscape4plus = (navigator.appName == "Netscape" && navigator.appVersion.substring(0,1) >= "4");
var bExplorer4plus = (navigator.appName == "Microsoft Internet Explorer" && navigator.appVersion.substring(0,1) >= "4");
function CheckUIElements(){
     var yMenuFrom, yMenuTo, yButtonFrom, yButtonTo, yOffset, timeoutNextCheck;

     if ( bNetscape4plus ) { 
             yMenuFrom   = document["divMenu"].top;
             yMenuTo     = top.pageYOffset + 116; //넷스케이프용 최초 레이어 좌표 값
     }
     else if ( bExplorer4plus ) {
             yMenuFrom   = parseInt (divMenu.style.top, 10);
             yMenuTo     = document.body.scrollTop + 250; //익스플로러용 최초 레이어 좌표 값
     }

     timeoutNextCheck = 500;

     if ( Math.abs (yButtonFrom - (yMenuTo + 152)) < 6 && yButtonTo < yButtonFrom ) {
             setTimeout ("CheckUIElements()", timeoutNextCheck);
             return;
     }

     if ( yButtonFrom != yButtonTo ) {
             yOffset = Math.ceil( Math.abs( yButtonTo - yButtonFrom ) / 10 );
             if ( yButtonTo < yButtonFrom )
                     yOffset = -yOffset;

             if ( bNetscape4plus )
                     document["divLinkButton"].top += yOffset;
             else if ( bExplorer4plus )
                     divLinkButton.style.top = parseInt (divLinkButton.style.top, 10) + yOffset;

             timeoutNextCheck = 10;
     }
     if ( yMenuFrom != yMenuTo ) {
             yOffset = Math.ceil( Math.abs( yMenuTo - yMenuFrom ) / 20 );
             if ( yMenuTo < yMenuFrom )
                     yOffset = -yOffset;

             if ( bNetscape4plus )
                     document["divMenu"].top += yOffset;
             else if ( bExplorer4plus )
                     divMenu.style.top = parseInt (divMenu.style.top, 10) + yOffset;

             timeoutNextCheck = 10;
     }

     setTimeout ("CheckUIElements()", timeoutNextCheck);
}

function OnLoad()
{
     var y;
     if ( top.frames.length )
     if ( bNetscape4plus ) {
             document["divMenu"].top = top.pageYOffset + 116; //넷스케이프용 로딩시 시작 레이어 좌표 값
             document["divMenu"].visibility = "visible";
     }
     else if ( bExplorer4plus ) {
             divMenu.style.top = document.body.scrollTop + 500; //익스플로러용 로딩시 시작 레이어 좌표 값
             divMenu.style.visibility = "visible";
     }
     CheckUIElements();
     return true;
}
OnLoad();
//-->

<!-- 스크롤 배너 스크립트 끝 -->