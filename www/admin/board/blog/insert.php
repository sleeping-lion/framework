<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	require_once $setContentClassPath;
	$setContent=new SetBlog($con);
	$data['inserted_id']=$setContent->insert(new SetBlogRequestType($_POST));

	if($_FILES['photo']['size']) {
		$setBlogPhoto=new SetBlogPhoto($con);
		$setBlogPhoto->insert(new SetBlogPhotoRequestType($data['inserted_id'],$_FILES['photo']));
	} else {
		throw new Exception('사진을 입력해주세요');
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