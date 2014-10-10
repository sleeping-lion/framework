<?if($a_gb == "board" && $a_cd=="50"){?>
<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
<tr align="center" height='2'>
  <td width="60"><img src="/images/open_text.gif"></td>
</tr>
</table>
<?}?>

<!-- 제목 출력 시작 -->

<style type="text/css">
<!--
.regist {font-family : "나눔고딕";	  font-size:10pt;	color : #245caf;border-bottom:2px solid #cfcfcf;height:37px;}
-->
</style>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="3" cellpadding="10" >
  <tr>
    <td align="center" bgcolor='#FFFFFF'>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
 <tr>
   <td height='2' bgcolor='#245caf'></td>
 </tr>
</table>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="3" frame='hsides' align="center">
  <tr>
		 <th class="regist" style="width:50px;text-align:center">번호</th>
		 <th class="regist" width="*" style="width:520px;text-align:center">연락처</th>
		 <th class="regist" style="width:100px;text-align:center">접수일</th>
		 <th class="regist" style="width:100px;text-align:center">접수자</th>
		 <th class="regist" style="width:70px;text-align:center">처리상태</th>
  </tr>
  </tr>
		<?
			for($i=0; $i<$board->record_count; $i++)
			{
		?>
		
        <tr height='35'>
            <td align="center" width="50"><?=$arr[$i][NUM]?></td>
			<td align="center" style="padding-left:10px;" width="*"><a href="listbody.html?a_gb=<?=$a_gb?>&a_cd=<?=$a_cd?>&a_item=<?=$a_item?>&sm=<?=$sm?>&page=<?=$page?>&po_no=<?=$arr[$i][NO]?>"><?=$arr[$i][HP_TEL]?> <?if($arr[$i][TEL]){?>/ <?=$arr[$i][TEL]?><?}?></td>
			<td align="center" width="100"><?=$arr[$i][INPUT_YMDHMS]?></td>
			<td align="center" width="100"><?=$arr[$i][INPUT_NM]?></td>
			<td align="center" width="70"><? if($arr[$i][REPLY]=="Y"){?><a href="list.html?a_gb=<?=$a_gb?>&a_cd=<?=$a_cd?>&a_item=<?=$a_item?>&sm=<?=$sm?>&page=<?=$page?>&mod_no=<?=$arr[$i][NO]?>&status=N">완료</a><? } else{ ?><a href="list.html?a_gb=<?=$a_gb?>&a_cd=<?=$a_cd?>&a_item=<?=$a_item?>&sm=<?=$sm?>&page=<?=$page?>&mod_no=<?=$arr[$i][NO]?>&status=Y">접수중</a><? }?></td>

        </tr>
		<? 
			}
		?>
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

      <td width="75" align="right"><?//=$POST?></td>
      <td width="75" align="right"><?=$LIST?></td>

    </tr>
</table>

<br>
<br>

