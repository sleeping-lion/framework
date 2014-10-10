<table width="480" border="0" cellpadding="2" cellspacing="0" align="center">
   <tr>
	  <td align="center"><font color="#336699">▒ 검색된 주소를 클릭하시면 자동으로 입력됩니다.▒</font><br>
	  <div align="right">총 <b><?echo("$total_record")?></b>개의 주소가 검색되었습니다.</div>
	  </td>
   </tr>
</table>
<table width="480" border="0" cellspacing="1" cellpadding="3" background="/images/dotbg.gif" align="center">
	<tr bgcolor="#80b267" align="center">
		<td><FONT COLOR="#FFFFFF"><B>주 소</B></FONT></td>
		<td><FONT COLOR="#FFFFFF"><B>우편번호</B></FONT></td>
	</tr>

<?
	for($i=0; $i<$total_record; $i++)
	{
		$my_uid = $my_zip_arr[$i][0];
		$my_code = $my_zip_arr[$i][1];
		$my_addr1 = trim($my_zip_arr[$i][2]);
		$my_addr2 = trim($my_zip_arr[$i][3]);
		$my_addr3 = trim($my_zip_arr[$i][4]);
		$my_addr4 = trim($my_zip_arr[$i][5]);
		$my_gukbun = $my_zip_arr[$i][6];
      
		$address1 = "$my_addr1 $my_addr2 $my_addr3 $my_addr4";
		$address = "$my_addr1 $my_addr2 $my_addr3";
?>	
	<tr bgcolor="#F7F7F7">
		<td style="cursor:hand" onClick="selectIt(<?echo("$what")?>,'<?=$my_code?>','<?=$address?>')">&nbsp;<img src="images/arr.gif" hspace="3"><?=$address1?></td>
		<td align="center"><?=$my_code?></td>
	</tr>
<?
	}
?>      
	<tr bgcolor="#BBBBBB">
		<td colspan="2" height="1"></td>
	</tr>
</table>
