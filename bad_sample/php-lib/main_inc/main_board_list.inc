<?php
	#New Icon 출력위해 변수 설정
	$tm_new_mark_time = 2;

	$time_limit = 60*60*24 * $tm_new_mark_time;
	$sql = "SELECT no,subject,memo,input_ymdhms FROM $board_table_name WHERE gb='$board_gb' AND cd='$board_cd' and DEPTH=0 ORDER BY no DESC LIMIT $board_limit";
	$result = mysql_query($sql);
	if(!$result) echo mysql_error();
	$total_no = mysql_num_rows($result);
	$i=0;
	while($row = mysql_fetch_array($result)){
		$subject = cutStr($row[subject],50);
		$inputyear =  substr($row[input_ymdhms],0,4);
		$inputmonth =  substr($row[input_ymdhms],4,2);
		$inputday =  substr($row[input_ymdhms],6,2);
		$inpputtime = 	"[".$inputyear.".".$inputmonth.".".$inputday."]";

?>
	  <a href='/common/board/listbody.html?a_gb=<?=$board_gb?>&amp;a_cd=<?=$board_cd?>&amp;a_item=0&amp;sm=<?=$board_sm?>&amp;po_no=<?=$row[no]?>'><span style="font-size:11px;"><?=$inpputtime ?> <?=$subject?></span></a> &nbsp;&nbsp; 
			
<?php

	$i=$i+1;
}
	if($total_no < $board_limit){
		for($i=0;$i<($board_limit-$total_no);$i++){
?>
								 <span style="font-size:11px;">&nbsp;</span>
								
<?php
		}
	}
?>