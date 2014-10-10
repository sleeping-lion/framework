<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $adminOnly;

	$con=getPDO($db_config);

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	// 삭제
	require_once $contentClassPath.DIRECTORY_SEPARATOR.'SetFaq.php';
	$setContent=new SetFaq($con);
	$setContent->delete(new SetFaqRequestType(array('id'=>$_POST['id'])));

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