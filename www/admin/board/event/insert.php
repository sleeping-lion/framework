<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	require_once $setContentClassPath;
	$setContent=new SetEvent($con);
	$data['inserted_id']=$setContent->insert(new SetEventRequestType($_POST));
debug($data);
	if($_FILES['photo']['size']) {
		require_once $setContentPhotoClassPath;
		$setContent=new SetEventPhoto($con);
		$setContent->insert(new SetEventPhotoRequestType($data['inserted_id'],$_FILES['photo']));
	} else {
		throw new Exception('사진을 입력해주세요');
	}

	/******** 커밋 **********/
	$con->commit();
	$con=null;

	require_once $formatSuccessDataClassPath;
	$formatData=new FormatSuccessData($config);
	$formatData->echoFormatData('index.php',$data);
} catch(Exception $e) {
	if($con) {
		if($con->inTransaction())
		/******** 롤백 **********/			
		$con->rollback();
		$con=null;
	}

	require_once $formatErrorDataClassPath;
	$formatData=new FormatErrorData($config);
	$formatData->echoFormatData($template,$e);
}

?>