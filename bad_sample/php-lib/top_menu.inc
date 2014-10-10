

	<h1><a href="/"><img src="/images/logo.jpg" alt="피치텍" /></a></h1>


	<div id="gnb">

		<div class="topMenu">
			<span><a href="/">Home</a></span>
			<?php if(!$cf_cook_id){?>
			<span><a href="/member/login/login.html?a_gb=member&a_cd=3&a_item=0&sm=7_1">로그인</a></span>
			<span><a href="/member/register/register.html?a_gb=member&a_cd=1&a_item=0&sm=7_2" title="join">회원가입</a></span>
			<?php } else {?>
			<span><a href="/member/login/logout.html">로그아웃</a></span>
			<span><a href="/member/register/modifyform.html?a_gb=member&a_cd=2&a_item=0&sm=7_7">회원정보수정</a></span>
			<?php } ?> 
			<span><a href="/contents/sitemap.html?sm=8_1">사이트맵</a></span>
		</div>


		<ul id="gnbmenu">

			<li class="menus"><a class="menus-title" href="/contents/company.html?sm=1_1" onfocus="sildeDown('sm1');sildeUp('sm2');" onmouseover="sildeDown('sm1');" onmouseout="sildeUp('sm1');"><img src="/images/menu1.png" alt="회사소개" /></a>
				<div class="layer0 pos1" id="sm1" onmouseover="sildeDown('sm1');" onmouseout="sildeUp('sm1');">
					<ul>
						<li style="margin-left:20px;"><a class="smenu1" href="/contents/company.html?sm=1_1">인사말</a></li>
						<li><a class="smenu2" href="/contents/manage.html?sm=1_2">비전/경영이념</a></li>
						<li><a class="smenu3" href="/contents/history.html?sm=1_3">연혁</a></li>
						<li><a class="smenu4" href="/contents/cert.html?sm=1_4">인증현황</a></li>
						<li><a class="smenu5" href="/contents/location.html?sm=1_5">오시는 길</a></li>
					</ul>
				</div>
			</li>

			<li class="menus"><a class="menus-title" href="/contents/peachtech_text.html?sm=2_1" onfocus="sildeDown('sm2');sildeUp('sm1');sildeUp('sm3');" onmouseover="sildeDown('sm2');" onmouseout="sildeUp('sm2');"><img src="/images/menu2.png" alt="근적외선" /></a>
				<div class="layer0 pos2" id="sm2" onmouseover="sildeDown('sm2');" onmouseout="sildeUp('sm2');">
					<ul>
						<li style="margin-left:20px;"><a class="smenu2" href="/contents/peachtech_text.html?sm=2_1">근적외선이란</a></li>
					</ul>
				</div>			
			</li>

			<li class="menus"><a class="menus-title" href="/contents/pt_100.html?sm=3_1" onfocus="sildeDown('sm3');sildeUp('sm2');sildeUp('sm4');" onmouseover="sildeDown('sm3');" onmouseout="sildeUp('sm3');"><img src="/images/menu3.png" alt="제품소개" /></a>
				<div class="layer0 pos3" id="sm3" onmouseover="sildeDown('sm3');" onmouseout="sildeUp('sm3');">
					<ul>
						<li style="margin-left:30px;"><a class="smenu1" href="/contents/pt_100.html?sm=3_1">PT-100</a></li>
						<!-- <li><a class="smenu2" href="/contents/pt_200.html?sm=3_2">PT-200</a></li> -->
					</ul>
				</div>			
			</li>

			<li class="menus"><a class="menus-title" href="/common/board/list.html?a_gb=board&a_cd=1&a_item=0&sm=4_1" onfocus="sildeDown('sm4');sildeUp('sm3');sildeUp('sm5');" onmouseover="sildeDown('sm4');" onmouseout="sildeUp('sm4');"><img src="/images/menu4.png" alt="홍보센터" /></a>
				<div class="layer0 pos4" id="sm4" onmouseover="sildeDown('sm4');" onmouseout="sildeUp('sm4');">
					<ul>
						<li style="margin-left:20px;"><a class="smenu1" href="/common/board/list.html?a_gb=board&a_cd=1&a_item=0&sm=4_1">피치텍뉴스</a></li>
						<li><a class="smenu2" href="/common/board/list.html?a_gb=board&a_cd=2&a_item=0&sm=4_2">언론보도</a></li>
						<li><a class="smenu3" href="/common/board/list.html?a_gb=board&a_cd=3&a_item=0&sm=4_3">건강상식</a></li>
					</ul>
				</div>			
			</li>

			<li class="menus"><a class="menus-title" href="/common/board/list.html?a_gb=board&a_cd=7&a_item=0&sm=5_1" onfocus="sildeDown('sm5');sildeUp('sm4');sildeUp('sm6');" onmouseover="sildeDown('sm5');" onmouseout="sildeUp('sm5');"><img src="/images/menu5.png" alt="고객지원" /></a>
				<div class="layer0 pos5" id="sm5" onmouseover="sildeDown('sm5');" onmouseout="sildeUp('sm5');">
					<ul>
						<li style="margin-left:20px;"><a class="smenu2" href="/common/board/list.html?a_gb=board&a_cd=7&a_item=0&sm=5_1">FAQ</a></li>
						<li><a class="smenu1" href="/common/board/list.html?a_gb=board&a_cd=6&a_item=0&sm=5_2">사용설명서</a></li>
						<li><a class="smenu3" href="/common/board/postform.html?a_gb=board&a_cd=8&a_item=0&sm=5_3">1:1 고객문의</a></li>
					</ul>
				</div>			
			</li>

			<li class="menus"><a class="menus-title" href="/shopping/shop/list.html?a_gb=shop&a_cd=5&a_item=0&po_it_no=i101&po_no=1&po_it_lclass=i10&sm=6_1" onfocus="sildeDown('sm6');sildeUp('sm5');sildeUp('sm7');" onmouseover="sildeDown('sm6');" onmouseout="sildeUp('sm6');"><img src="/images/menu6.png" alt="제품구매" /></a>
				<div class="layer0 pos6" id="sm6" onmouseover="sildeDown('sm6');" onmouseout="sildeUp('sm6');">
					<ul>
						<li style="margin-left:20px;"><a class="smenu1" href="/shopping/shop/list.html?a_gb=shop&a_cd=5&a_item=0&po_it_no=i101&po_no=1&po_it_lclass=i10&sm=6_1">제품구매</a></li>
					</ul>
				</div>			
			</li>


		</ul>
		
	</div>
<!-- gnb end      -->