<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	require_once $getContentClassPath;
	$getContent=new GetEvent($con);
	$data['content']=$getContent->getContent(new GetEventRequestType(array('id'=>$_GET['id'])));

	$con=null;
	
	$template['script']='admin/board/editScript.html';	

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