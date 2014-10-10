<?php

try {
	require_once 'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	require_once $getContentClassPath;
	$getContent=new GetAccount($con);
	$data['content']=$getContent->getContent(new GetAccountRequestType(array('id'=>$_GET['id'])));
	
	$con=null;
	
	require_once $foramtSuccessData;
} catch(Exception $e) {
	$con=null;

	require_once $foramtErrorData;
}

?>