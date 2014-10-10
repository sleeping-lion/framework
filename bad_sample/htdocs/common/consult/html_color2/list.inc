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
		 <th class="regist" width="7%">번호</th>
		 <!--th class="regist" width="*">A/S접수 제목</th-->
		 <th class="regist" width="15%">접수일</th>
		 <th class="regist" width="*">고장 증상</th>

		 <th class="regist" width="15%">처리상태</th>
  </tr>
  </tr>
		<?
			for($i=0; $i<$board->record_count; $i++)
			{
		?>
		
        <tr height='35'>
            <td align="center"><?=$arr[$i][NUM]?></td>
			<!--td align="center"><?=$arr[$i][SUBJECT]?></td-->
			<td align="center"><a href="listbody.html?<?=$po_adv_query;?>&page=<?=$page;?>&po_no=<?=$arr[$i][NO];?>"><?=$arr[$i][INPUT_YMDHMS]?></a></td>
			<td align="left"><a href="listbody.html?<?=$po_adv_query;?>&page=<?=$page;?>&po_no=<?=$arr[$i][NO];?>"><?=$arr[$i][TROUBLE_STATE]?></a></td>
			<td align="center"><? if($arr[$i][REPLY]=="Y"){?>완료<? } else{ ?>접수중<? }?></td>

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

      <td width="75" align="right"><?=$POST?></td>
      <td width="75" align="right"><?=$LIST?></td>

    </tr>
</table>

<br>
<br>





<!-- 


<table width="<?=$cf_table_wd_large?>" border="0" cellpadding="0" cellspacing="0">
<tr>
    <td style="border-bottom:3px solid #568832;">&nbsp;</td>
</tr>
<tr>
    <td background="<?=$cf_images_dir?>/view_bg.gif" style="padding-left:15px">
        <table width="<?=$cf_table_wd_large-20?>" border="1" cellspacing="0" cellpadding="3" frame='hsides' bordercolorlight='#aaaaaa' bordercolordark='#FFFFFF'>
		<tr>
			<th width="10%">번호</th>
			<th width="*">A/S 접수 제목</th>
			<th width="15%">접수일</th>
			<th width="15%">처리상태</th>
		</tr>
		<?
			for($i=0; $i<$board->record_count; $i++)
			{
		?>
		
        <tr height='37'>
            <td align="center"><?=$arr[$i][NUM]?></td>
			<td align="center"><?=$arr[$i][SUBJECT]?></td>
			<td align="center"><?=$arr[$i][INPUT_YMDHMS]?></td>
			<td align="center"><? if($arr[$i][REPLY]=="Y"){?>완료<? } else{ ?>접수중<? }?></td>

        </tr>
		<? 
			}
		?>


        </table>


    </td>
</tr>
<tr>
    <td style="border-top:2px solid #568832;">&nbsp;</td>
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

      <td width="75" align="right"><?=$POST?></td>
      <td width="75" align="right"><?=$LIST?></td>

    </tr>
</table>

<br>
<br>
 -->