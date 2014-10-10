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


	// 이스케이프
	$fr_it_name = escape_string($fr_it_name);
	$fr_it_company = escape_string($fr_it_company);
	$fr_it_memo = escape_string($fr_it_memo);
	$fr_it_etc = escape_string($fr_it_etc);

	# 상품 조회수
	$tm_it_ver_cnt = 0;

	if(!$fr_it_pos) $fr_it_pos = 999999;

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
	$query =  "insert into $cf_table_col_nm (" .
            "NO, " .
            "IT_LCLASS, " .
            "IT_MCLASS, " .
            "IT_SCLASS, " .
            "IT_NO, " .
            "IT_MODEL_NO, " .
            "IT_NAME, " .
            "IT_EVENT_CD, " .
            "IT_BRAND_CD, " .
            "IT_COMPANY, " .
            "IT_CNT, " .
            //금액
						"IT_PRICE, " .
						"IT_PRICE1, " .
						"IT_PRICE2, " .
						//할인금액
            "IT_SALE_PRICE, " .
            "IT_SALE_PRICE1, " .
            "IT_SALE_PRICE2, " .
            "IT_SALE_PER, " .
						//적립금액
            "IT_SAVE_PRICE, " .
            "IT_SAVE_PRICE1, " .
						"IT_SAVE_PRICE2, " .
						"IT_SAVE_PER, " .

            "IT_PRICE_UNIT, " .
            "IT_ETC, " .

						//관련상품
						"IT_FRIEND, " .
						//옵션상품
						"IT_OPTION, " .
						"IT_OPTION1, " .
						"IT_OPTION2, " .

            "IT_POS, " .
            "IT_MEMO, " .
            "IT_VER_CNT, " .
            "IT_SELL_YN, " .
            "IT_SERVICE_YN, " .
            "INPUT_ID, " .
            "INPUT_NM, " .
            "INPUT_IP, " .
            "INPUT_YMDHMS, " .
            "SIGN_ID, " .
            "SIGN_NM, " .
            "SIGN_IP, " .
            "SIGN_YMDHMS, " .

            #무료배송비 추가 070628 mir9
            "BASONG_YN" .

            ") values (" .

            "'$my_no', " .
            "'$fr_it_lclass', " .
            "'$fr_it_mclass', " .
            "'$fr_it_sclass', " .
            "'$my_it_no', " .
            "'$fr_it_model_no', " .
            "'$fr_it_name', " .
            "'$fr_it_event_cd', " .
            "'$fr_it_brand_cd', " .
            "'$fr_it_company', " .
            "'$fr_it_cnt', " .
						//금액
						"'$fr_it_price', " .
            "'$fr_it_price1', " .
            "'$fr_it_price2', " .
						//할인금액
            "'$fr_it_sale_price', " .
            "'$fr_it_sale_price1', " .
            "'$fr_it_sale_price2', " .
            "'$fr_it_sale_per', " .
            //적립금액
						"'$fr_it_save_price', " .
            "'$fr_it_save_price1', " .
						"'$fr_it_save_price2', " .
						"'$fr_it_save_per', " .

            "'$fr_it_price_unit', " .
            "'$fr_it_etc', " .

						//관련상품
						"'$fr_friend_value', " .
						//옵션상품
						"'$fr_option_value', " .
						"'$fr_option1_value', " .
						"'$fr_option2_value', " .

            "'$fr_it_pos', " .
            "'$fr_it_memo', " .
            "'$tm_it_ver_cnt', " .
            "'$fr_it_sell_yn', " .
            "'$fr_it_service_yn', " .
            "'$tm_input_id', " .
            "'$tm_input_nm', " .
            "'$tm_input_ip', " .
            "'$tm_input_ymdhms', " .
            "'$tm_sign_id', " .
            "'$tm_sign_nm', " .
            "'$tm_sign_ip', " .
            "'$tm_sign_ymdhms', " .
            #무료배송비 추가 070628 mir9
            "'$fr_basong_yn'" .
            ")";

  if($DB->Insert_Query($query)){
  error_msg("에러발생", "back");
  }


  # 기존 자료가 있을경우 삭제
  $query = "SELECT COUNT(IT_NO) FROM OPTION_IMG WHERE IT_NO='$my_it_no'";
  $tm_count = $DB->Value($query);

  if($tm_count) {
  $query = "DELETE FROM OPTION_IMG WHERE IT_NO='$my_it_no'";
  $DB->Delete_Query($query);
  }

  $query =    "insert into OPTION_IMG (" .
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