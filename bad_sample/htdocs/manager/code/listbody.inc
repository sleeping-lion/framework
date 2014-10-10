<?
	// 선택한 게시물의 입력값을 뽑아낸다.
	include "t.inc";

	// 구분코드명을 구한다.
	$query = "SELECT NM FROM $cf_table_cod_nm WHERE CD = '$my_gb'";
	$my_gb_nm = $DB->Value($query);

	// 글쓴날 처리
	$tm_input_ymdhms = substr($my_input_ymdhms, 0, 4) . "/" .
						substr($my_input_ymdhms, 4, 2) . "/" .
						substr($my_input_ymdhms, 6, 2) . " " .
						substr($my_input_ymdhms, 8, 2) . ":" .
						substr($my_input_ymdhms, 10, 2) . ":" .
						substr($my_input_ymdhms, 12, 2);

	// 수정날 처리
	$tm_sign_ymdhms = substr($my_sign_ymdhms, 0, 4) . "/" .
						substr($my_sign_ymdhms, 4, 2) . "/" .
						substr($my_sign_ymdhms, 6, 2) . " " .
						substr($my_sign_ymdhms, 8, 2) . ":" .
						substr($my_sign_ymdhms, 10, 2) . ":" .
						substr($my_sign_ymdhms, 12, 2);

	# ------------------------------------------------------------ #
	#	버튼처리 시작
	# ----------------------------------------------------------- #
	// 리스트 버튼
	$LIST = "<a href=\"list.html?$po_adv_query&po_gb=$po_gb&po_cd=$po_cd&page=$page\" onMouseOver=\"status='reload articles';return true;\" onMouseOut=\"status=''\"><img src=\"$cf_images_dir/list.gif\" align='absmiddle'></a>";

	// 답변 버튼
	if($cf_reply_level_yn == "Y" && $cf_reply_yn == "Y")
	{
		$REPLY = "<a href=\"replyform.html?$po_adv_query&po_gb=$po_gb&po_cd=$po_cd&page=$page\" onMouseOver=\"status='reply to this article'; return true;\" onMouseOut=\"status=''\"\"><img src=\"$cf_images_dir/reply.gif\" border=0></a>";
	}

	// 수정 버튼
	if($cf_modify_level_yn == "Y")
	{
		$MODIFY = "<a href=\"modifyform.html?$po_adv_query&po_gb=$po_gb&po_cd=$po_cd&page=$page\" onMouseOver=\"status='modify this article';return true;\" onMouseOut=\"status=''\"\"><img src=\"$cf_images_dir/modify.gif\" border=0></a>";
	}

	// 삭제 버튼
	if($cf_delete_level_yn == "Y")
	{
		$DELETE = "<a href=\"deleteform.html?$po_adv_query&po_gb=$po_gb&po_cd=$po_cd&page=$page\" onMouseOver=\"status='delete this article';return true;\" onMouseOut=\"status=''\"\"><img src=\"$cf_images_dir/delete.gif\" border=0></a>";
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
