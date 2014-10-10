<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<?
	// POST로 넘어온 변수들을 입력값에 맞도록 특수문자를 escape한다.
	if(is_array($_POST))
	{
		foreach($_POST as $k => $v)
		{
			if($v == "Array" || is_array($v)) continue;
			unset(${$k});
			${$k} = escape_string(trim($v));
		}
	}

	if(!ereg("([^[:space:]]+)", $fr_subject))
	{
		error_msg("입력하신 제목은 허용되지 않는 문자입니다.\\n\\n다시 입력하여 주십시오..", "back");
		exit;
	}

	if(!ereg("([^[:space:]]+)", $fr_input_nm))
	{
		error_msg("입력하신 이름은 허용되지 않는 문자입니다.\\n\\n 다시 입력하여 주십시오.", "back");
		exit;
	}

//	if(ereg("([^[:space:]]+)", $fr_email) && (!ereg("(^[_0-9a-zA-Z-]+(\.[_0-9a-zA-Z-]+)*@[0-9a-zA-Z-]+(\.[0-9a-zA-Z-]+)*$)", $fr_email)))
//	{
//		error_msg("입력하신 이메일 주소는 허용되지 않는 주소입니다.\\n\\n 다시 입력하여 주십시오.", "back");
//		exit;
//	}

	if(!$cf_cook_id && !ereg("(^[0-9a-zA-Z]{4,}$)", $fr_passwd))
	{
		error_msg("입력하신 비밀번호는 허용되지 않는 문자입니다.\\n\\n 다시 입력하여 주십시오.", "back");
		exit;
	}

//	if($fr_homepage == "http://")
//	{
//		$fr_homepage = "";
//	}

//	if(ereg("([^[:space:]]+)", $fr_homepage) && (!ereg("http://([0-9a-zA-Z./@~?&=_]+)", $fr_homepage)))
//	{
//		error_msg("입력하신 홈페이 주소는 허용되지 않는 주소입니다.\\n\\n 다시 입력하여 주십시오.", "back");
//		exit;
//	}

	if(!ereg("([^[:space:]]+)", $fr_memo))
	{
		error_msg("입력하신 본문은 허용되지 않는 문자입니다.\\n\\n 다시 입력하여 주십시오.", "back");
		exit;
	}

	# -------------------------------------------------------------------- #
	#	제한어 검색시작
	# -------------------------------------------------------------------- #
	$query = "SELECT BIGO FROM $cf_table_cod_nm WHERE CD = 'limit_string'";
	$l_string = trim($DB->Value($query));

	if($l_string)
	{
		$limit_string = explode(" ", $l_string);

		for($i=0; $i<sizeof($limit_string); $i++)
		{
			$limit_string[$i] = trim($limit_string[$i]);

			if(eregi($limit_string[$i], $fr_subject))
			{
				error_msg("제목의 $limit_string[$i] 는 사용할 수 없는 단어입니다.", "back");
				exit;
			}

			if(eregi($limit_string[$i], $fr_memo))
			{
				error_msg("본문의 $limit_string[$i] 는 사용할 수 없는 단어입니다.", "back");
				exit;
			}
		}
	}
	# -------------------------------------------------------------------- #
	#	제한어 검색 끝
	# -------------------------------------------------------------------- #
?>
