<?
	# 패스 및 클래스
	include $_SERVER[DOCUMENT_ROOT]."/Root_Path.inc";
	include "variable_config.inc";

	# DB 접속 및 함수
	include "logon.inc";
	include "user_function.inc";
?>
<link href="/css/manager.css" rel="stylesheet" type="text/css">
<link href="/css/project.css" rel="stylesheet" type="text/css">
<object id=factory style="display:none;" classid="clsid:1663ed61-23eb-11d2-b92f-008048fdd814" viewastext codebase="/images/ScriptX.cab#Version=6,1,429,14"></object>

<? 
   include "t.inc";
   $cf_table_wd_large="100%";

?>
   <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
   <tr>
   <td><br /><br /><br /><br />

<table width="95%" border="0" cellpadding="0" cellspacing="0">
	<tr>
		<th style="height:100px;padding-top:40"><h1 style="text-decoration:underline;">견학 신청서</h1></th>
	</tr>

	<tr>
		<td align="center" height="50">삼육식품 회사에 아래와 같이 견학을 신청합니다.</td>
	</tr>

	<tr>
		<td align="center" height="80">-  아&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;래 -</td>
	</tr>
	
	<tr>
		<td height="30" style="padding-left:65px">신청기관 : <?=$my_company;?></td>
	</tr>

	<tr>
		<td height="30" style="padding-left:65px">인&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;원 : <?=$my_people_cnt;?></td>
	</tr>

	<tr>
		<td height="30" style="padding-left:65px">견학일시 : <?=$my_tour_date;?></td>
	</tr>

	<tr>
		<td height="30" style="padding-left:65px">연 락 처(단체) : <?=$my_tel1;?></td>
	</tr>
	
	<tr>
		<td height="30" style="padding-left:65px">연 락 처(단체) : <?=$my_tel2;?></td>
	</tr>

	<tr>
		<td height="200" align="center"><?=$tm_input_ymdhms;?></td>
	</tr>
</table>
</td>
</tr>
</table>
<script>

function putSettings(type,lm,rm,tm,bm) 
{ 
	with(factory.printing)
	{
		header = ''; // 머릿말
		footer = ''; // 꼬릿말
		portrait = type; // true이면 세로 인쇄, false이면 가로 인쇄.
		leftMargin = lm; // 왼쪽 여백
		rightMargin = rm; // 오른쪽 여백
		topMargin = tm; // 윗쪽 여백
		bottomMargin = bm; // 아랫쪽 여백
	}
}



function doPrint(frame)
{
	putSettings(true,0,0,0.4,0);
	//factory.printing.Print(true, frame);
	window.print();
	//window.close();
}

doPrint(window);
</script>

