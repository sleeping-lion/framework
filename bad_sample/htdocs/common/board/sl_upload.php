<?php
	# 패스 및 클래스
	include $_SERVER[DOCUMENT_ROOT]."/Root_Path.inc";
	
	$file_name = $_FILES['upload_file']['name'];
	$tmp_file = $_FILES['upload_file']['tmp_name'];

	$file_path = $cf_doc_root/.'files/editor'.$file_name;
	$image_url = $url['root'].'files/editor' . $file_name;

	$r = move_uploaded_file($tmp_file, $file_path);

?> 