<?
	// 링크를 위한 쿼리 정의 - 기본쿼리(항상유지되야할쿼리) - adv쿼리(검색을 고려한쿼리)
    $po_basic_query = $cf_basic_nm;
	$po_adv_query = $po_basic_query;

	if($po_code1) $po_adv_query .= "&po_code1=".$po_code1;
	if($po_code2) $po_adv_query .= "&po_code2=".$po_code2;
?>