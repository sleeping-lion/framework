// --------------------------------------------------------- //
//	각 폼 인자값 체크 함수 시작
// --------------------------------------------------------- //
function checkIt()		// 회원정보수정시
{
	var form = document.signform;

	// 새비밀번호가 입력된경우
	if(form.fr_cm_new_passwd.value.length > 0)
	{
		if(!ChkEle(form.fr_cm_new_passwd.value, "C", 4, 32)) return Error("새비밀번호를 정확하게 입력해주세요.!\n\n영문기준 4~32자", form.fr_cm_new_passwd);
		if(!ChkEle(form.fr_cm_new_passwd2.value, "C", 4, 32)) return Error("확인용 비밀번호를 정확하게 입력해주세요.!\n\n영문기준 4~32자", form.fr_cm_new_passwd2);
		if(form.fr_cm_new_passwd.value != form.fr_cm_new_passwd2.value)
			return Error("새비밀번호와 확인용 비밀번호가 틀립니다.!", form.fr_cm_new_passwd2);
	}
	form.submit();
}

function post_checkIt()// 회원정보수정시
{
	var form = document.signform;

	// 아이디
	if(!ChkEle(form.fr_cm_id.value, "C", 2, 20)) return Error("아이디를 입력해주세요.!", form.fr_cm_id);

	// 아이디 영/숫자인지 검사
	//if(!IsAlNum(form.fr_cm_id.value)) return Error("아이디는 영문자와 숫자의 조합으로 만들어주세요.!", form.fr_cm_id);

	// 아이디 중복체크 확인여부
	if(form.fr_id_check.value != "Y") return Error("아이디 중복체크를 해주세요.!", form.fr_cm_id);

	// 패스워드
	if(!ChkEle(form.fr_cm_passwd.value, "C", 4, 32)) return Error("비밀번호를 정확하게 입력해주세요.!\n\n영문기준 4~32자", form.fr_cm_passwd);

	// 패스워드 확인
	if(!ChkEle(form.fr_cm_passwd2.value, "C", 4, 32)) return Error("확인용 비밀번호를 정확하게 입력해주세요.!\n\n영문기준 4~32자", form.fr_cm_passwd2);

	if(form.fr_cm_passwd.value != form.fr_cm_passwd2.value)
		return Error("비밀번호와 확인용 비밀번호가 틀립니다.!", form.fr_cm_passwd2);

	// 이름
	if(!ChkEle(form.fr_cm_nm.value, "C", 1, 32)) return Error("이름을 입력해주세요.!", form.fr_cm_nm);

	if(!IsSSNO(form.fr_cm_jumin2.name)) return Error("잘못된 주민등록번호입니다.!", form.fr_cm_jumin1);

	// 주소입력여부
	if(form.fr_addr_check.value != "Y") return Error("우편번호 검색창을 이용하여 주소를 입력해주세요.!", form.fr_cm_zip_cd);

	// 주소체크
	if(!ChkEle(form.fr_cm_zip_cd.value, "C") || !ChkEle(form.fr_cm_addr.value, "C"))
		return Error("우편번호 찾기를 이용하여 주소를 입력해주세요.!", form.fr_cm_zip_cd);
	if(!ChkEle(form.fr_cm_addr2.value, "C")) return Error("나머지 주소를 입력해주세요.!", form.fr_cm_addr2);


	// 전화번호체크
	if(!ChkEle(form.fr_cm_tel1.value, "C")) return Error("전화번호를 입력해주세요.!", form.fr_cm_tel1);


}

// 탈퇴사유 검사창
function checkDelete()
{
	var form = document.signform;

	// 탈퇴사유
	if(form.fr_cm_del_reason.value.split(" ").join("") == '')
	{
		alert("탈퇴사유를 적어주세요.\n\n탈퇴사유는 보다 나은 서비스를 위해 사용됩니다.");
		form.fr_cm_del_reason.value = "";
		form.fr_cm_del_reason.focus();
		return false;
	}

	// 주민등록번호 검사
	if(!form.fr_cm_jumin1.value || !form.fr_cm_jumin2.value)
	{
		alert("주민등록번호를 정확히 입력해주세요.");
		return false;
	}

	if(!IsSSNO("fr_cm_jumin2"))
		return false;

	// 비밀번호
	if(form.fr_cm_passwd.value.split(" ").join("") == '')
	{
		alert("비밀번호를 입력해주세요.");
		form.fr_cm_passwd.value = "";
		form.fr_cm_passwd.focus();
		return false;
	}

	if(!confirm("확인을 누르시면 회원탈퇴작업이 이루어집니다.\n\n현재 회원정보는 매매 및 관련 정보관리를 위하여 일정기간 삭제되지 않습니다.\n\n회원 재가입을 원하실 경우 관리자에게 문의하시기 바랍니다.\n\n정말로 삭제하시겠습니까?"))
		return false;

	form.submit();
}
// --------------------------------------------------------- //
//	각 폼 인자값 체크 함수 끝
// --------------------------------------------------------- //


// --------------------------------------------------------- //
//	포커스 관련 함수 시작
// --------------------------------------------------------- //
function focusID()
{
	document.signform.fr_cm_id.focus();
}
// --------------------------------------------------------- //
//	포커스 관련 함수 끝
// --------------------------------------------------------- //


// --------------------------------------------------------- //
//	새창 관련함수 시작
// --------------------------------------------------------- //
// 아이디 검사창
function check_id_window(ref)
{
	var fr_cm_id = eval(document.signform.fr_cm_id);

	if(!ChkEle(fr_cm_id.value, "C", 4, 20)) return Error("아이디를 4자 이상 넣어주세요.!", fr_cm_id);

	ref = ref + "?fr_cm_id=" + fr_cm_id.value;
	new_window(ref, "checkIDWin", "", 250, 160);
}

// 우편번호 검색창
function ZipWindow(ref,what)
{
	ref = ref + "?what=" + what;      
	//new_window(ref, "zipWin", "", 539, 350);
	new_window(ref, "zipWin", "", 525, 750);
}
// --------------------------------------------------------- //
//	새창 관련함수 끝
// --------------------------------------------------------- //


function mem_cd_ch(v) {
	if(v=="ee") { // 기업 회원이라면
		memview.style.display = "block";
	} else {
		memview.style.display = "none";
	}
}