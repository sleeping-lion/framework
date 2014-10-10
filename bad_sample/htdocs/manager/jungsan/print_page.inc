<?
	# 패스 및 클래스
	include $_SERVER[DOCUMENT_ROOT]."/Root_Path.inc";
	include "variable_config.inc";

	# DB 접속 및 함수
	include "logon.inc";
	include "user_function.inc";

	# 변수 및 설정
	include "config.inc";
	include "t_config.inc";

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


?>
<link href="/css/manager.css" rel="stylesheet" type="text/css">
<link href="/css/project.css" rel="stylesheet" type="text/css">
<object id=factory style="display:none;" classid="clsid:1663ed61-23eb-11d2-b92f-008048fdd814" viewastext codebase="/images/ScriptX.cab#Version=6,1,429,14"></object>

<? 
   include "t.inc";
   $cf_table_wd_large="100%";

?>
   <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
      <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
        <tr>
          <td colspan='4' align='center' class="table_menu"><b>주문정보</b></td> 
        </tr>	
        <tr>
          <td width='20%' align='center' class="table_body_menu">주문번호</td>
          <td width='30%' class="table_body_text"><font color="#FF6600"><b><?=$my_order_no?></b></font></td>
          <td  width="20%" align="center" class="table_body_menu">주문자아이디</td>
          <td class="table_body_text"><?=$my_input_id?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">주문일시</td>
          <td class="table_body_text" colspan="3"><?=substr($my_sign_ymdhms,0,4)?>년 <?=substr($my_sign_ymdhms,4,2)?>월 <?=substr($my_sign_ymdhms,6,2)?>일 <?=substr($my_sign_ymdhms,8,2)?>시 <?=substr($my_sign_ymdhms,10,2)?>분</td>
        </tr>
      </table>
    </td>
  </tr>
</table>

<br>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
      <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
        <tr>
          <td colspan='4' align='center' class="table_menu"><b>구매자 정보</b></td> 
        </tr>	
        <tr>
          <td width='20%' align='center' class="table_body_menu">주문자명</td>
          <td width='30%' class="table_body_text"><font color="#FF6600"><b><?=$my_sen_name?></b></font></td>
          <td  width="20%" align="center" class="table_body_menu">주문자우편번호</td>
          <td class="table_body_text"><?=$my_sen_zip?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">주소</td>
          <td class="table_body_text" colspan="3">
		  <?=$my_sen_addr?>
		  </td>
        </tr>
		<tr>
          <td align="center" class="table_body_menu">전화번호</td>
          <td class="table_body_text">
		  <?=$my_sen_tel?>
		  </td>
		  <td align="center" class="table_body_menu">핸드폰번호</td>
          <td class="table_body_text">
		  <?=$my_sen_hp_tel?>
		  </td>
        </tr>
		<tr>
          <td align="center" class="table_body_menu">이메일</td>
          <td class="table_body_text" colspan="3">
		  <?=$my_sen_email?>
		  </td>
        </tr>
      </table>
    </td>
  </tr>
</table>

<br>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
      <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
        <tr>
          <td colspan='4' align='center' class="table_menu"><b>수령인 정보</b></td> 
        </tr>	
        <tr>
          <td width='20%' align='center' class="table_body_menu">수령인 이름</td>
          <td width='30%' class="table_body_text"><font color="#FF6600"><b><?=$my_rec_name?></b></font></td>
          <td  width="20%" align="center" class="table_body_menu">수령지우편번호</td>
          <td class="table_body_text"><?=$my_rec_zip?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">수령지주소</td>
          <td class="table_body_text" colspan="3">
		  <?=$my_rec_addr?>
		  </td>
        </tr>
		<tr>
          <td align="center" class="table_body_menu">수신인 전화번호</td>
          <td class="table_body_text">
		  <?=$my_rec_tel?>
		  </td>
		  <td align="center" class="table_body_menu">수신인 핸드폰번호</td>
          <td class="table_body_text">
		  <?=$my_rec_hp_tel?>
		  </td>
        </tr>
		<tr>
          <td align="center" class="table_body_menu">하고싶은말</td>
          <td class="table_body_text" colspan="3">
		  <?=$my_memo?>
		  </td>
        </tr>
<?if($my_after_memo) {?>
		<tr>
          <td align="center" class="table_body_menu"><font color="red">주문후 하고싶은말</font></td>
          <td class="table_body_text" colspan="3">
		  <?=$my_after_memo?>
		  </td>
        </tr>
<?}?>
      </table>
    </td>
  </tr>
</table>

<br>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
      <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
        <tr>
          <td colspan='4' align='center' class="table_menu"><b>결제 정보</b></td> 
        </tr>	
        <tr>
          <td width='20%' align='center' class="table_body_menu">총구매액 </td>
          <td width='30%' class="table_body_text"><font color="#FF6600"><b><?=$tm_amount?></b></font></td>
          <td  width="20%" align="center" class="table_body_menu">총결제액</td>
          <td class="table_body_text"><?=$tm_re_amount?>
            
            <?  #포인트 사용금액
              if($my_mileage && $my_mileage > 0){
                echo "(".$my_mileage." point 사용)";
              }
            ?>
            
          </td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">결제방법</td>
          <td class="table_body_text">
		  <?=$tm_settlemetn_nm?>
		  </td>
		  <td align="center" class="table_body_menu">결제결과</td>
          <td class="table_body_text">
		  <?=$tm_response_code_nm?>
		  </td>
        </tr>

		<tr>
          <td align="center" class="table_body_menu">승인번호</td>
          <td class="table_body_text">
		  <?=$my_auth_no?>
		  </td>
		  <td align="center" class="table_body_menu">승인일자</td>
          <td class="table_body_text">
		  <?=$my_auth_date?>
		  </td>
        </tr>
<?if($my_settlement_cd == "20") { // 무통장
	$query = "SELECT CON_CD, BIGO,NM FROM $cf_table_cod_nm WHERE CD = '$my_card_cd'";
	$bank_arr = $DB->Row($query);
	$my_bank_master = $bank_arr[0];
	$my_bank_cd = $bank_arr[1];
	$my_bank_nm = $bank_arr[2];

?>
		<tr>
          <td align="center" class="table_body_menu">예금주</td>
          <td class="table_body_text">
		  <?=$my_bank_master?>
		  </td>
		  <td align="center" class="table_body_menu">계좌번호</td>
          <td class="table_body_text">
		  <?=$my_bank_cd?> (<?=$my_bank_nm?>)
		  </td>
        </tr>
		<tr>
          <td align="center" class="table_body_menu">입금자</td>
          <td class="table_body_text">
		  <?=$my_pay_name?>
		  </td>
		  <td align="center" class="table_body_menu">결제상황</td>
          <td class="table_body_text">
			<?if($my_receipt_cd == "10") {?>
			미입금
			</select>
			<?} else {
				echo "입금완료";
			}?>
		  </td>
        </tr>
<?}?>
		<tr>
          <td align="center" class="table_body_menu">배송비</td>
          <td class="table_body_text">
		  <?=$tm_sending_charge?>
		  </td>
		  <td align="center" class="table_body_menu">부과세금액</td>
          <td class="table_body_text">
		  <?=$tm_tex?>
		  </td>
    </tr>
    <!-- // 영수증 여부 //-->

    <tr>
      <td align='center' class="table_body_menu">영수증 여부</td>
      <td class="table_body_text" colspan='3'><font color="#FF6600"><b>
      <?
      if($my_tex_yn == "Y"){ echo "세금계산서 발행 요청"; }
      if($my_money_yn == "Y"){ echo "현금영수증 발행 요청"; }
      ?>
      </b>
      </td>
<!-- 		<tr>
          <td align="center" class="table_body_menu">할인금액</td>
          <td class="table_body_text">
		  <?=number_format($my_per)?>
		  </td>
		  <td align="center" class="table_body_menu"></td>
          <td class="table_body_text">
		  
		  </td>
        </tr> -->
      </table>
    </td>
  </tr>
</table>

<br>


<!-- // 070701 mir9 세금계산서 //-->
<?  if($my_tex_yn == "Y"){	?>
<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
      <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
        <tr>
          <td colspan='4' align='center' class="table_menu"><b>세금계산서 정보</b></td> 
        </tr>	
        <tr>
          <td width='20%' align='center' class="table_body_menu">업체명</td>
          <td width='30%' class="table_body_text"><font color="#FF6600"><b><?=$my_nm?></b></font></td>
          <td  width="20%" align="center" class="table_body_menu">사업자번호</td>
          <td class="table_body_text"><?=$my_reg_no?></td>
        </tr>

        <tr>
          <td align="center" class="table_body_menu">대표자</td>
          <td class="table_body_text" colspan="3">
		  <?=$my_bos_nm?>
		  </td>
        </tr>
		<tr>
          <td align="center" class="table_body_menu">업태</td>
          <td class="table_body_text">
		  <?=$my_upjong?>
		  </td>
		  <td align="center" class="table_body_menu">종목</td>
          <td class="table_body_text">
		  <?=$my_jongmok?>
		  </td>
        </tr>
		<tr>
          <td align="center" class="table_body_menu">주소</td>
          <td class="table_body_text" colspan="3">
		  <?=$my_addr?>
		  </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<br>
<? }	?>
<!-- // 세금계산서 끝		   //-->



<?if(($my_settlement_cd == "20" && $my_receipt_cd == "20") || $my_settlement_cd == "10") {?>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
      <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
        <tr>
          <td colspan='4' align='center' class="table_menu"><b>상태 정보</b></td> 
        </tr>	
        <tr>
          <td width='20%' align='center' class="table_body_menu">상태 </td>
          <td width='30%' class="table_body_text">
		  <? switch($my_progress){
				case "20" : echo "결제요청"; break;
				case "50" : echo "배송신청"; break;
				case "60" : echo "배송중"; break;
				case "70" : echo "배송완료"; break;
				case "80" : echo "반송"; break;
				case "100" : echo "완결"; break;
				case "120" : echo "환불"; break;

			}
		  ?>
		  </td>
          <td  width="20%" align="center" class="table_body_menu">수정자</td>
          <td class="table_body_text"><?=$my_writer?></td>
        </tr>
        <tr>
          <td colspan="4" align='left'>
          * 배송완료 및 완결시에 물품 적립금 추가.
          * 배송완료 및 완결 후에 환불시만 적립금 삭제.(환불은 신중히)
          </td>
      </table>
    </td>
  </tr>
</table>

<br>
<?}?>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
      <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
        <tr>
          <td  align='center' class="table_menu"><b>주문상품 정보</b></td> 
        </tr>	
        <tr>
          <td>
		  
<?
#장바구니로 부터 정보를 가져온다.
$query = "select COUNT(IT_NO)  from " . $cf_table_car_nm . " where ORDER_NO='$po_no' ";
$total_record = $DB->Value($query);

$query = "select SEQ,IT_NO,IT_NAME,IT_PRICE, IT_SALE_PRICE,QAT,TAK_NAME,TAK_NO,OP_NAME,OP_PRICE  from " . $cf_table_car_nm . " where ORDER_NO='$po_no' ";
$arr = $DB->Pipe_Arr($query);

for($i=0; $i < $total_record ; $i++){

	$my_it_no[$i]			= $arr[$i][IT_NO];
	$my_it_name[$i]			= $arr[$i][IT_NAME];
	$my_it_price[$i]		= $arr[$i][IT_PRICE];
	$my_it_sale_price[$i]	= $arr[$i][IT_SALE_PRICE];
	$my_op_name[$i]	= $arr[$i][OP_NAME];
	$my_op_price[$i]	= $arr[$i][OP_PRICE];
	$my_qat[$i]				= $arr[$i][QAT];

    $my_it_seq[$i]			= $arr[$i][SEQ];
    $my_it_tak_name[$i]		= $arr[$i][TAK_NAME];
    $my_it_tak_no[$i]		= $arr[$i][TAK_NO];

}

?>
						<table width='99%' border='0' cellspacing='1' cellpadding='3' bgcolor='#40659B' align="center">
							
							<tr align='center' bgcolor='#7FA1D0'>
								<td width='20%'><font color="#ffffff">상품명</font></td>
								<td width='15%'><font color="#ffffff">옵 &nbsp;션</font></td>
								<td width='8%' align='center'><font color="#ffffff">가격</font></td>
								<td width='7%'><font color="#ffffff">수량</font></td>
								<td width='10%'><font color="#ffffff">소계</font></td>
							</tr>
<?
for ($t=0; $t < sizeof($my_it_no); $t++) {
	$tm_sell_price[$t] = $my_it_sale_price[$t] ? $my_it_sale_price[$t] : $my_it_price[$t];
	$tm_sell_price[$t] = $my_op_price[$t] ? $my_op_price[$t] : $tm_sell_price[$t];

//	$tm_total_price = $my_it_price[$t] * $my_qat[$t];
	$tm_total_price = $tm_sell_price[$t] * $my_qat[$t];
	$tm_total_amount = $tm_total_amount +  $tm_total_price;    // 총결제금액
	$tm_total_price = number_format($tm_total_price);   //상품별 총금액
	$tm_it_price = number_format($tm_it_price);  //상품별 총금액 출력포맷

	$my_seq = $my_it_seq[$t];
	

?>	
				  <tr align='right' bgcolor='#FFFFFF'>
					<td><?=$my_it_name[$t]?></td>
					<td><?=$my_op_name[$t]?></td>
					<td><?=$tm_sell_price[$t]?></td>
					<td><?=$my_qat[$t]?></td>
					<td><?=$tm_total_price?></td>
				  </tr>

<?
}
?> 

			  <tr >
               <td bgcolor='#7FA1D0' colspan="4" align="right"><font color="#ffffff">총주문액</font></td>
               <td bgcolor='#FFFFFF' align="right"><!-- <?=number_format($tm_total_amount)?> --><?=$tm_amount?></td>
              </tr>  
           	</table>
		  
		  </td>
        </tr>
      </table>
    </td>
  </tr>
</table>

<br>


<script>

function putSettings(type,lm,rm,tm,bm) 
{ 
	with(factory.printing)
	{
		header = ''; // 머릿말
		footer = ''; // 꼬릿말
		portrait = type; // true이면 세로 인쇄, false이면 가로 인쇄.
		leftMargin = lm; // 왼쪽 여백
		rightMargin = rm; // 오른쪽 여백
		topMargin = tm; // 윗쪽 여백
		bottomMargin = bm; // 아랫쪽 여백
	}
}



function doPrint(frame)
{
	putSettings(true,0,0,0.4,0);
	//factory.printing.Print(true, frame);
	window.print();
	//window.close();
}

doPrint(window);
</script>

