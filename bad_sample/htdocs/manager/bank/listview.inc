<?
	# 초기값 설정
	$board = new CPaging();
	$page = $page ? $page : 1;
	$cf_num_per_page = $check_line ? $check_line : $cf_num_per_page;

	# ------------------------------------------------------------ #
	#	사용할 쿼리정리 시작
	# ------------------------------------------------------------ #
	$query_select = "SELECT * ";
	$query_select_count = "SELECT COUNT(CD) ";
	$query_from = "FROM $cf_table_col_nm ";
	$query_where = "WHERE GB = 'bank' ";
	$query_order = " ORDER BY NM ASC ";


	// 검색키가 있는경우
	if(eregi("[^[:space:]]+",$key))
	{
		$encoded_key = urlencode($key);

		if ($keyfield_nm)
		{
			$query_where = $query_where . "AND ( ";
			if($keyfield_nm)
				$query_name = "$keyfield_nm LIKE '%$key%' ";
			else
				$query_name = "1 = 2 ";


			$query_where = $query_where .
							$query_name . ")";
		}
	}
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

	// 게시물의 가상번호(게시물의 개수에 따른 일련번호)
	$article_num = $total_record - $cf_num_per_page * ($page - 1);
	$loop_cnt = 0;

	// 참고사항
	// listview 출력을 위해 추가된 변수는 다음과 같다.
	// 스타일은 $arr[$i][INDENT]
	// INDENT, ICON, SUBJECT_LINK, NEW_ICON, FILE_PATH
	for($i=0; $i<$board->record_count; $i++)
	{
		# ---- 게시물 번호 ---- #
		$arr[$i][NUM] = $article_num;

		
		# ---- 분류명 ---- #
		// $arr[$i][NM];

		if(!$arr[$i][NM])
			$arr[$i][NM] = "분류명없음";

		// 게시물의 링크
		$arr[$i][LISTBODY_LINK] = "listbody.html?$po_adv_query&page=" . $page . "&po_gb=" . $arr[$i][GB]."&po_cd=" . $arr[$i][CD];

		// 제목을 검색시에는 검색어를 붉은색으로 출력한다.
		if(!strcmp($keyfield_nm, "nm") && $key)
			$arr[$i][NM] = eregi_replace("($key)", "<font color=red>\\1</font>", $arr[$i][NM]);

		// 2분류 등록

		$arr[$i][MODIFY] = get_button_href("수정","modifyform.html?".$po_adv_query."&po_gb=".$arr[$i][GB]."&po_cd=".$arr[$i][CD]."&page=".$page);

		$arr[$i][DEL] = get_button_href("삭제","deleteform.html?".$po_adv_query."&po_gb=".$arr[$i][GB]."&po_cd=".$arr[$i][CD]."&page=".$page);

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
		}
		# ---- 제목 관련처리 끝 ---- #

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
		$POST = get_button_href("계좌등록","postform.html?".$po_adv_query."&page=".$page);
	}
	// ------------------------------------------------------------ //
	//	버튼처리 끝
	// ------------------------------------------------------------ //

	// ------------------------------------------------------------ //
	//	검색을 위한 처리 시작
	// ------------------------------------------------------------ //
	$tm_check_line_var = array(
							"" => "",
							"10" => "10",
							"20" => "20",
							"30" => "30",
							"50" => "50",
							"100" => "100",
							"200" => "200",
							"전체" => "100000"
						);

	if($keyfield_nm)
	{
		$keyfield = "total";
	}
	else if($keyfield_nm)
	{
		$keyfield = "nm";
	}

	$tm_search_var = array(
						"total" => " * 전 체 * ",
						"nm" => "은행명",
					);
	// ------------------------------------------------------------ //
	//	검색을 위한 처리 끝
	// ------------------------------------------------------------ //
	########## 리스트 출력화일 ##########
	include $cf_skin_nm . "/list.inc";
	#####################################
?>
