<?php

try {
	require 'setting.php';
	/*
	 require_once $getDbConnectionClassPath;
	 $con=GetDbConnection::getConnection($configDb);

	 $con=null;
	 */

	if (empty($_SESSION['ACCOUNT_ID'])) {
		$data['token']=md5(uniqid(rand(), true));
		$_SESSION['LOGIN_TOKEN']=$data['token'];
	}

	if (empty($_SESSION['ADMIN'])) {
		$config['template']['layout']='admin/login.php';
		$config['template']['main']='login.php';
	}

	$con = null;

	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
} catch(Exception $e) {
	$con = null;

	require INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>