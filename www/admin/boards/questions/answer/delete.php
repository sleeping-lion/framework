<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	require_once $setContentAnswerClassPath;
	$setAnswerRequestType=new SetAnswerRequestType(array('id'=>$_POST['id']));
	$setAnswer->delete($setAnswerRequestType);

	/******** 커밋 **********/
	$con->commit();
	$con=null;

	$template='../show.php?id='.$setAnswerRequestType->parentId;
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