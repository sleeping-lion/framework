<style type="text/css">
<!--
.regist {font-family:"나눔고딕"; font-size:10pt;color:#70A535; text-align:left; padding-left:20px;border-bottom:1px solid #CFCFCF; background:#F5F9F1;}
-->
</style>

<!-- <img src="<?=$cf_images_dir?>/inquiry_topimg.jpg" > -->



<?
	if($tm_subject){
		$tm_subject .= "제품 문의드립니다.";
	}
?>
<input type="hidden" name="b_type_yn" value="Y">

<input type="hidden" name="fr_model" id="fr_model"  maxlength="100" value="" />
<input type="hidden" name="fr_model2" id="fr_model2"  maxlength="100" value="" />
<input type="hidden" name="fr_cm_b_type" id="fr_cm_b_type"  maxlength="100" value="" />

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0" align="center" style="border-top:2px solid #70A535;">
  <tr>
		 <th width="100" class="regist">제목</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;"align="left">&nbsp;&nbsp;<input type="text" name="fr_subject" size="80" maxlength="250" value="<?=$tm_subject?>" class='box'></td>
  </tr>
  <tr>
		 <th class="regist">제품명</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;"align="left">&nbsp;&nbsp;<iframe name="ctg" src="get_model.html" width="100%" height="30" frameborder="0"></iframe></td>
  </tr>
  <tr>
		 <th class="regist">업체명/이름</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;" align="left">&nbsp;&nbsp;<input type="text" name="fr_nm" size="30" maxlength="20" value="" class='box'></td>
  </tr>
  <tr>
		 <th  class="regist">이메일 주소</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;" align="left">&nbsp;&nbsp;<input type="text" name="fr_email" size="40" maxlength="250" class='box'></td>
  </tr>
  <tr>
		 <th  class="regist">증상</th>
         <td style="padding-left:3px; height:100px;border-bottom:1px solid #cfcfcf;" align="left"><ul>
		 <?
			for($j=0;$j<count($b_type_arr);$j++){
				?>
				<li style="float:left;width:200px;padding-left:5px;"><input type="checkbox" name="tm_cm_b_type" id="tm_cm_b_type<?=$j?>" value="<?=$b_type_arr[$j][0]?>" onclick="box_check(this.id);"> <label for="tm_cm_b_type<?=$j?>"><?=$b_type_arr[$j][1]?></label> </li>
				<?
			}
		 ?>
			</ul>
			<br/>
			<p style="clear:both;color:#ff0000">* 증상은 1~3개까지 선택 가능합니다.</p>
		 </td>
  </tr>
  <tr>
		 <th class="regist">내용</th>
         <td style="padding-left:3px; height:180px;border-bottom:1px solid #cfcfcf;" align="left">&nbsp;&nbsp;<textarea name="fr_memo" cols="80" rows="10" class="textarea"></textarea></td>
  </tr>

  <? if($cf_secret_yn=="Y"){?>
	<tr>
		 <th class="regist">비밀번호</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;" align="left">&nbsp;&nbsp;<input type="password" name="fr_passwd" value="" size="10" maxlength="50"></td>
  </tr>
  <? } ?>
</table>
<br>


<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
<tr>
    <td height="36" align="center">
        <input type="image" src="<?=$cf_images_dir?>/ok.gif" style="vertical-align:middle;"></a>
        <a href="javascript:signform.reset();"><img src="<?=$cf_images_dir?>/cancel.gif" border="0" style="vertical-align:middle"></a>
    </td>
</tr>
</table>
<BR>
<BR>




