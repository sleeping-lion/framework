// FORM 전송시 체크사항
function checkIt(flag)
{
	var form = document.signform;

	// 가로창크기
	if(!ChkEle(form.fr_width.value, "C", 1, 15)) return Error("가로크기를 입력하세요.!", form.fr_width);

	// 세로창 크기
	if(!ChkEle(form.fr_height.value, "C", 1, 15)) return Error("세로크기를 입력하세요.!", form.fr_height);


	// 본문
	//if(!ChkEle(form.fr_content.value, "C")) return Error("본문을 입력해주세요.!", form.fr_content);
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
var check_flag= "N";

function check_all() {

	var str = document.signform.fr_check_no;
	
	for(i=1 ; i < str.length ; i++){
		
		if (check_flag =="N") str[i].checked  = true; 
		else  str[i].checked  = false;	

	}

	if (check_flag =="N") check_flag ="Y";
	else check_flag ="N";
		
}

function check_del(url) {

	var str = document.signform.fr_check_no;
	var check_cnt = 0 ;
	
	signform.fr_del_no.value ="";

	for(i=1 ; i < str.length ; i++){
		if (str[i].checked) {
			check_cnt++;
			
			signform.fr_del_no.value += str[i].value + ",";
		}
	}

	if (!check_cnt) {
		alert ("삭제할 게시물을 선택해주세요.");
		return;
	}
	
	var ans ="선택된 게시물을 삭제하시겠습니까?";

	if (confirm(ans)) {
		signform.action=url;
		signform.submit();
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


//팝업 종류 설정
function popupReg() {
	var form=document.signform;
	if( form.fr_display[0].checked) {
		document.all.popup_view[0].style.display="none"; 
		document.all.popup_view[1].style.display="none"; 
		document.all.popup_view[2].style.display="none"; 
		document.all.popup_view[3].style.display="none"; 
		document.all.popup_view[4].style.display=""; 
		document.all.popup_view[5].style.display=""; 
	} else if( form.fr_display[1].checked ) {
		document.all.popup_view[0].style.display=""; 
		document.all.popup_view[1].style.display=""; 
		document.all.popup_view[2].style.display=""; 
		document.all.popup_view[3].style.display=""; 
		document.all.popup_view[4].style.display="none"; 
		document.all.popup_view[5].style.display="none"; 
	}
}