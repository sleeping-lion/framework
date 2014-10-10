<?php

try {
	require_once 'setting.php';
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
		$template['layout']='layout/admin/login.html';
		$template['main']='admin/login.html';
	}

	require_once $foramtSuccessData;
} catch(Exception $e) {
	require_once $foramtErrorData;
}

?>