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
		 <th class="regist" width="100">접수자</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;" align="left">&nbsp;&nbsp;<?=$my_cm_nm;?></td>
  </tr>
  <tr>
		 <th  class="regist">주소(교실)</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;" align="left">&nbsp;&nbsp;<?=$my_cm_addr;?></td>
  </tr>

   <tr>
		 <th  class="regist">연락처</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;" align="left">&nbsp;&nbsp;<?=$my_cm_tel;?></td>
  </tr>

   <tr>
		 <th  class="regist">방문 희망일</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;" align="left">&nbsp;&nbsp;<?=$my_hope_date;?></td>
  </tr>
   <tr>
		 <th  class="regist">고장 증상</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;" align="left">&nbsp;&nbsp;<?=nl2br($my_trouble_state);?></td>
  </tr>
  <tr>
		 <th class="regist">비고</th>
         <td style="padding-left:3px; height:35px;border-bottom:1px solid #cfcfcf;" align="left">&nbsp;&nbsp;<?=nl2br($my_memo);?></td>
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



<!-- 

<table width="<?=$cf_table_wd_large?>" border="0" cellpadding="0" cellspacing="0">
<tr>
    <td style="border-bottom:3px solid #568832;">&nbsp;</td>
</tr>
<tr>
    <td background="<?=$cf_images_dir?>/view_bg.gif" style="padding-left:15px">
        <BR>


        <table width="<?=$cf_table_wd_large-40?>" border="1" cellspacing="0" cellpadding="3" frame='hsides' bordercolorlight='#aaaaaa' bordercolordark='#FFFFFF'>
        <tr height='37'>
            <th align="center" width="10%">접수 제목</th>
            <td align="left">&nbsp;&nbsp;<?=$my_subject;?></td>
        </tr>

        <tr height='37'>
            <th width="20%" align='center'>접수자</th>
            <td width="80%" align="left">&nbsp;&nbsp;<?=$my_cm_nm;?></td>
        </tr>

        <tr height="37">
            <th align="center">이메일 주소</th>
            <td align="left">&nbsp;&nbsp;<?=$my_cm_email;?></td>
        </tr>

        <tr height="37">
            <th align="center">A/S 접수 내용</th>
            <td align="left">&nbsp;&nbsp;<?=$my_memo;?></td>
        </tr>

        </table>
        <BR>

    </td>
</tr>
<tr>
    <td style="border-top:2px solid #568832;">&nbsp;</td>
</tr>
</table>

<BR>


<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
<tr>
    <td height="36" align="center">
        <?=$LIST?>
    </td>
</tr>
</table>
<BR>
<BR>

 -->