<?
	# 초기값 설정
	$board = new CPaging();
	$page = $page ? $page : 1;
	$cf_num_per_page = $check_line ? $check_line : $cf_num_per_page;

	# ------------------------------------------------------------ #
	#	사용할 쿼리정리 시작
	# ----------------------------------------------------------- #
	$query_select		= "SELECT * ";
	$query_select_count = "SELECT COUNT(*) ";
	$query_from			= "FROM $cf_table_col_nm ";
	$query_where		= "WHERE 1=1 ";
	$query_order		= "ORDER BY NO DESC ";

	// 검색키가 있는경우
	if($s_poll_type)
	{
		$query_where	.= 	" and POLL_TYPE = '".$s_poll_type."'";
	}

	if($s_subject)
	{
		$query_where	.= 	" and SUBJECT LIKE '%".$s_subject."%'";
	}
	# ------------------------------------------------------------ #
	#	사용할 쿼리정리 끝
	# ----------------------------------------------------------- #
	# ---- 전체게시물 수를 구한다. ---- #
	$query = $query_select_count .
				$query_from .
				$query_where;

	$total_record = $DB->Value($query);

	# ---- 페이징변수 처리 (총 레코드수, 현재페이지번호, 페이지당 레코드수, 페이지블럭당 페이지 수) ---- #
    $board->Paging($total_record, $page, $cf_num_per_page, $cf_page_per_block);

	# ---- 전체 출력할 레코드를 가져온다. ---- #
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

	// 실제 출력 레코드변수 설정
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

		# ---- 설문 구분 ---- #
		$arr[$i][POLL_TYPE]=get_code_nm($arr[$i][POLL_TYPE]);

		// 검색시 붉은색 표시
		if(!strcmp($keyfield_gb,"gb") && $key)
			$arr[$i][GB] = eregi_replace("($key)", "<font color=red>\\1</font>", $arr[$i][GB]);

	
		// 검색시 붉은색 표시
		if(!strcmp($keyfield_cd,"cd") && $key)
			$arr[$i][CD] = eregi_replace("($key)", "<font color=red>\\1</font>", $arr[$i][CD]);


		// 검색시 붉은색 표시
		if(!strcmp($keyfield_title_nm,"title_nm") && $key)
			$arr[$i][TITLE_NM] = eregi_replace("($key)", "<font color=red>\\1</font>", $arr[$i][TITLE_NM]);

		// 구분코드명 링크
		// GB = 'admin' 인 것은 최고관리자만 수정이 가능하다.
		if($arr[$i][GB] == "admin" && $cf_cook_level == "aa" || $arr[$i][GB] != "admin")
		{
			$arr[$i][LISTBODY_LINK] = "listbody.html?$po_adv_query&page=$page&po_no=".$arr[$i][NO];
		}
		else
		{
			$arr[$i][LISTBODY_LINK] = "#";
		}

		# ---- 관리자 ---- #
		// $arr[$i][ADMIN_ID]

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
			$PAGES[$i] = "<B>" . $board->pages[$i] . "</B>";
		else
			$PAGES[$i] = "<a href='list.html?$po_adv_query&page=" . $board->pages[$i] . "'>" . $board->pages[$i] . "</a>";
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


	$tm_check_line = array(
						"10" => "10",
						"20" => "20",
						"30" => "30",
						"50" => "50",
						"100" => "100",
						"200" => "200",
						"100000" => "전체"
					);
	
	// 설문구분
	$query = "SELECT CD, NM FROM $cf_table_cod_nm WHERE GB = 'poll_type' ORDER BY NM ASC";

	$poll_type_arr = $DB->Arr($query);

	// ------------------------------------------------------------ //
	//	검색을 위한 처리 끝
	// ------------------------------------------------------------ //

	########## 리스트 출력화일 ##########
	include "html/list.inc";
	#####################################
?>
