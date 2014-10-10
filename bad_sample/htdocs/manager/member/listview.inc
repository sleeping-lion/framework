<?
	# 초기값 설정
	$board = new CPaging();
	$page = $page ? $page : 1;
	$cf_num_per_page = $check_line ? $check_line : $cf_num_per_page;

	# ------------------------------------------------------------ #
	#	사용할 쿼리정리 시작
	# ------------------------------------------------------------ #
	$query_select = "SELECT CM_ID, CM_NM, CM_EMAIL, CM_HP_TEL, CM_LOG_CNT, CM_LEVEL, CM_DEL_YN,INPUT_YMDHMS, CM_ADDR, CM_ADDR2 ";
	$query_select_count = "SELECT COUNT(CM_ID) ";
	$query_from = "FROM $cf_table_mem_nm ";
	$query_where .= "WHERE CM_LEVEL >= '$cf_cook_level' ";
	$query_order = " ORDER BY INPUT_YMDHMS DESC ";

	if($sr_start_day && $sr_end_day) {	// 주문날짜
		$query_where .= "AND (DATE_FORMAT(INPUT_YMDHMS,'%Y%m%d') >= $sr_start_day AND DATE_FORMAT(INPUT_YMDHMS,'%Y%m%d') <= $sr_end_day) ";
	}

	if($level)
		$query_where .= "AND CM_LEVEL = '$level' ";

	// 검색키가 있는경우
	if(eregi("[^[:space:]]+",$key))
	{
		$encoded_key = urlencode($key);

		if ($keyfield_id || $keyfield_nm || $keyfield_tel)
		{
			$query_where = $query_where . "AND ( ";
			if($keyfield_id)
				$query_id = "$keyfield_id LIKE '%$key%' ";
			else
				$query_id = "1 = 2 ";

			if($keyfield_nm)
				$query_nm = "$keyfield_nm LIKE '%$key%' ";
			else
				$query_nm = "1 = 2 ";

			if($keyfield_tel)
				$query_tel = "$keyfield_tel LIKE '%$key%' ";
			else
				$query_tel = "1 = 2 ";

			$query_where	= 	$query_where .
								$query_id . "OR " .
								$query_nm . "OR " .
								$query_tel . ")";
		}
	}


	$po_adv_query = $po_adv_query."&sr_start_day=".$sr_start_day."&sr_end_day=".$sr_end_day;
	# ------------------------------------------------------------ #
	#	사용할 쿼리정리 끝
	# ------------------------------------------------------------ #

	# ---- 전체게시물 수를 구한다. ---- #
	$query = $query_select_count .
				$query_from .
				$query_where;
	$total_record = $DB->Value($query);
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


		# ---- 아이디 ---- #
		// $arr[$i][CM_ID]

		# ---- 아이디 링크(상세보기) ---- #
		$arr[$i][LISTBODY_LINK] = "listbody.html?$po_adv_query&page=$page&po_cm_id=" . $arr[$i][CM_ID];

		# ---- 아이디 앞에 출력할 아이콘 ---- #
		if($po_cm_id == $arr[$i][CM_ID])
			$arr[$i][ICON] = "reading.gif";
		else
			$arr[$i][ICON] = "thread.gif";

		# ---- 성명 ---- #
		// $arr[$i][CM_NM]

		# ---- 성명링크(이메일) ---- #
		if($arr[$i][CM_EMAIL])
			$arr[$i][CM_NM] = $arr[$i][CM_NM];

		# ---- 전화번호 ---- #
		// $arr[$i][CM_TEL]

		# ---- 접속횟수 ---- #
		// $arr[$i][CM_LOG_CNT]

		# ---- 회원레벨 ---- #
		$query = "SELECT NM FROM " . $cf_table_cod_nm . " WHERE CD = '" . $arr[$i][CM_LEVEL] . "'";
		$arr[$i][CM_LEVEL_NM] = $DB->Value($query);

		# ---- 글쓴날 처리 ---- #
		$arr[$i][INPUT_YMDHMS] = substr($arr[$i][INPUT_YMDHMS],0,4) . "-" .
								substr($arr[$i][INPUT_YMDHMS],4,2) . "-" .
								substr($arr[$i][INPUT_YMDHMS],6,2);


		# ---- 가입여부 ---- #
		// $arr[$i][CM_DEL_YN]

		# ---- 검색관련 처리 시작 ---- #
		// 아이디
		if(!strcmp($keyfield_id,"cm_id") && $key)
			$arr[$i][CM_ID] = eregi_replace("($key)", "<font color=red>\\1</font>", $arr[$i][CM_ID]);

		// 이름
		if(!strcmp($keyfield_nm,"cm_nm") && $key)
			$arr[$i][CM_NM] = eregi_replace("($key)", "<font color=red>\\1</font>", $arr[$i][CM_NM]);

		// 닉네임
		if(!strcmp($keyfield_tel,"cm_tel") && $key)
			$arr[$i][CM_TEL] = eregi_replace("($key)", "<font color=red>\\1</font>", $arr[$i][CM_TEL]);
		# ---- 검색관련 처리 끝 ---- #

		// 게시물 가상번호 감소
		$article_num--;
	}
	// ------------------------------------------------------------ //
	//	출력할 레코드처리 끝
	// ------------------------------------------------------------ //

	// ------------------------------------------------------------ //
	//	페이징처리 시작
	// ------------------------------------------------------------ //
	# ---- 이전페이지 블록 ---- #
	if($board->prev_pageblock)
	   $PREV_BLOCK = "<a href=\"list.html?$po_adv_query&page=" . $board->prev_pageblock . "\" onMouseOver=\"status='load previous $page_per_block pages';return true;\" onMouseOut=\"status=''\"><img src='$cf_images_dir/prev10.gif' border='0' align='absmiddle'></a>";
	else
	   $PREV_BLOCK = "<img src='$cf_images_dir/prev10.gif' border='0' align='absmiddle'>";

	# ---- 이전페이지 ---- #
	if($board->prev_page)
		$PREV_PAGE = "<a href=\"list.html?$po_adv_query&page=" . $board->prev_page . "\" onMouseOver=\"status='previous page';return true;\" onMouseOut=\"status=''\"><img src=\"$cf_images_dir/prev.gif\" border=0 align='absmiddle'></a>";
	else
		$PREV_PAGE = "<img src=\"$cf_images_dir/prev.gif\" border=0  align='absmiddle'>";

	# ---- 다음페이지 ---- #
	if($board->next_page)
	   $NEXT_PAGE = "<a href=\"list.html?$po_adv_query&page=" . $board->next_page . "\" onMouseOver=\"status='next page';return true;\" onMouseOut=\"status=''\"><img src=\"$cf_images_dir/next.gif\" border=0 align='absmiddle'></a>";
	else
		$NEXT_PAGE = "<img src=\"$cf_images_dir/next.gif\" border=0 align='absmiddle'>";

	# ---- 다음페이지 블록 ---- #
	if($board->next_pageblock)
		$NEXT_BLOCK = "<a href=\"list.html?$po_adv_query&page=" . $board->next_pageblock . "\" onMouseOver=\"status='load next $page_per_block pages';return true;\" onMouseOut=\"status=''\"><img src='$cf_images_dir/next10.gif' border='0' align='absmiddle'></a>";
	else
	   $NEXT_BLOCK = "<img src='$cf_images_dir/next10.gif' border='0' align='absmiddle'>";

	# ---- 페이지링크 ---- #
	for($i=0; $i<$board->page_count; $i++)
	{
		if($board->pages[$i] == $page)
			$PAGES[$i] = " <font color='red'><B>" . $board->pages[$i] . "</B></font> ";
		else
			$PAGES[$i] = " <a href='list.html?$po_adv_query&page=" . $board->pages[$i] . "'>" . $board->pages[$i] . "</a> ";
	}
	// ------------------------------------------------------------ //
	//	페이징처리 끝
	// ------------------------------------------------------------ //

	// ------------------------------------------------------------ //
	//	버튼처리 시작
	// ------------------------------------------------------------ //
	# 리스트 버튼
	$LIST = get_button_href("목록","list.html?".$po_basic_query);

	# 쓰기 버튼
	if($cf_post_level_yn == "Y")
	{
		$POST = get_button_href("등록","postform.html?".$po_adv_query."&page=".$page);
	}

	// ------------------------------------------------------------ //
	//	버튼처리 끝
	// ------------------------------------------------------------ //

	// ------------------------------------------------------------ //
	//	검색을 위한 처리 시작
	// ------------------------------------------------------------ //
	// 레벨
	if($cf_cook_level)
	{
		$query = "SELECT CD, NM FROM $cf_table_cod_nm WHERE GB = 'level' AND CD >= '$cf_cook_level'";
		$level_arr = $DB->Arr($query);
	}

	// check_line
	$tm_check_line = array(
						"" => " ---- ",
						"10" => "10",
						"20" => "20",
						"30" => "30",
						"50" => "50",
						"100" => "100",
						"200" => "200",
						"100000" => "전체"
					);

	if($keyfield_id && $keyfield_nm && $keyfield_tel)
	{
		$keyfield = "total";
	}
	else if($keyfield_id)
	{
		$keyfield = "cm_id";
	}
	else if($keyfield_nm)
	{
		$keyfield = "cm_nm";
	}
	else if($keyfield_tel)
	{
		$keyfield = "tel";
	}

	$tm_search_var = array(
						"total" => " * 전 체 * ",
						"cm_id" => "아이디",
						"cm_nm" => "이름",
						"cm_tel" => "전화번호"
					);
	// ------------------------------------------------------------ //
	//	검색을 위한 처리 끝
	// ------------------------------------------------------------ //

	########## 리스트 출력화일 ##########
	include $cf_skin_nm . "/list.inc";
	#####################################
?>
