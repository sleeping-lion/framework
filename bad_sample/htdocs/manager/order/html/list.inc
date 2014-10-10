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

<form name="signform" method="post" action="delete.html?<?=$po_adv_query?>">

<table width="<?=$cf_table_wd_large?>" border="0"  cellspacing="0" cellpadding="0" >
  <tr>
    <td width="20%"></td>
    <td width="70%" align="center"><font size="2">총 게시물 : <b><?=$total_record?></b> (Total <b><?=$total_record?></b> Articles)</font></td>
    <td width="10%" align="right"><font size=2>( <font color="red"><?=$page?></font> / <font color="red"><?=$board->total_page?></font> )</font></td>
  </tr>
</table>

<table bgcolor="#FFFFFF" border="0" width="<?=$cf_table_wd_large?>" cellspacing="0" cellpadding="1" >

  <tr>
    <td class="table_line">
      <table border="0" width="100%"  cellspacing="1" cellpadding="3">
        <tr class="table_menu" align="center">
          <td width='8%'>주문번호</td>
		  <td width='4%'>선택</td>

		  <td width='9%'>구매일</td>
		  <td width='15%'>구매제품</td>
		  <td width='9%'>옵션</td>
		  <td width='4%'>수량</td>

          <td width='6%'>구매자이름</td>
          <td width='6%'>입금자이름</td>
          <td width='6%'>요청금액</td>
		  <td width="6%">결제금액</td>
          <td width='7%'>결제방법</td>
          <td width='7%'>상태코드</td>
		  <!-- <td width='7%'>영수증</td>
		  <td width='5%'>배송</td> -->
        </tr>

<!-- 여기부터 실제 레코드 출력 -->
<?
	for($i=0; $i<$board->record_count; $i++)
	{
?>
        <tr class="table_body" align="center">
          <td><a href="<?=$arr[$i][LISTBODY_LINK]?>"><?=$arr[$i][ORDER_NO]?></a> <?=$arr[$i][AFTER_MEMO_M]?></td>
		  <td><input type="checkbox" name="check_v[]" value="<?=$arr[$i][ORDER_NO]?>"></td>
		  <td><?=substr($arr[$i][INPUT_YMDHMS],0,4)?>-<?=substr($arr[$i][INPUT_YMDHMS],4,2)?>-<?=substr($arr[$i][INPUT_YMDHMS],6,2)?></td>
		  <td><?=$arr[$i][IT_NAME]?></td>
		  <td><?if($arr[$i][OP_NAME]!="undefined"){?><?=$arr[$i][OP_NAME]?><?}?></td>
		  <td><?=$arr[$i][QAT]?></td>
          <td><?=$arr[$i][SEN_NAME]?></td>
          <td><?=$arr[$i][PAY_NAME]?></td>
          <td><?=number_format($arr[$i][AMOUNT])?></td>
          <td><?=number_format($arr[$i][RE_AMOUNT])?></td>
          <td><?=$arr[$i][SETTLEMENT_CD_NM]?></td>
		  <td><?=$arr[$i][PROGRESS_NM]?></td>
		  <!-- <td><?=$arr[$i][APP_STATUS_NM]?><?=$arr[$i][short_paper]?></td>
		  <td><?=$arr[$i][D_LINK]?></td> -->
        </tr>
<?
	}
	if($total_record < 1) {
?>
		<tr class="table_body" align="center">
			<td colspan="14">등록된 자료가 없습니다.</td>
		</tr>
<?
	}
?>
<!-- 여기까지 실제 레코드 출력 -->

	  </table>
    </td>
  </tr>
</table>
<br>

<?if($sr_progress == "50" || $sr_progress == "60" || $sr_progress == "70" || $sr_progress == "80") {
	include "order_t_progress.inc";
}
?>


<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td colspan="3" class="page_head" height='1'></td>
  </tr>
  <tr>
	<td class="page_body" width="100">&nbsp;</td>
    <td class="page_body" height='26' align='center'><?=$PREV_BLOCK?>&nbsp;&nbsp;<?=$PREV_PAGE?>&nbsp;&nbsp; 
<?
	for($i=0; $i<$board->page_count; $i++)
	{
        echo " $PAGES[$i] ";
	}
?>
    &nbsp;&nbsp;<?=$NEXT_PAGE?>&nbsp;&nbsp;<?=$NEXT_BLOCK?></td>
	<td width="100" align="right" class="page_body"><?if($cf_cook_id=="mir9"){?><?=$DELETE?><?}?>&nbsp;</td>
  </tr>
  <tr>
    <td colspan="3" class="page_bottom" height='4'></td>
  </tr>
</table>
</form>

<BR>
<BR>


<iframe name="excel" width="0" height="0"></iframe>