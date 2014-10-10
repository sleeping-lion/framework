<?
//-- 검색종류가 선택박스인경우 검색 변수 처리
if($_POST[keyfield])
{
	if($_POST[keyfield] == "total")
	{
		$keyfield_order_no = "a.order_no";
		$keyfield_pay_name = "c.pay_name";
		$keyfield_sen_name = "c.sen_name";
		$keyfield_it_name = "b.it_name";
		$keyfield_input_id = "a.input_id";
	}
	else if($_POST[keyfield] == "order_no")
	{
		$keyfield_order_no = "a.order_no";
	}
	else if($_POST[keyfield] == "pay_name")
	{
		$keyfield_pay_name = "c.pay_name";
	}
	else if($_POST[keyfield] == "sen_name")
	{
		$keyfield_sen_name = "c.sen_name";
	}
	else if($_POST[keyfield] == "it_name")
	{
		$keyfield_it_name = "b.it_name";
	}
	else if($_POST[keyfield] == "input_id")
	{
		$keyfield_input_id = "a.input_id";
	}
}

// 링크를 위한 쿼리 정의 - 기본쿼리(항상유지되야할쿼리) - adv쿼리(검색을 고려한쿼리)
$po_basic_query = "a_gb=$a_gb&a_cd=$a_cd&a_item=$a_item";
$po_adv_query = $po_basic_query;
if($check_line) $po_adv_query .= "&check_line=$check_line";
if($sr_start_day) $po_adv_query .= "&sr_start_day=$sr_start_day";
if($sr_end_day) $po_adv_query .= "&sr_end_day=$sr_end_day";
if($sr_settlement_cd) $po_adv_query .= "&sr_settlement_cd=$sr_settlement_cd";
if($sr_receipt_cd) $po_adv_query .= "&sr_receipt_cd=$sr_receipt_cd";
if($sr_progress) $po_adv_query .= "&sr_progress=$sr_progress";
if($key) $po_adv_query .= "&keyfield_order_no=$keyfield_order_no&keyfield_pay_name=$keyfield_pay_name&keyfield_sen_name=$keyfield_sen_name&keyfield_it_name=$keyfield_it_name&keyfield_input_id=$keyfield_input_id&key=$encoded_key&keyfield=$keyfield";
?>