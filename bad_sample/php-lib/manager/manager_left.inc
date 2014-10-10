
<div><img src="/manager/images/left-title.jpg" alt="관리자메뉴" /></div>

<table width="200" border="0" cellpadding="0" cellspacing="0" bgcolor="#F4F4F4">
	<tr>
		<td  align="center" valign="top">

		<BR />


			<table width="170" border="0" cellpadding="5" cellspacing="2" bgcolor="#F4F4F4">

<?if($_SESSION['USER_LEVEL'] == "aa") {?>
				<tr>
					<td bgcolor="#FFFFFF" style="text-align:left;padding-left:10px;"><img src="/manager/images/icon.gif" hspace="3"> <a href="/manager/table/list.html?a_gb=admin&a_cd=1&a_item=0">프로그램관리</a></td>
				</tr>
<?}?>

				<tr>
					<td bgcolor="#FFFFFF" style="text-align:left;padding-left:10px;"><img src="/manager/images/icon.gif" hspace="3"><a href="/manager/member/list.html?a_gb=member&a_cd=3&a_item=0"> 회원관리</a></td>
				</tr>
			</table>
		</td>
	</tr>
</table>
