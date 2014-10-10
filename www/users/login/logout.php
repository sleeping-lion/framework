<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	if($_SESSION['USER_ID']) {
		

		session_destroy();
	}

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con=null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>