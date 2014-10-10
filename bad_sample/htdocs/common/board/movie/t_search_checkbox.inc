<form name="searchForm" method="post" action="list.html?<?=$po_basic_query?>">
출력행수 <?=ArrToSelect("check_line", "class='SELECT'", "<option value=''>----</option>", $check_line_arr, $check_line)?>
<?
	$i = 0;
	foreach($tm_search_var as $k => $v)
	{
		if($i++ == 0) continue;

		$tm_name = "keyfield_" . $k;
		$tm_value = $k;
		$tm_msg = $v;

		$tm_checked = ($$tm_name == $tm_value) ? "checked" : "";

		echo "<input type='checkbox' name='$tm_name' value='$tm_value' $tm_checked>$tm_msg ";
	}
?>
<input type="text" size="40" maxlength="40" name="key" value="<?=$key?>" class="INPUT">&nbsp;
<input type="image" onMouseOver="status='search';return true;" onMouseOut="status=''" src='<?=$cf_images_dir?>/search.gif' align="absmiddle">
</form>
