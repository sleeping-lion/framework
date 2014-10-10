<?$cf_table_wd_large = "500"?>
<form name="signform" method="post">

<table border="0" width="<?=$cf_table_wd_large?>"  cellspacing="0" cellpadding="1">
  <tr>
    <td class="table_line">
      <table border="0" width="<?=$cf_table_wd_small?>"  cellspacing="1" cellpadding="3">
        <tr class="table_menu" align="center">
		  <td>관련상품등록</td>
        </tr>
	  </table>
	</td>
  </tr>
</table>

<br>
<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td align="center">
      <font size="2">총 게시물 : <b><?=$board->total?></b></font>
    </td>
    <td width="80" align="right"><font size=2>( <font color="red"><?=$board->page?></font> / <font color="red"><?=$board->total_page?></font> )</font></td>
  </tr>
</table>

<table border="0" width="<?=$cf_table_wd_large?>"  cellspacing="0" cellpadding="1">
  <tr>
    <td class="table_line">
      <table id="productListTable" border="0" width="<?=$cf_table_wd_small?>"  cellspacing="1" cellpadding="3">
        <tr class="table_menu" align="center">
				  <td width=8%>선택</td>
	        <td width=18%>상품코드</td>
          <td width=38%>상품명</td>
          <td width=10%>판매가격</td>
          <td width=6%>판매</td>
        </tr>
<?
	for($i=0; $i<$board->record_count; $i++)
	{
?>
        <tr class="table_body" align="center" >
					<td ><!--<input type="checkbox" name="fr_check_no[]" value="<?=$arr[$i][IT_NO]?>" onclick="moveBox_old('<?=$i?>','<?=$arr[$i][NO]?>','<?=$arr[$i][IT_NAME]?>');" style="cursor:hand;">-->
					<input type="checkbox" name="fr_check_no[]" onclick="moveBox(this,'<?=$arr[$i][NO]?>','<?=$arr[$i][IT_NAME]?>');" style="cursor:hand;">

					</td>
          <td><span style="display:none;"><?=$arr[$i][NO]?></span><?=$arr[$i][IT_LCLASS_NM]?></td>
					<td><?=$arr[$i][IT_NAME]?></td>
          <td><?=$arr[$i][IT_PRICE]?></td>
          <td><?=$arr[$i][IT_SELL_YN]?></td>
        </tr>
<?
	}
	if($total_record < 1) {
?>
		<tr class="table_body" align="center">
			<td colspan="5">상품이 없습니다.</td>
		</tr>
<?
	}
?>
      </table>
    </td>
  </tr>
</table>
</form>

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
      <td width="60" align="right"><input type="button" value="닫기" onclick="self.close();" class="input_button"></td>
    </tr>
</table>
<br>

<?
	// 검색박스 출력
	if($cf_search_cd == "search100")
	{
		include $cf_skin_nm . "/t_search_select2.inc";
	}
	else if($cf_search_cd == "search200")
	{

	}
?>

<!--//이미 체크된 값은 X표시 해줌//-->
<script>init();</script>
