<?

if($total_record > $cf_num_per_page){
	$faq_count = $cf_num_per_page; 
}else{
	$faq_count = $total_record; 
} 

?>

<!-- board lst -->
<div class="board_lst">
	<table cellspacing="0" border="0" summary="공지사항 리스트입니다">
		<caption>공지사항 리스트</caption>
		<colgroup>
			<col style="width:50px;" />
			<?IF($ctg_arr){?>
			<col style="width:90px;" />
			<?}?>
			<col style="width:auto;" />
		</colgroup>
		<thead>	
			<tr>
				<th>번호</th>
				<?IF($ctg_arr){?>
				<th>분류</th>
				<?}?>
				<th>제목</th>
			</tr>
		</thead>
		<tbody>
			<?
				for($i=0; $i<$board->record_count; $i++)
				{
			?>
			<tr >
				<td><?=$arr[$i][NUM]?></td>
				<?IF($ctg_arr){?>
				<td class="list_cat">[<?=get_code_nm($arr[$i][CATEGORY])?>]</td>
				<?}?>
				<td id="faq_subj<?=$i?>" class="list_title"><a href="javascript:faq_view(<?=$i?>,<?=$faq_count?>)" alt=""><?=$arr[$i][SUBJECT_FAQ]?></a></td>
			</tr>

			<tr id="faq_memo<?=$i?>" class="faq_choice">
				<td class="faq_view" style="text-align:center;vertical-align:top;"><img src="/images/board/ico_reply.gif" alt="답변" /></td>
				<td class="faq_view" colspan="2"><?=$arr[$i][MEMO]?>
				<? # 수정 버튼
if($cf_modify_level_yn == "Y")
{
	echo "<div class='btn_right'><a href=\"/common/board/listbody.html?$po_adv_query&page=$page&po_no=".$arr[$i][NO]."\" onMouseOut=\"status=''\"  class='btn_type'><span>관리</span></a></div>";
}
?>
				</td>
			</tr>
			<?
				}

				if($board->record_count < 1)
				{
					if($key) $tm_search_msg = "검색된";
					else $tm_search_msg = "등록된";
			?>
			<tr>
				<td height="24" colspan='3'><?=$tm_search_msg?> 게시글이 없습니다.</td>
			</tr>
			<?
				}
				// 게시물 출력 후 사용한 변수파기
				unset($arr);
			?>
			<!-- 여기까지 실제 레코드 출력 -->
		</tbody>
	</table>
</div>
<!-- //board lst -->


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
		<?=$POST?> <?//=$LIST?>
	</div>
</div>
<!-- //board_bottom -->

<br />
