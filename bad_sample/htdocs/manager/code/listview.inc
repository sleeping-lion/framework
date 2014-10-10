<?
	# 초기값 설정
	$board = new CPaging();
	$page = $page ? $page : 1;
	$cf_num_per_page = $check_line ? $check_line : $cf_num_per_page;
	$po_gb = $po_gb ? $po_gb : $cf_c_cd_gb;

	// 구분코드명
	
	$query = "SELECT NM FROM $cf_table_cod_nm WHERE CD = '$po_gb'";
	
	$po_gb_nm = $DB->Value($query);

	// ------------------------------------------------- //
	// 리스트페이지 경로정보 구하기 시작
	// ------------------------------------------------- //
	$i = 0;
	if($po_gb != $cf_c_cd_gb)
	{
		for($i=0;;$i++)
		{
			$tm_gb = $my_path_gb[0] ? $my_path_gb[0] : $po_gb;
			unset($my_path_gb);
			$query = "SELECT GB, NM FROM " . $cf_table_cod_nm . " WHERE CD = '$tm_gb'";

			$my_path_gb = $DB->Row($query);
			$my_path_arr[$i][CD] = $tm_gb;
			$my_path_arr[$i][NM] = $my_path_gb[1];
			if($i > 5 || $my_path_gb[0] == $cf_c_cd_gb) { $i++; break; }
		}
		unset($my_path_gb);
	}
	unset($tm_gb);
	unset($tm_nm);
	$my_path_arr[$i][CD] = $cf_c_cd_gb;
	$my_path_arr[$i][NM] = "종합코드";

	// 경로정보를 정리한다.
	$tm_code_path = "";
	for($i=sizeof($my_path_arr) - 1; $i>=0; $i--)
	{
		if($i != sizeof($my_path_arr) - 1) $tm_code_path .= " > ";
		$tm_code_path .= "<a href='/common/code/list.html?$po_basic_query&po_gb=" . $my_path_arr[$i][CD] . "'>" . $my_path_arr[$i][NM] . "</a> ";
	}
	unset($my_path_arr);
	// ------------------------------------------------- //
	// 리스트페이지 경로정보 구하기 끝
	// ------------------------------------------------- //

	# ------------------------------------------------------------ #
	#	사용할 쿼리정리 시작
	# ----------------------------------------------------------- #
	$query_select	 	= "SELECT GB, CD, NM, CON_CD ";
	$query_select_count = "SELECT COUNT(*) ";
	$query_from 		= "FROM $cf_table_cod_nm ";
	$query_where 		= "WHERE GB = '$po_gb' ";
	if($po_gb == "level")
		$query_where .= "AND CD >= '$cf_cook_level' ";
	$query_order 		= "ORDER BY GB ASC, CD ASC ";

	// 검색키가 있는경우
	if(eregi("[^[:space:]]+",$key))
	{
		$encoded_key = urlencode($key);

		if ($keyfield_cd || $keyfield_nm || $keyfield_bigo)
		{
			$query_where = $query_where . "AND ( ";
			if($keyfield_cd)
				$query_cd = "$keyfield_cd LIKE '%$key%' ";
			else
				$query_cd = "1 = 2 ";

			if($keyfield_nm)
				$query_nm = "$keyfield_nm LIKE '%$key%' ";
			else
				$query_nm = "1 = 2 ";

			if($keyfield_bigo)
				$query_bigo = "$keyfield_bigo LIKE '%$key%' ";
			else
				$query_bigo = "1 = 2 ";

			$query_where	= 	$query_where .
								$query_cd . "OR " .
								$query_nm . "OR " .
								$query_bigo . ")";
		}
	}
	# ------------------------------------------------------------ #
	#	사용할 쿼리정리 끝
	# ----------------------------------------------------------- #

	# ---- 전체게시물 수를 구한다. ---- #
	$query = $query_select_count .
				$query_from .
				$query_where;
	$total_record = $DB->Value($query);

	# ---- 페이지당 레코드 수 ---- #
	if($check_line)
		$cf_num_per_page=$check_line;

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

		# ---- 코드구분 ---- #
		// $arr[$i][GB]

		# ---- 구분코드명 ---- #
		$arr[$i][GB_NM] = $po_gb_nm;

		// 구분코드명 링크
		if($arr[$i][CD] == $cf_c_cd_gb)
			$arr[$i][LISTBODY_LINK] = "#";
		else
			$arr[$i][LISTBODY_LINK] = "listbody.html?$po_adv_query&po_gb=$po_gb&po_cd=" . $arr[$i][CD] . "&page=$page";

		# ---- 코드 ---- #
		// $arr[$i][CD]

		// 검색시 붉은색 표시
		if(!strcmp($keyfield_cd,"cd") && $key)
			$arr[$i][CD] = eregi_replace("($key)", "<font color=red>\\1</font>", $arr[$i][CD]);

		# ---- 코드명 ---- #
		$query = "SELECT NM FROM $cf_table_cod_nm WHERE GB='$po_gb' AND CD = '" . $arr[$i][CD] . "'";
		$arr[$i][CD_NM] = $DB->Value($query);

		// 검색시 붉은색 표시
		if(!strcmp($keyfield_nm,"nm") && $key)
			$arr[$i][NM] = eregi_replace("($key)", "<font color=red>\\1</font>", $arr[$i][NM]);

		// 코드명 링크
		if($arr[$i][CD] == $cf_c_cd_gb)
			$arr[$i][LIST_LINK] = "#";
		else
			$arr[$i][LIST_LINK] = "list.html?$po_adv_query&po_gb=" . $arr[$i][CD] . "&page=1";

		# ---- 관리코드 ---- #
		// $arr[$i][CON_CD]

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
	   $PREV_BLOCK = "<a href=\"list.html?$po_adv_query&po_gb=$po_gb&page=" . $board->prev_pageblock . "\" onMouseOver=\"status='load previous $page_per_block pages';return true;\" onMouseOut=\"status=''\"><img src='$cf_images_dir/prev10.gif' border='0' align='absmiddle'></a>";
	else
	   $PREV_BLOCK = "<img src='$cf_images_dir/prev10.gif' border='0' align='absmiddle'>";

	# ---- 이전페이지 ---- #
	if($board->prev_page)
		$PREV_PAGE = "<a href=\"list.html?$po_adv_query&po_gb=$po_gb&page=" . $board->prev_page . "\" onMouseOver=\"status='previous page';return true;\" onMouseOut=\"status=''\"><img src=\"$cf_images_dir/prev.gif\" border=0 align='absmiddle'></a>";
	else
		$PREV_PAGE = "<img src=\"$cf_images_dir/prev.gif\" border=0  align='absmiddle'>";

	# ---- 다음페이지 ---- #
	if($board->next_page)
	   $NEXT_PAGE = "<a href=\"list.html?$po_adv_query&po_gb=$po_gb&page=" . $board->next_page . "\" onMouseOver=\"status='next page';return true;\" onMouseOut=\"status=''\"><img src=\"$cf_images_dir/next.gif\" border=0 align='absmiddle'></a>";
	else
		$NEXT_PAGE = "<img src=\"$cf_images_dir/next.gif\" border=0 align='absmiddle'>";

	# ---- 다음페이지 블록 ---- #
	if($board->next_pageblock)
		$NEXT_BLOCK = "<a href=\"list.html?$po_adv_query&po_gb=$po_gb&page=" . $board->next_pageblock . "\" onMouseOver=\"status='load next $page_per_block pages';return true;\" onMouseOut=\"status=''\"><img src='$cf_images_dir/next10.gif' border='0' align='absmiddle'></a>";
	else
	   $NEXT_BLOCK = "<img src='$cf_images_dir/next10.gif' border='0' align='absmiddle'>";

	# ---- 페이지링크 ---- #
	for($i=0; $i<$board->page_count; $i++)
	{
		if($board->pages[$i] == $page)
			$PAGES[$i] = "<B>" . $board->pages[$i] . "</B>";
		else
			$PAGES[$i] = "<a href='list.html?$po_adv_query&po_gb=$po_gb&page=" . $board->pages[$i] . "'>" . $board->pages[$i] . "</a>";
	}
	// ------------------------------------------------------------ //
	//	페이징처리 끝
	// ------------------------------------------------------------ //

	// ------------------------------------------------------------ //
	//	버튼처리 시작
	// ------------------------------------------------------------ //
	# 리스트 버튼
	$LIST = "<a href=\"list.html?$po_basic_query\" onMouseOver=\"status='reload articles';return true;\" onMouseOut=\"status=''\"><img src=\"$cf_images_dir/list.gif\" align='absmiddle'></a>";

	# 쓰기 버튼
	if($cf_post_level_yn == "Y")
	{
		$POST = "<a href=\"postform.html?$po_adv_query&po_gb=$po_gb&page=$page\" onMouseOver=\"status='post a new article';return true;\" onMouseOut=\"status=''\"><img src=\"$cf_images_dir/post.gif\" align='absmiddle'></a>";
	}
	// ------------------------------------------------------------ //
	//	버튼처리 끝
	// ------------------------------------------------------------ //

	// ------------------------------------------------------------ //
	//	검색을 위한 처리 시작
	// ------------------------------------------------------------ //
	if($keyfield_cd && $keyfield_nm && $keyfield_bigo)
	{
		$keyfield = "total";
	}
	else if($keyfield_cd)
	{
		$keyfield = "cd";
	}
	else if($keyfield_nm)
	{
		$keyfield = "nm";
	}
	else if($keyfield_bigo)
	{
		$keyfield = "bigo";
	}

	$tm_search_var = array(
						"total" => " * 전 체 * ",
						"cd" => "코드",
						"nm" => "코드명",
						"bigo" => "비고"
					);

	$tm_check_line = array(
						"10" => "10",
						"20" => "20",
						"30" => "30",
						"50" => "50",
						"100" => "100",
						"200" => "200",
						"100000" => "전체"
					);
	// ------------------------------------------------------------ //
	//	검색을 위한 처리 끝
	// ------------------------------------------------------------ //

	########## 리스트 출력화일 ##########
	include "html/list.inc";
	#####################################
?>
