<?php
// ---------------------------------------------------------------- //
//	웹사이트 제작시 필요한 공통함수를 나열한다.
//		주의사항 : 실제 DB접속하는 함수의 경우 DB접속 구조체와 쿼리확인필수!!
// ---------------------------------------------------------------- //

	// ------------------------------------------------------------ //
	//	분류 : 회원관리
	//
	//	기능 : 실제 존재하는 레벨인지 체크한다.
	//
	//	입력 :	$cm_level			- 현재 사용자 레벨
	//			$global				- DB 접속 구조체
	//
	//	출력 :	Boolean(True/False)
	// ------------------------------------------------------------ //
	function is_level($cm_level)
	{
		global $DB, $cf_table_cod_nm;
		$query = "SELECT COUNT(*) FROM $cf_table_cod_nm WHERE GB = 'level' AND CD = '$cm_level'";
		if($DB->Value($query))
			return true;
		else
			return false;
	}

	// ------------------------------------------------------------ //
	//	분류 : 회원관리
	//
	//	기능 : 실제 존재하는 레벨인지 체크한다.
	//
	//	입력	 :	$cm_level				- 현재 사용자 레벨
	//				$check_level			- 게시판 사용가능레벨
	//				$method				- 레벨체크 방법(V, VH, H)
	//												V : 각레벨 수직관계
	//												VH : 각레벨 수직관계 일부 수평관계
	//												H : 각레벨 수평관계
	//				$global					- DB 접속 구조체
	//
	//	출력	 :	$level_check_yn		- Boolean(True/False)
	// ------------------------------------------------------------ //
	function get_level_check($cm_level, $check_level, $method="V")
	{
/*		if($_SERVER[REMOTE_ADDR]=="210.97.226.101"){
			echo "메쏘드".$method;
			echo "나의레벨".$cm_level;
			echo "설정레벨".$check_level."_";
			echo "수정나의레벨".$kk = substr($cm_level,0,2);
			echo "수정설정레벨".$nn = substr($check_level,0,2);
		}
*/
		if(!is_level($cm_level))
		{
			error_msg("레벨체크 오류입니다.\\n\\n다시 로그인해주세요.", "back");
			exit;
		}

		switch($method)
		{
			case "V" :
				if($cm_level <= $check_level)
					$level_check_yn = "Y";
				else
					$level_check_yn = "N";
				break;

			case "VH" :
//				substr($cm_level,0,1) < substr($cm_level,0,1
				if($cm_level == $check_level || substr($cm_level,0,2) <= substr($check_level,0,2))
					$level_check_yn = "Y";
				else
					$level_check_yn = "N";
				break;

			case "H" :
				if($cm_level == $check_level)
					$level_check_yn = "Y";
				else
					$level_check_yn = "N";
				break;

			default :
				if($cm_level <= $check_level)
					$level_check_yn = "Y";
				else
					$level_check_yn = "N";
		}

		return $level_check_yn;
	}


	function get_php_self_filename()
	{
		$uri = basename($_SERVER[SCRIPT_NAME]);
		$uri = eregi(".", $uri) ? substr($uri, 0, strrpos($uri, ".")) : $uri;
		$uri = eregi("_", $uri) ? substr($uri, 0, strpos($uri, "_")) : $uri;
		return $uri;
	}

	// ------------------------------------------------------------ //
	//	분류 : 화일
	//
	//	기능 : 권한체크를 위한 화일명을 구한다.
	//
	//	출력 : $url_nm					- (post,list,modify,reply)
	// ------------------------------------------------------------ //
	function get_admin_filename()
	{
		$uri = get_php_self_filename();

		if(eregi("listbody", $uri))
			$uri_nm = "listbody";			// 상세읽기
		elseif(eregi("list", $uri))
			$uri_nm = "list";				// 리스트
		else if(eregi("post", $uri))
			$uri_nm = "post";				// 쓰기
		else if(eregi("modify", $uri))
			$uri_nm = "modify";				// 수정
		else if(eregi("reply", $uri))
			$uri_nm = "reply";				// 답변
		else if(eregi("delete", $uri))
			$uri_nm = "delete";				// 삭제

		return $uri_nm;
	}

	function get_button_value($uri)
	{
		$BUTTON_VALUE_POST      = "글 쓰 기";
		$BUTTON_VALUE_MODIFY    = "수정 글쓰기";
		$BUTTON_VALUE_REPLY     = "답변 글쓰기";
		$BUTTON_VALUE_DELETE    = "글 삭 제";
		$BUTTON_VALUE_RESET     = "취  소";

		switch($uri)
		{
			case ("postform") :
				$button_value = $BUTTON_VALUE_POST;
				break;
			case ("postform1") :
				$button_value = $BUTTON_VALUE_POST;
				break;
			case ("modifyform") :
				$button_value = $BUTTON_VALUE_MODIFY;
				break;
			case ("replyform") :
				$button_value = $BUTTON_VALUE_REPLY;
				break;
			case ("deleteform") :
				$button_value = $BUTTON_VALUE_DELETE;
				break;
			case ("reset") :
				$button_value = $BUTTON_VALUE_RESET;
				break;

			default :
		}
		return $button_value;
	}


function resize_image($file, $w, $h, $crop=FALSE) {
    list($width, $height) = getimagesize($file);
    $r = $width / $height;
    if ($crop) {
        if ($width > $height) {
            $width = ceil($width-($width*($r-$w/$h)));
        } else {
            $height = ceil($height-($height*($r-$w/$h)));
        }
        $newwidth = $w;
        $newheight = $h;
    } else {
        if ($w/$h > $r) {
            $newwidth = $h*$r;
            $newheight = $h;
        } else {
            $newheight = $w/$r;
            $newwidth = $w;
        }
    }
    $src = imagecreatefromjpeg($file);
    $dst = imagecreatetruecolor($newwidth, $newheight);
    imagecopyresampled($dst, $src, 0, 0, 0, 0, $newwidth, $newheight, $width, $height);

    return $dst;
}

	function print_title_image($code)
	{
	   $img_title = $code . ".gif";
	   echo("<center><img src=\"$img_title\" border=0></center><p>");
	}

	function print_htmltag_yesno($allow_html)
	{
		if($allow_html=="Y")
			echo("<FONT face=돋움>(태그<font color=#426FA6>가능</font>)</FONT>");
		else
			echo("<FONT face=돋움>(태그<font color=#CC3300>불가</font>)</FONT>");
	}

	function print_htmltag_yesno_en($allow_html)
	{
		if($allow_html=="Y")
			echo("<FONT face=돋움>(Tag <font color=#426FA6>Possible</font>)</FONT>");
		else
			echo("<FONT face=돋움>(Tag <font color=#CC3300>Impossible</font>)</FONT>");
	}

	// --------------------------------------------------------------- //
	//	작성자 : 최현덕 			작성일 : 2002.10.28
	//
	//	기능 : 에러메세지출력 및 자바스크립트의 간단한 제어
	//
	//	입력 :	$msg 			- 에러
	//			$action			- 에러메시지출력 후 이동할 URL 혹은 액션
	//								1. NULL -> 페이지를 이동하지 않는다.
	// 								2. -1, back	-> 이전페이지로 이동한다.
	//								3. close -> 창을 닫는다.
	//								4. 그외 -> 해당 URL로 이동한다.
	//			$target			- 이동할 창이름
	//
	//	출력 :	없음
	//
	//	용법 :	error_msg("메세지");				- 메세지경고창을 띄운다.
	//			error_msg("메세지", "/");		- 메세지경고창을 띄우고 홈페이지루트로
	//			error_msg("", "/");				- 경고창없이 홈페이지루트로
	// --------------------------------------------------------------- //
	function error_msg($msg, $action=NULL, $target="window")
	{
		$tm_action_state = $action;

		// 에러메세지 처리
		$err_msg = $msg ? "\talert(\"" . $msg . "\");\n" : "";

		// 자바스크립트 액션 (뒤로, 닫기, 이동) 처리
		if($action == NULL) $action = "";
		elseif($action == -1 || $action == "back") $action = "\thistory.back();\n";
		elseif($action == "close") $action = "\t" . $target . ".close();\n";
		elseif($action == "reload") $action = "\t" . $target. ".location.reload(true);\n";
		else $action = "\t" . $target . ".location.href='" . $action . "';\n";

		// 출력메세지 처리
		$print_msg = "<script language='javascript'>\n";
		$print_msg .= "<!--\n";
		$print_msg .= $err_msg;
		$print_msg .= $action;
		$print_msg .= "\t//-->\n";
		$print_msg .= "</script>\n";

		// 출력
		echo $print_msg;

		// back 입력시 프로그램 종료
		if($tm_action_state == "back")
			exit;
	}

	// --------------------------------------------------------------- //
	//  소켓을 이용한 메일전송
	//
	//	입력 :	$fromname		- 보내는사람 이름
	//			$from			- 보내는사람 메일주소
	//			$to				- 받는사람 메일주소
	//			$subject		- 제목
	//			$body			- 내용
	//			$file			- 파일(다중 배열)
	//				예) $file[0][name] - 이름, $file[0][tmp_name] - 업로드된경로, $file[0][size] - 화일크기
	//			$tag			- html 여부 (HTML or TEXT)
	//			$server			- 메일서버
	//
	//  출력 :
	// --------------------------------------------------------------- //
	function Sock_Sendmail($fromname, $from, $to, $subject, $body, $file="", $tag="TEXT", $server="")
	{
		# ---- 변수 초기화 ---- #
		$from = trim($from);
		$to = trim($to);
		$mail_result = 0;
		$encoding = "base64";
		$charset = "euc_kr";

		# ---- 필수입력사항 체크 ---- #
		if(!$to || !$subject)
		{
			error_msg("받는사람 메일주소와 제목은 필수사항입니다.\\n\\n입력사항 체크 후 다시 시도하세요.", "back");
			exit;
		}

		# ---- 제목 문자열처리 ---- #
		$subject = trim(strip_tags($subject));

		# ---- 보내는사람이름 ---- #\
		$fromname = "=?" . $charset . "?B?" . base64_encode($fromname) . "?=";

		# ---- 제목과 본문에 대한 문자열 처리 시작 ---- #
		// 태그허용여부
		if($tag == "HTML")
		{
            $mailHead  = "<html>\n";
            $mailHead .= "<head>\n";
            $mailHead .= "<title></title>\n";
            $mailHead .= "<meta http-equiv='Content-Type' content='text/html; charset=euc-kr'>\n";
            $mailHead .= "<meta name='GENERATOR' content='Mir9 Mailer'>\n";
            $mailHead .= "</head>\n";
            $mailHead .= "<body bgcolor='#FFFFFF' text='#000000'>\n";

            $mailTail = "</body>\n";
            $mailTail .= "</html>\n";

			$body = $mailHead . $body . $mailTail;
		}
		# ---- 제목과 본문에 대한 문자열 처리 끝 ---- #

		# ---- 서버설정부분 ---- #
		$server = $server ? $server : "localhost";

		# ------------------------------------------------------------------------- #
		#	25번 포트로 접속해서 메일 보내는 부분 시작
		# ------------------------------------------------------------------------- #
		# ---- 25번 포트로 접속 ---- #
		$fp = fsockopen($server, 25, $errno, $errstr, 30);
		if(!$fp)
		{
			error_msg("메일서버 연결에러입니다. 관리자에게 문의하세요.\\n\\n에러번호 : $errno\\n\\n에러내용 : $errstr", "back");
			exit;
		}

		$domain = substr($from, strrpos($from, "@")+1);

		// 공통 메일헤더 작성
		global $HTTP_SERVER_VARS;
		$REMOTE_ADDR = $HTTP_SERVER_VARS['REMOTE_ADDR'];
		$SERVER_NAME = $HTTP_SERVER_VARS['SERVER_NAME'];
		$REMOTE_PORT = $HTTP_SERVER_VARS['REMOTE_PORT'];

		if($HTTP_SERVER_VARS['REMOTE_HOST']) $REMOTE_HOST = $HTTP_SERVER_VARS['REMOTE_HOST'];
		if($HTTP_SERVER_VARS['HTTP_VIA']) $HTTP_VIA = $HTTP_SERVER_VARS['HTTP_VIA'];
		if($HTTP_SERVER_VARS['HTTP_X_FORWARDED_FOR']) $HTTP_X_FORWARDED_FOR = $HTTP_SERVER_VARS['HTTP_X_FORWARDED_FOR'];

		if (isset($REMOTE_HOST)) $received_from = "$REMOTE_HOST ([$REMOTE_ADDR])";
		else $received_from = $REMOTE_ADDR;
		if(isset($HTTP_VIA) || isset ($HTTP_X_FORWARDED_FOR))
		{
			if($HTTP_X_FORWARDED_FOR == '') $HTTP_X_FORWARDED_FOR = 'unknown';
			$received_from .= " (proxying for $HTTP_X_FORWARDED_FOR)";
		}

		$subject = "=?" . $charset . "?B?" . base64_encode($subject) . "?=";
		$date = date("D, j M Y H:i:s ", mktime()) . timezone();
		$message_id = '<'.$REMOTE_PORT.'.'.$REMOTE_ADDR.'.'.time().'.Mir9@'.$SERVER_NAME .'>';
		$boundary = '----=_'.date( 'YmdHis' ).'_'.mt_rand(10000, 99999);

		# ---- HELO ---- #
		fputs($fp, "HELO " . $domain . "\r\n");
		$Msg = SMTPerrorCheck(fgets($fp, 1024));
		if($Msg != 5)
		{
			error_msg($Msg, "back");
			exit;
		}

		# ---- 사용자수만큼 반복한다. ---- #
		$tos = explode(",", $to);
		for($i=0; $i<sizeof($tos); $i++)
		{
			# ---- MAIL FROM ---- #
			fputs($fp, "MAIL FROM: <" . $from . ">\r\n");
			$Msg = SMTPerrorCheck(fgets($fp, 1024));
			if($Msg != 5)
			{
				error_msg($Msg, "back");
				exit;
			}

			# ---- RCPT TO ---- #
			// 헤더에 추가할 이메일 리스트
			$to_lists = "";
			$to_lists = "<" . $tos[$i] . ">,\r\n\t";

			// RCPT TO
			fputs($fp, "RCPT TO: <" . $tos[$i] . ">\r\n");
			$Msg = SMTPerrorCheck(fgets($fp, 1024));
			if($Msg != 5)
			{
				error_msg($Msg, "back");
				exit;
			}

			$to_lists = substr($to_lists, 0, -4);

			# ---- Data ---- #
			fputs($fp, "DATA\r\n");
			$Msg = SMTPerrorCheck(fgets($fp, 1024));
			if($Msg != 5)
			{
				error_msg($Msg, "back");
				exit;
			}

			// 첨부화일
			if(is_array($file))
				$type = 1;

			// 메일헤더 작성 마무리
			$header  = "Received: from $received_from\r\n";
			$header .= "    (Mir9 authenticated user $from)\r\n";
			$header .= "    by $_SERVER[SERVER_NAME] with HTTP;\r\n";
			$header .= "    $date\r\n";
			$header .= "Message-ID: $message_id\r\n";
			$header .= "From: \"$fromname\" <$from>\r\n";
			$header .= "To: $to_lists\r\n";
			if($cc) $header .= "Cc: $cc\r\n";
			$header .= "Subject: $subject\r\n";
			$header .= "Date: $date\r\n";
			$header .= "X-Mailer: Mir9 Mailer Ver 0.1.19)\r\n";
			if(!$Priority) $Priority = 3;
			$header .= "X-Priority: ".$Priority."\r\n";
			$header .= "MIME-Version: 1.0\r\n";

			if($type == 1)
			{
				$header .= 'Content-Type: multipart/mixed; boundary="';
				$header .= $boundary;
				$header .= "\"\r\n";
			}
			else
			{
				$header .= "Content-Type: text/".strtolower($tag)."; charset=\"".$charset."\"\r\n";
				$header .= "Content-Transfer-Encoding: ".$encoding."\r\n";
			}
			$header .= "\r\n";
			fputs($fp, $header);
			// 메일헤더 작성 끝

			// 본문 작성 시작
			if($type == 1)  // multipart
			{
				$max_size = getMaxUploadSize();

				fputs($fp, "--" . $boundary . "\r\n");
				fputs($fp, "Content-Type: text/".strtolower($tag)."; charset=\"".$charset."\"\r\n");
				fputs($fp, "Content-Transfer-Encoding: ".$encoding."\r\n\r\n");

				// Body 쓰기
				if($encoding == "base64")
					fputs($fp, chunk_split(base64_encode($body))."\r\n\r\n");
				else
					fputs($fp, $body."\r\n\r\n");

				// 첨부화일
				for($i=0; $i<sizeof($file); $i++)
				{
					if($file[$i][size] > $max_size) continue;

					$fna = basename($file[$i][name]);
					$ContentType = getFileContentType($fna);
					if(eregi("^application", $ContentType)) $disposition = "attachment;";
					else $disposition = "inline;";

					@fputs($fp, "--" . $boundary . "\r\n");
					@fputs($fp, "Content-Type: ".$ContentType."; name=\"".$fna."\"\r\n");
					@fputs($fp, "Content-Disposition: ".$disposition." filename=\"".$fna."\"\r\n");
					@fputs($fp, "Content-Transfer-Encoding: base64\r\n\r\n");

					$filep = @fopen($file[$i][tmp_name], "r");
					while($tmp = @fread($filep, 570))
					@fputs($fp, chunk_split(base64_encode($tmp)));
					@fclose($filep);
				}

				@fputs($fp, "\r\n--" . $boundary . "--\r\n\r\n");
			}
			else
			{
				// Body 쓰기
				if($encoding == "base64")
					fputs($fp, chunk_split(base64_encode($body))."\r\n\r\n");
				else
					fputs($fp, $body."\r\n\r\n");
			}
			// 본문 작성 끝

			fputs($fp, ".\r\n");
			$Msg = SMTPerrorCheck(fgets($fp, 1024));
			if($Msg != 5)
			{
				error_msg($Msg, "back");
				exit;
			}
		}

        fputs($fp, "QUIT\r\n");
        fclose($fp);
		return true;
		# ------------------------------------------------------------------------- #
		#	25번 포트로 접속해서 메일 보내는 부분 끝
		# ------------------------------------------------------------------------- #
	}

	// SMTP 에러 체크
	function SMTPerrorCheck($line)
	{
		$err_num = substr($line, 0, strpos($line, " "));
		$OK = array(211, 214, 220, 221, 235, 250, 251, 334, 354);
		if(in_array($err_num, $OK))
			return 5;
		return trim($line);
	}

	// Time Zone 구하기
	function timezone()
	{
		$diff_second = date('Z');
		if($diff_second > 0) $sign = '+';
		else $sign = '-';

		$diff_second = abs($diff_second);
		$diff_hour = floor($diff_second / 3600);
		$diff_minute = floor(($diff_second-3600*$diff_hour) / 60);

		$zonename = '('.strftime('%Z').')';
		$result = sprintf ("%s%02d%02d %s", $sign, $diff_hour, $diff_minute, $zonename);
		return $result;
	}

	// upload_max_filesize 구하기
	function getMaxUploadSize()
	{
		$size = get_cfg_var("upload_max_filesize");
		if($size == "") return 0;

		$scan['MB'] = 1048576;
		$scan['M'] = 1048576;
		$scan['KB'] = 1024;
		$scan['K'] = 1024;

		while(list($key) = each($scan))
		{
			if((strlen($size) > strlen($key)) && (substr($size, strlen($size) - strlen($key)) == $key))
			{
				$size = substr($size, 0, strlen($size) - strlen($key)) * $scan[$key];
				break;
			}
		}
		return $size;
	}

    // 파일 이름에서 확장자 가져오기
    function getFileExt($file_name)
    {
        return strtolower(trim(str_replace(".", "", strrchr($file_name, "."))));
    }

    // 파일 확장자에 따른 ContentType 가져오기
    function getFileContentType($file_name)
    {
        $ext = getFileExt($file_name);

        switch($ext)
        {
            case "gif" : return "image/gif";
            case "jpg" : return "image/jpeg";
            case "jpeg" : return "image/jpeg";
            case "bmp" : return "image/bmp";
            case "png" : return "image/png";
            case "txt" : return "text/plain";
            case "text" : return "text/plain";
            case "php" : return "text/plain";
            case "php3" : return "text/plain";
            case "phps" : return "text/plain";
            case "asp" : return "text/plain";
            case "htm" : return "text/html";
            case "html" : return "text/html";
            case "shtml" : return "text/html";
            case "zip" : return "application/x-zip-compressed";
            default : return "application/octet-stream";
        }
    }

	//--------------------------------------------------------------//
	// 	메일 함수(프로시져)		:	sendmail()
	//
	//		개요	:	기존의 메일함수에
	//					사용상의 편리함을 추가하였다.
	//		1. to	-->	보내는 사람 ( reply-to 와 동일)
	//		2. from	-->	받는사람
	//		3. subject -->	제목
	//		4. memo		-->		템플릿을 포함한 본문내용.
	//
	//		5. type			// ( 파일 타입 "text/text" 와 "text/html" )
	//		6. attach_file  // ( 이미지 관련 mime타입은 지원하지 않는며
	//							 사용시 배열을 쓸것 (풀패스 사용))
	//
	//
	//		# -- 주의사항
	//				메일을 보내는 시간은 시스템이나 메일 어드레스에
	//				따라 상황이 틀려질수 있으므로 commit 나 rollback
	//				후에 위치시킬것.
	//		# -- 바운더리 작성시 mime type을 적용하기를 원한다면
	//			 mime type 정의 모듈이 필요하다.
	//
	//		2001-08-28 수정 :			수정자 :	이병각
	//				인터페이스중 파일 패스와 파일에 모호함을 해결
	//				하기 위하여 하나로 통합
	//
	//--------------------------------------------------------------//
	function Sendmail($to,$from,$subject,$memo,$type,$attach_file)
	{
		if( (!$to) || (!$subject) || (!$memo) ){
			echo("<br>\n\t\tsendmail() ERROR 인수가 부족합니다\n");
			exit;
		}

		if(!$attach_file){	//##---- 첨부파일이 없는경우

			mail($to,$subject,$memo,"FROM:$from\nReply-To:$from\nContent-Type: $type;charset=EUC-KR\n");

		}else{				//##---- 첨부파일이 있는경우

			for($i=0;$i<sizeof($attach_file);$i++){
				if($attach_file[$i]){
					if(file_exists($attach_file[$i])){
						$result[$i] = fopen("$attach_file[$i]","r");
						$file_size[$i] = filesize("$attach_file[$i]");
						$file[$i] = fread($result[$i],$file_size[$i]);
						fclose($result[$i]);
					}else{
						//-- 적당한 에러를 뿌려야 되는데.....
					}
				}
			}

			$j=sizeof($result); //---- 성공적으로 열린 파일에 갯수를 센다.

			//----멀티 바운더리 시작

			$send_boundary = (string)date("U") . md5("$HOST"); //---- 바운더리 헤더를 만든다.

			$mailheaders ="FROM:$from\"\nReply-To:\"$from\"\n " ;//---- from 과 reply를 메일헤더에 끼워넣는다.
			$mailheaders .= ("\nMIME-Version: 1.0 \n");
			$mailheaders .= ("Content-Type: multipart/mixed; boundary=\"--=_NextPar") . $send_boundary .("\"");

			$bodytext .= ("This is a multi-part message in MIME format.\n");
			$bodytext .= ("----=_NextPar") .$send_boundary . ("\n");
			$bodytext .= ("Content-Type: $type; charset=euc_kr\nContent-Transfer-Encoding: 7bit\n\n");
			$bodytext .= ("$memo \n\n");

			if($j>0){
				$real=1;
				for($i=0;$i<sizeof($attach_file);$i++){

					if($attach_file[$i]){ //---- 이 부분부터 멀티바운더리시작
						$filedata[$i] = chunk_split(base64_encode( $file[$i] ), 73, "\n");

						$bodytext .= ("----=_NextPar") . $send_boundary . ("\n");
						$bodytext .= ("Content-type:application/octet-stream; name=\"$attach_file[$i]\"\n");
						$bodytext .= ("Content-Transfer-Encoding: base64\n");
						$bodytext .= ("Content-Disposition: attachment; filename=\"$attach_file[$i]\"\n");
						$bodytext .= ("\n");
						$bodytext .= ("$filedata[$i]");
						$bodytext .= ("\n");

						if($real==$j){
							$bodytext .= ("----=_NextPar") . $send_boundary . ("--\n\n");
						}else{
							$bodytext .= ("----=_NextPar") . $send_boundary . ("\n");
						}
						$real++;

					}//---- 멀티바운더리끝.
				}
			}

			mail($to,$subject,$bodytext,$mailheaders); // 메일을 보낸다.

		}
	}

	//--------------------------------------------------------------//
	// 	파일 생성프로시저		:	Upload_mkdir()
	//
	//		개요	:	기존에 업로드 부분을 함수화 했다.
	//
	//		1. name	-->	생성디렉토리 이름
	//		2. path	-->	생성될 디렉토리 명
	//--------------------------------------------------------------//
	function Upload_Mkdir($dir)
	{
		if(!(file_exists($dir)) || !(is_dir($dir))){
			if(!mkdir($dir,0777))
				error_msg("필요한 디렉토리를 생성하는데 실패하였습니다.", "back");
		}
	}

	// ---------------------------------------------------------------- //
	//	디렉토리를 삭제하는 함수
	//		** 디렉토리가 없거나 디렉토리가 아닌경우도 삭제성공으로 간주한다.
	//		** 파일이 들어있는경우 모든 화일을 삭제한 후 디렉토리를 삭제한다.
	//		** 디렉토리내에 다른 디렉토리가 있는경우 삭제불능 (에러의원인)
	//
	//	입력 :	$savedir_physical	-- 삭제하고자 하는 디렉토리의 절대경로
	//
	//	출력 :	$result				-- 성공하면 True, 실패하면 False를 리턴
	// ---------------------------------------------------------------- //
	function Upload_Rmdir($savedir_physical)
	{
		$result = true;
		if(file_exists($savedir_physical) && is_dir($savedir_physical))
		{
			$dir = dir($savedir_physical);
			while($entry = $dir->read())
			{
				if(is_file($savedir_physical . "/" . $entry) && !unlink($savedir_physical . "/" . $entry))
					$result = false;
			}
			$dir->close();
			if(!rmdir($savedir_physical))
				$result = false;
		}
		return $result;
	}

	//--------------------------------------------------------------//
	//	파일 업로드 함수		:	Upload_File()
	//		주의 :	$t_filename 은 화일이 한개인경우만 사용할것
	//				$files 가 여러개 화일일 경우 전부 다 업로드 됨
	//
	//		입력	:	1. files		-->	화일 스트림 구조체 ex)userfile
	//					2. path			--> 화일을 복사할 디렉토리
	//					3. quart		-->	화일 제한 사이즈 (단위는 Kbye)
	//					4. t_filename	--> 복사할이름
	//					5. overwrite	--> 중복화일 업로드여부
	//
	//		반환값	:	up_cnt			--> 업로드 성공한 화일갯수
	//
	//--------------------------------------------------------------//
	function Upload_File($files,$path,$quart,$t_filename=FALSE,$overwrite=FALSE)
	{
		if(!is_array($files))
		{
			error_msg("화일을 업로드 할 수 없습니다.", "back");
			exit;
		}

		// 업로드 될 예정인 화일갯수(화일이 선택되지 않은경우도 갯수에 포함)
		$total_file = sizeof($files[tmp_name]);

		// 배열인경우 인덱스 값을 구한다.
		unset($index);
		if(is_array($files[tmp_name]))
		{
			$i = 0;
			foreach($files[tmp_name] as $key => $value)
			{
				$index[$i++] = $key;
			}
		}

		// 업로드되는 화일 갯수
		$up_cnt = 0;
		for($i=0; $i<$total_file; $i++)
		{
			// 정보를 담기 위한 변수 초기화
			unset($file);

			if($total_file > 1)
			{
				if(is_uploaded_file($files[tmp_name][$index[$i]]))
				{
					$file[name] = $files[name][$index[$i]];
					$file[size] = $files[size][$index[$i]];
					$file[tmp_name] = $files[tmp_name][$index[$i]];
				}
				else
					continue;
			}
			else
			{
				if(is_uploaded_file($files[tmp_name]))
				{
					$file[name] = $files[name];
					$file[size] = $files[size];
					$file[tmp_name] = $files[tmp_name];
				}
				else
					continue;
			}

			// ------------------------------------------------- //
			// 파일 업로드 처리 시작
			// ------------------------------------------------- //
			$size = $file[size] / 1000;

			// 화일 쿼터 처리
			if($size >= ($quart) && ($quart))
			{
				error_msg("업로드 가능한 파일 크기는 $quart K-byte이하 입니다.\\n 자세한 사항은 관리자에게 문의하세요!", "back");
				exit;
			}
			else if(!$quart)
			{
				error_msg("이 게시판은 파일 업로드를 지원하지 않습니다.\\n 자세한 사항은 관리자에게 문의하세요!", "back");
				exit;
			}

			// 업로드 금지 확장자 처리
			$extention = strrchr($file[name], ".");
			$ban_ext = array(".php", ".php3", ".php4", ".html", ".inc", ".cgi", ".exe");
			if(in_array($extention, $ban_ext))
			{
				error_msg("이 파일은 업로드할수 없습니다.\\n 자세한 사항은 관리자에게 문의하세요!", "back");
				exit;
			}

			// 디렉토리가 없는경우 생성한다.
			if(!is_dir($path))
			{
				if(!mkdir($path,0755))
				{
					error_msg("화일을 적제할 정상적인 디렉토리를 생성할수 없습니다.", "back");
					exit;
				}
			}

			// 저장할 화일이 있는경우
			$filename = $t_filename ? $t_filename : $file[name];

			// 동일한 화일이름 처리
			if(file_exists("$path/$filename") && is_file("$path/$filename"))
			{
				if($overwrite)
				{
					if(!unlink("$path/$filename"))
					{
						error_msg("중복화일을 삭제할 수 없습니다.", "back");
						exit;
					}
				}
				else
				{
					error_msg("동일한 이름의 화일이 이미 존재합니다.", "back");
					exit;
				}
			}

			if(!@move_uploaded_file($file[tmp_name], $path."/".$filename))
			{
				error_msg("화일을 지정한 디렉토리에 복사하는데 실패 했습니다.", "back");
				exit;
			}
			$up_cnt++;
		}
		return $up_cnt;
	}

	//--------------------------------------------------------------//
	//	파일 업로드 함수		:	Upload_Files()
	//		기능	: 기존 Uplaod_File 에서 복수개 화일을 업로드하는 경우 개별처리를 함
	//
	//		입력	:	1. files		-->	화일 스트림 구조체 ex)userfile
	//					2. 화일번호		--> 업로드할 화일번호 (여러개 화일일경우 $_FILES[userfile][tmp_name][xx]의 xx 부분지정)
	//					3. path			--> 화일을 복사할 디렉토리
	//					4. quart		-->	화일 제한 사이즈 (단위는 Kbye)
	//					5. t_filename	--> 복사할이름
	//					6. overwrite	--> 중복화일 업로드여부
	//
	//		반환값	:	up_cnt			--> 업로드 성공여부
	//
	//--------------------------------------------------------------//
	function Upload_Files($files,$num,$path,$quart,$t_filename=FALSE,$overwrite=FALSE)
	{
		if(!is_array($files))
		{
			error_msg("화일을 업로드 할 수 없습니다.", "back");
			exit;
		}

		// 업로드되는 화일 갯수
		$up_cnt = 0;

		// 화일관련 초기화
		$file[name] = $files[name][$num];
		$file[size] = $files[size][$num];
		$file[tmp_name] = $files[tmp_name][$num];

		// ------------------------------------------------- //
		// 파일 업로드 처리 시작
		// ------------------------------------------------- //
		$size = $file[size] / 1000;

		// 화일 쿼터 처리
		if($size >= ($quart) && ($quart))
		{
			error_msg("업로드 가능한 파일 크기는 $quart K-byte이하 입니다.\\n 자세한 사항은 관리자에게 문의하세요!", "back");
			exit;
		}
		else if(!$quart)
		{
			error_msg("이 게시판은 파일 업로드를 지원하지 않습니다.\\n 자세한 사항은 관리자에게 문의하세요!", "back");
			exit;
		}

		// 업로드 금지 확장자 처리
		$extention = strrchr($file[name], ".");
		$ban_ext = array(".php", ".php3", ".php4", ".html", ".inc", ".cgi", ".exe");
		if(in_array($extention, $ban_ext))
		{
			error_msg("이 파일은 업로드할수 없습니다.\\n 자세한 사항은 관리자에게 문의하세요!", "back");
			exit;
		}

		// 디렉토리가 없는경우 생성한다.
		if(!is_dir($path))
		{
			if(!mkdir($path,0755))
			{
				error_msg("화일을 적제할 정상적인 디렉토리를 생성할수 없습니다.", "back");
				exit;
			}
		}

		// 저장할 화일이 있는경우
		$filename = $t_filename ? $t_filename : $file[name];

		// 동일한 화일이름 처리
		if(file_exists("$path/$filename") && is_file("$path/$filename"))
		{
			if($overwrite)
			{
				if(!unlink("$path/$filename"))
				{
					error_msg("중복화일을 삭제할 수 없습니다.", "back");
					exit;
				}
			}
			else
			{
				error_msg("동일한 이름의 화일이 이미 존재합니다.", "back");
				exit;
			}
		}

		if(!@move_uploaded_file($file[tmp_name], $path."/".$filename))
		{
			error_msg("화일을 지정한 디렉토리에 복사하는데 실패 했습니다.", "back");
			exit;
		}

		$up_cnt++;

		return $up_cnt;
	}

	//--------------------------------------------------------------//
	// 	파일 함수		:	Delete_File()
	//
	//		개요	:	파일을 삭제한다.
	//		정상 수행하면 true(1)을 반환한다.
	//--------------------------------------------------------------//
	function Delete_File($file)
	{
		if(file_exists($file) && unlink($file))
			return true;
		else
			return false;
	}

	function Delete_File2($po_no,$order_no,$path)
	{
		global $DB;
		$query = "SELECT REAL_PATH  FROM CM_FILE_T  WHERE FILE_TYPE='normal' AND ORDER_NO = '$order_no' AND P_NO='".$po_no."'";
		$arr = $DB->Pipe_Row($query);
		if($arr[0]!=""){
		$tm_del_file =  $_SERVER["DOCUMENT_ROOT"]."/".$path."/".$arr[0];
		
		$del_query = "DELETE  FROM CM_FILE_T  WHERE FILE_TYPE='normal' AND ORDER_NO = '$order_no' AND P_NO='".$po_no."'";
		$DB->Delete_Query($del_query);
		if(file_exists($tm_del_file) && unlink($tm_del_file))
			return true;
		else
			return false;
		}
		else{
			return true;
		}
	}

	function Delete_File3($po_no,$file_type,$path)
	{
		global $DB;
		$query = "SELECT REAL_PATH  FROM CM_FILE_T  WHERE FILE_TYPE = '$file_type' AND P_NO='".$po_no."'";
		$arr = $DB->Pipe_Row($query);
		if($arr[0]!=""){
		$tm_del_file =  $_SERVER["DOCUMENT_ROOT"]."/".$path."/".$arr[0];
		
		$del_query = "DELETE  FROM CM_FILE_T  WHERE FILE_TYPE = '$file_type' AND P_NO='".$po_no."'";
		$DB->Delete_Query($del_query);
		if(file_exists($tm_del_file) && unlink($tm_del_file))
			return true;
		else
			return false;
		}
		else{
			return true;
		}
	}

	//--------------------------------------------------------------//
	// 	가-하,A-Z 정렬함수		:	SELECT_CLAUSE()
	//
	//		개요	:	DB정렬시 가나다 또는 ABCD순으로 정렬할때 쓰인다.
	//					선택된 캐릭터를 연관배열로 반환한다.
	//					*-- 영문 사용시 대소문자 구분 없음.
	//
	//		코드값	:	가=0				a=0 			A=0
	//					나=1				b=1 			B=1
	//					다=2				c=2 			C=2
	//					라=3				d=3 			D=3
	//					마=4				e=4 			E=4
	//					바=5				f=5 			F=5
	//					사=6				g=6 			G=6
	//					아=7				h=7 			H=7
	//					자=8				i=8 			I=8
	//					차=9				j=9 			J=9
	//					카=10				k=10			K=10
	//					타=11				l=11			L=11
	//					파=12				m=12			M=12
	//					하=13				n=13			N=13
	//					기타=14				o=14			O=14
	//										p=15			P=15
	//										q=16			Q=16
	//										r=17			R=17
	//										s=18			S=18
	//										t=19			T=19
	//										u=20			U=20
	//										v=21			V=21
	//										w=22			W=22
	//										x=23			X=23
	//										y=24			Y=24
	//										z=25			Z=25		기타=26
	//		입력값	:	type	=	K (한글)
	//								E (영문)
	//					code	=	위 코드값
	//
	//		반환값	:	(연관배열로 반환한다.)
	//				(한글)
	//					clause[S]	=	start (>)
	//					clause[E]	=	end	  (<)
	//				(영문)
	//					clause[S]	=	like 소문자
	//					clause[E]	=	like 대문자
	//					기타에 경우 where 절이 틀리다.( 영문 기타 예외처리 꼭!!)
	//		*------------------------ 주의 ----------------------*
	//
	//		**** 한글 사용시 비교연사
	//		**** 영문 사용시 LIKE 절
	//
	//--------------------------------------------------------------//
	function SELECT_CLAUSE($type,$code)
	{
		if($type=="K")
		{
			switch($code)
			{
				case 0:
					$clause1="가";
					$clause2="나";
					break;
				case 1:
					$clause1="나";
					$clause2="다";
					break;
				case 2:
					$clause1="다";
					$clause2="라";
					break;
				case 3:
					$clause1="라";
					$clause2="마";
					break;
				case 4:
					$clause1="마";
					$clause2="바";
					break;
				case 5:
					$clause1="바";
					$clause2="사";
					break;
				case 6:
					$clause1="사";
					$clause2="아";
					break;
				case 7:
					$clause1="아";
					$clause2="자";
					break;
				case 8:
					$clause1="자";
					$clause2="차";
					break;
				case 9:
					$clause1="차";
					$clause2="카";
					break;
				case 10:
					$clause1="카";
					$clause2="타";
					break;
				case 11:
					$clause1="타";
					$clause2="파";
					break;
				case 12:
					$clause1="파";
					$clause2="하";
					break;
				case 13:
					$clause1="하";
					$clause2="히";
					break;
				case 14:
					$clause1="A";
					$clause2="가";
					break;
			}
		}
		else if($type=="E")
		{
			switch($code)
			{
				case 0:
					$clause1="A";
					$clause2="a";
					break;
				case 1:
					$clause1="B";
					$clause2="b";
					break;
				case 2:
					$clause1="C";
					$clause2="c";
					break;
				case 3:
					$clause1="D";
					$clause2="d";
					break;
				case 4:
					$clause1="E";
					$clause2="e";
					break;
				case 5:
					$clause1="F";
					$clause2="f";
					break;
				case 6:
					$clause1="G";
					$clause2="g";
					break;
				case 7:
					$clause1="H";
					$clause2="h";
					break;
				case 8:
					$clause1="I";
					$clause2="i";
					break;
				case 9:
					$clause1="J";
					$clause2="j";
					break;
				case 10:
					$clause1="K";
					$clause2="k";
					break;
				case 11:
					$clause1="L";
					$clause2="l";
					break;
				case 12:
					$clause1="M";
					$clause2="m";
					break;
				case 13:
					$clause1="N";
					$clause2="n";
					break;
				case 14:
					$clause1="O";
					$clause2="o";
					break;
				case 15:
					$clause1="P";
					$clause2="p";
					break;
				case 16:
					$clause1="Q";
					$clause2="q";
					break;
				case 17:
					$clause1="R";
					$clause2="r";
					break;
				case 18:
					$clause1="S";
					$clause2="s";
					break;
				case 19:
					$clause1="T";
					$clause2="t";
					break;
				case 20:
					$clause1="U";
					$clause2="u";
					break;
				case 21:
					$clause1="V";
					$clause2="v";
					break;
				case 22:
					$clause1="W";
					$clause2="w";
					break;
				case 23:
					$clause1="X";
					$clause2="x";
					break;
				case 24:
					$clause1="Y";
					$clause2="y";
					break;
				case 25:
					$clause1="Z";
					$clause2="z";
					break;
				case 26:
					$clause1=null;
					$clause2=null;
					break;
			}
		}
		$clause=array('S' =>$clause1,'E' =>$clause2);
		return $clause;
	}

	//-------------------------------------------------------------//
	//	입력된 스트링에서 캐리지리턴(개행문자)을 제거한다.
	//
	//	작성자 : 박종필			수정자 : 이병각
	//
	//							#- 박종필씨 감사합니다.
	//							   덕분에 잘 쓰고 있습니다.
	//-------------------------------------------------------------//
	function nl2null($value)
	{
		$value = ereg_replace("[[:space:]]+", " ", $value);
		$value = ereg_replace("\'","",$value);
		$value = ereg_replace("\"","",$value);

		return $value;
	}

	//--------------------------------------------------------------//
	//	입력된 주민등록번호의 정상유무 확인
	//
	//	입력 :	1.	ssn1	:	주민번호 앞자리
	//			2.	ssn2	:	주민번호 뒷자리
	//	출력  -	합격			:	'Y'
	//			불합격		:	'N'
	//--------------------------------------------------------------//
	function check_jumin($ssn1,$ssn2)
	{
		$num = "234567892345";
		$ssn = $ssn1 . $ssn2;
		$sum = 0;

		for($i=0; $i<12; $i++)
			$sum += substr($ssn,$i,1) * $num[$i];

		$sum = (11 - ($sum % 11)) % 10;

		if($sum == $ssn[12])
			return true;
		else
			return false;
	}

	// --------------------------------------------------------------- //
	//	입력 전화번호의 지역번호를 판단한다.
	//		* 일반전화번호의 지역번호와 핸드폰번호의 지역번호만을 판단하기 때문에
	//		  기타 전화번호는 에러처리 된다.
	//
	//	입력 : $tel_number				: 전화번호
	//
	//	반환값 :		false	: 잘못된 전화번호
	//				1		: 일반 전화번호
	//				2		: 핸드폰 전화번호
	// --------------------------------------------------------------- //
	function check_tel($tel_number)
	{
		// "-" 및 " " 제거
		$tel_number = ereg_replace("-", "", $tel_number);
		$tel_number = ereg_replace(" ", "", $tel_number);
		$tel_length = strlen($tel_number);
		$local_number = substr($tel_number, 0, 3);

		if(	substr($local_number, 0, 2) == "02" ||  // 서울
				$local_number == "032" ||               // 인천
				$local_number == "042" ||               // 대전
				$local_number == "051" ||               // 부산
				$local_number == "052" ||               // 울산
				$local_number == "053" ||               // 대구
				$local_number == "062" ||               // 광주
				$local_number == "031" ||               // 경기
				$local_number == "033" ||               // 강원
				$local_number == "041" ||               // 충남
				$local_number == "043" ||               // 충북
				$local_number == "055" ||               // 경남
				$local_number == "054" ||               // 경북
				$local_number == "061" ||               // 전남
				$local_number == "063" ||               // 전북
				$local_number == "064")                 // 제주
			$result = 1;
		else if($local_number == "010" ||
				$local_number == "011" ||
				$local_number == "017" ||
				$local_number == "016" ||
				$local_number == "018" ||
				$local_number == "019")
			$result = 2;
		else
			$result = FALSE;

		if(($result == 1 && $tel_length < 9) || $result == 2 && $tel_length < 10)
			$result = FALSE;

		return $result;
	}



	/***********************************************************
	*	작성일	:	2001-06-22			작성자	:	이병각
	*	화일명	:	mysql_lib.php
	*
	*	GAT_VALUE_DB 는 DB (mysql) 로 부터 검색된 값을 가져다준다.
	*	이 함수는 간단한 값을 가져오기 위한 함수로
	*	지나친 남용은 전체 시스템에 부담을 초래하므로
	*	필요이상의 사용을 자제한다.
	***********************************************************/
	//---------------------------------------------------------//
	// 개요 : mysql 에러 표시 프로시저
	//
	// 사용법  1. 입력값 :	X
	//		   2. 반환값 :	X
	//
	//---------------------------------------------------------//
	function GET_DB_ERROR()
	{
			 $err_no = mysql_errno();
			 $err_msg = mysql_error();
			 $error_msg = "ERROR CODE " . $err_no . " : $err_msg";
			 $error_msg = addslashes($error_msg);

			 //echo "$error_msg";
			 error_msg($error_msg, "back");
	}

	// ------------------------------------------------------------------------------------- //
	//
	//	배열을 선택박스로 출력하는 함수
	//
	//	입력	:	$name					선택박스 이름
	//			$option					선택박스 옵션
	//			$blank					선택박스 선택없을시 출력값
	//			$arr[row][col]			출력할 2차배열 (row=value, col=display)
	//			or $arr[key] => $value	출력할 1차배열 (key=value, col=display)
	//			$selected_value			선택된 값 (selected)
	//			$loop_start				출력범위시작값
	//			$loop_count				출력할 갯수
	//
	//	출력	:	2차배열을 이용한 선택박스 출력
	//
	//	리턴값	:	$print_msg
	//
	// ------------------------------------------------------------------------------------- //
	function ArrToSelect($name, $option, $blank, $arr, $selected_value, $loop_start=0, $loop_count=FALSE)
	{

		# Select 박스 시작
		$print_msg = "<select name=\"" . $name . "\" $option>\n";

		# 빈 option 값 출력
		if($print_msg&&strLen($blank)>1){
			$print_msg .= "<option value='' selected>" . $blank . "</option>\n";
		}
		# 빈 option 값 출력
///		$print_msg .= "  " . $blank . "\n";

		# 출력할 셀렉트 박스 범위 규정
		if($loop_count && (($loop_start+$loop_count) < sizeof($arr)))
			$loop_end = $loop_start+$loop_count-1;
		else
			$loop_end = sizeof($arr);

		$i = 0;
		if(is_array($arr))
		{
			foreach($arr as $key => $value)
			{
				# 시작범위보다 작으면 통과
				if($i < $loop_start)
					continue;

				# 종료범위보다 크면 종료
				if($i > $loop_end)
					break;

				# 2차 배열일경우 처리
				if(is_array($value))
				{
					$j = 0;
					foreach($value as $key2 => $value2)
					{
						if($j > 1) break;
						if($j == 0)
							$v = $value2;
						else
							$d = $value2;
						$j++;
					}
				}
				# 1차 배열일 경우 처리
				else
				{
					$v = $key;
					$d = $value;
				}

				# Option 처리
				$selected_flag = ($v == $selected_value) ? " selected" : "";
				$print_msg .= "  <option value=\"" . $v . "\"" . $selected_flag . ">" . $d . "</option>\n";

				$i++;
			}
		}

		# Select 박스 종료
		$print_msg .= "</select>\n";

		# Select 박스 출력
		return $print_msg;
	}


	// --------------------------------------------------------------- //
	//  문자열에서 입력바이트보다 크지 않은 최대한의 글자를 리턴한다.
	//
	//  입력 :	$string			- 입력 메세지
	//			$string_limit   - 제한수(Byte단위)
	//			$add_string		- 문자를 자른후에 뒤에 붙일 추가문자(옵션)
	//
	//  출력 :	$result_string	- 글자수단위 문자열
	// --------------------------------------------------------------- //
	function substr_byte($string, $string_limit, $add_string="...")
	{
		if($string_limit >= strlen($string))
		{
			return $string;
		}

		$string_k = $string_limit - 1;
		while(ord($string[$string_k]) & 0x80)
		{
			$string_k--;
		}
		$result_string = substr($string, 0, $string_limit - ($string_limit + $string_k + 1) % 2) . $add_string;

		return $result_string;
	}

	function sl_mb_substr($string, $string_limit, $add_string="...")
	{
		if($string_limit >= mb_strlen($string))
		{
			return $string;
		}	
		
		$result_string = mb_substr($string,0,$string_limit,'UTF-8'). $add_string;

		return $result_string;
	}

	//한글을 깨끗하게 자르기 위한 함수
   function cutStr($str,$cutbyte,$add_string="...")
   {

      $strbyte = strlen($str); //$str 의 바이트 수를 구한다
      if($strbyte <= $cutbyte) return $str;
      for($i=0; $i<$cutbyte;$i++){ 
         if(ord($str[$i])>127) $hancnt++; //아스키 코드값 128부터 $hancnt를 1씩 증가시킨다
      }

      //if($hancnt%2==0) $str = substr($str,0,$cutbyte);
      //else $str = substr($str,0,$cutbyte+1);
	  
		$str = mb_strcut($str,0,$cutbyte,"utf-8");

	  $str = $str.$add_string;
      return $str;
   }

	// --------------------------------------------------------------- //
	//  문자열에서 입력라인수보다 크지 않은 라인수를 리턴한다.
	//
	//  입력 :	$string			- 입력 메세지
	//			$line_limit		- 제한수(라인수)
	//			$add_string		- 문자를 자른후에 뒤에 붙일 추가문자(옵션)
	//
	//  출력 :	$result_string	- 줄단위 문자열
	// --------------------------------------------------------------- //
	function substr_br($string, $line_limit, $add_string="...")
	{
		// $string 의 라인수를 구한다.
		if(!eregi("<br />", $string))
			$flag_word = "<br>";

   		$string_arr = explode("\n",$string);
   		$line = sizeof($string_arr);

		if($line_limit >= $line)
		{
			if($flag_word) $string = nl2br($string);
			return $string;
		}

		// 리턴할 스트링을 구한다.
		$result_string = "";
		for($i=0; $i<$line_limit; $i++)
			$result_string .= $string_arr[$i] . $flag_word;

		return $result_string . $add_string;
	}

	// --------------------------------------------------------------- //
	//  이미지를 받아들여 원하는 사이즈의 비율맞는 크기값 반환
	//
	//  입력 :	$img_path		- 이미지절대경로
	//			$width			- 원하는 가로크기 (보통 가로사이즈를 기준으로 한다.)
	//			$flag			- 이미지의 가로를 무조건 $width 에 맞추면 1
	//							- 이미지의 가로가 $width 보다 큰것만 맞추면 false
	//
	//  출력 :	$result[]		- 구한 크기값배열 혹은 false
	//							  $result[0] : 가로
	//							  $result[1] : 세로
	//							  $result[2] : HTML TAG ex) width=40 height=30
	//							  or false
	// --------------------------------------------------------------- //
	function get_image_size($img_path, $width, $flag=false)
	{
		# 화일이 존재하지 않는경우 false를 리턴한다.
		if(!file_exists($img_path))
			return $result = false;

		# 이미지의 크기정보를 얻는다.
		$img_info = GetImageSize($img_path);

		# 이미지 정보가 없으면 false를 리턴한다.
		if(!$img_info)
			return $result = false;

		# 출력을 위한 이미지 사이즈를 구한다.
		if($flag || $img_info[0] > $width)
		{
			# flag 가 있는경우 무조건 가로크기를 $width에 맞춘다.
			$result[0] = $width;
			$result[1] = (int)($img_info[1] * $width / $img_info[0]);
		}
		else
		{
			# flag 가 없고 가로크기가 $width 보다 작은경우
			$result[0] = $img_info[0];
			$result[1] = $img_info[1];
		}
		$result[2] = " width=" . $result[0] . " height=" . $result[1];
		return $result;
	}

	// --------------------------------------------------------------- //
	//  입력문자를 입력갯수만큼 출력한다.
	//
	//	입력 :	$string			- 출력할 문자
	//			$count			- 반복횟수
	//
	//  출력 :	$print_string	- 출력문자
	// --------------------------------------------------------------- //
	function print_string($string, $count=1)
	{
		$print_string = "";
		for($i=0; $i<$count; $i++)
			$print_string .= $string;
		return $print_string;
	}

	function escape_string($string)
	{
		$string = stripslashes($string);
		$string = addslashes($string);
		return $string;
	}


	// 종합코드테이블에서 코드의 이름값을 구한다.
	function get_code_nm($code)
	{
		global $DB, $cf_table_cod_nm;
		$query = "SELECT NM FROM $cf_table_cod_nm WHERE CD = '$code'";
		$nm = $DB->Value($query);
		return $nm;
	}

	// 종합코드 해당 GB의 코드들의 코드/이름 값을 구한다.
	function get_code_arr($gb)
	{
		global $DB, $cf_table_cod_nm;
		$query = "SELECT CD, NM FROM $cf_table_cod_nm WHERE GB = '$gb'";
		$arr = $DB->Arr($query);
		return $arr;
	}

	// 종합코드 해당 GB의 코드들의 코드/이름 값을 구한다.
	function get_code_arrnm($gb)
	{
		global $DB, $cf_table_cod_nm;
		$query = "SELECT CD, NM FROM $cf_table_cod_nm WHERE GB = '$gb'";
		$arr = $DB->Pipe_Arr($query);
		return $arr;
	}

	// --------------------------------------------------------------- //
	//	URL 또는 메일링크에 자동으로 링크걸기
	// --------------------------------------------------------------- //
	function auto_link($text)
	{
		$ret = eregi_replace("([[:alnum:]]+)://([^[:space:]]*)([[:alnum:]#?/&=])", "<a href=\"\\1://\\2\\3\" target=\"_blank\">\\1://\\2\\3</a>", $text);
		$ret = eregi_replace("(([a-z0-9_]|\-|\.)+@([^[:space:]]*)([[:alnum:]-]))", "<a href=\"mailto:\\1\" target=\"_blank\">\\1</a>", $ret);
		return($ret);
	}


function show_select($arr,$select)
{
	for($i=0; $i<sizeof($arr) ;$i++){
		if($select==$arr[$i][0]){
			$selected="selected";
		}else{
			$selected="";
		}
		printf("\t\t\t\t<option value='%s' %s>%s\n",$arr[$i][0],$selected,$arr[$i][1]);
	}
}

#####################################
// 20060324
// 추가 : 진재복
// 설명 : 버튼생성
#####################################

function get_button_href($b_value,$b_href,$b_type=false,$b_script=false) {
	if($b_type == "submit") {
		return "<input type=\"submit\" value=\"$b_value\" class=\"input_button\">";
	} else if($b_type == "reset") {
		return "<input type=\"reset\" value=\"$b_value\" class=\"input_button\">";
	} else {
		if($b_script) {
			return "<input type=\"button\" value=\"$b_value\" $b_script class=\"input_button\">";
		} else {
			return "<input type=\"button\" value=\"$b_value\" onclick=\"location.href='$b_href'\" class=\"input_button\">";
		}
	}
}




// 한메일 발송은 하지 않는다....

function check_daum($fn_email) {

	$tm_arr_email = split("@",$fn_email);
	$arr_daum=array("hanmail.net","daum.net");

	if (in_array($tm_arr_email[1],$arr_daum))
		return "Y";
	else
		return "N";

}


 // 체크박스 explode 처리시 사용 2010-12-15 김정득
function explode_chk_yn($match_arr,$value){ //배열, 비교값 배열값과 일치한 비교값 있을때 true 리턴
	$return_value=false;
      
	for($i=0;$i<count($match_arr);$i++){
		if(trim($value)==trim($match_arr[$i])){
			$return_value=true;
		}
	}
	return $return_value;
}

function get_ymdhms_timestamp($ymdhms){
		return mktime(substr($ymdhms,8,2),	substr($ymdhms,10,2),substr($ymdhms,12,2),
								substr($ymdhms,4,2),substr($ymdhms,6,2),substr($ymdhms,0,4));
	}


	
function get_event_img($event_cd){
	
	switch($event_cd){
		case "et_cd1": $return_value="icon2.png"; break;
		case "et_cd2": $return_value="best.jpg"; break;
		case "et_cd3": $return_value="icon.png"; break;
		case "et_cd4": $return_value="icon3.png"; break;
		case "et_cd5": $return_value="hot.jpg"; break;
		case "et_cd6": $return_value="icon4.gif"; break;
		case "et_cd7": $return_value="icon5.png"; break;
		case "et_cd8": $return_value="icon4.png"; break;
		default :
			 $return_value="";
	}
		return $return_value;

}

// 상품가격 HTML을 구한다.
function getProductPriceHTML($price, $arySalePrice, $unit)
{
	$salePrice = getProductSalePrice($arySalePrice);
	$html = "";
	if ($salePrice > 0)
	{
		$html .= "<s style='color:#666666;'>" . number_format($price) . " " . $unit . "</s><br>";
		$html .= "<span style='color:#FC7056; font-weight:bold;'>" . number_format($salePrice) . " " . $unit . "</span>";
	}
	else
	{
		$html .= "<span style='color:#FC7056; font-weight:bold;'>" . number_format($price) . " " . $unit . "</span>";
	}
	return $html;
}

// 세일가격을 구한다.
function getProductSalePrice($arySalePrice)
{
	global $cf_cook_level;
	if (array_key_exists($cf_cook_level, $arySalePrice)) return $arySalePrice[$cf_cook_level];
	return $arySalePrice['zz'];
}

// 할인율 계산
function getSaleRate($price, $salePrice)
{
	$rateSale = 100 - round($salePrice / $price * 100, 2);
	return $rateSale;
}

// 적립포인트 % 계산
function getPointRate($price, $point)
{
	$ratePoint = round($point / $price * 100, 2);
	return $ratePoint;
}

// 할인율이 적용된 가격을 구한다.
function getSaleRatePrice($price, $salePercent)
{
	$return_price = 0;
	if ($salePercent > 0) $return_price = floor($price * (100 - $salePercent) / 100);
	return $return_price;
}

// 적립금 사용가능여부 판단
function get_point_yn($point)
{
	global $DB, $cf_table_cod_nm;
	$return_yn = "N";
	
	$query = "SELECT CON_CD FROM $cf_table_cod_nm WHERE CD = 'pointlimit'";
	$yn = $DB->Value($query);
	# 내 적립금 >= 사용가능한적립금
	if($point >= $yn['CON_CD']) $return_yn = "Y";
		
	return $return_yn;
}


// 배송비를 구한다.
function get_send_price($yn, $price)
{
	global $DB, $cf_table_cod_nm;
	$return_price = 0;
	if ($yn != "Y")
	{
		$query = "SELECT CON_CD, ENM, BIGO FROM $cf_table_cod_nm WHERE CD = 'sendprice'";
		$arr = $DB->Pipe_Row($query);

		if ($price < $arr['CON_CD']) $return_price = $arr['ENM'];
	}

	return $return_price;
}

// 배송비정보를 구한다.
function get_send_price_info()
{
	global $DB, $cf_table_cod_nm;
	$query = "SELECT CON_CD, ENM, BIGO FROM $cf_table_cod_nm WHERE CD = 'sendprice'";
	$arr = $DB->Pipe_Row($query);
	return $arr;
}

// 강좌의 마지막날을 자동계산한다.
function getLectureLastDay($start, $limit)
{
	$bonus_day = 5;

	$last = date("Ymd");
	if (!$start || !$limit) return $last;

	$cnt = substr($limit, 0, -1);
	$unit = substr($limit, -1);

	if ($unit == "W")
	{
		$limit = $cnt * 7 + $bonus_day;
		$last = date("Ymd", strtotime("+".$limit." day"));
	}
	else if ($unit == "M")
	{
		$limit = mktime(0, 0, 0, substr($start, 4, 2) + $cnt, substr($start, 6, 2) + $bonus_day, substr($start, 0, 4));
		$last = date("Ymd", $limit);
	}
	else if ($unit == "Y")
	{
		$limit = mktime(0, 0, 0, substr($start, 4, 2), substr($start, 6, 2) + $bonus_day, substr($start, 0, 4) + $cnt);
		$last = date("Ymd", $limit);
	}

	return $last;
}

function makeTicketNumber($key, $number)
{
	$t_number = substr($key, 0, 3) . $number[0] . substr($key, 3, 1) . $number[1] . substr($key, 4, 3) . $number[2] . substr($key, 7, 1) . $number[3] . substr($key, 8, 4);
	return $t_number;
}

function checkTicketNumber($serial)
{
	$check = "N";
	if (checkCouponRule($serial))
	{
		// 이미 사용된 수강권인지 체크
		if (isUsedCoupon($serial))
		{
			// 정상적인 수강권인지 체크
			if (checkCoupon($serial))
			{
				$check = "Y";
			}
		}
		else
		{
			$check = "U";
		}
	}
	return $check;
}

function checkCouponRule($serial)
{
	$reg = "LZ[0-9][A-Z][A-Z][0-9]26[RP][0-9][HPB][0-9][KTASV][0-9][TSYW][0-9]";
	$check = eregi($reg, $serial);
	return $check;
}

function isUsedCoupon($serial)
{
	global $DB;
	$chk = false;
	if (!empty($serial))
	{
		$query = "SELECT TU_USE_YN FROM CM_TICKET_USE_T WHERE TU_NUMBER = '" . $serial . "'";
		$yn = $DB->Value($query);
		if (empty($yn) || $yn != "Y") $chk = true;
	}

	return $chk;
}

function checkCoupon($serial)
{
	global $DB;

	$key = "";
	$number = "";
	for ($i = 0; $i < strlen($serial); $i++)
	{
		if (in_array($i, array(3, 5, 9, 11)))
		{
			$number .= $serial[$i];
		}
		else
		{
			$key .= $serial[$i];
		}
	}

	$chk = false;
	if (!empty($key) && !empty($number))
	{
		$query = "SELECT TI_USE_YN FROM CM_TICKET_T WHERE TI_KEY = '" . $key . "' AND TI_START <= '" . $number . "' AND TI_END >= '" . $number . "'";
		$yn = $DB->Value($query);
		if ($yn == "Y") $chk = true;
	}
	return $chk;
}

// --------------------------------------------------------------- //
//  마일리지 사용/적립 내역관리
//
//  입력 :	$id				- 마일리지 사용/적립 아이디
//			$kind			- 마일리지 처리분류
//			$sign			- 마일리지 사용분류 (1 : 적립, -1 : 사용)
//			$mileage		- 마일리지 사용/적립금액
//			$mileage_yn		- 마일리지 처리구분 (Y : 사용또는적립, N : 대기)
//			$order_no		- 쇼핑몰인경우 주문번호를 입력한다.
//			$id2			- 회원가입시 추천인이 있는경우 입력한다.
//
//  출력 :	$boolean		- true or false
// --------------------------------------------------------------- //
function setPoint($id, $kind, $sign, $mileage, $mileage_yn, $order_no="", $id2="")
{
	global $DB;

	//  입력값 체크
	if (empty($id) || empty($kind) || empty($sign) || empty($mileage) || empty($mileage_yn)) return false;

	$query = "INSERT INTO CM_POINT_T (P_KIND, P_INPUT_ID, P_CHOO_ID, P_ORDER_NO, P_MILEAGE, P_MIL_YN, P_MIL_SIGN, P_SIGN_YMD) VALUES ("
				. "'". $kind . "', '" . $id . "', '" . $id2 . "', '" . $order_no . "', " . $mileage . ", '" . $mileage_yn . "', " . $sign . ", NOW()"
				.")";
	$err = $DB->Insert_Query($query);
	if($err['log'] == "error")
	{
		return false;
	}

	if ($mileage_yn == "Y")
	{
		$mp = $sign * $mileage;
		$query = "UPDATE CM_MEMBER_T SET CM_POINT = CM_POINT + (" . $mp . ") WHERE CM_ID = '" . $id . "'";
		$DB->Update_Query($query);
	}

	return true;
}

// 해당 주문번호에 해당하는 마일리지 포인트를 적용한다.
function applyPoint($order_no)
{
	global $DB;

	//  입력값 체크
	if (empty($order_no)) return false;

	$query = "SELECT * FROM CM_POINT_T WHERE P_ORDER_NO = '" . $order_no . "' AND P_MIL_YN = 'N'";
	//echo $query . "<br>";
	$arr = $DB->Pipe_Arr($query);

	for ($i = 0; $i < count($arr); $i++)
	{
		$query = "UPDATE CM_POINT_T SET P_MIL_YN = 'Y' WHERE P_NO = '" . $arr[$i]['P_NO'] . "'";
		echo $query . "<br>";
/*
		$err = $DB->Update_Query($query);
		if($err['log'] == "error")
		{
			return false;
		}
*/		
		$mp = $arr[$i]['P_MIL_SIGN'] * $arr[$i]['P_MILEAGE'];
		$query = "UPDATE CM_MEMBER_T SET CM_POINT = CM_POINT + (" . $mp . ") WHERE CM_ID = '" . $arr[$i]['P_INPUT_ID'] . "'";
		echo $query . "<br>";
/*
		$err = $DB->Update_Query($query);
		if($err['log'] == "error")
		{
			return false;
		}
*/
	}
	return true;
}

// 관리자 주문관리 화면에서 결제관리 처리로직
function getNextCartCd($cd)
{
	$aryCartCd = array(
					20 => array(20 => "결제요청", 30 => "결제완료", 40 => "결제오류", 50 => "배송신청", 110 => "미결"),
					30 => array(30 => "결제완료", 50 => "배송신청", 60 => "배송중", 70 => "배송완료", 100 => "완결", 120 => "환불"),
					40 => array(40 => "결제오류", 110 => "미결"),
					50 => array(50 => "배송신청", 60 => "배송중", 70 => "배송완료", 100 => "완결", 120 => "환불"),
					60 => array(60 => "배송중", 70 => "배송완료", 80 => "반송", 100 => "완결", 120 => "환불"),
					70 => array(70 => "배송완료", 80 => "반송", 100 => "완결", 120 => "환불"),
					80 => array(60 => "배송중", 70 => "배송완료", 80 => "반송", 120 => "환불"),
					100 => array(100 => "완결", 120 => "환불"),
					110 => array(110 => "미결"),
					120 => array(110 => "미결", 120 => "환불")
				);
	return $aryCartCd[$cd];
}

// 라이프존 상품권정보를 이용하여 기초정보 가져오기
function getTicketNumberInfo($ticket_number)
{
	$info = array();
	$info[0] = false;

	$le_class = array(
					"K" => array("KIDS", "lec_10", "Life Kids"),
					"T" => array("1020", "lec_20", "Life 1020"),
					"A" => array("3040", "lec_30", "Life 3040"),
					"S" => array("5060", "lec_40", "Life 5060"),
					"V" => array("VIP", "lec_90", "Life VIP")
				);
	$le_limit = array(
					"T" => array("3M", "3개월"),
					"S" => array("6M", "6개월"),
					"Y" => array("12M", "12개월"),
					"W" => array("1W", "1주일")
				);

	if (!empty($ticket_number))
	{
		$info[0] = true;

		$le_class_cd = substr($ticket_number, 12, 1);
		$le_limit_cd = substr($ticket_number, 14, 1);

		// 강좌이름
		$le_class[$le_class_cd][2] .= " " . $le_limit[$le_limit_cd][1];

		// 강좌분류
		$info['le_class'] = $le_class[$le_class_cd];

		// 수강기간
		$info['le_limit'] = $le_limit[$le_limit_cd][0];
	}

	return $info;
}


	// 종합코드에서 무료최저비용 구함
	function get_code_freelimit($code)
	{
		global $DB, $cf_table_cod_nm;
		$query = "SELECT CON_CD FROM $cf_table_cod_nm WHERE CD = '$code'";
		$nm = $DB->Value($query);
		return $nm;
	}




function basong_check($cart_no,$send_price){
	global $DB, $cf_table_car_nm;
	$query = "SELECT COUNT(*) FROM $cf_table_car_nm WHERE CART_NO  = '$cart_no' AND BASONG_YN ='N'";
	$basong= $DB->Value($query);
	if($basong>0){
		return 0;
	}
	else{
		return $send_price;
	}
	

}

function get_bank_nm($cd){

	switch($cd){
		case "02" : $return = "한국산업은행"; break;
		case "04" : $return = "국민은행"; break;
		case "07" : $return = "수협중앙회"; break;
		case "12" : $return = "단위농협"; break;
		case "20" : $return = "우리은행"; break;
		case "23" : $return = "제일은행"; break;
		case "26" : $return = "신한은행"; break;
		case "31" : $return = "대구은행"; break;
		case "34" : $return = "광주은행"; break;
		case "37" : $return = "전북은행	"; break;
		case "39" : $return = "경남은행"; break;
		case "53" : $return = "씨티은행"; break;
		case "71" : $return = "우체국"; break;
		case "83" : $return = "평화은행"; break;
		case "88" : $return = "신한은행(조흥 통합)"; break;
	
	}

	return $return;
}

function getBrowser() {
 $iPod = stripos($_SERVER['HTTP_USER_AGENT'], "iPod");
 $iPhone = stripos($_SERVER['HTTP_USER_AGENT'], "iPhone");
 $iPad = stripos($_SERVER['HTTP_USER_AGENT'], "iPad");
 $Android = stripos($_SERVER['HTTP_USER_AGENT'], "Android");

	if($iPod || $iPhone || $iPad ){
		$return = "iphone";
	}

	else if($Android){    
		$return = "android";
	}
	else{
		$return = "web";
	}	
	

	return $return;
}

// 배송추적
function get_delivery_info($t_name,$t_no)
{
	global $DB, $cf_table_cod_nm;
	$query = "SELECT NM_DESC FROM $cf_table_cod_nm WHERE GB = 'takbae' AND CD = '".$t_name."' ";
	$d_value = $DB->Value($query);

	$d_link = $d_value."".$t_no;

	return $d_link;
}

function erp_synchro()
{
	global $DB;

	$query = "select orderid,orderstep,tack_comp,tack_number from rb_shop_order order by uid DESC limit 0, 30 ";
	$arr = $DB->Pipe_Arr($query);	

	for($k=0; $k < 30 ; $k++){

		$orderid = "";
		$orderstep = "";
		$tack_comp = "";
		$tack_number = "";

		$orderid = $arr[$k][orderid];
		$orderstep = "0".$arr[$k][orderstep];
		$tack_comp = $arr[$k][tack_comp];
		$tack_number = $arr[$k][tack_number];

		// 주문테이블 주문상태값 동기화

		if($orderstep==4){
			$query_order_up = "UPDATE MT_ORDER_T SET " . 
							  "PROGRESS = '$orderstep', " .
							  "TAK_NAME = '$tack_comp', " .
							  "TAK_NO = '$tack_number', " .
							  "SYNK_END = 'Y' " .
							  " WHERE ORDER_NO = '$orderid' and SYNK_END = 'N' "; //동기화 업데이트 스톱을 위해 SYNK_END에 Y값을 준다
		}else{
			$query_order_up = "UPDATE MT_ORDER_T SET " . 
							  "PROGRESS = '$orderstep', " .
							  "TAK_NAME = '$tack_comp', " .
							  "TAK_NO = '$tack_number' " .
							  " WHERE ORDER_NO = '$orderid' ";
		}
		//if($_SERVER[REMOTE_ADDR]=="116.34.28.137"){
			$DB->Update_Query($query_order_up);
		//}

		if($tack_comp=="로젠택배" || $tack_comp=="http://www.ilogen.com/customer/reserve_03_detail.asp?f_slipno="){
			$tack_comp_v = "004";
		}elseif($tack_comp=="한진택배"){
			$tack_comp_v = "003";
		}elseif($tack_comp=="현대택배"){
			$tack_comp_v = "002";
		}elseif($tack_comp=="KGB택배"){
			$tack_comp_v = "001";
		}elseif($tack_comp=="CJ GLS"){
			$tack_comp_v = "HLC";
		}

		$query_order_up2 = "UPDATE MT_CART_T SET " . 						  
						  "TAK_NAME = '$tack_comp_v', " .
						  "TAK_NO = '$tack_number' " .
						  " WHERE ORDER_NO = '$orderid'";
		//if($_SERVER[REMOTE_ADDR]=="116.34.28.137"){
			$DB->Update_Query($query_order_up2);
		//}
	}
}

// 각월에 마지막 날을 구한다.
function get_totalday($year,$month){
	$date=1;
	while(checkdate($month,$date,$year)){
		$date++;
	}
	$date--;
	return $date;
}


/*
###############################################
     ::: 브라우저 체크함수 :::          
	ex) 변수 = CheckBrowser();
###############################################
*/

function CheckBrowser() {
	
	if(!$agent=getenv("HTTP_USER_AGENT")) return 'unknown';
    
	if(eregi( 'MSIE', $agent)) { 
		preg_match("/MSIE ([0-9][.][0-9]{0,2})/i",$agent,$match);
		return "MS-Explorer {$match[1]}"; 
	} 
	if(eregi( 'Netscape', $agent)) {
		$temp=substr($agent,strrpos($agent,'Netscape'));
		$temp = preg_replace("/[^0-9+.]/","",$temp);
		return "Netscape {$temp}"; 
	} 	
	if(eregi( 'Opera', $agent)) { 
		$temp=substr($agent,strrpos($agent,'Opera'));
		$temp = preg_replace("/[^0-9+.]/","",$temp);
		return "Opera {$temp}"; 
	}
	if(eregi( 'Firefox', $agent)) { 
		$temp=substr($agent,strrpos($agent,'Firefox'));
		$temp = preg_replace("/[^0-9+.]/","",$temp);
		return "Firefox {$temp}"; 
	}
	if(eregi( 'Mozilla', $agent)) { 
		if(eregi('rv',$agent)){
			preg_match_all("/rv:(.*)\)/i",$agent,$match,PREG_SET_ORDER);
			return "Mozilla {$match[0][1]}"; 
		}
	}

	if (eregi('Chrome', $agent)) return "Chrome";
    if (eregi('Safari', $agent)) return "Safari";
	if (eregi('Lynx', $agent)) return "Lynx";
	if (eregi('LibWWW', $agent)) return "LibWWW";
	if (eregi('Konqueror', $agent)) return "Konqueror";
	if (eregi('Internet Ninja', $agent)) return "Internet Ninja";
	if (eregi('Download Ninja', $agent)) return "Download Ninja";
	if (eregi('WebCapture', $agent)) return "WebCapture";
	if (eregi('LTH', $agent)) return "LTH";
	if (eregi('Gecko', $agent)) return "Gecko";
	if (eregi('wget', $agent)) return "Wget command";

	if (eregi('PSP', $agent)) return "PlayStation Portable";
	if (eregi('Symbian', $agent)) return "Symbian PDA";
	if (eregi('Nokia', $agent)) return "Nokia PDA";
	if (eregi('LGT', $agent)) return "LG Mobile";
	if (eregi('mobile', $agent)) return "ETC Mobile";

	if (eregi('Googlebot', $agent)) return "GoogleBot";
	if (eregi('OmniExplorer', $agent)) return "OmniExplorerBot";
	if (eregi('MJ12bot', $agent)) return "majestic12Bot";
	if (eregi('ia_archiver', $agent)) return "Alexa(IA Archiver)";
	if (eregi('Yandex', $agent)) return "Yandex bot";
	if (eregi('Inktomi', $agent)) return "Inktomi Slurp";
	if (eregi('Giga', $agent)) return "GigaBot";
	if (eregi('Jeeves', $agent)) return "Jeeves bot";
	if (eregi('Planetwide', $agent)) return "IBM Planetwide bot";
	if (eregi('bot', $agent) || eregi('Crawler', $agent) || eregi('library', $agent)) return "ETC Robot";

	return 'unknown';
}


/*
###############################################
     ::: OS 체크함수 :::          
	ex) 변수명 = CheckOs();
###############################################
*/

function CheckOs() {
    	
	if(!$agent=getenv("HTTP_USER_AGENT")) return 'unknown';
						
    if (eregi('win95', $agent) || eregi('windows 95', $agent)) return "Windows 95";
    if (eregi('Windows 9x', $agent) || eregi('Win 9x 4.90', $agent) || eregi('Windows Me', $agent)) return "Windows ME";
	if (eregi('Win98', $agent) || eregi( 'Windows 98', $agent)) return "Windows 98";	
	if (eregi('Windows NT 5.1', $agent) || eregi('Windows XP', $agent)) return "Windows XP";	
	if (eregi('Windows NT 5.0', $agent) || eregi('Windows 2000', $agent)) return "Windows 2000";    
    if (eregi('windows NT 5.2', $agent) || eregi('Windows 2003', $agent)) return "Windows 2003";
	if (eregi('windows NT 6', $agent)) return "Windows Vista";
	if (eregi('Winnt', $agent) || eregi('Windows NT', $agent)) return "Windows NT";
	if (eregi('windows', $agent)) return "ETC Windows";
    if (eregi('Mac', $agent )) {
		if(eregi('PowerPC' , $agent)) return "Mac PowerPC";
		if(eregi('Macintosh' , $agent)) return "Mac Macintosh";
		if(eregi('PowerPC' , $agent)) return "Mac OS X";
		return "ETC Mac";
	}	
	if (eregi('Os2', $agent)) return "OS2";
	if (eregi('Linux', $agent) || eregi('Wget', $agent)) return "Linux";
	if (eregi('Unix', $agent)) return "Unix";
	if (eregi('Freebsd', $agent)) return "Freebsd";

	if (eregi('PSP', $agent)) return "PlayStation Portable";
	if (eregi('Symbian', $agent)) return "Symbian PDA";
	if (eregi('Nokia', $agent)) return "Nokia PDA";
	if (eregi('LGT', $agent)) return "LG Mobile";
	if (eregi('mobile', $agent)) return "ETC Mobile";

	if (eregi('Googlebot', $agent)) return "GoogleBot";
	if (eregi('OmniExplorer', $agent)) return "OmniExplorerBot";
	if (eregi('MJ12bot', $agent)) return "majestic12Bot";
	if (eregi('ia_archiver', $agent)) return "Alexa(IA Archiver)";
	if (eregi('Yandex', $agent)) return "Yandex bot";
	if (eregi('Inktomi', $agent)) return "Inktomi Slurp";
	if (eregi('Giga', $agent)) return "GigaBot";
	if (eregi('Jeeves', $agent)) return "Jeeves bot";
	if (eregi('Planetwide', $agent)) return "IBM Planetwide bot";
	if (eregi('bot', $agent) || eregi('Crawler', $agent) || eregi('library', $agent)) return "ETC Robot";
	
	return 'unknown';
}