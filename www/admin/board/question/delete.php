<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	// 본문 가져오기 
	require_once $getContentClassPath;
	$getQuestion=new GetQuestion($con);
	$content=$getQuestion->checkAnonPriv(new GetQuestionRequestType($_REQUEST));

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	// 삭제
	require_once $setContentClassPath;
	$setQuestion=new SetQuestion($con);
	$data['deleted']=$setQuestion->delete(new SetQuestionRequestType(array('id'=>$content['id'])));

	/******** 커밋 **********/
	$con->commit();
	$con=null;

	$template='index.php';
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