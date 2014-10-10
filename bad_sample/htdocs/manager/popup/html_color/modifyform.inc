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

 <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
    <tr height='3'>
      <td width="120" bgcolor='#cacaca'></td>
      <td width="480" bgcolor='#444444'></td>
    </tr>
  </table>


<table width="<?=$cf_table_wd_large?>" border="0" cellpadding="0" cellspacing="0">

	<tr bgcolor='#F4F4F4' height="27">
       <td width="119" align="center">팝업 제목</td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td width="480">&nbsp;&nbsp;<input type="text" name="fr_title_bar" size="60" maxlength="60" value="<?=$my_title_bar?>" class='box'></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='3'></td>
    </tr>

	<input type="hidden" name="fr_display" value="0" />

	<tr bgcolor='#F4F4F4' height="27">
      <td width="119" align="center">시작일/종료일</td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td>&nbsp;&nbsp;<select name="fr_start_year" class='select'><? for($i=2009;$i<2015;$i++){	$tm_start_day=explode("-",$my_start_day);?><option value="<?=$i?>" <?if($i==$tm_start_day[0]) echo("selected");?>><?=$i?></option><?}?></select>&nbsp;년&nbsp;&nbsp;
						<select name="fr_start_mon" class='select'><? for($i=1;$i<13;$i++){if(strlen($i)==1)$i="0".$i; ?><option value="<?=$i?>" <?if($i==$tm_start_day[1]) echo("selected");?>><?=$i?></option><?}?></select>&nbsp;월&nbsp;&nbsp; 
						<select name="fr_start_day" class='select'><? for($i=1;$i<32;$i++){if(strlen($i)==1)$i="0".$i;?><option value="<?=$i?>" <?if($i==$tm_start_day[2]) echo("selected");?>><?=$i?></option><?}?></select>&nbsp;일&nbsp;~&nbsp;
						<select name="fr_end_year" class='select'><? for($i=2009;$i<2015;$i++){	$tm_end_day=explode("-",$my_end_day);?><option value="<?=$i?>" <?if($i==$tm_end_day[0]) echo("selected");?>><?=$i?></option><?}?></select>&nbsp;년&nbsp;&nbsp;
						<select name="fr_end_mon" class='select'><? for($i=1;$i<13;$i++){if(strlen($i)==1)$i="0".$i; ?><option value="<?=$i?>" <?if($i==$tm_end_day[1]) echo("selected");?>><?=$i?></option><?}?></select>&nbsp;월&nbsp;&nbsp; 
						<select name="fr_end_day" class='select'><? for($i=1;$i<32;$i++){if(strlen($i)==1)$i="0".$i; ?><option value="<?=$i?>" <?if($i==$tm_end_day[2]) echo("selected");?>><?=$i?></option><?}?></select>&nbsp;일</td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='3'></td>
    </tr>

		<tr bgcolor='#F4F4F4' height="27">
      <td width="119" align="center">팝업창 크기</td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td>&nbsp;&nbsp;<input name="fr_width" type="text" size="3" class='box' value="<?=$my_width;?>"/>
              가로 X
              <input name="fr_height" type="text" size="3" class='box' value="<?=$my_height;?>"/>
              세로 &nbsp;&nbsp;&nbsp;(새로운 창의 크기를 설정해주세요)</td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='3'></td>
    </tr>

	<tr bgcolor='#F4F4F4' height="27">
      <td width="119" align="center">팝업창 위치</td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td>&nbsp;&nbsp;왼쪽에서&nbsp;<input name="fr_left" type="text" size="3" class='box' value="<?=$my_p_left;?>"/>px&nbsp;&nbsp;&nbsp;              
              위에서&nbsp;<input name="fr_top" type="text" size="3" class='box' value="<?=$my_p_top;?>"/>px
              </td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='3'></td>
    </tr>
   
	<input type="hidden" name="fr_live" value="0"/>
	   
	<tr bgcolor='#F4F4F4' height="27"  id="popup_view">
      <td width="119" align="center">링크 URL</td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td>&nbsp;&nbsp;HTTP://
                <input name="fr_link_url" type="text" class='box' size="50" value="<?=$my_link_url;?>"/></td>
    </tr>
    <tr  id="popup_view" style="display:none;">
      <td bgcolor='#E4E4E4' height='1' colspan='3'></td>
    </tr>

	<tr bgcolor='#F4F4F4' height="27"  id="popup_view" >
      <td colspan='3'><textarea name="fr_content" id="editor" class='tbox' style="width:675px;height:300px;"><?=$my_content?></textarea></td>
    </tr>
    <tr id="popup_view" style="display:none;">
      <td bgcolor='#E4E4E4' height='1' colspan='3'></td>
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

<script type="text/javascript" src="/smarteditor2/js/HuskyEZCreator.js" charset="utf-8"></script>
<script type="text/javascript"> 
var oEditors = [];
	nhn.husky.EZCreator.createInIFrame({
		oAppRef: oEditors,
		elPlaceHolder: "editor",
		sSkinURI: "/smarteditor2/SmartEditor2Skin.html",	
		htParams : {bUseToolbar : true,
			fOnBeforeUnload : function(){
				//alert("아싸!");	
			}
		}, //boolean
		fOnAppLoad : function(){
			//예제 코드
			//oEditors.getById["ir1"].exec("PASTE_HTML", ["로딩이 완료된 후에 본문에 삽입되는 text입니다."]);
		},
		fCreator: "createSEditor2"
	});
</script>