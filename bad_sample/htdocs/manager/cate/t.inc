<?
	$query = "SELECT * FROM " . $cf_table_col_nm . " " .
				"WHERE GB = '$po_gb' AND CD = '$po_cd'";

    $arr = $DB->Pipe_Row($query);

    // 정보가 있는경우
    if(is_array($arr))
    {
        foreach($arr as $k => $v)
            ${"my_" . strtolower($k)} = $v;
        unset($arr);
    }



?>
