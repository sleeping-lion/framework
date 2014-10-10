<?php include "manager/manager_config.inc"; ?>
<!DOCTYPE html>
<html>
<head>
<title><?=$cf_site_nm?> 관리자페이지</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<link href="/css/text.css" rel="stylesheet" type="text/css">
<link href="/css/manager.css" rel="stylesheet" type="text/css">
<link href="/css/project.css" rel="stylesheet" type="text/css">
<?php if(isset($CSS)) echo $CSS; ?>
<script language="javascript" src="/js/common.js"></script>
<script language="JavaScript" src="/js/PopupCalendar.js"></script>
<script language="javascript" src="/js/jquery.min.js"></script>
<?php if(isset($JS)) echo $JS; ?>
<?php
//aa 최고관리자 bb관리자
if(!$_SESSION['USER_ID'] || ($_SESSION['USER_ID'] && ($_SESSION['USER_LEVEL'] != "aa" && $_SESSION['USER_LEVEL'] != "bb"))) {
?>
	<SCRIPT LANGUAGE="JavaScript">
	<!--
		alert("로그인 해주세요.");
		location.href="<?=$tm_login_url?>";
	//-->
	</SCRIPT>
<?
	exit;
}?>
<!--[if IE]>
<meta http-equiv="X-UA-Compatible" content="IE=Edge,chrome=1" />
<![endif]-->
</head>
<body leftmargin="0" topmargin="0" bgcolor="#FFFFFF">
<!--[if lt IE 9]>
	<script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
<![endif]-->
<div class="m_warp">
	<table width="100%" border="0" cellspacing="0" cellpadding="0">
	  <tr>
		<th width="250" align="center"><a href="/manager"><img src="/manager/images/logo.jpg"></a></th>
		<td align="center" valign="top" style="padding:0px 0 0 0;">
		<!-- 소메뉴 -->
		<?include "manager/small_menu.inc";?>
		 </td>
	  </tr>
	</table>
</div>

<table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr>
	<td width="200" valign="top" bgcolor="#F4F4F4">
		<!-- left menu -->
		<?include "manager/manager_left.inc";?>
	</td>
	<td align="center" valign="top">
		<div class="cf_title_div_top">
			<div class="cf_title_div"><div class="cf_title"><?=$cf_title_nm?></div></div>
		</div>
		<br />
