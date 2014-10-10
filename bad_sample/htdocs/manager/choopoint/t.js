function checkIt()
{
	var form = eval("document.signform");

	if (!ChkEle(form.fr_con_cd.value, "I"))
	{
		Error("적립금을 입력해주세요!", form.fr_con_cd);
		return;
	}

	signform.submit();
}
