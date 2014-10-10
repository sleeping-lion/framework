<?php include "site_config.inc"; ?>
<!DOCTYPE html>
<html lang="ko">
<head>
<title>종로세종당구아카데미 국일관당구클럽</title>
<meta charset="utf-8">
<meta name="description" content="종로세종당구아카데미 국일관당구클럽">
<meta name="keywords" content="종로세종당구아카데미 국일관당구클럽">
<!--[if IE]>
<meta http-equiv="X-UA-Compatible" content="IE=Edge,chrome=1" />
<![endif]-->
<link rel="stylesheet" type="text/css" href="/css/common.css" />
<script type="text/javascript" src="/js/common.js"></script>
<script type="text/javascript" src="/js/javascript.js"></script>
<script type="text/javascript" src="/js/jquery-1.6.4.js"></script>
<script type="text/javascript" src="/js/ui.js"></script>
<script type="text/javascript" src="/js/handong_util.js"></script>
<?=$JS?>
</head>
<body>
<!--accessibility start-->
<div id="accessibility">
	<ul>
		<li><a href="#gnb">주메뉴바로가기</a></li>
		<li><a href="#main_wrap">컨텐츠바로가기</a></li>
	</ul>
</div>
<hr />



<div id="wrapper" class="sub_bg"><!-- wrapper start --> 		
		<div id="header"><!-- header start --> 
		
		<!-- gnb start -->
			<h1><a href="/"><img src="/images/logo.gif" alt="종로세종당구아카데미 국일관당구클럽" /></a></h1>


				<div id="gnb">

					<div class="topMenu">
                        <span><a href="/">HOME</a></span>
                        <!-- <span><a href="" title="join">JOIN</a></span> -->
                        <span><a href="/sitemap.html?sm=5_1">SITEMAP</a></span>
                        <?php if(isset($_SESSION['USER_ID'])): ?>
                        <span><?php echo $_SESSION['USER_NAME'] ?>님 환영합니다.<a href="/manager/login/logoff.html">로그아웃</a></span>
						<?php else: ?>
                        <span><a href="/manager">ADMIN</a></span>
						   <?php endif ?>
                    </div>

					<ul id="gnbmenu">

						<li class="menus"><a class="menus-title" href="/greeting.html?sm=1_1" onfocus="sildeDown('sm1');sildeUp('sm2');" onmouseover="sildeDown('sm1');" onmouseout="sildeUp('sm1');"><img src="/images/menu1.jpg" alt="인사말" /></a>
							<div class="layer0 pos1" id="sm1" onmouseover="sildeDown('sm1');" onmouseout="sildeUp('sm1');">
								<ul>
									<li style="margin-left:20px;"><a class="smenu1" href="/greeting.html?sm=1_1">인사말씀</a></li>
									<li><a class="smenu2" href="/company.html?sm=1_2">시설소개</a></li>
								</ul>
							</div>
						</li>

						<li class="menus"><a class="menus-title" href="/course.html?sm=2_1" onfocus="sildeDown('sm2');sildeUp('sm1');sildeUp('sm3');" onmouseover="sildeDown('sm2');" onmouseout="sildeUp('sm2');"><img src="/images/menu2.jpg" alt="강의안내" /></a>
							<div class="layer0 pos2" id="sm2" onmouseover="sildeDown('sm2');" onmouseout="sildeUp('sm2');">
								<ul>
									<li style="margin-left:20px;"><a class="smenu2" href="/course.html?sm=2_1">수강안내및 수강료</a></li>
									<li><a class="smenu2" href="/lecturer.html?sm=2_2">강사소개</a></li>
								</ul>
							</div>			
						</li>

						<li class="menus"><a class="menus-title" href="/common/board/list.html?a_gb=board&a_cd=2&a_item=0&sm=3_1" onfocus="sildeDown('sm3');sildeUp('sm2');sildeUp('sm4');" onmouseover="sildeDown('sm3');" onmouseout="sildeUp('sm3');"><img src="/images/menu3.jpg" alt="커뮤니티" /></a>
							<div class="layer0 pos3" id="sm3" onmouseover="sildeDown('sm3');" onmouseout="sildeUp('sm3');">
								<ul>
									<li style="margin-left:30px;"><a class="smenu1" href="/common/board/list.html?a_gb=board&a_cd=2&a_item=0&sm=3_1">아카데미소식</a></li>
									<li><a class="smenu2" href="/common/board/list.html?a_gb=board&a_cd=1&a_item=0&sm=3_2">동호회소식</a></li>
									<li><a class="smenu3" href="/common/board/list.html?a_gb=board&a_cd=3&a_item=0&sm=3_3">자유게시판</a></li>									
								</ul>
							</div>			
						</li>

						<li class="menus"><a class="menus-title" href="/common/board/list.html?a_gb=board&a_cd=4&a_item=0&sm=6_1" onfocus="sildeDown('sm5');sildeUp('sm4');sildeUp('sm6');" onmouseover="sildeDown('sm5');" onmouseout="sildeUp('sm5');"><img src="/images/menu6.jpg" alt="공지사항" /></a>
                            <div class="layer0 pos5" id="sm5" onmouseover="sildeDown('sm5');" onmouseout="sildeUp('sm5');">
                                <ul>
                                    <li style="margin-left:20px;"><a class="smenu1" href="/common/board/list.html?a_gb=board&a_cd=4&a_item=0&sm=6_1">공지사항</a></li>
                                </ul>
                            </div>          
                        </li>

						<li class="menus"><a class="menus-title" href="/location.html?sm=4_1" onfocus="sildeDown('sm4');sildeUp('sm3');sildeUp('sm5');" onmouseover="sildeDown('sm4');" onmouseout="sildeUp('sm4');"><img src="/images/menu4.jpg" alt="찾아오시는길" /></a>
							<div class="layer0 pos4" id="sm4" onmouseover="sildeDown('sm4');" onmouseout="sildeUp('sm4');">
								<ul>
									<li style="margin-left:20px;"><a class="smenu1" href="/location.html?sm=4_1">찾아오시는길</a></li>
								</ul>
							</div>			
						</li>

						
					</ul>
					
				</div>
			<!-- gnb end      -->
 
		</div><!-- header end -->
		


<div id="wrap"><!-- wrap start -->
        <div id="wrap_sub"><!-- wrap_sub start -->
     
            <!-- left start -->
            <?php include $left_include; ?>
            <!--// left end --> 
                
     
            <div id="contents_wrap"><!-- contents_wrap start -->    

                    <div id="title_area">   
                        <h3 id="h3"><?=$title_images?>&nbsp;&nbsp;<img src="/images/title/title_txt.gif"></h3>   
                        <div id="location">
                            <ul>
                                <li class="home">홈 &nbsp;&nbsp;>&nbsp;</li>
                                <li><?=$menu_nm[$tm_menu_num][0]?> &nbsp;&nbsp;>&nbsp;</li>
                                <li class="now"><?=$menu_nm[$tm_menu_num][$tm_submenu_num]?></li>
                            </ul>
                        </div>                  
                    </div>              

                <div id="contents">
