<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	if($_SESSION['ACCOUNT_ID']) {
/*
		require_once $getDbConnectionClassPath;
		$con=GetDbConnection::getConnection($configDb);

		require_once $setContentLogoutClassPath;
		$setAccountLogoutLog=new SetAccountLogoutLog($con);
		$setAccountLogoutLog->insert(new SetAccountLogoutLogRequestType());

		$con=null; */

		session_destroy();
	}

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con=null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>