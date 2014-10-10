<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	// 본문 가져오기 
	require_once $getContentClassPath;
	$getContent=new GetQuestion($con);
	$data['content']=$getContent->getContent(new GetQuestionRequestType($_REQUEST));
	
	require_once $contentQuestionAnswerClassPath.DIRECTORY_SEPARATOR.'GetQuestionAnswer.php';
	$getAnswer=new GetQuestionAnswer($con);
	$data['answerList']=$getAnswer->getList(new GetQuestionAnswerRequestType(array('parent_id'=>$data['content']['id'])));

	$con=null;
	
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