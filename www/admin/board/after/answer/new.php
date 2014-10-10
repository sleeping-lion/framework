<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	// 본문 가져오기 
	require_once $getContentClassPath;
	$getContent=new GetAfter($con);
	$data['content']=$getContent->getContent(new GetAfterRequestType(array('id'=>$_GET['question_id'])));	
	
	$con=null;
	
	require_once $formatSuccessDataClassPath;	
	$formatData=new FormatSuccessData($config);
	$formatData->echoFormatData($template,$data);
} catch(Exception $e) {
	$con=null;
	
	$formatData=new FormatErrorData($config);
	$formatData->echoFormatData($template,$e);
}

?>