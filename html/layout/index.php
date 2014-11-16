<!DOCTYPE html>
<html lang="<?php echo $config['site']['language'] ?>">
	<head>
		<title><?php echo $config['site']['title'] ?></title>
		<meta charset="utf-8">
		<?php sl_style($config['template']['stylesheets']); ?>
		<meta content="<?php echo $config['site']['description'] ?>" name="description" />
		<meta content="<?php echo $config['site']['keywords'] ?>" name="keywords" />
		<meta content="width=device-width, initial-scale=1.0" name="viewport" />		
		<meta name="author" content="<?php echo $config['site']['author'] ?>" />
		<!--[if IE]>
		<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" />
		<![endif]-->
	</head>
	<body id="sl_main_page">
		<?php require_once $config['template']['header'] ?>
		<div id="mom">
			<div id="main" class="container">
				<?php require_once INCLUDE_DIRECTORY.DIRECTORY_SEPARATOR.'breadcrumbs.php' ?>
<?php if(!strcmp($config['controller'],'home')): ?>
	<div class="jumbotron hero-unit">
		<h1>최신의 PHP 게시판 시스템 SLBoard</h1>
		<p class="lead">PHP 5.3.0버전 부터 사용가능합니다.</p>
		<a class="modal_link btn btn-large btn-success" data-target="#myModal" data-toggle="modal" href="/popup.php">깨끗한 웹을 꿈꾸고 있습니다</a>
	</div>
<?php endif ?>
				<section class="sub_main">
				<?php require_once INCLUDE_DIRECTORY.DIRECTORY_SEPARATOR.'ad.php' ?>	
				<?php require_once INCLUDE_DIRECTORY.DIRECTORY_SEPARATOR.'message.php' ?>
				<?php require_once $config['template']['main'] ?>
				</section>
				<?php echo $config['template']['aside'] ?>
			</div>
		</div>
<div class="slboard_overlay" id="overlay"></div>
<div class="modal fade" id="myModal" tabindex="-1" role="dialog"></div>		
		<?php require_once $config['template']['footer'] ?>
		<?php sl_script($config['template']['javascripts']); ?>
	</body>
</html>
