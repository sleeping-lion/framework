<?
	// 코드
	if(!$fr_cd)
		error_msg("코드를 입력해주세요.", "back");
	
	// 코드명
	if(!$fr_nm)
		error_msg("코드명을 입력해주세요.", "back");

	if($MY_URI == "post") {
		$query = "SELECT COUNT(*) FROM $cf_table_cod_nm WHERE CD = '$fr_cd'";
		if($DB->Value($query))
			error_msg("입력하신 코드는 이미 존재 합니다.\\n\\n 다시 입력하여 주십시오.", "back");
		}
?>
