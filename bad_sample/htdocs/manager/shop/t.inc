<?
	$query = "SELECT * FROM " . $cf_table_col_nm . " " .
				"WHERE NO = '$po_no'";
    $arr = $DB->Pipe_Row($query);

    // 정보가 있는경우
    if(is_array($arr))
    {
        foreach($arr as $k => $v)
            ${"my_" . strtolower($k)} = $v;
        unset($arr);
    }

	##### 프로그램에 따라서 쿼리부분과 아래 부분만 수정하세요. #####


	// addslashes() 함수로 escape된 문자열을 원상복귀시킨다.
	$my_it_name = stripslashes($my_it_name);
	$my_it_company = stripslashes($my_it_company);
	$my_it_memo = stripslashes($my_it_memo);


	// 수정폼인경우는 HTML태그 허용여부, 검색어처리 및 문자열개행처리를 하지 않는다.
	if($MY_URI == "listbody" || $MY_URI == "deleteform")
	{
		// 본문에 대해 HTML태그를 허용하지 않을 경우 태그문자를 그대로 출력한다.
		if($cf_allow_html_yn == "N")
		{
			$my_it_memo = strip_tags($my_it_memo);
      // 문자열을 개행처리한다.
		$my_it_memo = nl2br($my_it_memo);
		}

		


		// 삭제폼의 경우 메일발송자료로 활용되며 검색어처리가 필요없다.
		if($MY_URI != "deleteform")
		{
			// 검색어가 있는 경우 검색어를 red color 처리하여 출력한다.
			if(!strcmp($keyfield_subject,"subject") && $key)
				$my_it_profile = eregi_replace("($key)", "<font color=red>\\1</font>", $my_it_profile);

			if(!strcmp($keyfield_input_nm,"input_nm") && $key)
				$my_input_nm = eregi_replace("($key)", "<font color=red>\\1</font>", $my_input_nm);

			if(!strcmp($keyfield_it_memo,"memo") && $key)
				$my_it_memo = eregi_replace("($key)","<font color=red>\\1</font>",$my_it_memo);
		}

	}

	unset($img_arr);
	$query = "SELECT EXT1,EXT2,EXT3,EXT4,EXT5,EXT6,EXT7,EXT8,EXT9,EXT10 FROM " . $cf_table_img_nm . " " .
				"WHERE IT_NO = '$my_it_no'";
    $img_arr = $DB->Row($query);

?>
