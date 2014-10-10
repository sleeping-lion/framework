<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	if(!$_FILES['photo']['size'])
	throw new Exception('사진을 입력해주세요');

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	require_once $setContentClassPath;
	$setContent=new SetGallery($con);
	$insertedId=$setContent->insert(new SetGalleryRequestType($_POST));

	require_once $setContentPhotoClassPath;
	$setContentPhoto=new SetGalleryPhoto($con);
	$setContentPhoto->insert(new SetGalleryPhotoRequestType($insertedId,$_FILES['photo']));

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