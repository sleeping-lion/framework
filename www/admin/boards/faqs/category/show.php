<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);
	
	$getFaqCategory=new GetFaqCategory($con);
	$content=$getFaqCategory->getContent(new FaqCategoryRequestType(array('id'=>$_GET['id'])));
	
	$con=null;
	
	require_once $foramtSuccessData;
} catch(Exception $e) {
	$con=null;

	require_once $foramtErrorData;
}

?>