<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	if(isset($_SESSION['USER_ID'])) {
		unset($_SESSION['USER_ID']);
		unset($_SESSION['USER_NAME']);
	}
	
	if(isset($_SESSION['ADMIN']))
		unset($_SESSION['ADMIN']);
		
	session_destroy();
	
	if ($clean['return_url']) {
		$sl_redirect=$clean['return_url'];
	} else {
		$sl_redirect='index.php';
	}	

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con=null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>