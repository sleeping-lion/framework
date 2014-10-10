<?php
	// 선택한 게시물의 입력값을 뽑아낸다.
	include "t.inc";

	# 권한체크
	if($my_gb == "admin" && $cf_cook_level != "aa")
	{
		error_msg("존재하지 않는 페이지입니다. 주소를 정확히 체크해주세요.!", "back");
	}

	// 프로그램 접속 URL
	$tm_program_url = $my_path_url . "/list.html?a_gb=" . $my_gb . "&a_cd=" . $my_cd . "&a_item=" . $my_item;

	# ------------------------------------------------------------ #
	#	버튼처리 시작
	# ----------------------------------------------------------- #
	// 리스트 버튼
	//$LIST = "<a href=\"list.html?$po_adv_query&gb=$gb&cd=$cd&item=$item&page=$page\" onMouseOver=\"status='reload articles';return true;\" onMouseOut=\"status=''\"><img src=\"$cf_images_dir/list.gif\" valign='absmiddle'></a>";
	$LIST = get_button_href("목록","list.html?".$po_adv_query."&gb=".$gb."&cd=".$cd."&item=".$item."&page=".$page);


	// 수정 버튼
	if($cf_modify_level_yn == "Y")
	{
		//$MODIFY = "<a href=\"modifyform.html?$po_adv_query&gb=$gb&cd=$cd&item=$item&page=$page\" onMouseOver=\"status='modify this article';return true;\" onMouseOut=\"status=''\"\"><img src=\"$cf_images_dir/modify.gif\" valign='absmiddle'></a>";
		$MODIFY = get_button_href("수정하기","modifyform.html?".$po_adv_query."&gb=".$gb."&cd=".$cd."&item=".$item."&page=".$page);
	}

	// 삭제 버튼
	if($cf_delete_level_yn == "Y")
	{
		//$DELETE = "<a href=\"deleteform.html?$po_adv_query&gb=$gb&cd=$cd&item=$item&page=$page\" onMouseOver=\"status='delete this article';return true;\" onMouseOut=\"status=''\"\"><img src=\"$cf_images_dir/delete.gif\" valign='absmiddle'></a>";
		$DELETE = get_button_href("삭제하기","deleteform.html?".$po_adv_query."&gb=".$gb."&cd=".$cd."&item=".$item."&page=".$page);
	}
	# ------------------------------------------------------------ #
	#	버튼처리 끝
	# ------------------------------------------------------------ #

	########## 상세보기 출력화일 ##########
	include "html/listbody.inc";
	#######################################

	// 상세보기 하단 리스트 출력
	include "listview.inc";
?>
