<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	$setCotnent=new SetBlog($con);
	$setBlogRequestType=new SetBlogRequestType($_POST);
	$setCotnent->update($setBlogRequestType);

	if($_FILES['photo']['size']) {
		$setBlogPhoto=new SetBlogPhoto($con);
		$setBlogPhoto->delete(new SetBlogPhotoRequestType($setBlogRequestType->id));
		$setBlogPhoto->insert(new SetBlogPHotoRequestType($setBlogRequestType->id,$_FILES['photo']));
	}

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

	require_once $foramtErrorData;
}

?>