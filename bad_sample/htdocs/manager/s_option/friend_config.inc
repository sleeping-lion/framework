<?
//aa 최고관리자 bb관리자
if(!$cf_cook_id || ($cf_cook_id && ($cf_cook_level != "aa" && $cf_cook_level != "bb"))) {
?>
	<SCRIPT LANGUAGE="JavaScript">
	<!--
		alert("로그인 해주세요.");
		location.href="<?=$t_url?>";
	//-->
	</SCRIPT>
<?
	exit;
}


$cf_table_wd_large = "600";
?>

<meta http-equiv="Content-Type" content="text/html; charset=euc-kr">
<link href="/css/text.css" rel="stylesheet" type="text/css">
<link href="/css/manager.css" rel="stylesheet" type="text/css">