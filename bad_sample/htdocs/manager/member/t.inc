<?
	$query = "SELECT * FROM " . $cf_table_mem_nm . " " .
				"WHERE CM_ID = '$po_cm_id'";
    $arr = $DB->Pipe_Row($query);

    // 정보가 있는경우
    if(is_array($arr))
    {
        foreach($arr as $k => $v)
            ${"my_" . strtolower($k)} = $v;
        unset($arr);
    }

	##### 프로그램에 따라서 쿼리부분과 아래 부분만 수정하세요. #####

	// 주민등록번호
	$my_cm_jumin1 = substr($my_cm_jumin, 0, 6);
	$my_cm_jumin2 = substr($my_cm_jumin, 6, 7);

	// 전화번호
	$tel = split("-", $my_cm_tel);
	$my_cm_tel1 = $tel[0];
	$my_cm_tel2 = $tel[1];
	$my_cm_tel3 = $tel[2];
	unset($tel);

	// 핸드폰번호
	$hp_tel = split("-", $my_cm_hp_tel);
	$my_cm_hp_tel1 = $hp_tel[0];
	$my_cm_hp_tel2 = $hp_tel[1];
	$my_cm_hp_tel3 = $hp_tel[2];
	unset($hp_tel);

	// 팩스번호
	$fax = split("-", $my_cm_fax);
	$my_cm_fax1 = $fax[0];
	$my_cm_fax2 = $fax[1];
	$my_cm_fax3 = $fax[2];
	unset($fax);

	// 아이피
	$ip_addr = split("-", $my_cm_ip);
	$my_cm_ip1 = $ip_addr[0];
	$my_cm_ip2 = $ip_addr[1];
	$my_cm_ip3 = $ip_addr[2];
	unset($ip);

	// 이메일주소
	$email = split("@", $my_cm_email);
	$my_cm_email1 = $email[0];
	$my_cm_email2 = $email[1];
	unset($email);


	$my_cm_etc = stripslashes($my_cm_etc);


	if($my_cm_children_yn=="Y"){
		switch($my_cm_children_age){
			case "1" : $tm_cm_children_age="유아"; break;
			case "2" : $tm_cm_children_age="초등"; break;
			case "3" : $tm_cm_children_age="중등"; break;
			case "4" : $tm_cm_children_age="고등"; break;
			case "5" : $tm_cm_children_age="20대"; break;
			case "6" : $tm_cm_children_age="30대이상"; break;
		}
	}
  
	// 수정폼인경우는 HTML태그 허용여부, 검색어처리 및 문자열개행처리를 하지 않는다.
	if($MY_URI == "listbody" || $MY_URI == "deleteform")
	{
		// 본문에 대해 HTML태그를 허용하지 않을 경우 태그문자를 그대로 출력한다. 
		if($cf_allow_html_yn == "N")
		{
			$my_cm_etc = htmlspecialchars($my_cm_etc);
		}

		// 삭제폼의 경우 메일발송자료로 활용되며 검색어처리가 필요없다.
		if($MY_URI != "deleteform")
		{
			// 검색어가 있는 경우 검색어를 red color 처리하여 출력한다.
			if(!strcmp($keyfield_cm_id,"cm_id") && $key)
				$my_cm_id = eregi_replace("($key)", "<font color=red>\\1</font>", $my_cm_id);

			if(!strcmp($keyfield_cm_nm,"cm_nm") && $key)
				$my_cm_nm = eregi_replace("($key)", "<font color=red>\\1</font>", $my_cm_nm);

			if(!strcmp($keyfield_cm_tel,"cm_tel") && $key)
				$my_cm_tel = eregi_replace("($key)","<font color=red>\\1</font>",$my_cm_tel);
		}

		// 본문의 문자열을 개행처리한다.
		$my_cm_etc = nl2br($my_cm_etc);
	}
?>
