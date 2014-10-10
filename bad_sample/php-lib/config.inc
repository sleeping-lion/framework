<?php
// ---------------------------------------------------------------- //
//	프로그램 관리자를 통한 프로그램관련 변수설정
// ---------------------------------------------------------------- //

# ---- 프로그램 관리자 사용여부 확인
// a_gb 가 "html" 인경우 cm_config.inc 화일을 사용할 수 없다.
if($a_gb == "html")
{
	error_msg("프로그램 관리자 설정에러입니다.\\n\\n관리자에게 문의하세요", "back");
	exit;
}

// 종합코드 초기화 변수
$cf_c_cd_gb = "0code";							// 종합코드 초기화 변수

// 프로그램관리 변수
$cf_css_dir = "/css/common.css";					// CSS
$cf_images_dir = "images";						// 기본 이미지 디렉토리
$cf_num_per_page = 10;							// 한 페이지당 출력할 게시물의 수
$cf_page_per_block = 10;						// 게시물 출력목록 하단에 링크를 걸 페이지의 개수
$cf_admin_email = "wlswoqhr@mir9.co.kr";			// 게시판 관리자의 전자우편주소
$cf_tel_no = "031-497-8833";						// 게시판 관리자의 전화번호
$cf_notify_new_article = 1;						// New 마크 표시시간
$cf_savedir = "/files/$a_gb.$a_cd";				// 첨부화일 경로

// 게시판관리 변수
$BG_COLOR				= "#FFFFFF";
$LIST_TH_COLOR			= "#D7E3EC";
$LIST_TH_FONT_COLOR		= "#000066";
$LIST_TD_COLOR			= "#FFFFFF";
$VW_TH_COLOR			= "#f5f8fa";
$VW_TD_COLOR			= "#FFFFFF";
$VW_FRAME_BG			= "#95B5CA";
$VW_BODY_TITLE			= "#000066";
$VW_BODY_SUBJ			= "#000066";
$VW_BG_SUBJ				= "#D7E3EC";
$LIST_SEARCH_COLOR		= "#F6F6F6";
$ITEM_NECESSARY_COLOR	= "#CC3300";

# ------------------------------------------------------------ #
#	프로그램 관리자를 통한 프로그램관련 변수설정 시작
# ------------------------------------------------------------ #
// 프로그램관리자에서 설정을 읽는다.
include "cm_table_t.inc";

// 첨부화일 경로
$cf_savedir_physical = $_SERVER['DOCUMENT_ROOT'] . $cf_savedir;

// 쿼리 및 경로로 프로그램의 안정성을 체크한다.
// 프로그램 관리자에 등록된 경로명과 현재 경로명이 일치하지 않으면 부적절한 접근이다.
//echo dirname($_SERVER[SCRIPT_NAME]);
//echo $cf_path_url;
//echo dirname($_SERVER[SCRIPT_NAME]);
//exit;
if($cf_path_url != dirname($_SERVER['SCRIPT_NAME'])  )
{
?>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>시스템 메시지</title>
</head>
<body>
<?php
	error_msg("부적절한 접근입니다.\\n\\n메뉴를 통한 정상적인 접근을 해주세요.", "/");

	exit;
}
# ------------------------------------------------------------ #
#	프로그램 관리자를 통한 프로그램관련 변수설정 끝
# ------------------------------------------------------------ #


# ------------------------------------------------------------ #
#	관리자권한을 구하기 시작
# ------------------------------------------------------------ #
// 초기화
$cf_top_level_yn = "";
$cf_admin_level_yn = "";
$cf_read_level_yn = "";
$cf_body_level_yn = "";
$cf_post_level_yn = "";
$cf_modify_level_yn = "";
$cf_delete_level_yn = "";
$cf_reply_level_yn = "";

// 실제레벨을 체크한다.
$cm_level = $cf_cook_level ? $cf_cook_level : "zz";		// 로그인하지 않은경우 비회원

// 최고관리자인경우와 관리자 아이디로 지정된경우
if(($cf_admin_id && $_SESSION['USER_ID'] == $cf_admin_id) || $_SESSION['USER_LEVEL'] == "aa" || $_SESSION['USER_LEVEL'] == "bb")
{
	$cf_top_level_yn = "Y";
	$cf_admin_level_yn = "Y";
	$cf_read_level_yn = "Y";
	$cf_body_level_yn = "Y";
	$cf_post_level_yn = "Y";
	$cf_modify_level_yn = "Y";
	$cf_delete_level_yn = "Y";
	$cf_reply_level_yn = "Y";
}
else
{
	// 읽기권한를 체크한다.
	$cf_read_level_yn = get_level_check($cm_level, $cf_read_level);

	// 상세읽기권한를 체크한다.
	$cf_body_level_yn = get_level_check($cm_level,$cf_body_level);

	// 쓰기권한를 체크한다.
	$cf_post_level_yn = get_level_check($cm_level, $cf_post_level);

	// 수정권한를 체크한다.
	$cf_modify_level_yn = get_level_check($cm_level,$cf_modify_level);

	// 삭제권한를 체크한다.
	$cf_delete_level_yn = get_level_check($cm_level,$cf_delete_level);

	// 답변권한를 체크한다.
	$cf_reply_level_yn = get_level_check($cm_level, $cf_reply_level);
}
# ------------------------------------------------------------ #
#	관리자권한을 구하기 끝
# ------------------------------------------------------------ #



# ------------------------------------------------------------ #
#	관리자권한 체크 시작
# ------------------------------------------------------------ #
$MY_ADMIN_URI = get_admin_filename();

switch ($MY_ADMIN_URI)
{
	case ("list") :
		if($cf_read_level_yn != "Y")
		{
			// 로그인한 경우
			if($cf_cook_level)
			{
				// 로그인하자마자 - back할경우 로그인 무한루프
				if($login_now)
					error_msg("회원님은 읽기 권한이 없습니다.", "/");
				else
					error_msg("회원님은 읽기 권한이 없습니다.", "back");
			}
			else
			{
				error_msg("회원전용서비스입니다.\\n\\n로그인 후 사용하세요.",$t_url);
			}
			exit;
		}
		break;

	case ("listbody") :
		if($cf_body_level_yn != "Y")
		{
			if($cf_cook_level)
			{
				if($login_now)
					error_msg("회원님은 읽기 권한이 없습니다.", "/");
				else
					error_msg("회원님은 읽기 권한이 없습니다.", "back");
			}
			else
			{
				error_msg("회원전용서비스입니다.\\n\\n로그인 후 사용하세요.",$t_url);
			}
			exit;
		}
		break;


	case ("post") :
		if($cf_post_level_yn != "Y")
		{
			if($cf_cook_level)
			{
				if($login_now)
					error_msg("회원님은 쓰기 권한이 없습니다.", "/");
				else
					error_msg("회원님은 쓰기 권한이 없습니다.", "back");
			}
			else
			{
				error_msg("회원전용서비스입니다.\\n로그인 후 사용하세요.",$t_url);
			}
			exit;
		}
		break;

	case ("modify") :
		if($cf_modify_level_yn != "Y")
		{
			if($cf_cook_level)
			{
				if($login_now)
					error_msg("회원님은 수정 권한이 없습니다.", "/");
				else
					error_msg("회원님은 수정 권한이 없습니다.", "back");
			}
			else
			{
				error_msg("회원전용서비스입니다.\\n로그인 후 사용하세요.",$t_url);
			}
			exit;
		}
		break;

	case ("delete") :
		if($cf_delete_level_yn != "Y"){
			if($cf_cook_level)
			{
				if($login_now)
					error_msg("회원님은 삭제 권한이 없습니다.", "/");
				else
					error_msg("회원님은 삭제 권한이 없습니다.", "back");
			}
			else
			{
				error_msg("회원전용서비스입니다.\\n로그인 후 사용하세요.",$t_url);
			}
			exit;

		}
		break;

	case ("reply") :
		if($cf_reply_level_yn != "Y"){
			if($cf_cook_level)
			{
				if($login_now)
					error_msg("회원님은 답변 권한이 없습니다.", "/");
				else
					error_msg("회원님은 답변 권한이 없습니다.", "back");
			}
			else
			{
				error_msg("회원전용서비스입니다.\\n로그인 후 사용하세요.",$t_url);
			}
			exit;

		}
		break;

	default :
}
# ------------------------------------------------------------ #
#	관리자권한 체크 끝
# ------------------------------------------------------------ #

//$cf_test_id ="99";	// 환경설정 변수를 출력하고 싶을경우 주석제거
# ------------------------------------------------------------ #
#	환경설정변수 출력 끝
# ------------------------------------------------------------ #
if($cf_test_id == "99")
{
	echo("[사이트URL(cf_site_url)						: $cf_site_url]<br>");
	echo("[메인페이지주소(cf_mainpage)					: $cf_mainpage]<br>");
	echo("[메인페이지인덱스(cf_mainpage_index)				: $cf_mainpage_index]<br>");
	echo("[이미지주소(cf_images_dir)						: $cf_images_dir]<br>");
	echo("[css주소(cf_css_dir)							: $cf_css_dir]<br>");
	echo("[종합코드초기변수(cf_c_cd_gb)					: $cf_c_cd_gb]<br>");
	echo("[최고관리자여부(cf_top_level_yn)				: $cf_top_level_yn]<br>");
	echo("[관리자여부(cf_admin_level_yn)					: $cf_admin_level_yn]<br>");
	echo("[관리자아이디(cf_admin_id)						: $cf_admin_id]<br>");

	echo("[사용테이블명(cf_table_col_nm)					: $cf_table_col_nm]<br>");
	echo("[사용종합코드테이블명(cf_table_cod_nm)			: $cf_table_cod_nm]<br>");
	echo("[사용회원테이블관리명(cf_table_mem_nm)			: $cf_table_mem_nm]<br>");
	echo("[사용프로그램관리테이블명(cf_table_pgm_nm)		: $cf_table_mem_nm]<br>");
	echo("[로그인id(cf_cook_id)							: $cf_cook_id]<br>");
	echo("[로그인명(cf_cook_nm)							: $cf_cook_nm]<br>");
	echo("[로그인레벨(cf_cook_level)						: $cf_cook_level<br>");
	echo("[사이트명(cf_site_nm)							: $cf_site_nm]<br>");

	echo("[게시판명칭(cf_title_nm)						: $cf_title_nm]<br>");
	echo("[국가코드(cf_ctr_cd)							: $cf_ctr_cd]<br>");
	echo("[타이틀이미지(cf_title_images)					: $cf_title_images]<br>");

	echo("[사용테이블명(cf_table_nm)						: $cf_table_nm]<br>");
	echo("[큰테이블크기(cf_table_wd_large)				: $cf_table_wd_large]<br>");
	echo("[작은테이블크기(cf_table_wd_small)				: $cf_table_wd_small]<br>");
	echo("[테이블옆공간(cf_table_wd_space)				: $cf_table_wd_space]<br>");
	echo("[이미지저장위치(cf_images_dir)					: $cf_images_dir]<br>");
	echo("[css저장위치(cf_css_dir)						: $cf_css_dir]<br>");

	echo("[관리자이메일주소(cf_admin_email)				: $cf_admin_email]<br>");
	echo("[메일통보여부(cf_notify_email_yn)				: $cf_notify_email_yn]<br>");
	echo("[메일발송자1(cf_email_id1)						: $cf_email_id1]<br>");
	echo("[메일발송자2(cf_email_id2)						: $cf_email_id2]<br>");
	echo("[메일발송자3(cf_email_id3)						: $cf_email_id3]<br>");
	echo("[관리전화번호(cf_tel_no)						: $cf_tel_no]<br>");
	echo("[비밀번호저장여부(cf_passwd_yn)					: $cf_passwd_yn]<br>");

	echo("[첨부파일위치(cf_savedir)						: $cf_savedir]<br>");
	echo("[첨부물리적적위치(cf_savedir_physical)			: $cf_savedir_physical]<br>");
	echo("[첨부파일사이즈(cf_attach_size)					: $cf_attach_size]<br>");

	echo("[게시물게시시간(초)(cf_notify_new_article)		: $cf_notify_new_article]<br>");
	echo("[출력게시물수(cf_num_per_page)					: $cf_num_per_page]<br>");
	echo("[하단블록수(cf_page_per_block)					: $cf_page_per_block]<br>");
	echo("[태크허용여부(cf_allow_html_yn)					: $cf_allow_html_yn]<br>");
	echo("[게시판종류(cf_board_cd)						: $cf_board_cd]<br>");

	echo("[읽기권한여부(cf_read_level_yn)					: $cf_read_level_yn ]<br>");
	echo("[읽기레벨(cf_read_level)						: $cf_read_level]<br>");
	echo("[여러글읽기사용여부(cf_multy_read_yn)			: $cf_multy_read_yn]<br>");
	echo("[상세읽기레벨(cf_body_level)					: $cf_body_level]<br>");
	echo("[상세읽기권한여부(cf_body_level_yn)				: $cf_body_level_yn]<br>");
	echo("[쓰기레벨(cf_post_level							: $cf_post_level]<br>");
	echo("[쓰기권한여부(cf_post_level_yn)					: $cf_post_level_yn ]<br>");
	echo("[수정권한여부(cf_modify_level_yn)				: $cf_modify_level_yn]<br>");
	echo("[수정레벨(cf_modify_level)						: $cf_modify_level]<br>");
	echo("[수정화면미리보기(cf_modify_review_yn)			: $cf_modify_review_yn]<br>");
	echo("[삭제권한여부(cf_deletelevel_yn)				: $cf_delete_level_yn]<br>");
	echo("[삭제레벨(cf_delete_level)						: $cf_delete_level]<br>");
	echo("[답변여부(cf_reply_yn)							: $cf_reply_yn]<br>");
	echo("[답변권한여부(cf_reply_level_yn)				: $cf_reply_level_yn]<br>");
	echo("[답변레벨(cf_reply_level)						: $cf_reply_level]<br>");
	echo("[답변글한계수(cf_reply_indent)					: $cf_reply_indent]<br>");
	echo("[답변글삭제여부(cf_allow_delete_thread_yn)		: $cf_allow_delete_thread_yn]<br>");

	echo("[HTML_제목(cf_meta_title)						: $cf_meta_title]<br>");
	echo("[HTML_설명(cf_meta_desc)						: $cf_meta_desc]<br>");
	echo("[HTML_키워드(cf_meta_keywd)					: $cf_meta_keywd]<br>");

	echo("[타이틀공지글(cf_title_annou)					: $cf_title_annou]<br>");
	echo("[검색창종류(cf_search_cd)						: $cf_search_cd]<br>");
	echo("[공지글사용여부(cf_annou_yn)					: $cf_annou_yn]<br>");
	echo("[스킨종류(cf_skin_nm)							: $cf_skin_nm]<br>");
	echo("[코멘트글사용여부(cf_comment_yn)					: $cf_comment_yn]<br>");
}
# ------------------------------------------------------------ #
#	환경설정변수 출력 끝
# ------------------------------------------------------------ #
?>