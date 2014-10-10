$(document).ready(function() {
	$("#slboard_admin_login_form").submit(function(){		
		var token=$('#slboard_admin_login_form input[name="token"]').val();
		var userId=$('#slboard_admin_login_form input[name="user_id"]').val();		
		var password=$('#slboard_admin_login_form input[name="password"]').val();
		
		if($.trim(userId)=='') {
			alert('아이디를 써주세요');
			return false;
		}
		
		if($.trim(password)=='') {
			alert('비밀번호를 써주세요');
			return false;
		}
		
		var password=hex_sha1(password);
		
		$.post($(this).attr('action'),{'user_id':userId,'token':token,'password':password,'crypt':true,'json':true},function(data){
			if(data.result=='success') {
				alert('로그인 성공');
			} else {
				$('#login_form_error_message').text(data.error_message);
			}
		},'json');
		return false;
	});
});