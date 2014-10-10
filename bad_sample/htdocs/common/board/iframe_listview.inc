<?
	# 초기값 설정
	$board = new CPaging();
	$page = $page ? $page : 1;		//page값 1
	$cf_num_per_page = $check_line ? $check_line : $cf_num_per_page;	//echo $cf_num_per_page;	//10


	# ------------------------------------------------------------ #
	#	사용할 쿼리정리 시작
	# ------------------------------------------------------------ #
	$query_select = "SELECT * ";
	$query_select_count = "SELECT COUNT(*) ";
	$query_from = "FROM $cf_table_col_nm ";
	$query_where = "WHERE GB = '$a_gb' AND CD = '$a_cd' AND ITEM = '$a_item' AND NOTICE_YN = 'N' AND PRD_NO = $shop_no ";
	$query_where_notice = "WHERE GB = '$a_gb' AND CD = '$a_cd' AND ITEM = '$a_item' AND NOTICE_YN = 'Y' AND PRD_NO = $shop_no ";
	if($cf_top_level_yn != "Y")
		$query_where .= "AND SERVICE_YN = 'Y' ";

	$query_order = "ORDER BY FID ASC, SORT ASC ";

	$po_adv_query = $po_adv_query."&shop_no=".$shop_no;
	$po_basic_query = $po_basic_query."&shop_no=".$shop_no;

	if($po_cate){	
		$query_where .= " And CATEGORY='$po_cate' ";
	}
	// 검색키가 있는경우
	if(eregi("[^[:space:]]+",$key))
	{
		if($cf_top_level_yn != "Y")
			$query_where .= "AND PUBLIC_YN = 'Y' ";

		if ($keyfield_subject || $keyfield_input_nm || $keyfield_memo)
		{
			$query_where = $query_where . "AND ( ";
			if($keyfield_subject)
				$query_subject = "$keyfield_subject LIKE '%$key%' ";
			else
				$query_subject = "1 = 2 ";

			if($keyfield_input_nm)
				$query_input_nm = "$keyfield_input_nm LIKE '%$key%' ";
			else
				$query_input_nm = "1 = 2 ";

			if($keyfield_memo)
				$query_memo = "$keyfield_memo LIKE '%$key%' ";
			else
				$query_memo = "1 = 2 ";

			$query_where	= 	$query_where .
								$query_subject . "OR " .
								$query_input_nm . "OR " .
								$query_memo . ")";
		}
	}
	# ------------------------------------------------------------ #
	#	사용할 쿼리정리 끝
	# ------------------------------------------------------------ #

	# ------------------------------------------------------------ #
	#	공지사항이 있는경우 출력하기 위한 처리 시작
	#	* 페이지가 1이고 공지사항 사용여부가 Y 인경우
	# ------------------------------------------------------------ #

	if($cf_annou_yn == "Y")	// Y(관리자면)
	{
		$notice_board = new CPaging();

		# ---- 전체게시물 수를 구한다. ---- #
		$query = $query_select_count .
					$query_from .
					$query_where_notice;

		$total_record_notice = $DB->Value($query);


		# ---- 페이징변수 처리 (총 레코드수, 현재페이지번호, 페이지당 레코드수, 페이지블럭당 페이지 수) ---- #
		$notice_board->Paging($total_record_notice, 1, $cf_num_per_page, $cf_page_per_block);



		# ---- 전체 출력할 레코드를 가져온다. ---- #
		unset($notice_arr);
		$query_limit = "LIMIT $board->first, $notice_board->record_count";

		$query = $query_select .
					$query_from .
					$query_where_notice .
					$query_order.
					$query_limit;

		$notice_arr = $DB->Pipe_Arr($query);
		//print_r($notice_arr);

		for($i=0; $i<$notice_board->record_count; $i++)
		{
			# ---- 게시물 번호 ---- #
			$notice_arr[$i][NUM] = "<font color='red'>[공지]</font>";

			# ---- 제목 처리 시작 ---- #
			// addslashes() 함수로 escape된 제목의 문자열을 원상복귀시킨다.
			$notice_arr[$i][SUBJECT] = stripslashes($notice_arr[$i][SUBJECT]);

			// 제목에 HTML 태그 제거 후 적당한 길이로 자른다.
			$notice_arr[$i][SUBJECT] = substr_byte(strip_tags($notice_arr[$i][SUBJECT]), 100, "...");

			// 제목이 없는경우 삭제를 위해서 임시문자열을 출력한다.
			if(!$notice_arr[$i][SUBJECT])
				$notice_arr[$i][SUBJECT] = "제목이 없습니다.";

			//echo $notice_arr[$i][SUBJECT];
			# ---- 제목 처리 끝 ---- #

			// 게시물의 링크
			$notice_arr[$i][LISTBODY_LINK] = "<a href=\"iframe_listbody.html?$po_adv_query&page=$page&po_no=".$notice_arr[$i][NO]."\" onMouseOut=\"status=''\">".$notice_arr[$i][SUBJECT]."</a>";


			// 코멘트를 사용하는 경우 게시물에 해당하는 코멘트 수를 구한다.
			if($cf_comment_yn == "Y")
			{
				$notice_arr[$i][COMM_CNT] = ($notice_arr[$i][COMM_CNT] > 0) ? "(" . $notice_arr[$i][COMM_CNT] . ")" : "";
			}
			else
			$notice_arr[$i][COMM_CNT] = "";
			# ---- 제목 관련처리 끝 ---- #

			# ---- 글쓴이 처리 시작 ---- #
			// 이메일이 있는경우 이름을 이메일주소에 링크시킨다.
			if(trim($notice_arr[$i][EMAIL]))
			{
				$notice_arr[$i][SIGN_NM] = "<a href=\"mailto:" . $notice_arr[$i][EMAIL] . "\">" . $notice_arr[$i][SIGN_NM] . "</a>";
			}
			# ---- 글쓴이 처리 끝 ---- #

			# ---- 글쓴날 처리 ---- #
			$notice_arr[$i][INPUT_YMDHMS] = substr($notice_arr[$i][INPUT_YMDHMS],0,4) . "-" .
											substr($notice_arr[$i][INPUT_YMDHMS],4,2) . "-" .
											substr($notice_arr[$i][INPUT_YMDHMS],6,2);

			# ---- 조회수 처리 ---- #
			$notice_arr[$i][VER_CNT];
		}
	}
	# ------------------------------------------------------------ #
	#	공지사항이 있는경우 출력하기 위한 처리 끝
	# ------------------------------------------------------------ #

	# ---- 전체게시물 수를 구한다. ---- #
	$query = $query_select_count .
				$query_from .
				$query_where;

	$total_record = $DB->Value($query);


	# ---- 현재페이지가 존재하지 않을경우 페이지수를 동기화한다. ----- #
	if(($page > 1) && (($page-1) * $cf_num_per_page >= $total_record))
		$page = $page - 1;



	# ---- 페이징변수 처리 (총 레코드수, 현재페이지번호, 페이지당 레코드수, 페이지블럭당 페이지 수) ---- #
    $board->Paging($total_record, $page, $cf_num_per_page, $cf_page_per_block);


	# ---- 전체 출력할 레코드를 가져온다. ---- #
	unset($arr);
	$query_limit = "LIMIT $board->first, $board->record_count";
	$query = $query_select .
				$query_from .
				$query_where .
				$query_order .
				$query_limit;
	$arr = $DB->Pipe_Arr($query);


	// ------------------------------------------------------------ //
	//	출력할 레코드처리 시작
	// ------------------------------------------------------------ //
	// New 마크를 출력할 시간 처리

	//echo $cf_notify_new_article."<br><br>"; //초기값 1로 받아옴..
	$cf_notify_new_article = $cf_notify_new_article ? $cf_notify_new_article : 0;
	$time_limit = 60*60*24 * $cf_notify_new_article;

	// 게시물의 가상번호(게시물의 개수에 따른 일련번호)
	$article_num = $total_record - $cf_num_per_page * ($page - 1);
	$loop_cnt = 0;


	// 참고사항
	// listview 출력을 위해 추가된 변수는 다음과 같다.
	// 스타일은 $arr[$i][INDENT]
	// INDENT, ICON, SUBJECT_LINK, NEW_ICON, FILE_PATH
	for($i=0; $i<$board->record_count; $i++)
	{
		// 원글에 대한 아이디를 기억한다. (비공개글이 있는경우 사용한다.)
		if($arr[$i][SORT] == ceil($arr[$i][SORT]))
		{
			$tm_original_id = $arr[$i][INPUT_ID];
		}

		// 레코드 출력부분 디자인요소 처리
		if($loop_cnt == 0)
		{
			$arr[$i][LOOP_CLASS] = "class=board_td";
			$loop_cnt = 1;
		}
		else
		{
			$arr[$i][LOOP_CLASS] = "class=board_td_1";
			$loop_cnt = 0;
		}


		# ---- 게시물 번호 ---- #
		$arr[$i][NUM] = $article_num;

		# ---- 제목 처리 시작 ---- #
		// 비공개글인경우
		if($arr[$i][PUBLIC_YN] == "N" && $cf_top_level_yn != "Y" && (!$cf_cook_id || ($cf_cook_id != $arr[$i][INPUT_ID] && $cf_cook_id != $tm_original_id)))
		{
			$arr[$i][SUBJECT] = "비공개 글입니다.";

			// 게시물의 링크
			$arr[$i][LISTBODY_LINK] = "#";
		}
		else
		{
			# $arr[$i][SUBJECT_G] 는 갤러리용 변수

			// addslashes() 함수로 escape된 제목의 문자열을 원상복귀시킨다.
			$arr[$i][SUBJECT] = stripslashes($arr[$i][SUBJECT]);
			$arr[$i][MEMO_T] = $arr[$i][MEMO];
			// 제목에 HTML 태그 제거 후 적당한 길이로 자른다.

				$arr[$i][SUBJECT] = substr_byte(strip_tags($arr[$i][SUBJECT]), 109, "...");
				$arr[$i][SUBJECT_G] = substr_byte(strip_tags($arr[$i][SUBJECT]), 41, "...");
				$arr[$i][MEMO] = $arr[$i][MEMO];


			// 제목을 검색시에는 검색어를 붉은색으로 출력한다.
			if(!strcmp($keyfield_subject,"subject") && $key)
			{
				$arr[$i][SUBJECT] = eregi_replace("($key)", "<font color=red>\\1</font>", $arr[$i][SUBJECT]);
				$arr[$i][SUBJECT_G] = eregi_replace("($key)", "<font color=red>\\1</font>", $arr[$i][SUBJECT_G]);
			}

			// 제목이 없는경우 삭제를 위해서 임시문자열을 출력한다.
			if(!$arr[$i][SUBJECT])
				$arr[$i][SUBJECT] = "제목이 없습니다.";

			// 게시물의 링크
			$arr[$i][LISTBODY_LINK] = "iframe_listbody.html?$po_adv_query&page=$page&po_no=" . $arr[$i][NO];
			
			$arr[$i][SUBJECT_FAQ] = $arr[$i][SUBJECT];

			if ($arr[$i][SECRET_YN] == "Y") {
				if (($arr[$i][INPUT_ID] && $arr[$i][INPUT_ID] == $cf_cook_id) || $cf_top_level_yn == "Y") {
					$arr[$i][SUBJECT] = "<img src='$cf_images_dir/icon_key.gif'> <a href=\"iframe_listbody.html?$po_adv_query&page=$page&po_no=".$arr[$i][NO]."\" onMouseOut=\"status=''\">".$arr[$i][SUBJECT]."</a>";
				} else {
					$arr[$i][SUBJECT] = "<img src='$cf_images_dir/icon_key.gif'> ".$arr[$i][SUBJECT];
				}
			} else {
				$arr[$i][SUBJECT] = "<a href=\"iframe_listbody.html?$po_adv_query&page=$page&po_no=".$arr[$i][NO]."\" onMouseOut=\"status=''\">".$arr[$i][SUBJECT]."</a>";
			}
		}
		# ---- 제목 처리 끝 ---- #



		# ---- 제목 관련처리 시작 ---- #
		# 응답의 단계에 따라 출력할 제목의 문자열을 안쪽으로 indent를 시킨다.
		$spacer = $arr[$i][DEPTH];
		//echo "spacer : ".$spacer;

		# 원글에 대한 답변글이 $reply_indent 값 이상이 되면 답변글의 출력indent를 고정시킨다. ##########
		//echo $cf_reply_indent; //기본값 5
		if($spacer > $cf_reply_indent) $spacer = $cf_reply_indent;
		$arr[$i][INDENT] = print_string("&nbsp;&nbsp;", $spacer);


		// 제목앞에 출력할 아이콘을 구한다.
		if($po_no == $arr[$i][NO])
		{
			$arr[$i][ICON] = "reading.gif";
		}
		else
		{
			if($spacer)
				$arr[$i][ICON] = "lp.gif";
			else
				$arr[$i][ICON] = "thread.gif";
		}

		// new 마크를 출력할경우
		$arr[$i][NEW_ICON] = "";
		if($cf_notify_new_article)
		{
			# 최근 게시물 시간을 위한 입력시간 시간변환
			$tm_input_ymdhms_mktime = mktime(substr($arr[$i][INPUT_YMDHMS],8,2),
												substr($arr[$i][INPUT_YMDHMS],10,2),
												substr($arr[$i][INPUT_YMDHMS],12,2),
												substr($arr[$i][INPUT_YMDHMS],4,2),
												substr($arr[$i][INPUT_YMDHMS],6,2),
												substr($arr[$i][INPUT_YMDHMS],0,4)
										);
			if($tm_input_ymdhms_mktime > mktime() - $time_limit)
				$arr[$i][NEW_ICON] = "<img src='$cf_images_dir/new.gif' align='absmiddle'>";
		}

		// 코멘트를 사용하는 경우 게시물에 해당하는 코멘트 수를 구한다.
		if($cf_comment_yn == "Y")
		{
			$arr[$i][COMM_CNT] = ($arr[$i][COMM_CNT] > 0) ? "(" . $arr[$i][COMM_CNT] . ")" : "";
		}
		else
			$arr[$i][COMM_CNT] = "";
		# ---- 제목 관련처리 끝 ---- #

		# ---- 글쓴이 처리 시작 ---- #
		// 비공개글인경우
		if($arr[$i][PUBLIC_YN] == "N" && $cf_top_level_yn != "Y" && (!$cf_cook_id || ($cf_cook_id != $arr[$i][INPUT_ID] && $cf_cook_id != $tm_original_id)))
		{
			$arr[$i][SIGN_NM] = "비공개";
		}
		else
		{
			// 검색시 붉은색 표시
			if(!strcmp($keyfield_input_nm,"sign_nm") && $key)
				$arr[$i][SIGN_NM] = eregi_replace("($key)", "<font color=red>\\1</font>", $arr[$i][SIGN_NM]);

			// 이메일이 있는경우 이름을 이메일주소에 링크시킨다.
			if(trim($arr[$i][EMAIL]))
				$arr[$i][SIGN_NM] = "<a href=\"mailto:" . $arr[$i][EMAIL] . "\">" . $arr[$i][SIGN_NM] . "</a>";
		}
		# ---- 글쓴이 처리 끝 ---- #


		# ---- 글쓴날 처리 ---- #
		$arr[$i][INPUT_YMDHMS] = substr($arr[$i][INPUT_YMDHMS],0,4) . "-" .
									substr($arr[$i][INPUT_YMDHMS],4,2) . "-" .
									substr($arr[$i][INPUT_YMDHMS],6,2);

		# ---- 조회수 처리 ---- #
		// $arr[$i][VER_CNT];

		# ---- 첨부화일 처리 ---- #
		if($cf_attach_size > 0){

			$f_query = "SELECT * FROM CM_FILE_T WHERE GB ='".$a_gb."' AND CD ='".$a_cd."' AND ITEM ='".$a_item."' AND P_NO =".$arr[$i][NO]." AND FILE_TYPE='normal' ORDER BY NO ASC LIMIT 0,1";
			$f_row = $DB->Pipe_Row($f_query);

			if(trim($f_row["ATTACH_PATH"])){
				$arr[$i][FILE_PATH] = "<a href='".$cf_savedir."/".$f_row["REAL_PATH"]."' target='_blank'><img src='$cf_images_dir/file.gif'></a>";
				$arr[$i][FILE_PATH_DATA] = $cf_savedir."/".$f_row["REAL_PATH"];
				$arr[$i][IMAGE] = "<img src='".$cf_savedir."/".$f_row["REAL_PATH"]."' width='178' height='130'>";

			}
			else{
				$arr[$i][FILE_PATH] = "";
				$arr[$i][IMAGE] = "NO IMAGE";
			}
			unset($f_row);
		}

		# ------------------------------------------- #
		#	포토갤러리
		# ------------------------------------------- #
		
		// 게시물 가상번호 감소
		$article_num--;
			//print_r($arr);
	}
	// ------------------------------------------------------------ //
	//	출력할 레코드처리 끝
	// ------------------------------------------------------------ //

	// ------------------------------------------------------------ //
	//	페이징처리 시작
	// ------------------------------------------------------------ //
	$P_SKIN = 1;
	$paging_skin[0] = array(
								"none" => " 1 ",
								"prev_pageblock" => "<font color='#CCCCCC'>◀|</font>",
								"prev_page" => "",
								"next_page" => "",
								"next_pageblock" => "<font color='#CCCCCC'>|▶</font>",
								"first" => "[처음]",
								"last" => "[끝]",
							);

	$paging_skin[1] = array(
								"none" => " 1 ",
								"prev_pageblock" => "<img src='$cf_images_dir/prev10.gif' border='0' align='absmiddle'>",
								"prev_page" => "<img src=\"$cf_images_dir/prev.gif\" border=0 align='absmiddle'>",
								"next_page" => "<img src='$cf_images_dir/next.gif' border='0' align='absmiddle'>",
								"next_pageblock" => "<img src='$cf_images_dir/next10.gif' border='0' align='absmiddle'>",
								"first" => "[처음]",
								"last" => "[끝]",
							);

	# ---- 첫페이지 ---- #
	if($board->total_page > 1 && $board->page != 1)
	{
		$FIRST_PAGE = "<a href='iframe_list.html?$po_adv_query&page=1'><img src='/images/board/btn_first.gif' alt='처음' /></a>";
	}
	else
	{
		$FIRST_PAGE = "<img src='/images/board/btn_first.gif' alt='처음' />";
	}

	# ---- 마지막페이지 ---- #
	if($board->total_page > 1 && $board->total_page != $board->page)
	{
		$LAST_PAGE = "<a href='iframe_list.html?$po_adv_query&page=" . $board->total_page . "'><img src='/images/board/btn_last.gif' alt='마지막' /></a>";
	}
	else
	{
		$LAST_PAGE = "<img src='/images/board/btn_last.gif' alt='마지막' />";
	}

	# ---- 이전페이지 블록 ---- #
	if($board->prev_pageblock)
	   $PREV_BLOCK = "<a href=\"iframe_list.html?$po_adv_query&page=" . $board->prev_pageblock . "\" onMouseOver=\"status='load previous $page_per_block pages';return true;\" onMouseOut=\"status=''\"><img src='/images/board/btn_prev.gif' alt='이전 10페이지 이동' /></a>";
	else
	   $PREV_BLOCK = "<img src='/images/board/btn_prev.gif' alt='이전 10페이지 이동' />";

	# ---- 이전페이지 ---- #
	if($board->prev_page)
		$PREV_PAGE = "<a href=\"iframe_list.html?$po_adv_query&page=" . $board->prev_page . "\" onMouseOver=\"status='previous page';return true;\" onMouseOut=\"status=''\">" . $paging_skin[$P_SKIN][prev_page] . "</a>";
	else
		$PREV_PAGE = $paging_skin[$P_SKIN][prev_page];

	# ---- 다음페이지 ---- #
	if($board->next_page)
	   $NEXT_PAGE = "<a href=\"iframe_list.html?$po_adv_query&page=" . $board->next_page . "\" onMouseOver=\"status='next page';return true;\" onMouseOut=\"status=''\">" . $paging_skin[$P_SKIN][next_page] . "</a>";
	else
		$NEXT_PAGE = $paging_skin[$P_SKIN][next_page];

	# ---- 다음페이지 블록 ---- #
	if($board->next_pageblock)
		$NEXT_BLOCK = "<a href=\"iframe_list.html?$po_adv_query&page=" . $board->next_pageblock . "\" onMouseOver=\"status='load next $page_per_block pages';return true;\" onMouseOut=\"status=''\"><img src='/images/board/btn_next.gif' alt='다음 10페이지 이동' /></a>";
	else
	   $NEXT_BLOCK = "<img src='/images/board/btn_next.gif' alt='다음 10페이지 이동' />";

	# ---- 페이지링크 ---- #
	if($board->page_count == 0)
	{
		$board->page_count = 1;
		$PAGES[$i] = "<li> <strong>" . $paging_skin[$P_SKIN][none] . "</strong> </li>";
	}
	else
	{
		for($i=0; $i<$board->page_count; $i++)
		{
			if($board->pages[$i] == $page)
				$PAGES[$i] = "<li> <strong>" . $board->pages[$i] . "</strong> </li> ";
			else
				$PAGES[$i] = "<li> <a href='iframe_list.html?$po_adv_query&page=" . $board->pages[$i] . "'>" . $board->pages[$i] . "</a> </li>";
		}
	}
	// ------------------------------------------------------------ //
	//	페이징처리 끝
	// ------------------------------------------------------------ //

	// ------------------------------------------------------------ //
	//	버튼처리 시작
	// ------------------------------------------------------------ //
	# 리스트 버튼
	$LIST = "<a href='iframe_list.html?$po_basic_query&po_cate=$po_cate' class='btn_type'><span>목록</span></a>";
	

	# 이동 버튼
	if($cf_top_level_yn == "Y")
	{
		$MOVE = "<a href=\"#\" onclick=\"check_move('".$po_basic_query."')\" class='btn_type'><span>선택 이동</span></a>";
	}

	# 쓰기 버튼
	if($cf_post_level_yn == "Y")
	{
//		$POST = "<a href='postform.html?$po_adv_query&page=$page' onMouseOver=\"status='새 글쓰기';return true;\" onMouseOut=\"status=''\"><img src='$cf_images_dir/post.gif' align='absmiddle'></a>";
		$POST = "<a href=\"iframe_postform.html?$po_adv_query&page=$page\" class='btn_type'><span>작성</span></a>";
	}
	################################################################
	# 삭제 버튼
	if($cf_delete_level_yn == "Y"){
		//$DELETE = "<a href=\"javascript:check_del('delete_list.html?$po_adv_query')\"><img src=\"$cf_images_dir/delete.gif\" border=0 align='absmiddle' style='cursor:hand'></a>";
		$DELETE = "<a href=\"javascript:check_del('iframe_delete_list.html?$po_adv_query')\" class='btn_type'><span>삭제</span></a>";
	}
	################################################################
	// ------------------------------------------------------------ //
	//	버튼처리 끝
	// ------------------------------------------------------------ //

	// ------------------------------------------------------------ //
	//	검색을 위한 처리 시작
	// ------------------------------------------------------------ //
	// check_line
	$check_line_arr = array(
						"" => " ---- ",
						"10" => "10",
						"20" => "20",
						"30" => "30",
						"50" => "50",
						"100" => "100",
						"200" => "200",
						"100000" => "전체"
					);

	if($keyfield_subject && $keyfield_input_nm && $keyfield_memo)
	{
		$keyfield = "total";
		$keyfield_subject_checked = "checked";
		$keyfield_input_nm_checked = "checked";
		$keyfield_memo_checked = "checked";
	}
	else
	{
		if($keyfield_subject)
		{
			$keyfield = "subject";
			$keyfield_subject_checked = "checked";
		}
		if($keyfield_input_nm)
		{
			$keyfield = "sign_nm";
			$keyfield_input_nm_checked = "checked";
		}
		if($keyfield_memo)
		{
			$keyfield = "memo";
			$keyfield_memo_checked = "checked";
		}
	}

	$tm_search_var = array(
						"total" => " * 전 체 * ",
						"subject" => "제목",
						"sign_nm" => "이름",
						"memo" => "내용"
					);
	// ------------------------------------------------------------ //
	//	검색을 위한 처리 끝
	// ------------------------------------------------------------ //

	if($a_gb=="board" && $a_cd=="7"){
		$query = "SELECT CD,NM FROM $cf_table_cod_nm WHERE GB = 'faq_cate' ORDER BY CD ASC";
		$ctg_arr = $DB->Pipe_Arr($query);
		
	}

	IF($ctg_arr){
		include "tab.inc";
	}

	########## 리스트 출력화일 ##########
	include $cf_skin_nm . "/iframe_list.inc";
	#####################################
?>