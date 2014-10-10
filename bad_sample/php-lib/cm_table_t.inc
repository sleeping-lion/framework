<?php
	$query = "SELECT * FROM $cf_table_pgm_nm WHERE GB = '$a_gb' AND CD = '$a_cd' AND ITEM = '$a_item'";
	$arr = $DB->Pipe_Row($query);
	if(!is_array($arr))
	{
		error_msg("등록되지 않은 프로그램입니다.\\n\\n정상적인 사용을 위해서 프로그램을 먼저 등록해주세요.", "/");
		exit;
	}
	foreach($arr as $k => $v)
	{
		${"cf_" . strtolower($k)} = $v ? $v : ${"cf_" . strtolower($k)};
	}
	unset($arr);
	// 메뉴번호
	if($cf_item_nm)
		$sm = $cf_item_nm;

	// 프로그램에서 참조할 기본 테이블 명칭
	$query = "SELECT NM FROM " . $cf_table_cod_nm . " " .
				"WHERE GB = 'a_table_nm' AND CD = '$cf_table_nm' " ;
	
	$cf_table_col_nm = $DB->Value($query);

	// 타이틀 이미지
	if($cf_title_images)
		$cf_title_images = "/images/title/" . $cf_title_images;

	// 스킨디렉토리
	$cf_skin_nm = $_SERVER[DOCUMENT_ROOT] . $cf_skin_nm;
?>