<form name="searchForm" method="post" action="list.html?<?=$po_basic_query?>">
<table width="<?=$cf_table_wd_large?>" cellpadding="2"  cellspacing="0" style="border:1 solid #cccccc">
  <tr valign='middle'> 
    <td align="center" valign="center">
	  <input type="checkbox" name="keyfield_subject" value="subject" <?=$keyfield_subject_checked?>> 제목&nbsp;
	  <input type="checkbox" name="keyfield_input_nm" value="sign_nm" <?=$keyfield_input_nm_checked?>> 글쓴이&nbsp;
	  <input type="checkbox" name="keyfield_memo" value="memo" <?=$keyfield_memo_checked?>> 내용&nbsp;
	  <input type="text" size="20" maxlength="30" name="key" value='<?=$key?>' class="box"> &nbsp;
	  <a onMouseOver="status='search';return true;" onMouseOut="status=''" onclick="submit(this.form)"><img src='<?=$cf_images_dir?>/search.gif' align="absmiddle"></a></td>
  </tr>
</table>
</form>
