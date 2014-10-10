<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="2" cellpadding="2" >
  <tr align='center'>
    <td>▷ <font color="#CC3300"> * </font>표가 있는 항목은 반드시 입력하시기 바랍니다. ◁</td>
  </tr>
</table>

<table width='<?=$cf_table_wd_large?>' border="0" cellspacing="1" cellpadding="0" >
  <tr>
    <td bgColor="#626262">
      <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="1" cellpadding="5">
        <tr>
          <td width='20%' class="td1">코드구분<font size=2 color=#CC3300> *</font></font></td>
          <td width='80%' bgColor="#FFFFFF"><?=$po_gb?></td>
        </tr>

        <tr>
          <td class='td1'>코&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp드<font size=2 color=#CC3300> *</font></td>
          <td bgColor="#FFFFFF"><input type="text" name="fr_cd" size="40" maxlength="20" value="<?=$my_cd?>"></td>
        </tr>

        <tr>
          <td class='td1'>코&nbsp;&nbsp드&nbsp;&nbsp명<font size=2 color=#CC3300> *</font></td>
          <td bgColor="#FFFFFF"><input type="text" name="fr_nm" size="40" maxlength="40" value="<?=$my_nm?>"></td>
        </tr>   

        <tr>
          <td class='td1'>관리항목코드</td>
          <td bgColor="#FFFFFF"><input type="text" name="fr_con_cd" size="40" maxlength="10" value="<?=$my_con_cd?>"></td>
        </tr>   
   
        <tr>
          <td class='td1'>코드영문명</td>
          <td bgColor="#FFFFFF"><input type="text" name="fr_enm" size="40" maxlength="40" value="<?=$my_enm?>"></td>
        </tr>
  
        <tr>
          <td class='td1'>코드설명</td>
          <td bgColor="#FFFFFF"><input type="text" name="fr_nm_desc" size="60" maxlength="120" value="<?=$my_nm_desc?>"></td> 
        </tr>

        <tr>
          <td class='td1'>비 &nbsp; &nbsp; &nbsp; &nbsp 고<p><font size=2>(태그<font color=red>불가</font>)</font></td>
          <td bgColor="#FFFFFF"><textarea name="fr_bigo" cols="60" rows="5" wrap ="hard"><?=$my_bigo?></textarea></td>
        </tr>

        <tr>
          <td align="center" colspan="2" bgColor="#DFDFDF">
		    <input type="button" value="쓰기" onClick="checkIt(this.form)">
            <input type="reset" value="다시쓰기">
			<input type="button" value="취소" onClick="history.back();">
          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<BR>
<BR>
