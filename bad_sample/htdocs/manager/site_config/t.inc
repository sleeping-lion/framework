<?
	unset($arr);
	$query = "SELECT * FROM $cf_table_col_nm WHERE NO = '$po_no'";
    $arr = $DB->Pipe_Row($query);

    // 정보가 있는경우
    if(is_array($arr))
    {
        foreach($arr as $k => $v)
			${"my_" . strtolower($k)} = $v;
        unset($arr);
    }

	
?>
