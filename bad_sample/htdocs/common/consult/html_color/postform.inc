<style type="text/css">
<!--
.regist {height:35px;font-family:"나눔고딕"; font-size:12px;color:#0d636d; text-align:left; padding-left:20px;border-bottom:1px dashed #CFCFCF; background:#eaf4f6;}
.regist2 {font-family:"나눔고딕"; font-size:12px;color:#666; text-align:left; padding:5px 0 5px 10px; border-bottom:1px dashed #cfcfcf;background:#FFFFFF;}
.box_regist {Background-color:#FFFFFF; Border:1px SOLID #B3B3B3; height:18px; font-size:9pt; color : #616161;}
.input_textarea{ width:98%; border:1px solid #b7b7b7;font-family:Arial, "돋움", Sans-serif;}
-->
</style>

<img src="/images/contents/agent_form_img.jpg" >


<br />
<br />

<?
	if($tm_subject){
		$tm_subject .= "제품 문의드립니다.";
	}
?>
<input type="hidden" name="b_type_yn" value="N">

<input type="hidden" name="fr_model" id="fr_model"  maxlength="100" value="" />
<input type="hidden" name="fr_model2" id="fr_model2"  maxlength="100" value="" />
<input type="hidden" name="fr_cm_b_type" id="fr_cm_b_type"  maxlength="100" value="" />


<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0" align="center" style="border-top:2px solid #46aab4;border-bottom:1px solid #46aab4;">
	<colgroup>
		<col style="width:90px;" />
		<col style="width:auto;" />
		<col style="width:70px;" />
		<col style="width:250px;" />
	</colgroup>
  <tr>
		 <th class="regist">신청인</th>
         <td class="regist2"><input type="text" name="fr_nm" style="width:100px;" maxlength="250" value="" class="box_regist"'></td>
		 <th class="regist">성별</th>
         <td class="regist2"><input type="radio" name="fr_sex" class="box_regist"' value="1" style="border:0px;text-align:center;vertical-align:top;"> 남 &nbsp;&nbsp;&nbsp;<input type="radio" name="fr_sex" class="box_regist"' value="2" style="border:0px;text-align:center;vertical-align:top;"> 여 </td>
  </tr>
  <tr>
		 <th class="regist">휴대폰</th>
         <td class="regist2"><input type="text" name="fr_hp_tel" style="width:70%;" maxlength="250" value="<?=$tm_subject?>" class="box_regist"'></td>
		 <th class="regist">집전화</th>
         <td class="regist2"><input type="text" name="fr_tel" style="width:70%;" maxlength="250" value="<?=$tm_subject?>" class="box_regist"'></td>
  </tr>
  <tr>
		 <th class="regist">주소</th>
         <td class="regist2" colspan="3"><input type="text" name="fr_address" style="width:490px;" maxlength="30" value="" class="box_regist"' ></td>
  </tr>
  <tr>
		 <th class="regist">현재직업</th>
         <td class="regist2"><input type="text" name="fr_job" style="width:70%;" maxlength="250" value="<?=$tm_subject?>" class="box_regist"'></td>
		 <th class="regist">희망지역</th>
         <td class="regist2"><input type="text" name="fr_hope" style="width:70%;" maxlength="250" value="<?=$tm_subject?>" class="box_regist"'></td>
  </tr>
  <tr>
		 <th class="regist">사업동기</th>
         <td class="regist2" colspan="3"><textarea name="fr_motive" style="width:90%;" rows="3" class="input_textarea"></textarea></td>
  </tr>
  <tr>
		 <th class="regist">경력사항(사업)</th>
         <td class="regist2" colspan="3"><textarea name="fr_career" style="width:90%;" rows="3" class="input_textarea"></textarea></td>
  </tr>
  <tr>
		 <th class="regist">사회활동</th>
         <td  class="regist2" colspan="3"><textarea name="fr_memo1" style="width:90%;" rows="3" class="input_textarea"></textarea></td>
  </tr>
  <tr>
		 <th class="regist">포상</th>
         <td class="regist2" colspan="3"><textarea name="fr_memo2" style="width:90%;" rows="3" class="input_textarea"></textarea></td>
  </tr>

  <? if($cf_secret_yn=="Y"){?>
	<tr>
		 <th class="regist">비밀번호</th>
         <td class="regist2" colspan="3"><input type="password" name="fr_passwd" value=""  maxlength="50"></td>
  </tr>
  <? } ?>
</table>
<br>
<br>
<br>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
<tr>
    <td height="36" align="center">
        <input type="image" src="<?=$cf_images_dir?>/ok.gif" style="vertical-align:middle;"> &nbsp;&nbsp;&nbsp;&nbsp;
        <a href="javascript:signform.reset();"><img src="<?=$cf_images_dir?>/cancel.gif" border="0" style="vertical-align:middle"></a>
    </td>
</tr>
</table>

<BR>
<BR>


