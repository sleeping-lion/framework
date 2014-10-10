<?php
$now_date=date("Y-m-d");
$result=mysql_query("SELECT * FROM CM_POPUP_T WHERE START_DAY<='".$now_date."' AND END_DAY>='".$now_date."' AND SERVICE_YN='Y'") or die(mysql_error());
//echo "SELECT * FROM CM_POPUP_T WHERE START_DAY<='".$now_date."' AND END_DAY>='".$now_date."' AND SERVICE_YN='Y'";
//$data1=mysql_fetch_array($result);
$total_size = mysql_num_rows($result);

while($data1=mysql_fetch_array($result)){

if($data1[NO]) { ?>

<script language="javascript">
// 쿠키가 있나 찾습니다
function getCookie( name ){
var nameOfCookie = name + "=";
var x = 0;
while ( x <= document.cookie.length )
{
var y = (x+nameOfCookie.length);
if ( document.cookie.substring( x, y ) == nameOfCookie ) {
if ( (endOfCookie=document.cookie.indexOf( ";", y )) == -1 )
endOfCookie = document.cookie.length;
return unescape( document.cookie.substring( y, endOfCookie ) );
}
x = document.cookie.indexOf( " ", x ) + 1;
if ( x == 0 )
break;
}
return "";
}
</script>
	<script>
	if ( getCookie( "g<?=$data1[NO]?>" ) != "done" ) {
	window.open('popup.php?po_no=<?=$data1[NO]?>','<?=$data1[NO]?>_blank','width=400,height=400,left=50,top=50,status=no,location=no,directories=no,menubar=no,scrollbars=no,toolbar=no');
	}
	</script>
<?php
	}
} ?>

<!-- 팝업창 스크립트-->
<script language="JavaScript">
function getCookie(name) {
	var Found = false
	var start, end
	var i = 0

	// cookie 문자열 전체를 검색
	while(i <= document.cookie.length) {
		start = i
		end = start + name.length
		// name과 동일한 문자가 있다면
		if(document.cookie.substring(start, end) == name) {
			Found = true
			break
		}

		i++
	}

	// name 문자열을 cookie에서 찾았다면
	if(Found == true) {
		start = end + 1
		end = document.cookie.indexOf(";", start)
		// 마지막 부분이라는 것을 의미(마지막에는 ";"가 없다)
		if(end < start)
		end = document.cookie.length
		// name에 해당하는 value값을 추출하여 리턴한다.
		return document.cookie.substring(start, end)
	}

	// 찾지 못했다면
	return ""

}

</script>
<!-- 팝업창 스크립트 끝-->