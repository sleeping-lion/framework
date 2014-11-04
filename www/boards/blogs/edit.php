<?php

try {
	require_once __DIR__ . DIRECTORY_SEPARATOR . 'setting.php';

	$con=null;
	require_once HTML_DIRECTORY . DIRECTORY_SEPARATOR .'main.php';
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con=null;
	
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>