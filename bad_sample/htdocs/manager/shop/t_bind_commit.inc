<?
	foreach ($_FILES[userfile][tmp_name] as $fk=>$fv) {
		
		if(is_uploaded_file($_FILES[userfile][tmp_name][$fk])) {
			$tm_file_ext[$fk] = substr($_FILES[userfile][name][$fk],strrpos($_FILES[userfile][name][$fk],".")+1);	// 파일 확장자 구하기
			$tm_upload_name = $my_no.$cf_upload_nm[$fk].".".$tm_file_ext[$fk];	// 저장 파일명 만들기
			if(!Upload_Files($_FILES[userfile],$fk,$cf_savedir_physical,$cf_attach_size,$tm_upload_name,1)) {
				error_msg("$cf_upload_column_nm[$fk] 업로드 실패 다시 시도해 주세요.","back");
				exit;
			}
		}		
	}


	############## 업로드 유형 설정 ############### 
	$ableExt = array('jpg','jpeg','gif','png','bmp');

	//업로드 폴더 설정
	$upload_folder = $_SERVER[DOCUMENT_ROOT].'/files/shop.1/';

	$file_name3 = "";
	$org_name3 = "";

	##################### 다중 파일 업로드 ###################
	for($i = 0;$i < count($_FILES[upload][name]);$i++){

		$img = $_FILES['upload']['name'][$i];		
	
		if($img && $img!=""){//업로드 파일이 있다면
			$mend = explode(" ", microtime());//마이크로타임 뒷자리를 구한다.중복방지로 붙이려고..
			
			//파일 확장자 가져오고 파일명 변경;
			$path = pathinfo($_FILES['upload']['name'][$i]);
			$ext = strtolower($path['extension']);
			
			//jpg,jpeg,gif,png,bmp 이미지 파일 확인
			if(!in_array($ext, $ableExt)) {
				echo "<script>alert('지정된 파일이 아닙니다.');</script>";
			}else{
				$img_name = $mend[1]."$i.".strtoupper($ext);
				$toName = $upload_folder.$img_name;
				$fromName = $_FILES['upload']['tmp_name'][$i];//업로드된 임시파일이름		
				
				if(move_uploaded_file($fromName, $toName)){
					if($i == 0){
						$org_name3 .= $_FILES['upload']['name'][$i];//원본파일명이 넘어온값이 없다면 원본파일명 셋팅
						$file_name3 .= $img_name;
					}else{
						$org_name3 .= ",".$_FILES['upload']['name'][$i];//원본파일명이 넘어온값이 없다면 원본파일명 셋팅
						$file_name3 .= ",".$img_name;
					}
				}else{
					echo "파일업로드 실패";
				}
			}		
		}
	}


	// 이스케이프
	$fr_it_name = escape_string($fr_it_name);
	$fr_it_company = escape_string($fr_it_company);
	$fr_it_memo = escape_string($fr_it_memo);
	$fr_it_etc = escape_string($fr_it_etc);

	# 공개여부
	//$tm_it_service_yn
	

	# 상품 조회수
	$tm_it_ver_cnt = 0;
  ## 기본정렬
	if(!$fr_it_pos) $fr_it_pos = 99999;
  ## 베스트 정렬
  if(!$fr_it_bestpos) $fr_it_bestpos = 99999;
  ## 메인글 정렬
  if(!$fr_it_mpos) $fr_it_mpos = 99999;
  ## 메인 베스트 정렬
  if(!$fr_it_bpos) $fr_it_bpos = 99999;


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
	$query =    "insert into $cf_table_col_nm (" .
						"NO, " .
                        "IT_LCLASS, " .
                        "IT_MCLASS, " .
						"IT_SCLASS, " .
                        "IT_NO, " .
						"IT_MODEL_NO, " .
						"IT_NAME, " .
						"IT_FEATURE, " .
                        "IT_EVENT_CD, " .
						"IT_BRAND_CD, " .
						"IT_ORIGIN, " .
						"IT_BRAND, " .
						"IT_COMPANY, " .
						"IT_STANDARD, " .
                        "IT_CNT, " .
                        "IT_PRICE, " .
                        "IT_SALE_PRICE, " .
                        "IT_SAVE_PRICE, " .
                        "IT_PRICE_UNIT, " .
						"IT_ETC, " .
						"IT_POS, " .
                   //     "IT_BESTPOS, " .
                      //  "IT_MPOS, " .
                       // "IT_BPOS, " .
					    "IT_OPTION, " .
                        "IT_MEMO, " .
                        "IT_VER_CNT, " .
                        "IT_SELL_YN, " .
						"IT_SERVICE_YN, " .
						"BASONG_YN,".
                        "INPUT_ID, " .
                        "INPUT_NM, " .
						"INPUT_IP, " .
                        "INPUT_YMDHMS, " .
						"SIGN_ID, " .
						"SIGN_NM, " .
						"SIGN_IP, " .
						"SIGN_YMDHMS, " .
						"IT_GALLERY, " .
						"IT_GALLERY_ORG" .

                    ") values (" .

						"'$my_no', " .
                        "'$fr_it_lclass', " .
                        "'$fr_it_mclass', " .
						"'$fr_it_sclass', " .
                        "'$my_it_no', " .
						"'$fr_it_model_no', " .
                        "'$fr_it_name', " .
						"'$fr_it_feature', " .
						"'$fr_it_event_cd', " .
						"'$fr_it_brand_cd', " .
						"'$fr_it_origin', " .
						"'$fr_it_brand', " .
                        "'$fr_it_company', " .
						"'$fr_it_standard', " .
                        "'$fr_it_cnt', " .
                        "'$fr_it_price', " .
                        "'$fr_it_sale_price', " .
                        "'$fr_it_save_price', " .
                        "'$fr_it_price_unit', " .
						"'$fr_it_etc', " .
						"'$fr_it_pos', " .
						//"'$fr_it_bestpos', " .
						//"'$fr_it_mpos', " .
					//	"'$fr_it_bpos', " .
						"'$fr_it_option', " .
                        "'$fr_it_memo', " .
                        "'$tm_it_ver_cnt', " .
                        "'$fr_it_sell_yn', " .
						"'$fr_it_service_yn', " .
						"'$fr_basong_yn', " .
                        "'$tm_input_id', " .
                        "'$tm_input_nm', " .
						"'$tm_input_ip', " .
                        "'$tm_input_ymdhms', " .
                        "'$tm_sign_id', " .
                        "'$tm_sign_nm', " .
						"'$tm_sign_ip', " .
                        "'$tm_sign_ymdhms', " .
						"'$file_name3', " .
						"'$org_name3' " .
                    ")";

	if($DB->Insert_Query($query)){
		error_msg("에러발생", "back");
	}


	# 기존 자료가 있을경우 삭제
	$query = "SELECT COUNT(IT_NO) FROM $cf_table_img_nm WHERE IT_NO='$my_it_no'";
	$tm_count = $DB->Value($query);

	if($tm_count) {
		$query = "DELETE FROM $cf_table_img_nm WHERE IT_NO='$my_it_no'";
		$DB->Delete_Query($query);
	}

	$query =    "insert into $cf_table_img_nm (" .
						"IT_NO, " .
						"EXT1, " .
						"EXT2, " .
						"EXT3, " .
						"EXT4, " .
						"EXT5, " .
						"EXT6, " .
						"EXT7, " .
						"EXT8, " .
						"EXT9, " .
						"EXT10, " .
						"INPUT_ID, " .
						"INPUT_NM, " .
						"INPUT_IP, " .
						"INPUT_YMDHMS, " .
						"SIGN_ID, " .
						"SIGN_NM, " .
						"SIGN_IP, " .
						"SIGN_YMDHMS" .

					") values (".
						"'$my_it_no', " .
						"'".$tm_file_ext[0]."',".
						"'".$tm_file_ext[1]."',".
						"'".$tm_file_ext[2]."',".
						"'".$tm_file_ext[3]."',".
						"'".$tm_file_ext[4]."',".
						"'".$tm_file_ext[5]."',".
						"'".$tm_file_ext[6]."',".
						"'".$tm_file_ext[7]."',".
						"'".$tm_file_ext[8]."',".
						"'".$tm_file_ext[9]."',".
						"'$tm_input_id', " .
                        "'$tm_input_nm', " .
						"'$tm_input_ip', " .
                        "'$tm_input_ymdhms', " .
                        "'$tm_sign_id', " .
                        "'$tm_sign_nm', " .
						"'$tm_sign_ip', " .
                        "'$tm_sign_ymdhms'" .
					")";

	if($DB->Insert_Query($query)){
		error_msg("에러발생", "back");
	}
	

	// 페이지 이동
	error_msg("", "list.html?$po_basic_query");
?>