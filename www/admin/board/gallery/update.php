<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	require_once $setContentClassPath;
	$setContent=new SetGallery($con);
	$setContentRequestType=new SetGalleryRequestType($_POST);
	$setContent->update($setContentRequestType);

	if($_FILES['photo']['size']) {
		require_once $setContentPhotoClassPath;
		$setGalleryPhoto=new SetGalleryPhoto($con);
		$setGalleryPhoto->delete(new SetGalleryPhotoRequestType($setContentRequestType->id));
		$setGalleryPhoto->insert(new SetGalleryPhotoRequestType($setContentRequestType->id,$_FILES['photo']));
	}

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