<table border="0" width="<?=$cf_table_wd_large?>"  cellspacing="0" cellpadding="1">
  <tr>
    <td class="table_line">
      <table border="0" width="<?=$cf_table_wd_small?>"  cellspacing="1" cellpadding="3">
        <tr class="table_menu" align="center">
		  <td> 제품분류 관리</td>
        </tr>
	  </table>
	</td>
  </tr>
</table>

<br>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td align="center">
      <font size="2">총 대분류 : <b><?=$board->total?></b></font>
    </td>
    <td width="80" align="right"><font size=2>( <font color="red"><?=$board->page?></font> / <font color="red"><?=$board->total_page?></font> )</font></td>
  </tr>
</table>

<table border="0" width="<?=$cf_table_wd_large?>"  cellspacing="0" cellpadding="1">
  <tr>
    <td class="table_line">
      <table border="0" width="<?=$cf_table_wd_small?>"  cellspacing="1" cellpadding="3">
        <tr class="table_menu" align="center">
		  <td width=45%>제품 분류명</td>
		  <!--<td width=15%>메뉴 이미지</td>-->
          <td width=40%>비고</td>
        </tr>
<?
	for($i=0; $i<$board->record_count; $i++)
	{
?>
        <tr class="table_body" align="center">
		  <td align="left">▶ <a href="<?=$arr[$i][LISTBODY_LINK]?>"><?=$arr[$i][NM]?></a></td>
		  <!--<td><?=$arr[$i][NM_IMG]?></td>-->
          <td><?=$arr[$i][REG]?> <?=$arr[$i][MODIFY]?> <?=$arr[$i][DEL]?></td>
        </tr>
<?
		if(cate_check($arr[$i][CD])) {
			cate_view($arr[$i][CD],1,$page);
		}
	}
	if($total_record < 1) {
?>
		<tr class="table_body" align="center">
			<td colspan="8">등록된 제품분류가 없습니다.</td>
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
