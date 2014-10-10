<!-- 에디터 -->
<script language="Javascript1.2"><!-- // load htmlarea
_editor_url = "./edit/";                     // URL to htmlarea files
_Upload_url = "<?=$cf_savedir?>"
var win_ie_ver = parseFloat(navigator.appVersion.split("MSIE")[1]);
if (navigator.userAgent.indexOf('Mac')        >= 0) { win_ie_ver = 0; }
if (navigator.userAgent.indexOf('Windows CE') >= 0) { win_ie_ver = 0; }
if (navigator.userAgent.indexOf('Opera')      >= 0) { win_ie_ver = 0; }
if (win_ie_ver >= 5.5) {
  document.write('<scr' + 'ipt src="' +_editor_url+ 'editor.js"');
  document.write(' language="Javascript1.2"></scr' + 'ipt>');  
} else { document.write('<scr'+'ipt>function editor_generate() { return false; }</scr'+'ipt>'); }
// --></script>

<?php
	$MY_URI = get_php_self_filename($_SERVER[PHP_SELF]);  
//	include $cf_initial_s . "_necessary.inc";

	if($cf_cook_nick_nm)
		$tm_input_nm = $cf_cook_nick_nm;
	else
		$tm_input_nm = $my_input_nm;

	$tm_input_Y = substr($my_input_ymdhms, 0, 4);
	$tm_input_m = substr($my_input_ymdhms, 4, 2);
	$tm_input_d = substr($my_input_ymdhms, 6, 2);
	$tm_input_H = substr($my_input_ymdhms, 8, 2);
	$tm_input_i = substr($my_input_ymdhms, 10, 2);
	$tm_input_s = substr($my_input_ymdhms, 12, 2);
?>
 <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
    <tr height='3'>
      <td width="120" bgcolor='#cacaca'></td>
      <td width="480" bgcolor='#444444'></td>
    </tr>
  </table>


<table width="<?=$cf_table_wd_large?>" border="0" cellpadding="0" cellspacing="0">

	<tr bgcolor='#F4F4F4' height="27">
       <td width="119" align="center"><img src="<?=$cf_images_dir?>/title.gif"></td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td width="480">&nbsp;&nbsp;<input type="text" name="fr_subject" size="60" maxlength="60" value="<?=$my_subject?>" class='box'></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='3'></td>
    </tr>

	<tr bgcolor='#F4F4F4' height="27">
      <td align="center"><img src="<?=$cf_images_dir?>/name.gif"></td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td>&nbsp;&nbsp;<input type="text" name="fr_input_nm" size="15" maxlength="10" value="<?=$my_sign_nm?>" class='box'></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='3'></td>
    </tr>
    
	<tr bgcolor='#F4F4F4' height="27">
      <td align="center"><img src="<?=$cf_images_dir?>/email.gif"></td>
      <td width="1"><img src="<?=$cf_images_dir?>/th_line.gif"></td>
      <td>&nbsp;&nbsp;<input type="text" name="fr_email" size="15" value="<?=$my_email?>" class='box'></td>
    </tr>
    <tr>
      <td bgcolor='#E4E4E4' height='1' colspan='3'></td>
    </tr>
</table>

<table width="<?=$cf_table_wd_large?>" border="0" cellpadding="0" cellspacing="0">
<tr bgcolor='#F4F4F4'><td height="5"></td></tr>
<tr bgcolor='#F4F4F4' height="27">
	<td colspan="3" align="center"><textarea name="fr_memo" cols="95%" rows="30" class='contents'><?=$my_memo?></textarea><BR><BR></td>
</tr>
</table>

  <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
    <tr height='1'>
      <td bgcolor='#DBDBDB'></td>
    </tr>
    <tr height='4'>
      <td bgcolor='#F5F5F5'></td>
    </tr>
  </table>
  <br>

  <table width="<?=$cf_table_wd_large?>" border="0" cellspacing="0" cellpadding="0">
    <tr>
      <td height="36" align="right">
	    <input type="image" src="<?=$cf_images_dir?>/ok.gif"></a>
	    <a href="javascript:signform.reset();"><img src="<?=$cf_images_dir?>/cancel.gif" border="0"></a>
		<a href="list.html?<?=$po_adv_query?>" onMouseOver="status='reload articles';return true;" onMouseOut="status=''"><img src="<?=$cf_images_dir?>/list.gif" border="0"></a>
	  </td>
    </tr>
  </table>
  <BR>
  <BR>

<!-- 에디터 -->
<script language="javascript1.2">
  var config = new Object();    // create new config object
  config.width = "580px";
  config.height = "300px";
<? if($cf_allow_html_yn == "Y") {?>
  editor_generate("fr_memo", config);
<?}?>
</script>

