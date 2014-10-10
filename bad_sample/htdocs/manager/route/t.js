function Select_Menu(which,query) {
	var code;
	code = which.value;
	if(code != "")
	location.href = "list.html?po_year="+code+"&"+query;
}


function Select_Menu2() {
	document.searchform.submit();
}

function counter_excel(v){
	var f = document.signform;
	document.getElementById("counter_type").value = v;
	f.submit();
}