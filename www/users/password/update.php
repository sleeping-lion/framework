<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $classPath.DIRECTORY_SEPARATOR.'GetDbConnection.php';
	$con=GetDbConnection::getConnection($configDb);

	require_once $getContentClassPath;
	$getContent=new GetAccount($con);
	$content=$getContent->getContent(new GetAccountRequestType(array('id'=>$_SESSION['ACCOUNT_ID'])));

	$getContentRequestType=new GetAccountRequestType(array('id'=>$content['id'],'password'=>$_POST['old_password'],'word'=>$content['word']));
	$getContent->checkPassword($getContentRequestType);

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	require_once $setContentClassPath;
	$setContent=new SetAccount($con);
	$setContent->updatePassword(new SetAccountRequestType(array('id'=>$content['id'],'password'=>$_POST['new_password'])));

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

	require_once INCLUDE_DIRECTORY . DIRECTORY_SEPARATOR . 'error.php';
}

?>
