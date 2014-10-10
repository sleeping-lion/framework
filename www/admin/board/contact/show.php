<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	require_once $getContentClassPath;
	$getContent=new GetContact($con);
	$data['content']=$getContent->getContent(new GetContactRequestType(array('id'=>$_GET['id'])));

	$con=null;

	require_once $foramtSuccessData;
} catch(Exception $e) {
	$con=null;

	require_once $foramtErrorData;
}

?>