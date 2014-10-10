<?php

try {
	require_once dirname(__FILE__).'/setting.php';

	require_once $configPath.'/getDbConnection.php';
	$con=GetDbConnection::getConnection();

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	require_once $classPath.'/board/postscript/setPostscript.php';
	$setPostscript=new SetPostscript($con);
	$insertedId=$setPostscript->insert(new SetPostscriptRequestType($_POST));

	/******** 커밋 **********/
	$con->commit();
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