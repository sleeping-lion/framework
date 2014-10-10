<form name="signform" method="post" action="modify.html?<?=$po_adv_query?>">
<table width='<?=$cf_table_wd_large?>' border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
	  <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
	  	<tr>
		  <td class="table_menu" colspan="4" align="center">배송비관리</td>
		  </td>
		</tr>

		<tr>
		  <td class="table_body_menu" >무료배송 최저선<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_con_cd" size="15" maxlength="15" value="<?=$my_con_cd?>" class="box1">
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu" width="20%" cols>배송비<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_enm" size="15" maxlength="15" value="<?=$my_enm?>" class="box1">
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu" width="20%" cols>참고사항</td>
		  <td class="table_body_text" colspan="3">
		  <textarea name="fr_bigo" style="width:95%; height:150px;"><?=$my_bigo?></textarea>
		  </td>
		</tr>
		<tr>
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
			<input type="button" value="수정하기" onClick="checkIt(this.form)" class="input_button">
			</font>
		  </td>
	    </tr>
	  </table>
    </td>
  </tr>
</table>
</form>