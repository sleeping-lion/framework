<script type="text/javascript" src="/ckeditor/ckeditor.js"></script>
<?php
	$MY_URI = get_php_self_filename($_SERVER[PHP_SELF]);  
//	include $cf_initial_s . "_necessary.inc";

	if($cf_cook_nick_nm)
		$tm_input_nm = $cf_cook_nick_nm;
	else
		$tm_input_nm = $my_input_nm;

	$tm_input_Y = substr($my_input_ymdhms, 0, 4);
	$tm_input_m = substr($my_input_ymdhms, 4, 2);
	$tm_input_d = substr($my_input_ymdhms, 6, 2);
	$tm_input_H = substr($my_input_ymdhms, 8, 2);
	$tm_input_i = substr($my_input_ymdhms, 10, 2);
	$tm_input_s = substr($my_input_ymdhms, 12, 2);
?>




<table width="<?=$cf_table_wd_large?>" border="0" cellpadding="3" cellspacing="0" style="border-top:2px solid #cacaca;border-bottom:1px solid #cacaca;">
	<tr bgcolor='#F4F4F4' height="27">
       <td width="120" align="center">팝업 제목</td>
      <td bgcolor='#FFFFFF' align="left">&nbsp;&nbsp;<input type="text" name="fr_title_bar" size="60" maxlength="60" value="<?=$my_title_bar?>" class='box'></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='2'></td>
    </tr>

	<tr bgcolor='#F4F4F4' height="27">
      <td align="center">팝업 종류</td>
      <td bgcolor='#FFFFFF' align="left"><!-- &nbsp;&nbsp;<input type="radio" name="fr_display" value="0" onClick="popupReg()"   />   HTML  -->&nbsp;&nbsp;
            <input type="radio" name="fr_display" value="1" onClick="popupReg()" checked/>   단일 이미지</td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='2'></td>
    </tr>

	<tr bgcolor='#F4F4F4' height="27">
      <td align="center">시작일/종료일</td>
      <td bgcolor='#FFFFFF' align="left">&nbsp;&nbsp;<select name="fr_start_year" class='select'><? for($i=2014;$i<2023;$i++){	$today_y=date("Y");?><option value="<?=$i?>" <?if($i==$today_y) echo("selected");?>><?=$i?></option><?}?></select>&nbsp;년&nbsp;&nbsp;
						<select name="fr_start_mon" class='select'><? for($i=1;$i<13;$i++){if(strlen($i)==1)$i="0".$i; $today_m=date("m");?><option value="<?=$i?>" <?if($i==$today_m) echo("selected");?>><?=$i?></option><?}?></select>&nbsp;월&nbsp;&nbsp; 
						<select name="fr_start_day" class='select'><? for($i=1;$i<32;$i++){if(strlen($i)==1)$i="0".$i; $today_d=date("d");?><option value="<?=$i?>" <?if($i==$today_d) echo("selected");?>><?=$i?></option><?}?></select>&nbsp;일&nbsp;~&nbsp;
						<select name="fr_end_year" class='select'><? for($i=2014;$i<2023;$i++){	$today_y=date("Y");?><option value="<?=$i?>" <?if($i==$today_y) echo("selected");?>><?=$i?></option><?}?></select>&nbsp;년&nbsp;&nbsp;
						<select name="fr_end_mon" class='select'><? for($i=1;$i<13;$i++){if(strlen($i)==1)$i="0".$i; $today_m=date("m");?><option value="<?=$i?>" <?if($i==$today_m) echo("selected");?>><?=$i?></option><?}?></select>&nbsp;월&nbsp;&nbsp; 
						<select name="fr_end_day" class='select'><? for($i=1;$i<32;$i++){if(strlen($i)==1)$i="0".$i; $today_d=date("d");?><option value="<?=$i?>" <?if($i==$today_d) echo("selected");?>><?=$i?></option><?}?></select>&nbsp;일</td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='2'></td>
    </tr>

	<tr bgcolor='#F4F4F4' height="27">
      <td align="center">팝업창 크기</td>
      <td bgcolor='#FFFFFF' align="left">&nbsp;&nbsp;<input name="fr_width" type="text" size="3" class='box'/> 가로  &nbsp; X &nbsp;  <input name="fr_height" type="text" size="3" class='box' /> 세로 &nbsp;&nbsp;&nbsp;(새로운 창의 크기를 설정해주세요)</td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='2'></td>
    </tr>

	<tr bgcolor='#F4F4F4' height="27">
      <td align="center">팝업창 위치</td>
      <td bgcolor='#FFFFFF' align="left">&nbsp;&nbsp;<input name="fr_left" type="text" size="3" class='box'/> 왼쪽  <input name="fr_top" type="text" size="3" class='box' /> 위 &nbsp;&nbsp;&nbsp;(새로운 창의 위치를 설정해주세요)</td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='2'></td>
    </tr>

   
	<tr bgcolor='#F4F4F4' height="27">
      <td align="center">쿠키설정</td>
      <td bgcolor='#FFFFFF' align="left">&nbsp;&nbsp;<input type="radio" name="fr_live" value="0"/> ※ 오늘은 이창을 다시 띄우지 않음 &nbsp;
              <input type="radio" name="fr_live" value="1" /> ※ 이창은 다시는 띄우지 않음</td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='2'></td>
    </tr>

	   
	<tr bgcolor='#F4F4F4' height="27"  id="popup_view" style="display:;">
      <td align="center">링크 URL</td>
      <td bgcolor='#FFFFFF' align="left">&nbsp;&nbsp;HTTP://<input name="fr_link_url" type="text" class='box' size="50" /></td>
    </tr>

    <tr  id="popup_view" style="display:none;">
      <td bgcolor='#E4E4E4' height='1' colspan='2'></td>
    </tr>


	<tr bgcolor='#F4F4F4' height="27"  id="popup_view" style="display:;">
      <td align="center">출력 이미지</td>
      <td bgcolor='#FFFFFF' align="left">&nbsp;&nbsp;<input name="userfile" type="file" size="30" class='box'/><br>
             &nbsp;&nbsp; <font color="red"> 출력할 이미지를 등록해 주세요</font></td>
    </tr>
    <tr  id="popup_view" style="display:none;">
      <td bgcolor='#E4E4E4' height='1' colspan='2'></td>
    </tr>

	<tr bgcolor='#F4F4F4' height="27"  id="popup_view" style="display:none;">
      <td align="center">출력 내용[HTML]</td>
      <td>&nbsp;&nbsp;<textarea name="fr_content" cols="65%" rows="15" class='tbox'><?=$my_it_memo?></textarea></td>
    </tr bgcolor='#FFFFFF' align="left">
    <tr id="popup_view" style="display:none;">
      <td bgcolor='#E4E4E4' height='1' colspan='2'></td>
    </tr>  
   
</table>


  <br>

  <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
    <tr>
      <td height="36" align="right">
	    <input type="image" src="<?=$cf_images_dir?>/ok.gif"></a>
	    <a href="javascript:signform.reset();"><img src="<?=$cf_images_dir?>/cancel.gif" border="0"></a>
		<a href="list.html?<?=$po_adv_query?>" onMouseOver="status='reload articles';return true;" onMouseOut="status=''"><img src="<?=$cf_images_dir?>/list.gif" border="0"></a>
	  </td>
    </tr>
  </table>
  <BR>
  <BR>

<script type="text/javascript"> 
//<![CDATA[ 
CKEDITOR.replace('fr_content',{
	 width: '100%',
     height: 300,
	 /* skin:'스킨폴더명', //스킨 폴더 위치
      uiColor: '#14B8C4', //UI색깔
	  language : 'english', //언어
	  toolbar:
		  [
			['Bold','-', 'Italic'], 
            ['NumberedList']
          ],// 툴바 정의
	  customConfig : '커스텀설정js파일위치',
	  width: '100%',
      height: 300,
      */
       /*
	     기본 툴바 목록
		 ['Source','-','Save','NewPage','Preview','-','Templates'],
		 ['Cut','Copy','Paste','PasteText','PasteFromWord','-','Print', 'SpellChecker', 'Scayt'],
		 ['Undo','Redo','-','Find','Replace','-','SelectAll','RemoveFormat'],
		 ['Form', 'Checkbox', 'Radio', 'TextField', 'Textarea', 'Select', 'Button', 'ImageButton', 'HiddenField'],
		 '/',
		 ['Bold','Italic','Underline','Strike','-','Subscript','Superscript'],
		 ['NumberedList','BulletedList','-','Outdent','Indent','Blockquote'],
		 ['JustifyLeft','JustifyCenter','JustifyRight','JustifyBlock'],
		 ['Link','Unlink','Anchor'],
		 ['Image','Flash','Table','HorizontalRule','Smiley','SpecialChar','PageBreak'],
		 '/',
		 ['Styles','Format','Font','FontSize'],
		 ['TextColor','BGColor'],
		 ['Maximize', 'ShowBlocks','-','About']	
	   */
	  //customConfig : '커스텀설정js파일위치', 
	//				 width: '100%', 
		//			 height: 300  //  기본 설정값
	   filebrowserUploadUrl : "/ckfinder/core/connector/php/connector.php?command=QuickUpload&type=Files",
       filebrowserImageUploadUrl : "/ckfinder/core/connector/php/connector.php?command=QuickUpload&type=Images",
       filebrowserFlashUploadUrl : "/ckfinder/core/connector/php/connector.php?command=QuickUpload&type=Flash",
	   
	   toolbar:
		  [
			['Source','-','NewPage','Preview','-','Templates'],
            ['Cut','Copy','Paste','PasteText','PasteFromWord','-','Print', 'SpellChecker', 'Scayt'],
		    ['Undo','Redo','-','Find','Replace','-','SelectAll','RemoveFormat'],
		    ['Bold','Italic','Underline','Strike','-','Subscript','Superscript'],
		    ['NumberedList','BulletedList','-','Outdent','Indent','Blockquote'],
		    ['Image','Table','HorizontalRule','Smiley','SpecialChar','PageBreak'],
		    ['Styles','Format','Font','FontSize'],
			['TextColor','BGColor'],
			['Maximize', 'ShowBlocks','-','About']	
          ],
	  enterMode:'2',   // 엔터 모드 1:<p></p> 2:<br /> 3:<div></div>
	  shiftEnterMode:'3' //쉬프트+엔터 1:<p></p> 2:<br /> 3:<div></div>

	});

//]]> 
</script>
