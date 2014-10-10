<?
	// 작성자관련정보 설정
	$signdate = time();
	$tm_input_id = $cf_cook_id ? $cf_cook_id : "";
	$tm_input_nm = $cf_cook_nick_nm ? $cf_cook_nick_nm : $cf_cook_nm;
	$tm_input_ip = $_SERVER[REMOTE_ADDR];
	$tm_input_ymdhms = date("YmdHis", $signdate);
	$tm_sign_id = $tm_input_id;
	$tm_sign_nm = $tm_input_nm;
	$tm_sign_ip = $tm_input_ip;
	$tm_sign_ymdhms = $tm_input_ymdhms;

	# --------------------------------------------------------------- #
	#	상품정보 입력
	# --------------------------------------------------------------- #
	$query = "INSERT INTO $cf_table_cod_nm (" .
					"GB, " .
					"CD, " .
					"NM, " .
					"CON_CD, " .
					"NM_DESC, " .
					"ENM, " .
					"BIGO, " .
					"INPUT_ID, " .
					"INPUT_NM, " .
					"INPUT_IP, " .
					"INPUT_YMDHMS, " .
					"SIGN_ID, " .
					"SIGN_NM, " .
					"SIGN_IP, " .
					"SIGN_YMDHMS" .

				") VALUES (" .

					"'$po_cd', " .
					"'$fr_cd', " .
					"'$fr_nm', " .
					"'$fr_con_cd', " .
					"'$null_nm_desc', " .
					"'$fr_enm', " .
					"'$fr_bigo', " .
					"'$tm_input_id', " .
					"'$tm_input_nm', " .
					"'$tm_input_ip', " .
					"'$tm_input_ymdhms', " .
					"'$tm_sign_id', " .
					"'$tm_sign_nm', " .
					"'$tm_sign_ip', " .
					"'$tm_sign_ymdhms'" .
				");";


	if($DB->Insert_Query($query)){
		error_msg("에러발생", "back");
	}
	

	// 페이지 이동
	error_msg("", "list.html?$po_basic_query");
?>