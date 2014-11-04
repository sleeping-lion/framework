<?php

try {
	require_once 'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);
	
	$getContentCategory=new GetAccountCategory($con);
	$data['category']=$getContentCategory->getList(new GetAccountCategoryRequestType());

	$con=null;

	require_once $foramtSuccessData;
} catch(Exception $e) {
	$con=null;

	require_once $foramtErrorData;
}

?>