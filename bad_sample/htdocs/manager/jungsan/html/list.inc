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

<table bgcolor="#FFFFFF" border="0" width="<?=$cf_table_wd_large?>" cellspacing="0" cellpadding="1" >

  <tr>
    <td class="table_line">
      <table border="0" width="100%"  cellspacing="1" cellpadding="3">
        <tr class="table_menu" align="center">
          <th width='10%' rowspan="2">구분</th>
		  <th width='*' colspan="10">상태</th>
        </tr>

		<tr class="table_menu" align="center">
			<th width="16%" colspan="2">결제요청</th>
			<th width="16%" colspan="2">배송신청</th>
			<th width="16%" colspan="2">배송중</th>
			<th width="16%" colspan="2">배송완료</th>
			<th width="16%" colspan="2">완결</th>
		</tr>

		<tr class="table_body" align="center">
			<td>판매가</td>
			<td><?=number_format(get_jungsan("1",$query_where." AND a.PROGRESS = '20'","1"));?>건</td>
			<td><?=number_format(get_jungsan("1",$query_where." AND a.PROGRESS = '20'","2"));?>원</td>
			<td><?=number_format(get_jungsan("1",$query_where." AND a.PROGRESS = '50'","1"));?>건</td>
			<td><?=number_format(get_jungsan("1",$query_where." AND a.PROGRESS = '50'","2"));?>원</td>
			<td><?=number_format(get_jungsan("1",$query_where." AND a.PROGRESS = '60'","1"));?>건</td>
			<td><?=number_format(get_jungsan("1",$query_where." AND a.PROGRESS = '60'","2"));?>원</td>
			<td><?=number_format(get_jungsan("1",$query_where." AND a.PROGRESS = '70'","1"));?>건</td>
			<td><?=number_format(get_jungsan("1",$query_where." AND a.PROGRESS = '70'","2"));?>원</td>
			<td><?=number_format(get_jungsan("1",$query_where." AND a.PROGRESS = '100'","1"));?>건</td>
			<td><?=number_format(get_jungsan("1",$query_where." AND a.PROGRESS = '100'","2"));?>원</td>	
		</tr>

		<tr class="table_body" align="center">
			<td>옵션가</td>
			<td><?=number_format(get_jungsan("2",$query_where." AND a.PROGRESS = '20'","1"));?>건</td>
			<td><?=number_format(get_jungsan("2",$query_where." AND a.PROGRESS = '20'","2"));?>원</td>
			<td><?=number_format(get_jungsan("2",$query_where." AND a.PROGRESS = '50'","1"));?>건</td>
			<td><?=number_format(get_jungsan("2",$query_where." AND a.PROGRESS = '50'","2"));?>원</td>
			<td><?=number_format(get_jungsan("2",$query_where." AND a.PROGRESS = '60'","1"));?>건</td>
			<td><?=number_format(get_jungsan("2",$query_where." AND a.PROGRESS = '60'","2"));?>원</td>
			<td><?=number_format(get_jungsan("2",$query_where." AND a.PROGRESS = '70'","1"));?>건</td>
			<td><?=number_format(get_jungsan("2",$query_where." AND a.PROGRESS = '70'","2"));?>원</td>
			<td><?=number_format(get_jungsan("2",$query_where." AND a.PROGRESS = '100'","1"));?>건</td>
			<td><?=number_format(get_jungsan("2",$query_where." AND a.PROGRESS = '100'","2"));?>원</td>	
		</tr>

		<tr class="table_body" align="center">
			<td>배송료</td>
			<td><?=number_format(get_jungsan("3",$query_where." AND a.PROGRESS = '20'","1"));?>건</td>
			<td><?=number_format(get_jungsan("3",$query_where." AND a.PROGRESS = '20'","2"));?>원</td>
			<td><?=number_format(get_jungsan("3",$query_where." AND a.PROGRESS = '50'","1"));?>건</td>
			<td><?=number_format(get_jungsan("3",$query_where." AND a.PROGRESS = '50'","2"));?>원</td>
			<td><?=number_format(get_jungsan("3",$query_where." AND a.PROGRESS = '60'","1"));?>건</td>
			<td><?=number_format(get_jungsan("3",$query_where." AND a.PROGRESS = '60'","2"));?>원</td>
			<td><?=number_format(get_jungsan("3",$query_where." AND a.PROGRESS = '70'","1"));?>건</td>
			<td><?=number_format(get_jungsan("3",$query_where." AND a.PROGRESS = '70'","2"));?>원</td>
			<td><?=number_format(get_jungsan("3",$query_where." AND a.PROGRESS = '100'","1"));?>건</td>
			<td><?=number_format(get_jungsan("3",$query_where." AND a.PROGRESS = '100'","2"));?>원</td>	
		</tr>
		

		<tr class="table_body" align="center">
			<td>합계</td>
			<th width="16%" colspan="2"><?=number_format(get_jungsan("4",$query_where." AND a.PROGRESS = '20'","3"));?>원</th>
			<th width="16%" colspan="2"><?=number_format(get_jungsan("4",$query_where." AND a.PROGRESS = '50'","3"));?>원</th>
			<th width="16%" colspan="2"><?=number_format(get_jungsan("4",$query_where." AND a.PROGRESS = '60'","3"));?>원</th>
			<th width="16%" colspan="2"><?=number_format(get_jungsan("4",$query_where." AND a.PROGRESS = '70'","3"));?>원</th>
			<th width="16%" colspan="2"><?=number_format(get_jungsan("4",$query_where." AND a.PROGRESS = '100'","3"));?>원</th>
			
		</tr>

<!-- 여기까지 실제 레코드 출력 -->

	  </table>
    </td>
  </tr>
</table>
<br>

</form>

<BR>
<BR>


<iframe name="excel" width="0" height="0"></iframe>