<?php
#include_once "logon.inc";
#include_once "user_function.inc";
####################################
// 쇼핑몰 설정

##############
// e_best : 베스트 상품     e_new : 신상품 e_com : 일반상품    //e_sale : 세일상품 e_recom : 추천상품
// gb : shop cd : 1=> 쇼핑 2: 장바구니 3: 주문관리

$cf_upload_nm = array("_S_img","_M_img","_L_img");						// 이미지 명
$cf_upload_column_nm = array("작은이미지","중간이미지","확대이미지");	// 이미지 업로드 칼럽명
$cf_upload_no_nm = array("noimg.gif","noimg.gif","noimg.gif");	// 상품이미지가 없을시
$cf_upload_size_nm = array("150 X 150","300 X 300"," 600 X 600");		// 이미지 사이즈

$cf_stock_yn = "Y";						// 재고량 사용유무
$cf_point_yn = "N";						// 포인트구매 사용유무
$cf_carduse_yn = "N";					// 카드 사용 . Y 이면 카드 사용

// 배송비는 DB 에서 설정한다.
// get_send_price_info();
#$free_price_arr = get_send_price_info();
#$cf_free_sending_amt = $free_price_arr[0];
#$cf_sending = $free_price_arr[1];
#$cf_sending_msg1 = $free_price_arr[2];

$cf_free_sending_amt =50000;			// 배송비 무료 최저선
$cf_sending = 2500;						//배송비
$cf_sending_msg1 = "<BR>- 제품의 이미지는 실제와 약간의 차이가 있을 수 있습니다. <BR>- 구매금액이 5만원 이상이면 무료배송입니다(5만원 미만 3,000원 추가) ";

$cf_cardtax = 1.1 ;						// 카드 사용시 금액에 세금(110%) 곱해주기.

############################
// 이니시스 INIpayTest
$cf_inisys_key = "MIR9peacht";
//$cf_inisys_key = "MIR9hihip2";
$cf_inisys_key2 = "ESMIR9peac"; //에스크로용


//////////////////////////////////////////////////////
// 무이자할부 개월수
$cf_it_noisa_price_month = 5;
$cf_it_noisa_low_price = 100000;	// 무이자 할부 최저선


// 신용카드일 때 무조건 세금계산서 발행 안할지 여부.
// /shopping/order/order_postform.html 에서 사용
// Y 면 무조건 발행 안 함
$cf_card_not_accout = "Y";

//세금계산서
//$cf_accout_company_no		= ""; //사업자등록번호
//$cf_accout_company_owner	= ""; //대표자
//$cf_accout_company_add		= "";
//$cf_accout_company_uptae	= "";
//$cf_accout_company_mok		= "";

// 쇼핑몰 관련 테이블 설정
$cf_table_sho_nm = "CM_SHOP_T";				  // 상품 테이블
$cf_table_img_nm = "CM_SHOP_IMG_T";			// 상품 이미지확장자 테이블

$cf_table_car_nm = "MT_CART_T";				  // 장바구니
$cf_table_wish_nm = "MT_WISHLIST_T";				  // 장바구니
$cf_table_ord_nm = "MT_ORDER_T";			  // 주문테이블
$cf_table_cre_nm = "MT_CREDIT_T";			  // 결제 테이블
$cf_table_svi_nm = "CM_SHOP_VIEW_T";		// 오늘본상품
$cf_table_le_lec_nm = "LE_LEC_T";       // 강좌 테이블
$cf_table_le_order_nm = "LE_ORDER_T";   // 강좌 주문 테이블
$cf_table_act_nm = "MT_ACCOUT_T";			// 세금계산서 테이블

$cook_cart_no	= "CK_CM_CART_NO";        // 쿠키설정

if(array_key_exists($cook_cart_no, $_COOKIE))
$cf_cook_cart_no = $_COOKIE[$cook_cart_no]; // 쿠키값설정

// 쇼핑몰 설정파일 완료
######################################
?>