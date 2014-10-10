<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	$con=GetDbConnection::getConnection($configDb);

	$getContent=new GetBlogCategory($con);
	$data['list']=$getContent->getList(new GetBlogCategoryRequestType($_GET));

	$con=null;

	$formatData=new FormatSuccessData($config);
	$formatData->echoFormatData($template,$data);
} catch(Exception $e) {
	$con=null;

	$formatData=new FormatErrorData($config);
	$formatData->echoFormatData($template,$e);
}

?>