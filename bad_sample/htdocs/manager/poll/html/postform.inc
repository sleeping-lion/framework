<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="2" cellpadding="2" >
  <tr align='center'>
    <td>▷ <font color="#CC3300"> * 표가 있는 항목은 반드시 입력하시기 바랍니다. ◁</font></td>
  </tr>
</table>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
      <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
        <tr>
          <th width='20%' align='center' class="table_body_menu">구 &nbsp; &nbsp; &nbsp; 분<font size=2 color='red'> *</font></th>
          <td width='*' class="table_body_text">&nbsp;<?=ArrToSelect("fr_poll_type", "class='select'", "==선택==", $poll_type_arr, $my_poll_type)?></td>
        </tr>
        
		<tr>
          <th width='20%' align='center' class="table_body_menu">설&nbsp;문&nbsp;제&nbsp;목<font size=2 color='red'> *</font></th>
          <td width='*' class="table_body_text">&nbsp;<input type="text" name="fr_subject" size="50" maxlength="200" value="<?=$my_subject?>" class="box1"></td>
        </tr>

		<tr>
          <th width='20%' align='center' class="table_body_menu">설&nbsp;문&nbsp;기&nbsp;간<font size=2 color='red'> *</font></th>
          <td width='*' class="table_body_text">&nbsp;<input type="text" name="fr_start_date" size="15" maxlength="15" value="<?=$my_start_date?>" class="box1" readonly="readonly"> <img src="images/btn_date.gif" width="18" height="18"  style="cursor:pointer;vertical-align:middle" onclick="popUpCalendar(this, fr_start_date, 'yyyy-mm-dd')" onkeypress="this.onclick();" alt="달력" /> ~ <input type="text" name="fr_end_date" size="15" maxlength="15" value="<?=$my_end_date?>" class="box1" readonly="readonly"> <img src="images/btn_date.gif" width="18" height="18"  style="cursor:pointer;vertical-align:middle" onclick="popUpCalendar(this, fr_end_date, 'yyyy-mm-dd')" onkeypress="this.onclick();" alt="달력" /></td>
        </tr>

     

        <tr>
          <td align="center" colspan="4" class="page_body">
            <input type="button" value="<?=get_button_value($MY_URI)?>" onClick="checkIt(this.form)" class="input_button">
            <input type="reset" value="<?=get_button_value('reset')?>" class="input_button">
          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<BR>
<BR>
