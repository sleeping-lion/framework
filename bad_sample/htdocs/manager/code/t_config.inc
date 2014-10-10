<?
	//-- 검색종류가 선택박스인경우 검색 변수 처리
	if($_POST[keyfield])
	{
		if($_POST[keyfield] == "total")
		{
			$keyfield_cd = "cd";
			$keyfield_nm = "nm";
			$keyfield_bigo = "bigo";
		}
		else if($_POST[keyfield] == "cd")
		{
			$keyfield_cd = "cd";
		}
		else if($_POST[keyfield] == "nm")
		{
			$keyfield_nm = "nm";
		}
		else if($_POST[keyfield] == "bigo")
		{
			$keyfield_bigo = "bigo";
		}
	}

	//-- 검색종류가 선택박스인경우 검색 변수 처리 끝

	// 링크를 위한 쿼리 정의 - 기본쿼리(항상유지되야할쿼리) - adv쿼리(검색을 고려한쿼리)
    $po_basic_query = "a_gb=$a_gb&a_cd=$a_cd&a_item=$a_item&check_line=$check_line&sm=$sm";
	$po_adv_query = $po_basic_query . "&keyfield_cd=$keyfield_cd&keyfield_nm=$keyfield_nm&keyfield_bigo=$keyfield_bigo&key=$encoded_key";
?>