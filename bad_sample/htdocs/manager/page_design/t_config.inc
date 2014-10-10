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

    if($a_cd){
		switch($a_cd){
			case "1" : $tm_menu_nm=" 핫 세일 "; break;
			case "2" : $tm_menu_nm=" 이벤트 "; break;
			case "3" : $tm_menu_nm=" 메인 이벤트 품목 "; break;
		}
	}
?>