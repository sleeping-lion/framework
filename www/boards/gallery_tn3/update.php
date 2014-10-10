<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	if(empty($_SESSION['ADMIN']))
	Header('Location:'.$slboard_login_url);

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	// 트랙잭션 시작	
	$con->beginTransaction();

	require_once $setContentClassPath;
	$setNotice=new SetNotice($con);
	$insertedId=$setNotice->update(new SetNoticeRequestType($_POST));

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