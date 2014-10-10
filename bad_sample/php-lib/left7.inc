<div id="snbwrap">
	<h3><img src="/images/left7.jpg" alt="회원" /></h3>
	<ul id="snb">
		<?php if(!$cf_cook_id){?>
		<li class="menus"><a href="/member/login/login.html?a_gb=member&a_cd=3&a_item=0&sm=7_1" class="menus-title" id="lm1">로그인</a></li>
		<li class="menus"><a href="/member/register/register.html?a_gb=member&a_cd=1&a_item=0&sm=7_2" class="menus-title" id="lm2">회원가입</a></li>
		<li class="menus"><a href="/member/login/find_id.html?sm=7_3" class="menus-title" id="lm3">아이디/비밀번호찾기</a></li>
		<li class="menus"><a href="/contents/raw.html?sm=7_4" class="menus-title" id="lm4">이용약관</a></li>
		<li class="menus"><a href="/contents/privacy.html?sm=7_5" class="menus-title" id="lm5">개인정보취급방침</a></li>
		<li class="menus"><a href="/contents/email.html?sm=7_6" class="menus-title" id="lm6"><span style="letter-spacing:-1px;">이메일 주소 무단수집거부</span></a></li>
		<?php } else {?>
		<li class="menus"><a href="/member/register/modifyform.html?a_gb=member&a_cd=2&a_item=0&sm=7_7" class="menus-title" id="lm7">회원정보수정</a></li>
		<li class="menus"><a href="/contents/raw.html?sm=7_4" class="menus-title" id="lm4">이용약관</a></li>
		<li class="menus"><a href="/contents/privacy.html?sm=7_5" class="menus-title" id="lm5">개인정보취급방침</a></li>
		<li class="menus"><a href="/contents/email.html?sm=7_6" class="menus-title" id="lm6"><span style="letter-spacing:-1px;">이메일 주소 무단수집거부</span></a></li>
		<?php } ?>  
	</ul>
</div>
<script type="text/javascript">snbMenu("snbwrap","<?=$tm_submenu_num?>");</script>





