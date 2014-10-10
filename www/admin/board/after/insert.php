<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';
	
	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	require_once $setContentClassPath;
	$setContent=new SetAfter($con);
	$data['inserted_id']=$setContent->insert(new SetAfterRequestType($_POST));

	if($_FILES['photo']['size']) {
		require_once $setContentPhotoClassPath;
		$setContentPhoto=new SetAfterPhoto($con);
		$setContentPhoto->insert(new SetAfterPhotoRequestType($data['inserted_id'],$_FILES['photo']));
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

?>
