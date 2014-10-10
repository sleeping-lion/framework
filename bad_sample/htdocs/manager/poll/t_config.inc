<?
	//-- 검색종류가 선택박스인경우 검색 변수 처리
	

	//-- 검색종류가 선택박스인경우 검색 변수 처리 끝

	// 링크를 위한 쿼리 정의 - 기본쿼리(항상유지되야할쿼리) - adv쿼리(검색을 고려한쿼리)
	$po_basic_query = "a_gb=$a_gb&a_cd=$a_cd&a_item=$a_item";
	$po_adv_query = $po_basic_query;
	if($check_line) $po_adv_query .= "&check_line=$check_line";
	if($s_poll_type) $po_adv_query .= "&s_poll_type=$s_poll_type";
	if($s_subject) $po_adv_query .= "&s_subject=$s_subject";
?>
