<?php

try {
	require __DIR__ . DIRECTORY_SEPARATOR . 'setting.php';

	// 입력 필터
	$clean = filter_input_array(INPUT_GET, array('id' => FILTER_VALIDATE_INT));
	
	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);
	

	$con = null;
	
	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con = null;

	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}
?>