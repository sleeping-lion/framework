

<form name="searchForm" method="post" action="list.html?<?=$po_basic_query?>">
<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td align="center" bgcolor='#F1F1F1'><?=ArrToSelect("keyfield", "class='select'", "", $tm_search_var, $keyfield)?>&nbsp;&nbsp;<input type="text" size="30" maxlength="30" name="key" value="<?=$key?>" class="box" tabindex="1">&nbsp;&nbsp;<input type="image" src="<?=$cf_images_dir?>/search.gif" align="absmiddle" onMouseOver="status='search';return true;" onMouseOut="status=''" tabindex="2"></td>
   </tr>
  <!--  <?if($_SERVER[REMOTE_ADDR]=="210.97.226.101"){echo $keyfield;}   ?> -->

</table>
</form>
