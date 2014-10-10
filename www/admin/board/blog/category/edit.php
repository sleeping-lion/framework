<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	$con=GetDbConnection::getConnection($configDb);
	
	$getCategory=new GetBlogCategory($con);
	$data['content']=$getCategory->getContent(new GetBlogCategoryRequestType(array('id'=>$_GET['id'])));	
	
	$con=null;

	$formatData=new FormatSuccessData($config);
	$formatData->echoFormatData($template,$data);
} catch(Exception $e) {
	$con=null;

	$formatData=new FormatErrorData($config);
	$formatData->echoFormatData($template,$e);
}

?>