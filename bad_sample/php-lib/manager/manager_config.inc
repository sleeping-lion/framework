<?php
# 현재페이지 참조URL : 예) 로그인 후 다시 현재페이지로 오는 경우 등...
if(empty($po_uri))
	$po_uri = $_SERVER['REQUEST_URI'];

if($cf_cook_id)
{
	# ---- 로그인 했을때
	// 로그아웃
	$tm_login_img = "로그아웃";
	$tm_login_url = "/manager/login/logout.html";

	urlencode($po_uri);

}
else
{
	# ---- 로그인 안 했을때
	// 로그인
	$tm_login_img = "로그인";
	$tm_login_url = "/manager/login/login.html?po_uri=" . urlencode($po_uri);

	// 회원가입
	$tm_join_img = "회원가입";
	$tm_join_url = "/manager/register/register.html?a_gb=member&a_cd=1&a_item=0&po_uri=" . urlencode($po_uri);

}


######################################
// title이미지및 left메뉴 결정 등등 
if(isset($sm)) {
	$tm_menu_arr = explode("_", $sm);
	$tm_menu_num = $tm_menu_arr[0];
	$tm_submenu_num = $tm_menu_arr[1];
	unset($tm_menu_arr);
}

// 메뉴번호가 없는경우
if(empty($tm_menu_num))
$tm_menu_num = 1;

if(empty($tm_submenu_num))
$tm_submenu_num = 1;

######################################
// left 메뉴 결정
if(is_numeric($tm_menu_num)) {
	$manager_left_include = "manager_left".$tm_menu_num.".inc";
} else {
	$manager_left_include = "manager_left1.inc";
}

######################################
// 타이틀 이미지
$title_images = "t".$tm_menu_num."_".$tm_submenu_num.".gif";

if(file_exists($_SERVER['DOCUMENT_ROOT']."/images/title/".$title_images)) {
	$title_images = "<img src=\"/images/title/".$title_images."\">";
} else {
	$title_images = "<img src=\"/images/title/t1_1.gif\">";
}


#########################
// position설정
$menu_nm = array(
		"1" => array(
					"0" => "",
					"1" => "",
					"2" => "",
					"3" => "",
					"4" => "",
					"5" => "",
					"6" => "",
					"7" => "",
					"8" => "",
					"9" => "",
					"10" => ""
				),
		"2" => array(
					"0" => "",
					"1" => "",
					"2" => "",
					"3" => "",
					"4" => "",
					"5" => "",
					"6" => "",
					"7" => "",
					"8" => "",
					"9" => "",
					"10" => ""
				),
		"3" => array(
					"0" => "",
					"1" => "",
					"2" => "",
					"3" => "",
					"4" => "",
					"5" => "",
					"6" => "",
					"7" => "",
					"8" => "",
					"9" => "",
					"10" => ""
				),
		"4" => array(
					"0" => "",
					"1" => "",
					"2" => "",
					"3" => "",
					"4" => "",
					"5" => "",
					"6" => "",
					"7" => "",
					"8" => "",
					"9" => "",
					"10" => ""
				),
		"5" => array(
					"0" => "",
					"1" => "",
					"2" => "",
					"3" => "",
					"4" => "",
					"5" => "",
					"6" => "",
					"7" => "",
					"8" => "",
					"9" => "",
					"10" => ""
				),
		"6" => array(
					"0" => "",
					"1" => "",
					"2" => "",
					"3" => "",
					"4" => "",
					"5" => "",
					"6" => "",
					"7" => "",
					"8" => "",
					"9" => "",
					"10" => ""
				)
	);

//$menu_nm[$tm_menu_num][0]
//$menu_nm[$tm_menu_num][$tm_submenu_num]
?>
