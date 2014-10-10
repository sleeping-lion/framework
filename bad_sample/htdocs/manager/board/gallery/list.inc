<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
<?
	for($i=0; $i<$board->record_count; $i+=4)
	{
?> 


  <!-- 레코드 출력 시작 -->
  <tr>
    <td><img src="images/space.gif" width="1" height="2"></td>
  </tr><!-- 겔러리롤링시작 -->
  <tr>
  <td>
	<table width="145" border="0" cellspacing="0" cellpadding="9">
        <tr> 
          <td width="145" height="120" align="center" valign="top" background="/images/photolinebg.gif">
			<table width="125" border="0" cellspacing="0" cellpadding="0">
			<tr> 
                <td height="95" align="center" bgcolor="#FFFFFF"><a href="<?=$arr[$i][LISTBODY_LINK]?>"><?=$arr[$i][IMAGE]?></a></td>
			</tr>
			</table>
		  </td>
		</tr>
		<tr height="5" valign="top" align="center">
		<td height="5">&nbsp<?=$arr[$i][SUBJECT_G]?>&nbsp</td>
		</tr>
     </table>
	</td>
	<td>
	 <table width="145" border="0" cellspacing="0" cellpadding="9">
        <tr> 
          <td width="145" height="120" align="center" valign="top" background="/images/photolinebg.gif">
			<table width="125" border="0" cellspacing="0" cellpadding="0">
			<tr> 
                <td height="95" align="center" bgcolor="#FFFFFF"><a href="<?=$arr[$i+1][LISTBODY_LINK]?>"><?=$arr[$i+1][IMAGE]?></a></td>
			</tr>
			</table>
		  </td>
		</tr>
		<tr height="5" valign="top" align="center">
		<td height="5">&nbsp<?=$arr[$i+1][SUBJECT_G]?>&nbsp</td>
		</tr>
     </table>
	 </td>
	 <td>
	 <table width="145" border="0" cellspacing="0" cellpadding="9">
        <tr> 
          <td width="145" height="120" align="center" valign="top" background="/images/photolinebg.gif">
			<table width="125" border="0" cellspacing="0" cellpadding="0">
			<tr> 
                <td height="95" align="center" bgcolor="#FFFFFF"><a href="<?=$arr[$i+2][LISTBODY_LINK]?>"><?=$arr[$i+2][IMAGE]?></a></td>
			</tr>
			</table>
		  </td>
		</tr>
		<tr height="5" valign="top" align="center">
		<td height="5">&nbsp<?=$arr[$i+2][SUBJECT_G]?>&nbsp</td>
		</tr>
     </table>
	 </td>
	 <td>
	 <table width="145" border="0" cellspacing="0" cellpadding="9">
        <tr> 
          <td width="145" height="120" align="center" valign="top" background="/images/photolinebg.gif">
			<table width="125" border="0" cellspacing="0" cellpadding="0">
			<tr> 
                <td height="95" align="center" bgcolor="#FFFFFF"><a href="<?=$arr[$i+3][LISTBODY_LINK]?>"><?=$arr[$i+3][IMAGE]?></a></td>
			</tr>
			</table>
		  </td>
		</tr>
		<tr height="5" valign="top" align="center">
		<td height="5">&nbsp<?=$arr[$i+3][SUBJECT_G]?>&nbsp</td>
		</tr>
     </table>
	 </td>

	
 
 <!-- 갤러리롤링끝 -->
  <!-- 레코드 출력 끝 -->
<?
	}

	// 등록된 사진이 없는경우
	if($board->record_count < 1)
	{
		if($key) $tm_search_msg = "검색된";
		else $tm_search_msg = "등록된";
?>
  <tr>
    <td height="25" align='center' valign="middle">
	  <?=$tm_search_msg?> 이미지가 없습니다
    </td>
  </tr>
<?
	}
?>
 
</table>

<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="3" bordercolorlight="#660099" bordercolordark="#FFFFFF" >
  <tr> 
    <td width="130" valign="bottom"><font style='font-size:7pt' face="Verdana, Arial, Helvetica, sans-serif"><?=$board->page?> 
      / <?=$board->total_page?>&nbsp;&nbsp;Data:<?=$board->total?></font></td>
    <td height="30" align="right" valign="bottom"> 
      <!-- 글쓰기버튼 -->
      <?=$POST?>
	</td>
  </tr>
  <tr bgcolor="#E7E7E7"> 
    <td height="1" colspan="2"></td>
  </tr>
  <tr> 
    <td colspan="2" align="center"> 
      <!-- 맨처음리스트로 -->
      <!-- 게시물5페이지씩보여주기 -->
      <?=$PREV_BLOCK?>
<?
	# 페이지 링크출력
	for($i=0; $i<$board->page_count; $i++)
	{
		if($i != 0)
		{
			echo " <font color='#CCCCCC'>|</font> ";
		}
        echo $PAGES[$i];
	}
?>
      <?=$NEXT_BLOCK?>
      <!-- 맨마지막게시물 리스트 -->
    </td>
  </tr>
  <tr> 
    <td colspan="2"><img src="<?=$cf_images_dir?>/space.gif" width="1" height="1"> </td>
  </tr>
</table><!-- 게시물 검색관련한 테이블 시작 -->

