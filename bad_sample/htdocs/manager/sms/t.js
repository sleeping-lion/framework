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

function b_value1(){
	var frm = document.signform;
	var t = window.document.getElementById("byte_v1");		
	var m_length = new String(frm.fr_msg1.value);
	var onechar,leftchar;
	var tcount = 0;
	var jcount = 0;
	var tmpEscape = "";
	
	for (k=0;k<m_length.length;k++) {
		onechar = m_length.charAt(k);

		if(escape(onechar).length > 4){
			tcount += 2;
		}else if (onechar!='\r') {
			tcount++;
		}else{
				//tcount++;
		}
		if(tcount > 50){
			break;
		}
		tmpEscape = tmpEscape + onechar;
	} // for
	
	if(tcount > 50){

		alert("보낼 메시지가 50Byte를 초과하였습니다.");			
		frm.fr_msg1.value = tmpEscape;
		return true;
	}

	t.innerHTML = tcount+"/50Byte";
}

function b_value2(){
	var frm = document.signform;
	var t = window.document.getElementById("byte_v2");		
	var m_length = new String(frm.fr_msg2.value);
	var onechar,leftchar;
	var tcount = 0;
	var jcount = 0;
	var tmpEscape = "";
	
	for (k=0;k<m_length.length;k++) {
		onechar = m_length.charAt(k);

		if(escape(onechar).length > 4){
			tcount += 2;
		}else if (onechar!='\r') {
			tcount++;
		}else{
				//tcount++;
		}
		if(tcount > 50){
			break;
		}
		tmpEscape = tmpEscape + onechar;
	} // for
	
	if(tcount > 50){

		alert("보낼 메시지가 50Byte를 초과하였습니다.");			
		frm.fr_msg2.value = tmpEscape;
		return true;
	}

	t.innerHTML = tcount+"/50Byte";
}

function b_value3(){
	var frm = document.signform;
	var t = window.document.getElementById("byte_v3");		
	var m_length = new String(frm.fr_msg3.value);
	var onechar,leftchar;
	var tcount = 0;
	var jcount = 0;
	var tmpEscape = "";
	
	for (k=0;k<m_length.length;k++) {
		onechar = m_length.charAt(k);

		if(escape(onechar).length > 4){
			tcount += 2;
		}else if (onechar!='\r') {
			tcount++;
		}else{
				//tcount++;
		}
		if(tcount > 50){
			break;
		}
		tmpEscape = tmpEscape + onechar;
	} // for
	
	if(tcount > 50){

		alert("보낼 메시지가 50Byte를 초과하였습니다.");			
		frm.fr_msg3.value = tmpEscape;
		return true;
	}

	t.innerHTML = tcount+"/50Byte";
}

function b_value4(){
	var frm = document.signform;
	var t = window.document.getElementById("byte_v4");		
	var m_length = new String(frm.fr_msg4.value);
	var onechar,leftchar;
	var tcount = 0;
	var jcount = 0;
	var tmpEscape = "";
	
	for (k=0;k<m_length.length;k++) {
		onechar = m_length.charAt(k);

		if(escape(onechar).length > 4){
			tcount += 2;
		}else if (onechar!='\r') {
			tcount++;
		}else{
				//tcount++;
		}
		if(tcount > 50){
			break;
		}
		tmpEscape = tmpEscape + onechar;
	} // for
	
	if(tcount > 50){

		alert("보낼 메시지가 50Byte를 초과하였습니다.");			
		frm.fr_msg4.value = tmpEscape;
		return true;
	}

	t.innerHTML = tcount+"/50Byte";
}

function b_value5(){
	var frm = document.signform;
	var t = window.document.getElementById("byte_v5");		
	var m_length = new String(frm.fr_msg5.value);
	var onechar,leftchar;
	var tcount = 0;
	var jcount = 0;
	var tmpEscape = "";
	
	for (k=0;k<m_length.length;k++) {
		onechar = m_length.charAt(k);

		if(escape(onechar).length > 4){
			tcount += 2;
		}else if (onechar!='\r') {
			tcount++;
		}else{
				//tcount++;
		}
		if(tcount > 50){
			break;
		}
		tmpEscape = tmpEscape + onechar;
	} // for
	
	if(tcount > 50){

		alert("보낼 메시지가 50Byte를 초과하였습니다.");			
		frm.fr_msg5.value = tmpEscape;
		return true;
	}

	t.innerHTML = tcount+"/50Byte";
}

function b_value6(){
	var frm = document.signform;
	var t = window.document.getElementById("byte_v6");		
	var m_length = new String(frm.fr_msg6.value);
	var onechar,leftchar;
	var tcount = 0;
	var jcount = 0;
	var tmpEscape = "";
	
	for (k=0;k<m_length.length;k++) {
		onechar = m_length.charAt(k);

		if(escape(onechar).length > 4){
			tcount += 2;
		}else if (onechar!='\r') {
			tcount++;
		}else{
				//tcount++;
		}
		if(tcount > 50){
			break;
		}
		tmpEscape = tmpEscape + onechar;
	} // for
	
	if(tcount > 50){

		alert("보낼 메시지가 50Byte를 초과하였습니다.");			
		frm.fr_msg6.value = tmpEscape;
		return true;
	}

	t.innerHTML = tcount+"/50Byte";
}

function b_value7(){
	var frm = document.signform;
	var t = window.document.getElementById("byte_v7");		
	var m_length = new String(frm.fr_msg7.value);
	var onechar,leftchar;
	var tcount = 0;
	var jcount = 0;
	var tmpEscape = "";
	
	for (k=0;k<m_length.length;k++) {
		onechar = m_length.charAt(k);

		if(escape(onechar).length > 4){
			tcount += 2;
		}else if (onechar!='\r') {
			tcount++;
		}else{
				//tcount++;
		}
		if(tcount > 50){
			break;
		}
		tmpEscape = tmpEscape + onechar;
	} // for
	
	if(tcount > 50){

		alert("보낼 메시지가 50Byte를 초과하였습니다.");			
		frm.fr_msg7.value = tmpEscape;
		return true;
	}

	t.innerHTML = tcount+"/50Byte";
}

function b_value8(){
	var frm = document.signform;
	var t = window.document.getElementById("byte_v8");		
	var m_length = new String(frm.fr_msg8.value);
	var onechar,leftchar;
	var tcount = 0;
	var jcount = 0;
	var tmpEscape = "";
	
	for (k=0;k<m_length.length;k++) {
		onechar = m_length.charAt(k);

		if(escape(onechar).length > 4){
			tcount += 2;
		}else if (onechar!='\r') {
			tcount++;
		}else{
				//tcount++;
		}
		if(tcount > 50){
			break;
		}
		tmpEscape = tmpEscape + onechar;
	} // for
	
	if(tcount > 50){

		alert("보낼 메시지가 50Byte를 초과하였습니다.");			
		frm.fr_msg8.value = tmpEscape;
		return true;
	}

	t.innerHTML = tcount+"/50Byte";
}

function b_value9(){
	var frm = document.signform;
	var t = window.document.getElementById("byte_v9");		
	var m_length = new String(frm.fr_msg9.value);
	var onechar,leftchar;
	var tcount = 0;
	var jcount = 0;
	var tmpEscape = "";
	
	for (k=0;k<m_length.length;k++) {
		onechar = m_length.charAt(k);

		if(escape(onechar).length > 4){
			tcount += 2;
		}else if (onechar!='\r') {
			tcount++;
		}else{
				//tcount++;
		}
		if(tcount > 50){
			break;
		}
		tmpEscape = tmpEscape + onechar;
	} // for
	
	if(tcount > 50){

		alert("보낼 메시지가 50Byte를 초과하였습니다.");			
		frm.fr_msg9.value = tmpEscape;
		return true;
	}

	t.innerHTML = tcount+"/50Byte";
}

function b_value10(){
	var frm = document.signform;
	var t = window.document.getElementById("byte_v10");		
	var m_length = new String(frm.fr_msg10.value);
	var onechar,leftchar;
	var tcount = 0;
	var jcount = 0;
	var tmpEscape = "";
	
	for (k=0;k<m_length.length;k++) {
		onechar = m_length.charAt(k);

		if(escape(onechar).length > 4){
			tcount += 2;
		}else if (onechar!='\r') {
			tcount++;
		}else{
				//tcount++;
		}
		if(tcount > 50){
			break;
		}
		tmpEscape = tmpEscape + onechar;
	} // for
	
	if(tcount > 50){

		alert("보낼 메시지가 50Byte를 초과하였습니다.");			
		frm.fr_msg10.value = tmpEscape;
		return true;
	}

	t.innerHTML = tcount+"/50Byte";
}