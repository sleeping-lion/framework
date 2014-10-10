<?
	// 수강권번호 재조립
	$tm_ti_ticket = $fr_key1 . $fr_key3 . substr($fr_key_start, 0, 1) . $fr_key5 . substr($fr_key_start, 1, 1) . $fr_key7 . $fr_key9 . substr($fr_key_start, 2, 1) . $fr_key11 . substr($fr_key_start, 3, 1) . $fr_key13 . substr($fr_key14, 0, 1) . $fr_key15 . substr($fr_key14, 1, 1);

	if (!checkCouponRule($tm_ti_ticket))
	{
		error_msg("수강권 규칙이 맞지 않습니다.", "back");
	}

	$tm_ti_key = $fr_key1 . $fr_key3 . $fr_key5 . $fr_key7 . $fr_key9 . $fr_key11 . $fr_key13 . substr($fr_key14, 0, 1) . $fr_key15 . substr($fr_key14, 1, 1);

	if ($MY_URI == "post")
	{
		$query = "SELECT TI_KEY FROM " . $cf_table_col_nm . " WHERE TI_KEY = '" . $tm_ti_key . "' AND TI_START <= '" . $fr_key_start . "' AND TI_END >= '" . $fr_key_end . "'";
		$my_ti_key = $DB->Value($query);
	}
	else if ($MY_URI == "modify")
	{
		$query = "SELECT TI_KEY FROM " . $cf_table_col_nm . " WHERE TI_NO != " . $po_ti_no . " AND TI_KEY = '" . $tm_ti_key . "' AND TI_START <= '" . $fr_key_start . "' AND TI_END >= '" . $fr_key_end . "'";
		$my_ti_key = $DB->Value($query);
	}

	if (!empty($my_ti_key))
	{
		error_msg("중복되는 수강권 일련번호가 있습니다.", "back");
	}
?>
