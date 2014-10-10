// FORM 전송시 체크사항
function checkIt(flag)
{
	var form = document.signform;
	
	// 성명
	if(!ChkEle(form.fr_nm.value, "C", 1, 250)) return Error("성명을 입력해주세요.!", form.fr_input_nm);

	// 성별
	if(form.fr_sex[0].checked==false && form.fr_sex[1].checked==false) {
		return Error("성별을 선택해주세요.!");
	}

	// 주소
	if(!ChkEle(form.fr_address.value, "C", 1, 250)) return Error("주소를 입력해주세요.!", form.fr_address);

	// 휴대전화
	if(!ChkEle(form.fr_hp_tel.value, "C", 1, 250)) return Error("휴대전화 번호를 입력해주세요.!", form.fr_hp_tel);

	// 전화번호
	if(!ChkEle(form.fr_tel.value, "C", 1, 250)) return Error("전화번호를 입력해주세요.!", form.fr_tel);

	// 현재직업
	if(!ChkEle(form.fr_job.value, "C", 1, 250)) return Error("현재직업을 입력해주세요.!", form.fr_job);

	// 희망지역
	if(!ChkEle(form.fr_hope.value, "C", 1, 250)) return Error("희망지역을 입력해주세요.!", form.fr_hope);

	// 사업동기
	if(!ChkEle(form.fr_motive.value, "C", 1, 250)) return Error("사업동기를 입력해주세요.!", form.fr_motive);

	// 경력사항
	if(!ChkEle(form.fr_career.value, "C", 1, 250)) return Error("경력사항을 입력해주세요.!", form.fr_career);

	// 사회활동
	//if(!ChkEle(form.fr_memo1.value, "C", 1, 250)) return Error("사회활동을 간력히 입력해주세요.!", form.fr_memo1);

	// 포상내역
	//if(!ChkEle(form.fr_memo2.value, "C", 1, 250)) return Error("포상내역을 간력히 입력해주세요.!", form.fr_memo2);
	
	form.submit();

}

function box_check(t_id){
	var form = document.signform;

	var obj = document.getElementsByName("tm_cm_b_type");

	var chk_cnt = 0;
	
	form.fr_cm_b_type.value= "";

	var	tm_txt = "";

	for(var i=0; i<obj.length; i++){
		if(obj[i].checked == true){
			chk_cnt++;

			if(chk_cnt<4){
				if(chk_cnt==1){
					tm_txt = tm_txt+obj[i].value;
				}else{
					tm_txt = tm_txt+"@@"+obj[i].value;
				}
			}
		}
		
	}

	if(chk_cnt>3){
		document.getElementById(t_id).checked = false;
		alert("최대 3개까지 선택 가능합니다.");
	}

	form.fr_cm_b_type.value = tm_txt;

	return chk_cnt; 

}

function preview(){
	if(checkIt()){
	window.open("","preview","width=500,height=700");
	document.signform.submit();
	}
}

// 우편번호 검색창
function ZipWindow(ref,what)
{
	ref = ref + "?what=" + what;
	new_window(ref, "zipWin", "", 539, 350);
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