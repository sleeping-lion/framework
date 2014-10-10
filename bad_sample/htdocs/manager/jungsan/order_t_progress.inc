
<table bgcolor="#FFFFFF" border="0" width="<?=$cf_table_wd_large?>"  cellspacing="0" cellpadding="1" >
  <tr>
    <td class="table_line">
      <table border="0" width="100%"  cellspacing="1" cellpadding="3">
        <tr class="table_menu" align="center">
			<td>
<?
switch($sr_progress) {
	case("50") :
		echo "<input type='radio' name='cheri_update_value' value='60' checked>배송중";
		break;
	case("60") :
		echo "<input type='radio' name='cheri_update_value' value='70' checked>배송완료";
		break;
	case("70") :
		echo "<input type='radio' name='cheri_update_value' value='100' checked>완결&nbsp;&nbsp;";
		echo "<input type='radio' name='cheri_update_value' value='80'>반송<br>";
		echo "<textarea name='fr_reson' cols='60%' rows='3'>반품 / 반송 내역</textarea>";
		break;
	case("80") :
		echo "<input type='radio' name='cheri_update_value' value='50' checked>배송신청&nbsp;&nbsp;";
		echo "<input type='radio' name='cheri_update_value' value='120'>환불<br>";
		break;

}
?>
			</td>
		</tr>
		<tr>
			<td align="center"><?=get_button_href("상태변경","","","onclick=\"J_progress('$po_adv_query');\"");?></td>
		</tr>
	  </table>
	</td>
  </tr>
</table>

<br>