<?
	//-- 검색종류가 선택박스인경우 검색 변수 처리
	if($_POST[keyfield])
	{
		if($_POST[keyfield] == "total")
		{
			$keyfield_name = "it_name";
			$keyfield_company = "it_company";
			$keyfield_brand = "it_brand";
		}
		else if($_POST[keyfield] == "it_name")
		{
			$keyfield_name = "it_name";
		}
		else if($_POST[keyfield] == "it_company")
		{
			$keyfield_company = "it_company";
		}
		else if($_POST[keyfield] == "it_no")
		{
			$keyfield_no = "it_no";
		}
	}
	//-- 검색종류가 선택박스인경우 검색 변수 처리 끝

	// 링크를 위한 쿼리 정의 - 기본쿼리(항상유지되야할쿼리) - adv쿼리(검색을 고려한쿼리)
    $po_basic_query = $cf_basic_nm;
	$po_adv_query = $po_basic_query;
	if($check_line) $po_adv_query .= "&check_line=$check_line";
	if($key) $po_adv_query .= "&keyfield_name=$keyfield_name&keyfield_company=$keyfield_company&keyfield_brand=$keyfield_brand&key=$encoded_key";
	if($po_it_lclass) $po_adv_query .= "&po_it_lclass=$po_it_lclass";
	if($po_it_mclass) $po_adv_query .= "&po_it_mclass=$po_it_mclass";
	if($po_it_sclass) $po_adv_query .= "&po_it_sclass=$po_it_sclass";
	if($po_it_event_cd) $po_adv_query .= "&po_it_event_cd=$po_it_event_cd";

	// 화일저장경로 (상품목록은 /files/item 에 저장한다.
	//$cf_savedir = "/files/item";
	//$cf_savedir_physical = $_SERVER[DOCUMENT_ROOT] . $cf_savedir;

	######################
	// 사운드 URL
	$cf_sound_path = "/files/sound";
?>

