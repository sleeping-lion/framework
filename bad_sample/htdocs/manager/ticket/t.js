function checkIt()
{
	var form = eval("document.signform");

	signform.submit();
}

function IsNumber(formname)
{
	var form = eval("document.signform." + formname);

	for(var i = 0; i < form.value.length; i++)
	{
		var chr = form.value.substr(i,1);
		if(chr < '0' || chr > '9')
		{
			return false;
		}
	}
	return true;
}

function del_ok(url)
{
	if(confirm("확인을 누르시면 수강권정보가 삭제됩니다."))
	{
		window.location=url;
	}
}
