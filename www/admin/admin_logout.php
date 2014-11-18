<?php

try {
	require_once 'setting.php';
/*
	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	$setAccountLogoutLog=new SetAccountLogoutLog($con);
	$setAccountLogoutLog->insert(new SetAccountLogoutLogRequestType());

	$con=null;
*/
	session_destroy();

	$con = null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con = null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>