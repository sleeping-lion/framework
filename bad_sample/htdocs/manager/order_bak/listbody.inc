<?

	// 선택한 게시물의 입력값을 뽑아낸다.
	include "t.inc";

	#결재테이블에서 금액정보를 가져온다.
	$query = "select AUTH_NO,SETTLEMENT_CD, RECEIPT_CD,AMOUNT, RE_AMOUNT, MILEAGE, MILEAGE_POINT, CARD_CD, SENDING_CHARGE, TEX, AUTH_DATE,RESPONSE_CODE, CHECK_YN,PAY_NAME,PER, TEX_YN, MONEY_YN  from " . $cf_table_cre_nm . " where ORDER_NO ='$po_no'";
	$arr = $DB->Pipe_Row($query);

	$my_auth_no					= $arr[AUTH_NO]; #승인번호
	$my_settlement_cd			= $arr[SETTLEMENT_CD]; #결제방법
	$my_receipt_cd				= $arr[RECEIPT_CD]; #입금확인
	$my_amount					= $arr[AMOUNT]; #구매액
	$my_re_amount				= $arr[RE_AMOUNT]; #실제결제금액
  $my_mileage         = $arr[MILEAGE];    #마일리지
	$my_mileage_point			= $arr[MILEAGE_POINT];    #남은 마일리지
	$my_sending_charge			= $arr[SENDING_CHARGE]; #배송요금
	$my_card_cd					= $arr[CARD_CD];	# 통장종류
	$my_tex						= $arr[TEX]; //세금
	$my_auth_date				= $arr[AUTH_DATE]; #승인일자
	$my_response_code			= $arr[RESPONSE_CODE]; #결제결과코드
	$my_check_yn				= $arr[CHECK_YN];
	$my_pay_name				= $arr[PAY_NAME];	# 입금자
	$my_per						= $arr[PER];		# 할인율 적용

  #070702 mir9 세금계산서발행용 출력 검색시 TEX,TEX_NO추가
	$my_tex_yn					= $arr[TEX_YN];	#세금계산서 발행여부
	
  ### 070709 mir9 현금영수증 발행 여부
  $my_money_yn        = $arr[MONEY_YN];

	#세금계산서 발행했으면 정보가져옴(MT_ACCOUT_T)
	if($my_tex_yn == "Y"){
		$query_tex = "select * from MT_ACCOUT_T where ORDER_NO ='$po_no'";
		$arr_tex = $DB->Pipe_Row($query_tex);
			
			$my_reg_no = $arr_tex[AC_REG_NO];	#사업자
			$my_nm = $arr_tex[AC_NM];			#업체
			$my_bos_nm = $arr_tex[AC_BOS_NM];	#대표자명
			$my_addr  = $arr_tex[AC_ADDR];		#주소
			$my_upjong = $arr_tex[AC_UPJONG];	#업종
			$my_jongmok = $arr_tex[AC_JONGMOK];	#종목
	}



	switch($my_settlement_cd){#결제방법
		case ("10"):
			$tm_settlemetn_nm = "카드";
		break;
		case ("20"):
			$tm_settlemetn_nm = "무통장";
		break;
		case ("30"):
			$tm_settlemetn_nm = "자동이체";
		break;
		default:
			$tm_settlemetn_nm = "미결제";
		break;
	}

  #마일리지 확인
    if($my_amount > 0 && $my_mileage && $my_mileage > 0){
			$tm_settlemetn_nm = "적립금&". $tm_settlemetn_nm ;
    }else if($my_mileage && $my_mileage > 0){
      $tm_settlemetn_nm = "적립금";
    }



	switch ($my_response_code) {
		case ("00"):
			$tm_response_code_nm = "정상처리";
		break;
		default:
			$tm_response_code_nm = "처리오류";
		break;
	}

	##################
	// 입금확인
	switch ($my_receipt_cd) {
		case ("10"):
			$tm_receipt_nm = "미확인";
		break;
		case ("20"):
			$tm_receipt_nm = "입금완료";
		break;
		case ("30"):
			$tm_receipt_nm = "미입금";
		break;
		case ("40"):
			$tm_receipt_nm = "부분입금";
		break;
		
		default:
			$tm_receipt_nm = "미확인";
		break;
		
	}

	$tm_tex = number_format($my_tex);			#세금
	$tm_amount = number_format($my_amount);	#구매금액
	$tm_re_amount = number_format($my_re_amount);	#실구매금액
	$tm_sending_charge = number_format($my_sending_charge);	#배송요금


	# ------------------------------------------------------------ #
	#	버튼처리 시작
	# ----------------------------------------------------------- #
	// 리스트 버튼
	//$LIST = "<a href=\"list.html?$po_adv_query&gb=$gb&cd=$cd&item=$item&page=$page\" onMouseOver=\"status='reload articles';return true;\" onMouseOut=\"status=''\"><img src=\"$cf_images_dir/list.gif\" valign='absmiddle'></a>";
	$LIST = get_button_href("목록","list.html?".$po_adv_query."&gb=".$gb."&cd=".$cd."&item=".$item."&page=".$page);


	// 수정 버튼
	if($cf_modify_level_yn == "Y")
	{
		$MODIFY = get_button_href("수정하기","","submit");
	}

	// 삭제 버튼
	if($cf_delete_level_yn == "Y")
	{
		$url = "delete.html?".$po_adv_query."&po_no=".$po_no."&page=".$page;
		$DELETE = get_button_href("삭제하기","","","onclick=\"DelConfirm('$url')\";");
	}
	# ------------------------------------------------------------ #
	#	버튼처리 끝
	# ------------------------------------------------------------ #
?>
	<form name="singform" method="post" action="modify.html?<?=$po_adv_query?>&po_no=<?=$po_no?>&page=<?=$page?>">
<?
	
	########## 상세보기 출력화일 ##########
	include "html/listbody.inc";
	#######################################
?>
	</form>
<?
	// 상세보기 하단 리스트 출력
	include "listview.inc";
?>
