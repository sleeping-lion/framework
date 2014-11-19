<?php
	require WEBROOT_DIRECTORY . DIRECTORY_SEPARATOR . 'phpThumb' . DIRECTORY_SEPARATOR . 'phpThumb.config.php';
	$data['photo']	=htmlspecialchars(phpThumbURL('src=/../uploads/gallery/'.$data['content']['id'].'/'.$data['content']['photo'], '/phpThumb/phpThumb.php'));
	$data['photo']['large_thumb']=htmlspecialchars(phpThumbURL('src=/../uploads/gallery/'.$data['content']['id'].'/'.$data['content']['photo'].'&w=400&h=300', '/phpThumb/phpThumb.php'));
	echo json_encode($data);