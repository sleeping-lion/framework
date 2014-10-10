<?php
# 현재페이지 참조URL : 예) 로그인 후 다시 현재페이지로 오는 경우 등...
if(empty($po_uri))
	$po_uri = $_SERVER['REQUEST_URI'];

if(isset($cf_cook_nm)) {
	# ---- 로그인 했을때
	// 로그아웃
	$tm_login_img = "LOGOUT";
	$tm_login_url = "/member/login/logout.html";

	// 정보수정
	$tm_join_img = "MYPAGE";
	$tm_join_url = "/member/register/register.html?a_gb=member&amp;a_cd=1&amp;a_item=0&amp;sm=5_2&amp;po_uri=" . urlencode($po_uri);

} else {
	# ---- 로그인 안 했을때
	// 로그인
	$tm_login_img = "LOGIN";
	$tm_login_url = "/member/login/login.html?sm=5_1&amp;po_uri=" . urlencode($po_uri);

	// 회원가입
	$tm_join_img = "JOIN";
	$tm_join_url = "/member/register/register.html?a_gb=member&amp;a_cd=1&amp;a_item=0&amp;sm=5_2&amp;po_uri=" . urlencode($po_uri);

	$tm_find_img= "아이디/비밀번호 찾기";
	$tm_find_url = "/member/login/find_id.html?sm=5_5&po_uri=" . urlencode($po_uri);
	$tm_find_url2 = "/member/login/find_pass.html?sm=5_6&po_uri=" . urlencode($po_uri);
}


######################################
// title이미지및 left메뉴 결정 등등 

if(isset($sm)) {
	$tm_menu_arr = explode("_", $sm);
	$tm_menu_num = $tm_menu_arr[0];
	$tm_submenu_num = $tm_menu_arr[1];
	$tm_subsmenu_num = $tm_menu_arr[2];
	unset($tm_menu_arr);
}

// 메뉴번호가 없는경우
if(empty($tm_menu_num))
$tm_menu_num = 1;

if(empty($tm_submenu_num))
$tm_submenu_num = 1;


######################################
// left 메뉴 결정


$left_include = "left".$tm_menu_num.".inc";

######################################
// css
if($cf_css_dir == "/css/common.css") {
	$CSS = '<link rel="stylesheet" href="/css/common.css" type="text/css" />';
} else {
	$CSS = '<link rel="stylesheet" href="/css/common.css" type="text/css" /><link rel="stylesheet" href="'.$cf_css_dir.'" type="text/css" />';
}

#########################
// position설정
$menu_nm = array(
		"1" => array(
					"0" => "인사말",
					"1" => "인사말씀",
					"2" => "시설소개"					
				),
		"2" => array(
					"0" => "강의안내",
					"1" => "수강안내 및 수강료",					
					"2" => "강사소개"
				),
		"3" => array(
					"0" => "커뮤니티",		
					"1" => "아카데미 소식",
					"2" => "동호회 소식",
					"3" => "자유게시판"
				),

		"4" => array(
					"0" => "찾아오시는길",
					"1" => "찾아오시는길"
				),
		"5" => array(
					"0" => "사이트맵",
					"1" => "사이트맵"
				),
		"6" => array(
					"0" => "공지사항",
					"1" => "공지사항"
				),
		"7" => array(
					"0" => "회원관리",
					"1" => "로그인",
					"2" => "회원가입",
					"3" => "아이디/비밀번호찾기",
					"4" => "로그아웃",
					"5" => "회원정보수정",
					"6" => "회원탈퇴",
					"7" => "이용약관",
					"8" => "개인정보보호정책",
					"9" => "",
					"10" => ""
					),
		"8" => array(
					"0" => "사이트맵",
					"1" => "사이트맵"
				)
	);

if(isset($cf_cook_id)) {
	$menu_nm[8][9] = "";
	$menu_nm[8][7] = "";
}else{
	$menu_nm[8][8] = "";
	$menu_nm[8][10] = "";
}



######################################
// 타이틀 이미지
$title_images = "title".$tm_menu_num."_".$tm_submenu_num.".gif";
if(file_exists($_SERVER['DOCUMENT_ROOT']."/images/title/".$title_images)) {
	$title_images = "<img src=\"/images/title/".$title_images."\">";
} else {
	$title_images = "<img src=\"/images/title/title_1_1.gif\">";
}
?>
