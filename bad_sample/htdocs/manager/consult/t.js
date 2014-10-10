// FORM 전송시 체크사항
function checkIt(flag)
{
	var form = document.signform;
    

	// 기관
	if(!ChkEle(form.fr_company.value, "C", 1, 120)) return Error("신청하실 기관을 입력해주세요.!", form.fr_company);
 

	// 인원
	if(!ChkEle(form.fr_people_cnt.value, "C", 1, 120)) return Error("견학 예정인원을 입력해주세요.!", form.fr_people_cnt);

	// 견학일시
	if(!ChkEle(form.fr_tour_date.value, "C", 1, 120)) return Error("견학 예정 일시를 입력해주세요.!", form.fr_tour_date);

	// 연락처
	if(!ChkEle(form.fr_tel1.value, "C", 1, 60) && !ChkEle(form.fr_tel2.value, "C", 1, 60)) return Error("연락처를 하나라도 입력하셔야 연락 드릴수 있습니다.!", form.fr_tel1);
}

// 삭제시 경고창
function DelConfirm(url)
{
	if(confirm("확인을 누르면 게시물이 삭제되며 삭제된 게시물은 복구할 수 없습니다.\n\n정말로 삭제하시겠습니까?"))
	{
		window.location.href = url;
	}
}



function print_start(param){
	window.open("print_page.inc?"+param,"print","width=500,height=700");
}
