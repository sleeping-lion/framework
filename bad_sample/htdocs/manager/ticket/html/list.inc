<table border="0" width="<?=$cf_table_wd_large?>"  cellspacing="0" cellpadding="1">
  <tr>
    <td class="table_line">
      <table border="0" width="<?=$cf_table_wd_small?>"  cellspacing="1" cellpadding="3">
        <tr class="table_menu" align="center">
		  <td><b>수강권 관리</b></td>
        </tr>
	  </table>
	</td>
  </tr>
</table>
<br>

<font color="#FF0000">* 참고사항 : 수강권번호는 일련번호를 제외한 번호입니다.ㄹ</font>
<table border="0" width="<?=$cf_table_wd_large?>"  cellspacing="0" cellpadding="1">
  <tr>
    <td class="table_line">
      <table border="0" width="<?=$cf_table_wd_small?>"  cellspacing="1" cellpadding="3">
        <tr class="table_menu" align="center">
		  <td width="10%">번호</td>
		  <td width="30%">수강권번호</td>
		  <td width="15%">시작번호</td>
		  <td width="15%">끝번호</td>
		  <td width="20%">등록일</td>
		  <td width="10%">사용여부</td>
        </tr>
<?
	for($i=0; $i<$board->record_count; $i++)
	{
?>
        <tr class="table_body" align="center">
		  <td><?=$arr[$i]['NUM']?></td>
		  <td><a href="<?=$arr[$i]['LISTBODY_LINK']?>"><?=$arr[$i]['TI_KEY']?></a></td>
		  <td><?=$arr[$i]['TI_START']?></td>
		  <td><?=$arr[$i]['TI_END']?></td>
		  <td><?=$arr[$i]['INPUT_YMDHMS']?></td>
		  <td><?=$arr[$i]['TI_USE_YN']?></td>
        </tr>
<?
	}
	if($total_record < 1) {
?>
		<tr class="table_body" align="center">
			<td colspan="8">등록된 수강권이 없습니다.</td>
		</tr>
<?
	}
?>
      </table>
    </td>
  </tr>
</table>
<br>
<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
  <tr> 
    <td width="<?=$cf_table_wd_small?>" align="center">
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
      <td width="60" align="right"><?=$POST?></td>
    </tr>
</table>
<br>

<?
	// 검색박스 출력
	if($cf_search_cd == "search100")
	{
		include $cf_skin_nm . "/t_search_select.inc";
	}
	else if($cf_search_cd == "search200")
	{

	}
?>
