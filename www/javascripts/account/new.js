$(document).ready(function() {
	$("a[rel]").overlay({	
		mask:'#333',
		onBeforeLoad: function(){
		var wrap = this.getOverlay();
		wrap.load(this.getTrigger().attr("href")+'?no_layout=1');
		oinst= this;
		}
	});
	
	$("#sl_zip1,#sl_zip2").focus(function(){
		$("#sl_find_zip_link").click();
	});	
	
	$("input:password").chromaHash({bars: 3}); //.dPassword()
	
	$("#sl_user_id").keyup(function(){
		var testId=$.trim($(this).val());
		
		if(testId=='' || testId.length<5) {
			$("#a_id").empty();
			$("#sl_user_id").parent().find('.explain').html('5~60자의 문자열을 입력해주세요');		
			return false;
		}
		
		$.getJSON('/account/check/user_id.php',{'user_id':testId,'json':true},function(data){
			if(data.result=='success') {	
				if(data.exist) {
					$('input[name="check_user_id"]').val('0');
					$("#sl_user_id").parent().find('.explain').html('<span id="no_a" style="color:red">이미 사용중인 아이디입니다.</span>');
				} else {
					$('input[name="check_user_id"]').val('1');					
					$("#sl_user_id").parent().find('.explain').html('<span style="color:blue">사용 가능한 아이디입니다.</span>');
				}					
			} else {
				alert('??');
			}
		});
	});
	
	$("#sl_email").keyup(function(){
		var testEmail=$.trim($(this).val());
		
		if(testEmail=='' || testEmail.length<5) {
			$("#a_id").empty();
			$("#sl_user_id").parent().find('.explain').html('5~60자의 문자열을 입력해주세요');		
			return false;
		}
		
		$.getJSON('/account/check/email.php',{'email':testId,'json':true},function(data){
			if(data.result=='success') {	
				if(data.exist) {
					$('input[name="check_email"]').val('0');
					$("#sl_email").parent().find('.explain').html('<span id="no_a" style="color:red">이미 사용중인 이메일입니다.</span>');
				} else {
					$('input[name="check_email"]').val('1');					
					$("#sl_email").parent().find('.explain').html('<span style="color:blue">사용 가능한 이메일입니다.</span>');
				}					
			} else {
				alert('??');
			}
		});
	});	
	
	$('input:text,input:password,select,textarea').focus(function(){
		if($(this).parent().find('.alert').length) {
			$(this).parent().find('.alert').css('color','red');
		} else {
			$(this).parent().find('.explain').show();			
		}
	}).blur(function(){
		if($(this).attr('id')=='user_id' && $(this).next().find('span').attr('id')=='no_a') {
			return false;
		}		
		
		if($(this).parent().parent().attr('id')=='phone') {		
			$(this).parent().parent().css('background','none');
		} else {
			$(this).parent().css('background','none');
			$(this).parent().find('.explain').hide();
		}
	});
	
	$("#sl_password").keyup(function(){
		if($.trim($(this).val())!='') {
			if($.trim($(this).val())==$("#sl_password_confirm").val()) {
				$("#sl_password_confirm").parent().css('background','none');				
				$("#sl_password_confirm").parent().find('.alert').remove();
			}
		}			
	});
	
	$("#sl_password_confirm").keyup(function(){
		if($.trim($(this).val())=='' && $("#sl_password_confirm").parent().find('.alert').length) {
			$("#sl_password_confirm").parent().find('.alert').remove();
			$("#sl_password_confirm").parent().find('.explain').show();
		}
	});	
	
	$("#sl_password_confirm").blur(function(){
		if($.trim($(this).val())!='') {
			if($.trim($("#sl_password").val())!=$.trim($(this).val())) {
				$("#sl_password_confirm").parent().css('background','#FFEE99');
				$("#sl_password_confirm").parent().find('.alert').remove();				
				$("#sl_password_confirm").parent().append('<span class="alert">비밀번호가 일치하지 않습니다.</span>')
			} else {
				$("#sl_password_confirm").parent().find('.alert').remove();
			}
		}
	});
	
	
	$("#slboard_account_new_form").submit(function(){
		var result=true;
		$('.required').each(function(){
			if($(this).val() == "") {
				$(this).css('background-color', '#ffc000');
				result=false;
			} else {
				$(this).css('background-color', 'none');				
			}
		});
		
		if(result) {
			if($('#sl_user_id').val().length<5) {
				alert('아이디는5자 이상입니다.');
				$('#sl_user_id').focus();
				$('#sl_user_id').css('background-color', '#ffc000');
				$('html, body').animate( {scrollTop:0} );
				return false;
			}
			
			if($('input[name="check_user_id"]').val()!='1') {
				alert('아이디를 확인해주세요');
				$('#sl_user_id').focus();
				$('#sl_user_id').css('background-color', '#ffc000');
				$('html, body').animate( {scrollTop:0} );
				return false;
			}
			
			var testEmail=$.trim($('#sl_email').val());
			
			var filter = /^([a-zA-Z0-9_\.\-])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})+$/;
			if (!filter.test(testEmail)) {
				return false;
			}
			
			if(testEmail=='') {
				$('#sl_email').parent().find('.explain').html('* 5~12자의 영문 소문자, 숫자, 특수기호( _ )만 사용 할 수 있습니다.');		
				return false;
			}			
			
			/*
			if($('input[name="check_email"]').val()!='1') {
				alert('이메일을 확인해주세요');
				$('#email').focus();
				$('#email').css('background-color', '#ffc000');
				$('html, body').animate( {scrollTop:0} );
				return false;
			}	
			*/		
			
			var password1=$.trim($('#sl_password').val());
			var password2=$.trim($('#sl_password_confirm').val());
			
			if(password1.length<6) {
				alert('비밀번호는 6자 이상입니다.');
				$('#sl_password').focus();
				$('#sl_password').css('background-color', '#ffc000');
				$('html, body').animate( {scrollTop:0} );
				return false;
			}
			
			if(password2.length<6) {
				alert('비밀번호확인은 6자 이상입니다.');
				$('#sl_password_confirm').focus();
				$('#sl_password_confirm').css('background-color', '#ffc000');
				$('html, body').animate( {scrollTop:0} );
				return false;				
			}
			
			if(password1!=password2) {
				alert('비밀번호와 비밀번호 확인이 같지 않습니다.');
				$('#sl_password_confirm').focus();
				$('#sl_password_confirm').css('background-color', '#ffc000');
				$('html, body').animate( {scrollTop:0} );
				return false;						
			}
			submit();
		} else {
			alert('필수 항목 미입력이 있습니다.');
			$('html, body').animate( {scrollTop:0} );
			return false;
		}
	});	
});