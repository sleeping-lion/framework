   <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
   <tr>
   <td>
<div id="print_top" style="text-align:right;padding:5px;"><input type="button"  value="인쇄" style="border:1px solid gray; font-weight:bold; padding:2px;cursor:hand;" onclick="print_start('<?=$po_basic_query;?>&po_no=<?=$po_no;?>');" /></div>
<table width="95%" border="0" cellpadding="0" cellspacing="0">
	<tr>
		<th style="height:100px;padding-top:40"><h1 style="text-decoration:underline;">견학 신청서</h1></th>
	</tr>

	<tr>
		<td align="center" height="50">삼육식품 회사에 아래와 같이 견학을 신청합니다.</td>
	</tr>

	<tr>
		<td align="center" height="80">-  아&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;래 -</td>
	</tr>
	
	<tr>
		<td height="30" style="padding-left:65px">신청기관 : <?=$my_company;?></td>
	</tr>

	<tr>
		<td height="30" style="padding-left:65px">인&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;원 : <?=$my_people_cnt;?></td>
	</tr>

	<tr>
		<td height="30" style="padding-left:65px">견학일시 : <?=$my_tour_date;?></td>
	</tr>

	<tr>
		<td height="30" style="padding-left:65px">연 락 처(단체) : <?=$my_tel1;?></td>
	</tr>
	
	<tr>
		<td height="30" style="padding-left:65px">연 락 처(단체) : <?=$my_tel2;?></td>
	</tr>

	<tr>
		<td height="200" align="center"><?=$tm_input_ymdhms;?></td>
	</tr>
</table>
</td>
</tr>
</table>


  <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
    <tr height='1'>
      <td bgcolor='#DBDBDB'></td>
    </tr>
    <tr height='4'>
      <td bgcolor='#F5F5F5'></td>
    </tr>
  </table>
  <br><br><br>

<?



	// 삭제폼에서 listbody.inc 를 가져다 쓰는 경우를 고려했다.
	// 삭제폼에서 $DELETE_PRINT_YN = "N"; 를 넣은경우 아래 부분은 출력하지 않는다.
	if($DELETE_PRINT_YN != "N")
	{
?>
<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="3" cellpadding="3">
  <tr>
    <td align="center">
		<?if($prev_it_no){echo $PREV;}else{echo "&nbsp;";}?>&nbsp;&nbsp;
		<?if($next_it_no){echo $NEXT;}else{echo "&nbsp;";}?>
	</td>
  </tr>
</table>

  <br>
  <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
    <tr>
      <td height="36" align="right"><?=$MODIFY?> <?=$DELETE?> <?=$LIST?></td>
    </tr>
  </table>

<BR>
<BR>
<?
	}
?>