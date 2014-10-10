function checkIt()
{
	var form = eval("document.signform");

	// 분류
	if(!form.fr_cd.value)
	{
		alert("분류코드를 입력해주세요!");
		form.fr_cd.focus();
		return;
	}
	if(!form.fr_nm.value)
	{
		alert("분류명을 입력해주세요!");
		form.fr_nm.focus();
		return;
	}

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
	if(confirm("확인을 누르시면 상품정보가 삭제됩니다."))
	{
		window.location=url;
	}
}

function check_pic()
{
	var lclass = signform.fr_it_lclass.value;
	var userfile = signform.userfile.value;
	var ext = userfile.substring(userfile.lastIndexOf(".")+1);


	if(!signform.userfile.value)
	{
		alert ("파일을 선택해 주세요!");
		signform.userfile.focus();
		return;
	}

	if (lclass=="i10"&&(ext != "jpg" && ext != "gif"))
	{
		alert("이미지 파일만 올려주세요! \n예 gif , jpg ");
		return;
	}

	signform.submit();
}

function mod_pic(img)
{
	var  str="?a_gb=item&a_cd=1&a_item=0&po_it_no=&po_img=" + img;
	window.open('modifyform_picture.html'+str,'mod','width=300,height=200,left=0,top=0');
}

function del_ask(str)
{
	ans=confirm("등록된 옵션을 삭제하시겠습니까?");
	var url ="/admin/item/option/delete.html?" + str;
	if (ans==true)
	{
		location.href=url;
	}
}


