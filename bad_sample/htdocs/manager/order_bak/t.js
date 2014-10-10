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

// 삭제시 경고창
function DelConfirm(url)
{
	if(confirm("확인을 누르면 게시물이 삭제되며 삭제된 게시물은 복구할 수 없습니다.\n\n정말로 삭제하시겠습니까?"))
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
		alert("하나이상 체크해 주세요.");
		return;
	}
	if(confirm("정말로 삭제하시겠 습니까?")) {
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
		alert("하나이상 체크해 주세요.");
		return;
	}

	form.action="order_progress_ok.html?"+query;
	form.submit();
}