<?
	//-- 검색종류가 선택박스인경우 검색 변수 처리
	if($_POST[keyfield])
	{
		if($_POST[keyfield] == "total")
		{
			$keyfield_nm = "nm";
		}
		else if($_POST[keyfield] == "nm")
		{
			$keyfield_nm = "nm";
		}
	}
	//-- 검색종류가 선택박스인경우 검색 변수 처리 끝

	// 링크를 위한 쿼리 정의 - 기본쿼리(항상유지되야할쿼리) - adv쿼리(검색을 고려한쿼리)
    $po_basic_query = $cf_basic_nm;
	$po_adv_query = $po_basic_query;
	if($check_line) $po_adv_query .= "&check_line=$check_line";
	if($key) $po_adv_query .= "&keyfield_nm=$keyfield_nm&key=$encoded_key";

function cate_check($gcd) {
	global $DB,$cf_table_cod_nm;
	
	$query = "SELECT COUNT(CD) FROM $cf_table_cod_nm WHERE GB='$gcd'";
	return $DB->Value($query);
}

function cate_view($gcd,$cha) {
	global $DB,$cf_table_cod_nm,$po_adv_query;
	
	for($i = 0; $i < $cha; $i++) {
		$tm_nbsp .= "&nbsp;&nbsp;&nbsp;&nbsp;";
	}
	$query = "SELECT * FROM $cf_table_cod_nm WHERE GB='$gcd'";
	$arr = $DB->Pipe_Arr($query);
	for($i = 0; $i < count($arr); $i++) {
		$arr[$i][LISTBODY_LINK] = "listbody.html?$po_adv_query&page=" . $page . "&po_gb=" . $arr[$i][GB]."&po_cd=" . $arr[$i][CD];

		# ---- 메뉴이미지 ---- #
		if(!$arr[$i][ENM]) {
			$arr[$i][ENM] = "N";
		}

		// 2분류 등록
		if($cha == 1) {
			$arr[$i][REG] = get_button_href("상품 분류등록","postform.html?".$po_adv_query."&po_gb=".$arr[$i][GB]."&po_cd=".$arr[$i][CD]."&page=".$page);
		}
		$arr[$i][MODIFY] = get_button_href("수정","modifyform.html?".$po_adv_query."&po_gb=".$arr[$i][GB]."&po_cd=".$arr[$i][CD]."&page=".$page);

		$arr[$i][DEL] = get_button_href("삭제","deleteform.html?".$po_adv_query."&po_gb=".$arr[$i][GB]."&po_cd=".$arr[$i][CD]."&page=".$page);

		
		# ---- 분류명 ---- #
		// $arr[$i][NM];

		if(!$arr[$i][NM])
			$arr[$i][NM] = "분류명없음";

		$tm_list_view = "<tr class=\"table_body\" align=\"center\">";
		$tm_list_view .= "<td align=\"left\">&nbsp;&nbsp;".$tm_nbsp."↗ <a href=\"".$arr[$i][LISTBODY_LINK]."\">".$arr[$i][NM]."</a></td>";
		$tm_list_view .= "<td>".$arr[$i][ENM]."</td>";
        $tm_list_view .= "<td>".$arr[$i][REG]." ".$arr[$i][MODIFY]." ".$arr[$i][DEL]."</td>";
        $tm_list_view .= "</tr>";
		echo $tm_list_view;

		if(cate_check($arr[$i][CD])) {
			cate_view($arr[$i][CD],$cha+1);
		}
	}
}
?>