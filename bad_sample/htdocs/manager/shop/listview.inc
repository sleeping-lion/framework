<?
	# 초기값 설정
	$board = new CPaging();
	$page = $page ? $page : 1;
	$cf_num_per_page = $check_line ? $check_line : $cf_num_per_page;

	# ------------------------------------------------------------ #
	#	사용할 쿼리정리 시작
	# ------------------------------------------------------------ #
	$query_select = "SELECT * ";
	$query_select_count = "SELECT COUNT(NO) ";
	$query_from = "FROM $cf_table_col_nm ";
	$query_where = "WHERE 1 = 1 ";
	if($cf_top_level_yn != "Y")
		$query_where .= "AND IT_SERVICE_YN = 'Y' ";
	$query_order = " ORDER BY IT_LCLASS, IT_MCLASS DESC ";

	if($po_it_lclass)
		$query_where .= "AND IT_LCLASS = '$po_it_lclass' ";
	if($po_it_mclass)
		$query_where .= "AND IT_MCLASS = '$po_it_mclass' ";
	if($po_it_sclass)
		$query_where .= "AND IT_SCLASS = '$po_it_sclass' ";
	if($po_it_event_cd)
		$query_where .= "AND IT_EVENT_CD = '$po_it_event_cd' ";

	// 검색키가 있는경우
	if(eregi("[^[:space:]]+",$key))
	{
		$encoded_key = urlencode($key);

		if ($keyfield_name || $keyfield_company || $keyfield_no)
		{
			$query_where = $query_where . "AND ( ";
			if($keyfield_name)
				$query_name = "$keyfield_name LIKE '%$key%' ";
			else
				$query_name = "1 = 2 ";

			if($keyfield_company)
				$query_company = "$keyfield_company LIKE '%$key%' ";
			else
				$query_company = "1 = 2 ";

			if($keyfield_no)
				$query_no = "$keyfield_no LIKE '%$key%' ";
			else
				$query_no = "1 = 2 ";

			$query_where = $query_where .
							$query_name . "OR " .
							$query_company . "OR " .
							$query_no . ")";
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

		# ---- 대분류 ---- #
		$arr[$i][IT_LCLASS_NM] = get_code_nm($arr[$i][IT_LCLASS]);

		# ---- 중분류 ---- #
		$arr[$i][IT_MCLASS_NM] = get_code_nm($arr[$i][IT_MCLASS]);

		# ---- 소분류 ---- #
		$arr[$i][IT_SCLASS_NM] = get_code_nm($arr[$i][IT_SCLASS]);

		# ---- 상품명 ---- #
		if(!$arr[$i][IT_NAME])
			$arr[$i][IT_NAME] = "상품명없음";

		// 게시물의 링크
		$arr[$i][LISTBODY_LINK] = "listbody.html?$po_adv_query&page=" . $page . "&po_no=" . $arr[$i][NO];

		// 제목을 검색시에는 검색어를 붉은색으로 출력한다.
		if(!strcmp($keyfield_name, "it_name") && $key)
			$arr[$i][IT_NAME] = eregi_replace("($key)", "<font color=red>\\1</font>", $arr[$i][IT_NAME]);

		# ---- 상품코드 ---- #

		# ---- 상품재고량 ---- #
		
		# ---- 이벤트종류 ----- #
		$arr[$i][IT_EVENT_CD_NM] = get_code_nm($arr[$i][IT_EVENT_CD]);

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
				$arr[$i][NEW_ICON] = "&nbsp;<img src='$cf_images_dir/new.gif' align='absmiddle'>";
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
		$POST = get_button_href("상품등록","postform.html?".$po_adv_query."&page=".$page);
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

	if($keyfield_name && $keyfield_company && $keyfield_brand)
	{
		$keyfield = "total";
	}
	else if($keyfield_name)
	{
		$keyfield = "it_name";
	}
	else if($keyfield_company)
	{
		$keyfield = "it_company";
	}
	else if($keyfield_no)
	{
		$keyfield = "it_no";
	}

	$tm_search_var = array(
						"total" => " * 전 체 * ",
						"it_name" => "상품명",
						"it_company" => "제조사",
						"it_no" => "상품코드"
					);

	// 분류명칭
	$lclass_arr = get_code_arr("i_class");
	if($po_it_lclass)
		$mclass_arr = get_code_arr("$po_it_lclass");
	if($po_it_mclass)
		$sclass_arr = get_code_arr("$po_it_mclass");
	// ------------------------------------------------------------ //
	//	검색을 위한 처리 끝
	// ------------------------------------------------------------ //

	########## 리스트 출력화일 ##########
	include $cf_skin_nm . "/list.inc";
	#####################################
?>
