<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	require_once $getContentClassPath;
	$getContent=new GetAfter($con);
	$data['content']=$getContent->getContent(new GetAfterRequestType(array('id'=>$_GET['id'])));
	
	require_once $getContentAnswerClassPath;
	$getAnswer=new GetAnswer($con);
	$data['answerList']=$getAnswer->getList(new GetAnswerRequestType(array('parent_id'=>$data['content']['id'])));

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