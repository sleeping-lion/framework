<?
	// 선택한 게시물의 입력값을 뽑아낸다.
	include "t.inc";

	// 분류
	$my_it_lclass_nm = get_code_nm($my_it_lclass);
	$my_it_mclass_nm = get_code_nm($my_it_mclass);
	$my_it_sclass_nm = get_code_nm($my_it_sclass);

	# 이벤트명
	$my_it_event_cd_nm = get_code_nm($my_it_event_cd);

	# 브랜드명
	$my_it_brand_cd_nm = get_code_nm($my_it_brand_cd);

	foreach($cf_upload_nm as $uk=>$uv) {
		$tm_real_path = "";
		$tm_real_path = $cf_savedir . "/" . $my_no.$cf_upload_nm[$uk].".".$img_arr[$uk];
		$tm_real_path_physical = $cf_doc_root.$tm_real_path;
		if(is_file($tm_real_path_physical)) {
			$tm_file_info_arr = getimagesize($tm_real_path_physical);
			if($tm_file_info_arr[2] > 0 && $tm_file_info_arr[2] < 4) {
				$tm_image_info = get_image_size($tm_real_path_physical, 500);
				$tm_image_[$uk] = "<center><a href='$tm_real_path' target='_blank'><img src='$tm_real_path'" . $tm_image_info[2] . " align='absmiddle'></a></center><br>";
			}
		}
	}

	if(!empty($my_it_gallery)){		
		$arrfile = explode(",",$my_it_gallery);		
		for($i=0;$i<count($arrfile);$i++){
			$my_it_gallery_size = get_image_size($cf_doc_root."/files/shop.1/".$arrfile[$i], 400);
			if($i==0){
				$GALLERY_IMG = "<img src='/files/shop.1/".$arrfile[$i]."' style='width:".$my_it_gallery_size[0]."px;height:".$my_it_gallery_size[1]."px'>";
			}else{
				$GALLERY_IMG .= "<p><img src='/files/shop.1/".$arrfile[$i]."' style='width:".$my_it_gallery_size[0]."px;height:".$my_it_gallery_size[1]."px'>";
			}
		}
	}

	// 글쓴날 처리
	$tm_input_ymdhms = substr($my_input_ymdhms, 0, 4) . "/" .
						substr($my_input_ymdhms, 4, 2) . "/" .
						substr($my_input_ymdhms, 6, 2) . " " .
						substr($my_input_ymdhms, 8, 2) . ":" .
						substr($my_input_ymdhms, 10, 2) . ":" .
						substr($my_input_ymdhms, 12, 2);

	$tm_sell_yn_nm = $my_it_sell_yn == "Y" ? "판매가능" : "판매불가";
	$tm_service_yn_nm = $my_it_service_yn == "Y" ? "공개함" : "공개하지 않음";

	// ------------------------------------------------------------ //
	//	버튼처리 시작
	// ------------------------------------------------------------ //
	# 리스트 버튼
	$LIST = get_button_href("목록","list.html?".$po_adv_query."&page=".$page);


	# 수정 버튼
	if($cf_modify_level_yn == "Y")
	{
		$MODIFY = get_button_href("수정하기","modifyform.html?".$po_adv_query."&page=".$page."&po_no=".$po_no);
	}

	# 삭제 버튼
	if($cf_delete_level_yn == "Y")
	{
		$DELETE = get_button_href("삭제하기","deleteform.html?".$po_basic_query."&po_no=".$po_no);
	}
	// ------------------------------------------------------------ //
	//	버튼처리 끝
	// ------------------------------------------------------------ //

	########## 상세보기 출력화일 ##########
	include $cf_skin_nm . "/listbody.inc";
	#######################################

	// 상세보기 하단 리스트 출력

	switch($cf_board_cd)
	{
		case "ba_100" :		// 리스트형
			include "listview.inc";
			break;

		case "ba_200" :		// 패밀리형
			include "flistview.inc";
			break;
		
		case "ba_300" :		// 공지형
			include "list_bottom.inc";
			break;

		default :			// 선택하지 않은경우 출력없음
			break;
	}
?>
