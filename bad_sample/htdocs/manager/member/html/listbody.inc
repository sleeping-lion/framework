<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line" valign="top">
		<table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="6">
		  <tr>
			<td colspan='2' align='center' class="table_menu"><b>회원정보 보기</b></td> 
		  </tr>

		<tr height='25'>
			<td width="20%" class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 아이디</td>
			<td width="80%" class="table_body_text"><?=$my_cm_id?></td>
		</tr>

		<!-- <tr height='25'>
			<td  class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 패스워드문</td>
			<td class="table_body_text"><?=$my_cm_passwd_q_nm?></td>
		</tr>

		<tr height='25'>
			<td  class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 패스워드답</td>
			<td class="table_body_text"><?=$my_cm_passwd_a?></td>
		</tr> -->

		<input type="hidden" name="fr_cm_crypt_passwd" value="<?=$my_cm_passwd?>"> 

		<!--tr height='25'>
			<td width='100'  class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 회사명</td>
			<td class="table_body_text"> <?=$my_cm_com_nm?></td>
		</tr>
		<tr height='25'>
			<td width='100'  class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 사업자번호</td>
			<td class="table_body_text"> <?=$my_cm_com_num?></td>
		</tr-->
		<tr height='25'>
			<td width='100'  class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 이름</td>
			<td class="table_body_text"> <?=$my_cm_nm?></td>
		</tr>

		<!-- <tr height='25'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 주민등록번호</td>
			<td class="table_body_text"> <?=$my_cm_jumin1?> - *******<?#$my_cm_jumin2?></td>
			</td>
		</tr> -->
		<tr height='30'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 주소</td>
			<td class="table_body_text"> 	(<?=$my_cm_zip_cd?>) <?=$my_cm_addr?> <?=$my_cm_addr2?></td>
		</tr>
		<tr height='30'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 전화번호</td>
			<td class="table_body_text"> 	<?=$my_cm_tel?></td>
		</tr>
		<tr height='30'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 휴대폰 번호</td>
			<td class="table_body_text"> <?=$my_cm_hp_tel?></td>
		</tr>
		<!--tr height='30'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 팩스 번호</td>
			<td class="table_body_text"> <?=$my_cm_fax?></td>
		</tr-->
		<tr height='30'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> E-Mail</td>
			<td class="table_body_text"> <?=$my_cm_email?></td>
		</tr>
		<tr height='30'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 시리얼넘버</td>
			<td class="table_body_text"> <?=$my_serial_no?></td>
		</tr>

		<!-- <tr height='30'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 직업</td>
			<td class="table_body_text"><?=$my_cm_job?></td>
		</tr>

		<tr height='30' <? if($my_cm_children_yn=="N") {?>style="display:none"<? }?>>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 자녀</td>
			<td class="table_body_text"><?=$tm_cm_children_age?></td>
		</tr> -->


<?if($my_cm_level == "ee") {?>
		<tr height='30'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 등급</td>
			<td class="table_body_text"><?=$my_cm_mem_nm?></td>
		</tr>
<?}?>
		<tr height='30'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 현재레벨</td>
			<td class="table_body_text"><?=$my_cm_level_nm?></td>
		</tr>

		<tr height='30'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 탈퇴여부</td>
			<td class="table_body_text"><?=$my_cm_del_yn?></td>
		</tr>
        
		<!-- <tr height='30'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 추천인 아이디</td>
			<td class="table_body_text"><?=$my_cm_choo?></td>
		</tr>

		<tr height='30'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 퀴즈 정답</td>
			<td class="table_body_text"><?=$my_cm_quize?></td>
		</tr> -->

		<tr height='30'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 구매히스토리</td>
			<td class="table_body_text"><?=$order_history_text?></td>
		</tr>

		<!-- <tr height='30'>
			<td class="table_body_menu"><img src="<?=$cf_images_dir?>/icon_ring2.gif"> 가입경로</td>
			<td class="table_body_text">
				<table>
					<tr>
						<td style="padding-left:6px;"><b>우리 제품 및 기업을 어떻게 알게 되었나요?</b></td>
					</tr>
					<tr>
						<td style="padding-left:6px;">인터넷 검색 <input type="checkbox" name="fr_choice_v1" value="1" <?=$route1_checked?>></td>
					</tr>
					<tr>
						<td style="padding-left:6px;">TV광고 <input type="checkbox" name="fr_choice_v2" value="2" <?=$route2_checked?>></td>
					</tr>
					<tr>
						<td style="padding-left:6px;">서적이나 잡지, 또는 신문 광고 <input type="checkbox" name="fr_choice_v3" value="3" <?=$route3_checked?>></td>
					</tr>
					<tr>
						<td style="padding-left:6px;">지인들을 통해 <input type="checkbox" name="fr_choice_v4" value="4" <?=$route4_checked?>></td>
					</tr>
					<tr>
						<td style="padding-left:6px;">세미나, 박람회 등을 통해 <input type="checkbox" name="fr_choice_v5" value="5" <?=$route5_checked?>></td>
					</tr>
					<tr>
						<td style="padding-left:6px;">기타 <input type="checkbox" name="fr_choice_v6" value="6" <?=$route6_checked?>> <?=$my_etc_text?></td>
					</tr>
				</table>
			</td>
		</tr> -->

		 
		</table>
	  </td>
	</tr>
</table>

<br>



<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0" >
  <tr>
	<td align='right'><?=$MODIFY?>&nbsp;&nbsp;<?=$DELETE?>&nbsp;&nbsp;<?=$LIST?></td>
  </tr>
</table>

<BR>
<br>