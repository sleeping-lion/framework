<?php
	// 패스워드를 암호화하여 입력한다.
	$tm_crypt_passwd = $DB->Value("SELECT md5('$fr_cm_passwd')");

	// 문자열에 포함된 특수문자를 escape시킨다.
	$fr_cm_etc = escape_string($fr_cm_etc);

	# ---------------------------------------- #
	#	레벨관련처리
	# ---------------------------------------- #
	// 회원레벨 - 요청레벨이 있더라도 현재는 일반회원
	if(!$fr_cm_level) $fr_cm_level = "xx";

	
	// 탈퇴관련
	$tm_cm_del_yn = "N";
	$tm_cm_del_ymdhms = "";
	$tm_cm_del_reason = "";

	// 로그인 횟수 (자동로그인이므로 초기화 1);
	$tm_cm_log_cnt = 1;

	// 최종 접속시간
	$tm_cm_time = date("YmdHis");

	// 핸드폰 번호만들기
	if($fr_cm_hp_tel1 && $fr_cm_hp_tel2 && $fr_cm_hp_tel3) {
		$tm_cm_hp_tel = $fr_cm_hp_tel1."-".$fr_cm_hp_tel2."-".$fr_cm_hp_tel3;
	}
	// 전화 번호만들기
	if($fr_cm_tel1 && $fr_cm_tel2 && $fr_cm_tel3) {
		$tm_cm_tel = $fr_cm_tel1."-".$fr_cm_tel2."-".$fr_cm_tel3;
	}

	// 팩스 번호만들기
	if($fr_cm_fax1 && $fr_cm_fax2 && $fr_cm_fax3) {
		$tm_cm_fax = $fr_cm_fax1."-".$fr_cm_fax2."-".$fr_cm_fax3;
	}


	// 이메일

	// 작성자관련정보 설정
	$tm_input_id = $fr_cm_id;
	$tm_input_nm = $fr_cm_nm;
	$tm_input_ip = $_SERVER[REMOTE_ADDR];
	$tm_input_ymdhms = $tm_cm_time;
	$tm_sign_id = $tm_input_id;
	$tm_sign_nm = $tm_input_nm;
	$tm_sign_ip = $tm_input_ip;
	$tm_sign_ymdhms = $tm_input_ymdhms;

	// ------------------------------------------------------------- //
	//	입력쿼리
	// ------------------------------------------------------------- //
    $query = "INSERT INTO $cf_table_mem_nm (" .
					"CM_ID, " .
					"CM_PASSWD, " .
					"CM_PASSWD_Q, " .
					"CM_PASSWD_A, " .
					"CM_NM, " .
					"CM_JUMIN, " .
					"CM_EMAIL, " .
					"CM_TEL, " .
					"CM_HP_TEL, " .
					#"CM_FAX, " .
					"CM_ZIP_CD, " .
					"CM_ADDR, " .
					"CM_ADDR2, " .
					"CM_LEVEL, " .
					"CM_REQ_LEVEL, " .
					"CM_DEL_YN, " .
					"CM_DEL_YMDHMS, " .
					"CM_DEL_REASON, " .
					"CM_LOG_CNT, " .
					"CM_TIME, " .
					#"CM_COM_NM, " .
					#"CM_COM_NUM, " .
					"INPUT_IP, " .
					"INPUT_ID, " .
					"INPUT_NM, " .
					"INPUT_YMDHMS, " .
					"SIGN_IP, " .
					"SIGN_ID, " .
					"SIGN_NM, " .
					"SIGN_YMDHMS, " .
					"SERIAL_NO" .

				") VALUES (" .

					"'$fr_cm_id', " .
					"'$tm_crypt_passwd', " .
					"'$fr_cm_passwd_q', " .
					"'$fr_cm_passwd_a', " .
					"'$fr_cm_nm', " .
					"'$fr_cm_jumin', " .
					"'$fr_cm_email', " .
					"'$tm_cm_tel', " .
					"'$tm_cm_hp_tel', " .
					#"'$tm_cm_fax', " .
					"'$fr_zip_cd', " .
					"'$fr_addr', " .
					"'$fr_addr2', " .
					"'$fr_cm_level', " .
					"'$fr_cm_req_level', " .
					"'$tm_cm_del_yn', " .
					"'$tm_cm_del_ymdhms', " .
					"'$tm_cm_del_reason', " .
					"'$tm_cm_log_cnt', " .
					"'$tm_cm_time', " .
					#"'$fr_cm_com_nm', " .
					#"'$fr_cm_com_num', " .
					"'$tm_input_ip', " .
					"'$tm_input_id', " .
					"'$tm_input_nm', " .
					"'$tm_input_ymdhms', " .
					"'$tm_sign_ip', " .
					"'$tm_sign_id', " .
					"'$tm_sign_nm', " .
					"'$tm_sign_ymdhms', " .
					"'$fr_serial_no'" .
				")";

	// 입력처리
	$DB->Insert_Query($query);

	error_msg("정상적으로 가입되었습니다.","listbody.html?".$po_adv_query."&po_cm_id=".$fr_cm_id,"parent");
?>
