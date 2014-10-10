<!-- based on insimage.dlg -->
<!DOCTYPE HTML PUBLIC "-//W3C//DTD W3 HTML 3.2//EN">
<HTML  id=dlgImage STYLE="width: 432px; height: 230px;">
<head>
<meta http-equiv="content-type" content="text/html; charset=euc-kr">
<meta http-equiv="MSThemeCompatible" content="yes">
<title>웹페이지 그림 삽입</title>
<style>
  html, body, button, div, input, select, fieldset { font-family: MS Shell Dlg; font-size: 8pt; position: absolute; };
</style>
<script language="javascript" src="../upload_image.js"></script>
<script language="javascript">
function show_wait_show() {
 show_orig.style.display='none';
 show_wait.style.display='block';
}
  
function show_wait_hide() {
 show_orig.style.display='block';
 show_wait.style.display='none';
}
</script>
</head>
<body id=bdy onload="Init();" style="background: threedface; color: windowtext;" scroll=no>
<table id="show_orig" width="100%" border="0" cellspacing="0" cellpadding="0" style="display:block;position:relative;">
<tr><td align="center">

<div id=divFileName style="left: 0.98em; top: 1.2168em; width: 7em; height: 1.2168em; ">그림 선택 :</div>
<input id="txtFileName" type="text" style="left: 8.54em; top: 1.0647em; width: 21.5em;height: 2.1294em;" tabIndex=10 onfocus="select();" style="display:block;position:absolute;">

<div id=divAltText style="left: 0.98em; top: 4.1067em; width: 6.58em; height: 1.2168em; ">대체 문자 :</div>
<input id="txtAltText" type=text tabIndex=15 style="left: 8.54em; top: 3.8025em; width: 21.5em; height: 2.1294em; " onfocus="select();">

<fieldset id=fldLayout style="left: .9em; top: 7.1em; width: 17.08em; height: 7.6em;">
<legend id=lgdLayout>윤 곽</legend>
</fieldset>

<fieldset id=fldSpacing style="left: 18.9em; top: 7.1em; width: 11em; height: 7.6em;">
<legend id=lgdSpacing>여 백</legend>
</fieldset>

<div id=divAlign style="left: 1.82em; top: 9.126em; width: 4.76em; height: 1.2168em; ">정 렬 :</div>
<select size=1 id=selAlignment tabIndex=20 style="left: 10.36em; top: 8.8218em; width: 6.72em; height: 1.2168em; ">
<option id=optNotSet value=""> Not set </option>
<option id=optLeft value=left> Left </option>
<option id=optRight value=right> Right </option>
<option id=optTexttop value=textTop> Texttop </option>
<option id=optAbsMiddle value=absMiddle> Absmiddle </option>
<option id=optBaseline value=baseline SELECTED> Baseline </option>
<option id=optAbsBottom value=absBottom> Absbottom </option>
<option id=optBottom value=bottom> Bottom </option>
<option id=optMiddle value=middle> Middle </option>
<option id=optTop value=top> Top </option>
</select>

<div id=divHoriz style="left: 19.88em; top: 9.126em; width: 4.76em; height: 1.2168em; ">수 평</div>
<input id="txtHorizontal" style="left: 24.92em; top: 8.8218em; width: 4.2em; height: 2.1294em; ime-mode: disabled;" type=text size="2" maxlength="2" value="0" tabIndex=25 onfocus="select()">

<div id=divBorder style="left: 1.82em; top: 12.0159em; width: 8.12em; height: 1.2168em; ">두 께</div>
<input id="txtBorder" style="left: 10.36em; top: 11.5596em; width: 6.72em; height: 2.1294em; ime-mode: disabled;" type=text size="2" maxlength="2" value="0" tabIndex=21 onfocus="select()">

<div id=divVert style="left: 19.88em; top: 12.0159em; width: 3.64em; height: 1.2168em; ">수 직</div>
<input id="txtVertical" style="left: 24.92em; top: 11.5596em; width: 4.2em; height: 2.1294em; ime-mode: disabled;" type=text size="2" maxlength="2" value="0" tabIndex=30 onfocus="select()">


<form name="bform1" method="post" action="upload_image_ok.php" target="uploading" enctype="multipart/form-data" style="margin:0px">
<input id="hFileName" name="image1" onChange="up_show_pic2('1','image1',document.bform1);" type="file" style="left: 8.54em; top: 1.0647em; width: 21.5em;height: 2.1294em;" tabIndex=10 style="display:none;position:absolute;">
<input type="hidden" name="hAltText" value="">
<input type="hidden" name="hselAlignment" value="">
<input type="hidden" name="hHorizontal" value="">
<input type="hidden" name="hBorder" value="">
<input type="hidden" name="hVertical" value="">
<input type="hidden" name="hVertical" value="">
<input type="hidden" name="upUrl" value="<?=$_GET[upUrl]?>">

<div id=divgubun style="left: 31.36em; top: 1.0647em; width: 7em; height: 1.2168em;"><font onclick="ch_gubun('1');" onMouseOver="this.style.cursor='hand'">링크</font> - <font onclick="ch_gubun('2');" onMouseOver="this.style.cursor='hand'">업로드</font></div>

<button id="btn1" style="left: 31.36em; top: 3.0em; width: 7em; height: 2.2em;" type="button" tabIndex=40 onclick="javascript:jimgUp();" style="display:block;position:absolute;">링 크</button>
<button id="btn2" style="left: 31.36em; top: 3.0em; width: 7em; height: 2.2em;" type="button" tabIndex=40 onclick="javascript:jupload();" style="display:none;position:absolute;">업로드</button>
<button style="left: 31.36em; top: 5.5em; width: 7em; height: 2.2em;" type=reset tabIndex=45 onClick="self.close();">취 소</button>
<div style="left: 31.36em; top: 8.5em;">
<img id=pic1 height="68" width="80" style="display:none;">
</div>

</form>

    </td>
</tr>
</table>

<table id="show_wait" width="100%" border="0" cellspacing="0" cellpadding="0" style="display:none;position:relative;">
<tr height="30"><td></td></tr>
<tr height="25">
   <td align="center" width="100%">
   <table width="80%" border="0" cellspacing="0" cellpadding="0">
   <tr height="25"><td align="center"><font style="font-size: 9pt; color:#333333; line-height:13pt; font-family:굴림,arial;">요청하신 사항을 처리중에 있습니다.</font></td>
   </tr>
   </table>
   </td>
</tr>
<tr height="5"><td></td></tr>
<tr><td align="center"><img src="images/Loading-Bar.gif"></td></tr>
</table>

<iframe name="uploading" width="0%" height="0" frameborder="0" hspace="0" marginheight="0" marginwidth="0" vspace="0"></iframe>

</body>
</html>