<?
unset($arr);
$query = "SELECT SUM(CO_VISIT) FROM $cf_table_cti_nm";
$total = $DB->Value($query);

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
						  <table width="600" border="0" cellpadding="0" cellspacing="0">
							<tr> 
							  <td height="25" class="count_01"> <b><font color="#6600CC" face="Tahoma">
								<font color="#FF6600">年</font></font></b>별 방문자수 <font face="Tahoma"><b>Total</b></font> 
								: <b><?=$total?></b>명</td>
							</tr>
						  </table>
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
							if(!$total) {
								echo "
									<tr> 
									  <td height='75'  align='center'>기록이 없습니다.</td>
									</tr>
									<tr> 
									  <td height='1' bgcolor='cdcdcd'></td>
									</tr>";
							}else {
								unset($arr);
								$query = "SELECT DATE_FORMAT(CO_TIME,'%Y') as YEAR FROM $cf_table_cti_nm GROUP BY YEAR ORDER BY YEAR DESC";
								$arr = $DB->Pipe_Arr($query);

								for($i = 0; $i < count($arr); $i++) {
									$query = "SELECT SUM(CO_VISIT) FROM $cf_table_cti_nm WHERE DATE_FORMAT(CO_TIME,'%Y') = '".$arr[$i][YEAR]."'";
									$total2 = $DB->Value($query);
									$percent = round(100*$total2/$total, 2);
									$percent_width = 344*$percent/100;
							?>
							<tr>
							  <td height='33'> 
								<table width='600' border='0' cellpadding='0' cellspacing='0' class="text-2">
								  <tr> 
									<td width='10' class='count_01'></td>
									<td width='50' class='count_01'><b><?=$arr[$i][YEAR]?></b>년</td>
									<td width='100' class='count_01' align='right'><b><?=$total2?></b>명</td>
									<td width='10'></td>
									<td width='345'>
									  <table width='<?=$percent_width?>' border='0' cellspacing='0' cellpadding='0'>
										<tr> 
										  <td background='images/pix03.gif' height='8'></td>
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
							<?
								}
							}
							?>

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
</table>