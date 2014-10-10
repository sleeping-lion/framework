<!-- search -->
<div class="search_box">
	<form name="searchForm" method="post" action="/common/product/list.html?<?=$po_basic_query?>">
	<input type="hidden" name="po_l_cate" value="<?=$po_l_cate?>"/>
	<input type="hidden" name="po_m_cate" value="<?=$po_m_cate?>"/>
	<input type="hidden" name="keyfield" value="total"/>
	<input type="text" maxlength="30" name="key" value="<?=$key?>" style="width:120px;">
	<button type="button" class="search_btn" onclick="form.submit();">search</button>
	</form>
</div>

<!-- //search -->