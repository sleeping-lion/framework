<?php

try {
	require_once __DIR__.DIRECTORY_SEPARATOR.'setting.php';

	require_once $loginUserOnly;

	$con=getPDO($config_db);
	

	$con=null;

	require_once USER_HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'notices' . DIRECTORY_SEPARATOR . 'index.php';
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con=null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>