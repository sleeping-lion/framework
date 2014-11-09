<?php

try {
	require_once __DIR__ . DIRECTORY_SEPARATOR . 'setting.php';

	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);
	
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'common_select.php';		

	// 공지사항 가져오기
	require_once BOARD_DIRECTORY.DIRECTORY_SEPARATOR.'notices'.DIRECTORY_SEPARATOR.'_index.php';

	// 질문 답변 가져오기
	require_once BOARD_DIRECTORY.DIRECTORY_SEPARATOR.'questions'.DIRECTORY_SEPARATOR.'_index.php';

	//  갤러리 가져오기 
	require_once BOARD_DIRECTORY.DIRECTORY_SEPARATOR.'galleries'.DIRECTORY_SEPARATOR.'_index.php';	
	

	require_once BOARD_DIRECTORY.DIRECTORY_SEPARATOR.'blogs'.DIRECTORY_SEPARATOR.'_index_photo.php';	

	// 커넥터(PDO)  해제
	$con = null;
	
	$config['controller']='home';

 	require_once WEBROOT_DIRECTORY.DIRECTORY_SEPARATOR.'phpThumb'.DIRECTORY_SEPARATOR.'phpThumb.config.php';
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con = null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}
?>