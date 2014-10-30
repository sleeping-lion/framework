<header>
	<h1><a href="/">Framework Test</a></h1>
	<nav>
		<ul>
			<li><a href="/boards/histories"><?php echo _('histroy') ?></a></li>			
			<li><a href="/boards/contacts/new.php"><?php echo _('contact') ?></a></li>
			<li><a href="/blogs"><?php echo _('blog') ?></a></li>
			<li><a href="/boards/galleries"><?php echo _('gallery') ?></a></li>
			<li><a href="/boards/questions"><?php echo _('question') ?></a></li>
			<li><a href="/boards/faqs"><?php echo _('faq') ?></a></li>			
			<li><a href="/boards/notices"><?php echo _('notice') ?></a></li>
			<li><a href="/boards/guest_books"><?php echo _('guest_book') ?></a></li>
			<li><a href="/users/agree.php"><?php echo _('user') ?></a></li>
			<?php if($_SESSION['USER_ID']): ?>
			<li><a href="/users/login/logout.php"><?php echo _('logout') ?></a></li>
			<?php else: ?>
			<li><a href="/users/login/index.php"><?php echo _('login') ?></a></li>
			<?php endif ?>
		</ul>
	</nav>
</header>
