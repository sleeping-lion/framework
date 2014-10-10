<!-- 제목 출력 시작 -->
<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0" bgcolor="CCCCCC">
<tr align="center" height='3'>
  <td bgcolor='#8B8B8B'></td>
</tr>
</table>

<table width="<?=$cf_table_wd_large?>" border="0" cellpadding="0" cellspacing="0">
<form name="signform" method="post" action="">
<input type="hidden" name="fr_check_no" >
<input type="hidden" name="fr_del_no" >

<tr align="center" height='27'>
	<?if($cf_cook_level == "aa" || $cf_cook_level == "bb"){?>
	  <td width="29" background="<?=$cf_images_dir?>/th_bg.gif"><img src="<?=$cf_images_dir?>/select.gif" onclick="check_all()"></td>
      <td width="1" background="<?=$cf_images_dir?>/th_bg.gif"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
	<?}?>
      <td width="40" background="<?=$cf_images_dir?>/th_bg.gif"><img src="<?=$cf_images_dir?>/no.gif"></td>
      <td width="1" background="<?=$cf_images_dir?>/th_bg.gif"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td width="*" background="<?=$cf_images_dir?>/th_bg.gif"><img src="<?=$cf_images_dir?>/title.gif"></td>
      <td width="1" background="<?=$cf_images_dir?>/th_bg.gif"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td width="85" background="<?=$cf_images_dir?>/th_bg.gif"><img src="<?=$cf_images_dir?>/name.gif"></td>
      <td width="1" background="<?=$cf_images_dir?>/th_bg.gif"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td width="85" background="<?=$cf_images_dir?>/th_bg.gif"><img src="<?=$cf_images_dir?>/date.gif"></td>
      <td width="1" background="<?=$cf_images_dir?>/th_bg.gif"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td width="50" background="<?=$cf_images_dir?>/th_bg.gif"><img src="<?=$cf_images_dir?>/hit.gif"></td>
    </tr>
 </table>
<table width="<?=$cf_table_wd_large?>" border="0" cellpadding="0" cellspacing="0">



<!-- 여기서부터 실제 공지레코드 출력 -->
<?
	for($i=0; $i<$notice_board->record_count; $i++)
	{
?>
  <tr bgcolor="<?=$tm_bgcolor?>" align='center' height="24">
	<?if($cf_cook_level == "aa" || $cf_cook_level == "bb"){?>
	  <td width="29"><input type='checkbox' name='fr_check_no' value='<?=$notice_arr[$i][NO]?>'></td>
	<?}?>
      <td width="40" ><?=$notice_arr[$i][NUM]?></td>
      <td align='left' width="*" >&nbsp;&nbsp;&nbsp;<?=$notice_arr[$i][INDENT]?> <?=$notice_arr[$i][LISTBODY_LINK]?> <font color="#0099FF"><!-- 코멘트갯수삽입 --><?=$notice_arr[$i][COMM_CNT]?></font> <?=$notice_arr[$i][FILE_PATH]?> <?=$notice_arr[$i][NEW_ICON]?></td>
      <td width="85"><?=$notice_arr[$i][INPUT_NM]?></td>
      <td width="85"><?=$notice_arr[$i][INPUT_YMDHMS]?></td>
      <td width="50"><?=$notice_arr[$i][VER_CNT]?></td>
  </tr>
<?
	}
?>

<?

	// 게시물 출력 후 사용한 변수파기
	unset($notice_arr);
?>
<!-- 여기까지 실제 공지레코드 출력 -->





<!-- 여기서부터 실제 레코드 출력 -->
<?
	for($i=0; $i<$board->record_count; $i++)
	{
?>
  <tr bgcolor="<?=$tm_bgcolor?>" align='center' height="24">
	<?if($cf_cook_level == "aa" || $cf_cook_level == "bb"){?>
	  <td width="29"><input type='checkbox' name='fr_check_no' value='<?=$arr[$i][NO]?>'></td>
	<?}?>
      <td width="40"><?=$arr[$i][NUM]?></td>
      <td align='left' width="*"><?=$arr[$i][INDENT]?><img src="<?=$cf_images_dir?>/<?=$arr[$i][ICON]?>"> <?=$arr[$i][SUBJECT]?> <font color="#0099FF"><!-- 코멘트갯수삽입 --><?=$arr[$i][COMM_CNT]?></font> <?=$arr[$i][FILE_PATH]?> <?=$arr[$i][NEW_ICON]?></td>
      <td width="85"><?=$arr[$i][INPUT_NM]?></td>
      <td width="85"><?=$arr[$i][INPUT_YMDHMS]?></td>
      <td width="50"><?=$arr[$i][VER_CNT]?></td>
  </tr>
<?
	}

	if($board->record_count < 1)
	{
		if($key) $tm_search_msg = "Searched";
		else $tm_search_msg = "Registed";
?>
  <tr bgcolor="<?=$tm_bgcolor?>" align='center'>
      <td height="24" align="center" colspan="6">No <?=$tm_search_msg?> data</td>
  </tr>
<?
	}
	// 게시물 출력 후 사용한 변수파기
	unset($arr);
?>
<!-- 여기까지 실제 레코드 출력 -->
  </table>
</form>

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
      <td width="70"><?=$LIST?></td>
      <td width="*" align="center">
		<?=$PREV_BLOCK?>&nbsp;
		<?=$PREV_PAGE?>&nbsp;
<?
	# 페이지 링크출력
	for($i=0; $i<$board->page_count; $i++)
	{
        echo $PAGES[$i];
	}
?>
		&nbsp;<?=$NEXT_PAGE?>
		&nbsp;<?=$NEXT_BLOCK?>
	  </td>
	  <?if($cf_cook_level == "aa" || $cf_cook_level == "bb"){?>
	  <td width="70" align="right"><?=$DELETE?></td>
	  <?}?>
      <td width="70" align="right"><?=$POST?></td>
    </tr>
</table>

<br>
<br>
