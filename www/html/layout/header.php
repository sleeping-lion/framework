<header>
	<h1><a href="/">Framework Test</a></h1>
	<nav>
		<ul>
			<li><a href="/boards/histories">연혁</a></li>			
			<li><a href="/boards/contacts/new.php">문의</a></li>
			<li><a href="/blogs">블로그</a></li>
			<li><a href="/boards/galleries">갤러리</a></li>
			<li><a href="/boards/questions">질문,답변</a></li>
			<li><a href="/boards/notices">공지사항</a></li>
			<li><a href="/boards/guest_books">방명록</a></li>
			<li><a href="/users/agree.php">회원가입</a></li>
			<?php if($_SESSION['USER_ID']): ?>
			<li><a href="/users/login/logout.php">로그아웃</a></li>
			<?php else: ?>
			<li><a href="/users/login/index.php">로그인</a></li>
			<?php endif ?>
		</ul>
	</nav>
</header>
	
