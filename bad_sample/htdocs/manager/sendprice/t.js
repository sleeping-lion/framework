function checkIt()
{
	var form = eval("document.signform");

	if (!ChkEle(form.fr_con_cd.value, "I"))
	{
		Error("무료배송 최저금액을 입력해주세요!", form.fr_con_cd);
		return;
	}

	if (!ChkEle(form.fr_enm.value, "I"))
	{
		Error("배송비를 입력해주세요!", form.fr_enm);
		return;
	}

	signform.submit();
}
