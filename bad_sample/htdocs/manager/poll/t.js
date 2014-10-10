function checkIt(form)
{      
	if(!form.fr_poll_type.value)
	{
		alert('설문 종류를 선택하세요!!');
		form.fr_poll_type.focus();
		return;
	}

	if(!form.fr_subject.value)
	{
		alert('설문 제목을 입력하세요!!');
		form.fr_subject.focus();
		return;
	}

	if(!form.fr_start_date.value)
	{
		alert('설문 시작일을 선택하세요!!');
		form.fr_start_date.focus();
		return;
	}

	if(!form.fr_end_date.value)
	{
		alert('설문 종료일을 선택하세요!!');
		form.fr_end_date.focus();
		return;
	}
	form.submit();
}

