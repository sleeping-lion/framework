<?
	// 선택한 게시물의 입력값을 뽑아낸다.
	include "t.inc";



##############################################################################
	// 1.첨부화일
	$tm_real_path = $cf_savedir . "/" . $my_popup_img;
	$tm_real_path_physical = $cf_doc_root . $tm_real_path;
	if(is_file($tm_real_path_physical))
		{
			//$tm_attach_file_tmp = "<img src='$cf_images_dir/file.gif' align='absmiddle'> <a href='/files/download.html?file=" . base64_encode($tm_real_path_physical) . "' target='fdown'>$my_attach_path</a>";
			$tm_attach_file_tmp = "<img src='$tm_real_path' align='absmiddle'>";
		}
		else
		{
			$tm_attach_file_tmp = "첨부된 화일이 없습니다.";
		}
	





	// ------------------------------------------------------------ //
	//	버튼처리 시작
	// ------------------------------------------------------------ //
	#이전버튼
	$PREV = "<a href=\"$tm_pn_url&po_no=$prev_it_no\" onMouseOver=\"status='reload articles';return true;\" onMouseOut=\"status=''\"><img src=\"$cf_images_dir/btn_pre.gif\" align='absmiddle'></a>";
	#다음버튼
	$NEXT = "<a href=\"$tm_pn_url&po_no=$next_it_no\" onMouseOver=\"status='reload articles';return true;\" onMouseOut=\"status=''\"><img src=\"$cf_images_dir/btn_next.gif\" align='absmiddle'></a>";

	# 리스트 버튼
	$LIST = "<a href='list.html?$po_adv_query&page=$page' onMouseOver=\"status='reload articles';return true;\" onMouseOut=\"status=''\"><img src='$cf_images_dir/list.gif' align='absmiddle'></a>";

	# 쓰기 버튼
	if($cf_post_level_yn == "Y")
	{
		$POST = "<a href='postform.html?$po_adv_query&page=$page' onMouseOver=\"status='새 글쓰기';return true;\" onMouseOut=\"status=''\"><img src='$cf_images_dir/post.gif' align='absmiddle'></a>";
	}

	# 답변 버튼
	if($my_notice_yn == "Y")
	{
		$REPLY = "";
	}
	else if($cf_reply_level_yn == "Y" && $cf_reply_yn == "Y")
	{
		$REPLY = "<a href=\"replyform.html?$po_adv_query&page=$page&po_no=$po_no\" onMouseOver=\"status='reply to this article'; return true;\" onMouseOut=\"status=''\"\"><img src=\"$cf_images_dir/reply.gif\" border=0 align='absmiddle'></a>";
	}

	# 수정 버튼
	if($my_notice_yn == "Y" && $cf_top_level_yn != "Y")
	{
		$MODIFY = "";
	}
	else if($cf_modify_level_yn == "Y" && ($cf_top_level_yn == "Y" || !$my_input_id || $my_input_id == $cf_cook_id))
	{
		$MODIFY = "<a href=\"modifyform.html?$po_adv_query&page=$page&po_no=$po_no\" onMouseOver=\"status='modify this article';return true;\" onMouseOut=\"status=''\"\"><img src=\"$cf_images_dir/modify.gif\" border=0 align='absmiddle'></a>";
	}
	else
	{
		$MODIFY = "";
	}

	# 삭제 버튼
	$DELETE = "";
	if($my_notice_yn == "Y" && $cf_top_level_yn == "Y")
	{
		$DELETE = "<img src=\"$cf_images_dir/delete.gif\" border=0 align='absmiddle' onClick=\"DelConfirm('delete.html?$po_adv_query&page=$page&po_no=$po_no')\" style='cursor:hand'>";
	}
	else if($cf_delete_level_yn == "Y")
	{
		if(!$my_input_id)
		{
			$DELETE = "<a href=\"deleteform.html?$po_adv_query&page=$page&po_no=$po_no\" onMouseOver=\"status='delete this article';return true;\" onMouseOut=\"status=''\"\"><img src=\"$cf_images_dir/delete.gif\" border=0 align='absmiddle'></a>";
		}
		else if($cf_cook_id && ($cf_top_level_yn == "Y" || $my_input_id == $cf_cook_id))
		{
			$DELETE = "<img src=\"$cf_images_dir/delete.gif\" border=0 align='absmiddle' onClick=\"DelConfirm('delete.html?$po_adv_query&page=$page&po_no=$po_no')\" style='cursor:hand'>";
		}
	}
	// ------------------------------------------------------------ //
	//	버튼처리 끝
	// ------------------------------------------------------------ //

	########## 상세보기 출력화일 ##########
	include $cf_skin_nm . "/listbody.inc";
	#######################################

	
			include "listview.inc";
		

?>
