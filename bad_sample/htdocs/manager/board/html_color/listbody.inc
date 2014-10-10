
 <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0" bgcolor="CCCCCC">
    <tr height='2'>
      <td width="68" bgcolor='#cacaca'></td>
      <td width="532" bgcolor='#444444'></td>	 
    </tr>
  </table>
 <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
	<tr bgcolor='#F4F4F4' height='27'>
      <td width="80" align="center"><img src="<?=$cf_images_dir?>/title.gif"></td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td colspan="9" width="<?=$cf_table_wd_large-80?>">&nbsp;&nbsp;<?=$my_subject?></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='11'></td>
    </tr>

	<tr bgcolor='#F4F4F4' height='27'>
      <td width="80" align="center"><img src="<?=$cf_images_dir?>/name.gif"></td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td width="160">&nbsp;&nbsp;<?=$my_sign_nm?></td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td width="80" align="center"><img src="<?=$cf_images_dir?>/date.gif"></td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td width="130">&nbsp;&nbsp;<?=$tm_input_ymdhms?></td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
	  <td width="80" align="center"><img src="<?=$cf_images_dir?>/hit.gif"></td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td width="<?=$cf_table_wd_large-535?>">&nbsp;&nbsp;<?=$my_ver_cnt?></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='11'></td>
    </tr>
<?
	// 첨부화일
	if($cf_attach_size > 0 || $my_attach_path)
	{
?>
	<tr bgcolor='#F4F4F4' height='27'>
      <td align="center"><img src="<?=$cf_images_dir?>/file_nm.gif"></td>
      <td><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td colspan="9">&nbsp;&nbsp;<?=$tm_attach_file_tmp?></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='11'></td>
    </tr>
	<?if($tm_attach_file_tmp1){?>
	<tr bgcolor='#F4F4F4' height='27'>
      <td align="center"><img src="<?=$cf_images_dir?>/file_nm.gif"></td>
      <td><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td colspan="9">&nbsp;&nbsp;<?=$tm_attach_file_tmp1?></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='11'></td>
    </tr>
	<?}?>
	<?if($tm_attach_file_tmp2){?>
	<tr bgcolor='#F4F4F4' height='27'>
      <td align="center"><img src="<?=$cf_images_dir?>/file_nm.gif"></td>
      <td><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td colspan="9">&nbsp;&nbsp;<?=$tm_attach_file_tmp2?></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='11'></td>
    </tr>
	<?}?>
	<?if($tm_attach_file_tmp3){?>
	<tr bgcolor='#F4F4F4' height='27'>
      <td align="center"><img src="<?=$cf_images_dir?>/file_nm.gif"></td>
      <td><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td colspan="9">&nbsp;&nbsp;<?=$tm_attach_file_tmp3?></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='11'></td>
    </tr>
	<?}?>
<?
	}
?>

<?
	if($cf_cook_id != '822170515') {

		// 특수기능
		if($cf_top_level_yn == "Y")
		{
			if($a_cd == "50" && $cf_cook_level > aa){
			}else{
	?>
		<tr bgcolor='#F4F4F4' height='27'>
		  <td align="center"><img src="<?=$cf_images_dir?>/serv.gif"></td>
		  <td><img src="<?=$cf_images_dir?>/th_line.gif"></td>
		  <td>
			&nbsp;&nbsp;공개 : <?=$my_service_yn?>&nbsp;&nbsp;&nbsp;&nbsp;등록 : <?=$my_public_yn?>
		  </td>
		  <td><img src="<?=$cf_images_dir?>/th_line.gif"></td>
		  <td align="center"><img src="<?=$cf_images_dir?>/information.gif"></td>
		  <td><img src="<?=$cf_images_dir?>/th_line.gif"></td>
		  <td colspan="5">&nbsp;&nbsp;ID : <?=$my_input_id?> &nbsp; &nbsp; IP : <?=$my_input_ip?></td>
		</tr>
		<tr>
		  <td bgcolor='#E4E4E4' height='1' colspan='11'></td>
		</tr>
<?			}
		}
	}
?>

 </table>

  <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
    <tr height='1'>
      <td bgcolor='#DBDBDB'></td>
    </tr>
    <tr height='4'>
      <td bgcolor='#F5F5F5'></td>
    </tr>
  </table>

  <table width="560" border="0" cellspacing="0" cellpadding="0">
    <tr>
      <td style="line-height=150%"><BR>

<?
	if($my_attach_path && is_file($tm_real_path_physical))
	{
		$tm_file_info_arr = getimagesize($tm_real_path_physical);

		if($tm_file_info_arr[2] > 0 && $tm_file_info_arr[2] < 4)
		{
			$tm_image_info = get_image_size($tm_real_path_physical, 450);
?>
		 <table border="0" width="<?=$cf_table_wd_large?>">
			<tr>
				<td align="center">
					<img src="<?=$tm_real_path?>" name="img1" <?=$tm_image_info[2]?> <? if(is_file($tm_real_path_physical)) { ?> onclick="pop_img('<?=$tm_real_path?>')" style="cursor:hand" <? } ?>>
				</td>
			</tr>
			</table><br>
<?
		}
	}
?>
	  
	  <?=$my_memo?><br></td>
    </tr>
  </table>
  <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
    <tr height='1'>
      <td bgcolor='#DBDBDB'></td>
    </tr>
    <tr height='4'>
      <td bgcolor='#F5F5F5'></td>
    </tr>
  </table>
  <br><br><br>

<?
	// 코멘트 사용여부가 y 이고 상세보기폼일때
	if($cf_comment_yn == "Y" && $MY_URI == "listbody")
	{
		include $cf_skin_nm . "/listbody_comment.inc";
	}


	// 삭제폼에서 listbody.inc 를 가져다 쓰는 경우를 고려했다.
	// 삭제폼에서 $DELETE_PRINT_YN = "N"; 를 넣은경우 아래 부분은 출력하지 않는다.
	if($DELETE_PRINT_YN != "N")
	{
?>
<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="3" cellpadding="3">
  <tr>
    <td align="center">
		<?if($prev_it_no){echo $PREV;}else{echo "&nbsp;";}?>&nbsp;&nbsp;
		<?if($next_it_no){echo $NEXT;}else{echo "&nbsp;";}?>
	</td>
  </tr>
</table>

  <br>
  <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
    <tr>
      <td height="36" align="right"><?=$MODIFY?> <?=$REPLY?> <?=$DELETE?> <?=$LIST?></td>
    </tr>
  </table>

<BR>
<BR>
<?
	}
?>