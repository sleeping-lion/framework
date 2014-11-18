<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);
	
	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();
	
	$setFaqCategory=new SetFaqCategory($con);
	$data['inserted_id']=$setFaqCategory->insert(new SetFaqCategoryRequestType($_POST));
	
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