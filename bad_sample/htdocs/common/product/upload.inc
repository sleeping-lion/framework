<?php
	// 첨부화일 업로드 (화일이 여러개일경우 각각의 사이즈를 구하지 못한다.)

	if($_FILES[userfile]){
			
		foreach($_FILES[userfile][tmp_name] AS $key => $val){

			if(!empty($val)){
			// ------------------------------------------------- //
			// 파일 업로드 처리 시작
			// ------------------------------------------------- //
		
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

	
	if($cf_allow_html_yn =="Y"){
		for($i=0;$i<count($tx_attach_path);$i++){
			$f_query = "INSERT INTO CM_FILE_T (GB,CD,ITEM,P_NO,ORDER_NO,ATTACH_PATH,ATTACH_SIZE,REAL_PATH,FILE_TYPE) VALUES ('".$a_gb."','".$a_cd."','".$a_item."','".$my_no."','".$i."','".$tx_attach_path[$i]."','".$tx_attach_size[$i]."','".$tx_real_path[$i]."','editor')";
			$DB->Insert_Query($f_query);
		}
	}

?>