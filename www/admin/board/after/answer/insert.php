<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	require_once $setContentAnswerClassPath;
	$setAnswer=new SetAnswer($con);
	$setAnswerRequestType=new SetAnswerRequestType($_POST);
	$insertedId=$setAnswer->insert($setAnswerRequestType);

	require_once $setContentClassPath;
	$setQuestion=new SetAfter($con);
	$setQuestion->updateAnswerPlus(new SetAfterRequestType(array('id'=>$setAnswerRequestType->parentId)));

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