$(document).ready(function() {
	$('header nav ul').superfish({delay:400,animation:{opacity:'show', height:'show'},speed:400,autoArrows:  false,dropShadows: false});
	
	
	$('#slboard_contact_new_form').submit(function(){
		var result=true;
		$(this).find('*[required]').each(function(){
			if($(this).val() == "") {
				$(this).css('background-color', '#ffc000');
				result=false;
			} else {
				$(this).css('background-color', 'none');				
			}
		});
		
		if(!result) {
			alert('필수 항목이 입력되지 않았습니다.');
			return false;
		}
		
		var emailVal=$.trim($(this).find('input[name="email"]').val());
		
		var filter = /^([a-zA-Z0-9_\.\-])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})+$/;
		if (!filter.test(emailVal)) {
			alert('정확한 이메일 주소를 입력해주세요');
			$(this).find('input[name="email"]').focus();
			return false;
		}
		
		var query = $(this).serializeArray();
		var json = {'json':true};

		for (i in query) {
			json[query[i].name] = query[i].value;
		}
		
		$.post($(this).attr('action'),json,function(data){
			if(data.result=='success') {
				$('#slboard_contact_new_form').slideUp(function(){
					$("#sl_message_box").slideDown();
				});
			} else {
				
			}			
		},'json');
		return false;
	});
});