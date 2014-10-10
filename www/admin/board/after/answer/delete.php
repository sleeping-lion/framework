<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);
	
	$setAnswerRequestType=new SetAnswerRequestType(array('id'=>$_POST['id']));
	$setAnswer->delete($setAnswerRequestType);
	
	/******** 커밋 **********/
	$con->commit();
	$con=null;
	
	require_once $formatSuccessDataClassPath;	
	$formatData=new FormatSuccessData($config);
	$formatData->echoFormatData('../show.php?id='.$setAnswerRequestType->parentId,$data);
} catch(Exception $e) {
	if($con) {
		if($con->inTransaction())
		/******** 롤백 **********/			
		$con->rollback();
		$con=null;
	}
	
	require_once $formatErrorDataClassPath;	
	$formatData=new FormatErrorData($config);
	$formatData->echoFormatData($template,$e);
}

?>