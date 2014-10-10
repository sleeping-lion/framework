<?
	//-- 검색종류가 선택박스인경우 검색 변수 처리
	if($_POST[keyfield])
	{
		if($_POST[keyfield] == "total")
		{
			$keyfield_subject = "subject";
			$keyfield_input_nm = "sign_nm";
			$keyfield_memo = "memo";
		}
		else if($_POST[keyfield] == "subject")
		{
			$keyfield_subject = "subject";
		}
		else if($_POST[keyfield] == "sign_nm")
		{
			$keyfield_input_nm = "sign_nm";
		}
		else if($_POST[keyfield] == "memo")
		{
			$keyfield_memo = "memo";
		}
	}

	//-- 검색종류가 선택박스인경우 검색 변수 처리 끝

	// 링크를 위한 쿼리 정의 - 기본쿼리(항상유지되야할쿼리) - adv쿼리(검색을 고려한쿼리)
    $po_basic_query = $cf_basic_nm;
	$po_adv_query = $po_basic_query;
	if($check_line) $po_adv_query .= "&check_line=$check_line";
	if($key) $po_adv_query .= "&keyfield_input_nm=$keyfield_input_nm&keyfield_subject=$keyfield_subject&keyfield_memo=$keyfield_memo&key=$encoded_key";
	if($po_l_cate) $po_adv_query .="&po_l_cate=$po_l_cate";
	if($po_m_cate) $po_adv_query .="&po_m_cate=$po_m_cate";

	//메일주소 관련 
	$mail_arr = array("chol.com", "dreamwiz.com", "empal.com", "freechal.com","gmail.com","hanmail.net", "hanmir.com", "hitel.net", "hotmail.com","korea.com","nate.com","naver.com","orgio.net","paran.com","shinbiro.com","yahoo.co.kr","yahoo.com");
?>