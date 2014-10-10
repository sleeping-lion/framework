<style type="text/css">
<!--
.regist {font-family : "나눔고딕";	  font-size:10pt;	color : #245caf; text-align:left; padding-left:10px;border-bottom:1px solid #cfcfcf;}
-->
</style>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="3" cellpadding="10" >
  <tr>
    <td align="center" bgcolor='#FFFFFF'>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
 <tr>
   <td height='2' bgcolor='#245caf'></td>
 </tr>
</table>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="3" frame='hsides' bordercolorlight='#a1a1a1' bordercolordark='#FFFFFF' align="center">
  <tr>
		 <th width="100" class="regist">신청인</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;"align="left">&nbsp;&nbsp;<?=$my_input_nm;?> <?=$my_sex_text?></td>
  </tr>
  <tr>
		 <th width="100" class="regist">주소</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;"align="left">&nbsp;&nbsp;<?=$my_address;?></td>
  </tr>
  <tr>
		 <th width="100" class="regist">연락처</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;"align="left">&nbsp;&nbsp;<?=$my_hp_tel;?> <?if($my_tel){?>/ <?=$my_tel;?><?}?></td>
  </tr>
  <tr>
		 <th class="regist">현재직업</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;" align="left">&nbsp;&nbsp;<?=$my_job;?></td>
  </tr>
  <tr>
		 <th  class="regist">희망지역</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;" align="left">&nbsp;&nbsp;<?=$my_hope;?></td>
  </tr>
  <tr>
		 <th  class="regist">사업동기</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;" align="left">&nbsp;&nbsp;<?=$my_motive;?></td>
  </tr>
  <tr>
		 <th  class="regist">경력사항</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;" align="left">&nbsp;&nbsp;<?=$my_career;?></td>
  </tr>
  <tr>
		 <th class="regist">사회활동</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;" align="left">&nbsp;&nbsp;<?=nl2br($my_memo1);?></td>
  </tr>
  <tr>
		 <th class="regist">포상</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;" align="left">&nbsp;&nbsp;<?=nl2br($my_memo2);?></td>
  </tr>
  <tr>
		 <th class="regist">처리상태</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;" align="left">&nbsp;&nbsp;<?=$my_status_text;?></td>
  </tr>
</table>
<br>
  </td>
  </tr>
</table>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
<tr>
    <td height="36" align="center">
        <?=$LIST?>
    </td>
</tr>
</table>
<BR>
<BR>


