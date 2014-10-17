<!DOCTYPE html>
<html>
<head>
	<title>SL BOARD</title>
	<meta charset="utf-8">
	<link type="text/css" rel="stylesheet" href="/stylesheets/index.css" />
	<link type="text/css" rel="stylesheet" href="/stylesheets/bootstrap.min.css" />	
	<?php sl_style($sl_style); ?>
	<meta content="width=device-width, initial-scale=1.0" name="viewport" />
	<meta name="author" content="Sleeping-Lion" />
	<!--[if IE]>
  <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" />
  <![endif]-->	
</head>
<body id="sl_main_page">
	<?php require_once $config['template']['header'] ?>
	<div id="mon">
		<div id="main" class="container">
			<div class="page-header">
				<h1 itemtype="http://schema.org/WebPageElement" itemscope="" itemprop="mainContentOfPage"><span itemprop="headline">사진첩</span></h1>
					<ol class="breadcrumb">
						<li itemtype="http://data-vocabulary.org/Breadcrumb" itemscope="itemscope"><a itemprop="url" href="/"><span itemprop="title">홈</span></a></li>
						<li itemtype="http://data-vocabulary.org/Breadcrumb" itemscope="itemscope" class="active"><span itemprop="title">사진첩</span></li>						
					</ol>
			</div>
		<?php require_once $config['template']['main'] ?>
		</div>		
	</div>
	<?php require_once $config['template']['footer'] ?>
	<script type="text/javascript" src="/javascripts/jquery-2.1.1.min.js"></script>
	<script type="text/javascript" src="/javascripts/bootstrap.min.js" ></script>
	<?php sl_js($sl_js); ?>		
</body>
</html>
