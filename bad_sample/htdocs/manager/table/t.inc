<?
	$query = "SELECT * FROM $cf_table_pgm_nm " .
				"WHERE GB = '$gb' AND CD = '$cd' AND ITEM = '$item'";
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
	// 구분코드명
	$my_gb_nm = get_code_nm($my_gb);

	// 사용테이블명
	$my_table_cd_nm = get_code_nm($my_table_nm);
	// 코멘트 사용테이블명
	$my_co_table_cd_nm = get_code_nm($my_co_table_nm);

	// 관리자명
//	$query = "SELECT CM_NM FROM CM_MEMBER_T WHERE CM_ID = '$my_admin_id'";
//	$my_cm_nm = $DB->Value($query);

	// 권한체크
	$my_post_level		= strtolower($my_post_level);
	$my_read_level		= strtolower($my_read_level);
	$my_body_level		= strtolower($my_body_level);
	$my_reply_level		= strtolower($my_reply_level);
	$my_modify_level	= strtolower($my_modify_level);
	$my_delete_level	= strtolower($my_delete_level);

	$my_post_nm			= get_code_nm($my_post_level);
	$my_read_nm			= get_code_nm($my_read_level);
	$my_body_nm			= get_code_nm($my_body_level);
	$my_reply_nm		= get_code_nm($my_reply_level);
	$my_modify_nm		= get_code_nm($my_modify_level);
	$my_delete_nm		= get_code_nm($my_delete_level);

	// 게시판형태
	$my_board_cd_nm = get_code_nm($my_board_cd);

	// 검색창종류
	$my_search_cd_nm = get_code_nm($my_search_cd);

	// addslashes() 함수로 escape된 제목과 본문의 문자열을 원상복귀시킨다.
	$my_title_annou = stripslashes($my_title_annou);
	$my_title_desc = stripslashes($my_title_desc);

	// 수정폼인경우는 HTML태그 허용여부, 검색어처리 및 문자열개행처리를 하지 않는다.
	if($MY_URI == "listbody" || $MY_URI == "deleteform" || $MY_URI == "delete")
	{
		// 종합코드에서는 HTML 태그를 허용하지 않는다.
		$my_title_annou = str_replace("<", "&lt", $my_title_annou);
		$my_title_annou = str_replace(">", "&gt", $my_title_annou);
		$my_title_desc = str_replace("<", "&lt", $my_title_desc);
		$my_title_desc = str_replace(">", "&gt", $my_title_desc);

		// 삭제의 경우 메일발송자료로 활용되며 검색어처리가 필요없다.
		if($MY_URI != "delete")
		{
			// 검색어가 있는 경우 검색어를 red color 처리하여 출력한다.
			if(!strcmp($keyfield_gb,"gb") && $key)
				$my_gb = eregi_replace("($key)", "<font color=red>\\1</font>", $my_gb);

			if(!strcmp($keyfield_cd,"cd") && $key)
				$my_cd = eregi_replace("($key)", "<font color=red>\\1</font>", $my_cd);

			if(!strcmp($keyfield_title_nm,"title_nm") && $key)
				$my_title_nm = eregi_replace("($key)","<font color=red>\\1</font>",$my_title_nm);
		}

		// 본문의 문자열을 개행처리한다.
		$my_title_annou = nl2br($my_title_annou);
		$my_title_desc = nl2br($my_title_desc);
	}


?>
