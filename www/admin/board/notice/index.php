<?php

try {
	require_once 'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	// 목록 가져오기 
	require_once $getContentClassPath;
	$getContent=new GetNotice($con);
	$data['list']=$getContent->getList(new GetNoticeRequestType($_GET));

	$con=null;

	require_once $foramtSuccessData;
} catch(Exception $e) {
	$con=null;

	require_once $foramtErrorData;
}

?>