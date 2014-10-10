<?
$query = "select count(*) from CM_MEMBER_ROUTE ";
$total_record = $DB->Value($query);
?>

<form name="signform" method="post" action="excel.html?<?=$po_adv_query?>">
<input type="hidden" name="counter_type" id="counter_type">
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
								참여 <font face="Tahoma"><b>Total</b></font> 
								: <b><?=$total_record?></b></td>
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
							if($total_record<1) {
								echo "
									<tr> 
									  <td height='75'  align='center'>기록이 없습니다.</td>
									</tr>
									<tr> 
									  <td height='1' bgcolor='cdcdcd'></td>
									</tr>";
							}else {
								unset($arr);
								
								$query3 = "select choice_v,count(choice_v) as cnt from CM_MEMBER_ROUTE group by choice_v order by cnt desc ";
								$arr = $DB->Pipe_Arr($query3);

								for($k=0; $k < 6 ; $k++){
									$choice_v = "";
									$cnt = "";

									$choice_v = $arr[$k][choice_v];
									$cnt = $arr[$k][cnt];

									if($choice_v==1){
										$choice_text = "인터넷 검색";
									}elseif($choice_v==2){
										$choice_text = "TV광고";
									}elseif($choice_v==3){
										$choice_text = "서적이나 잡지, 또는 신문 광고";
									}elseif($choice_v==4){
										$choice_text = "지인들을 통해";
									}elseif($choice_v==5){
										$choice_text = "세미나, 박람회 등을 통해";
									}elseif($choice_v==6){
										$choice_text = "기타";
									}else{
										$choice_text = "TV광고";
										$cnt = 0;
									}


									$percent = round(100*$cnt/$total_record, 2);
									$percent_width = 199*$percent/100;
							?>
							<tr>
							  <td height='33'> 
								<table width='600' border='0' cellpadding='0' cellspacing='0' class="text-2">
								  <tr> 
									<td width='10' class='count_01'></td>
									<td width='*' class='count_01'><b><?=$choice_text?></b></td>
									<td width='100' class='count_01' align='right'><b><?=$cnt?></b>명</td>
									<td width='10'></td>
									<td width='200' style='text-align:left'>
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
	<tr>
		<td style="text-align:right;padding-top:5px;">
			<input type="button" value="ExcelDown" onclick="javascript:counter_excel('5');" class="input_button">
		</td>
	</tr>
</table>
</form>