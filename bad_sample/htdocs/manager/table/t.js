function checkIt(form)
{      
	if(!form.fr_gb.value)
	{
		alert('코드구분을 입력하세요!');
		form.fr_gb.focus();
		return;
	}
	form.submit();
}

function focusIt()
{
	document.signform.fr_gb.focus();
} 

function check_site_nm()
{
	var sel_idx = signform.fr_item.selectedIndex;
	var sel_txt = signform.fr_item.options[sel_idx].text;
	signform.fr_item_nm.value = sel_txt;
}
