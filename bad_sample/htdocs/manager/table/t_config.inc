<?php
	//-- 검색종류가 선택박스인경우 검색 변수 처리
	if($_POST[keyfield])
	{
		if($_POST[keyfield] == "total")
		{
			$keyfield_gb = "gb";
			$keyfield_cd = "cd";
			$keyfield_title_nm = "title_nm";
		}
		else if($_POST[keyfield] == "gb")
		{
			$keyfield_gb = "gb";
		}
		else if($_POST[keyfield] == "cd")
		{
			$keyfield_cd = "cd";
		}
		else if($_POST[keyfield] == "title_nm")
		{
			$keyfield_memo = "title_nm";
		}
	}

	//-- 검색종류가 선택박스인경우 검색 변수 처리 끝

	// 링크를 위한 쿼리 정의 - 기본쿼리(항상유지되야할쿼리) - adv쿼리(검색을 고려한쿼리)
	$po_basic_query = "a_gb=$a_gb&a_cd=$a_cd&a_item=$a_item";
	$po_adv_query = $po_basic_query;
	if($check_line) $po_adv_query .= "&check_line=$check_line";
	if($key) $po_adv_query .= "&keyfield_gb=$keyfield_gb&keyfield_cd=$keyfield_cd&keyfield_title_nm=$keyfield_title_nm&key=$encoded_key";
?>
