<?
$cf_now_year=date("Y");  //현재년도
$cf_now_mon=date("m");
$cf_now_day=date("d");


if($po_st_year == null || $po_st_month == null ) {
	$po_st_year = $cf_now_year;
	$po_st_month = $cf_now_mon;
}

$cf_maxday = get_totalday($po_st_year,$po_st_month);

	// 링크를 위한 쿼리 정의 - 기본쿼리(항상유지되야할쿼리) - adv쿼리(검색을 고려한쿼리)
    $po_basic_query = $cf_basic_nm;
	$po_adv_query = $po_basic_query;

	if($po_st_year) $po_adv_query .= "&po_st_year=$po_st_year";
	if($po_st_month) $po_adv_query .= "&po_st_month=$po_st_month";


for($y=2012 ; $y <= $cf_now_year ; $y++) {
	$arr_year[$y] = $y; 
}
for($m=1 ; $m <= 12 ; $m++) {
	$arr_month[$m] = $m; 
}
$arr_month[13] = "전체";
?>