<?php


//echo phpinfo();

	// 조회수 초기화
	$tm_ver_cnt = 0;		// 조회수
	$tm_comm_cnt = 0;		// 코멘트갯수
	$tm_recom_cnt = 0;		// 추천인수

	// HTML 사용여부
	$tm_html_yn = ($fr_html_yn == "Y") ? "Y" : "N";

	// 공개여부
	$tm_public_yn = ($fr_public_yn == "N") ? "N" : "Y";

	// 서비스여부
	$tm_service_yn = "Y";

	// 공지여부 <-- 프로그램전까지 "N"을 기본값으로 셋팅한다.
	if($cf_annou_yn == "Y")
	{
		$tm_notice_yn = ($fr_notice_yn == "Y") ? "Y" : "N";

		$tm_notice_start = $fr_notice_start_year .
							$fr_notice_start_mon .
							$fr_notice_start_day .
							$fr_notice_start_hour .
							$fr_notice_start_min .
							$fr_notice_start_sec;
		$tm_notice_end = $fr_notice_end_year .
							$fr_notice_end_mon .
							$fr_notice_end_day .
							$fr_notice_end_hour .
							$fr_notice_end_min .
							$fr_notice_end_sec;
	}
	else
	{
		$tm_notice_yn = "N";
		$tm_notice_start = "";
		$tm_notice_end = "";
	}

	// 작성자관련정보 설정
	$signdate = time();
	$tm_input_id = $cf_cook_id ? $cf_cook_id : "";
	$tm_input_nm = $fr_input_nm;
	$tm_input_ip = $_SERVER[REMOTE_ADDR];


	if($fr_input_Y)
	{
		$fr_input_H = substr($tm_sign_ymdhms,8,2);
		$fr_input_i = substr($tm_sign_ymdhms,10,2);
		$fr_input_s = substr($tm_sign_ymdhms,12,2);
		$tm_input_ymdhms =	sprintf("%04d", $fr_input_Y) .
							sprintf("%02d", $fr_input_m) .
							sprintf("%02d", $fr_input_d) .
							sprintf("%02d", $fr_input_H) .
							sprintf("%02d", $fr_input_i) .
							sprintf("%02d", $fr_input_s);
	}
	else
	{
		$tm_input_ymdhms = date("YmdHis",$signdate);
	}

	$tm_sign_id = $tm_input_id;
	$tm_sign_nm = $tm_input_nm;
	$tm_sign_ip = $tm_input_ip;
	$tm_sign_ymdhms = $signdate;

	# 비밀글 여부
	if($cf_secret_yn == "Y") {
		if(!$fr_secret_yn || $fr_secret_yn == "N") {
			$tm_secret_yn = "N";
		} else {
			$tm_secret_yn = "Y";
		}
		if (!$cf_cook_id) {
			$tm_secret_yn = "N";
		}

	} else {
		$tm_secret_yn = "N";
	}

	// ------------------------------------------------------------- //
	//	입력쿼리
	// ------------------------------------------------------------- //
	$query = "insert into " . $cf_table_col_nm . " (" .
					"NO," .
					"GB," .
					"CD," .
					"L_CATE," .
					"M_CATE," .
					"ITEM," .
					"SUBJECT," .
					"MEMO," .
					"META_TITLE," .
					"META_KEYWD," .
					"META_DESC," .
					"VER_CNT," .
					"COMM_CNT, " .
					"HTML_YN," .
					"PUBLIC_YN, " .
					"SERVICE_YN," .
					"NOTICE_YN," .
					"SECRET_YN," .
					"INPUT_ID," .
					"INPUT_NM," .
					"INPUT_IP," .
					"INPUT_YMDHMS," .
					"SIGN_ID," .
					"SIGN_NM," .
					"SIGN_IP," .
					"SIGN_YMDHMS" .
				")VALUES(".
					"'$my_no'," .
					"'$a_gb'," .
					"'$a_cd'," .
					"'$fr_l_cate'," .
					"'$fr_m_cate'," .
					"'$a_item'," .
					"'$fr_subject'," .
					"'$fr_memo'," .
					"'$fr_meta_title'," .
					"'$fr_meta_keywd'," .
					"'$fr_meta_desc'," .
					"'$tm_ver_cnt'," .
					"'$tm_comm_cnt', " .
					"'$tm_html_yn'," .
					"'$tm_public_yn'," .
					"'$tm_service_yn'," .
					"'$tm_notice_yn'," .
					"'$tm_secret_yn'," .
					"'$tm_input_id'," .
					"'$tm_input_nm'," .
					"'$tm_input_ip'," .
					"'$tm_input_ymdhms'," .
					"'$tm_sign_id'," .
					"'$tm_sign_nm'," .
					"'$tm_sign_ip'," .
					"'$tm_sign_ymdhms'" .
				")";


###################################################################################
//echo $fr_email;
//echo $MY_URI;
/*
  if($MY_URI == "post"){
	include "send_mail_board.inc";
}
###################################################################################*/



	unset($err);
	$err = $DB->Insert_Query($query);

	if($err[log] == "error")
	{
		echo $err[error] . "<br>";
		exit;
	}
	
	include "upload.inc";
	

	# 작성글 보기 폼으로 이동
	switch($MY_URI)
	{
		case "post" :

			error_msg("", "/common/product/list.html?$po_basic_query&page=$page&sm=$sm");

			break;

		case "reply" :

			error_msg("", "/common/product/list.html?$po_adv_query&page=$page&sm=$sm");
			break;
	}
?>