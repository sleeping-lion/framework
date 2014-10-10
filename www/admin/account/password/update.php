<?php

try {
	require_once 'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	require_once $getContentClassPath;
	$getAccount=new GetAccount($con);
	$content=$getAccount->getContent(new GetAccountRequestType(array('id'=>$_SESSION['ACCOUNT_ID'])));

	$getAccountRequestType=new GetAccountRequestType(array('id'=>$content['id'],'password'=>$_POST['old_password'],'word'=>$content['word']));
	$getAccount->checkPassword($getAccountRequestType);

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	require_once $setContentClassPath;
	$setAccount=new SetAccount($con);
	$setAccount->updatePassword(new SetAccountRequestType(array('id'=>$content['id'],'password'=>$_POST['new_password'])));

	/******** 커밋 **********/
	$con->commit();
	$con=null;

	$template='complete.php';
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
