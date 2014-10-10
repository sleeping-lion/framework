<?

	header("Content-Type: text/html; charset=utf-8");
	$client = getenv('REMOTE_ADDR');
	$browser = getenv('HTTP_USER_AGENT');
	$signdate = date("Y년 m월 d일 H시 i분 s초",$signdate);
	$mail_input_nm = ($MY_URI == "delete") ? $my_sign_nm : $fr_name;
	$mail_email = ($MY_URI == "delete") ? $my_email : $fr_email;
	//$mail_subject = ($MY_URI == "delete") ? $my_subject : stripslashes($fr_subject);
	$mail_memo = ($MY_URI == "delete") ? $my_memo : nl2br(stripslashes($fr_inquiry));

	$cf_title_nm = '=?utf-8?B?'.base64_encode("한동하이드로").'?=';
	$add_header = "From :$cf_title_nm<>\n";
	$add_header .= "Content-Type : text/html;charset=UTF-8";

//exit;

	//$add_header = "From:$mailfrom\n";			//보내는사람  다음,핫메일발송안될시...
	//$add_header .= "Reply-To:$mailfrom\n";	
	//$add_header .= "Content-Type:text/html;charset=EUC-KR\n\n";


	// ---------------------------------------------------------------------------------- //
	//	제목 생성
	// ---------------------------------------------------------------------------------- //

	if($a_cd=="2"){
		$subject = "[한동하이드로]'$fr_nm'님께서 개설상담 게시판에 문의하신 내용입니다.";
	}else{
		$subject = "[한동하이드로]'$fr_nm'님께서 개설상담 게시판에 문의하신 내용입니다.";
	}

	if($fr_sex=="1"){
		$fr_sex_text = "(남)";
	}else{
		$fr_sex_text = "(여)";
	}
	
	$subject = '=?utf-8?B?'.base64_encode($subject).'?=';

	// 관리자에게 발송되는 메일내용
	$contents = "
		<table width=\"710\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\" bgcolor=\"CCCCCC\">
			<tr height='2'>
			  <td width=\"68\" bgcolor='#8B8B8B'></td>
			  <td width=\"532\" bgcolor='#8B8B8B'></td>
			</tr>
		  </table>
		 <table width=\"710\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\">
			 <tr bgcolor='#F4F4F4' height='27'>
			  <td width=\"100\" align=\"center\">요청시각</td>
			  <td width=\"610\">&nbsp;&nbsp;$signdate</td>
			</tr>
			<tr>
			  <td bgcolor='#E4E4E4' height='1' colspan='11'></td>
			</tr>
			<tr bgcolor='#F4F4F4' height='27'>
			  <td align=\"center\">신청인</td>
			  <td>&nbsp;&nbsp;$fr_nm $fr_sex_text</td>
			</tr>
			<tr>
			  <td bgcolor='#E4E4E4' height='1' colspan='11'></td>
			</tr>
			<tr bgcolor='#F4F4F4' height='27'>
			  <td align=\"center\">주소</td>
			  <td>&nbsp;&nbsp;$fr_address</td>
			</tr>
			<tr>
			  <td bgcolor='#E4E4E4' height='1' colspan='11'></td>
			</tr>
			<tr bgcolor='#F4F4F4' height='27'>
			  <td align=\"center\">연락처</td>
			  <td>&nbsp;&nbsp;$fr_hp_tel / $fr_tel</td>
			</tr>
			<tr>
			  <td bgcolor='#E4E4E4' height='1' colspan='11'></td>
			</tr>
			<tr bgcolor='#F4F4F4' height='27'>
			  <td align=\"center\">현재직업</td>
			  <td>&nbsp;&nbsp;$fr_job</td>
			</tr>
			<tr>
			  <td bgcolor='#E4E4E4' height='1' colspan='11'></td>
			</tr>
			<tr bgcolor='#F4F4F4' height='27'>
			  <td align=\"center\">희망지역</td>
			  <td>&nbsp;&nbsp;$fr_hope</td>
			</tr>
			<tr>
			  <td bgcolor='#E4E4E4' height='1' colspan='11'></td>
			</tr>
			<tr bgcolor='#F4F4F4' height='27'>
			  <td align=\"center\">사업동기</td>
			  <td>&nbsp;&nbsp;$fr_motive</td>
			</tr>
			<tr>
			  <td bgcolor='#E4E4E4' height='1' colspan='11'></td>
			</tr>
			<tr bgcolor='#F4F4F4' height='27'>
			  <td align=\"center\">경력사항</td>
			  <td>&nbsp;&nbsp;$fr_career</td>
			</tr>			
		 </table>
		  <table width=\"710\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\">
			<tr height='1'>
			  <td bgcolor='#DBDBDB'></td>
			</tr>
			<tr height='4'>
			  <td bgcolor='#F5F5F5'></td>
			</tr>
		  </table>

		  <table width=\"560\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\">
			<tr>
			<td bgcolor='#DBDBDB' align=\"center\">사회활동
			</td>
			</tr>
			<tr>
			  <td style=\"line-height=150%\"><BR>

			  $fr_memo1<br><BR><BR></td>
			</tr>
			<tr>
			<td bgcolor='#DBDBDB' align=\"center\">포상
			</td>
			</tr>
			<tr>
			  <td style=\"line-height=150%\"><BR>

			  $fr_memo2<br><BR><BR></td>
			</tr>
		  </table>
		  <table width=\"710\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\">
			<tr height='1'>
			  <td bgcolor='#DBDBDB'></td>
			</tr>
			<tr height='4'>
			  <td bgcolor='#F5F5F5'></td>
			</tr>
		  </table>
	";


	if($a_cd=="2"){
		$cf_email_id1 = "zagec@mir9.co.kr";
	}else{
		$cf_email_id1 = "zagec@mir9.co.kr";
	}

	//$cf_email_id3 = $fr_email;
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
	$contents .= "<br/><h3>개설상담 신청이 완료되었습니다.  <br/>신청내용 확인 후 연락드리겠습니다.</h3>";
	if($cf_email_id3)
	{
		$ml_mailer_email = $cf_email_id3;
		mail($ml_mailer_email, $subject, $contents, $add_header);
	}



//====================================================================================//

?>


