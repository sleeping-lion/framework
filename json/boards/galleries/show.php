<?php
	require WEBROOT_DIRECTORY . DIRECTORY_SEPARATOR . 'phpThumb' . DIRECTORY_SEPARATOR . 'phpThumb.config.php';
	$data['content']['large_thumb']=phpThumbURL('src=/../uploads/gallery/'.$data['content']['id'].'/'.$data['content']['photo'].'&w=400&h=300', '/phpThumb/phpThumb.php');
	$data['content']['photo']	=phpThumbURL('src=/../uploads/gallery/'.$data['content']['id'].'/'.$data['content']['photo'], '/phpThumb/phpThumb.php');
	echo json_encode($data);