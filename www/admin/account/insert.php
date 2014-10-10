<?php

try {
	require_once 'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	require_once $getContentClassPath;
	$getContent=new GetAccount($con);
	$getContent->checkExistUserId(new GetAccountRequestType(array('user_id'=>$_POST['user_id'])));
	$getContent->checkExistEmail(new GetAccountRequestType(array('email'=>$_POST['email'])));

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	//삽입
	require_once $setContentClassPath;	
	$setContent=new SetAccount($con);
	$data['inserted_id']=$setContent->insert(new SetAccountRequestType($_POST));

	$setContentAddress=new SetAccountAddress($con);
	$setContentAddress->insert(new SetAccountAddressRequestType($data['inserted_id'],$_POST));

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