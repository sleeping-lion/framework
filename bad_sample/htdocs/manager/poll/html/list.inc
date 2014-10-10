<table width="<?=$cf_table_wd_large?>" border="0"  cellspacing="0" cellpadding="0" >
  <tr>
    <td width="20%"></td>
    <td width="70%" align="center"><font size="2">총 게시물 : <b><?=$total_record?></b> (Total <b><?=$total_record?></b> Articles)</font></td>
    <td width="10%" align="right"><font size=2>( <font color="red"><?=$page?></font> / <font color="red"><?=$board->total_page?></font> )</font></td>
  </tr>
</table>

<table bgcolor="#FFFFFF" border="0" width="<?=$cf_table_wd_large?>"  cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
      <table border="0" width="100%"  cellspacing="1" cellpadding="3">
        <tr class="table_menu">
          <th width='7%'>번호</th>
          <th width='15%'>설문구분</th>
          <th width='*'>설문제목</th>
          <th width='20%'>설문기간</th>
		  <th width="10%">설문자수</th>

        </tr>

<!-- 여기부터 실제 레코드 출력 -->
<?
	for($i=0; $i<$board->record_count; $i++)
	{
?>
        <tr class="table_body">
          <td align="center"><font size="2"><?=$arr[$i][NUM]?></font></td>
          <td align="center"><font size=2><?=$arr[$i][POLL_TYPE]?></font></td>
          <td align="left"><a href="<?=$arr[$i][LISTBODY_LINK]?>"><font size=2><?=$arr[$i][SUBJECT]?></font></a></td>
          <td align="center"><font size=2><?=$arr[$i][START_DATE]?> ~<br /><?=$arr[$i][END_DATE]?></font></td>
          <td align="center"><font size=2><?=number_format($arr[$i][POLL_CNT])?></font></td>
        </tr>
<?
	}
	if($total_record < 1) {
?>
		<tr class="table_body" align="center">
			<td colspan="7">등록된 설문이 없습니다.</td>
		</tr>
<?
	}
?>
<!-- 여기까지 실제 레코드 출력 -->

	  </table>
    </td>
  </tr>
</table>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td class="page_head" height='1'></td>
  </tr>
  <tr>
    <td class="page_body" height='26' align='center'><?=$PREV_BLOCK?>&nbsp;&nbsp;<?=$PREV_PAGE?>&nbsp;&nbsp; 
<?
	for($i=0; $i<$board->page_count; $i++)
	{
        echo " $PAGES[$i] ";
	}
?>
    &nbsp;&nbsp;<?=$NEXT_PAGE?>&nbsp;&nbsp;<?=$NEXT_BLOCK?></td>
  </tr>
  <tr>
    <td class="page_bottom" height='4'></td>
  </tr>
</table>

<BR>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0" >
  <form name="searchForm" method="post" action="list.html?<?=$po_basic_query?>" >  <tr> 
	<td background='<?=$cf_images_dir?>/box_bg.gif'>
	  &nbsp; <?=ArrToSelect("check_line", "class='select'", "<option value=''></option>", $tm_check_line, $check_line)?>
	  &nbsp; <?=ArrToSelect("s_poll_type", "class='select'", "==설문 구분==", $poll_type_arr, $s_poll_type)?>
	  &nbsp; <span style="font-weight:bold;">설문명 : </span><input type="text" class="box" size="15" maxlength="30" name="s_subject" value='<?=$s_subject?>' style="height:20px">
	  &nbsp; <input type="image" src="<?=$cf_images_dir?>/search.gif" align='absmiddle'></a></td>
	<td background='<?=$cf_images_dir?>/box_bg.gif' align='right'><?=$LIST?> <?=$POST?></td>
  </tr>
  </form>
</table>
<BR>
<BR>
