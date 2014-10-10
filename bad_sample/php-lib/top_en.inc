<?php include "site_config_en.inc"; ?>
<!DOCTYPE html>
<html lang="ko">
<head>
<meta charset="utf-8" />
<title><?=$cf_site_nm?></title>
<meta name="description" content="<?=$cf_meta_desc?>">
<meta http-equiv="keywords" content="<?=$cf_meta_keywd?>">
<link href="/en/css/common.css" rel="stylesheet" type="text/css" />
<link rel="shortcut icon" href="/en/images/favicon.ico" />
<script type="text/javascript" src="/js/jquery-1.11.1.min.js"></script>
<script src="/en/js/top_menu.js"></script>
<script src="/en/js/menu.js"></script>
<?=$JS?>
<!--[if IE]>
<meta http-equiv="X-UA-Compatible" content="IE=Edge,chrome=1" />
<![endif]-->
</head>
<body>
<!--[if lt IE 9]>
	<script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
<![endif]-->
<div id="skip" class="blind">
	<dl>
		<dt>콘텐츠 바로가기</dt>
		<dd><a href="#MainMenu">menu</a></dd>
		<dd><a href="#main_content">main contents</a></dd>
		<dd><a href="#footer">copyright</a></dd>
    </dl>
</div>
<hr class="hidden" />
<div id="wrapper">
  <div id="wrap">
        <!--head menu-->
		<div id="head_menu">
			<h1><a href="/en/main.html"><img src="/en/images/logo.gif" alt="if-imagination factory" /></a></h1>
			<ul id="top_sm">
				<li><a href="/"><img src="/en/images/intro.gif" alt="intro" /></a></li>
				<?php if(empty($cf_cook_id)): ?>
				<!-- <li><a href="javascript:FlashLink(5,2)"><img src="/en/images/join.gif" alt="join" /></a></li>
				<li><a href="javascript:FlashLink(5,1)"><img src="/en/images/login.gif" alt="login" /></a></li> -->
				<li><a href="javascript:FlashLink(5,6)"><img src="/en/images/admin.gif" alt="admin" /></a></li>
				<?php else: ?>
				<li><a href="/member/login/logout.html"><img src="/en/images/logout.gif" alt="logout" /></a></li>
				<?php endif ?>
				<li><a href="javascript:FlashLink(5,5)"><img src="/en/images/contactus.gif" alt="contactus" /></a></li>
			</ul>

			<!--main menu-->
				<div id="MainMenu">
					<h3>main menu</h3>
					<ul>
						<li id="gm_01"><a href="javascript:FlashLink(1,1)" onmouseover="setMenu(1);" onfocus="setMenu(1);" accesskey="1" id="mm1"><img src="/en/images/menu/menu1.gif" name="g_menu_011"></a>        
						<ul style="display: none;"  id="gmsub_201">
								  <!-- <li><a href="javascript:FlashLink(1,1)"><img src="/en/images/menu/menu1_1.gif"></a></li>			  
								  <li><a href="javascript:FlashLink(1,2)"><img src="/en/images/menu/menu1_2.gif"></a></li>				
								  <li><a href="javascript:FlashLink(1,3)"><img src="/en/images/menu/menu1_3.gif"></a></li> -->
							</ul>    
						</li>    

						<li id="gm_02"><a href="javascript:FlashLink(2,1)" onmouseover="setMenu(2);" onfocus="setMenu(2);" accesskey="2" id="mm2" ><img src="/en/images/menu/menu2.gif" name="g_menu_021"></a>
						  <ul style="display: none;"  id="gmsub_202">
						    <li><img src="/en/images/menu/menu_left.gif"></li>
							<li><a href="javascript:FlashLink(2,1)"><img src="/en/images/menu/menu2_1.gif"></a></li>	
							<li><a href="javascript:FlashLink(2,2)"><img src="/en/images/menu/menu2_2.gif"></a></li>				
							<li><a href="javascript:FlashLink(2,3)"><img src="/en/images/menu/menu2_3.gif"></a></li>
							<li><img src="/en/images/menu/menu_right.gif"></li>
						  </ul>    
						</li>

						<li id="gm_03"><a href="javascript:FlashLink(3,1)" onmouseover="setMenu(3);" onfocus="setMenu(3);" accesskey="3"   id="mm3"><img src="/en/images/menu/menu3.gif" name="g_menu_031"></a>
						   <ul style="display: none;" id="gmsub_203">
						          <li><img src="/en/images/menu/menu_left.gif"></li>
								  <li><a href="javascript:FlashLink(3,1)"><img src="/en/images/menu/menu3_1.gif"></a></li>			  
								  <li><a href="javascript:FlashLink(3,2)"><img src="/en/images/menu/menu3_2.gif"></a></li>
								  <li><img src="/en/images/menu/menu_right.gif"></li>
						  </ul>    
						</li>

						<li id="gm_04"><a href="javascript:FlashLink(4,1)" onmouseover="setMenu(4);" onfocus="setMenu(4);" accesskey="4"  id="mm4"><img src="/en/images/menu/menu4.gif" name="g_menu_041"></a>
						  <ul style="display: none;" id="gmsub_204">
							     <!--  <li><a href="javascript:FlashLink(4,1)"><img src="/en/images/menu/menu4_1.gif"></a></li>	 -->
						  </ul>    
						</li>

											 
						</ul>
				</div>
               <script type="text/javascript">
					setMenu(0);
				</script>

				<div class="sub_txt"><img src="/en/images/sub_txt.png"></div>
				<div class="sub_img"><img src="/en/images/cube.png"></div>

			<!--//main menu-->
		</div>
		<!--//head menu-->


		<!--main contents-->
		<div id="main_content">

		  <div id="cont"><!--컨텐츠-->

			  <h2 id="title"><tt><img src="/en/images/title/title_icon.gif" />&nbsp;&nbsp;<?=$title_images?></tt></h2>
			  <div class="na">Home &gt; <?=$menu_nm[$tm_menu_num][0]?> &gt; <span><?=$menu_nm[$tm_menu_num][$tm_submenu_num]?></span></div>

			  <div class="contents">