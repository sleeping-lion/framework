function checkIt()
{
	var form = eval("document.signform");

	if (!ChkEle(form.fr_con_cd.value, "I"))
	{
		Error("�ּһ�� �������� �Է����ּ���!", form.fr_con_cd);
		return;
	}

	signform.submit();
}
