<form name="commentform" method="post" action="listbody_comment_post.html">
<input type="hidden" name="a_gb" value="<?=$a_gb?>">
<input type="hidden" name="a_cd" value="<?=$a_cd?>">
<input type="hidden" name="a_item" value="<?=$a_item?>">
<input type="hidden" name="po_uri" value="<?=$po_uri?>">
<input type="hidden" name="po_no" value="<?=$po_no?>">
<input type="hidden" name="po_c_no" value="">
<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td>
      <!--코멘트 테이블 시작 -->
      <table width="<?=$cf_table_wd_large?>" border="0" align="center" cellpadding="0" cellspacing="0">
	    <tr>
		  <td height="1" colspan="3" bgcolor="#000000"></td>
	    </tr>
<?
		for($i=0; $i<$my_comment_count; $i++)
		{
?>
        <tr>
		  <td height="10" colspan="3" ></td>
		</tr>
	    <tr bgcolor="#FAFAFA" style="padding:10px">
          <td width="15%"><strong><!-- 코멘트작성자 이름 -->&nbsp; <?=$comment_arr[$i][INPUT_NM]?></strong></td>
          <td><!-- 코멘트내용 --><?=$comment_arr[$i][MEMO]?></td>
          <td width="12%" align="center">
		    <FONT class=text8pt><!-- 코멘트작성일 --><?=$comment_arr[$i][INPUT_YMDHMS]?></FONT>
			<!-- 코멘트삭제버튼 --><?=$comment_arr[$i][COMM_DEL]?>
		  </td>
        </tr>
	    <tr>
		  <td height="10" colspan="3"></td>
		</tr>
	    <tr>
		  <td height="1" colspan="3" bgcolor="#000000"></td>
	    </tr>
<?
		}
?>
        <tr>
          <td colspan="3">
		    <TABLE width="80%" border=0 align="right" cellPadding=0 cellSpacing=0 style="MARGIN-TOP: 5px; MARGIN-BOTTOM: 5px">
			  <TR>
                <TD><TEXTAREA class="contents" style="WIDTH: 100%" tabIndex=11 name="fr_comm_memo" rows=3></TEXTAREA></TD>
              </TR>
              <TR>
                <TD style="PADDING-TOP: 3px">
				  <TABLE cellSpacing=0 cellPadding=0 width="100%" border=0>
                    <TR>
                      <TD style="COLOR: #555555" align=left width=50><B>COMMENT</B></TD>
                      <TD align="right" valign="top">NAME <!-- 코멘트작성자 --><INPUT class="box" tabIndex=12 maxLength=10 size=9 name="fr_comm_input_nm" value="<?=$cf_cook_nm?>"> &nbsp;&nbsp; PASS&nbsp; <!-- 코멘트작성자비밀번호 --><INPUT class="box" tabIndex=13 type="password" maxLength=10 size=9 name="fr_comm_passwd"> </TD>
                      <TD align=right>
					    <img src="<?=$cf_images_dir?>/comm_post.gif" align=absMiddle onClick="checkIt_comm()" style="cursor:hand" tabIndex=14></TD>
                    </TR>
                  </TABLE></TD>
              </TR>
            </TABLE>
          </td>
        </tr>
      </table>
      <!--코멘트 테이블 끝 -->
    </td>
  </tr>
</table>

<!-- 코멘트삭제문구레이어시작 -->
<DIV id="del_comm" style="BORDER-TOP-WIDTH: 1px; BORDER-LEFT-WIDTH: 1px; Z-INDEX: 1; LEFT: 0px; VISIBILITY: hidden; BORDER-BOTTOM-WIDTH: 1px; WIDTH: 170px; POSITION: absolute; TOP: 0px; HEIGHT: 62px; BORDER-RIGHT-WIDTH: 1px">
<TABLE style="BORDER-RIGHT: #dddddd 1px solid; BORDER-TOP: #dddddd 1px solid; MARGIN-TOP: 5px; BORDER-LEFT: #dddddd 1px solid; BORDER-BOTTOM: #dddddd 1px solid" cellSpacing=0 cellPadding=2 width=170 bgColor=#f5f5f5 border=0>
  <TR>
	  <TD>
	  <TABLE cellSpacing=0 cellPadding=0 width="100%" border=0>
		 <TR>
		  <TD class=text8pt align=middle height=18><B>Delete</B></TD>
			</TR>
			<TR>
			  <TD bgColor=#dddddd height=1></TD>
			</TR>
			<TR bgColor=#ffffff>
			  <TD class=text8pt align=middle height=35>Password&nbsp;&nbsp;
				<INPUT class="box" type=password maxLength=30 size=10 name="fr_del_passwd"> </TD>
			</TR>
			<TR align=middle bgColor=#ffffff>
			  <TD style="PADDING-TOP: 2px" height=30>
			  <IMG src="<?=$cf_images_dir?>/comm_ok.gif" align=absMiddle onClick="checkIt_commdel()" style="cursor:hand">&nbsp; <IMG src="<?=$cf_images_dir?>/comm_cancel.gif" align=absMiddle onClick="show_commdel_form(0)" style="cursor:hand"></A></TD>
			</TR>
		</TABLE></TD>
	</TR>
</TABLE>
</DIV>
<!-- 코멘트문구 삭제 레이어 끝 -->
</form>
