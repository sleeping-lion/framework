function checkIt()
{
	var form = eval("document.signform");

	// 분류
	//if(!ChkEle(form.fr_it_lclass.value, "C")) return Error("상품분류를 선택해주세요.!", "");

	// 상품명
	if(!ChkEle(form.fr_it_name.value, "C")) return Error("상품명을 입력해주세요!", form.fr_it_name);

	// 상품설명
	//if(!ChkEle(form.fr_it_memo.value, "C")) return Error("상품설명을 입력해주세요!", form.fr_it_memo);


	form.submit();
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
	if(confirm("확인을 누르시면 상품정보가 삭제됩니다."))
	{
		window.location=url;
	}
}

