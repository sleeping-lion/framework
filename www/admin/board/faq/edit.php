<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;	
	$con=GetDbConnection::getConnection($configDb);

	require_once $getContentClassPath;
	$getFaq=new GetFaq($con);
	$data['content']=$getFaq->getContent(new GetFaqRequestType(array('id'=>$_GET['id'])));

	$con=null;

	$template='index.php';
	require_once $foramtSuccessData;
} catch(Exception $e) {
	$con=null;

	require_once $foramtErrorData;
}

?>