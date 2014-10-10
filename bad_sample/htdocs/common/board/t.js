// FORM 전송시 체크사항

// ----------------------------------------------------------------- //
//	폼값 처리를 위한 함수 시작
// ----------------------------------------------------------------- //
// 폼 요소의 값을 체크한다.
function ChkEle(str, type, min, max)
{
	var IsNum;
	var Block = true;
	str = Trim(str);

	if(str.length < 1) return false;

	if(type == "I")
	{
		str = str.replace(",", "");
		str = str.replace(".", "");
		if(!IsNumber(str)) return false;
		if(min >= 0 && max >= 0) return ChkLen(str, min, max);
	}
	else if(type == "C")
	{
		if(min >= 0 && max >= 0)
			return ChkStrLen(str,min,max)
	}
	else
		return false;
	return true;
}

// 입력값이 숫자나문자인지 체크
function IsAlNum(str)
{
	for(var i=0; i<str.length; i++)
	{
		var chr = str.substr(i,1);
		if((chr < '0' || chr > '9') && (chr < 'a' || chr > 'z') && (chr < 'A' || chr > 'Z'))
		{
			return false;
		}
	}
	return true;
}

// 입력값이 숫자인지 검사
function IsNumber(str)
{
	var temp;
	var digits = "0123456789";

	for(var i=0; i<str.length; i++)
	{
		temp = str.substring(i,i+1)
		if(digits.indexOf(temp)==-1) {
			return false;
		}
	}
	return true;
}

// 입력값의 길이가 min < str < max 인지 체크
function ChkStrLen(str, min, max)
{
	if(!min) min = 0;	
	if(!max) max = 999;
	min = parseInt(min);
	max = parseInt(max);

	if(str.length >= min && str.length <= max)
	{
		return true;
	}
	return false;
}

// 입력값의 범위가 min < str < max 인지 체크
function ChkLen(digit, min, max)
{
	digit = parseInt(digit);
	min = parseInt(min);
	max = parseInt(max);

	if(!(min >= 0)) min = 0;
	if(!(max >= 0)) max = 9;

	if(digit >= min && digit <= max)
		return true;
	return false;
}









// trim()함수 정의
function Trim(str)
{
	if(!str) str = "";
	return str.replace(/(^\s*)|(\s*$)/g, "");
}



// 이메일 검사
function IsEmail(str)
{
	var exclude='/[^@\-\.\w]|^[_@\.\-]|[\._\-]{2}|[@\.]{2}|(@)[^@]*\1/';
	var check='/@[\w\-]+\./';
	var checkend='/\.[a-zA-Z]{2,3}$/';

	if(((str.search(exclude)!=-1)||(str.search(check))==-1)||(str.search(checkend)==-1))
		return false;
	else
		return true;
}

// 화면중앙에 새창띄우기 함수
function new_window(url, name, option, width, height, left, top)
{
	var win_width;
	var win_height;

	// 새창을 위한 좌표값을 구한다.
	if(screen.width < width)
	{
		win_width = 0;
		width = screen.width;
	}
	else
	{
		win_width = (screen.width - width) / 2;
	}

	if(screen.height < height)
	{
		win_height = 0;
		height = screen.height;
	}
	else
	{
		win_height = (screen.height - height) / 2;
	}

	// 옵션처리
	if(!option)
	{
		option = "resizable=no,scrollbars=yes,menubar=no,status=no";
	}

	if(left)
		win_width = left;

	if(top)
		win_height = top;

	// 새창을 띄운다.
	window.open(url,name,option+',width='+width+',height='+height+',left='+win_width+',top='+win_height);
}
// 로그인시 체크사항
function checkIt(flag,html)
{

	var form = document.signform;
	//이메일 주소 만들어주기()	
//	form.fr_email.value = form.fr_email1.value + '@' + form.fr_email2.value ;	

	// 제목
	if(!ChkEle(form.fr_subject.value, "C", 1, 60)) return Error("제목을 입력해주세요.!", form.fr_subject);

	// 이름
	if(!ChkEle(form.fr_input_nm.value, "C", 1, 15)) return Error("이름을 입력해주세요.!", form.fr_input_nm);

	// 이메일 체크
//	var email = form.fr_email.value;
//	if(email && !IsEmail(email)) return Error("이메일 주소를 정확하게 입력해주세요.!", form.fr_email);

	if(flag != "Y")
	{
		// 패스워드
		if(!ChkEle(form.fr_passwd.value, "C", 4, 20)) return Error("패스워드는 4자이상 입력해주세요.!", form.fr_passwd);
	}
	
	// 본문

	if(html=="Y"){

    // 에디터의 내용이 textarea에 적용된다.

    oEditors.getById["editor"].exec("UPDATE_CONTENTS_FIELD", []);

 

    // 에디터의 내용에 대한 값 검증은 이곳에서

    // document.getElementById("ir1").value를 이용해서 처리한다.

 

    try {

        form.submit();

    } catch(e) {}

	}
	else{
		if(!ChkEle(form.fr_memo.value, "C")){ return Error("본문을 입력해주세요.!", form.fr_memo);
		}else{
			form.submit();
		}

	}

}

// FORM 전송시 체크사항
function checkIt2(flag,html)
{

	var form = document.signform;
	//이메일 주소 만들어주기()	
//	form.fr_email.value = form.fr_email1.value + '@' + form.fr_email2.value ;	

	// 이름
	if(!ChkEle(form.fr_input_nm.value, "C", 1, 15)) return Error("이름을 입력해주세요.!", form.fr_input_nm);

	// 이메일 체크
	if(!ChkEle(form.fr_email1.value, "C", 1, 15)) return Error("이메일을 입력해주세요.!", form.fr_email1);

	// 이메일 체크
	if(!ChkEle(form.fr_email2.value, "C", 1, 15)) return Error("이메일을 입력해주세요.!", form.fr_email2);

	// 제목
	if(!ChkEle(form.fr_subject.value, "C", 1, 60)) return Error("제목을 입력해주세요.!", form.fr_subject);	
	

	if(flag != "Y")
	{
		// 패스워드
		if(!ChkEle(form.fr_passwd.value, "C", 4, 20)) return Error("패스워드는 4자이상 입력해주세요.!", form.fr_passwd);
	}
	
	// 본문

	if(html=="Y"){
		saveContent();
	}
	else{
		if(!ChkEle(form.fr_memo.value, "C")){ return Error("본문을 입력해주세요.!", form.fr_memo);
		}else{
			form.submit();
		}

	}

}
















// 삭제시 경고창
function DelConfirm(url)
{
	if(confirm("확인을 누르면 게시물이 삭제되며 삭제된 게시물은 복구할 수 없습니다.\n\n정말로 삭제하시겠습니까?"))
	{
		window.location.href = url;
	}
}

// 삭제폼 전송시 비밀번호 체크
function checkpasswd()
{
	var form = document.signform;

	// 패스워드
	if(!ChkEle(form.fr_passwd.value, "C", 4, 20)) return Error("패스워드는 4자이상 입력해주세요.!", form.fr_passwd);
}

// 패스워드에 포커스
function focusIt()
{
	document.signform.fr_passwd.focus();
} 

// 글쓴이에 포커스
function focusWriter()
{
	document.signform.fr_input_nm.focus();
}

// 제목에 포커스
function focusSubject()
{
	document.signform.fr_subject.focus();
}

// ----------------------------------------------------- //
//	커멘트 관련부분 시작
// ----------------------------------------------------- //
function checkIt_comm()
{
	var form = document.commentform;

	// 이름
	if(!ChkEle(form.fr_comm_input_nm.value, "C", 1, 15)) return Error("이름을 입력해주세요.!", form.fr_comm_input_nm);

	// 코멘트 내용
	if(!ChkEle(form.fr_comm_memo.value, "C")) return Error("코멘트를 입력해주세요.!", form.fr_comm_memo);

	// 패스워드
	if(!ChkEle(form.fr_comm_passwd.value, "C", 4, 20)) return Error("패스워드는 4자이상 입력해주세요.!", form.fr_comm_passwd);

	form.submit();
}

function checkIt_commdel()
{
	var form = document.commentform;

	// 패스워드
	if(!ChkEle(form.fr_del_passwd.value, "C", 4, 20)) return Error("패스워드는 4자이상 입력해주세요.!", form.fr_del_passwd);

	form.action = "listbody_comment_delete.html";

	form.submit();
}

// 커멘트 삭제폼(패스워드입력폼) 보이기
n4 = (document.layers) ? 1 : 0;
e4 = (document.all) ? 1 : 0;
function show_commdel_form(mode,c_no)
{
	if(mode == 1)
	{
		if(n4)
		{
			var x = event.pageX - 170;
			var y = event.pageY;

			del_comm.left = x;
			del_comm.top = y;
			del_comm.visibility = "visible"
		}
		else if(e4)
		{
			var x = event.clientX - 170;
			var y = event.clientY + document.body.scrollTop;

			del_comm.style.pixelLeft = x;
			del_comm.style.pixelTop = y;
			del_comm.style.visibility = "visible"
		}
		document.commentform.po_c_no.value = c_no;
	}
	else
	{
		del_comm.style.visibility = "hidden";
	}
}

// 삭제버튼 클릭시 삭제하는 경우
function commdel_submit(c_no)
{
	var form = document.commentform;

	if(!confirm("확인을 누르면 코멘트글이 삭제됩니다.\n\n삭제하시겠습니까?"))
	{
		return;
	}

	form.po_c_no.value = c_no;
	form.action = "listbody_comment_delete.html";
	form.submit();
}

// ----------------------------------------------------- //
//	커멘트 관련부분 끝
// ----------------------------------------------------- //

//###############################################################

function check_all() {

	var str = document.getElementsByName("fr_check_no");
	
	for(i=0 ; i < str.length ; i++){
		if(str[i].checked == true){
			str[i].checked  = false; 
		}
		else{
			str[i].checked  = true; 
		}

	}
}

function check_del(url) {

	var str = document.getElementsByName("fr_check_no");
	var del_no = document.getElementById("fr_del_no");
	var check_cnt = 0 ;
	
	del_no.value ="";

	for(i=0 ; i < str.length ; i++){
		if (str[i].checked) {
			check_cnt++;
			
			del_no.value += str[i].value + ",";

		}
	}

	if (!check_cnt) {
		alert ("삭제할 게시물을 선택해주세요.");
		return;
	}
	
	var ans ="선택된 게시물을 삭제하시겠습니까?";

	if (confirm(ans)) {
		//del_no.action=url;
		//del_no.submit();
		location.href=url+"&fr_del_no="+del_no.value;
	}

}

function check_move(po_basic_query) {

	var str = document.getElementsByName("fr_check_no");

	var check_cnt = 0 ;

	for(i=0 ; i < str.length ; i++){
		if (str[i].checked) {
			check_cnt++;
		}
	}

	if (!check_cnt) {
		alert ("이동할 게시물을 선택해주세요.");
		return;
	}
	else{
		window.open("pop_move.html?"+po_basic_query,"","width=400,height=500");
	}

}



function show_rank(t) {
	if(t == 1) {
		if (s_rank1.style.display == "none"){
			s_rank1.style.display="block";
		} else {
			s_rank1.style.display = "none";
		}
	
	} 

	if(t == 2) {
		if (s_rank2.style.display == "none"){
			s_rank2.style.display="block";
		} else {
			s_rank2.style.display = "none";
		}
	
	} 

	if(t == 3) {
		if (s_rank3.style.display == "none"){
			s_rank3.style.display="block";
		} else {
			s_rank3.style.display = "none";
		}
	
	} 
}



//이메일 주소
function SelectCombo(addr){

	if (addr == 0) {
		document.signform.fr_email2.value = '';
		document.signform.fr_email2.disabled = false;

		document.signform.fr_email2.focus();
	} else {
		document.signform.fr_email2.value = addr;
		document.signform.fr_email2.disabled = true;

		document.signform.fr_email1.focus();
	}
	
}



var old_faq_num = "xx";
//faq 보기
function faq_view(num, list_count){
	
	
	for(var ad=0;ad<list_count;ad++){
		
		var memo = document.getElementById("faq_memo"+ad);
		var subject = document.getElementById("faq_subj"+ad);
		if(ad==num && (old_faq_num != num)){
			memo.className="";
			subject.className="faq_title";
		}else{
			memo.className="faq_choice";
			subject.className="list_title";
		}
	}

	if(old_faq_num != num){
		old_faq_num = num;
	}else{
		old_faq_num = "xx";
	}

}


