function checkIt()
{
	var form = eval("document.signform");

	if (!ChkEle(form.fr_con_cd.value, "I"))
	{
		Error("������ �����ݾ��� �Է����ּ���!", form.fr_con_cd);
		return;
	}

	if (!ChkEle(form.fr_enm.value, "I"))
	{
		Error("��ۺ� �Է����ּ���!", form.fr_enm);
		return;
	}

	signform.submit();
}
