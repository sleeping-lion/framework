<?php
    

	// 첨부화일 업로드 (화일이 여러개일경우 각각의 사이즈를 구하지 못한다.)
	if(is_uploaded_file($_FILES[userfile][tmp_name]))
	{
		$tm_upload_path = $my_no . "_" . $_FILES[userfile][name];
		if(Upload_File($_FILES[userfile], $cf_savedir_physical, $cf_attach_size, $tm_upload_path, 1))
		{
			$tm_attach_size = $_FILES[userfile][size];
			$tm_attach_path = $_FILES[userfile][name];
			$tm_real_path = $tm_upload_path;
		}
	}
	else
	{
		$tm_attach_size = "";
		$tm_attach_path = "";
		$tm_real_path = "";
	}



	// 작성자관련정보 설정
	$signdate = time();
	$tm_input_id = $cf_cook_id ? $cf_cook_id : "";
	$tm_input_nm = $fr_nm;
	$tm_input_ip = $_SERVER[REMOTE_ADDR];
	
	
	
	$tm_input_ymdhms = date("YmdHis",$signdate);
			
	$tm_sign_id = $tm_input_id;
	$tm_sign_nm = $tm_input_nm;
	$tm_sign_ip = $tm_input_ip;
	$tm_sign_ymdhms = $signdate;
    
	if($fr_category){
		$query = "SELECT BIGO FROM CM_CODE_C WHERE CD = '$fr_category'";
		$cate_email = $DB->Value($query);
	}
	
	// ------------------------------------------------------------- //
	//	입력쿼리
	// ------------------------------------------------------------- //
	$query = "insert into " . $cf_table_col_nm . " (" .
					"NO," .
					"GB," .
					"CD," .
					"ITEM," .
					"SEX, " .
					"ADDRESS, " .
					"HP_TEL, " .
					"TEL, " .
					"JOB, " .
					"HOPE, " .
					"MOTIVE, " .
					"CAREER," .
					"MEMO1," .
					"MEMO2," .
					"INPUT_ID," .
					"INPUT_NM," .
					"INPUT_IP," .
					"INPUT_YMDHMS," .
					"SIGN_ID," .
					"SIGN_NM," .
					"SIGN_IP," .
					"SIGN_YMDHMS, " .
					"REPLY" .
				")VALUES(".
					"'$my_no'," .
					"'$a_gb'," .
					"'$a_cd'," .
					"'$a_item'," .
					"'$fr_sex', " .
					"'$fr_address', " .
					"'$fr_hp_tel', " .
					"'$fr_tel', " .
					"'$fr_job', " .
					"'$fr_hope', " .
					"'$fr_motive'," .
					"'$fr_career'," .
					"'$fr_memo1'," .
					"'$fr_memo2'," .
					"'$tm_input_id'," .
					"'$tm_input_nm'," .
					"'$tm_input_ip'," .
					"'$tm_input_ymdhms'," .
					"'$tm_sign_id'," .
					"'$tm_sign_nm'," .
					"'$tm_sign_ip'," .
					"'$tm_sign_ymdhms'," .
					"'N'" .
				")";

	unset($err);

	$err = $DB->Insert_Query($query);
	
	if($err[log] == "error")
	{
		echo $err[error] . "<br />";
		exit;
	}

	include "send_mail_board.inc";

	$tm_msg = "개설상담 신청이 완료되었습니다. 신청내용 확인 후 연락드리겠습니다.";
	switch($MY_URI)
	{
		case "post" :
			error_msg($tm_msg, $cf_http_url."/");
			break;
	}
?>