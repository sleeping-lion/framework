<?
	# ------------------------------------------------------- #
	#	화일 업로드 처리
	#	- 화일 삭제를 체크한경우 => 화일만 지운다.
	#	- 화일 업로드를 체크한경우 => 화일을 지우고 다시 업로드한다.
	# ------------------------------------------------------- #
############################# 1번째 #####################################
	
	for($i = 0 ;$i<count($fr_file_del);$i++){
		if($fr_file_del[$i] != ""){
			if(!Delete_File2($po_no,$fr_file_del[$i],$cf_savedir,$a_gb,$a_cd,$a_item)){
				error_msg("기존 첨부화일을 삭제하는데 실패했습니다.", "back");
				exit;
			}
		}
	}

	if($_FILES[userfile]){
				
			foreach($_FILES[userfile][tmp_name] AS $key => $val){

				if(!empty($val)){
				// ------------------------------------------------- //
				// 파일 업로드 처리 시작
				// ------------------------------------------------- //
					
					if(!Delete_File2($po_no,$key,$cf_savedir,$a_gb,$a_cd,$a_item)){
						error_msg("기존 첨부화일을 삭제하는데 실패했습니다.", "back");
						exit;
					}
					
					$temp = pathinfo($_FILES[userfile][name][$key]);

					$ext =  strtolower($temp['extension']);

					$temp = explode(' ',microtime());
						
					$tm_upload_path = $temp[1] . substr($temp[0],2) . $key . '.' .  $ext;
		
					if(Upload_Files($_FILES[userfile],$key, $cf_savedir_physical, $cf_attach_size, $tm_upload_path, 1))
					{
						$tm_attach_size = $_FILES[userfile][size][$key];
						$tm_attach_path = $_FILES[userfile][name][$key];
						$tm_real_path = $tm_upload_path;

						$f_query = "INSERT INTO CM_FILE_T (GB,CD,ITEM,P_NO,ORDER_NO,ATTACH_PATH,ATTACH_SIZE,REAL_PATH,FILE_TYPE) VALUES ('".$a_gb."','".$a_cd."','".$a_item."','".$my_no."','".$key."','".$tm_attach_path."','".$tm_attach_size."','".$tm_real_path."','normal')";
						$DB->Insert_Query($f_query);

					}

			
				}

			}
		}

	$tm_file_list = "";
	
	if($cf_allow_html_yn =="Y"){
		for($i=0;$i<count($tx_attach_path);$i++){
			$tm_file_list .= "'".$tx_real_path[$i]."',";
		}
		$tm_file_list = substr($tm_file_list,0,-1);
		
		if($tm_file_list!=""){
			$f_sql = "SELECT REAL_PATH FROM CM_FILE_T WHERE P_NO = '".$po_no."' AND GB ='".$a_gb."' AND CD ='".$a_cd."' AND ITEM ='".$a_item."' and REAL_PATH NOT IN (".$tm_file_list.") and FILE_TYPE='editor' ";
			$f_arr = $DB->Pipe_Arr($f_sql);

			for($i=0;$i<count($f_arr);$i++){
				//echo $_SERVER["DOCUMENT_ROOT"]."/".$cf_savedir."/".$f_arr[$i]["REAL_PATH"];
				if(is_file($_SERVER["DOCUMENT_ROOT"]."/".$cf_savedir."/".$f_arr[$i]["REAL_PATH"]) ){
					if(!Delete_File($_SERVER["DOCUMENT_ROOT"]."/".$cf_savedir."/".$f_arr[$i]["REAL_PATH"])){
						error_msg("기존 첨부화일을 삭제하는데 실패했습니다.", "back");
						exit;
					}
				}
			}
		}
		else{
			$f_sql = "SELECT REAL_PATH FROM CM_FILE_T WHERE P_NO = '".$po_no."' AND GB ='".$a_gb."' AND CD ='".$a_cd."' AND ITEM ='".$a_item."' and FILE_TYPE='editor' ";
			$f_arr = $DB->Pipe_Arr($f_sql);

			for($i=0;$i<count($f_arr);$i++){
				//echo $_SERVER["DOCUMENT_ROOT"]."/".$cf_savedir."/".$f_arr[$i]["REAL_PATH"];
				if(is_file($_SERVER["DOCUMENT_ROOT"]."/".$cf_savedir."/".$f_arr[$i]["REAL_PATH"]) ){
					if(!Delete_File($_SERVER["DOCUMENT_ROOT"]."/".$cf_savedir."/".$f_arr[$i]["REAL_PATH"])){
						error_msg("기존 첨부화일을 삭제하는데 실패했습니다.", "back");
						exit;
					}
				}
			}
		}


		$del_query = "DELETE FROM CM_FILE_T WHERE P_NO = '".$po_no."' AND GB ='".$a_gb."' AND CD ='".$a_cd."' AND ITEM ='".$a_item."' and FILE_TYPE='editor' ";
		$DB->Delete_Query($del_query);

		
		for($i=0;$i<count($tx_attach_path);$i++){
			$f_query = "INSERT INTO CM_FILE_T (GB,CD,ITEM,P_NO,ORDER_NO,ATTACH_PATH,ATTACH_SIZE,REAL_PATH,FILE_TYPE) VALUES ('".$a_gb."','".$a_cd."','".$a_item."','".$my_no."','".$i."','".$tx_real_path[$i]."','".$tx_attach_size[$i]."','".$tx_real_path[$i]."','editor')";
			$DB->Insert_Query($f_query);
		}
	}
?>
