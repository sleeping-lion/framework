<!DOCTYPE html>
<html lang="<?php echo $config['site']['language'] ?>">
	<head>
		<title><?php echo $config['site']['title'] ?></title>
		<meta charset="utf-8">
		<?php if($config['use_boostrap']): ?>
		<link type="text/css" rel="stylesheet" href="/stylesheets/bootstrap.min.css" />
		<?php endif ?>
		<link type="text/css" rel="stylesheet" href="/stylesheets/index.css" />		
		<?php sl_style($config['template']['theme_style']); ?>
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
		<a class="modal_link btn btn-large btn-success" data-target="#myModal" data-toggle="modal" href="/home/popup">깨끗한 웹을 꿈꾸고 있습니다</a>
	</div>
<?php endif ?>				
				<section class="sub_main">
				<?php require_once INCLUDE_DIRECTORY.DIRECTORY_SEPARATOR.'message.php' ?>
				<?php require_once $config['template']['main'] ?>
				</section>
				<?php require_once $config['template']['aside'] ?>
			</div>
		</div>
		<?php require_once $config['template']['footer'] ?>
		<?php if($config['use_boostrap'] OR $config['use_jquery']):
		?>
		<script type="text/javascript" src="/javascripts/jquery-2.1.1.min.js"></script>
		<?php endif ?>
		<?php if($config['use_boostrap']): ?>
		<script type="text/javascript" src="/javascripts/bootstrap.min.js" ></script>
		<?php endif ?>
		<?php sl_js($config['template']['theme_script']); ?>
	</body>
</html>