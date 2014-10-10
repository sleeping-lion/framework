
<!-- board lst -->
<div class="board_lst">
	<table cellspacing="0" border="0" summary="공지사항 리스트입니다">
		<caption>공지사항 리스트</caption>
		<colgroup>
			<? if($cf_top_level_yn =="Y"){?>
			<col style="width:50px;" />
			<? } ?>
			<col style="width:50px;" />
			<col style="width:auto;" />
			<col style="width:110px;" />
			<col style="width:110px;" />
		</colgroup>
		<thead>	
			<tr>
			<? if($cf_top_level_yn =="Y"){?>
				<th><a href="#" onclick="check_all();">선택</a></th>
			<? } ?>
				<th>번호</th>
				<th>제목</th>
				<th>작성자</th>
				<th>등록일</th>
			</tr>
		</thead>
		<tbody>
			<?
				for($i=0; $i<$notice_board->record_count; $i++)
				{
			?>
			<tr>
				<? if($cf_top_level_yn =="Y"){?>
				<td class="notice"><input type="checkbox" name="fr_check_no" value="<?=$notice_arr[$i]["NO"];?>" /></td>
				<? } ?>
				<td class="notice"><?=$notice_arr[$i][NUM]?></td>
				<td class="list_title notice"><?=$notice_arr[$i][INDENT]?> <?=$notice_arr[$i][LISTBODY_LINK]?><font color="#0099FF"><!-- 코멘트갯수삽입 --><?=$notice_arr[$i][COMM_CNT]?></font> <?=$notice_arr[$i][NEW_ICON]?></td>
				<td class="notice"><?=$notice_arr[$i][INPUT_NM]?></td>
				<td class="notice"><?=$notice_arr[$i][INPUT_YMDHMS]?></td>
			</tr>
			<?
				}
				// 게시물 출력 후 사용한 변수파기
				unset($notice_arr);
			?>
			<!-- 여기서부터 실제 레코드 출력 -->
			<?
				for($i=0; $i<$board->record_count; $i++)
				{
			?>
			<tr>
				<? if($cf_top_level_yn =="Y"){?>
				<td><input type="checkbox" name="fr_check_no" value="<?=$arr[$i]["NO"];?>" /></td>
				<? } ?>

				<td><?=$arr[$i][NUM]?></td>

				<td class="list_title"><?=$arr[$i][INDENT]?><img src="<?=$cf_images_dir?>/<?=$arr[$i][ICON]?>"> <?=$arr[$i][SUBJECT]?> <font color="#0099FF"><?=$arr[$i][COMM_CNT]?></font></td>
				<td><?=$arr[$i][SIGN_NM]?></td>
				<td><?=$arr[$i][INPUT_YMDHMS]?></td>
			</tr>
			<?
				}

				if($board->record_count < 1)
				{
					if($key) $tm_search_msg = "검색된";
					else $tm_search_msg = "등록된";
			?>
			<tr>
				<td height="24" colspan='5'><?=$tm_search_msg?> 게시글이 없습니다.</td>
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

<input type="hidden" name="fr_del_no" id="fr_del_no" value="123"/>

<!-- board_bottom -->
<div class="board_bottom">
	<div class="rbtn">
		<?//=$MOVE?> <?=$DELETE?> <?=$POST?> <?=$LIST?>
	</div>
</div>
<!-- //board_bottom -->

<br>
<br>
