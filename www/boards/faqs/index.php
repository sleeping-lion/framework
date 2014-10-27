<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	// 커넥터(PDO) 가져오기
	$con=get_PDO($db_config);
	

	$con=null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con=null;

	require_once $foramtErrorData;
}

?>