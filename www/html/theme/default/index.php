<section id="main" class="container">
	<div class="jumbotron hero-unit">
		<h1>최신의 PHP게시판 시스템 SLBoard</h1>
		<p class="lead">PHP 5.3.0버전 부터 사용가능합니다.</p>
		<a class="modal_link btn btn-large btn-success" data-target="#myModal" data-toggle="modal" href="/home/popup">깨끗한 웹을 꿈꾸고 있습니다</a>
	</div>
	<hr class="none">
	<section class="sub_main">
		<section id="main_main">
			<section class="row">
				<?php require_once BOARD_HTML_DIRECTORY.DIRECTORY_SEPARATOR.'notices'.DIRECTORY_SEPARATOR.'_index.php' ?>
				<?php require_once BOARD_HTML_DIRECTORY.DIRECTORY_SEPARATOR.'questions'.DIRECTORY_SEPARATOR.'_index.php' ?>
			</section>
			<section class="row">
				<?php require_once BOARD_HTML_DIRECTORY.DIRECTORY_SEPARATOR.'galleries'.DIRECTORY_SEPARATOR.'_index.php' ?>
				<?php require_once BOARD_HTML_DIRECTORY.DIRECTORY_SEPARATOR.'blogs'.DIRECTORY_SEPARATOR.'_index.php' ?>
			</section>
		</section>
	</section>
</section>	