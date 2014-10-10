<?
if(!$po_year) $po_year = date("Y");
if(!$po_month) $po_month = date("m");
unset($arr);
$query = "SELECT SUM(CO_VISIT) FROM $cf_table_cti_nm WHERE YEAR(CO_TIME)='$po_year' AND MONTH(CO_TIME)='$po_month'";
$total = $DB->Value($query);

if(!$total) $total = 0;

?>

<table border="0" width="<?=$cf_table_wd_large?>"  cellspacing="0" cellpadding="1">
	<tr>
		<td class="table_line">
		<table border="0" width="<?=$cf_table_wd_small?>"  cellspacing="1" cellpadding="3">
			<tr class="table_menu" align="center">
				<td>

					<table width="<?=$cf_table_wd_small?>" border="0" cellpadding="0" cellspacing="3" bgcolor="#CCCCCC">
					  <tr> 
						<td align="center" valign="top" bgcolor="#FFFFFF"><br>
						  <table width="600" border="0" cellpadding="0" cellspacing="0" class="text-2">
							<form name="searchform" method="post" action="list.html?<?=$po_adv_query?>">
							<tr> 
							  <td height="25" class="count_01"> <b><font color="#6600CC" face="Tahoma">
								<font color="#FF6600">日</font></font></b>별 방문자수 : <b><?=$po_year?></b>년 <b><?=$po_month?></b>월  <font face="Tahoma"><b>Total</b></font> 
								: <b><?=$total?></b>명</td>
							  <td align="right">
								<select name="po_year" onChange="Select_Menu2();">
									<?for($i = 2005; $i <= date("Y"); $i++) { if($i == $po_year){$se="selected";} else{ $se="";}?>
									<option value="<?=$i?>" <?=$se?>><?=$i?></option>
									<?}?>
								</select> 년
								<select name="po_month" onChange="Select_Menu2();">
									<?for($i = 1; $i <= 12; $i++) { if($i == $po_month){$se="selected";} else{ $se="";}?>
									<option value="<?=$i?>" <?=$se?>><?=$i?></option>
									<?}?>
								</select> 월
							  </td>
							</tr>
							</form>
						  </table>
<form name="signform" method="post" action="excel.html?<?=$po_adv_query?>">
<input type="hidden" name="counter_type" id="counter_type">
<input type="hidden" name="po_year_v" value="<?=$po_year?>">
<input type="hidden" name="po_month_v" value="<?=$po_month?>">
						  <table width="600" border="0" cellspacing="0" cellpadding="0" align="center">
							<tr> 
							  <td height="3" bgcolor="EDEDED"></td>
							</tr>
							<tr> 
							  <td height='1' bgcolor='7D7D7D'></td>
							</tr>
							<tr> 
							  <td>&nbsp; </td>
							</tr>

							<?
							for($i=1;$i<=31;$i++){
								$query="SELECT SUM(CO_VISIT) FROM $cf_table_cti_nm WHERE YEAR(CO_TIME) = '$po_year' AND MONTH(CO_TIME)='$po_month' AND DATE_FORMAT(CO_TIME,'%e')='$i'";
								$t_sum = $DB->Value($query);
								if($max<$t_sum) {
									$max=$t_sum;
								}
							}
							for($i=1;$i<=31;$i++){
								$query="SELECT SUM(CO_VISIT) FROM $cf_table_cti_nm WHERE YEAR(CO_TIME) = '$po_year' AND MONTH(CO_TIME)='$po_month' AND DATE_FORMAT(CO_TIME,'%e')='$i'";
								$total2 = $DB->Value($query);
								if(!$total2) {
									$total2 = 0;
								}
								if($total) {
									$percent = round(100*$total2/$total, 2);
									$percent1 = round(100*$total2/$max, 2);
									$percent_width = 344*$percent1/100;
								}
								if(!$percent_width) $percent_width = "1";
								if($max == $total2) {
									$back_color = "background='images/pix04.gif'";
								}else {
									$back_color = "background='images/pix03.gif'";
								}
							?>
							<tr>
							  <td height='33'> 
								<table width='600' border='0' cellpadding='0' cellspacing='0' class="text-2">
								  <tr> 
									<td width='10' class='count_01'></td>
									<td width='50' class='count_01'><b><?=$i?></b>일</td>
									<td width='100' class='count_01' align='right'><b><?=$total2?></b>명</td>
									<td width='10'></td>
									<td width='345' style='text-align:left'>
									  <table width='<?=$percent_width?>' border='0' cellspacing='0' cellpadding='0'>
										<tr> 
										  <td <?=$back_color?> height='8'></td>
										</tr>
									  </table>
									</td>
									<td width='15' class='count_01'>&nbsp;</td>
									<td width='70' class='count_01'>(<b><?=$percent?></b>%)</td>
								  </tr>
								</table>
							  </td>
							</tr>
							<tr> 
							  <td height='1' bgcolor='cdcdcd'></td>
							</tr>
							<? } ?>

						  </table>
						  <br>
						</td>
					  </tr>
					</table>
				
				</td>
			</tr>
		</table>
		</td>
	</tr>
	<tr>
		<td style="text-align:right;padding-top:5px;">
			<input type="button" value="ExcelDown" onclick="javascript:counter_excel('3');" class="input_button">
		</td>
	</tr>
</table>
</form>