<?php
session_start();
//CASTLE -KISA WEB Attack Defense Tool
//define("__CASTLE_PHP_VERSION_BASE_DIR__" ,"/home/host/castle");
//include_once(__CASTLE_PHP_VERSION_BASE_DIR__."/castle_referee.php");
ini_set("display_error",1);

header("Content-Type: text/html; charset=UTF-8");

// 현재화일 관리명
$MY_URI = basename($_SERVER['SCRIPT_NAME']);
if($MY_URI=='post_update.html'||$MY_URI=='post_wishlist.html') $not_post="1";
$MY_URI = preg_match("/^./", $MY_URI) ? substr($MY_URI, 0, strrpos($MY_URI, ".")) : $MY_URI;
$MY_URI = preg_match("/^_/", $MY_URI) ? substr($MY_URI, 0, strpos($MY_URI, "_")) : $MY_URI;


#---- GET 변수 설정 시작 ---- #
if(is_array($_GET))
{
	foreach($_GET as $KEY => $VALUE)
	{
		unset(${$KEY});
		if($VALUE == "Array" || is_array($VALUE)){
			${$KEY} = $VALUE;
		} else {
			${$KEY} = trim($VALUE);
		}

		# 실행, 쿼리문에 대해서 예외처리
		if((preg_match("/^SELECT/", $VALUE) && preg_match("/^FROM/", $VALUE)) || (preg_match("/^DELETE/", $VALUE) && preg_match("/^FROM/", $VALUE)) || (preg_match("/^UPDATE/", $VALUE) && preg_match("/^SET/", $VALUE)) || (preg_match("/^INSERT/", $VALUE) && preg_match("/^INTO/", $VALUE))){
			echo "<SCRIPT LANGUAGE='JavaScript'>";
			echo " location.href='/'";
			echo "</SCRIPT>";
			exit;
		}
	}
}
# ---- GET 변수 설정 끝 ---- #

# ---- POST 변수 설정 시작 ---- #
if(is_array($_POST))
{
	foreach($_POST as $KEY => $VALUE)
	{
		unset(${$KEY});
		if($VALUE == "Array" || is_array($VALUE)) {
			${$KEY} = $VALUE;
		} else {
			${$KEY} = trim($VALUE);
		}

		# 실행, 쿼리문에 대해서 예외처리
		if((eregi("SELECT", $VALUE) && eregi("FROM", $VALUE)) || (eregi("DELETE", $VALUE) && eregi("FROM", $VALUE)) || (eregi("UPDATE", $VALUE) && eregi("SET", $VALUE)) || (eregi("INSERT", $VALUE) && eregi("INTO", $VALUE))){
			echo "<SCRIPT LANGUAGE='JavaScript'>";
			echo " location.href='/'";
			echo "</SCRIPT>";
			exit;
		}

	}
}
#---- POST 변수 설정 끝 ---- #

# ---- COOKIE 변수 설정 시작 ---- #
if(is_array($_COOKIE))
{
	foreach($_COOKIE as $KEY => $VALUE)
	{
		if($_COOKIE[$KEY] == "deleted")
			unset($_COOKIE[$KEY]);
	}
}
#---- COOKIE 변수 설정 끝 ---- #

// 사용한 변수 파기
unset($KEY);
unset($VALUE);

# ---- COOKIE 변수 설정 시작 ----#
// 쿠키명설정
$cook_id        = "CK_CM_ID";
$cook_nm        = "CK_CM_NM";
$cook_jumin2     = "CK_CM_JUMIN2";
$cook_userno     = "CK_CM_USERNO";
$cook_passwd    = "CK_CM_PASSWD";
$cook_email     = "CK_CM_EMAIL";
$cook_level     = "CK_CM_LEVEL";
$cook_log_cnt   = "CK_CM_LOG_CNT";
$cook_last_time = "CK_CM_LAST_TIME";

$cook_find_id	= "CK_CM_FIND_ID";
$cook_find_nm	= "CK_CM_FIND_NM";
$cook_find_ssno = "CK_CM_FIND_SSNO";
$cook_find_email = "CK_CM_FIND_EMAIL";
$cook_find_ok	= "CK_CM_FIND_OK";
$cook_find_pw	= "CK_CM_FIND_PASSWD";

$cook_cart_no	= "CK_CART_NO";
$cook_check_order	= "CK_CHECK_ORDER";

// 쿠키값설정
if(isset($_SESSION['USER_ID']))
$cf_cook_id = $_SESSION['USER_ID'];

if(isset($_SESSION['USER_NAME']))
$cf_cook_nm = $_SESSION['USER_NAME'];

if(array_key_exists($cook_jumin2, $_COOKIE))
$cf_cook_jumin2 = $_COOKIE[$cook_jumin2];

if(array_key_exists($cook_userno, $_COOKIE))
$cf_cook_userno = $_COOKIE[$cook_userno];

if(array_key_exists($cook_passwd, $_COOKIE))
$cf_cook_passwd = $_COOKIE[$cook_passwd];

if(array_key_exists($cook_email, $_COOKIE))
$cf_cook_email = $_COOKIE[$cook_email];

if(isset($_SESSION['USER_LEVEL']))
$cf_cook_level = $_SESSION['USER_LEVEL'];

if(array_key_exists($cook_log_cnt, $_COOKIE))
$cf_cook_log_cnt = $_COOKIE[$cook_log_cnt];

if(array_key_exists($cook_last_time, $_COOKIE))
$cf_cook_last_time = $_COOKIE[$cook_last_time];

if(array_key_exists($cook_find_id, $_COOKIE))
$cf_cook_find_id = $_COOKIE[$cook_find_id];

if(array_key_exists($cook_find_nm, $_COOKIE))
$cf_cook_find_nm = $_COOKIE[$cook_find_nm];

if(array_key_exists($cook_find_ssno, $_COOKIE))
$cf_cook_find_ssno = $_COOKIE[$cook_find_ssno];

if(array_key_exists($cook_find_email, $_COOKIE))
$cf_cook_find_email = $_COOKIE[$cook_find_email];

if(array_key_exists($cook_find_ok, $_COOKIE))
$cf_cook_find_ok = $_COOKIE[$cook_find_ok];

if(array_key_exists($cook_find_pw, $_COOKIE))
$cf_cook_find_pw = $_COOKIE[$cook_find_pw];

if(array_key_exists($cook_cart_no, $_COOKIE))
$cf_cook_cart_no = $_COOKIE[$cook_cart_no];

if(array_key_exists($cook_check_order, $_COOKIE))
$cf_cook_check_order = $_COOKIE[$cook_check_order];

# ---- COOKIE 변수 설정 끝 ---- #

# ------------------------------------------------------------ #
#	DB 테이블 이름 관련정보 정리 시작
# ------------------------------------------------------------ #
// 공통테이블
$cf_table_cod_nm = "CM_CODE_C";				// 사용코드테이블명
$cf_table_mem_nm = "CM_MEMBER_T";			// 사용회원테이블명
$cf_table_pgm_nm = "CM_TABLE_T";			// 사용프로그램관지자명
$cf_table_itm_nm = "CM_SHOP_T";			// 사용실적소개테이블명
$cf_table_act_nm = "MT_ACCOUT_T";			// 세금계산서

$cf_table_cou_nm = "CM_COUNTER_T";			// 카운터
$cf_table_cob_nm = "CM_CO_OSBROWSER_T";		// os browser
$cf_table_cor_nm = "CM_CO_REFERER_T";		// referer
$cf_table_cip_nm = "CM_CO_IP_T";			// connect ip
$cf_table_cti_nm = "CM_CO_TIME_T";			// time

# ------------------------------------------------------------ #
#	DB 테이블 이름 관련정보 정리 끝
# ------------------------------------------------------------ #



// 시스템 이메일 관련
//$cf_cookie_url = $_SERVER[HTTP_HOST];
$cf_cookie_url = ".peachtech.co.kr";
//$cf_cookie_url = "webmaster@peachtech.co.kr";
$cf_site_code = "korea";
//$cf_mailserver = "mail.mir9.co.kr";
$cf_mail_from = "webmaster@peachtech.co.kr";			// (글등록/수정/삭제) 메일을 보낼때 (보내는사람이름/메일주소)

$cf_mail_from_name = "피치텍";


// 사이트 명칭 및 URL 관련
$cf_site_nm = "종로당구";								// 사이트명
$cf_site_tel = "02-859-3477";
$cf_site_url = "http://".$_SERVER['HTTP_HOST'];			// 사이트URL
//$cf_site_url = "http://www.peachtech.co.kr";
$cf_mainpage = "http://".$_SERVER['HTTP_HOST'];
$cf_mainpage_index = "/index.html";




include "shop_config.inc";

$cf_css_dir = "/css/common.css";						// default CSS
$cf_skin_nm = dirname($_SERVER['SCRIPT_NAME']) . "/html";	// default SKIN

if(isset($cf_images_dir)) {
$cf_images_dir = $cf_images_dir;
} else {
$cf_images_dir="images";	 // defalut image directory
}


# ---- 각종 링크 및 쿼리정보 ---- #
// 링크를 위한 쿼리 정의 - 기본쿼리(항상유지되야할쿼리) - adv쿼리(검색을 고려한쿼리)
// 게시판별 적용쿼리는 각 게시판 디렉토리에 있다.

if(isset($key))
$encoded_key = urlencode($key);

$cf_basic_nm='';

if(isset($a_gb) AND isset($a_cd) AND isset($a_item))
$cf_basic_nm .= "a_gb=$a_gb&a_cd=$a_cd&a_item=$a_item";

if(isset($sm))
	$cf_basic_nm .= "&sm=$sm";

if(isset($key))
	$cf_adv_nm = $cf_basic_nm . "&keyfield_input_nm=$keyfield_input_nm&keyfield_subject=$keyfield_subject&keyfield_memo=$keyfield_memo&key=$encoded_key";

$t_url = $cf_site_url . "/member/login/login.html?a_gb=member&a_cd=3&a_item=0&sm=7_1&po_uri=" . urlencode($_SERVER['REQUEST_URI']);

$cf_admin_dir="manager";
$cf_module_web_editor = "/daumeditor/";
$cf_file_length = 1;
?>