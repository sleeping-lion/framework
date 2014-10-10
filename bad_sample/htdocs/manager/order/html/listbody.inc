<input type="hidden" name="old_progress" value="<?=$my_progress?>">
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
		  <?if($tm_settlemetn_nm!="무통장"){?><?=$tm_response_code_nm?><?}?>
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
	$query = "SELECT ES_BANK_CD, ES_BANK_NO,ES_DATE,ES_BANK_NM,ES_NM FROM $cf_table_cre_nm WHERE CREDIT_NO = '$my_credit_no'";
	$bank_arr = $DB->Row($query);
	$my_es_bank_cd = $bank_arr[0];
	$my_es_bank_no = $bank_arr[1];
	$my_es_date = $bank_arr[2];
	$my_es_bank_nm = $bank_arr[3];
	$my_es_nm = $bank_arr[4];

?>
		<tr>
          <td align="center" class="table_body_menu">예금주</td>
          <td class="table_body_text">
		  <?=$my_es_bank_nm?>
		  </td>
		  <td align="center" class="table_body_menu">계좌번호</td>
          <td class="table_body_text">
		  <!-- <?=$my_es_bank_no?> (<?=get_bank_nm($my_es_bank_cd)?>) -->농협 301-0135-0123-91
		  </td>
        </tr>
		<tr>
          <td align="center" class="table_body_menu">입금자</td>
          <td class="table_body_text">
		  <?=$my_bank_name?>
		  </td>
		  <td align="center" class="table_body_menu">결제상황</td>
          <td class="table_body_text">
			<?if($my_receipt_cd == "10") {?>
			<select name="fr_receipt_cd">
				<option value="10">미입금</option>
				<option value="20">입금확인</option>
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

    <!-- <tr>
      <td align='center' class="table_body_menu">영수증 여부</td>
      <td class="table_body_text" colspan='3' class="table_line">

		<?if($my_receipt_chk=="1" || $my_receipt_chk=="2"){?>
			발급승인 : <input type="radio" name="fr_apply_paper" value="Y" <?if($my_apply_paper=="Y"){?>checked<?}?>>&nbsp;&nbsp;발급미승인 : <input type="radio" name="fr_apply_paper" value="N" <?if($my_apply_paper!="Y"){?>checked<?}?>>
		<?}?>

		<?if($my_receipt_chk=="1"){?>
			<table border="1" cellspacing="0" cellpadding="1" bordercolor="#F3F3F3">
				<tr>
					<td colspan="2">세금계산서 요청</td>
				</tr>
				<tr>
					<td>상호</td>
					<td><?=$rb_name?></td>
				</tr>
				<tr>
					<td>대표명</td>
					<td><?=$rb_ceo?></td>
				</tr>
				<tr>
					<td>사업자번호</td>
					<td><?=substr($rb_num,0,3)?>-<?=substr($rb_num,3,2)?>-<?=substr($rb_num,5,5)?></td>
				</tr>
				<tr>
					<td>업태</td>
					<td><?=$rb_upte?></td>
				</tr>
				<tr>
					<td>종목</td>
					<td><?=$rb_jongmok?></td>
				</tr>
				<tr>
					<td>주소</td>
					<td><?=substr($rb_zip,0,3)?>-<?=substr($rb_zip,3,3)?> <?=$rb_addr1?> <?=$rb_addr2?></td>
				</tr>
			</table>
        <?}elseif($my_receipt_chk=="2"){?>
			<table border="1" cellspacing="0" cellpadding="1" bordercolor="#F3F3F3">
				<tr>
					<td colspan="2">현금영수증 요청</td>
				</tr>
				<tr>
					<td>영수증용 휴대폰번호</td>
					<td><?=$my_receipt_info?></td>
				</tr>
				<tr>
					<td>승인번호</td>
					<td><input type="text" name="fr_app_no" value="<?=$my_app_no?>"></td>
				</tr>
				<tr>
					<td>처리</td>
					<td>
					<?if($my_app_status=="1" && $my_app_no){?>
						발급
					<?}elseif($my_app_status!="1" && $my_app_no){?>
						대기
					<?}else{?>
						승인전
					<?}?>
					</td>
				</tr>
			</table>
		<?}else{?>
		<?}?> -->
      </td>
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



<?//if(($my_settlement_cd == "20" && $my_receipt_cd == "20") || $my_settlement_cd == "10") {?>

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
		  <select name="fr_progress">
			<!-- <option value="20" <?if($my_progress == "20"){echo "selected";}?>>결제요청</option>
			<option value="50" <?if($my_progress == "50"){echo "selected";}?>>배송신청</option>
			<option value="60" <?if($my_progress == "60"){echo "selected";}?>>배송중</option>
			<option value="70" <?if($my_progress == "70"){echo "selected";}?>>배송완료</option>
			<option value="20" <?if($my_progress == "130"){echo "selected";}?>>취소요청</option>
			<option value="80" <?if($my_progress == "80"){echo "selected";}?>>반송</option>
			<option value="100" <?if($my_progress == "100"){echo "selected";}?>>완결</option>
			<option value="120" <?if($my_progress == "120"){echo "selected";}?>>환불</option> -->
			<option value="01" <?if($my_progress == "01"){echo "selected";}?>>주문접수</option>
			<option value="02" <?if($my_progress == "02"){echo "selected";}?>>입금확인</option>
			<option value="03" <?if($my_progress == "03"){echo "selected";}?>>배송준비</option>
			<option value="04" <?if($my_progress == "04"){echo "selected";}?>>상품발송</option>
			<option value="05" <?if($my_progress == "05"){echo "selected";}?>>거래완료</option>
			<option value="06" <?if($my_progress == "06"){echo "selected";}?>>주문취소</option>
			<option value="07" <?if($my_progress == "07"){echo "selected";}?>>환불요청</option>
			<option value="08" <?if($my_progress == "08"){echo "selected";}?>>환불완료</option>
			<option value="09" <?if($my_progress == "09"){echo "selected";}?>>교환요청</option>
			<option value="10" <?if($my_progress == "10"){echo "selected";}?>>교환완료</option>
		  </select>
		  </td>
          <td  width="20%" align="center" class="table_body_menu">수정자</td>
          <td class="table_body_text"><?=$my_writer?></td>
        </tr>
        <!-- <tr>
          <td colspan="4" align='left'>
          * 배송완료 및 완결시에 물품 적립금 추가.
          * 배송완료 및 완결 후에 환불시만 적립금 삭제.(환불은 신중히)
          </td>
		</tr> -->
      </table>
    </td>
  </tr>
</table>

<br>
<?//}?>

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

$query = "select SEQ,IT_NO,IT_NAME,IT_PRICE, IT_SALE_PRICE,QAT,TAK_NAME,TAK_NO,OP_NAME,OP_PRICE,(SELECT IT_STANDARD  FROM CM_SHOP_T WHERE IT_NO=A.IT_NO) AS IT_STANDARD  from " . $cf_table_car_nm . " AS A where ORDER_NO='$po_no' ";
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
	$my_it_standard[$i]		= $arr[$i][IT_STANDARD];

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
	$tm_sell_price[$t] = $my_op_price[$t] ? $tm_sell_price[$t]+$my_op_price[$t] : $tm_sell_price[$t];

//	$tm_total_price = $my_it_price[$t] * $my_qat[$t];
	$tm_total_price = $tm_sell_price[$t] * $my_qat[$t];
	$tm_total_amount = $tm_total_amount +  $tm_total_price;    // 총결제금액
	$tm_total_price = number_format($tm_total_price);   //상품별 총금액
	$tm_it_price = number_format($tm_it_price);  //상품별 총금액 출력포맷

	$my_seq = $my_it_seq[$t];
	

?>	
				  <tr align='right' bgcolor='#FFFFFF'>
					<td><?=$my_it_name[$t]?><br /><?=$my_it_standard[$t];?></td>
					<td><?=$my_op_name[$t]?></td>
					<td><?=$tm_sell_price[$t]?></td>
					<td><?=$my_qat[$t]?></td>
					<td><?=$tm_total_price?></td>
				  </tr>
				  <tr>
					<td bgcolor='#7FA1D0' align='right'><font color="#ffffff">&nbsp;택 배</font></td>
					<td colspan="4" bgcolor='#FFFFFF'>
					택배회사 : 
<?
	$query_tak = "SELECT CD,NM FROM $cf_table_cod_nm WHERE GB = 'takbae' order by order_no desc ";

	$my_tak = $DB->Arr($query_tak);
	echo ArrToSelect("fr_tak_name_".$my_seq, "", "", $my_tak, $my_it_tak_name[$t]);

?>			
					송장번호 : <input type="text" name="fr_tak_no[<?=$my_seq?>]" class="box" size=15 value="<?=$my_it_tak_no[$t]?>">
					</td>
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
<br>



<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td align="center"><?=$LIST?> &nbsp;&nbsp;<?=$PRINT?> &nbsp;&nbsp;<?=$MODIFY?> &nbsp;&nbsp;<?//=$DELETE?></td>
  </tr>
</table>

<BR>
<BR>


