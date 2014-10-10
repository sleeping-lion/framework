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

	$template='/admin/index.php';
	require_once $foramtSuccessData;
} catch(Exception $e) {
	require_once $foramtErrorData;
}

?>