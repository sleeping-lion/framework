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

	##### 프로그램에 따라서 쿼리부분과 아래 부분만 수정하세요. #####

	// addslashes() 함수로 escape된 제목과 본문의 문자열을 원상복귀시킨다.
	$my_subject = stripslashes($my_subject);
	$my_memo = stripslashes($my_memo);

	// 수정폼인경우는 HTML태그 허용여부, 검색어처리 및 문자열개행처리를 하지 않는다.
	if($MY_URI == "listbody" || $MY_URI == "deleteform")
	{
		// 원칙상 제목에는 HTML 태그를 허용하지 않는다.
		$my_subject = strip_tags($my_subject);

		// 본문에 대해 HTML태그를 허용하지 않을 경우 태그문자를 그대로 출력한다.
		if($cf_allow_html_yn == "N" && $my_html_yn == "N")
		{
			$my_memo = strip_tags($my_memo);

			// 본문의 문자열을 개행처리한다.
			$my_memo = nl2br($my_memo);

			// HTML링크및 이메일 자동링크 (HTML을 허용하지 않는 경우만
			$my_memo = auto_link($my_memo);
		}
		else if($my_html_yn == "Y")
		{
		}
		else if($cf_allow_html_yn == "Y")
		{
			// 본문의 문자열을 개행처리한다.
			//$my_memo = nl2br($my_memo);
			//본문의 문자열을 개행처리하지 않는다
			$my_memo = $my_memo;
		}

		// 삭제폼의 경우 메일발송자료로 활용되며 검색어처리가 필요없다.
		if($MY_URI != "deleteform")
		{
			// 검색어가 있는 경우 검색어를 red color 처리하여 출력한다.
			if(!strcmp($keyfield_subject,"subject") && $key)
				$my_subject = eregi_replace("($key)", "<font color=red>\\1</font>", $my_subject);

			if(!strcmp($keyfield_input_nm,"sign_nm") && $key)
				$my_sign_nm = eregi_replace("($key)", "<font color=red>\\1</font>", $my_sign_nm);

			if(!strcmp($keyfield_memo,"memo") && $key)
				$my_memo = eregi_replace("($key)","<font color=red>\\1</font>",$my_memo);
		}
	}
?>
