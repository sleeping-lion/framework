<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	$con=getPDO($db_config);

	// 본문 가져오기 
	$getContent=new GetFaq($con);
	$content=$getContent->getContent(new GetFaqRequestType(array('id'=>$_GET['id'])));

	// 조회로그 기록  조회
	$getContentLog=new GetFaqLog($con);
	$count=$getContentLog->getCount(new GetFaqLogRequestType(array('parent_id'=>$content['id'])));

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	// 조회 로그 기록
	$setContentLog=new SetFaqLog($con);
	$insertId=$setContentLog->insert(new SetFaqLogRequestType(array('parent_id'=>$content['id'])));

	if(!$count) {
		//  조회수 업데이트
		$setContent=new SetFaq($con);
		$setContent->updateCountPlus(new SetFaqRequestType(array('id'=>$content['id'])));
	}

	/******** 커밋 **********/
	$con->commit();
	$con=null;

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'success.php';
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