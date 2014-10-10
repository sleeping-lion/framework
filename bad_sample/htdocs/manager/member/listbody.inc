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

	// 패스워드 질문을 구한다.
	$query = "SELECT NM FROM $cf_table_cod_nm WHERE CD = '$my_cm_passwd_q'";
	$my_cm_passwd_q_nm = $DB->Value($query);

	// 현재레벨 이름을 구한다.
	$query = "SELECT NM FROM $cf_table_cod_nm WHERE CD = '$my_cm_level'";
	$my_cm_level_nm = $DB->Value($query);

	// 요청레벨 이름을 구한다.
	$query = "SELECT NM FROM $cf_table_cod_nm WHERE CD = '$my_cm_req_level'";
	$my_cm_req_level_nm = $DB->Value($query);

	// 가입경로1을 구한다.
	$query = "SELECT COUNT(NO) FROM CM_MEMBER_ROUTE WHERE CHOICE_V = 1 AND INPUT_ID = '$my_cm_id'";
	$my_route1 = $DB->Value($query);
	if($my_route1>0){
		$route1_checked = "checked";
	}

	// 가입경로2을 구한다.
	$query = "SELECT COUNT(NO) FROM CM_MEMBER_ROUTE WHERE CHOICE_V = 2 AND INPUT_ID = '$my_cm_id'";
	$my_route2 = $DB->Value($query);
	if($my_route2>0){
		$route2_checked = "checked";
	}

	// 가입경로3을 구한다.
	$query = "SELECT COUNT(NO) FROM CM_MEMBER_ROUTE WHERE CHOICE_V = 3 AND INPUT_ID = '$my_cm_id'";
	$my_route3 = $DB->Value($query);
	if($my_route3>0){
		$route3_checked = "checked";
	}

	// 가입경로4을 구한다.
	$query = "SELECT COUNT(NO) FROM CM_MEMBER_ROUTE WHERE CHOICE_V = 4 AND INPUT_ID = '$my_cm_id'";
	$my_route4 = $DB->Value($query);
	if($my_route4>0){
		$route4_checked = "checked";
	}

	// 가입경로5을 구한다.
	$query = "SELECT COUNT(NO) FROM CM_MEMBER_ROUTE WHERE CHOICE_V = 5 AND INPUT_ID = '$my_cm_id'";
	$my_route5 = $DB->Value($query);
	if($my_route5>0){
		$route5_checked = "checked";
	}

	// 가입경로6을 구한다.
	$query = "SELECT COUNT(NO) FROM CM_MEMBER_ROUTE WHERE CHOICE_V = 6 AND INPUT_ID = '$my_cm_id'";
	$my_route6 = $DB->Value($query);
	if($my_route6>0){
		$route6_checked = "checked";
	}

	// 가입경로6 텍스트를 구한다.
	$query = "SELECT ETC_TEXT FROM CM_MEMBER_ROUTE WHERE CHOICE_V = 6 AND INPUT_ID = '$my_cm_id'";
	$my_etc_text = $DB->Value($query);

	$my_cm_mem_nm = get_code_nm($my_cm_mem_cd);

	// ------------------------------------------------------------ //
	//	버튼처리 시작
	// ------------------------------------------------------------ //
	# 리스트 버튼
	$LIST = get_button_href("목록","list.html?".$po_adv_query."&page=".$page);

	# 답변 버튼
	if($cf_reply_level_yn == "Y" && $cf_reply_yn == "Y")
	{
		$REPLY = "";
	}

	# 수정 버튼
	if($cf_modify_level_yn == "Y")
	{
		$MODIFY = get_button_href("수정하기","modifyform.html?".$po_adv_query."&page=".$page."&po_cm_id=".$po_cm_id);
	}

	# 삭제 버튼
	if($cf_delete_level_yn == "Y")
	{
		$DELETE = get_button_href("삭제하기","deleteform.html?".$po_adv_query."&page=".$page."&po_cm_id=".$po_cm_id);
	}
	// ------------------------------------------------------------ //
	//	버튼처리 끝
	// ------------------------------------------------------------ //


	#장바구니로 부터 정보를 가져온다.
	$query2 = "select COUNT(b.IT_NO)  from $cf_table_ord_nm as a, $cf_table_car_nm as b, $cf_table_cre_nm as c where a.ORDER_NO=b.ORDER_NO AND a.ORDER_NO=c.ORDER_NO and b.INPUT_ID='".$my_cm_id."' and a.PROGRESS = '05' ";
	$total_record2 = $DB->Value($query2);

	$query3 = "select b.INPUT_YMDHMS,b.IT_NAME,b.OP_NAME,b.QAT from $cf_table_ord_nm as a, $cf_table_car_nm as b, $cf_table_cre_nm as c where a.ORDER_NO=b.ORDER_NO AND a.ORDER_NO=c.ORDER_NO and b.INPUT_ID='".$my_cm_id."' and a.PROGRESS = '05' ";
			//echo $query3;
			$arr3 = $DB->Pipe_Arr($query3);			
			
			for($k=0; $k < $total_record2 ; $k++){			
				$my_it_name[$k]			= $arr3[$k][IT_NAME];
				$my_qat[$k]			= $arr3[$k][QAT];
				$my_input_text			= substr($arr3[$k][INPUT_YMDHMS],0,4)."-".substr($arr3[$k][INPUT_YMDHMS],4,2)."-".substr($arr3[$k][INPUT_YMDHMS],6,2);
				$my_op_name = $arr3[$k][OP_NAME];				

				if($k==0){
					$order_history_text = $my_input_text." / ".$my_it_name[$k]." / ".$$my_op_name." / 수량 : ".$my_qat[$k]."개";
					
				}else{
					$order_history_text = $order_history_text."<br>".$my_input_text." / ".$my_it_name[$k]." / ".$$my_op_name." / 수량 : ".$my_qat[$k]."개";
				}
			}


	########## 상세보기 출력화일 ##########
	include $cf_skin_nm . "/listbody.inc";
	#######################################

	// 상세보기 하단 리스트 출력
	include "listview.inc";
?>
