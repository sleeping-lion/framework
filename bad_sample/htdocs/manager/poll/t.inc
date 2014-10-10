<?
	$query = "SELECT * FROM $cf_table_col_nm " .
				"WHERE NO = '$po_no'";
    $arr = $DB->Pipe_Row($query);

    // 정보가 있는경우
    if(!is_array($arr))
		error_msg("관리자에게 문의하세요.", "back");

	foreach($arr as $k => $v)
	{
		${"my_" . strtolower($k)} = $v;
	}
	unset($arr);

	##### 프로그램에 따라서 쿼리부분과 아래 부분만 수정하세요. #####
	// 설문 타입
	$my_poll_type_nm = get_code_nm($my_poll_type);


?>
