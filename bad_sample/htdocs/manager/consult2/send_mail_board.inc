<?
	$client = getenv('REMOTE_ADDR');
	$browser = getenv('HTTP_USER_AGENT');
	$signdate = date("Y년 m월 d일 H시 i분 s초",$signdate);
	$mail_input_nm = ($MY_URI == "delete") ? $my_sign_nm : $tm_sign_nm;
	$mail_email = ($MY_URI == "delete") ? $my_email : $fr_email;
	$mail_subject = ($MY_URI == "delete") ? $my_subject : stripslashes($fr_subject);
	$mail_memo = ($MY_URI == "delete") ? $my_memo : nl2br(stripslashes($fr_memo));
	$add_header = "From :$cf_title_nm<>\n";
	$add_header .= "Content-Type : text/html;charset=EUC-KR";

//exit;

	//$add_header = "From:$mailfrom\n";			//보내는사람  다음,핫메일발송안될시...
	//$add_header .= "Reply-To:$mailfrom\n";	
	//$add_header .= "Content-Type:text/html;charset=EUC-KR\n\n";


	// ---------------------------------------------------------------------------------- //
	//	제목 생성
	// ---------------------------------------------------------------------------------- //
	switch($MY_URI)
	{
		case "post":
			// 새글 입력시 관리자에게 보내지는 제목
			$subject = "'$mail_input_nm'님께서 $cf_site_nm($cf_title_nm)에 새글을 올리셨습니다.";
			break;

		case "reply":
			// 답변글 입력시 관리자에게 보내지는 제목
			$subject = "'$mail_input_nm'님께서 $cf_site_nm($cf_title_nm)에 답변글을 올리셨습니다.";
			// 고객에게 보내지는 제목 및 추가 내용
			$subject_reply = "'$cf_title_nm'에 답변글이 등록되었습니다.";
			break;

		case "modify":
			// 글 수정시 관리자에게 보내지는 제목
			$subject = "'$mail_input_nm'님께서 $cf_site_nm($cf_title_nm)의 '$mail_subject'글을 수정하셨습니다.";
			break;

		case "delete":
			// 글 삭제시 관리자에게 보내지는 제목
			$subject = "'$cf_site_nm($cf_title_nm)'의 '$mail_subject'글이 삭제되었습니다.";
	}

	// 관리자에게 발송되는 메일내용
	$contents = "
	    글쓴이 : $mail_input_nm<br>
		시각 : $signdate<br>
		제목 : $mail_subject<br>
		내용 : <br>
		$mail_memo
	";


	if($cf_email_id1)
	{
		$ml_mailer_email = $cf_email_id1;
		mail($ml_mailer_email, $subject, $contents, $add_header);
	}

	if($cf_email_id2)
	{
		$ml_mailer_email = $cf_email_id2;
		mail($ml_mailer_email, $subject, $contents, $add_header);
	}

	if($cf_email_id3)
	{
		$ml_mailer_email = $cf_email_id3;
		mail($ml_mailer_email, $subject, $contents, $add_header);
	}

//====================================================================================//
	if($a_gb == "board" && ($a_cd == "16")){
//1

//20
		$ml_mailer_email = "redmoon0320@nate.com";
		mail($ml_mailer_email, $subject, $contents, $add_header);
	}


	if($cf_admin_email)
	{
		$ml_mailer_email = $cf_admin_email;
		mail($ml_mailer_email, $subject, $contents, $add_header);
	}
?>


