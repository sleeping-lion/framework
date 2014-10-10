<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);
	
	$getQuestion=new GetQuestion($con);
	$content=$getQuestion->checkAnonPriv(new GetQuestionRequestType($_POST));
	
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