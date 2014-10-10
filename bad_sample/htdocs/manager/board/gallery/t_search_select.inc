<form name="searchForm" method="post" action="list.html?<?=$po_basic_query?>">
<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
  <tr bgcolor='#F1F1F1'>
       <td width="200"><img src="<?=$cf_images_dir?>/search_txt.gif"></td>
       <td width="280" align="right"><?=ArrToSelect("keyfield", "class='select'", "", $tm_search_var, $keyfield)?>&nbsp;&nbsp;</td>
	<td width="15%"><input type="text" size="15" maxlength="30" name="key" value="<?=$key?>" class="box" tabindex="1">&nbsp;&nbsp;</td>
   <td width="120" align="right"><input type="image" src="<?=$cf_images_dir?>/search.gif" align="absmiddle" onMouseOver="status='search';return true;" onMouseOut="status=''" tabindex="2"><img src="<?=$cf_images_dir?>/search_end.gif"></td>
   </tr>
</table>
</form>