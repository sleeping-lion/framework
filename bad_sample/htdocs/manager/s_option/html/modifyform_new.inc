<script language="Javascript1.2"><!-- // load htmlarea
_editor_url = "./edit/";                     // URL to htmlarea files
_Upload_url = "<?=$cf_savedir?>"
var win_ie_ver = parseFloat(navigator.appVersion.split("MSIE")[1]);
if (navigator.userAgent.indexOf('Mac')        >= 0) { win_ie_ver = 0; }
if (navigator.userAgent.indexOf('Windows CE') >= 0) { win_ie_ver = 0; }
if (navigator.userAgent.indexOf('Opera')      >= 0) { win_ie_ver = 0; }
if (win_ie_ver >= 5.5) {
  document.write('<scr' + 'ipt src="' +_editor_url+ 'editor.js"');
  document.write(' language="Javascript1.2"></scr' + 'ipt>');  
} else { document.write('<scr'+'ipt>function editor_generate() { return false; }</scr'+'ipt>'); }
// --></script>



<!-- //관련상품 넘겨줄 값//-->
<input type="hidden" name="fr_friend_value" value="">

<!--// main_start //-->
<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="2" cellpadding="2" >
  <tr>
    <td>
      <div align="center"><font size="2" color="#000066">▷ <font color="#CC3300"> * </font>표가 있는 항목은 반드시 입력하시기 바랍니다. ◁</font></div>
    </td>
  </tr>
</table>

<table width='<?=$cf_table_wd_large?>' border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
	  <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
	  	<tr>
		  <td class="table_menu" colspan="4" align="center">상품정보</td>
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu" width="15%" cols>분류코드<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		  <input type="hidden" name="fr_it_lclass" value="<?=$my_it_lclass?>">
		  <input type="hidden" name="fr_it_mclass" value="<?=$my_it_mclass?>">
		  <input type="hidden" name="fr_it_sclass" value="<?=$my_it_sclass?>">
		  <iframe name="ctg" src="category.html?it_lclass=<?=$my_it_lclass?>&it_mclass=<?=$my_it_mclass?>&it_sclass=<?=$my_it_sclass?>" width="100%" height="28" frameborder="0"></iframe>
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu">상품명<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_it_name" size="50" maxlength="50" value="<?=$my_it_name?>" class="box1"></td>
	    </tr>
	    <tr>
		  <td class="table_body_menu">상품코드</td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_it_model_no" size="30" maxlength="30" value="<?=$my_it_model_no?>" class="box1"></td>
    </tr>
		<tr>
		  <td class="table_body_menu">상품분류</td>
		  <td class="table_body_text" colspan="3">
		 <?=ArrToSelect("fr_it_event_cd", "class='select'", "", $event_arr, $my_it_event_cd)?></td>
	  </tr>
		
		<!--//관련상품 등록 최대4개까지 (|)로 구분//-->
		<tr>
		  <td class="table_body_menu">관련상품</td>
		  <td class="table_body_text" colspan="3">
				<input type="button" value="찾기" class="box1" onclick="friend_popup('<?=$po_basic_query?>')"> 최대 4개<br>
 				<select id="fr_friend_select" name="fr_friend_select" multiple  style="width:350px;">
					<?=$my_friend_option?>
				</select><br>
		  	<input type="button" value="삭제" class="box1" onclick="delSelectItem(this.form.fr_friend_select)">
			</td>
    </tr>


	    <tr>
		  <td class="table_body_menu">제조사</td>
		  <td class="table_body_text" width="35%">
		  <input type="text" name="fr_it_company" size="15" maxlength="20" value="<?=$my_it_company?>" class="box1"></td>
		  <td class="table_body_menu" width="15%">정렬순서</td>
		  <td class="table_body_text">
		  <input type="text" name="fr_it_pos" size="10" maxlength="10" value="<?=$my_it_pos?>" class="box1"> 숫자만 기입</td>
	    </tr>
		<tr>
		  <td class="table_body_menu">간단한 설명</td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_it_etc" size="50" maxlength="50" value="<?=$my_it_etc?>" class="box1"> 50자 이내</td>
	    </tr>
		<tr>
		  <td class="table_body_menu">상세 설명</td>
		  <td class="table_body_text" colspan="3">
		  <textarea name="fr_it_memo" cols="65%" rows="15" class='tbox'><?=$my_it_memo?></textarea>
		  </td>
	    </tr>
	  </table>
	</td>
  </tr>
</table>
<br>

<table width='<?=$cf_table_wd_large?>' border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
	  <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
	  	<tr>
		  <td class="table_menu" colspan="4" align="center">판매정보</td>
		  </td>
		</tr>
	    <tr>
		  <td class="table_body_menu" width="20%">판매여부</td>
		  <td class="table_body_text" width="30%">
		  <?=ArrToSelect("fr_it_sell_yn", "class='select'", "", $sell_arr, $my_it_sell_yn)?></td>
		  <td class="table_body_menu" width="20%">공개여부</td>
		  <td class="table_body_text">
		  <?=ArrToSelect("fr_it_service_yn", "class='select'", "", $service_arr, $my_it_service_yn)?></td>
	    </tr>
<?if($cf_stock_yn == "Y") {?>
		<tr>
		  <td class="table_body_menu">상품재고량</td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_it_cnt" size="15" maxlength="15" value="<?=$my_it_cnt?>" class="box1"></td>
	    </tr>
<?}?>
		<tr>
		  <td class="table_body_menu">판매금액</td>
		  <td class="table_body_text">
		  <input type="text" name="fr_it_price" size="15" maxlength="15" value="<?=$my_it_price?>" class="box1"></td>
		  <td class="table_body_menu">판매가격단위</td>
		  <td class="table_body_text">
		  <?=ArrToSelect("fr_it_price_unit", "class='select'", "", $unit_arr, $my_it_price_unit)?></td>
	    </tr>

		<tr>
		  <td class="table_body_menu"><?=get_code_nm("ss")?> 할인금액</td>
		  <td class="table_body_text">
		  <input type="text" name="fr_it_sale_price1" size="15" maxlength="15" value="<?=$my_it_sale_price1?>" class="box1"></td>
		  <td class="table_body_menu"><?=get_code_nm("rr")?> 할인금액</td>
		  <td class="table_body_text">
		  <input type="text" name="fr_it_sale_price2" size="15" maxlength="15" value="<?=$my_it_sale_price2?>" class="box1"></td>
	    </tr>
		<tr>
		  <td class="table_body_menu"><?=get_code_nm("qq")?> 할인금액</td>
		  <td class="table_body_text">
		  <input type="text" name="fr_it_sale_price3" size="15" maxlength="15" value="<?=$my_it_sale_price3?>" class="box1"></td>
		  <td class="table_body_menu"><?=get_code_nm("pp")?> 할인금액</td>
		  <td class="table_body_text">
		  <input type="text" name="fr_it_sale_price4" size="15" maxlength="15" value="<?=$my_it_sale_price4?>" class="box1"></td>
	    </tr>


		<tr>
      <td class="table_body_menu">배송비</td>
		  <td class="table_body_text" colspan="3">
		  <?=ArrToSelect("fr_basong_yn", "class='select'", "", $basong_arr, $my_basong_yn)?></td>
	    </tr>
<?if($cf_point_yn == "Y") {?>
		<tr>
		  <td class="table_body_menu">마일리지</td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_it_save_price" size="15" maxlength="15" value="<?=$my_it_save_price?>" class="box1"> 이상품에 대하여 적립할 금액을 입력해 주세요 (숫자로만 기입)</td>
	    </tr>
<?}?>
	  </table>
	</td>
  </tr>
</table>

<br>

<table width='<?=$cf_table_wd_large?>' border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
	  <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
	  	<tr>
		  <td class="table_menu" colspan="4" align="center">이미지 정보</td>
		  </td>
		</tr>
<?foreach($cf_upload_nm as $uk=>$uv) {?>
		<tr>
		  <td class="table_body_menu" width="15%"><?=$cf_upload_column_nm[$uk]?></td>
		  <td class="table_body_text">
<?	if($tm_image_[$uk]) {?>
			<?=$tm_image_[$uk]?> &nbsp; <input type="checkbox" name="fr_file_del[<?=$uk?>]" value="Y"> 삭제<br>
<?	}?>
			<input type="file" name="userfile[<?=$uk?>]" size="40" class="box"> <font color=red>( <?=$cf_upload_size_nm[$uk]?> )</font><br>
		  </td>
		</tr>
<?}?>

	  </table>
	</td>
  </tr>
</table>



<br>

<table width='<?=$cf_table_wd_large?>' border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
	  <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
	    <tr>
		  <td align="center" colspan="2" bgColor="#D7E3EC">
			<font size=2 color=#000066>
			<input type="button" value="목록" onclick="location.href='list.html?<?=$po_adv_query?>&page=<?=$page?>'" class="input_button">
			<input type="button" value="수정하기" onClick="checkIt(this.form)" class="input_button">
			<input type="reset" value="취  소" class="input_button">
			</font>
		  </td>
	    </tr>
	  </table>
    </td>
  </tr>
</table>


<script language="javascript1.2">
  var config = new Object();    // create new config object
  config.width = "96%";
  config.height = "300px";
  editor_generate("fr_it_memo", config);
</script>