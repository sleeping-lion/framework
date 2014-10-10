<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
      <table width="<?=$cf_table_wd_small?>" border="0" cellspacing="1" cellpadding="3">
        <tr>
          <th width='20%' align='center' class="table_body_menu">구 &nbsp; &nbsp; &nbsp; 분</th>
          <td width='*' class="table_body_text">&nbsp;<?=$my_poll_type_nm;?></td>
        </tr>
        
		<tr>
          <th width='20%' align='center' class="table_body_menu">설&nbsp;문&nbsp;제&nbsp;목</th>
          <td width='*' class="table_body_text">&nbsp;<?=$my_subject?></td>
        </tr>

		<tr>
          <th width='20%' align='center' class="table_body_menu">설&nbsp;문&nbsp;기&nbsp;간</th>
          <td width='*' class="table_body_text">&nbsp;<?=$my_start_date?> ~ <?=$my_end_date?></td>
        </tr>
       

        <tr>
          <td align="center" colspan="4" class="page_body">
            <input type="submit" value="<?=get_button_value($MY_URI)?>" class="input_button">
            <input type="button" value="취 소" onClick="history.back()" class="input_button">
          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<BR>
<BR>
