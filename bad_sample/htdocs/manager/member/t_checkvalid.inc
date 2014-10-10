<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<?
	# ------------------------------------------ #
	#	패스워드
	# ------------------------------------------ #
	// 새 비밀번호가 입력된경우
	if(ereg("([^[:space:]]+)", $fr_cm_new_passwd))
	{
		// 새비밀번호 문자수
		if(strlen($fr_cm_new_passwd) < 4 || strlen($fr_cm_new_passwd) > 32)
		{
			error_msg("새비밀번호는 영문기준 4-32자 입니다.\\n\\n 다시 입력해주세요.", "back");
		}

		// 비밀번호확인 입력여부
		if(!ereg("([^[:space:]]+)", $fr_cm_new_passwd2) || strlen($fr_cm_new_passwd2) < 4 || strlen($fr_cm_new_passwd2) > 32)
		{
			error_msg("비밀번호 확인은 영문기준 4-32자 입니다.\\n\\n 다시 입력해주세요.", "back");
		}

		// 변경할 비밀번호 일치여부
		if($fr_cm_new_passwd != $fr_cm_new_passwd2)
		{
			error_msg("변경할 패스워드와 확인용 패스워드가 일치하지 않습니다.\\n\\n다시 입력해주세요.", "back");
		}

	}

	// 변경할 비밀번호가 있는경우 현재비밀번호를 변경할 비밀번호로 변경한다.
	if($fr_cm_new_passwd)
	{
		$fr_cm_passwd = $fr_cm_new_passwd;
	}
?>
