<?
	// 선택한 게시물의 입력값을 뽑아낸다.
	include "t.inc";
	

	// 비공개글인경우
	if($cf_secret_yn == "Y" && $$cf_top_level_yn != "Y" && $_COOKIE["CK_KC_COUNSEL_NO"]!=$my_no."ok")
	{
		error_msg("","check_passwd.html?".$po_adv_query."&po_no=".$po_no);
		exit;
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

	// 성별
	if($my_sex=="1"){
		$my_sex_text = "(남)";
	}else{
		$my_sex_text = "(여)";
	}

	// 처리상태
	if($my_reply=="N"){
		$my_status_text = "접수중";
	}else{
		$my_status_text = "완료";
	}
##############################################################################
	// 1.첨부화일
	if($cf_attach_size > 0){
		unset($f_arr);
		$tm_attach_file_tmp = "";
		$f_sql = "SELECT * FROM CM_FILE_T WHERE GB = '".$a_gb."' AND CD = '".$a_cd."' AND ITEM = '".$a_item."' AND P_NO ='".$po_no."' AND FILE_TYPE='normal' ORDER BY NO ASC";
		$f_arr = $DB->Pipe_Arr($f_sql);
		if(count($f_arr)>0){
			for($i=0;$i<count($f_arr);$i++){
				$tm_real_path_physical = $_SERVER["DOCUMENT_ROOT"] .$cf_savedir . "/" . $f_arr[$i]["REAL_PATH"];

				if($f_arr[$i]["ATTACH_PATH"] && is_file($tm_real_path_physical)){
					$tm_attach_file_tmp .= "<div><img src='$cf_images_dir/file.gif' align='absmiddle'> <a href='".$cf_savedir . "/" . $f_arr[$i]["REAL_PATH"]."' target='_blank'>".$f_arr[$i]["ATTACH_PATH"]."</a></div>";
				}
			}
		}
		else{
				$tm_attach_file_tmp = "첨부된 화일이 없습니다.";
		}
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
						" WHERE GB = '$a_gb' AND CD= '$a_cd' AND NO > '$po_no' " .
						$query_where;
	$next_it_no =$DB -> Value($query_next); // 갯수 조정시 패치되는 값을 바꾸어 주어야 한다.

	// 이전 상품을 구한다
	$query_prev  = "SELECT max(NO) prev FROM CM_BOARD_T ".
						" WHERE GB = '$a_gb' AND CD= '$a_cd' AND NO < '$po_no' " .
						 $query_where;
	$prev_it_no =$DB -> Value($query_prev); // 갯수 조정시 패치되는 값을 바꾸어 주어야 한다.

	// 링크..
	$tm_pn_url = "/common/board/listbody.html?a_gb=$a_gb&a_cd=$a_cd&a_item=$a_item" .
					"&page=$page";
	################ // 이전 다음 구하기 마무리 ##################


	// ------------------------------------------------------------ //
	//	버튼처리 시작
	// ------------------------------------------------------------ //
	#이전버튼
	$PREV = "<a href=\"$tm_pn_url&po_no=$prev_it_no&sm=$sm\" onMouseOver=\"status='reload articles';return true;\" onMouseOut=\"status=''\"><img src=\"$cf_images_dir/btn_pre.gif\" align='absmiddle'></a>";
	#다음버튼
	$NEXT = "<a href=\"$tm_pn_url&po_no=$next_it_no&sm=$sm\" onMouseOver=\"status='reload articles';return true;\" onMouseOut=\"status=''\"><img src=\"$cf_images_dir/btn_next.gif\" align='absmiddle'></a>";

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

?>
