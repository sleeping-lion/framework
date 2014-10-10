<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	// 트랙잭션 시작
	$con->beginTransaction();

	require_once $classPath.'/board/notice/setNotice.php';
	$setNotice=new SetNotice($con);
	$setNotice->delete(new SetNoticeRequestType(array('id'=>$_POST['id'])));

	/******** 커밋 **********/
	$con->commit();
	$con=null;

	$template='index.php';
	require_once $foramtSuccessData;
} catch(Exception $e) {
	if($con->inTransaction())
	$con->rollback();
	$con=null;

	require_once $foramtErrorData;
}

?>