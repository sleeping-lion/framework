<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	$file_dir = '.';
	$downfile = $_GET['filename'];

	if($_GET['sourcename']) {
		$source_name = $_GET['sourcename'];
	} else {
		$source_name = $_GET['filename'] . '.jpg';
	}

	if($_GET['thumb']) {
		switch($_GET['thumb']) {
			case '1' :
				$file = $uploadPath.'/gallery_photo/'.$_GET['id'].'/thumbnail_50x50/'. $downfile;
				break;
			case '2' :
				$file = $uploadPath.'/gallery_photo/'.$_GET['id'].'/thumbnail_100x100/' . $downfile;
				break;
			case '3' :
				$file = $uploadPath.'/gallery_photo/'.$_GET['id'].'/thumbnail_370x430/' . $downfile;
				break;
		}
	} else {
		$file = $uploadPath.'/gallery_photo/'.$_GET['id'].'/thumbnail_370x430/' . $downfile;
	}

	$filename = $downfile;

	if(file_exists($file)) {
		if(strstr($HTTP_USER_AGENT, "MSIE 5.5")) {
			header('Content-Type: doesn/matter');
			header("Content-length: " . filesize("$file"));
			header('Content-Disposition: attachment; filename="'.$source_name).'"';
			header('Content-Transfer-Encoding: binary');
			header('Pragma: no-cache');
			header('Expires: 0');
		} else {
			Header('Content-type: file/image');
			header("Content-length: " . filesize("$file"));
			Header('Content-Disposition: attachment; filename="'.$source_name).'"';
			Header('Content-Description: PHP Generated Data');
			header('Pragma: no-cache');
			header('Expires: 0');
		}
		if(is_file("$file")) {
			$fp = fopen("$file", "rb");
			if(!fpassthru($fp)) {
				fclose($fp);
			}
		}
	} else {
		throw new Exception('첨부파일이 존재하지 않습니다.' . $file);
	}

} catch(Exception $e) {
	require_once $foramtErrorData;
}

?>