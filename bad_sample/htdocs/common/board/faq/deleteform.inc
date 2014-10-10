<?
	// listbody.inc 를 그대로 가져다 쓰는 경우
	// 하단 버튼 등을 가져다 쓰지 않기 위해 $DELETE_PRINT_YN = "N"; 를 셋팅한다.
	$DELETE_PRINT_YN = "N";
	include $cf_skin_nm . "/listbody.inc";
?>
<?
	if($cf_top_level_yn == "Y")
	{
?>
      <input type='hidden' name='fr_passwd' value='<?=$my_passwd?>'>
<?
	}
	else
	{
?>
		  <table width="560" border="0" cellspacing="0" cellpadding="0">
			<tr>
			  <td width="15%">비 밀 번 호</td>
			  <td width="15%"><input type="password" name="fr_passwd" size="10" maxlength="10" class='box'></td>
			  <td width="70%"></td>
			</tr>
		    <tr>
			 <td class='dark' height="1" colspan='2'></td>
			 <td></td>
		    </tr>
		  </table>
<?
	}
?>

	<table width="<?echo($cf_table_wd_large)?>" border="0" cellspacing="0" cellpadding="0" background="<?=$cf_images_dir?>/boad_but_line.gif">
		<tr height="6">
			<td></td>
		</tr>
	</table>


	<table width="<?echo($cf_table_wd_large)?>" border="0" cellspacing="0" cellpadding="0">
		<tr>
			<td align="right">
			  <?=$LIST?>
			  <input type="image" src="<?=$cf_images_dir?>/delete.gif" align="absmiddle">
			  <a href="javascript:history.back()"><img src="<?=$cf_images_dir?>/cancel.gif" align="absmiddle"></a>
			</td>
		</tr>
	</table>
