// FORM 전송시 체크사항
function checkIt(flag)
{
	var form = document.signform;

	// 사이트명
	if(!ChkEle(form.fr_site_nm.value, "C", 1, 40)) return Error("사이트명은 필수 입력입니다.", form.fr_site_nm);
    
	// metatile
	if(!ChkEle(form.fr_meta_title.value, "C", 1, 250)) return Error("제목 표시줄은 필수 입력입니다.", form.fr_meta_title);

	// email
	if(!ChkEle(form.fr_mail_from.value, "C", 1, 250)) return Error("이메일 주소는 필수 입력입니다.", form.fr_mail_from);

	
}

