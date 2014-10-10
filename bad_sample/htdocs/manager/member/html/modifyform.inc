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

			<td width="80%" class="table_body_text">

			<?=$my_cm_id?></td>

		</tr>



		<input type="hidden" name="fr_cm_crypt_passwd" value="<?=$my_cm_passwd?>"> 

		  <tr height='25'>

			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 새비밀번호</td>

			<td class="table_body_text"> <input type="password" name="fr_cm_new_passwd" style='width:90px' maxlength="30"class="box1">

			  <span class='font_s'>(비밀번호 변경시만 입력하세요.)</span></td>

		  </tr>



		  <tr height='25'>

			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 비밀번호 확인</td>

			<td class="table_body_text"> <input type="password" name="fr_cm_new_passwd2" style='width:90px' maxlength="30"class="box1"></td>

		  </tr>



		<!-- <tr height='25'>

			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 비밀번호문</td>

			<td class="table_body_text"> <?=ArrToSelect("fr_cm_passwd_q", "", "", $passwd_q_arr, $my_cm_passwd_q)?></td>

		  </tr>



		  <tr height='25'>

			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 비밀번호답</td>

			<td class="table_body_text"><input type="text" name="fr_cm_passwd_a" size="10" maxlength="10"class="box1" value="<?=$my_cm_passwd_a?>"></td>

		  </tr> -->






<!--
		<tr height='25'>

			<td width='100' class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 회사명</td>

			<td class="table_body_text"> <input type="text" name="fr_cm_com_nm" size="20" maxlength="30" class='box1' value="<?=$my_cm_com_nm?>"></td>

		</tr>

		<tr height='25'>

			<td width='100' class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 사업자번호</td>

			<td class="table_body_text"> <input type="text" name="fr_cm_com_num" size="15" maxlength="15" class='box1' value="<?=$my_cm_com_num?>"></td>

		</tr>
-->
		<tr height='25'>

			<td width='100' class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 이름</td>

			<td class="table_body_text"> <input type="text" name="fr_cm_nm" size="10" maxlength="15" class='box1' value="<?=$my_cm_nm?>"></td>

		</tr>

		<tr height='25'>

			<td width='100' class="table_body_menu" rowspan="3"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 주소</td>

			<td class="table_body_text">

				<input type="text" name="fr_zip_cd" size='15' class='box1' readonly onClick="ZipWindow('/common/search_code/zipsearch.html',8);" style="cursor:hand" value="<?=$my_cm_zip_cd?>">



				<img src="images/adr_check.gif" align="absmiddle" onClick="ZipWindow('/common/search_code/zipsearch.html',8);" style="cursor:hand">

			</td>

		</tr>

		<tr height='25'>

			<td class="table_body_text">

				<input type="text" name="fr_addr" size='60' class='box1' readonly onClick="ZipWindow('/common/search_code/zipsearch.html',8);" value="<?=$my_cm_addr?>">

			</td>

		</tr>

		<tr height='25'>

			<td class="table_body_text"> 

				<input type="text" name="fr_addr2" size='60' class='box1' value="<?=$my_cm_addr2?>">

			</td>

		</tr>

		<tr height='25'>

			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 전화번호</td>

			<td class="table_body_text">

				<input type="text" name="fr_cm_tel1" size='3' class='box1' value="<?=$my_cm_tel1?>">

				- 

				<input type="text" name="fr_cm_tel2" size='4' class='box1' value="<?=$my_cm_tel2?>">

				- 

				<input type="text" name="fr_cm_tel3" size='4' class='box1' value="<?=$my_cm_tel3?>">

			</td>

		</tr>

		<tr height='25'>

			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 휴대폰 번호</td>

			<td class="table_body_text"> 

				<input type="text" name="fr_cm_hp_tel1" size='3' class='box1' value="<?=$my_cm_hp_tel1?>">

				- 

				<input type="text" name="fr_cm_hp_tel2" size='4' class='box1' value="<?=$my_cm_hp_tel2?>">

				- 

				<input type="text" name="fr_cm_hp_tel3" size='4' class='box1' value="<?=$my_cm_hp_tel3?>">

			</td>

		</tr>
<!--
		<tr height='25'>

			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 팩스 번호</td>

			<td class="table_body_text"> 

				<input type="text" name="fr_cm_fax1" size='3' class='box1' value="<?=$my_cm_fax1?>">

				- 

				<input type="text" name="fr_cm_fax2" size='4' class='box1' value="<?=$my_cm_fax2?>">

				- 

				<input type="text" name="fr_cm_fax3" size='4' class='box1' value="<?=$my_cm_fax3?>">

			</td>

		</tr>
-->
		<tr height='25'>

			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> E-Mail</td>

			<td class="table_body_text"> <input type=text name='fr_cm_email' style='width:200px'  class="box1" value="<?=$my_cm_email?>"></td>

		</tr>

		<tr height='25'>

			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 시리얼넘버</td>

			<td class="table_body_text"> <input type=text name='fr_serial_no' style='width:200px'  class="box1" value="<?=$my_serial_no?>"></td>

		</tr>

		<tr height='25' id="memview">

			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 등급</td>

			<td class="table_body_text"> <?=ArrToSelect("fr_cm_mem_cd", "class='select'", "- 변경할등급 -", $mem_cd_arr, $my_cm_mem_cd)?> 기업회원의 경우에만</td>

		  </tr>







	  <input type="hidden" name="fr_cm_req_level" value="<?=$my_cm_req_level?>"> 

	  <tr height='25'>

		<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 변경할레벨</td>

		<td class="table_body_text"> <?=ArrToSelect("fr_cm_new_level", "class='select' onchange='mem_cd_ch(this.value);'", "- 변경할레벨 -", $level_arr, $my_cm_level)?></td>

	  </tr>

		<tr height='25'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 탈퇴여부</td>
			<td class="table_body_text"> 
				<select name="fr_cm_del_yn">
					<option value="Y" <?if($my_cm_del_yn=="Y"){echo "selected";}?> >Y</option>
					<option value="N" <?if(!$my_cm_del_yn || $my_cm_del_yn=="N"){echo "selected";}?> >N</option>
				</select>
			</td>

	  </tr>



	</table>

  </td>

</tr>

</table>





<br>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0" >

  <tr>

	<td background='<?=$cf_images_dir?>/box_bg.gif' width='20'><img src="<?=$cf_images_dir?>/box_top.gif"></td>

	<td background='<?=$cf_images_dir?>/box_bg.gif' align='right'>

	<input type="button" value="<?=get_button_value($MY_URI)?>" onClick="checkIt();" class="input_button">

	<input type="button" value="취 소" onClick="history.back();" style="cursor:hand" class="input_button"></td>

	<td background='<?=$cf_images_dir?>/box_bg.gif' width='20' align='right'><img src="<?=$cf_images_dir?>/box_end.gif"></td>

  </tr>

</table>



<BR>

<br>

<SCRIPT LANGUAGE="JavaScript">

<!--

	mem_cd_ch('<?=$my_cm_level?>');

//-->

</SCRIPT>