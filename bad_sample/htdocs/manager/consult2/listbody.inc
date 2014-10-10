<?
	// 선택한 게시물의 입력값을 뽑아낸다.
	include "t.inc";

	// 비공개글인경우
	if($my_public_yn == "N")
	{
		if($my_sort == ceil($my_sort))
		{
			$tm_original_id = $my_input_id;
		}
		else
		{
			// 원글의 입력아이디를 가져온다.
			$query = "SELECT INPUT_ID FROM $cf_table_col_nm WHERE SORT = " . ceil($my_sort);
			$tm_original_id = $DB->Value($query);
		}

		if($cf_top_level_yn != "Y" && (!$cf_cook_id || ($cf_cook_id != $my_input_id && $cf_cook_id != $tm_original_id)))
		{
			error_msg("읽을 수 있는 권한이 없습니다.", "back");
			exit;
		}
	}

	// 선택한 게시물의 조회수를 증가시킨다. - 본인의 게시물인 경우 조회수를 증가시키지 않는다.
	if(!$my_input_id || ($cf_cook_id != $my_input_id && $cf_cook_id != $my_input_id))
	{
		$my_ver_cnt = $my_ver_cnt + 1;
		$upd_query = "UPDATE " . $cf_table_col_nm . " SET VER_CNT = $my_ver_cnt WHERE NO = '$po_no'";
		$upd_stmt = $DB->Update_Query($upd_query);
	}

	// 글쓴이 처리
   	if(!$my_email)
		$tm_sign_nm = $my_sign_nm;
	else
		$tm_sign_nm = "<a href=\"mailto:$my_email\">$my_sign_nm</a>";

	// 글쓴날 처리
	if(substr($my_input_ymdhms, 8, 2) < 12)
	{
		$tm_pm = "오전";
		$tm_h = substr($my_input_ymdhms, 8, 2);
	}
	else
	{
		$tm_pm = "오후";
		$tm_h = substr($my_input_ymdhms, 8, 2) - 12;
	}

	$tm_input_ymdhms = substr($my_input_ymdhms, 0, 4) . "-" .
						substr($my_input_ymdhms, 4, 2) . "-" .
						substr($my_input_ymdhms, 6, 2);
##############################################################################
	// 1.첨부화일
	$tm_real_path = $cf_savedir . "/" . $my_real_path;
	$tm_real_path_physical = $cf_doc_root . $tm_real_path;
	if($cf_attach_size > 0 || $my_attach_path)
	{
		if($my_attach_path && is_file($tm_real_path_physical))
		{
			//$tm_attach_file_tmp = "<img src='$cf_images_dir/file.gif' align='absmiddle'> <a href='/files/download.html?file=" . base64_encode($tm_real_path_physical) . "' target='fdown'>$my_attach_path</a>";
			$tm_attach_file_tmp = "<img src='$cf_images_dir/file.gif' align='absmiddle'> <a href='".$tm_real_path."' target='fdown'>$my_attach_path</a>";
		}
		else
		{
			$tm_attach_file_tmp = "첨부된 화일이 없습니다.";
		}
	}
//2
	$tm_real_path1 = $cf_savedir . "/" . $my_real_path1;
	$tm_real_path_physical1 = $cf_doc_root . $tm_real_path1;
	if($cf_attach_size > 0 || $my_attach_path1)
	{
		if($my_attach_path1 && is_file($tm_real_path_physical1)){
			//$tm_attach_file_tmp = "<img src='$cf_images_dir/file.gif' align='absmiddle'> <a href='/files/download.html?file=" . base64_encode($tm_real_path_physical) . "' target='fdown'>$my_attach_path</a>";
			$tm_attach_file_tmp1 = "<img src='$cf_images_dir/file.gif' align='absmiddle'> <a href='".$tm_real_path1."' target='fdown'>$my_attach_path1</a>";
		}else{}
	}
	//3
	$tm_real_path2 = $cf_savedir . "/" . $my_real_path2;
	$tm_real_path_physical2 = $cf_doc_root . $tm_real_path2;
	if($cf_attach_size > 0 || $my_attach_path2)
	{
		if($my_attach_path2 && is_file($tm_real_path_physical2)){
			$tm_attach_file_tmp2 = "<img src='$cf_images_dir/file.gif' align='absmiddle'> <a href='".$tm_real_path2."' target='fdown'>$my_attach_path2</a>";
		}else{}
	}
	//4
	$tm_real_path3 = $cf_savedir . "/" . $my_real_path3;
	$tm_real_path_physical3 = $cf_doc_root . $tm_real_path3;
	if($cf_attach_size > 0 || $my_attach_path3)
	{
		if($my_attach_path3 && is_file($tm_real_path_physical3))
		{
			$tm_attach_file_tmp3 = "<img src='$cf_images_dir/file.gif' align='absmiddle'> <a href='".$tm_real_path3."' target='fdown'>$my_attach_path3</a>";
		}else{}
	}
##################################################################################
	// 이미지 관련처리
	$tm_image_board = "";
	$tm_image = "";
	if($my_attach_path && is_file($tm_real_path_physical))
	{
		$tm_file_info_arr = getimagesize($tm_real_path_physical);

		if($tm_file_info_arr[2] > 0 && $tm_file_info_arr[2] < 4)
		{
			// 이미지보드 이미지
			$tm_image_board = "<IMG src='" . $tm_real_path . "' width='226' height='178' hspace=5 vspace=5 border=1 bodercolor='#000000' align=left class=starimage><br>";

			// 포토갤러리 스타일
			$tm_image_info = get_image_size($tm_real_path_physical, 450);
			$tm_image = "<center><a href='$tm_real_path' target='_blank'><img src='$tm_real_path'" . $tm_image_info[2] . "></a></center><br>";
		}
	}

	// ----------------------------------------------------------------------- //
	//	코멘트 처리 시작
	// ----------------------------------------------------------------------- //
	if($cf_comment_yn == "Y")
	{
		$query = "SELECT * FROM CM_BOARD_COMM_T WHERE P_NO = '$po_no' ORDER BY C_NO DESC";
		$comment_arr = $DB->Pipe_Arr($query);
		$my_comment_count = sizeof($comment_arr);

		for($i=0; $i<$my_comment_count; $i++)
		{
			$comment_arr[$i][MEMO] = nl2br(stripslashes($comment_arr[$i][MEMO]));
			$comment_arr[$i][INPUT_YMDHMS] = substr($comment_arr[$i][INPUT_YMDHMS], 4, 2) . "/" .
												substr($comment_arr[$i][INPUT_YMDHMS], 6, 2);

			if(($cf_cook_id && $cf_cook_id == $comment_arr[$i][INPUT_ID]) || $cf_top_level_yn == "Y")
			{
				$comment_arr[$i][COMM_DEL] = "<IMG src='$cf_images_dir/comm_delete.gif' align=absMiddle onClick='commdel_submit(" . $comment_arr[$i][C_NO] . ")' style='cursor:hand'>";
				$comment_arr[$i][COMM_DEL] = "<IMG src='$cf_images_dir/comm_delete.gif' align=absMiddle onClick='show_commdel_form(1," . $comment_arr[$i][C_NO] . ")' style='cursor:hand'>";
			}
			else
			{
				$comment_arr[$i][COMM_DEL] = "<IMG src='$cf_images_dir/comm_delete.gif' align=absMiddle onClick='show_commdel_form(1," . $comment_arr[$i][C_NO] . ")' style='cursor:hand'>";
			}
		}
	}
	// ----------------------------------------------------------------------- //
	//	코멘트 처리 끝
	// ----------------------------------------------------------------------- //
################ // 이전 다음 구하기 ##################

	// 다음상품을 구한다. 글이 먼저 등록된 글을 구한다는 뜻.
	$query_next  = "SELECT min(no) next FROM CM_BOARD_T " .
						" WHERE CD= '$a_cd' AND NO > '$po_no' " .
						$query_where; 
	$next_it_no =$DB -> Value($query_next); // 갯수 조정시 패치되는 값을 바꾸어 주어야 한다.
	
	// 이전 상품을 구한다
	$query_prev  = "SELECT max(NO) prev FROM CM_BOARD_T ". 
						" WHERE CD= '$a_cd' AND NO < '$po_no' " .
						 $query_where;
	$prev_it_no =$DB -> Value($query_prev); // 갯수 조정시 패치되는 값을 바꾸어 주어야 한다.

	// 링크..
	$tm_pn_url = $cf_path_url . "/listbody.html?a_gb=$a_gb&a_cd=$a_cd&a_item=$a_item" .
					"&page=$page";
	################ // 이전 다음 구하기 마무리 ##################


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
   //echo $cf_skin_nm;
	include $cf_skin_nm . "/listbody.inc";
	#######################################

	// 상세보기 하단 리스트 출력
	switch($cf_board_cd)
	{
		case "ba_100" :		// 리스트형
			include "listview.inc";
			break;

//		case "ba_200" :		// 공지형
//			include "list_bottom.inc";
//			break;

		case "ba_300" :		// 패밀리형
			include "flistview.inc";
			break;

		default :			// 선택하지 않은경우 출력없음
			break;
	}
?>
