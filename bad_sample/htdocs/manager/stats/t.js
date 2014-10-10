function Select_Menu(which,query) {
	var code;
	code = which.value;
	if(code != "")
	location.href = "list.html?po_year="+code+"&"+query;
}


function Select_Menu2() {
	document.searchform.submit();
}


function stats_excel(v,vv){
	var f = document.excelform;
	document.getElementById("stats_type").value = v;
	document.getElementById("month_type").value = vv;
	f.submit();
}