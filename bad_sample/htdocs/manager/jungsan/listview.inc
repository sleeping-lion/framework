<?
	

	if($sr_start_day && $sr_end_day) {	// 주문날짜
		$query_where .= "AND (DATE_FORMAT(a.INPUT_YMDHMS,'%Y%m%d') >= $sr_start_day AND DATE_FORMAT(a.INPUT_YMDHMS,'%Y%m%d') <= $sr_end_day) ";
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
