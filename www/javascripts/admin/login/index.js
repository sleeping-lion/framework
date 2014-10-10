$(document).ready(function() {
	$("#slboard_admin_login_form").submit(function(){
		var userId=$(this).find('input[name="user_id"]');
		var password=$(this).find('input[name="password"]');
		
		var userIdVal=$.trim(userId.val());
		var passwordVal=$.trim(password.val());
		
		if(userIdVal=='') {
			$("#bar p").html('<img src="/images/admin/error.png" width="16" height="16" alt="error" />&nbsp;아이디를 입력해주세요');
			userId.focus();
			return false;
		}
		
		if(passwordVal=='') {
			$("#bar p").html('<img src="/images/admin/error.png" width="16" height="16" alt="error" />&nbsp;비밀번호를 입력해주세요');
			password.focus();			
			return false;
		}			
		
		$.post($(this).attr('action'),{'user_id':userIdVal,'password':hex_sha1(passwordVal),'token':$(this).find('input[name="token"]').val(),'crypt':true,'json':true},function(data){
			if(data.result=='success') {
				location.href='index.php';
			} else {
				$("#bar p").html('<img src="/images/admin/error.png" width="16" height="16" alt="error" />&nbsp;'+data.error_message);
			}
		},'json');
		
		return false;
	});
});