
<script language="javascript">
<!--
function pop_img(img) {
      var window_left = (screen.width-640)/2;
      var window_top = (screen.height-480)/2;
      url = "item_image_t.html?a_gb=<?=$a_gb?>&a_cd=<?=$a_cd?>&a_item=<?=$a_item?>&po_no=<?=$po_no?>&po_img=" + img;

      window.open(url,"img",'width=500,height=610,scrollbars=yes,status=no,top=' + window_top + ',left=' + window_left + '');
}
//-->
</script>


<!-- 제품상세 view -->
<div class="txt_area mgt25">

	<div class="product_title"><span class="model"><?=$my_subject?></span></div>
	<div class="product_view">
		<?=$my_memo?>
	</div>
</div>
<!-- //board view -->

<!-- board_bottom -->
<div class="board_bottom">
	<div class="rbtn">
		<?=$MODIFY?> <?=$REPLY?> <?=$DELETE?> <?=$LIST?>
	</div>
</div>
<!-- //board_bottom -->

<br/>
<br/>