<input type="hidden" name="fr_id_check" value="<?=$tm_id_check?>">
<input type="hidden" name="fr_addr_check" value="<?=$tm_addr_check?>">

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="1" cellpadding="0" >
<tr>
	<td class="table_line">
		<table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="10">
		<tr>
			<td colspan='2' align='center' class="table_menu"><b>회원정보 등록</b></td> 
		</tr>

		<tr height='25'>
			<td width="20%" class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 아이디</td>
			<td width="80%" class="table_body_text"><input type=text name='fr_cm_id' size="10" maxlength="20" class="box1" value="" onChange="signform.fr_id_check.value='N'">
				<img src="images/id_check.gif" align="absmiddle" onClick="check_id_window('check_id.html')" style="cursor:hand"> (영문, 숫자 조합으로 4~20자)</td>
		</tr>

		<input type="hidden" name="fr_cm_crypt_passwd" value="<?=$my_cm_passwd?>"> 
		<tr height='25'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 새비밀번호</td>
			<td class="table_body_text"><input type="password" name="fr_cm_passwd" style='width:90px' maxlength="30" class="box1"><span class='font_s'></span></td>
		</tr>

		<?echo $my_cm_com_nm;?>
		<tr height='25'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 비밀번호 확인</td>
			<td class="table_body_text"> <input type="password" name="fr_cm_passwd2" style='width:90px' maxlength="30" class="box1"></td>
		</tr>

		<!-- <tr height='25'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 비밀번호문</td>
			<td class="table_body_text"> <?=ArrToSelect("fr_cm_passwd_q", "", "", $passwd_q_arr, $my_cm_passwd_q)?></td>
		  </tr>

		  <tr height='25'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 비밀번호답</td>
			<td class="table_body_text"><input type="text" name="fr_cm_passwd_a" size="10" maxlength="10"class="box1" value="<?=$my_cm_passwd_a?>"></td>
		  </tr> -->



		<!--tr height='25'>
			<td width='100' class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 회사명</td>
			<td class="table_body_text"> <input type="text" name="fr_cm_com_nm" size="20" maxlength="30" class='box1'></td>
		</tr>
		<tr height='25'>
			<td width='100' class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 사업자번호</td>
			<td class="table_body_text"> <input type="text" name="fr_cm_com_num" size="15" maxlength="15" class='box1'></td>
		</tr-->

		<tr height='25'>
			<td width='100' class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 이름</td>
			<td class="table_body_text"> <input type="text" name="fr_cm_nm" size="10" maxlength="15" class='box1' value=""></td>
		</tr>
		<!-- <tr height='25'>
			<td width='100' class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 주민등록번호</td>
			<td class="table_body_text"> 
				<input type="text" name="fr_cm_jumin1" size='6' class='box1' value="<?=$fr_cm_jumin1?>" OnKeyUp="IsSSNO(this.name)">
				- 
				<input type="text" name="fr_cm_jumin2" size='7' class='box1' value="<?=$fr_cm_jumin2?>" onKeyUp="IsSSNO(this.name)"></td>
		</tr> -->
		<tr height='25'>
			<td width='100' class="table_body_menu" rowspan="3"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 주소</td>
			<td class="table_body_text">
				<input type="text" name="fr_zip_cd" size='15' class='box1' readonly onClick="ZipWindow('/common/search_code/zipsearch.html',12);" style="cursor:hand">

				<img src="images/adr_check.gif" align="absmiddle" onClick="ZipWindow('/common/search_code/zipsearch.html',12);" style="cursor:hand">
			</td>
		</tr>
		<tr height='25'>
			<td class="table_body_text">
				<input type="text" name="fr_addr" size='60' class='box1' readonly onClick="ZipWindow('/common/search_code/zipsearch.html',8);">
			</td>
		</tr>
		<tr height='25'>
			<td class="table_body_text"> 
				<input type="text" name="fr_addr2" size='60' class='box1'>
			</td>
		</tr>
		<tr height='25'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 전화번호</td>
			<td class="table_body_text">
				<input type="text" name="fr_cm_tel1" size='3' class='box1'>
				- 
				<input type="text" name="fr_cm_tel2" size='4' class='box1'>
				- 
				<input type="text" name="fr_cm_tel3" size='4' class='box1'>
			</td>
		</tr>
		<tr height='25'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 휴대폰 번호</td>
			<td class="table_body_text"> 
				<input type="text" name="fr_cm_hp_tel1" size='3' class='box1'>
				- 
				<input type="text" name="fr_cm_hp_tel2" size='4' class='box1'>
				- 
				<input type="text" name="fr_cm_hp_tel3" size='4' class='box1'>
			</td>
		</tr>
		<!--tr height='25'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 팩스 번호</td>
			<td class="table_body_text"> 
				<input type="text" name="fr_cm_fax1" size='3' class='box1' >
				- 
				<input type="text" name="fr_cm_fax2" size='4' class='box1' >
				- 
				<input type="text" name="fr_cm_fax3" size='4' class='box1' >
			</td>
		</tr-->
		<tr height='25'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> E-Mail</td>
			<td class="table_body_text"> <input type=text name='fr_cm_email' style='width:200px'  class="box1" value=""></td>
		</tr>
		<tr height='25'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 시리얼넘버</td>
			<td class="table_body_text"> <input type=text name='fr_serial_no' style='width:200px'  class="box1" value=""></td>
		</tr>

	  <tr height='25'>
		<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 회원레벨</td>
		<td class="table_body_text"> <?=ArrToSelect("fr_cm_level", "class='select'", "- 회원레벨 -", $level_arr, "xx")?></td>
	  </tr>

	</table>
  </td>
</tr>
</table>

<br>

<br>
<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0" >
  <tr>
	<td background='<?=$cf_images_dir?>/box_bg.gif' width='20'><img src="<?=$cf_images_dir?>/box_top.gif"></td>
	<td background='<?=$cf_images_dir?>/box_bg.gif' align='right'>
	<input type=image  src="<?=$cf_images_dir?>/confirm.gif"  style="cursor:hand">
	<img src="<?=$cf_images_dir?>/cancel.gif" onClick="history.back();" style="cursor:hand"></td>
	<td background='<?=$cf_images_dir?>/box_bg.gif' width='20' align='right'><img src="<?=$cf_images_dir?>/box_end.gif"></td>
  </tr>
</table>



<BR>
<br>
