<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	$template['header']='account'.DIRECTORY_SEPARATOR.'test_header.html';

	require_once USER_HTML_DIRECTORY . DIRECTORY_SEPARATOR . 'notices' . DIRECTORY_SEPARATOR . 'index.php';
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>