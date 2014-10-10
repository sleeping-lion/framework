<center>
<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
  <form name="searchForm" method="post" action="list.html?<?=$po_basic_query?>">
  <tr align="right" height='30'>
    <td align="right">
	  <!--<?=ArrToSelect("po_it_lclass", " onChange='document.searchForm.submit();' style='font-size=9pt'", "대분류", $lclass_arr, $po_it_lclass)?>
	  <?=ArrToSelect("po_it_mclass", " onChange='document.searchForm.submit();' style='font-size=9pt'",  "중분류",$mclass_arr, $po_it_mclass)?>
	  <?=ArrToSelect("po_it_sclass", " onChange='document.searchForm.submit();' style='font-size=9pt'",  "소분류",$sclass_arr, $po_it_sclass)?>
	  &nbsp;-->
	<?=ArrToSelect("check_line", "class='select'", "", $tm_check_line_var, $check_line)?>&nbsp;&nbsp;</td>
    <td width="90"><?=ArrToSelect("keyfield", "class='select'", "", $tm_search_var, $keyfield)?>&nbsp;&nbsp;</td>
	<td width="100"><input type="text" size="15" maxlength="30" name="key" value="<?echo($key)?>" class="box" tabindex="1">&nbsp;&nbsp;</td>
    <td width="40"><img src="<?=$cf_images_dir?>/search.gif" align="absmiddle" border="0" onClick="document.searchForm.submit();" onKeyPress="document.searchForm.submit();" onMouseOver="status='search';return true;" onMouseOut="status=''" style="cursor:hand" tabindex="2"></td>
  </tr>
  </form>
</table>
</center>
