<?php
	#New Icon 출력위해 변수 설정
	$tm_new_mark_time = 2;

	$time_limit = 60*60*24 * $tm_new_mark_time;
	$sql = "SELECT lclass,mclass,sclass,state,lessons,no,subject,memo,input_ymdhms FROM $board_table_name WHERE gb='$board_gb'  ORDER BY no DESC LIMIT $board_limit";
	$result = mysql_query($sql);
	if(!$result) echo mysql_error();
	$total_no = mysql_num_rows($result);
	$i=0;
	while($row = mysql_fetch_array($result)){
		$subject = substr_byte($row[subject],50);
		$lessons = $row[lessons];
		$lclass= $row[lclass];
		$mclass= $row[mclass];

		if($row[state]=="0"){
			$state="<img src=\"/images/edu_ico_app.gif\" alt=\"접수중\"/>";
		}else if($row[state]=="1"){
			$state="<img src=\"/images/edu_ico_end.gif\" alt=\"신청완료\"/>";
		}else if($row[state]=="2"){
			$state="<img src=\"/images/edu_ico_study.gif\" alt=\"학습중\"/>";
		}

	switch ($lclass){
		case "i_1000";
			$board_cd="1";
			if($mclass=="i_1100"){
				$board_sm="3_4";
			}else if($mclass=="i_1200"){
				$board_sm="3_6";
			}
		break;

		case "i_2000";
			$board_cd="2";
			$board_sm="2_1";
		break;
		case "i_3000";
			if(!$mclass){
			$board_cd="2";
			$board_sm="4_1";
			}else if($mclass=="i_3200"){
			$board_cd="3";
			$board_sm="4_2";
			}

		break;
	}

?>
	 
<tr>
	<td class="list">
	<a href='/common/edu_proc/listbody.html?a_gb=edu&amp;a_cd=<?=$board_cd?>&amp;a_item=0&amp;sm=<?=$board_sm?>&amp;lclass=<?=$lclass?>&amp;mclass=<?=$mclass?>&amp;po_no=<?=$row[no]?>'><?=$subject?></a></td>
	<td><?=$lessons?> </td>
	<td><?=$state?></td>
	</tr>

<?php

	$i=$i+1;
}
	if($total_no < $board_limit){
		for($i=0;$i<($board_limit-$total_no);$i++){
?>
							<tr>
								<td class="list">&nbsp;</td>
								<td>&nbsp;</td>
								<td>&nbsp;</td>
							</tr>
								
<?php
		}
	}
?>