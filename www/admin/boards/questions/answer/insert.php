<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	require_once $setContentQuestionAnswerClassPath;
	$setQuestionAnswer=new SetQuestionAnswer($con);
	$setQuestionAnswerRequestType=new SetQuestionAnswerRequestType($_POST);
	$insertedId=$setQuestionAnswer->insert($setQuestionAnswerRequestType);

	require_once $setContentClassPath;
	$setContent=new SetQuestion($con);
	$setContent->updateAnswerPlus(new SetQuestionRequestType(array('id'=>$setQuestionAnswerRequestType->parentId)));

	/******** 커밋 **********/
	$con->commit();
	$con=null;

	$template='../show.php?id='.$setQuestionAnswerRequestType->parentId;
	require_once $foramtSuccessData;
} catch(Exception $e) {
	if($con) {
		if($con->inTransaction())
		/******** 롤백 **********/			
		$con->rollback();
		$con=null;
	}

	require_once $foramtErrorData;
}

?>