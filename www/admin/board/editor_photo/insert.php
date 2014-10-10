<?php

try {
	require_once dirname(__FILE__).DIRECTORY_SEPARATOR.'setting.php';

	require_once $getDbConnectionClassPath;
	$con=GetDbConnection::getConnection($configDb);

	/******** 트랙잭션 시작 **********/
	$con->beginTransaction();

	if($_FILES['photo']['size']) {
		require_once $setContentClassPath;
		$setEditorPhotoTemp=new SetEditorPhotoTemp($con);
		$data['inserted_id']=$setEditorPhotoTemp->insert(new SetEditorPhotoTempRequestType($_FILES['photo']));
	} else {
		throw new Exception('사진을 입력해주세요');
	}

	/******** 커밋 **********/
	$con->commit();
	$con=null;

	require_once $formatSuccessDataClassPath;
	$formatData=new FormatSuccessData($config);
	$formatData->echoFormatData('complete.php?id='.$data['inserted_id'],$data);
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