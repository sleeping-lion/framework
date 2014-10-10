<div class="tabbtn2" style="background:url(/images/board/tab_bg_line2.png);">
	<ul>
		<?
			if($po_cate){
				$tm_class = "off";
			}else{
				$tm_class = "on";
			}
		?>
		<li class='<?=$tm_class?>'><a href='list.html?<?=$po_basic_query?>' onmouseover='tabOn(2,0)'>Total</a></li>
		<?
		for($j=0;$j < count($ctg_arr);$j++){
			if($po_cate == $ctg_arr[$j][0]){
				$tm_class = "on";
			}else{
				$tm_class = "off";
			}
		?>
		<li class='<?=$tm_class?>'><a href='list.html?<?=$po_basic_query?>&po_cate=<?=$ctg_arr[$j][CD]?>' onmouseover='tabOn(2,<?=$j+1?>)'><?=$ctg_arr[$j][NM]?></a></li>	
		<?
		}
		?>
	</ul>
</div>