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
	$query_where = "WHERE GB = '$a_gb' AND CD = '$a_cd' AND ITEM = '$a_item' ";

	$query_order = "ORDER BY NO DESC ";

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



       // 게시물의 링크
		$arr[$i][LISTBODY_LINK] = "listbody.html?$po_adv_query&page=$page&po_no=" . $arr[$i][NO];

		# ---- 글쓴날 처리 ---- #
		$arr[$i][INPUT_YMDHMS] = substr($arr[$i][INPUT_YMDHMS],0,4) . "-" .
									substr($arr[$i][INPUT_YMDHMS],4,2) . "-" .
									substr($arr[$i][INPUT_YMDHMS],6,2);

	

		
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
		$FIRST_PAGE = "<a href='list.html?$po_adv_query&page=1'>" . $paging_skin[$P_SKIN][first] . "</a>";
	}
	else
	{
		$FIRST_PAGE = $paging_skin[$P_SKIN][first];
	}

	# ---- 마지막페이지 ---- #
	if($board->total_page > 1 && $board->total_page != $board->page)
	{
		$LAST_PAGE = "<a href='list.html?$po_adv_query&page=" . $board->total_page . "'>" . $paging_skin[$P_SKIN][last] . "</a>";
	}
	else
	{
		$LAST_PAGE = $paging_skin[$P_SKIN][last];
	}

	# ---- 이전페이지 블록 ---- #
	if($board->prev_pageblock)
	   $PREV_BLOCK = "<a href=\"list.html?$po_adv_query&page=" . $board->prev_pageblock . "\" onMouseOver=\"status='load previous $page_per_block pages';return true;\" onMouseOut=\"status=''\">" . $paging_skin[$P_SKIN][prev_pageblock] . "</a>";
	else
	   $PREV_BLOCK = $paging_skin[$P_SKIN][prev_pageblock];

	# ---- 이전페이지 ---- #
	if($board->prev_page)
		$PREV_PAGE = "<a href=\"list.html?$po_adv_query&page=" . $board->prev_page . "\" onMouseOver=\"status='previous page';return true;\" onMouseOut=\"status=''\">" . $paging_skin[$P_SKIN][prev_page] . "</a>";
	else
		$PREV_PAGE = $paging_skin[$P_SKIN][prev_page];

	# ---- 다음페이지 ---- #
	if($board->next_page)
	   $NEXT_PAGE = "<a href=\"list.html?$po_adv_query&page=" . $board->next_page . "\" onMouseOver=\"status='next page';return true;\" onMouseOut=\"status=''\">" . $paging_skin[$P_SKIN][next_page] . "</a>";
	else
		$NEXT_PAGE = $paging_skin[$P_SKIN][next_page];

	# ---- 다음페이지 블록 ---- #
	if($board->next_pageblock)
		$NEXT_BLOCK = "<a href=\"list.html?$po_adv_query&page=" . $board->next_pageblock . "\" onMouseOver=\"status='load next $page_per_block pages';return true;\" onMouseOut=\"status=''\">" . $paging_skin[$P_SKIN][next_pageblock] . "</a>";
	else
	   $NEXT_BLOCK = $paging_skin[$P_SKIN][next_pageblock];

	# ---- 페이지링크 ---- #
	if($board->page_count == 0)
	{
		$board->page_count = 1;
		$PAGES[$i] = " <font color='red'>" . $paging_skin[$P_SKIN][none] . "</font> ";
	}
	else
	{
		for($i=0; $i<$board->page_count; $i++)
		{
			if($board->pages[$i] == $page)
				$PAGES[$i] = " <b>" . $board->pages[$i] . "</b> ";
			else
				$PAGES[$i] = " <a href='list.html?$po_adv_query&page=" . $board->pages[$i] . "'>" . $board->pages[$i] . "</a> ";
		}
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
//		$POST = "<a href='postform.html?$po_adv_query&page=$page' onMouseOver=\"status='새 글쓰기';return true;\" onMouseOut=\"status=''\"><img src='$cf_images_dir/post.gif' align='absmiddle'></a>";
		$POST = "<a href=\"postform.html?$po_adv_query&page=$page\" onMouseOver=\"status='post a new article';return true;\" onMouseOut=\"status=''\"><img src=\"$cf_images_dir/post.gif\" align='absmiddle'></a>";
	}
	################################################################
	# 삭제 버튼
	if($cf_delete_level_yn == "Y"){
		$DELETE = "<a href=\"javascript:check_del('delete_list.html?$po_adv_query')\"><img src=\"$cf_images_dir/delete.gif\" border=0 align='absmiddle' style='cursor:hand'></a>";
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

			
	// 1차 카테고리
	if($my_kind_gb == "all") $tm_kind_gb_all = "selected";	
	else if($my_kind_gb == "3040") $tm_kind_gb_3040 = "selected";	
	else if($my_kind_gb == "5060") $tm_kind_gb_5060 = "selected";	


	// 2차 카테고리
	$query = "SELECT CD, NM FROM $cf_table_cod_nm WHERE GB = '$po_board_kind' ORDER BY CD ASC";
	$kind_cd_arr = $DB->Arr($query);

	
	
	
	########## 리스트 출력화일 ##########
	include $cf_skin_nm . "/list.inc";
	#####################################
	
	// 검색박스 출력
	if($cf_search_cd == "search100")
	{
		include $cf_skin_nm . "/t_search_select.inc";
	}
	else if($cf_search_cd == "search200")
	{
		include $cf_skin_nm . "/t_search_checkbox.inc";
	}
?>
