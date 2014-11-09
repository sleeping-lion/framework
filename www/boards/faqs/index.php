<?php

try {
	require_once __DIR__ . DIRECTORY_SEPARATOR . 'setting.php';

	$clean = filter_input_array(INPUT_GET, array());

	if (empty($clean['order'])) {
		$clean['order'] = 'id';
		$clean['desc'] = true;
	}

	// 커넥터(PDO) 가져오기
	$con = get_PDO($config_db);
	
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'common_select.php';

	$con = null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con = null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
	;
}
?>