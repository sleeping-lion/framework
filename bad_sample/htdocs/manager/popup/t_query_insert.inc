<?php
	include "upload.inc";

//echo phpinfo();

	// 조회수 초기화
	$tm_ver_cnt = 0;		// 조회수
	$tm_comm_cnt = 0;		// 코멘트갯수
	$tm_recom_cnt = 0;		// 추천인수



$tm_start_day=$fr_start_year."-".$fr_start_mon."-".$fr_start_day;

$tm_end_day=$fr_end_year."-".$fr_end_mon."-".$fr_end_day;
	// ------------------------------------------------------------- //
	//	입력쿼리
	// ------------------------------------------------------------- //
	$query = "insert into " . $cf_table_col_nm . " (" .
					"NO," .
					"GB," .
					"CD," .
					"ITEM," .
					"DISPLAY, " .
					"START_DAY," .
					"END_DAY, " .
					"WIDTH," .
					"HEIGHT," .
					"P_LEFT," .
					"P_TOP," .
					"LIVE," .
					"TITLE_BAR," .
					"LINK_URL," .
					"POPUP_IMG," .
					"CONTENT" .
					
				")VALUES(".
					"'$my_no'," .
					"'$a_gb'," .
					"'$a_cd'," .
					"'$a_item'," .
					"'$fr_display', " .
					"'$tm_start_day', " .
					"'$tm_end_day'," .
					"'$fr_width'," .
					"'$fr_height'," .
					"'$fr_left'," .
					"'$fr_top'," .
					"'$fr_live'," .
					"'$fr_title_bar'," .
					"'$fr_link_url'," .
					"'$tm_real_path',".
					"'$fr_content'" .
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

	# 작성글 보기 폼으로 이동
	switch($MY_URI)
	{
		case "post" :

			error_msg("", "list.html?$po_basic_query&page=$page");

			break;
		
		case "reply" :

			error_msg("", "list.html?$po_adv_query&page=$page");
			break;
	}
?>