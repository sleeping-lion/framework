<?
	# ------------------------------------------------------- #
	#	화일 업로드 처리
	#	- 화일 삭제를 체크한경우 => 화일만 지운다.
	#	- 화일 업로드를 체크한경우 => 화일을 지우고 다시 업로드한다.
	# ------------------------------------------------------- #
############################# 1번째 #####################################
	$tm_attach_size = "";
	$tm_attach_path = "";
	if(is_uploaded_file($_FILES[userfile][tmp_name]) || $fr_file_del == "Y"){
		// 기존화일이 있는경우 삭제한다.
		$tm_real_path = $cf_savedir . "/" . $my_real_path;
		$tm_real_path_physical = $cf_doc_root . "/" . $tm_real_path;
		if($my_attach_path && is_file($tm_real_path_physical) && !Delete_File($tm_real_path_physical)){
			error_msg("기존 첨부화일을 삭제하는데 실패했습니다.", "back");
			exit;
		}
		# ---- 화일 삭제를 체크한경우 ---- #
		if($fr_file_del == "Y"){
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
		$tm_real_path = $my_real_path;
	}
############################# 2번째 #####################################
	$tm_attach_size1 = "";
	$tm_attach_path1 = "";
	if(is_uploaded_file($_FILES[userfile_1][tmp_name]) || $fr_file_del1 == "Y"){
		// 기존화일이 있는경우 삭제한다.
		$tm_real_path1 = $cf_savedir . "/" . $my_real_path1;
		$tm_real_path_physical1 = $cf_doc_root . "/" . $tm_real_path1;
		if($my_attach_path1 && is_file($tm_real_path_physical1) && !Delete_File($tm_real_path_physical1)){
			error_msg("기존 첨부화일을 삭제하는데 실패했습니다.", "back");
			exit;
		}
		# ---- 화일 삭제를 체크한경우 ---- #
		if($fr_file_del1 == "Y"){
			$tm_attach_size1 = "";
			$tm_attach_path1 = "";
			$tm_real_path1 = "";
		}else{
			// 첨부화일 업로드 (화일이 여러개일경우 각각의 사이즈를 구하지 못한다.)
			if(is_uploaded_file($_FILES[userfile_1][tmp_name])){
				$tm_upload_path1 = $my_no . "_1_" . $_FILES[userfile_1][name];
				if(Upload_File($_FILES[userfile_1], $cf_savedir_physical, $cf_attach_size, $tm_upload_path1, 1)){
					$tm_attach_size1 = $_FILES[userfile_1][size];
					$tm_attach_path1 = $_FILES[userfile_1][name];
					$tm_real_path1 = $tm_upload_path1;
				}
			}
		}
	}else{
		// 기존화일의 파일관련변수
		$tm_attach_size1 = $my_attach_size1;
		$tm_attach_path1 = $my_attach_path1;
		$tm_real_path1 = $my_real_path1;
	}
############################# 3번째 #####################################
	$tm_attach_size2 = "";
	$tm_attach_path2 = "";
	if(is_uploaded_file($_FILES[userfile_2][tmp_name]) || $fr_file_del2 == "Y"){
		// 기존화일이 있는경우 삭제한다.
		$tm_real_path2 = $cf_savedir . "/" . $my_real_path2;
		$tm_real_path_physical2 = $cf_doc_root . "/" . $tm_real_path2;
		if($my_attach_path2 && is_file($tm_real_path_physical2) && !Delete_File($tm_real_path_physical2)){
			error_msg("기존 첨부화일을 삭제하는데 실패했습니다.", "back");
			exit;
		}
		# ---- 화일 삭제를 체크한경우 ---- #
		if($fr_file_del2 == "Y"){
			$tm_attach_size2 = "";
			$tm_attach_path2 = "";
			$tm_real_path2 = "";
		}else{
			// 첨부화일 업로드 (화일이 여러개일경우 각각의 사이즈를 구하지 못한다.)
			if(is_uploaded_file($_FILES[userfile_2][tmp_name])){
				$tm_upload_path2 = $my_no . "_2_" . $_FILES[userfile_2][name];
				if(Upload_File($_FILES[userfile_2], $cf_savedir_physical, $cf_attach_size, $tm_upload_path2, 1)){
					$tm_attach_size2 = $_FILES[userfile_2][size];
					$tm_attach_path2 = $_FILES[userfile_2][name];
					$tm_real_path2 = $tm_upload_path2;
				}
			}
		}
	}else{
		// 기존화일의 파일관련변수
		$tm_attach_size2 = $my_attach_size2;
		$tm_attach_path2 = $my_attach_path2;
		$tm_real_path2 = $my_real_path2;
	}
############################# 4번째 #####################################
	$tm_attach_size3 = "";
	$tm_attach_path3 = "";
	if(is_uploaded_file($_FILES[userfile_3][tmp_name]) || $fr_file_del3 == "Y"){
		// 기존화일이 있는경우 삭제한다.
		$tm_real_path3 = $cf_savedir . "/" . $my_real_path3;
		$tm_real_path_physical3 = $cf_doc_root . "/" . $tm_real_path3;
		if($my_attach_path3 && is_file($tm_real_path_physical3) && !Delete_File($tm_real_path_physical3)){
			error_msg("기존 첨부화일을 삭제하는데 실패했습니다.", "back");
			exit;
		}
		# ---- 화일 삭제를 체크한경우 ---- #
		if($fr_file_del3 == "Y"){
			$tm_attach_size3 = "";
			$tm_attach_path3 = "";
			$tm_real_path3 = "";
		}else{
			// 첨부화일 업로드 (화일이 여러개일경우 각각의 사이즈를 구하지 못한다.)
			if(is_uploaded_file($_FILES[userfile_3][tmp_name])){
				$tm_upload_path3 = $my_no . "_3_" . $_FILES[userfile_3][name];
				if(Upload_File($_FILES[userfile_3], $cf_savedir_physical, $cf_attach_size, $tm_upload_path3, 1)){
					$tm_attach_size3 = $_FILES[userfile_3][size];
					$tm_attach_path3 = $_FILES[userfile_3][name];
					$tm_real_path3 = $tm_upload_path3;
				}
			}
		}
	}else{
		// 기존화일의 파일관련변수
		$tm_attach_size3 = $my_attach_size3;
		$tm_attach_path3 = $my_attach_path3;
		$tm_real_path3 = $my_real_path3;
	}
?>
