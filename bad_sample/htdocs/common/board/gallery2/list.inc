<div class="gallery_area">
	<ul>	
<?
	$t_count = $board->record_count;
	for($i=0; $i<$t_count; $i+=4){
		for($j=0; $j<4; $j++){
			$cnts = $i+$j;
			if($t_count>$cnts){
?> 
		<li>
			<div class="photo"><a href="<?=$arr[$cnts][LISTBODY_LINK]?>"><?=$arr[$cnts][IMAGE]?></a></div>
			<div class="st"><span class="subject"><?=$arr[$cnts][SUBJECT_G]?></span>&nbsp;&nbsp;<!-- <span class="hit">(<?=$arr[$cnts][VER_CNT]?>)</span><br /> --><span class="category"></span>   </div>
			<div class="cont"><?=sl_mb_substr(strip_tags($arr[$cnts][MEMO]), 40, "...");?></div>
		</li>

<?
			}else{
?>
		<li class="none">
			&nbsp;
		</li>
<?
			}
		}
		if($i < $cf_num_per_page){
		?>
			</ul>					
		</div>	
		<div class="gallery_area mgt20">
			<ul>						
		<?
		}
	}
?>
	</ul>					
</div>	

<?
	// 등록된 사진이 없는경우
	if($board->record_count < 1)
	{
		if($key) $tm_search_msg = "검색된";
		else $tm_search_msg = "등록된";
?>
<table border="0" cellpadding=0 cellspacing=0 width="<?=$cf_table_wd_large?>">
  <tr>
    <td height="200" align='center' valign="middle">
	  <?=$tm_search_msg?> 이미지가 없습니다
    </td>
  </tr>
</table>
<?
	}
?>
 
</table>


<!-- paging -->
<div class="paging">
	 <ul>
		<li><?=$FIRST_PAGE?></li>
		<li><?=$PREV_BLOCK?></li>
		<?
			# 페이지 링크출력
			for($i=0; $i<$board->page_count; $i++)
			{
				echo $PAGES[$i];
			}
		?>
		<li><?=$NEXT_BLOCK?></li>
		<li><?=$LAST_PAGE?></li> 
	</ul> 
</div>	
<!-- //paging -->

<!-- board_bottom -->
<div class="board_bottom">
	<div class="rbtn">
		<?=$POST?> <?=$LIST?>
	</div>
</div>
<!-- //board_bottom -->

<br>
<br>
