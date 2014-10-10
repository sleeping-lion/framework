
<script>
	function check_passwd() {
		if(!signform.fr_passwd.value) {
			alert ("비밀번호를 입력하세요.");
			return;
		}

		signform.submit();

	}
</script>

<form name="signform" method="post" action="check.html?<?=$po_adv_query?>&page=<?=$page?>&po_no=<?=$po_no?>&po_fid=<?=$my_fid?>" onsubmit="check_passwd();return false">

<table width="450" border="0" cellpadding="0" cellspacing="0">
	<tr>
      <td height="60" bgcolor='#F2F2F2'><br>

        <table width="90%" border="0" align="center" cellpadding="5" cellspacing="0" bgcolor="#FFFFFF">
          <tr>
            <td align="center" style='font-size:10pt;color:#8C8A10 ; font-weight:bold'>▒ <?=$my_input_nm?>님께서 작성하신 비밀글입니다. ▒</td>
          </tr>
		  <tr>
            <td align="center" style='font-size:9pt; color:#6B6D6B'>작성시 입력한 비밀번호를 입력해 주세요! <br> 답변 글일 경우 원글 비밀번호와 같습니다.</td>
          </tr>
		  <tr>
			<td align="center">비밀번호 <input type="password" name="fr_passwd" size="15" class="box"> &nbsp;&nbsp;<input type="image" src="<?=$cf_images_dir?>/ok.gif" border="0" align="absmiddle">
			&nbsp;&nbsp;<a href="list.html?<?=$po_adv_query?>" onMouseOver="status='reload articles';return true;" onMouseOut="status=''"><img src="<?=$cf_images_dir?>/list.gif" border="0" align="absmiddle"></a>
			</td>
		  </tr>
        </table>

        <br>
      </td>
    </tr>
 </table>

</form>
