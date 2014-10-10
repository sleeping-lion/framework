<?
	$query = "SELECT * FROM " . $cf_table_col_nm . " " .
				"WHERE GB = '$a_gb' AND CD = '$a_cd'";

    $arr = $DB->Pipe_Row($query);

    // 정보가 있는경우
    if(is_array($arr))
    {
        foreach($arr as $k => $v)
            ${"my_" . strtolower($k)} = $v;
        unset($arr);
    }

	
	$tm_real_path1 = $cf_savedir . "/" . $my_attach_path1;
	$tm_real_path_physical = $cf_doc_root . $tm_real_path1;
	if($cf_attach_size > 0 || $my_attach_path1)
	{
		if($my_attach_path1 && is_file($tm_real_path_physical))
		{
			$tm_attach_path1 = "<a href='".$tm_real_path1."' target='fdown'>$my_attach_path1</a>";
		}
		else
		{
			$tm_attach_path1 = "첨부된 화일이 없습니다.";
		}
	}


	$tm_real_path2 = $cf_savedir . "/" . $my_attach_path2;
	$tm_real_path_physical2 = $cf_doc_root . $tm_real_path2;
	if($cf_attach_size > 0 || $my_attach_path2)
	{
		if($my_attach_path2 && is_file($tm_real_path_physical2))
		{
			$tm_attach_path2 = "<a href='".$tm_real_path2."' target='fdown'>$my_attach_path2</a>";
		}
		else
		{
			$tm_attach_path2 = "첨부된 화일이 없습니다.";
		}
	}




?>
