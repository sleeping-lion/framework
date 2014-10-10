// FORM 전송시 체크사항
function checkIt()
{
	var form = document.signform;

	// 코드
	if(!ChkEle(form.fr_cd.value, "C", 1, 20)) return Error("코드를 입력해주세요.!", form.fr_cd);

	// 코드명
	if(!ChkEle(form.fr_nm.value, "C", 1, 40)) return Error("코드명을 입력해주세요.!", form.fr_nm);

	signform.submit();
}
