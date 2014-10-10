<?
	//-- 검색종류가 선택박스인경우 검색 변수 처리
	if($_POST[keyfield])
	{
		if($_POST[keyfield] == "total")
		{
			$keyfield_nm = "nm";
		}
		else if($_POST[keyfield] == "nm")
		{
			$keyfield_nm = "nm";
		}
	}
	//-- 검색종류가 선택박스인경우 검색 변수 처리 끝

	// 링크를 위한 쿼리 정의 - 기본쿼리(항상유지되야할쿼리) - adv쿼리(검색을 고려한쿼리)
    $po_basic_query = $cf_basic_nm;
	$po_adv_query = $po_basic_query;
	if($check_line) $po_adv_query .= "&check_line=$check_line";
	if($key) $po_adv_query .= "&keyfield_nm=$keyfield_nm&key=$encoded_key";
?>