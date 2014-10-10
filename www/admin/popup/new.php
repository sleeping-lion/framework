<?php

try {
	require_once 'setting.php';

	$template['script']='admin'.DIRECTORY_SEPARATOR.'board'.DIRECTORY_SEPARATOR.'newScript.html';
	
	require_once $foramtSuccessData;
} catch(Exception $e) {
	require_once $foramtErrorData;
}

?>