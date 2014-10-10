<!-- 제목 출력 시작 -->
<table width="<?=$cf_table_wd_large?>" border="0" cellpadding="0" cellspacing="0">
<form name="signform" method="post" action="">
<input type="hidden" name="fr_check_no" >
<input type="hidden" name="fr_del_no" >
<tr>
 <td bgcolor='#DBDBDB' colspan="7" height="2"></td>
 </tr>
<tr align="center" height='27'>
      <th width="42" background="<?=$cf_images_dir?>/th_bg.gif">번호</th>
      <th width="1" background="<?=$cf_images_dir?>/th_bg.gif"><img src="<?=$cf_images_dir?>/th_line.gif"></th>
      <th width="*" background="<?=$cf_images_dir?>/th_bg.gif">신청 기관</th>
      <th width="1" background="<?=$cf_images_dir?>/th_bg.gif"><img src="<?=$cf_images_dir?>/th_line.gif"></th>
      <th width="150" background="<?=$cf_images_dir?>/th_bg.gif">견학 일시</th>
      <th width="1" background="<?=$cf_images_dir?>/th_bg.gif"><img src="<?=$cf_images_dir?>/th_line.gif"></th>
      <th width="85" background="<?=$cf_images_dir?>/th_bg.gif">신청일</th>
    </tr>
 </table>
<table width="<?=$cf_table_wd_large?>" border="0" cellpadding="0" cellspacing="0">
<!-- 여기서부터 실제 레코드 출력 -->
<?
	for($i=0; $i<$board->record_count; $i++)
	{
?>
  <tr bgcolor="<?=$tm_bgcolor?>" align='center'>

      <td height="24" width="8%"><?=$arr[$i][NUM]?></td>
      <td align='left' width="*">&nbsp;<a href="<?=$arr[$i][LISTBODY_LINK];?>"><?=$arr[$i][COMPANY]?></a></td>
      <td width="25%"><?=$arr[$i][TOUR_DATE]?></td>
      <td width="15%"><?=$arr[$i][INPUT_YMDHMS]?></td>

  </tr>
<?
	}

	if($board->record_count < 1)
	{
		if($key) $tm_search_msg = "검색된";
		else $tm_search_msg = "등록된";
?>
  <tr bgcolor="<?=$tm_bgcolor?>" align='center'>
      <td height="24" align="center"><?=$tm_search_msg?> 게시글이 없습니다.</td>
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
	  
    </tr>
</table>

<br>
<br>
