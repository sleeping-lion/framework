<?
	// 결제코드배열
	$query = "SELECT CD, NM FROM $cf_table_cod_nm WHERE GB = 'cart_cd'";
	$tm_progress_arr_tmp = $DB->Arr($query);

	for($i=0; $i<sizeof($tm_progress_arr_tmp); $i++)
	{
		$k = $tm_progress_arr_tmp[$i][0];
		$v = $tm_progress_arr_tmp[$i][1];
		$tm_progress_arr[$k] = $v;
	}
	unset($tm_progresss_arr_tmp);


	# 초기값 설정
	$board = new CPaging();
	$page = $page ? $page : 1;
	$cf_num_per_page = $check_line ? $check_line : $cf_num_per_page;

	# ------------------------------------------------------------ #
	#	사용할 쿼리정리 시작
	# ----------------------------------------------------------- #
	$query_select		= "SELECT a.*,c.PAY_NAME,c.SENDING_CHARGE,c.AMOUNT,c.RE_AMOUNT,c.SETTLEMENT_CD, c.MILEAGE ";
	$query_select_count = "SELECT COUNT(b.ORDER_NO) ";
	$query_from			= "FROM $cf_table_ord_nm as a, $cf_table_car_nm as b, $cf_table_cre_nm as c ";
	$query_where		= "WHERE a.ORDER_NO=b.ORDER_NO AND a.ORDER_NO=c.ORDER_NO ";
	$query_order		= "ORDER BY c.SEQ DESC ";

	if($sr_start_day && $sr_end_day) {	// 주문날짜
		$query_where .= "AND (DATE_FORMAT(a.INPUT_YMDHMS,'%Y%m%d') >= $sr_start_day AND DATE_FORMAT(a.INPUT_YMDHMS,'%Y%m%d') <= $sr_end_day) ";
	}
	if($sr_settlement_cd) {	// 결제방법
		$query_where .= "AND c.SETTLEMENT_CD = '$sr_settlement_cd' ";
	}
	if($sr_receipt_cd) {	// 입금완료
		$query_where .= "AND c.RECEIPT_CD = '$sr_receipt_cd' ";
	}
	if($sr_progress) {	// 진행상황
		$query_where .= "AND a.PROGRESS = '$sr_progress' ";
	}

	if($sr_tex_yn) {	// 세금계산서
		$query_where .= "AND c.TEX_YN = '$sr_tex_yn' ";
	}

	// 검색키가 있는경우
	if(eregi("[^[:space:]]+",$key))
	{
		$encoded_key = urlencode($key);

		if ($keyfield_order_no || $keyfield_pay_name || $keyfield_sen_name || $keyfield_it_name || $keyfield_input_id)
		{
			$query_where = $query_where . "AND ( ";
			if($keyfield_order_no)
				$query_order_no = "$keyfield_order_no LIKE '%$key%' ";
			else
				$query_order_no = "1 = 2 ";

			if($keyfield_pay_name)
				$query_pay_name = "$keyfield_pay_name LIKE '%$key%' ";
			else
				$query_pay_name = "1 = 2 ";

			if($keyfield_sen_name)
				$query_sen_name = "$keyfield_sen_name LIKE '%$key%' ";
			else
				$query_sen_name = "1 = 2 ";

			if($keyfield_it_name)
				$query_it_name = "$keyfield_it_name LIKE '%$key%' ";
			else
				$query_it_name = "1 = 2 ";

			if($keyfield_input_id)
				$query_input_id = "$keyfield_input_id LIKE '%$key%' ";
			else
				$query_input_id = "1 = 2 ";

			$query_where	= 	$query_where .
								$query_order_no . "OR " .
								$query_pay_name . "OR " .
								$query_it_name . "OR " .
								$query_input_id . "OR " .
								$query_sen_name . ") ";
		}
	}
	# ------------------------------------------------------------ #
	#	사용할 쿼리정리 끝
	# ----------------------------------------------------------- #
	
	##################################################
	// group 장바구니 때문
	$query_where .= " GROUP BY b.ORDER_NO ";


	# ---- 전체게시물 수를 구한다. ---- #
	$query = $query_select_count .
				$query_from .
				$query_where;
//				echo $query."<br>";
	//$total_record = $DB->Value($query);

	$result = mysql_query($query,$DB->connect);
	$total_record = @mysql_num_rows($result);


	# ---- 페이징변수 처리 (총 레코드수, 현재페이지번호, 페이지당 레코드수, 페이지블럭당 페이지 수) ---- #
    $board->Paging($total_record, $page, $cf_num_per_page, $cf_page_per_block);

	# ---- 전체 출력할 레코드를 가져온다. ---- #
	$query_limit = "LIMIT $board->first, $board->record_count";
	$query = $query_select .
				$query_from .
				$query_where .
				$query_order .
				$query_limit;
	
	if($_SERVER[REMOTE_ADDR]=="210.97.226.101"){
		echo "<div align='left'>";
		echo "전체게시물수:".$query_select_count."<br>";
		echo $query_select."<br>";
		echo $query_from."<br>";
		echo $query_where."<br>";
		echo $query_order."<br>";
		echo "</div>";
	}
	$arr = $DB->Pipe_Arr($query);

	// ------------------------------------------------------------ //
	//	출력할 레코드처리 시작


	// 게시물의 가상번호(게시물의 개수에 따른 일련번호)
	$article_num = $total_record - $cf_num_per_page * ($page - 1);
	$loop_cnt = 0;

	// 실제 출력 레코드변수 설정
	for($i=0; $i<$board->record_count; $i++)
	{
		// 게시물 번호
		$arr[$i][NUM] = $article_num;
		
		// 주문번호
		//$arr[$i][ORDER_NO]

		// 구매자 이름
		//$arr[$i][SEN_NAME]

		// 입금자명
		// $arr[$i][PAY_NAME]

		// 요청금액
		//$arr[$i][AMOUNT]
		
		// 결제금액
		// $arr[$i][RE_AMOUNT]

		// 결제방법
//		echo $arr[$i][SETTLEMENT_CD]."<br>";
		switch($arr[$i][SETTLEMENT_CD]){
			case (10) :
				$arr[$i][SETTLEMENT_CD_NM] = "신용카드";
				break;
			case (20) :
				$arr[$i][SETTLEMENT_CD_NM] = "무통장";
				break;
			case (30) :
				$arr[$i][SETTLEMENT_CD_NM] = "계좌이체";
				break;

		}

    #마일리지 확인
    if($arr[$i][AMOUNT] > 0 && $arr[$i][MILEAGE] && $arr[$i][MILEAGE] > 0){
			$arr[$i][SETTLEMENT_CD_NM] = "적립금&". $arr[$i][SETTLEMENT_CD_NM] ;
    }else if($arr[$i][MILEAGE] && $arr[$i][MILEAGE] > 0){
      $arr[$i][SETTLEMENT_CD_NM] = "적립금";
    }


		if($arr[$i][AFTER_MEMO]) {
			$arr[$i][AFTER_MEMO_M] = "<font color='red'>ⓜ</font>";
		}

		$arr[$i][LISTBODY_LINK] = "listbody.html?".$po_adv_query."&page=".$page."&po_no=".$arr[$i][ORDER_NO];

		// 상태코드
		//$tm_progress_arr[$k] = $v;
		//$tm_progress_arr[$my_progress]
		$tm_progress = $arr[$i][PROGRESS];
		$arr[$i][PROGRESS_NM] = $tm_progress_arr[$tm_progress];

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
		$DELETE = get_button_href(" 삭제 ","","","onclick=\"Delete_check();\"");
	}
	// ------------------------------------------------------------ //
	//	버튼처리 끝
	// ------------------------------------------------------------ //

	// ------------------------------------------------------------ //
	//	검색을 위한 처리 시작
	// ------------------------------------------------------------ //

	$tm_search_var = array(
						"total" => " * 전 체 * ",
						"input_id" => "구매자아이디",
						"order_no" => "주문번호",
						"sen_name" => "구매자명",
						"pay_name" => "입금자명",
						"it_name" => "상품명"
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

	$tm_settlement_cd = array(
						"10" => "카드결제",
						"20" => "무통장입금"
					);
	
	$tm_receipt_cd = array(
						"10" => "미입금",
						"20" => "입금확인"
					);

	$tm_tex_cd = array(
						"Y" => "발행",
						"N" => "미발행"
					);

	$tm_progress = array(
						"20" => "결제요청",
						"50" => "배송신청",
						"60" => "배송중",
						"70" => "배송완료",
						"80" => "반송",
						"100" => "완결",
						"120" => "환불"
					);
	// ------------------------------------------------------------ //
	//	검색을 위한 처리 끝
	// ------------------------------------------------------------ //

	########## 리스트 출력화일 ##########
	include "html/list.inc";
	#####################################
?>
