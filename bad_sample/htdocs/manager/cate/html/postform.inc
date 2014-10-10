<input type="hidden" name="po_gb" value="<?=$po_gb?>">
<input type="hidden" name="po_cd" value="<?=$po_cd?>">

<table width='<?=$cf_table_wd_large?>' border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
	  <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
	  	<tr>
		  <td class="table_menu" colspan="4" align="center">제품분류 등록</td>
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu" width="20%">상위코드</td>
		  <td class="table_body_text" colspan="3">
		  <?=get_code_nm($po_cd);?> &nbsp[ <?=$po_cd?> ]
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu">제품 분류코드<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_cd" size="15" maxlength="15" value="<?=$my_cd?>" class="box1">
		  </td>
		</tr>
		<tr>
		  <td class="table_body_menu" width="20%" cols>제품 분류명<font color=#CC3300> *</font></td>
		  <td class="table_body_text" colspan="3">
		  <input type="text" name="fr_nm" size="30" maxlength="30" value="<?=$my_nm?>" class="box1">
		  </td>
		</tr>
		<!-- <tr>
		  <td class="table_body_menu">제품분류 이미지1</td>
		  <td class="table_body_text" colspan="3">
		  <input type="file" name="userfile" size="30" class="box1"> (일반 image) (197 * ?)</td>
	    </tr>
	    <tr>
		  <td class="table_body_menu">제품분류 이미지2</td>
		  <td class="table_body_text" colspan="3">
		  <input type="file" name="userfile2" size="30" class="box1"> (mouse over image) (197 * ?)</td>
	    </tr> -->
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
			<input type="button" value="글 쓰 기" onClick="checkIt(this.form)" class="input_button">
			<input type="reset" value="취  소" class="input_button">
			</font>
		  </td>
	    </tr>
	  </table>
    </td>
  </tr>
</table>
