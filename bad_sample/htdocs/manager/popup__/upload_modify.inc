<?
	# ------------------------------------------------------- #
	#	화일 업로드 처리
	#	- 화일 삭제를 체크한경우 => 화일만 지운다.
	#	- 화일 업로드를 체크한경우 => 화일을 지우고 다시 업로드한다.
	# ------------------------------------------------------- #
############################# 1번째 #####################################
	$tm_attach_size = "";
	$tm_attach_path = "";
	if(is_uploaded_file($_FILES[userfile][tmp_name]) || $fr_display == "0"){
		// 기존화일이 있는경우 삭제한다.
		$tm_real_path = $cf_savedir . "/" . $my_popup_img;
		$tm_real_path_physical = $cf_doc_root . "/" . $tm_real_path;
		if($my_popup_img && is_file($tm_real_path_physical) && !Delete_File($tm_real_path_physical)){
			error_msg("기존 첨부화일을 삭제하는데 실패했습니다.", "back");
			exit;
		}
		# ---- 화일 삭제를 체크한경우 ---- #
		if($fr_display == "0"){
			$tm_attach_size = "";
			$tm_attach_path = "";
			$tm_real_path = "";
		}else{
			// 첨부화일 업로드 (화일이 여러개일경우 각각의 사이즈를 구하지 못한다.)
			if(is_uploaded_file($_FILES[userfile][tmp_name])){
				$tm_upload_path = $my_no . "_" . $_FILES[userfile][name];
				if(Upload_File($_FILES[userfile], $cf_savedir_physical, $cf_attach_size, $tm_upload_path, 1)){
					$tm_attach_size = $_FILES[userfile][size];
					$tm_attach_path = $_FILES[userfile][name];
					$tm_real_path = $tm_upload_path;
				}
			}
		}
	}else{
		// 기존화일의 파일관련변수
		$tm_attach_size = $my_attach_size;
		$tm_attach_path = $my_attach_path;
		$tm_real_path = $my_popup_img;
	}

?>
