<!-- search -->
<div class="search_box">
	<form name="searchForm" method="post" action="/common/board/list.html?<?=$po_basic_query?>">
	<?=ArrToSelect("keyfield", "class='select22'", "", $tm_search_var, $keyfield)?>
	<input type="text" size="40" maxlength="40" name="key" value="<?=$key?>" class="box" tabindex="1">
	<button type="button" class="search_btn" onclick="form.submit();">search</button>
	</form>
</div>

<!-- //search -->


