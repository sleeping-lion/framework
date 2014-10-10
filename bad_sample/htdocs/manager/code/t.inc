<?
	$query = "SELECT * FROM $cf_table_cod_nm " .
				"WHERE GB = '$po_gb' AND CD = '$po_cd'";
    $arr = $DB->Pipe_Row($query);

    // 정보가 있는경우
    if(is_array($arr))
    {
        foreach($arr as $k => $v)
		{
            ${"my_" . strtolower($k)} = $v;
		}
        unset($arr);
    }

	##### 프로그램에 따라서 쿼리부분과 아래 부분만 수정하세요. #####

	// addslashes() 함수로 escape된 제목과 본문의 문자열을 원상복귀시킨다.
	$my_nm_desc = stripslashes($my_nm_desc);
	$my_bigo = stripslashes($my_bigo);

	// 수정폼인경우는 HTML태그 허용여부, 검색어처리 및 문자열개행처리를 하지 않는다.
	if($MY_URI == "listbody" || $MY_URI == "deleteform" || $MY_URI == "delete")
	{
		// 종합코드에서는 HTML 태그를 허용하지 않는다.
		$my_nm_desc = str_replace("<", "&lt", $my_nm_desc);
		$my_bigo = str_replace("<", "&lt", $my_bigo);

		// 삭제의 경우 메일발송자료로 활용되며 검색어처리가 필요없다.
		if($MY_URI != "delete")
		{
			// 검색어가 있는 경우 검색어를 red color 처리하여 출력한다.
			if(!strcmp($keyfield_cd,"cd") && $key)
				$my_cd = eregi_replace("($key)", "<font color=red>\\1</font>", $my_cd);

			if(!strcmp($keyfield_nm,"nm") && $key)
				$my_nm = eregi_replace("($key)", "<font color=red>\\1</font>", $my_nm);

			if(!strcmp($keyfield_bigo,"bigo") && $key)
				$my_bigo = eregi_replace("($key)","<font color=red>\\1</font>",$my_bigo);
		}

		// 본문의 문자열을 개행처리한다.
		$my_bigo = nl2br($my_bigo);
	}
?>
