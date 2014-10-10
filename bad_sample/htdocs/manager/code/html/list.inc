<table width="<?echo($cf_table_wd_large)?>" border="0"  cellspacing="0" cellpadding="0">
  <tr>
    <td><?=$tm_code_path?></td>
  </tr>
</table>

<table bgcolor="#FFFFFF" width="<?=$cf_table_wd_large?>" border="0"  cellspacing="0" cellpadding="0" >
  <tr>
    <td width="20%"></td>
    <td width="70%" align="center"><font size="2">총 게시물 : <b><?=$total_record?></b> (Total <b><?=$total_record?></b> Articles)</font></td>
    <td width="10%" align="right"><font size=2>( <font color="red"><?=$page?></font> / <font color="red"><?=$board->total_page?></font> )</font></td>
  </tr>
</table>

<table bgcolor="#FFFFFF" border="0" width="<?=$cf_table_wd_large?>"  cellspacing="0" cellpadding="1" >
  <tr>
    <td class='tdxback'>
      <table border="0" width="100%"  cellspacing="1" cellpadding="3">
        <tr>
          <td class="th0" width='7%'>번호</td>
          <td class="th0" width='14%'>구분코드</td>
          <td class="th0" width='23%'>구분코드명</td>
          <td class="th0" width='14%'>코드</td>
          <td class="th0" width='23%'>코드명</td>
          <td class="th0" width='19%'>관리코드</td>
        </tr>

<!-- 여기부터 실제 레코드 출력 -->
<?
	for($i=0; $i<$board->record_count; $i++)
	{
?>
        <tr>
          <td bgColor=#FFFFFF align="center"><font size="2"><?=$arr[$i][NUM]?></font></td>
          <td bgColor=#FFFFFF align="left"><font size=2><?=$arr[$i][GB]?></font></td>
          <td bgColor=#FFFFFF align="left"><a href="<?=$arr[$i][LISTBODY_LINK]?>"><font size=2><?=$arr[$i][GB_NM]?></font></a></td>
          <td bgColor=#FFFFFF align="left"><font size=2><?=$arr[$i][CD]?></font></td>
          <td bgColor=#FFFFFF><a href="<?=$arr[$i][LIST_LINK]?>"><font size=2><?=$arr[$i][CD_NM]?></font></a></td>
          <td bgColor=#FFFFFF align="left"><font size=2><?=$arr[$i][CON_CD]?></font></td>
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
    <td bgcolor='#FFFFFF' height='1'></td>
  </tr>
  <tr>
    <td bgcolor='#EAEAEA' height='26' align='center'><?=$PREV_BLOCK?>&nbsp;&nbsp;<?=$PREV_PAGE?>&nbsp;&nbsp; 
<?
	for($i=0; $i<$board->page_count; $i++)
	{
        echo " $PAGES[$i] ";
	}
?>
    &nbsp;&nbsp;<?=$NEXT_PAGE?>&nbsp;&nbsp;<?=$NEXT_BLOCK?></td>
  </tr>
  <tr>
    <td bgcolor='#D8D8D8' height='4'></td>
  </tr>
</table>

<BR>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0" >
  <form name="searchForm" method="post" action="list.html?<?=$po_basic_query?>&po_gb=<?=$po_gb?>">  <tr> 
	<td background='<?=$cf_images_dir?>/box_bg.gif'>
	  &nbsp; <?=ArrToSelect("check_line", "class='select'", "<option value=''></option>", $tm_check_line, $check_line)?>
	  &nbsp; <?=ArrToSelect("keyfield", "class='select'", "", $tm_search_var, $keyfield)?>
	  &nbsp; <input type="text" class="box" size="15" maxlength="30" name="key" value='<?=$key?>'>
	  &nbsp; <input type="image" src="<?=$cf_images_dir?>/search.gif" align='absmiddle'></a></td>
	<td background='<?=$cf_images_dir?>/box_bg.gif' align='right'><?=$LIST?> <?=$POST?></td>
  </tr>
  </form>
</table>
<BR>
<BR>
