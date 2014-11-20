$(document).ready(function() {
	$("#sl_login_form").submit(function(){
		var userId=$.trim($("#sl_user_email").val());
		var password=$.trim($("#sl_user_password").val());
		var token=$(this).find('input[name="token"]').val();
		$("#sl_login_form .error_message").html('');
		
		if(userId=='') {
			$("#sl_login_form .error_message").html('아이디를 입력해주세요');
			return false;
		}
		
		if(password=='') {
			$("#sl_login_form .error_message").html('비밀번호를 입력해주세요');
			return false;
		}
		
		if($("#remember_id").is(":checked")) {
			setCookie('user_id',userId);
		}
		
		var password=hex_sha1(password);
		$.post($(this).attr('action'),{'user_id':userId,'token':token,'password':password,'crypt':true,'json':true},function(data){
			if(data.result=='success') {
				alert('로그인 성공');
			} else {
				$('#sl_login_form .error_message').text(data.error_message);
			}
		},'json'); 
		return false;
	});
});



/**
 * 쿠키값 추출
 * @param cookieName 쿠키명
 */
function getCookie( cookieName )
{
 var search = cookieName + "=";
 var cookie = document.cookie;

 // 현재 쿠키가 존재할 경우
 if( cookie.length > 0 )
 {
  // 해당 쿠키명이 존재하는지 검색한 후 존재하면 위치를 리턴.
  startIndex = cookie.indexOf( cookieName );
  // 만약 존재한다면
  if( startIndex != -1 )
  {
   // 값을 얻어내기 위해 시작 인덱스 조절
   startIndex += cookieName.length;

   // 값을 얻어내기 위해 종료 인덱스 추출
   endIndex = cookie.indexOf( ";", startIndex );

   // 만약 종료 인덱스를 못찾게 되면 쿠키 전체길이로 설정
   if( endIndex == -1) endIndex = cookie.length;

   // 쿠키값을 추출하여 리턴
   return cookie.substring( startIndex + 1, endIndex ) ;
  }
  else
  {
   // 쿠키 내에 해당 쿠키가 존재하지 않을 경우
   return false;
  }
 }
 else
 {
  // 쿠키 자체가 없을 경우
  return false;
 }
}


/**
 * 쿠키 설정
 * @param cookieName 쿠키명
 * @param cookieValue 쿠키값
 * @param expireDay 쿠키 유효날짜
 */
function setCookie( cookieName, cookieValue, expireDate )
{
 var today = new Date();
 today.setDate( today.getDate() + parseInt( expireDate ) );
 document.cookie = cookieName + "=" + cookieValue + "; path=/; expires=" + today.toGMTString() + ";";
}


/**
 * 쿠키 삭제
 * @param cookieName 삭제할 쿠키명
*/
function deleteCookie( cookieName )
{
 var expireDate = new Date();

 //어제 날짜를 쿠키 소멸 날짜로 설정한다.
 expireDate.setDate( expireDate.getDate() - 1 );
 document.cookie = cookieName + "= " + "; expires=" + expireDate.toGMTString() + "; path=/";
}