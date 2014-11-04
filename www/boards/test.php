<?php

try {
	require_once __DIR__.DIRECTORY_SEPARATOR.'setting.php';

	$template['header']='board'.DIRECTORY_SEPARATOR.'test_header.html';

	require_once $foramtSuccessData;
} catch(Exception $e) {
	require_once $foramtErrorData;
}

?>