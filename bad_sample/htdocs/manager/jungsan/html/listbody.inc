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
		  <select name="fr_progress">
			<option value="20" <?if($my_progress == "20"){echo "selected";}?>>결제요청</option>
			<option value="50" <?if($my_progress == "50"){echo "selected";}?>>배송신청</option>
			<option value="60" <?if($my_progress == "60"){echo "selected";}?>>배송중</option>
			<option value="70" <?if($my_progress == "70"){echo "selected";}?>>배송완료</option>
			<option value="80" <?if($my_progress == "80"){echo "selected";}?>>반송</option>
			<option value="100" <?if($my_progress == "100"){echo "selected";}?>>완결</option>
			<option value="120" <?if($my_progress == "120"){echo "selected";}?>>환불</option>
		  </select>
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
				  <tr>
					<td bgcolor='#7FA1D0' align='right'><font color="#ffffff">&nbsp;택 배</font></td>
					<td colspan="4" bgcolor='#FFFFFF'>
					택배회사 : 
<?
	$query_tak = "SELECT CD,NM FROM $cf_table_cod_nm WHERE GB = 'takbae' order by cd";

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



<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
      <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">

          <td align="center" colspan="4" class="table_body_menu"><?=$LIST?> <?=$PRINT?> <?=$MODIFY?> <?=$DELETE?></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<BR>
<BR>


