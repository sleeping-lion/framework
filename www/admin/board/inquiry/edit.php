<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	require_once $getContentClassPath;
	$getContent=new GetContact($con);
	$data['content']=$getContent->getContent(new GetContactRequestType(array('id'=>$_GET['id'])));
	$data['content']['phone']=explode('-',$data['content']['phone']);
	$data['content']['cell_phone']=explode('-',$data['content']['cell_phone']);
	
	$con=null;

	require_once $formatSuccessDataClassPath;
	$formatData=new FormatSuccessData($config);
	$formatData->echoFormatData($template,$data);
} catch(Exception $e) {
	$con=null;

	require_once $formatErrorDataClassPath;
	$formatData=new FormatErrorData($config);
	$formatData->echoFormatData($template,$e);
}

?>