<?
	// listbody.inc 를 그대로 가져다 쓰는 경우
	// 하단 버튼 등을 가져다 쓰지 않기 위해 $DELETE_PRINT_YN = "N"; 를 셋팅한다.
	$DELETE_PRINT_YN = "N";
	include $cf_skin_nm . "/listbody.inc";
?>
<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td><img src="<?=$cf_images_dir?>/space.gif" width="1" height="8"></td>
  </tr>
  <tr>
    <td><table width="40%" height="30"  border="0" align="right" cellpadding="0" cellspacing="0">
        <tr>
          <th width="100" bgcolor="#E7E7E7">비밀번호</th>
          <td width="1"><img src="<?=$cf_images_dir?>/h_line2.gif" width="1" height="25"></td>
          <td bgcolor="#F8F8F8"><div align="center">
            <input type="password" name="fr_passwd" style="width:100" class="box" maxlength="30" value="<?=$admin_passwd?>">
          </div></td>
        </tr>
    </table></td>
  </tr>
  <tr>
    <td bgcolor="#D3D3D3"><img src="<?=$cf_images_dir?>/space.gif" width="1" height="1"></td>
  </tr>
</table>
<table width="<?=$cf_table_wd_large?>" border="0" cellspacing="3" cellpadding="3">
  <tr>
    <td width="36"><?=$LIST?></td>
    <td width="480">&nbsp;</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <td><input type="image" src="<?=$cf_images_dir?>/delete.gif" align="absmiddle"></td>
    <td><a href="javascript:history.back()"><img src="<?=$cf_images_dir?>/cancel.gif" align="absmiddle"></a></td>
  </tr>
</table>
