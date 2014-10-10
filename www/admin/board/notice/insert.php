<?php

try {
	require_once 'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	// 삽입
	require_once $setContentClassPath;
	$setContent=new SetNotice($con);
	$data['inserted_id']=$setContent->insert(new SetNoticeRequestType($_POST));

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