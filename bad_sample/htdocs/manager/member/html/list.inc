<!--검색_시작 -->
<?
	// 검색박스 출력
	if($cf_search_cd == "search100")
	{
		include $cf_skin_nm . "/t_search_select.inc";
	}
	/*else if($cf_search_cd == "search200")
	{
		include $cf_skin_nm . "/t_search_checkbox.inc";
	}
	*/
?>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td bgcolor='#FFFFFF' align="right"><?=$board->total?> articles, <?=$board->page?> page / <?=$board->page_count?> pages</td>
  </tr>
</table>
<table bgcolor="#FFFFFF" border="0" width="<?=$cf_table_wd_large?>"  cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
		<table width="<?=$cf_table_wd_small?>" border="0"  cellspacing="1" cellpadding="3">
			<tr height='26' class="table_menu" align="center">
			  <td width="7%">번호</td>
			  <td width="14%">아이디</td>
			  <td width="10%">성명</td>
			  <td width="20%">주소</td>
			  <td width="13%">휴대폰번호</td>
			  <td width="13%">주문건</td>
			  <td width="10%">이메일주소</td>	  
			  <td width="13%">가입일</td>
			 </tr>

<!-- 여기서부터 실제 레코드 출력 -->
<?
	for($i=0; $i<$board->record_count; $i++)
	{
		$query2 = "select COUNT(SEQ)  from MT_ORDER_T where INPUT_ID='".$arr[$i][CM_ID]."'AND ( PROGRESS = '02' or PROGRESS = '03' or PROGRESS = '04' or PROGRESS = '05'  )";
		$total_record2 = $DB->Value($query2);

		if($total_record2>0){
			$order_cnt = $total_record2."건";
		}else{
			$order_cnt = "";
		}
?>
			<tr height='24' class="table_body" align="center">
			  <td><?=$arr[$i][NUM]?></td>
			  <td align='left'><img src="<?=$cf_images_dir?>/<?=$arr[$i][ICON]?>"> <a href="<?=$arr[$i][LISTBODY_LINK]?>"><?=$arr[$i][CM_ID]?></a></td>
			  <td><?=$arr[$i][CM_NM]?></td>
			  <td><?=$arr[$i][CM_ADDR]?> <?=$arr[$i][CM_ADDR2]?></td>
			  <td><?=$arr[$i][CM_HP_TEL]?></td>
			  <td><?=$order_cnt?></td>
			  <td><?=$arr[$i][CM_EMAIL]?></td>
			  <td><?=$arr[$i][INPUT_YMDHMS]?></td>
			 </tr>
<?
	}

	// 게시물 출력 후 사용한 변수파기
	unset($my_arr);
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
  <form name="searchForm" method="post" action="list.html?<?=$po_basic_query?>" >  <tr> 
	<td background='<?=$cf_images_dir?>/box_bg.gif'>
		<!-- <?=ArrToSelect("level", "class='select'", "<option value=''>-----</option>", $level_arr, $level)?> &nbsp&nbsp;
		<?=ArrToSelect("check_line", "class='select'", "", $check_line_arr, $check_line)?> &nbsp;&nbsp;
		<?=ArrToSelect("keyfield", "class='select'", "", $tm_search_var, $keyfield)?>   &nbsp;&nbsp;
		<input type="text" class="box" size="15" maxlength="30" name="key" value='<?=$key?>'>&nbsp;	
		<input type="image" src="<?=$cf_images_dir?>/search.gif" align='absmiddle'></a></td> -->
	<td background='<?=$cf_images_dir?>/box_bg.gif' align='right'><?=$LIST?> <?=$POST?></td>
  </tr>
  </form>
</table>
<BR>
<BR>

<iframe name="excel" width="0" height="0"></iframe>