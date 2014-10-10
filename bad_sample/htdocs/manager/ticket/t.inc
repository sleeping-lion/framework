<?
	$query = "SELECT * FROM " . $cf_table_col_nm . " " .
				"WHERE TI_NO = '" . $po_ti_no . "'";
    $arr = $DB->Pipe_Row($query);

    // 정보가 있는경우
    if(is_array($arr))
    {
        foreach($arr as $k => $v)
            ${"my_" . strtolower($k)} = $v;
        unset($arr);
    }
?>
