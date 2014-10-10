<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	$con=GetDbConnection::getConnection($configDb);

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	$setCotnent=new SetBlogCategory($con);
	$setCotnent->update(new SetBlogCategoryRequestType($_POST));
	
	/******** 커밋 **********/
	$con->commit();
	$con=null;

	$formatData=new FormatSuccessData($config);
	$formatData->echoFormatData('index.php',$data);
} catch(Exception $e) {
	if($con) {
		if($con->inTransaction())
		/******** 롤백 **********/			
		$con->rollback();
		$con=null;
	}

	$formatData=new FormatErrorData($config);
	$formatData->echoFormatData($template,$e);
}

?>