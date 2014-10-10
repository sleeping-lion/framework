<?
$co_to_day = date("Y-m-d");
unset($arr);
$query = "SELECT * FROM $cf_table_cou_nm WHERE FROM_UNIXTIME(CO_TIME,'%Y-%m-%d') != '$co_to_day'";

$arr = $DB->Pipe_Arr($query);
for($i = 0; $i < count($arr); $i++) {
	
}
?>