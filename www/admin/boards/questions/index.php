<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	// 목록 가져오기 
	require_once $getContentClassPath;
	$getContent=new GetQuestion($con);
	$data['list']=$getContent->getList(new GetQuestionRequestType($_GET));

	$con=null;

	require_once $foramtSuccessData;
} catch(Exception $e) {
	$con=null;

	require_once $foramtErrorData;
}

?>