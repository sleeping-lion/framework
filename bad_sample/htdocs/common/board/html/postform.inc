<script language="Javascript1.2"><!-- // load htmlarea
_editor_url = "./edit/";                     // URL to htmlarea files
_Upload_url = "<?=$cf_savedir?>";
  document.write('<scr' + 'ipt src="' +_editor_url+ 'editor.js"');
  document.write(' language="Javascript1.2"></scr' + 'ipt>');
// --></script>
<script src="./edit/editor.js"></script>
<?php
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

<br>

 <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0" bgcolor="CCCCCC">
    <tr height='2'>
      <td width="68" bgcolor='#8B8B8B'></td>
      <td width="532" bgcolor='#8B8B8B'></td>
    </tr>
  </table>


<table width="<?=$cf_table_wd_large?>" border="0" cellpadding="0" cellspacing="0">
<?
	if($cf_top_level_yn == "Y" || $cf_cook_level =="bb")
	{
?>
    <tr bgcolor='#F4F4F4' height="27">
<?if($a_gb=='board' && $a_cd!='6'){?><!-- 연혁입력시 필요없는테이블삭제 -->
       <td align="center"><img src="<?=$cf_images_dir?>/date.gif"></td>
<?}else{?>
       <td align="center"><strong>연혁일</strong></td>
<?}?>
	  <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td width="*">&nbsp;&nbsp;Year&nbsp;:<input type="text" name="fr_input_Y" size="4" maxlength="4" class="box" value="<?=$tm_input_Y?>">
		 Month&nbsp;:<input type="text" name="fr_input_m" size="2" maxlength="2" class="box" value="<?=$tm_input_m?>">
		 Day&nbsp;:<input type="text" name="fr_input_d" size="2" maxlength="2" class="box" value="<?=$tm_input_d?>">
		<!--input type="text" name="fr_input_H" size="2" maxlength="2" class="box" value="<?=$tm_input_H?>"> 시
		<input type="text" name="fr_input_i" size="2" maxlength="2" class="box" value="<?=$tm_input_i?>"> 분
		<input type="text" name="fr_input_s" size="2" maxlength="2" class="box" value="<?=$tm_input_s?>"> 초-->
		<?if($a_gb=='board' && $a_cd!='6'){?><!-- 연혁입력시 필요없는테이블삭제 -->
      ※ 특정날짜로 입력일로 할경우 입력하세요.
<?}?>
	  </td>
	</tr>
   <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='3'></td>
    </tr>
<?
	}
?>
	<tr bgcolor='#F4F4F4' height="27">
<?if($a_gb=='board' && $a_cd!='6'){?><!-- 연혁입력시 필요없는테이블삭제 -->
       <td align="center"><img src="<?=$cf_images_dir?>/title.gif"></td>
<?}else{?>
       <td align="center"><strong>연혁내용</strong></td>
<?}?>
	  <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td width="540">&nbsp;&nbsp;<input type="text" name="fr_subject" size="60" maxlength="60" value="<?=$my_subject?>" class='box'></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='3'></td>
    </tr>
<?if($a_gb=='board' && $a_cd!='6'){?><!-- 연혁입력시 필요없는테이블삭제 -->
	<tr bgcolor='#F4F4F4' height="27">
      <td align="center"><img src="<?=$cf_images_dir?>/name.gif"></td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td>&nbsp;&nbsp;<input type="text" name="fr_input_nm" size="15" maxlength="10" value="<?if($cf_cook_level=="aa" || $cf_cook_level=="bb"){echo "ADMIN";} else { echo $cf_cook_id;}?>" class='box'></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='3'></td>
    </tr>

<?	if(!$cf_cook_id)
	{
?>
	<tr bgcolor='#F4F4F4' height="27">
      <td align="center"><img src="<?=$cf_images_dir?>/pass.gif"></td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td>&nbsp;&nbsp;<input type="password" name="fr_passwd" size="15" maxlength="30" class='box'></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='3'></td>
    </tr>
<?
	}
?>
<tr bgcolor='#F4F4F4' height="27">
      <td align="center"><b>링크</b></td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td>&nbsp;&nbsp;<input type="text" name="fr_link" size="50" maxlength="50" class='box'></td>
</tr>
<?
	// 첨부화일
	if($cf_attach_size > 0)
	{
?>
	<tr bgcolor='#F4F4F4' height='30'>
	  <td align='center'><img src='<?=$cf_images_dir?>/file_nm.gif'></td>
	  <td width='1'><img src='<?=$cf_images_dir?>/th_line.gif'></td>
	  <td >&nbsp;&nbsp;<input type='file' name='userfile' size='30' maxlength='400' class='box'> (Max : <?=$tm_attach_size?> MB) </td>
	</tr>

	<!--	tr bgcolor='#F4F4F4' height='27' id="s_rank1" style="display:none;">
	  <td align='center'><img src='<?=$cf_images_dir?>/file_nm.gif'></td>
	  <td width='1'><img src='<?=$cf_images_dir?>/th_line.gif'></td>
	  <td>&nbsp;&nbsp;<input type='file' name='userfile_1' size='20' maxlength='400' class='box'> (최대용량 : <?=$tm_attach_size?> MB) <img src='<?=$cf_images_dir?>/add.gif' onclick="show_rank(2)" align="absmiddle"> </td>
	</tr>


	<tr bgcolor='#F4F4F4' height='27' id="s_rank2" style="display:none;">
	  <td align='center'><img src='<?=$cf_images_dir?>/file_nm.gif'></td>
	  <td width='1'><img src='<?=$cf_images_dir?>/th_line.gif'></td>
	  <td>&nbsp;&nbsp;<input type='file' name='userfile_2' size='20' maxlength='400' class='box'> (최대용량 : <?=$tm_attach_size?> MB) <img src='<?=$cf_images_dir?>/add.gif' onclick="show_rank(3)" align="absmiddle"> </td>
	</tr>


	<tr bgcolor='#F4F4F4' height='27' id="s_rank3" style="display:none;">
	  <td align='center'><img src='<?=$cf_images_dir?>/file_nm.gif'></td>
	  <td width='1'><img src='<?=$cf_images_dir?>/th_line.gif'></td>
	  <td>&nbsp;&nbsp;<input type='file' name='userfile_3' size='20' maxlength='400' class='box'> (최대용량 : <?=$tm_attach_size?> MB)</td>
	</tr-->

	<tr>
	  <td bgcolor='#E4E4E4' height='1' colspan='3'></td>
	</tr>

<?php
	}
?>

<?php

	// 특수기능(옵션)
	if($cf_top_level_yn == "Y")
	{
?>
	<tr bgcolor='#F4F4F4' height="27">
      <td align="center"><img src="<?=$cf_images_dir?>/serv.gif"></td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td>&nbsp;&nbsp;
		<input name="fr_service_yn" type="checkbox" value="Y" checked> 공개여부 &nbsp; <?=print_htmltag_yesno($cf_allow_html_yn)?>

	  <?php
		if($cf_secret_yn == "Y"){?>
		<input type="checkbox" name="fr_secret_yn" value="Y" checked> SECRET
	  <?} else {?>
		<input type="hidden" name="fr_secret_yn" value="N">
	  <?}?>

	<?if($cf_annou_yn == "Y") {?>
		<input type="checkbox" name="fr_notice_yn" value="Y"> NOTICE
	<? } ?>

	  </td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='3'></td>
    </tr>
<?php
	}else{

		if($cf_secret_yn == "Y"){
?>
	<tr bgcolor='#F4F4F4' height="27">
      <td align="center"><img src="<?=$cf_images_dir?>/serv.gif"></td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td>&nbsp;
		<input type="checkbox" name="fr_secret_yn" value="Y" checked> SECRET
	  </td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='3'></td>
    </tr>

<?		}else {?>
		<input type="hidden" name="fr_secret_yn" value="N">
<?		}
		echo "<input type='hidden' name='fr_service_yn' value='Y'>";
	}

	echo "<input type='hidden' name='fr_public_yn' value='Y'>";

?>
</table>

<table width="<?=$cf_table_wd_large?>" border="0" cellpadding="0" cellspacing="0">
<?if($cf_allow_html_yn=="N"){?>
<tr bgcolor='#FAFAFA' height="250">
	<td align='center'>
	<textarea name="fr_memo" cols="100%" rows="15" class='contents'><?=$my_memo?></textarea></td>
</tr>
<?}else{?>
<tr bgcolor='#F4F4F4' height="27">
	<td height="5"></td>
	<td colspan="3">
	<textarea name="fr_memo"  id="editor" cols="75%" rows="15" class='contents'><?=$my_memo?></textarea><BR><BR></td>
</tr>
<?}?>
</table>
<?}?>



  <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
    <tr height='1'>
      <td bgcolor='#DBDBDB'></td>
    </tr>
    <tr height='4'>
      <td bgcolor='#F5F5F5'></td>
    </tr>
  </table>
  <br>

  <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
    <tr>
      <td height="36" align="right">
	    <input type="image" src="<?=$cf_images_dir?>/ok.gif">
	    <a href="javascript:signform.reset();"><img src="<?=$cf_images_dir?>/cancel.gif" border="0"></a>
		<a href="list.html?<?=$po_adv_query?>" onMouseOver="status='reload articles';return true;" onMouseOut="status=''"><img src="<?=$cf_images_dir?>/list.gif" border="0"></a>
	  </td>
    </tr>
  </table>
  <BR>
  <BR>

<?if($cf_allow_html_yn == "Y"){?>
<script language="javascript1.2">
  var config = new Object();    // create new config object
  config.width = "100%";
  config.height = "300px";
   editor_generate("fr_memo", config);

</script>
<?}?>