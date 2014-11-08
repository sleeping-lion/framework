<header>	
	<nav class="container">
  <h1><a href="/">잠자는사자의 집</a></h1>
		<ul class="nav nav-pills">
			<li><a href="/boards/histories"><?php echo _('histroy') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<li><a href="/boards/contacts/new.php"><?php echo _('contact') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<li><a href="/boards/blogs"><?php echo _('blog') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<li><a href="/boards/galleries"><?php echo _('gallery') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<li><a href="/boards/questions"><?php echo _('question') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<li><a href="/boards/faqs"><?php echo _('faq') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<li><a href="/boards/notices"><?php echo _('notice') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<li><a href="/boards/guest_books"><?php echo _('guest_book') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<li><a href="/users/agree.php"><?php echo _('user') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<?php if($_SESSION['USER_ID']): ?>			
			<li><a href="/users/login/logout.php"><?php echo _('logout') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<?php else: ?>
			<li><a href="/users/login/index.php"><?php echo _('login') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<?php endif ?>															
		</ul>
	</nav>
</header>
