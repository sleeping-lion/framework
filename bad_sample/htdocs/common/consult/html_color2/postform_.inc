<script type="text/javascript" src="/ckeditor/ckeditor.js"></script>
<?php
	$MY_URI = get_php_self_filename($_SERVER[PHP_SELF]);  
//	include $cf_initial_s . "_necessary.inc";

	if($cf_cook_nick_nm)
		$tm_input_nm = $cf_cook_nick_nm;
	else
		$tm_input_nm = $my_input_nm;

	$tm_input_Y = substr($my_input_ymdhms, 0, 4);
	$tm_input_m = substr($my_input_ymdhms, 4, 2);
	$tm_input_d = substr($my_input_ymdhms, 6, 2);
	$tm_input_H = substr($my_input_ymdhms, 8, 2);
	$tm_input_i = substr($my_input_ymdhms, 10, 2);
	$tm_input_s = substr($my_input_ymdhms, 12, 2);
?>

<script>
function change(){
	var form = document.signform;
	var price1 = form.fr_item1.value * <?=$price_arr[0][CON_CD]?>;
	var price2 = form.fr_item2.value * <?=$price_arr[1][CON_CD]?>;
	var price3 = form.fr_item3.value * <?=$price_arr[2][CON_CD]?>;
	//var price4 = form.fr_item4.value * <?=$price_arr[3][CON_CD]?>; //가격 정해지면 주석 제거
	var price5 = price1 + price2 + price3;
	price1 = change2(price1);
	price2 = change2(price2);
	price3 = change2(price3);
	//price4 = change2(price4);
	price5 = change2(price5);
	form.fr_price1.value =price1;
	form.fr_price2.value =price2;
	form.fr_price3.value =price3;
	//form.fr_price4.value =price4;
	form.fr_price5.value =price5;
}
function change2(aaa){
	aaa = Number(String(aaa).replace(/\..*[^\d]/g,"")).toLocaleString().slice(0,-3);
	return aaa;
}
</script>
<table width="<?=$cf_table_wd_large?>" border="0" cellpadding="0" cellspacing="0">
	<tr>
		<td><img src="<?=$cf_images_dir?>/view_top.gif"></td>
	</tr>
	<tr>
		<td background="<?=$cf_images_dir?>/view_bg.gif" style="padding-left:10px">
		<BR>
<table width="630" border="1" cellspacing="0" cellpadding="0" bordercolorlight='#B9E1B3' bordercolordark='#FFFFFF' >
	<tr height='37'>
	  <td align="center" width="20%"><b><?=$price_arr[0][NM]?></b></td>      
	  <td align="center" width="20%">가격 : <?=$price_arr[0][CON_CD]?>원<td>
	  <td align="center" width="20%">수량 : <input type="text" name="fr_item1" size="3" maxlength="3" class='box' onkeypress="javascript:change();" onchange="javascript:change();"><td>
      <td width="40%">총액 : <input type="text" name="fr_price1" size="35" maxlength="30" class='box' readonly></td>
   </tr>
	<tr height='37'>
	  <td align="center" width="20%"><b><?=$price_arr[1][NM]?></b></td>      
	  <td align="center" width="20%">가격 : <?=$price_arr[1][CON_CD]?>원<td>
	  <td align="center" width="20%">수량 : <input type="text" name="fr_item2" size="3" maxlength="3" class='box' onkeypress="javascript:change();" onchange="javascript:change();"><td>
      <td width="40%">총액 : <input type="text" name="fr_price2" size="35" maxlength="30" class='box' readonly></td>
   </tr>
   <tr height='37'>
	  <td align="center" width="20%"><b><?=$price_arr[2][NM]?></b></td>      
	  <td align="center" width="20%">가격 : <?=$price_arr[2][CON_CD]?>원<td>
	  <td align="center" width="20%">수량 : <input type="text" name="fr_item3" size="3" maxlength="3" class='box' onkeypress="javascript:change();" onchange="javascript:change();"><td>
      <td width="40%">총액 : <input type="text" name="fr_price3" size="35" maxlength="30" class='box' readonly></td>
   </tr>
   <tr height='37'>
	  <td align="center" width="20%"><b><?=$price_arr[3][NM]?></b></td>      
	  <?if($price_arr[3][CON_CD]=="0"){?>
	  <td align="center" width="20%">준비중입니다.<td>
	  <td align="center" width="20%"><!-- 수량 : <input type="text" name="fr_item1" size="3" maxlength="3" class='box'> -->&nbsp;<td>
      <td width="40%"><!-- 총액 :  -->&nbsp;</td>
	  <?}else{?>
	  <td align="center" width="20%"><?=$price_arr[0][CON_CD]?><td>
	  <td align="center" width="20%"> 수량 : <input type="text" name="fr_item4" size="3" maxlength="3" class='box'> &nbsp;<td>
      <td width="40%"> 총액 : <input type="text" name="fr_price4" size="35" maxlength="30" class='box' readonly></td>
	  <?}?>
   </tr>
   <tr height='37'>
	  <td align="right" colspan="6" style="padding-right:15px;">총 금액 : 
<!-- 총액 :  -->&nbsp;<input type="text" name="fr_price5" size="40" maxlength="30" class='box' readonly></td>
   </tr>

</table>
<br/>
<b>아래의 계좌로 오후 2시 30분 이전에 입금이 확인이 된 경우 당일 발송됩니다.<br/>
입금은행 : 우리은행 1005-001-022985 예금주 : (주)웰바스</b><br/>
<table width="630" border="1" cellspacing="0" cellpadding="3" frame='hsides' bordercolorlight='#B9E1B3' bordercolordark='#FFFFFF' >
	<tr height="37">
	  <td align="center" colspan="2">세부정보</td>      
	  <td align="center" colspan="2">세금계산서 발행시 작성해 주세요.</td>      
    </tr>
	<tr height='37'>
	  <td align="center" width="100">회사명</td>      
      <td>&nbsp;&nbsp;<input type="text" name="fr_subject" size="30" maxlength="100" class='box'></td>
	  <td align="center" width="100">사업자번호</td>      
      <td>&nbsp;&nbsp;<input type="text" name="fr_company" size="30" maxlength="100" class='box'></td>
   </tr>
	
	<tr height="37">
	  <td align="center">받으실분</td>      
      <td>&nbsp;&nbsp;<input type="text" name="fr_nm" size="30" maxlength="100" class='box'></td>
	  <td align="center" width="100">업종, 업태</td>      
      <td>&nbsp;&nbsp;<input type="text" name="fr_memo2" size="30" maxlength="100" class='box'></td>
   </tr>

   <tr height="37">
	  <td align="center">전화번호</td>      
      <td>&nbsp;&nbsp;<input type="text" name="fr_tel1" size="30" maxlength="100" class='box'></td>
	  <td align="center" width="100">대표자</td>      
      <td>&nbsp;&nbsp;<input type="text" name="fr_memo3" size="30" maxlength="100" class='box'></td>
   </tr>

	<tr height="37">
      <td align="center">핸드폰번호</td>      
      <td>&nbsp;&nbsp;<input type="text" name="fr_hp" size="30" maxlength="30" class='box'></td>
	  <td align="center" width="100">E-mail</td>      
      <td>&nbsp;&nbsp;<input type="text" name="fr_email" size="30" maxlength="100" class='box'></td>
   </tr>

	<tr height="37">
      <td align="center">주소</td>      
      <td style="padding-left:8px;" colspan="3"><table width="100%" border="0" cellspacing="0" cellpadding="0"> 
		  <tr> 
			<td height='25'><input type="text" name="fr_cm_zip_cd" size='15' class='box' readonly onClick="ZipWindow('/common/search_code/zipsearch.html',8);" style="cursor:hand"> 
			  <img src="/member/register/images/adr_check.gif" align="absmiddle" onClick="ZipWindow('/common/search_code/zipsearch.html',8);" style="cursor:hand"> 
			  </td>
		  </tr>
		  <tr> 
			<td height='25'><input type="text" name="fr_cm_addr" size='80' class='box' readonly onClick="ZipWindow('/common/search_code/zipsearch.html',8);"> </td>
		  </tr>
		  <tr> 
			<td height='25'><input type="text" name="fr_cm_addr2" size='80' class='box'> </td>
		  </tr>
		</table></td>
	</tr>

	<tr height="37">
      <td align="center" >남기실 말씀</td>      
      <td colspan="3">&nbsp;&nbsp;<textarea name="fr_memo" cols="60" rows="10" class="textarea"></textarea></td>
    </tr>
 
</table>
<BR>
 
		</td>
	</tr>
	<tr>
		<td><img src="<?=$cf_images_dir?>/view_end.gif"></td>
	</tr>
</table>
 
<BR>


  <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
    <tr>
      <td height="36" align="center">
	    <input type="image" src="<?=$cf_images_dir?>/ok.gif" style="vertical-align:middle;" />
	    <a href="javascript:signform.reset();"><img src="<?=$cf_images_dir?>/cancel.gif" border="0" style="vertical-align:middle"></a>
	  </td>
    </tr>
  </table>
  <BR>
  <BR>

