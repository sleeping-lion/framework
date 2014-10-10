

 <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0" style="border-top:2px solid #6C6C6C; border-bottom:1px solid #DBDBDB; ">
	<tr bgcolor='#F4F4F4' height='27'>
      <td width="120" align="center"><b>팝업창 타이틀</b></td>      
      <td align="left" bgcolor='#FFFFFF'>&nbsp;&nbsp;<?=$my_title_bar?></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='2'></td>
    </tr>
     
	 <tr bgcolor='#F4F4F4' height='27'>
      <td align="center"><b>팝업창 종류</b></td>      
      <td align="left" bgcolor='#FFFFFF'>&nbsp;&nbsp;<? if($my_display=="0") echo "HTML"; else echo "이미지";?></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='2'></td>
    </tr>

	 <tr bgcolor='#F4F4F4' height='27'>
      <td align="center"><b>시작일/종료일</b></td>      
      <td align="left" bgcolor='#FFFFFF'>&nbsp;&nbsp;<? echo $my_start_day."~".$my_end_day?></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='2'></td>
    </tr>

	 <tr bgcolor='#F4F4F4' height='27'>
      <td align="center"><b>팝업창 크기</b></td>      
      <td align="left" bgcolor='#FFFFFF'>&nbsp;&nbsp; 가로 : <? echo $my_width;?> 세로 : <?=$my_height;?></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='2'></td>
    </tr>

	<tr bgcolor='#F4F4F4' height='27'>
      <td align="center"><b>팝업창 위치</b></td>      
      <td align="left" bgcolor='#FFFFFF'>&nbsp;&nbsp; Left : <? echo $my_p_left;?> | Top : <?=$my_p_top;?></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='2'></td>
    </tr>

<? if($my_display=="1"){// 이미지 팝업창일때?>
	 <tr bgcolor='#F4F4F4' height='27'>
      <td align="center"><b>링크 URL</b></td>      
      <td align="left" bgcolor='#FFFFFF'>&nbsp;&nbsp; http://<?=$my_link_url;?></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='2'></td>
    </tr>

	 <tr bgcolor='#F4F4F4' height='27'>
      <td align="center"><b>첨부 이미지</b></td>      
      <td align="left" bgcolor='#FFFFFF'>&nbsp;&nbsp; <?=$tm_attach_file_tmp;?></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='2'></td>
    </tr>

<? } else { //HTML 팝업창일때?>

     <tr bgcolor='#F4F4F4' height='27'>
      <td align="center"><b>출력 내용[HTML]</b></td>      
      <td align="left" bgcolor='#FFFFFF'>&nbsp;&nbsp; <?=$my_content;?></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='2'></td>
    </tr>

<? }?>	
  </table>
  <br>

<?
	// 삭제폼에서 listbody.inc 를 가져다 쓰는 경우를 고려했다.
	// 삭제폼에서 $DELETE_PRINT_YN = "N"; 를 넣은경우 아래 부분은 출력하지 않는다.
	if($DELETE_PRINT_YN != "N")
	{
?>

  <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
    <tr>
      <td height="36" align="right"><?=$MODIFY?> <?=$DELETE?> <?=$LIST?></td>
    </tr>
  </table>

<BR>
<BR>
<?
	}
?>