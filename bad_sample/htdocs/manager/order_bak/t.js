function checkIt(form)
{      
	if(!form.fr_gb.value)
	{
		alert('�ڵ屸���� �Է��ϼ���!');
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

// ������ ���â
function DelConfirm(url)
{
	if(confirm("Ȯ���� ������ �Խù��� �����Ǹ� ������ �Խù��� ������ �� �����ϴ�.\n\n������ �����Ͻðڽ��ϱ�?"))
	{
		window.location.href = url;
	}
}

function Delete_check() {
	var form = document.signform;
	var len = form.elements.length;
	var j = 0;
	for(i=0; i<len; i++) {
		if(form.elements[i].type == "checkbox" && form.elements[i].checked == true) {
			j++;
		}
	}

	if(!j) {
		alert("�ϳ��̻� üũ�� �ּ���.");
		return;
	}
	if(confirm("������ �����Ͻð� ���ϱ�?")) {
		form.submit();
	}
	return;
}

function J_progress(query) {
	var form = document.signform;
	var len = form.elements.length;
	var j = 0;
	for(i=0; i<len; i++) {
		if(form.elements[i].type == "checkbox" && form.elements[i].checked == true) {
			j++;
		}
	}

	if(!j) {
		alert("�ϳ��̻� üũ�� �ּ���.");
		return;
	}

	form.action="order_progress_ok.html?"+query;
	form.submit();
}