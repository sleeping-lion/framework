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

/*
// 에러 및 포커스
function Error(msg, ele)
{
	if(msg)alert(msg);
	if(ele) ele.focus();
	return false;
}
*/

// 이메일 검사
function IsEmail(str)
{
	var exclude=/[^@\-\.\w]|^[_@\.\-]|[\._\-]{2}|[@\.]{2}|(@)[^@]*\1/;
	var check=/@[\w\-]+\./;
	var checkend=/\.[a-zA-Z]{2,3}$/;

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
function checkIt2()
{
	var form = eval("document.signform2");
	if(!ChkEle(form.fr_cm_id.value, "C", 4, 20)) return Error("아이디를 입력해주세요.\n\n아이디는 4자 이상입니다.!", form.fr_cm_id);
	if(!ChkEle(form.fr_cm_passwd.value, "C", 4, 30)) return Error("패스워드를 입력해주세요.\n\n패스워드는 4자 이상입니다.!", form.fr_cm_passwd);
	return true;
}