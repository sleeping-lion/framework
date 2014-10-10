<?
	$query = "SELECT * FROM $cf_table_col_nm " .
				"WHERE ORDER_NO='$po_no'";
	$arr = $DB->Pipe_Row($query);

    // 정보가 있는경우
    if(!is_array($arr))
		error_msg("관리자에게 문의하세요.", "back");

	foreach($arr as $k => $v)
	{
		${"my_" . strtolower($k)} = $v;
	}
	unset($arr);

	$encoded_key = urlencode($key);
	$my_memo = nl2br($my_memo);

?>
