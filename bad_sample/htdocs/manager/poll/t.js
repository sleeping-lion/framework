function checkIt(form)
{      
	if(!form.fr_poll_type.value)
	{
		alert('���� ������ �����ϼ���!!');
		form.fr_poll_type.focus();
		return;
	}

	if(!form.fr_subject.value)
	{
		alert('���� ������ �Է��ϼ���!!');
		form.fr_subject.focus();
		return;
	}

	if(!form.fr_start_date.value)
	{
		alert('���� �������� �����ϼ���!!');
		form.fr_start_date.focus();
		return;
	}

	if(!form.fr_end_date.value)
	{
		alert('���� �������� �����ϼ���!!');
		form.fr_end_date.focus();
		return;
	}
	form.submit();
}

