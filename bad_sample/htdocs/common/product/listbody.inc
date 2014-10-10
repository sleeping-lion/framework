<?
	

	// 비공개글인경우
	
	if($cf_secret_yn == "Y"){
		$counsel_no = $my_fid.$my_passwd;
	   
		if($cf_top_level_yn=="Y"  || $_COOKIE["CK_KC_COUNSEL_NO"] == $counsel_no){ //최고관리자/중앙/쿠키인증

		}else{
			include "check.inc";
			exit;

		}
	 }


	if($my_public_yn == "N")
	{
		if($my_sort == ceil($my_sort))
		{
			$tm_original_id = $my_input_id;
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
	if($cf_attach_size > 0){
		unset($f_arr);
		$tm_attach_file_tmp = "";
		$f_sql = "SELECT * FROM CM_FILE_T WHERE GB = '".$a_gb."' AND CD = '".$a_cd."' AND ITEM = '".$a_item."' AND P_NO ='".$po_no."' AND FILE_TYPE='normal' ORDER BY NO ASC";
		$f_arr = $DB->Pipe_Arr($f_sql);
		if(count($f_arr)>0){
			for($i=0;$i<count($f_arr);$i++){
				$my_attach_path = $f_arr[$i]["REAL_PATH"];
				$tm_real_path = $cf_savedir . "/" . $f_arr[$i]["REAL_PATH"];
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

	$query_next  = "SELECT min(no) next FROM CM_PRODUCT_T " .
						" WHERE GB = '$a_gb' AND CD= '$a_cd' AND NO > '$po_no' " .
						$query_where;
	$next_it_no =$DB -> Value($query_next); 
	
	// 이전 상품을 구한다
	$query_prev  = "SELECT max(NO) prev FROM CM_PRODUCT_T ".
						" WHERE GB = '$a_gb' AND CD= '$a_cd' AND NO < '$po_no' " .
						 $query_where;
	$prev_it_no =$DB -> Value($query_prev); 


	// 다음상품을 구한다. 글이 먼저 등록된 글을 구한다는 뜻.
	$query_next  = "SELECT NO, SUBJECT, INPUT_YMDHMS FROM CM_PRODUCT_T " .
						" WHERE GB = '$a_gb' AND CD= '$a_cd' AND NO = '$next_it_no'";
	$next_arr =$DB -> Pipe_Row($query_next); // 갯수 조정시 패치되는 값을 바꾸어 주어야 한다.

	// 이전 상품을 구한다
	$query_prev  = "SELECT NO, SUBJECT, INPUT_YMDHMS FROM CM_PRODUCT_T ".
						" WHERE GB = '$a_gb' AND CD= '$a_cd' AND NO = '$prev_it_no' ";
	$prev_arr =$DB -> Pipe_Row($query_prev); // 갯수 조정시 패치되는 값을 바꾸어 주어야 한다.


	// 링크..
	$tm_pn_url = "/common/product/listbody.html?a_gb=$a_gb&a_cd=$a_cd&a_item=$a_item" .
					"&page=$page";
	################ // 이전 다음 구하기 마무리 ##################


	// ------------------------------------------------------------ //
	//	버튼처리 시작
	// ------------------------------------------------------------ //
	#이전버튼 
	$PREV = "<a href=\"$tm_pn_url&po_no=".$prev_arr[NO]."&sm=$sm\" onMouseOver=\"status='reload articles';return true;\" onMouseOut=\"status=''\">".$prev_arr[SUBJECT]."</a>";

	#다음버튼
	$NEXT = "<a href=\"$tm_pn_url&po_no=".$next_arr[NO]."&sm=$sm\" onMouseOver=\"status='reload articles';return true;\" onMouseOut=\"status=''\">".$next_arr[SUBJECT]."</a>";

	# 리스트 버튼
	$LIST = "<a href='/common/product/list.html?$po_adv_query&page=$page' onMouseOver=\"status='reload articles';return true;\" onMouseOut=\"status=''\"  class=\"btn_type\"><span>목록</span></a>";

	# 쓰기 버튼
	if($cf_post_level_yn == "Y")
	{
		$POST = "<a href='/common/product/postform.html?$po_adv_query&page=$page' onMouseOver=\"status='새 글쓰기';return true;\" onMouseOut=\"status=''\"><img src='$cf_images_dir/post.gif' align='absmiddle'></a>";
	}

	# 답변 버튼
	if($my_notice_yn == "Y")
	{
		$REPLY = "";
	}
	else if($cf_reply_level_yn == "Y" && $cf_reply_yn == "Y")
	{
		$REPLY = "<a href=\"/common/product/replyform.html?$po_adv_query&page=$page&po_no=$po_no\" onMouseOver=\"status='reply to this article'; return true;\" onMouseOut=\"status=''\"\"><img src=\"$cf_images_dir/reply.gif\" border=0 align='absmiddle'></a>";
	}

	# 수정 버튼
	if($my_notice_yn == "Y" && $cf_top_level_yn != "Y")
	{
		$MODIFY = "";
	}
	else if($cf_modify_level_yn == "Y" && ($cf_top_level_yn == "Y" || !$my_input_id || $my_input_id == $cf_cook_id))
	{
		$MODIFY = "<a href=\"/common/product/modifyform.html?$po_adv_query&page=$page&po_no=$po_no\" onMouseOver=\"status='modify this article';return true;\" onMouseOut=\"status=''\"\" class=\"btn_type\"><span>수정</span></a>";
	}
	else
	{
		$MODIFY = "";
	}

	# 삭제 버튼
	$DELETE = "";
	if($my_notice_yn == "Y" && $cf_top_level_yn == "Y")
	{
		$DELETE = "<a href=\"javascript:DelConfirm('/common/product/delete.html?$po_adv_query&page=$page&po_no=$po_no')\" onMouseOver=\"status='delete this article';return true;\" onMouseOut=\"status=''\"\" class=\"btn_type\"><span>삭제</span></a>";
	}
	else if($cf_delete_level_yn == "Y")
	{
		if(!$my_input_id)
		{
			$DELETE = "<a href=\"/common/product/deleteform.html?$po_adv_query&page=$page&po_no=$po_no\" onMouseOver=\"status='delete this article';return true;\" onMouseOut=\"status=''\"\" class=\"btn_type\"><span>삭제</span></a>";
		}
		else if($cf_cook_id && ($cf_top_level_yn == "Y" || $my_input_id == $cf_cook_id))
		{
			$DELETE = "<a href=\"javascript:DelConfirm('/common/product/delete.html?$po_adv_query&page=$page&po_no=$po_no')\" onMouseOver=\"status='delete this article';return true;\" onMouseOut=\"status=''\"\" class=\"btn_type\"><span>삭제</span></a>";
		}
	}
	// ------------------------------------------------------------ //
	//	버튼처리 끝
	// ------------------------------------------------------------ //

	########## 상세보기 출력화일 ##########
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

