<!-- 제목 출력 시작 -->
<table width="<?=$cf_table_wd_large?>" border="0" cellpadding="0" cellspacing="0" style="border-top:2px solid #cacaca;border-bottom:1px solid #cacaca; ">
<form name="signform" method="post" action="">
<input type="hidden" name="fr_check_no" >
<input type="hidden" name="fr_del_no" >
<tr align="center" height='27' bgcolor="#EFEFEF">
	<?if($cf_cook_level == "aa" || $cf_cook_level == "bb"){?>
	  <td width="29"><b>선택</b></td>
	<?}?>
      <td width="42"><b>번호</b></td>
      <td width="*"><b>타이틀바</b></td>
      <td width="95"><b>시작 시간</b></td>
      <td width="95"><b>마감 시간</b></td>
      <td width="55"><b>미리보기</b></td>
    </tr>
 </table>
<table width="<?=$cf_table_wd_large?>" border="0" cellpadding="0" cellspacing="0" style="border-bottom:1px solid #cacaca;">
<!-- 여기서부터 실제 레코드 출력 -->
<?
	for($i=0; $i<$board->record_count; $i++)
	{
?>
  <tr bgcolor="<?=$tm_bgcolor?>" align='center'>
	<?if($cf_cook_level == "aa" || $cf_cook_level == "bb"){?>
	  <td width="5%"><input type='checkbox' name='fr_check_no' value='<?=$arr[$i][NO]?>'></td>
	<?}?>
      <td height="24" width="8%"><?=$arr[$i][NUM]?></td>
      <td align='left' width="50%"><img src="<?=$cf_images_dir?>/<?=$arr[$i][ICON]?>"> <?=$arr[$i][TITLE_BAR]?> <?=$arr[$i][NEW_ICON]?></td>
      <td width="15%"><?=$arr[$i][START_DAY]?></td>
      <td width="15%"><?=$arr[$i][END_DAY]?></td>
      <td width="7%"><a href="#" onclick="javascript:window.open('preview.html?no=<?=$arr[$i][NO];?>&a_gb=<?=$a_gb;?>&a_cd=<?=$a_cd;?>&a_item=<?=$a_item;?>','preview','width=<?=$arr[$i][WIDTH]?>px,height=<?=$arr[$i][HEIGHT]?>')">보기</a></td>
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



<br />

  <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
    <tr>
		<td width="200">&nbsp;</td>
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
		<td width="200" align="right">
	  <?if($cf_cook_level == "aa" || $cf_cook_level == "bb"){?>
	  <?=$DELETE?>
	  <?}?>
      &nbsp;&nbsp;<?=$POST?>
	  &nbsp;&nbsp;<?=$LIST?>
	  </td>
	  
    </tr>
</table>

<br>
<br>
