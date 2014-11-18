<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);
	
	$getFaqCategory=new GetFaqCategory($con);
	$data['list']=$getFaqCategory->getList(new GetFaqCategoryRequestType($_GET));
	
	$con=null;
	
	require_once $foramtSuccessData;
} catch(Exception $e) {
	$con=null;

	require_once $foramtErrorData;
}

?>