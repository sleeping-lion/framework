<?
	// 선택한 게시물의 입력값을 뽑아낸다.
	include "t.inc";


	

	// 글쓴날 처리
	$tm_input_ymdhms = substr($my_input_ymdhms, 0, 4) . "/" .
						substr($my_input_ymdhms, 4, 2) . "/" .
						substr($my_input_ymdhms, 6, 2) . " " .
						substr($my_input_ymdhms, 8, 2) . ":" .
						substr($my_input_ymdhms, 10, 2) . ":" .
						substr($my_input_ymdhms, 12, 2);

	// ------------------------------------------------------------ //
	//	버튼처리 시작
	// ------------------------------------------------------------ //
	# 리스트 버튼
	//$LIST = "<a href=\"list.html?$po_adv_query&page=$page\" onMouseOver=\"status='reload articles';return true;\" onMouseOut=\"status=''\"><img src=\"$cf_images_dir/list.gif\" align='absmiddle'></a>";
	$LIST = get_button_href("목록","list.html?".$po_basic_query."&po_gb=".$po_gb."&po_cd=".$po_cd."&page=".$page);


	# 수정 버튼
	if($cf_modify_level_yn == "Y")
	{
		//$MODIFY = "<a href=\"modifyform.html?$po_adv_query&page=$page&po_no=$po_no\" onMouseOver=\"status='modify this article';return true;\" onMouseOut=\"status=''\"\"><img src=\"$cf_images_dir/modify.gif\" border=0 align='absmiddle'></a>";
		$MODIFY = get_button_href("수정하기","modifyform.html?".$po_adv_query."&po_gb=".$po_gb."&po_cd=".$po_cd."&page=".$page);
	}

	# 삭제 버튼
	if($cf_delete_level_yn == "Y")
	{
		//$DELETE = "<img src=\"$cf_images_dir/delete.gif\" border=0 align='absmiddle' onClick=del_ok('delete.html?$po_basic_query&po_no=$po_no') style='cursor:hand'>";
		$DELETE = get_button_href("삭제하기","deleteform.html?".$po_adv_query."&po_gb=".$po_gb."&po_cd=".$po_cd."&page=".$page);
	}
	// ------------------------------------------------------------ //
	//	버튼처리 끝
	// ------------------------------------------------------------ //

	########## 상세보기 출력화일 ##########
	include $cf_skin_nm . "/listbody.inc";
	#######################################

?>
