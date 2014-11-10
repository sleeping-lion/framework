<header>	
	<nav class="container">
  <h1><a href="/">잠자는사자의 집</a></h1>
  <ul id="top_menu">
			<?php if($_SESSION['USER_ID']): ?>			
			<li><a href="/users/login/logout.php"><?php echo _('logout') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<?php else: ?>
			<li><a href="/users/agree.php"><?php echo _('user') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>							
			<li><a href="/users/login/index.php"><?php echo _('login') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<?php endif ?>
  </ul>
		<ul class="nav nav-pills">
			<li <?php if(!strcmp($config['controller'],'intro')): ?><?php echo 'class="active"' ?><?php endif ?>><a href="/intro"><?php echo _('intro') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<li <?php if(!strcmp($config['controller'],'contact')): ?><?php echo 'class="active"' ?><?php endif ?>><a href="/boards/contacts/new.php"><?php echo _('contact') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<li <?php if(!strcmp($config['controller'],'blog')): ?><?php echo 'class="active"' ?><?php endif ?>><a href="/boards/blogs"><?php echo _('blog') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>			
			<li <?php if(!strcmp($config['controller'],'gallery')): ?><?php echo 'class="active"' ?><?php endif ?>><a href="/boards/galleries"><?php echo _('gallery') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<li <?php if(!strcmp($config['controller'],'question')): ?><?php echo 'class="active"' ?><?php endif ?>><a href="/boards/questions"><?php echo _('question') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<li <?php if(!strcmp($config['controller'],'faq')): ?><?php echo 'class="active"' ?><?php endif ?>><a href="/boards/faqs"><?php echo _('faq') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<li <?php if(!strcmp($config['controller'],'notice')): ?><?php echo 'class="active"' ?><?php endif ?>><a href="/boards/notices"><?php echo _('notice') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
			<li <?php if(!strcmp($config['controller'],'guest_book')): ?><?php echo 'class="active"' ?><?php endif ?>><a href="/boards/guest_books"><?php echo _('guest_book') ?><span class="visible-xs glyphicon glyphicon-chevron-right pull-right"></span></a></li>
		</ul>
	</nav>
</header>
