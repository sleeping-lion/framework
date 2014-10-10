
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

<!-- board view -->
<div class="board_view">
	<table cellspacing="0" border="0" summary="공지사항 보기입니다">
		<caption>공지사항 보기</caption>
		<colgroup>
			<col style="width:80px;" />
			<col style="width:auto;" />
			<col style="width:110px;" />
		</colgroup>
		<tbody>	
			<tr>
				<th>제목</th>
				<td class="tit"><?if($my_category){ echo "<span class='cat'>[".get_code_nm($my_category)."]</span>";}?> <?=$my_subject?></td>
				<td class="date"><?=$tm_input_ymdhms?></td>
			</tr>
			
			
			<?
				// 특수기능
			if($cf_top_level_yn == "Y")	{
			?>
			<tr>
				<th>특수기능</th>
				<td>
					공개 : <?=$my_service_yn?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;공지글 : <?=$my_notice_yn?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
					ID : <?=$my_input_id?> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; IP : <?=$my_input_ip?>
				</td>
				<td>&nbsp;</td>
			</tr>
			<?
				}
			?>
		</tbody>
	</table>		
	<div class="board_viewcont">

	<?=$my_memo?>

	</div>
	
</div>
<!-- //board view -->


<?
	// 코멘트 사용여부가 y 이고 상세보기폼일때
	if($cf_comment_yn == "Y" && $MY_URI == "listbody")
	{
		include $cf_skin_nm . "/listbody_comment.inc";
	}

?>

<!-- 이전글/다음글 -->
<div class="board_listgo">
	<table cellspacing="0" border="0" summary="이전글/다음글">
		<caption>이전글/다음글</caption>
		<colgroup>
			<col style="width:80px;" />
			<col style="width:auto;" />
			<col style="width:110px;" />
		</colgroup>
		<tbody>	
			<tr>
				<th>이전글 <img src="/images/board/th_prev.gif" align="absmiddle" /></th>
				<td><?if($prev_it_no){echo $PREV;}else{echo "이전글이 없습니다.";}?></td>
				<td class="date"><?=$prev_arr[INPUT_YMDHMS]?></td>
			</tr>
			<tr>
				<th>다음글 <img src="/images/board/th_next.gif" align="absmiddle" /></th>
				<td><?if($next_it_no){echo $NEXT;}else{echo "다음글이 없습니다.";}?></td>
				<td class="date"><?=$next_arr[INPUT_YMDHMS]?></td>
			</tr>
		</tbody>
	</table>
</div>
<!-- //이전글/다음글 -->


<!-- board_bottom -->
<div class="board_bottom">
	<div class="rbtn">
		<?=$MODIFY?> <?=$REPLY?> <?=$DELETE?> <?=$LIST?>
	</div>
</div>
<!-- //board_bottom -->

<br/>
<br/>