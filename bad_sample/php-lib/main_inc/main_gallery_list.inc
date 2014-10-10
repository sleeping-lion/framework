<?php
	#New Icon 출력위해 변수 설정
	$tm_new_mark_time = 2;
	$time_limit = 60*60*24 * $tm_new_mark_time;
	$sql = "SELECT no,subject,memo,input_ymdhms,real_path FROM $board_table_name WHERE gb='$board_gb' AND cd='$board_cd' ORDER BY no DESC LIMIT 0,$board_limit";
	
	$result = mysql_query($sql);
	if(!$result) echo mysql_error();
	$total_no = mysql_num_rows($result);
	$i=0;
	while($row = mysql_fetch_array($result)){
		$tm_subject = $row[subject];
		$tm_attach_file = "<img src=\"/files/$board_gb.$board_cd/". $row[real_path] ."\" width='85' height='61' border=0  align=\"absmiddle\" >";

?>
		
											 <td align="center">
											  <table width="89" border="0" cellspacing="0" cellpadding="0">
												  <tr>
													<td class="photo">
													<a href="/common/board/listbody.html?a_gb=<?=$board_gb?>&a_cd=<?=$board_cd?>&a_item=0&sm=<?=$board_sm?>&po_no=<?=$row[no]?>"><?=$tm_attach_file?></a>
													</td>
												  </tr>
												  <tr>
													<td align="center" style="padding-top:5px;"><?=$tm_subject?></td>
												  </tr>
											  </table>
											  </td>
	
	
<?php
	$i=$i+1;
}
	if($total_no < $board_limit){
		for($i=0;$i<($board_limit-$total_no);$i++){
?>
											  <td align="center">
											  <table width="89" border="0" cellspacing="0" cellpadding="0">
												  <tr>
													<td class="photo"><img src="/images/sam.gif"></td>
												  </tr>
												  <tr>
													<td align="center" style="padding-top:5px;">&nbsp;</td>
												  </tr>
											  </table>
											  </td>
<?php
		}
	}
?>